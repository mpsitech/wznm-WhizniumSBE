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

	// --- pnls
	outfile << "<!-- IP pnls - IBEGIN -->" << endl;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) {
			outfile << "\t\t<" << pnl->sref << endl;
			if (pnl->Avail != "") outfile << "\t\t\tv-if=\"statshr.pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "Avail\"" << endl;
			outfile << "\t\t\tv-on:request=\"handleRequest\"" << endl;
			outfile << "\t\t\tref=\"" << pnl->sref << "\"" << endl;
			outfile << "\t\t\t:scrJref=statshr.scrJref" << pnl->sref.substr(3+4+3) << endl;
			outfile << "\t\t/>" << endl;
		};
	};

	outfile << "<!-- IP pnls - IEND -->" << endl;

	// --- import
	outfile << "<!-- IP import - IBEGIN -->" << endl;
	outfile << "\t*/" << endl;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) outfile << "\timport " << pnl->sref << " from './" << pnl->sref << "';" << endl;
	};

	outfile << "\t/*" << endl;
	outfile << "<!-- IP import - IEND -->" << endl;

	// --- components
	outfile << "<!-- IP components - IBEGIN -->" << endl;
	outfile << "\t\t\t*/" << endl;

	first = true;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) {
			if (first) first = false;
			else outfile << "," << endl;
			outfile << "\t\t\t" << pnl->sref;
		};
	};

	if (!first) outfile << endl;

	outfile << "\t\t\t/*" << endl;
	outfile << "<!-- IP components - IEND -->" << endl;

	// --- handleReply
	outfile << "<!-- IP handleReply - IBEGIN -->" << endl;
	outfile << "\t\t\t\t\t*/" << endl;

	first = true;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) {
			outfile << "\t\t\t\t\t";
			if (first) first = false;
			else outfile << "else ";
			outfile << "if (obj.dpcheng.scrJref == this.statshr.scrJref" << pnl->sref.substr(3+4+3) << ") this.$refs." << pnl->sref << ".handleReply(obj);" << endl;
		};
	};

	outfile << "\t\t\t\t\t/*" << endl;
	outfile << "<!-- IP handleReply - IEND -->" << endl;

	// --- handleUpdate
	outfile << "<!-- IP handleUpdate - IBEGIN -->" << endl;
	outfile << "\t\t\t\t\t*/" << endl;

	first = true;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) {
			outfile << "\t\t\t\t\t";
			if (first) first = false;
			else outfile << "else ";
			outfile << "if (obj.dpcheng.scrJref == this.statshr.scrJref" << pnl->sref.substr(3+4+3) << ") this.$refs." << pnl->sref << ".handleUpdate(obj);" << endl;
		};
	};

	outfile << "\t\t\t\t\t/*" << endl;
	outfile << "<!-- IP handleUpdate - IEND -->" << endl;
};
// IP cust --- IEND
