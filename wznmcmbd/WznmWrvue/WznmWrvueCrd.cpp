/**
	* \file WznmWrvueCrd.cpp
	* Wznm operation processor - write Vue.js UI Vue code for card (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrvueCrd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrvue;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrvueCrd
 ******************************************************************************/

DpchRetWznm* WznmWrvueCrd::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrvueCrd* dpchinv
		) {
	ubigint refWznmMCard = dpchinv->refWznmMCard;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream vuefile;

	WznmMCard* car = NULL;

	string s;

	if (dbswznm->tblwznmmcard->loadRecByRef(refWznmMCard, &car)) {
		s = xchg->tmppath + "/" + folder + "/" + car->sref + ".vue.ip";
		vuefile.open(s.c_str(), ios::out);
		writeCrdVue(dbswznm, vuefile, car, Prjshort);
		vuefile.close();

		delete car;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrvueCrd::writeCrdVue(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMCard* car
			, const string& Prjshort
		) {
	ListWznmMPanel pnls;
	WznmMPanel* pnl = NULL;

	bool first;

	dbswznm->tblwznmmpanel->loadRstByCar(car->ref, false, pnls);

	// --- title*
	if (car->refIxVTbl == VecWznmVMCardRefTbl::VOID) outfile << "<!-- IP title - AFFIRM -->" << endl;
	else outfile << "<!-- IP title - REMOVE -->" << endl;

	// --- pnls
	outfile << "<!-- IP pnls - IBEGIN -->" << endl;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC)) {
			outfile << "\t\t<" << pnl->sref << endl;
			if (pnl->Avail != "") outfile << "\t\t\tv-if=\"statshr.pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "Avail\"" << endl;
			if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) outfile << "\t\t\tv-on:crdopen=\"handleCrdopen\"" << endl;
			outfile << "\t\t\tv-on:request=\"handleRequest\"" << endl;
			outfile << "\t\t\tref=\"" << pnl->sref << "\"" << endl;
			outfile << "\t\t\t:scrJref=statshr.scrJref" << pnl->sref.substr(3+4+3) << endl;
			outfile << "\t\t/>" << endl;
		};
	};

	outfile << "<!-- IP pnls - IEND -->" << endl;

	// --- import
	wrIbegin(outfile, 1, "import");

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC))
					outfile << "\timport " << pnl->sref << " from './" << pnl->sref << "';" << endl;
	};

	wrIend(outfile, 1, "import");

	// --- components
	wrIbegin(outfile, 3, "components");

	first = true;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC)) {
			if (first) first = false;
			else outfile << "," << endl;
			outfile << "\t\t\t" << pnl->sref;
		};
	};

	if (!first) outfile << endl;

	wrIend(outfile, 3, "components");

	// --- mergeDpchEngData
	wrIbegin(outfile, 4, "mergeDpchEngData");
	wrMergedpcheng(dbswznm, Prjshort, outfile, car->refWznmMJob);
	wrIend(outfile, 4, "mergeDpchEngData");

	// --- handleReply.subs
	wrIbegin(outfile, 5, "handleReply.subs");

	first = true;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST)) {
			outfile << "\t\t\t\t\t";
			if (first) first = false;
			else outfile << "else ";
			outfile << "if (obj.scrJref == this.statshr.scrJref" << pnl->sref.substr(3+4+3) << ") this.$refs." << pnl->sref << ".handleReply(obj);" << endl;
		};
	};

	outfile << "\t\t\t\t\t";
	if (!first) outfile << "else ";
	if (car->refIxVTbl != VecWznmVMCardRefTbl::VOID) outfile << "this.$refs.Pnl" << car->sref.substr(3) << "Rec.handleReply(obj);" << endl;
	else outfile << "console.log(\"got a '\" + obj.srefIx" << Prjshort << "VDpch + \"' from job with scrJref \" + obj.dpcheng.scrJref);" << endl;

	wrIend(outfile, 5, "handleReply.subs");

	// --- handleUpdate.subs
	wrIbegin(outfile, 5, "handleUpdate.subs");

	first = true;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST)) {
			outfile << "\t\t\t\t\t";
			if (first) first = false;
			else outfile << "} else ";
			outfile << "if (obj.dpcheng.scrJref == this.statshr.scrJref" << pnl->sref.substr(3+4+3) << ") {" << endl;
			outfile << "\t\t\t\t\t\tthis.$refs." << pnl->sref << ".handleUpdate(obj);" << endl;
			outfile << "\t\t\t\t\t\tprocessed = true;" << endl;
		};
	};

	outfile << "\t\t\t\t\t";
	if (!first) outfile << "}";
	if (car->refIxVTbl != VecWznmVMCardRefTbl::VOID) {
		if (!first) outfile << " else ";
		outfile << "processed = this.$refs.Pnl" << car->sref.substr(3) << "Rec.handleUpdate(obj);";
	};
	outfile << endl;

	wrIend(outfile, 5, "handleUpdate.subs");

	// --- handleUpdate.rec*

	// --- handleUpdate.norec*
	if (car->refIxVTbl == VecWznmVMCardRefTbl::VOID) outfile << "<!-- IP handleUpdate.norec - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleUpdate.norec - REMOVE -->" << endl;

	// --- data
	wrIbegin(outfile, 3, "data");
	wrData(dbswznm, Prjshort, outfile, car->refWznmMJob);
	wrIend(outfile, 3, "data");
};
// IP cust --- IEND
