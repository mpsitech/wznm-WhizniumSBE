/**
	* \file WznmWrvuePnl.cpp
	* Wznm operation processor - write Vue.js UI Vue code for panel (implementation)
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

#include "WznmWrvuePnl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrvue;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrvuePnl
 ******************************************************************************/

DpchRetWznm* WznmWrvuePnl::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrvuePnl* dpchinv
		) {
	ubigint refWznmMPanel = dpchinv->refWznmMPanel;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN

	// adapted version from WznmWrwebPnl.cpp

	fstream outfile;

	WznmMPanel* pnl = NULL;
	string estblk;

	WznmMCard* car = NULL;
	bool haspst = false;

	bool hashdr, hasftr;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	vector<unsigned int> icsBasecons;

	uint cnt;
	string s;

	if (dbswznm->tblwznmmpanel->loadRecByRef(refWznmMPanel, &pnl)) {
		dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, cons);
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->sref == "ButRegularize")) {
				if (con->ixVScope == VecWznmVMControlScope::APP) estblk = "statapp";
				else estblk = "statshr";

				break;
			};
		};

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM)) {
			Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT, VecWznmVMControlHkSection::CONTREGD}, 0, icsBasecons);

			// even detail panel has cpt in header
			hashdr = !((pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && (pnl->sref.find("Detail") != string::npos));

			hasftr = false;
			if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND hkIxVSection = "
						+ to_string(VecWznmVMControlHkSection::FTR) + " AND supRefWznmMControl = 0", cnt)) hasftr = (cnt > 0);

			// PnlXxxxYyyZzzzz_Form.vue
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".vue.ip";
			outfile.open(s.c_str(), ios::out);
			writePfVuefile(dbswznm, Prjshort, outfile, pnl, cons, icsBasecons, estblk, hashdr, hasftr);
			outfile.close();

		} else if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
			if (dbswznm->tblwznmmcard->loadRecByRef(pnl->carRefWznmMCard, &car)) {
				haspst = ((pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) && (car->Active.length() > 0));
				delete car;
			};

			// PnlXxxxYyyZzzzz.vue
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".vue.ip";
			outfile.open(s.c_str(), ios::out);
			writePlVuefile(dbswznm, Prjshort, outfile, pnl, cons, estblk, haspst);
			outfile.close();

		} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) {
			// PnlXxxxYyyRec.vue
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".vue.ip";
			outfile.open(s.c_str(), ios::out);
			writePrVuefile(dbswznm, Prjshort, outfile, pnl, cons);
			outfile.close();
		};

		delete pnl;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrvuePnl::writePfVuefile(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const string& estblk
			, const bool hashdr
			, const bool hasftr
		) {
	set<uint> unqcontypes;

	ListWznmMBlock dpchs;
	WznmMBlock* dpch = NULL;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) unqcontypes.insert(cons.nodes[i]->ixVBasetype);

	// --- hdr*
	if (hashdr) outfile << "<!-- IP hdr - AFFIRM -->" << endl;
	else outfile << "<!-- IP hdr - REMOVE -->" << endl;

	if (hashdr) {
		// --- buts
		outfile << "<!-- IP buts - IBEGIN -->" << endl;
		wrButs(dbswznm, Prjshort, outfile, cons, {VecWznmVMControlHkSection::HDR, VecWznmVMControlHkSection::HDRDETD, VecWznmVMControlHkSection::HDRREGD}, estblk);
		outfile << "\t\t\t\t\t&#160;&#160;" << endl;
		wrButs(dbswznm, Prjshort, outfile, cons, {VecWznmVMControlHkSection::SIDE}, estblk);
		outfile << "<!-- IP buts - IEND -->" << endl;
	};

	// --- nohdr*
	if (!hashdr) outfile << "<!-- IP nohdr - AFFIRM -->" << endl;
	else outfile << "<!-- IP nohdr - REMOVE -->" << endl;

	// --- cont
	outfile << "<!-- IP cont - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < icsBasecons.size(); i++) wrBasecon(dbswznm, Prjshort, outfile, pnl->sref, cons, icsBasecons, i, "");
	outfile << "<!-- IP cont - IEND -->" << endl;

	// --- handleButClick*
	if (has(unqcontypes, VecWznmVMControlBasetype::BUT)) outfile << "<!-- IP handleButClick - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleButClick - REMOVE -->" << endl;

	// --- handleButUploadClick*
	if (has(unqcontypes, VecWznmVMControlBasetype::ULD)) outfile << "<!-- IP handleButUploadClick - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleButUploadClick - REMOVE -->" << endl;

	// --- handlePupChange*
	if (has(unqcontypes, VecWznmVMControlBasetype::PUP)) outfile << "<!-- IP handlePupChange - AFFIRM -->" << endl;
	else outfile << "<!-- IP handlePupChange - REMOVE -->" << endl;

	// --- mergeDpchEngData
	wrIbegin(outfile, 4, "mergeDpchEngData", true);
	wrMergedpcheng(dbswznm, Prjshort, outfile, pnl->refWznmMJob);
	wrIend(outfile, 4, "mergeDpchEngData", true);

	// --- dpchhdls
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB)
				+ " AND refUref = " + to_string(pnl->refWznmMJob) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") = " + to_string(VecWznmWScope::APP), false, dpchs);

	wrIbegin(outfile, 3, "dpchhdls");

	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + pnl->sref.substr(3) + "Data") != 0) {
			outfile << endl;

			outfile << "\t\t\thandle" << dpch->sref << ": function(dpcheng) {" << endl;
			wrIp(outfile, 4, "handle" + dpch->sref, "BEGIN");
			outfile << "\t\t\t\tconsole.log(\"" << pnl->sref << ".handle" << dpch->sref << "()\" + dpcheng);" << endl;
			wrIp(outfile, 4, "handle" + dpch->sref, "END");
			outfile << "\t\t\t}," << endl;
		};
	};

	wrIend(outfile, 3, "dpchhdls");

	// --- handleUpdate
	wrIbegin(outfile, 4, "handleUpdate");

	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		outfile << "\t\t\t\t";
		if (i != 0) outfile << "else ";
		outfile << "if (obj.srefIx" << Prjshort << "VDpch == \"" << dpch->sref << "\") this.";
		if (dpch->sref.compare("DpchEng" + pnl->sref.substr(3) + "Data") == 0) outfile << "mergeDpchEngData";
		else outfile << "handle" << dpch->sref;
		outfile << "(obj.dpcheng);" << endl;
	};

	wrIend(outfile, 4, "handleUpdate");

	// --- hrefDld*
	if (has(unqcontypes, VecWznmVMControlBasetype::DLD)) outfile << "<!-- IP hrefDld - AFFIRM -->" << endl;
	else outfile << "<!-- IP hrefDld - REMOVE -->" << endl;

	// --- data
	wrIbegin(outfile, 3, "data");
	wrData(dbswznm, Prjshort, outfile, pnl->refWznmMJob);
	wrIend(outfile, 3, "data");
};

void WznmWrvuePnl::writePlVuefile(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
			, const string& estblk
			, const bool haspst
		) {
	ubigint ref;

	WznmMControl* con = NULL;

	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	ListWznmMBlock dpchs;
	WznmMBlock* dpch = NULL;

	string s;

	bool first, found;

	// --- pre1*
	if (haspst) outfile << "<!-- IP pre1 - AFFIRM -->" << endl;
	else outfile << "<!-- IP pre1 - REMOVE -->" << endl;

	// --- nopre1*
	if (!haspst) outfile << "<!-- IP nopre1 - AFFIRM -->" << endl;
	else outfile << "<!-- IP nopre1 - REMOVE -->" << endl;

	// --- buts
	outfile << "<!-- IP buts - IBEGIN -->" << endl;
	wrButs(dbswznm, Prjshort, outfile, cons, {VecWznmVMControlHkSection::HDR, VecWznmVMControlHkSection::HDRDETD, VecWznmVMControlHkSection::HDRREGD}, estblk);
	outfile << "\t\t\t\t\t&#160;&#160;" << endl;
	wrButs(dbswznm, Prjshort, outfile, cons, {VecWznmVMControlHkSection::SIDE}, estblk);
	outfile << "<!-- IP buts - IEND -->" << endl;

	// --- handleButClipboardClick
	wrIbegin(outfile, 4, "handleButClipboardClick", false);

	// exact copy from WznmWrweb.cpp
	found = false;

	for (unsigned int j = 0; j < cons.nodes.size(); j++) {
		con = cons.nodes[j];

		if ((con->ixVBasetype == VecWznmVMControlBasetype::TCO) && (con->refIxVTbl == VecWznmVMControlRefTbl::QCO)) {
			found = dbswznm->loadRefBySQL("SELECT qryRefWznmMQuery FROM TblWznmMQuerycol WHERE ref = " + to_string(con->refUref), ref);
			break;
		};
	};

	if (found) {
		dbswznm->tblwznmmquerycol->loadRstByQry(ref, false, qcos);

		outfile << "\t\t\t\t" << Prjshort << ".copyToClipboard(document, this.continf, this.rst, this.statshrqry, this.tag," << endl;

		// tags
		outfile << "\t\t\t\t\t\t\t[";
		first = true;

		for (unsigned int j = 0; j < qcos.nodes.size(); j++) {
			qco = qcos.nodes[j];

			if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
				if (first) first = false;
				else outfile << ",";

				outfile << "\"";

				for (unsigned int k = 0; k < cons.nodes.size(); k++) {
					con = cons.nodes[k];

					if ((con->ixVBasetype == VecWznmVMControlBasetype::TCO) && (con->refUref == qco->ref)) {
						outfile << con->sref.substr(3);
						break;
					};
				};

				outfile << "\"";
			};
		};
		outfile << "]," << endl;

		// tcos
		outfile << "\t\t\t\t\t\t\t[";
		first = true;

		for (unsigned int j = 0; j < qcos.nodes.size(); j++) {
			qco = qcos.nodes[j];

			if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
				if (first) first = false;
				else outfile << ",";

				outfile << "\"" << qco->Short << "\"";
			};
		};
		outfile << "]);" << endl;
	};

	wrIend(outfile, 4, "handleButClipboardClick", false);

	// --- handleButCrdopenClick*
	if (Wznm::hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, pnl->ref, "crdopen")) outfile << "<!-- IP handleButCrdopenClick - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleButCrdopenClick - REMOVE -->" << endl;

	// --- mergeDpchEngData
	wrIbegin(outfile, 4, "mergeDpchEngData", true);
	wrMergedpcheng(dbswznm, Prjshort, outfile, pnl->refWznmMJob);
	wrIend(outfile, 4, "mergeDpchEngData", true);

	// --- mergeDpchEngData.tcos
	wrIbegin(outfile, 5, "mergeDpchEngData.tcos");

	outfile << "\t\t\t\t\ttcos.push({value: \"jnum\", text: \"jnum\"}";

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) outfile << ", {value: \"" << con->sref << "\", text: this.tag." << con->sref << "}";
	};
	
	outfile << ");" << endl;

	wrIend(outfile, 5, "mergeDpchEngData.tcos");

	// --- mergeDpchEngData.rows
	wrIbegin(outfile, 6, "mergeDpchEngData.rows");

	outfile << "\t\t\t\t\t\trows.push({jnum: rec[\"jnum\"]";

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) {
			outfile << ", " << con->sref << ": rec[\"";
			if (dbswznm->loadStringBySQL("SELECT Short FROM TblWznmMQuerycol WHERE ref = " + to_string(con->refUref), s)) outfile << s;
			outfile << "\"]";
		};
	};

	outfile << "})" << endl;
	wrIend(outfile, 6, "mergeDpchEngData.rows");

	// --- handleReply.crdopen*
	if (Wznm::hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, pnl->ref, "crdopen")) outfile << "<!-- IP handleReply.crdopen - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleReply.crdopen - REMOVE -->" << endl;

	// --- handleDpchAppDoCrdopenReply*
	if (Wznm::hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, pnl->ref, "crdopen")) outfile << "<!-- IP handleDpchAppDoCrdopenReply - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleDpchAppDoCrdopenReply - REMOVE -->" << endl;

	// --- dpchhdls
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB)
				+ " AND refUref = " + to_string(pnl->refWznmMJob) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") = " + to_string(VecWznmWScope::APP), false, dpchs);

	wrIbegin(outfile, 3, "dpchhdls");

	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + pnl->sref.substr(3) + "Data") != 0) {
			outfile << endl;

			outfile << "\t\t\thandle" << dpch->sref << ": function(dpcheng) {" << endl;
			wrIp(outfile, 4, "handle" + dpch->sref, "BEGIN");
			outfile << "\t\t\t\tconsole.log(\"" << pnl->sref << ".handle" << dpch->sref << "()\" + dpcheng);" << endl;
			wrIp(outfile, 4, "handle" + dpch->sref, "END");
			outfile << "\t\t\t}," << endl;
		};
	};

	wrIend(outfile, 3, "dpchhdls");

	// --- handleUpdate
	wrIbegin(outfile, 4, "handleUpdate");

	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		outfile << "\t\t\t\t";
		if (i != 0) outfile << "else ";
		outfile << "if (obj.srefIx" << Prjshort << "VDpch == \"" << dpch->sref << "\") this.";
		if (dpch->sref.compare("DpchEng" + pnl->sref.substr(3) + "Data") == 0) outfile << "mergeDpchEngData";
		else outfile << "handle" << dpch->sref;
		outfile << "(obj.dpcheng);" << endl;
	};

	wrIend(outfile, 4, "handleUpdate");

	// --- pre2*
	if (haspst) outfile << "<!-- IP pre2 - AFFIRM -->" << endl;
	else outfile << "<!-- IP pre2 - REMOVE -->" << endl;

	// --- nopre2*
	if (!haspst) outfile << "<!-- IP nopre2 - AFFIRM -->" << endl;
	else outfile << "<!-- IP nopre2 - REMOVE -->" << endl;

	// --- data
	wrIbegin(outfile, 3, "data");
	wrData(dbswznm, Prjshort, outfile, pnl->refWznmMJob);
	wrIend(outfile, 3, "data");
};

void WznmWrvuePnl::writePrVuefile(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
		) {
	ListWznmMPanel crdpnls;
	WznmMPanel* crdpnl = NULL;

	bool first;

	dbswznm->tblwznmmpanel->loadRstByCar(pnl->carRefWznmMCard, false, crdpnls);

	// --- pnls
	outfile << "<!-- IP pnls - IBEGIN -->" << endl;

	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) {
			outfile << "\t\t\t<v-row";
			if (crdpnl->Avail != "") outfile << " v-if=\"statshr.pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << "Avail\"";
			outfile << ">" << endl;
			outfile << "\t\t\t\t<v-col cols=\"12\" md=\"12\">" << endl;
			outfile << "\t\t\t\t\t<" << crdpnl->sref << endl;
			if (Wznm::hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, crdpnl->ref, "crdopen")) outfile << "\t\t\t\t\t\tv-on:crdopen=\"handleCrdopen\"" << endl;
			outfile << "\t\t\t\t\t\tv-on:request=\"handleRequest\"" << endl;
			outfile << "\t\t\t\t\t\tref=\"" << crdpnl->sref << "\"" << endl;
			outfile << "\t\t\t\t\t\t:scrJref=statshr.scrJref" << crdpnl->sref.substr(3+4+3) << endl;
			outfile << "\t\t\t\t\t/>" << endl;
			outfile << "\t\t\t\t</v-col>" << endl;
			outfile << "\t\t\t</v-row>" << endl;
		};
	};

	first = true;

	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if (Wznm::getPnllhs(dbswznm, crdpnl) && (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
			if (first) {
				outfile << "\t\t\t<v-row>" << endl;
				first = false;
			};

			outfile << "\t\t\t\t<v-col cols=\"12\" md=\"6\">" << endl;
			outfile << "\t\t\t\t\t<" << crdpnl->sref << endl;
			if (pnl->Avail != "") outfile << "\t\t\t\t\t\tv-if=\"statshr.pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "Avail\"" << endl;
			if (Wznm::hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, crdpnl->ref, "crdopen")) outfile << "\t\t\t\t\t\tv-on:crdopen=\"handleCrdopen\"" << endl;
			outfile << "\t\t\t\t\t\tv-on:request=\"handleRequest\"" << endl;
			outfile << "\t\t\t\t\t\tref=\"" << crdpnl->sref << "\"" << endl;
			outfile << "\t\t\t\t\t\t:scrJref=statshr.scrJref" << crdpnl->sref.substr(3+4+3) << endl;
			outfile << "\t\t\t\t\t/>" << endl;
			outfile << "\t\t\t\t</v-col>" << endl;
		};
	};

	if (!first) outfile << "\t\t\t</v-row>" << endl;

	first = true;

	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if (Wznm::getPnlrhs(dbswznm, crdpnl)) {
			if (first) {
				outfile << "\t\t\t<v-divider/>" << endl;
				outfile << "\t\t\t<v-row>" << endl;

				first = false;
			};

			outfile << "\t\t\t\t<v-col cols=\"12\" md=\"6\">" << endl;
			outfile << "\t\t\t\t\t<" << crdpnl->sref << endl;
			if (pnl->Avail != "") outfile << "\t\t\t\t\t\tv-if=\"statshr.pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "Avail\"" << endl;
			if (Wznm::hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, crdpnl->ref, "crdopen")) outfile << "\t\t\t\t\t\tv-on:crdopen=\"handleCrdopen\"" << endl;
			outfile << "\t\t\t\t\t\tv-on:request=\"handleRequest\"" << endl;
			outfile << "\t\t\t\t\t\tref=\"" << crdpnl->sref << "\"" << endl;
			outfile << "\t\t\t\t\t\t:scrJref=statshr.scrJref" << crdpnl->sref.substr(3+4+3) << endl;
			outfile << "\t\t\t\t\t/>" << endl;
			outfile << "\t\t\t\t</v-col>" << endl;
		};
	};

	if (!first) outfile << "\t\t\t</v-row>" << endl;

	outfile << "<!-- IP pnls - IEND -->" << endl;

	// --- import
	wrIbegin(outfile, 1, "import");

	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST))
					outfile << "\timport " << crdpnl->sref << " from './" << crdpnl->sref << "';" << endl;
	};

	wrIend(outfile, 1, "import");

	// --- components
	wrIbegin(outfile, 3, "components");

	first = true;

	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
			if (first) first = false;
			else outfile << "," << endl;
			outfile << "\t\t\t" << crdpnl->sref;
		};
	};

	if (!first) outfile << endl;

	wrIend(outfile, 3, "components");

	// --- handleReply.subs
	wrIbegin(outfile, 6, "handleReply.subs");

	first = true;

	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
			outfile << "\t\t\t\t\t\t";
			if (first) first = false;
			else outfile << "else ";
			outfile << "if (obj.scrJref == this.statshr.scrJref" << crdpnl->sref.substr(3+4+3) << ") this.$refs." << crdpnl->sref << ".handleReply(obj);" << endl;
		};
	};

	wrIend(outfile, 6, "handleReply.subs");

	// --- handleUpdate.subs
	wrIbegin(outfile, 6, "handleUpdate.subs");

	first = true;

	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
			outfile << "\t\t\t\t\t\t";
			if (first) first = false;
			else outfile << "else ";
			outfile << "if (obj.dpcheng.scrJref == this.statshr.scrJref" << crdpnl->sref.substr(3+4+3) << ") this.$refs." << crdpnl->sref << ".handleUpdate(obj);" << endl;
		};
	};

	wrIend(outfile, 6, "handleUpdate.subs");

	// --- data
	wrIbegin(outfile, 3, "data");
	wrData(dbswznm, Prjshort, outfile, pnl->refWznmMJob);
	wrIend(outfile, 3, "data");
};

void WznmWrvuePnl::wrButs(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, ListWznmMControl& cons
			, const set<uint>& hkIcsVSection
			, const string& estblk
		) {
	ubigint refC;

	WznmMControl* con = NULL;

	string s;

	string indent = string(5, '\t');

	refC = 0;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (hkIcsVSection.find(con->hkIxVSection) != hkIcsVSection.end())) {
			s = "";
			dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "action", 0, s);

			outfile << indent;

			if (i != 0) {
				if ((con->refWznmCControl != 0) && (con->refWznmCControl != refC)) outfile << "&#160;";
				outfile << "&#160;" << endl;
			};
			refC = con->refWznmCControl;

			outfile << indent << "<v-btn" << endl;
			outfile << indent << "\tv-if=\"" << estblk << ".srefIx" << Prjshort << "VExpstate=='";
			if (con->sref == "ButRegularize") outfile << "mind";
			else outfile << "regd";
			outfile << "'\"" << endl;
			outfile << indent << "\tfab" << endl;
			outfile << indent << "\tsmall" << endl;
			outfile << indent << "\tlight" << endl;
			outfile << indent << "\tcolor=\"primary\"" << endl;
			if ((estblk == "statapp") && (con->sref == "ButMinimize")) outfile << indent << "\tv-on:click=\"statapp.srefIx" << Prjshort << "VExpstate='mind'\"" << endl;
			else if ((estblk == "statapp") && (con->sref == "ButRegularize")) outfile << indent << "\tv-on:click=\"statapp.srefIx" << Prjshort << "VExpstate='regd'\"" << endl;
			else if (s == "crdopen") outfile << indent << "\tv-on:click=\"handleButCrdopenClick('" << con->sref << "Click')\"" << endl;
			else if (con->sref == "ButClipboard") outfile << indent << "\tv-on:click=\"handleButClipboardClick()\"" << endl;
			else outfile << indent << "\tv-on:click=\"handleButClick('" << con->sref << "Click')\"" << endl;
			outfile << indent << "\t:value=\"1\"" << endl;
			if (con->Active != "") outfile << indent << "\t:disabled=\"!statshr." << con->sref << "Active\"" << endl;
			outfile << indent << ">" << endl;

			if (StrMod::srefInSrefs(con->srefsKOption, "icon")) {
				s = getButmdi(dbswznm, Prjshort, con);

				if (StrMod::srefInSrefs(con->srefsKOption, "onoff")) outfile << indent << "\t<v-icon color=\"white\">{{contapp." << con->sref << "On ? '" << s << "' : '" << s << "-off'}}</v-icon>" << endl;
				else outfile << indent << "\t<v-icon color=\"white\">" << s << "</v-icon>" << endl;

			} else {
				outfile << indent << "\t{{tag." << con->sref << "}}" << endl;
			};

			outfile << indent << "</v-btn>" << endl;
		};
	};
};
// IP cust --- IEND
