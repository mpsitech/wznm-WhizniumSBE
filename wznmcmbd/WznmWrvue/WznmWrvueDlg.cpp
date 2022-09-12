/**
	* \file WznmWrvueDlg.cpp
	* Wznm operation processor - write Vue.js UI Vue code for dialog (implementation)
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

#include "WznmWrvueDlg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrvue;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrvueDlg
 ******************************************************************************/

DpchRetWznm* WznmWrvueDlg::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrvueDlg* dpchinv
		) {
	ubigint refWznmMDialog = dpchinv->refWznmMDialog;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream outfile;

	WznmMDialog* dlg = NULL;

	ListWznmMControl dits;

	ListWznmMControl ftrcons;

	string s;

	if (dbswznm->tblwznmmdialog->loadRecByRef(refWznmMDialog, &dlg)) {
		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(refWznmMDialog)
					+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::DIT) + " ORDER BY hkNum ASC", false, dits);

		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(refWznmMDialog)
					+ " AND hkIxVSection = " + to_string(VecWznmVMControlHkSection::FTR) + " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::BUT) + " ORDER BY hkNum", false, ftrcons);

		// DlgXxxxYyyZzzzz.vue
		s = xchg->tmppath + "/" + folder + "/" + dlg->sref + ".vue.ip";
		outfile.open(s.c_str(), ios::out);
		writeDlgVue(dbswznm, outfile, dlg, dits, ftrcons, Prjshort);
		outfile.close();

		delete dlg;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrvueDlg::writeDlgVue(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMDialog* dlg
			, ListWznmMControl& dits
			, ListWznmMControl& ftrcons
			, const string& Prjshort
		) {
	WznmMControl* dit = NULL;

	ListWznmMControl cons;
	vector<unsigned int> icsCons;
	WznmMControl* con = NULL;

	vector<unsigned int> icsBasecons;

	set<uint> unqcontypes;

	string ditshort;

	ListWznmMBlock dpchs;
	WznmMBlock* dpch = NULL;

	dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::DLG, dlg->ref, false, cons);
	for (unsigned int i = 0; i < cons.nodes.size(); i++) unqcontypes.insert(cons.nodes[i]->ixVBasetype);

	// --- dse*
	if (dits.nodes.size() > 0) outfile << "<!-- IP dse - AFFIRM -->" << endl;
	else outfile << "<!-- IP dse - REMOVE -->" << endl;

	// --- cont
	outfile << "<!-- IP cont - IBEGIN -->" << endl;
	if (dits.nodes.size() > 0) outfile << "\t\t\t<v-tabs-items v-model=\"numFDse\">" << endl;

	if (dits.nodes.size() > 0) {
		for (unsigned int i = 0; i < dits.nodes.size(); i++) {
			dit = dits.nodes[i];

			ditshort = dit->sref.substr(3);
			Wznm::loadDitcons(dbswznm, dit->ref, cons);
			Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT}, dit->ref, icsBasecons);

			outfile << "\t\t\t\t<v-tab-item>" << endl;
			outfile << "\t\t\t\t\t<v-card flat>" << endl;
			outfile << "\t\t\t\t\t\t<v-card-text>" << endl;
			for (unsigned int j = 0; j < icsBasecons.size(); j++) wrBasecon(dbswznm, Prjshort, outfile, dlg->sref, cons, icsBasecons, j, ditshort);
			outfile << "\t\t\t\t\t\t</v-card-text>" << endl;
			outfile << "\t\t\t\t\t</v-card>" << endl;
			outfile << "\t\t\t\t</v-tab-item>" << endl;
		};

	} else {
		dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::DLG, dlg->ref, false, cons);
		Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT}, 0, icsBasecons);
		for (unsigned int i = 0; i < icsBasecons.size(); i++) wrBasecon(dbswznm, Prjshort, outfile, dlg->sref, cons, icsBasecons, i, "");
	};

	if (dits.nodes.size() > 0) outfile << "\t\t\t</v-tabs-items>" << endl;
	outfile << "<!-- IP cont - IEND -->" << endl;

	// --- ftr
	outfile << "<!-- IP ftr - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < ftrcons.nodes.size(); i++) {
		con = ftrcons.nodes[i];

		if (i != 0) outfile << "\t\t\t&#160;" << endl;
		outfile << "\t\t\t<v-btn class=\"primary\"" << endl;
		outfile << "\t\t\t\tv-on:click=\"handleButClick('', '" << con->sref << "Click')\"" << endl;
		outfile << "\t\t\t>" << endl;
		outfile << "\t\t\t\t{{tag." << con->sref << "}}" << endl;
		outfile << "\t\t\t</v-btn>" << endl;
	};
	outfile << "<!-- IP ftr - IEND -->" << endl;

	// --- handleButClick*
	if (has(unqcontypes, VecWznmVMControlBasetype::BUT)) outfile << "<!-- IP handleButClick - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleButClick - REMOVE -->" << endl;

	// --- handleButUploadClick*
	if (has(unqcontypes, VecWznmVMControlBasetype::ULD)) outfile << "<!-- IP handleButUploadClick - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleButUploadClick - REMOVE -->" << endl;

	// --- handlePupChange*
	if (has(unqcontypes, VecWznmVMControlBasetype::PUP)) outfile << "<!-- IP handlePupChange - AFFIRM -->" << endl;
	else outfile << "<!-- IP handlePupChange - REMOVE -->" << endl;

	// --- updateEng
	wrIbegin(outfile, 4, "updateEng");
	for (unsigned int i = 0; i < dits.nodes.size(); i++) {
		dit = dits.nodes[i];

		ditshort = dit->sref.substr(3);
		outfile << "\t\t\t\tif (mask.indexOf(\"contiac" << StrMod::lc(ditshort) << "\") != -1) dpchapp[\"ContIac" << dlg->sref << ditshort << "\"] = this.contiac" << StrMod::lc(ditshort) << ";" << endl;
	};
	wrIend(outfile, 4, "updateEng");

	// --- mergeDpchEngData
	wrIbegin(outfile, 4, "mergeDpchEngData");
	wrMergedpcheng(dbswznm, Prjshort, outfile, dlg->refWznmMJob);
	wrIend(outfile, 4, "mergeDpchEngData");

	// --- dpchhdls
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB)
				+ " AND refUref = " + to_string(dlg->refWznmMJob) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") = " + to_string(VecWznmWScope::APP), false, dpchs);

	wrIbegin(outfile, 3, "dpchhdls");

	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + dlg->sref + "Data") != 0) {
			outfile << endl;

			outfile << "\t\t\thandle" << dpch->sref << ": function(dpcheng) {" << endl;
			wrIp(outfile, 4, "handle" + dpch->sref, "BEGIN");
			outfile << "\t\t\t\tconsole.log(\"" << dlg->sref << ".handle" << dpch->sref << "()\" + dpcheng);" << endl;
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
		if (dpch->sref.compare("DpchEng" + dlg->sref + "Data") == 0) outfile << "mergeDpchEngData";
		else outfile << "handle" << dpch->sref;
		outfile << "(obj.dpcheng);" << endl;
	};

	wrIend(outfile, 4, "handleUpdate");

	// --- hrefDld*
	if (has(unqcontypes, VecWznmVMControlBasetype::DLD)) outfile << "<!-- IP hrefDld - AFFIRM -->" << endl;
	else outfile << "<!-- IP hrefDld - REMOVE -->" << endl;

	// --- numFDse*
	if (dits.nodes.size() > 0) outfile << "<!-- IP numFDse - AFFIRM -->" << endl;
	else outfile << "<!-- IP numFDse - REMOVE -->" << endl;

	// --- data
	wrIbegin(outfile, 3, "data");
	wrData(dbswznm, Prjshort, outfile, dlg->refWznmMJob);
	wrIend(outfile, 3, "data");
};
// IP cust --- IEND
