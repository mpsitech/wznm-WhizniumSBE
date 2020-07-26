/**
	* \file WznmWrwebDlg.cpp
	* Wznm operation processor - write web UI JS/HTML code for dialog (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrwebDlg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrweb;

/******************************************************************************
 namespace WznmWrwebDlg
 ******************************************************************************/

DpchRetWznm* WznmWrwebDlg::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrwebDlg* dpchinv
		) {
	ubigint refWznmMDialog = dpchinv->refWznmMDialog;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream outfile;

	WznmMDialog* dlg = NULL;

	ListWznmMControl dits;
	WznmMControl* dit = NULL;

	ListWznmMControl ftrcons;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	string s;

	if (dbswznm->tblwznmmdialog->loadRecByRef(refWznmMDialog, &dlg)) {
		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(refWznmMDialog)
					+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::DIT) + " ORDER BY hkNum ASC", false, dits);

		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(refWznmMDialog)
					+ " AND hkIxVSection = " + to_string(VecWznmVMControlHkSection::FTR) + " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::BUT) + " ORDER BY hkNum", false, ftrcons);

		// DlgXxxxYyyZzzzz_ftr.html
		s = xchg->tmppath + "/" + folder + "/" + dlg->sref + "_ftr.html.ip";
		outfile.open(s.c_str(), ios::out);
		writeDlgfHtfile(dbswznm, outfile, refWznmMDialog, ftrcons, (dits.nodes.size() > 0));
		outfile.close();

		if (dits.nodes.size() > 0) {
			// DlgXxxxYyyZzzzz_hdr.xml
			s = xchg->tmppath + "/" + folder + "/" + dlg->sref + "_hdr.xml.ip";
			outfile.open(s.c_str(), ios::out);
			writeDlghXmfile(dbswznm, outfile, refWznmMDialog, dits);
			outfile.close();
		};

		// DlgXxxxYyyZzzzzAaa.xml ; analogy to bcont.xml
		if (dits.nodes.size() > 0) {
			for (unsigned int i = 0; i < dits.nodes.size(); i++) {
				dit = dits.nodes[i];

				s = xchg->tmppath + "/" + folder + "/" + dlg->sref + dit->sref.substr(3) + ".xml.ip";
				outfile.open(s.c_str(), ios::out);
				writeDlgaXmfile(dbswznm, outfile, dlg, dit, Prjshort);
				outfile.close();
			};

		} else {
			s = xchg->tmppath + "/" + folder + "/" + dlg->sref + "_cont.xml.ip";
			outfile.open(s.c_str(), ios::out);
			writeDlgaXmfile(dbswznm, outfile, dlg, NULL, Prjshort);
			outfile.close();
		};

		// DlgXxxxYyyZzzzz.html
		s = xchg->tmppath + "/" + folder + "/" + dlg->sref + ".html.ip";
		outfile.open(s.c_str(), ios::out);
		writeDlgHtfile(dbswznm, outfile, dlg, (dits.nodes.size() > 0));
		outfile.close();

		if (dits.nodes.size() > 0) {
			// DlgXxxxYyyZzzzz.js
			s = xchg->tmppath + "/" + folder + "/" + dlg->sref + ".js.ip";
			outfile.open(s.c_str(), ios::out);
			writeDlgJsfile(dbswznm, outfile, dlg, dits, ftrcons, Prjshort);
			outfile.close();

		} else {
			// DlgXxxxYyyZzzzz_Nodse.js
			s = xchg->tmppath + "/" + folder + "/" + dlg->sref + ".js.ip";
			outfile.open(s.c_str(), ios::out);
			writeDlgndJsfile(dbswznm, outfile, dlg, ftrcons, Prjshort);
			outfile.close();
		};

		// DlgXxxxYyyZzzzz{Aaa}_LstXxx.xml
		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref)
					+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::LST) + " ORDER BY supNum ASC", false, cons);
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];


			s = xchg->tmppath + "/" + folder + "/" + dlg->sref;
			if (dits.nodes.size() > 0) s += con->sref.substr(0, 3) + "_" + con->sref.substr(3);
			else s += con->sref;
			s += ".xml.ip";

			outfile.open(s.c_str(), ios::out);
			writeLstXmfile(outfile, con, true);
			outfile.close();
		};

		delete dlg;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrwebDlg::writeDlgfHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMDialog
			, ListWznmMControl& ftrcons
			, const bool hasdse
		) {
	WznmMControl* con = NULL;

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, ftrcons, {VecWznmVMControlHkSection::FTR}, "", 1, hasdse);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- buts
	outfile << "<!-- IP buts - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < ftrcons.nodes.size(); i++) {
		con = ftrcons.nodes[i];

		outfile << "\t\t\t\t\t<span id=\"" << con->sref << "\" class=\"but\" onclick=\"handle" << con->sref << "Click()\">";
		if (i != 0) outfile << "&#160;&#160;";
		outfile << con->sref << "</span>" << endl;
	};
	outfile << "<!-- IP buts - IEND -->" << endl;
};

void WznmWrwebDlg::writeDlghXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMDialog
			, ListWznmMControl& dits
		) {
	ListWznmMControl cons;

	WznmMControl* dit = NULL;

	unsigned int w, wfill;

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::DLG, refWznmMDialog, false, cons);
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::HDR}, "", 1);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- colgrp
	outfile << "<!-- IP colgrp - IBEGIN -->" << endl;
	wfill = 690-5;

	outfile << "\t\t\t\t<col width=\"5\"/>" << endl;
	for (unsigned int i = 0; i < dits.nodes.size(); i++) {
		if (i == 0) w = 108;
		else if (i == 5) w = 103;
		else w = 116;

		outfile << "\t\t\t\t<col width=\"" << w << "\"/>" << endl;

		wfill -= w;
	};

	if (dits.nodes.size() < 6) outfile << "\t\t\t\t<col width=\"" << wfill << "\"/>" << endl;
	outfile << "<!-- IP colgrp - IEND -->" << endl;

	// --- cpts
	outfile << "<!-- IP cpts - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < dits.nodes.size(); i++) {
		dit = dits.nodes[i];

		outfile << "\t\t\t\t<td align=\"center\" valign=\"center\"><span id=\"Cpt" << dit->sref.substr(3) << "\" class=\"";
		if (i == 0) outfile << "hdr_ditsel"; else outfile << "hdr_dit";
		outfile << "\"";
		if (i != 0) outfile << " onclick=\"handleDseSelect(" << (i+1) << ")\"";
		outfile << ">Cpt" << dit->sref.substr(3) << "</span></td>" << endl;
	};
	outfile << "<!-- IP cpts - IEND -->" << endl;

	// --- dse
	outfile << "<!-- IP dse - IBEGIN -->" << endl;
	for (unsigned int i=1;i<dits.nodes.size(); i++) {
		outfile << "\t\t\t\t\t\t<line x1=\"" << (i*116-9-56) << "\" y1=\"7.5\" x2=\"" << (i*116-9+56) << "\" y2=\"7.5\" stroke=\"black\"/>" << endl;
	};

	for (unsigned int i = 0; i < dits.nodes.size(); i++) {
		dit = dits.nodes[i];

		outfile << "\t\t\t\t\t\t<rect id=\"" << dit->sref << "\" class=\"";
		if (i == 0) outfile << "hdr_ditsels"; else outfile << "hdr_dits";
		outfile << "\"";
		if (i != 0) outfile << " onclick=\"handleDseSelect(" << (i+1) << ")\"";
		outfile << " x=\"" << (47+i*116) << "\" y=\"4\" width=\"6\" height=\"6\"/>" << endl;
	};
	outfile << "<!-- IP dse - IEND -->" << endl;
};

void WznmWrwebDlg::writeDlgaXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMDialog* dlg
			, WznmMControl* dit
			, const string& Prjshort
		) {
	ListWznmMControl cons;
	vector<unsigned int> icsCons;

	vector<unsigned int> icsBasecons;

	string ditshort;

	if (dit) {
		ditshort = dit->sref.substr(3);
		Wznm::loadDitcons(dbswznm, dit->ref, cons);
	} else dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::DLG, dlg->ref, false, cons);

	// --- handleLoad*
	if (dit) outfile << "<!-- IP handleLoad - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleLoad - REMOVE -->" << endl;

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::CONT}, ditshort, 1);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- onload*
	if (!dit) outfile << "<!-- IP onload - AFFIRM -->" << endl;
	else outfile << "<!-- IP onload - REMOVE -->" << endl;

	// --- ditonload*
	if (dit) outfile << "<!-- IP ditonload - AFFIRM -->" << endl;
	else outfile << "<!-- IP ditonload - REMOVE -->" << endl;

	// --- ctlrows
	outfile << "<!-- IP ctlrows - IBEGIN -->" << endl;

	if (dit) Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT}, dit->ref, icsBasecons);
	else Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT}, 0, icsBasecons);

/*
	// DEBUG
	cout << "base control structure for dialog '" << StubWznm::getStubDlgStd(dbswznm, dlg->ref) << "'";
	if (dit) cout << ", dialog item '" << dit->sref << "'";
	cout << endl;
	if (dit) Wznm::showBasecons(dbswznm, cons, icsBasecons, dit->sref.substr(3));
	else Wznm::showBasecons(dbswznm, cons, icsBasecons, "");
	cout << endl;
	//
*/

	for (unsigned int i = 0; i < icsBasecons.size(); i++) wrBaseconXml(dbswznm, Prjshort, outfile, dlg->sref, cons, icsBasecons, i, ditshort, true);

	outfile << "<!-- IP ctlrows - IEND -->" << endl;
};

void WznmWrwebDlg::writeDlgHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMDialog* dlg
			, const bool hasdse
		) {
	uint cnt;

	// --- scrs
	outfile << "<!-- IP scrs - IBEGIN -->" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::HSB), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/hsb.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::LST), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/lst.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::PUP), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/pup.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::RBU), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/rbu.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::SLD), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/sld.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::UPD), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/upd.js\" type=\"text/javascript\"></script>" << endl;
	if (getJobvecio(dbswznm, dlg->refWznmMJob)) outfile << "\t\t<script src=\"../script/vecio.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::VSB), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/vsb.js\" type=\"text/javascript\"></script>" << endl;
	outfile << "<!-- IP scrs - IEND -->" << endl;

	// --- hdr*
	if (!hasdse) outfile << "<!-- IP hdr - AFFIRM -->" << endl;
	else outfile << "<!-- IP hdr - REMOVE -->" << endl;

	// --- dsehdr*
	if (hasdse) outfile << "<!-- IP dsehdr - AFFIRM -->" << endl;
	else outfile << "<!-- IP dsehdr - REMOVE -->" << endl;

	// --- cont*
	if (!hasdse) outfile << "<!-- IP cont - AFFIRM -->" << endl;
	else outfile << "<!-- IP cont - REMOVE -->" << endl;

	// --- ditcont*
	if (hasdse) outfile << "<!-- IP ditcont - AFFIRM -->" << endl;
	else outfile << "<!-- IP ditcont - REMOVE -->" << endl;
};

void WznmWrwebDlg::writeDlgJsfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMDialog* dlg
			, ListWznmMControl& dits
			, ListWznmMControl& ftrcons
			, const string& Prjshort
		) {
	WznmMControl* dit = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	vector<unsigned int> icsBasecons;

	string ditshort;

	ListWznmMBlock dpchs;
	WznmMBlock* dpch = NULL;

	bool hasdyn;

	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB)
				+ " AND refUref = " + to_string(dlg->refWznmMJob) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") = " + to_string(VecWznmWScope::APP), false, dpchs);

	// --- initDits
	outfile << "// IP initDits --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dits.nodes.size(); i++) {
		dit = dits.nodes[i];
		ditshort = dit->sref.substr(3);

		Wznm::loadDitcons(dbswznm, dit->ref, cons);
		Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT}, dit->ref, icsBasecons);

		outfile << "function init" << ditshort << "() {" << endl;
		outfile << "\tcontdoc = doc.getElementById(\"_cont\").contentDocument;" << endl;
		outfile << endl;

		outfile << "\t// IP init" << ditshort << " --- BEGIN" << endl;
		for (unsigned int j = 0; j < icsBasecons.size(); j++) wrBconiniJs(dbswznm, outfile, cons, icsBasecons, j, dlg->sref, ditshort);
		outfile << "\t// IP init" << ditshort << " --- END" << endl;
		outfile << endl;

		outfile << "\tsetSi(srcdoc, \"StatApp" << dlg->sref << "\", \"initdone\", \"true\");" << endl;
		outfile << endl;
		outfile << "\trefresh" << ditshort << "();" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP initDits --- IEND" << endl;

	// --- init
	outfile << "// IP init --- IBEGIN" << endl;
	for (unsigned int i = 0; i < ftrcons.nodes.size(); i++) {
		con = ftrcons.nodes[i];

		outfile << "\tsetTextContent(ftrdoc, ftrdoc.getElementById(\"" << con->sref << "\"), ";
		if (i != 0) outfile << "\"\\u00a0\\u00a0\" + ";
		outfile << "retrieveTi(srcdoc, \"Tag" << dlg->sref << "\", \"" << con->sref << "\"));" << endl;
	};
	outfile << "// IP init --- IEND" << endl;

	// --- refreshDits
	outfile << "// IP refreshDits --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dits.nodes.size(); i++) {
		dit = dits.nodes[i];
		ditshort = dit->sref.substr(3);

		Wznm::loadDitcons(dbswznm, dit->ref, cons);
		Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT}, dit->ref, icsBasecons);

		outfile << "function refresh" << ditshort << "() {" << endl;
		outfile << "\t// IP refresh" << ditshort << ".vars --- BEGIN" << endl;
		hasdyn = false;

		for (unsigned int j = 0; j < icsBasecons.size(); j++) if (wrBconvarsJs(dbswznm, outfile, cons, icsBasecons, j, dlg->sref, ditshort)) hasdyn = true;

		if (hasdyn) outfile << "\tvar mytd, first;" << endl;
		outfile << "\t// IP refresh" << ditshort << ".vars --- END" << endl;
		outfile << endl;

		outfile << "\t// IP refresh" << ditshort << " --- BEGIN" << endl;
		for (unsigned int j = 0; j < icsBasecons.size(); j++) wrBconrefrJs(dbswznm, Prjshort, outfile, dlg->sref, cons, icsBasecons, j, dlg->sref, ditshort, true);
		outfile << "\t// IP refresh" << ditshort << " --- END" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP refreshDits --- IEND" << endl;

	// --- refresh.vars
	outfile << "// IP refresh.vars --- IBEGIN" << endl;
	outfile << "\t// IP refresh.vars --- BEGIN" << endl;
	for (unsigned int i = 0; i < ftrcons.nodes.size(); i++) {
		con = ftrcons.nodes[i];
		if (con->Active.length() > 0) outfile << "\tvar " << con->sref << "Active = (retrieveSi(srcdoc, \"StatShr" << dlg->sref << "\", \"" << con->sref << "Active\") == \"true\");" << endl;
	};
	outfile << "\t// IP refresh.vars --- END" << endl;
	outfile << "// IP refresh.vars --- IEND" << endl;

	// --- refresh.dits
	outfile << "// IP refresh.dits --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dits.nodes.size(); i++) {
		dit = dits.nodes[i];
		ditshort = dit->sref.substr(3);

		outfile << "\t\t";
		if (i != 0) outfile << "} else ";
		outfile << "if (shortDit == \"" << ditshort << "\") {" << endl;
		outfile << "\t\t\trefresh" << ditshort << "();" << endl;
	};
	if (dits.nodes.size() > 0) outfile << "\t\t};" << endl;
	outfile << "// IP refresh.dits --- IEND" << endl;

	// --- refresh
	outfile << "// IP refresh --- IBEGIN" << endl;
	outfile << "\t// IP refresh --- BEGIN" << endl;
	for (unsigned int i = 0; i < ftrcons.nodes.size(); i++) {
		con = ftrcons.nodes[i];
		if (con->Active.length() > 0) outfile << "\trefreshBut(ftrdoc, \"" << con->sref << "\", " << con->sref << "Active, false);" << endl;
	};
	outfile << "\t// IP refresh --- END" << endl;
	outfile << "// IP refresh --- IEND" << endl;

	// --- evthdls
	outfile << "// IP evthdls --- IBEGIN" << endl;
	dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::DLG, dlg->ref, false, cons);
	wrEvthdlsJs(dbswznm, Prjshort, outfile, cons, dlg->sref, false, true);
	outfile << "// IP evthdls --- IEND" << endl;

	// --- mergeDpchEngData
	outfile << "// IP mergeDpchEngData --- IBEGIN" << endl;
	wrSrcblksJs(dbswznm, outfile, dlg->refWznmMJob, "DpchEng" + dlg->sref + "Data");
	outfile << "// IP mergeDpchEngData --- IEND" << endl;

	// --- handleDpchEng
	outfile << "// IP handleDpchEng --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + dlg->sref.substr(3) + "Data") != 0) {
			outfile << "\t} else if (dpch == \"" << dpch->sref << "\") {" << endl;
			outfile << "\t\thandle" << dpch->sref << "(dom);" << endl;
		};
	};
	outfile << "// IP handleDpchEng --- IEND" << endl;

	// --- dpchhdls
	outfile << "// IP dpchhdls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + dlg->sref.substr(3) + "Data") != 0) {
			outfile << "function handle" << dpch->sref << "(dom) {" << endl;
			outfile << "\t// IP handle" << dpch->sref << " --- INSERT" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP dpchhdls --- IEND" << endl;
};

void WznmWrwebDlg::writeDlgndJsfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMDialog* dlg
			, ListWznmMControl& ftrcons
			, const string& Prjshort
		) {
	ListWznmMControl cons;
	WznmMControl* con = NULL;

	vector<unsigned int> icsBasecons;

	ListWznmMBlock dpchs;
	WznmMBlock* dpch = NULL;

	bool hasdyn;

	dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::DLG, dlg->ref, false, cons);
	Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT}, 0, icsBasecons);

	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB)
				+ " AND refUref = " + to_string(dlg->refWznmMJob) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") = " + to_string(VecWznmWScope::APP), false, dpchs);

	// --- init
	outfile << "// IP init --- IBEGIN" << endl;
	for (unsigned int i = 0; i < icsBasecons.size(); i++) wrBconiniJs(dbswznm, outfile, cons, icsBasecons, i, dlg->sref, "");
	outfile << endl;

	for (unsigned int i = 0; i < ftrcons.nodes.size(); i++) {
		con = ftrcons.nodes[i];

		outfile << "\tsetTextContent(ftrdoc, ftrdoc.getElementById(\"" << con->sref << "\"), ";
		if (i != 0) outfile << "\"\\u00a0\\u00a0\" + ";
		outfile << "retrieveTi(srcdoc, \"Tag" << dlg->sref << "\", \"" << con->sref << "\"));" << endl;
	};
	outfile << "// IP init --- IEND" << endl;

	// --- refresh.vars
	outfile << "// IP refresh.vars --- IBEGIN" << endl;
	outfile << "\t// IP refresh.vars --- BEGIN" << endl;
	hasdyn = false;
	for (unsigned int i = 0; i < icsBasecons.size(); i++) if (wrBconvarsJs(dbswznm, outfile, cons, icsBasecons, i, dlg->sref, "")) hasdyn = true;
	if (hasdyn) outfile << "\tvar mytd, first;" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < ftrcons.nodes.size(); i++) {
		con = ftrcons.nodes[i];
		if (con->Active.length() > 0) outfile << "\tvar " << con->sref << "Active = (retrieveSi(srcdoc, \"StatShr" << dlg->sref << "\", \"" << con->sref << "Active\") == \"true\");" << endl;
	};
	outfile << "\t// IP refresh.vars --- END" << endl;
	outfile << "// IP refresh.vars --- IEND" << endl;

	// --- refresh
	outfile << "// IP refresh --- IBEGIN" << endl;
	outfile << "\t// IP refresh --- BEGIN" << endl;
	for (unsigned int i = 0; i < icsBasecons.size(); i++) wrBconrefrJs(dbswznm, Prjshort, outfile, dlg->sref, cons, icsBasecons, i, dlg->sref, "", true);
	outfile << endl;

	for (unsigned int i = 0; i < ftrcons.nodes.size(); i++) {
		con = ftrcons.nodes[i];
		if (con->Active.length() > 0) outfile << "\trefreshBut(ftrdoc, \"" << con->sref << "\", " << con->sref << "Active, false);" << endl;
	};
	outfile << "\t// IP refresh --- END" << endl;
	outfile << "// IP refresh --- IEND" << endl;

	// --- evthdls
	outfile << "// IP evthdls --- IBEGIN" << endl;
	wrEvthdlsJs(dbswznm, Prjshort, outfile, cons, dlg->sref, false, true);
	outfile << "// IP evthdls --- IEND" << endl;

	// --- mergeDpchEngData
	outfile << "// IP mergeDpchEngData --- IBEGIN" << endl;
	wrSrcblksJs(dbswznm, outfile, dlg->refWznmMJob, "DpchEng" + dlg->sref + "Data");
	outfile << "// IP mergeDpchEngData --- IEND" << endl;

	// --- handleDpchEng
	outfile << "// IP handleDpchEng --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + dlg->sref.substr(3) + "Data") != 0) {
			outfile << "\t} else if (dpch == \"" << dpch->sref << "\") {" << endl;
			outfile << "\t\thandle" << dpch->sref << "(dom);" << endl;
		};
	};
	outfile << "// IP handleDpchEng --- IEND" << endl;

	// --- dpchhdls
	outfile << "// IP dpchhdls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + dlg->sref.substr(3) + "Data") != 0) {
			outfile << "function handle" << dpch->sref << "(dom) {" << endl;
			outfile << "\t// IP handle" << dpch->sref << " --- INSERT" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP dpchhdls --- IEND" << endl;
};
// IP cust --- IEND


