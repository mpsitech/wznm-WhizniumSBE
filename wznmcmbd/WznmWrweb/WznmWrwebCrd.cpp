/**
	* \file WznmWrwebCrd.cpp
	* Wznm operation processor - write web UI JS/HTML code for card (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrwebCrd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrweb;

/******************************************************************************
 namespace WznmWrwebCrd
 ******************************************************************************/

DpchRetWznm* WznmWrwebCrd::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrwebCrd* dpchinv
		) {
	ubigint refWznmMCard = dpchinv->refWznmMCard;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	fstream outfile;

	WznmMCard* car = NULL;

	ListWznmMPanel pnls;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	string s;

	if (dbswznm->tblwznmmcard->loadRecByRef(refWznmMCard, &car)) {
		dbswznm->tblwznmmpanel->loadRstByCar(car->ref, false, pnls);

		// CrdXxxxYyy.html
		s = xchg->tmppath + "/" + folder + "/" + car->sref + ".html.ip";
		outfile.open(s.c_str(), ios::out);
		writeCrdHtfile(dbswznm, outfile, car, pnls);
		outfile.close();

		// CrdXxxxYyy.js
		s = xchg->tmppath + "/" + folder + "/" + car->sref + ".js.ip";
		outfile.open(s.c_str(), ios::out);
		writeCrdJsfile(dbswznm, outfile, car, pnls);
		outfile.close();

		// MenXxx.html
		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(car->ref)
					+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::MEN) + " ORDER BY hkNum ASC", false, cons);
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			s = xchg->tmppath + "/" + folder + "/" + con->sref + ".html.ip";
			outfile.open(s.c_str(), ios::out);
			writeMenHtfile(dbswznm, outfile, car, con->ref);
			outfile.close();
		};

		delete car;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrwebCrd::writeCrdHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMCard* car
			, ListWznmMPanel& pnls
		) {
	WznmMPanel* pnl = NULL;

	// --- pnls
	outfile << "<!-- IP pnls - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM)) {
			outfile << "\t\t\t<tr class=\"show\" id=\"spc" << pnl->sref.substr(3+4+3) << "\">" << endl;
			outfile << "\t\t\t\t<td colspan=\"3\" height=\"10\"></td>" << endl;
			outfile << "\t\t\t</tr>" << endl;

			if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) {
				outfile << "\t\t\t<tr class=\"show\" id=\"tr" << pnl->sref.substr(3+4+3) << "\">" << endl;
				outfile << "\t\t\t\t<td id=\"td" << pnl->sref.substr(3+4+3) << "\" colspan=\"3\" height=\"18\"><iframe id=\"" << pnl->sref.substr(3+4+3) << "\" src=\"\" width=\"1000\" height=\"18\" frameborder=\"0\" scrolling=\"no\">This page needs a web-browser capable of displaying inline frames!</iframe></td>" << endl;
				outfile << "\t\t\t</tr>" << endl;

			} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) {
				outfile << "\t\t\t<tr class=\"show\" id=\"tr" << pnl->sref.substr(3+4+3) << "\">" << endl;
				outfile << "\t\t\t\t<td id=\"td" << pnl->sref.substr(3+4+3) << "\" height=\"38\"></td>" << endl;
				outfile << "\t\t\t\t<td class=\"pnl\"><iframe id=\"" << pnl->sref.substr(3+4+3) << "\" src=\"\" width=\"710\" height=\"30\" frameborder=\"0\" scrolling=\"no\">This page needs a web-browser capable of displaying inline frames!</iframe></td>" << endl;
				outfile << "\t\t\t\t<td></td>" << endl;
				outfile << "\t\t\t</tr>" << endl;
			};
		};
	};
	outfile << "<!-- IP pnls - IEND -->" << endl;
};

void WznmWrwebCrd::writeCrdJsfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMCard* car
			, ListWznmMPanel& pnls
		) {
	ubigint ref;

	ubigint refWznmMVersion;

	ubigint refMen;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	ListWznmMControl con2s;
	WznmMControl* con2 = NULL;

	WznmMPanel* pnl = NULL;

	ListWznmMDialog dlgs;
	WznmMDialog* dlg = NULL;

	bool hasmrl;

	uint cnt;
	unsigned int availcnt;

	bool first;

	string s;

	dbswznm->loadRefBySQL("SELECT verRefWznmMVersion FROM TblWznmMModule WHERE ref = " + to_string(car->mdlRefWznmMModule), refWznmMVersion);

	// --- checkInitdone
	outfile << "// IP checkInitdone --- IBEGIN" << endl;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype != VecWznmVMPanelBasetype::RECFORM) && (pnl->ixVBasetype != VecWznmVMPanelBasetype::RECLIST))
					outfile << "\tvar initdone" << pnl->sref.substr(3+4+3) << " = (retrieveSi(srcdoc, \"StatApp" << car->sref.substr(3) << "\", \"initdone" << pnl->sref.substr(3+4+3) << "\") == \"true\");" << endl;
	};
	outfile << endl;

	first = true;
	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype != VecWznmVMPanelBasetype::RECFORM) && (pnl->ixVBasetype != VecWznmVMPanelBasetype::RECLIST)) {
			outfile << "\t";
			if (first) first = false; else outfile << "} else ";
			outfile << "if (!initdone" << pnl->sref.substr(3+4+3) << ") {" << endl;
			outfile << "\t\tdoc.getElementById(\"" << pnl->sref.substr(3+4+3) << "\").src = \"./" << pnl->sref << ".html?scrJref=\" + scrJref" << pnl->sref.substr(3+4+3) << ";" << endl;
		};
	};
	
	outfile << "// IP checkInitdone --- IEND" << endl;

	// --- getHeight
	outfile << "// IP getHeight --- IBEGIN" << endl;
	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype != VecWznmVMPanelBasetype::HEADBAR) && (pnl->ixVBasetype != VecWznmVMPanelBasetype::RECFORM) && (pnl->ixVBasetype != VecWznmVMPanelBasetype::RECLIST)) {
			outfile << "\t";
			if (pnl->Avail.length() > 0) outfile << "if (doc.getElementById(\"tr" << pnl->sref.substr(3+4+3) << "\").getAttribute(\"class\") == \"show\") ";
			outfile << "height += 10 + parseInt(doc.getElementById(\"td" << pnl->sref.substr(3+4+3) << "\").getAttribute(\"height\"))";
			if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC)) outfile << " + 8";
			outfile << ";" << endl;
		};
	};
	outfile << "// IP getHeight --- IEND" << endl;

	// -- initMens
	outfile << "// IP initMens --- IBEGIN" << endl;

	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(car->ref)
				+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::MEN) + " ORDER BY hkNum ASC", false, cons);

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(con->ref) + " ORDER BY hkNum ASC", false, con2s);

		outfile << "function init" << con->sref << "() {" << endl;
		outfile << "\tvar mendoc = doc.getElementById(\"Menu\").contentDocument;" << endl;
		outfile << endl;

		availcnt = 0;
		for (unsigned int i = 0; i < con2s.nodes.size(); i++) if (con2s.nodes[i]->Avail != "") availcnt++;

		if (availcnt > 0) {
			outfile << "\tvar height = parseInt(doc.getElementById(\"Menu\").getAttribute(\"height\"));" << endl;
			outfile << endl;
		};

		for (unsigned int i = 0; i < con2s.nodes.size(); i++) {
			con2 = con2s.nodes[i];

			if (con2->Avail != "") outfile << "\t" << con2->sref << "Avail = (retrieveSi(srcdoc, \"StatShr" << car->sref.substr(3) << "\", \"" << con2->sref << "Avail\") == \"true\");" << endl;
			if (con2->Active != "") outfile << "\t" << con2->sref << "Active = (retrieveSi(srcdoc, \"StatShr" << car->sref.substr(3) << "\", \"" << con2->sref << "Active\") == \"true\");" << endl;
		};
		outfile << endl;

		outfile << "\tmendoc.getElementById(\"colCont\").setAttribute(\"width\", retrieveSi(srcdoc, \"StatApp" << car->sref.substr(3) << "\", \"widthMenu\"));" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < con2s.nodes.size(); i++) {
			con2 = con2s.nodes[i];

			if ((con2->ixVBasetype == VecWznmVMControlBasetype::MIT) || (con2->ixVBasetype == VecWznmVMControlBasetype::MRL) || ((con2->ixVBasetype == VecWznmVMControlBasetype::MTX) && (con2->ixVScope == VecWznmVMControlScope::APP))) {
				outfile << "\tsetTextContent(mendoc, mendoc.getElementById(\"" << con2->sref << "\"), retrieveTi(srcdoc, \"Tag" << car->sref.substr(3) << "\", \"" << con2->sref << "\"));" << endl;
				if (con2->Active.length() > 0) outfile << "\tsetMitActive(\"" << con2->sref << "\", " << con2->sref << "Active);" << endl;

			} else if ((con2->ixVBasetype == VecWznmVMControlBasetype::MTX) && (con2->ixVScope == VecWznmVMControlScope::SHR)) {
				outfile << "\tsetTextContent(mendoc, mendoc.getElementById(\"" << con2->sref << "\"), retrieveCi(srcdoc, \"ContInf" << car->sref.substr(3) << "\", \"" << con2->sref << "\"));" << endl;
			};
		};

		if (availcnt > 0) {
			outfile << endl;

			for (unsigned int i = 0; i < con2s.nodes.size(); i++) {
				con2 = con2s.nodes[i];

				if (con2->Avail.length() > 0) {
					if ((con2->ixVBasetype == VecWznmVMControlBasetype::MIT) || (con2->ixVBasetype == VecWznmVMControlBasetype::MRL) || (con2->ixVBasetype == VecWznmVMControlBasetype::MTX)) outfile << "\theight -= setMitMspAvail(\"" << con2->sref << "\", " << con2->sref << "Avail, 20);" << endl;
					else if (con2->ixVBasetype == VecWznmVMControlBasetype::MSP) outfile << "\theight -= setMitMspAvail(\"" << con2->sref << "\", " << con2->sref << "Avail, 1);" << endl;
				};
			};

			outfile << endl;
			outfile << "\tdoc.getElementById(\"Menu\").setAttribute(\"height\", \"\" + height);" << endl;
		};

		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP initMens --- IEND" << endl;

	// --- evthdls
	outfile << "// IP evthdls --- IBEGIN" << endl;

	dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::CAR, car->ref, false, cons);

	hasmrl = false;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVScope == VecWznmVMControlScope::APP) {
			// specific event handler for app control
			if ((con->ixVBasetype == VecWznmVMControlBasetype::MIT) || (con->ixVBasetype == VecWznmVMControlBasetype::MRL)) {
				outfile << "function handle" << con->sref << "Click() {" << endl;
				outfile << "\t// IP handle" << con->sref << "Click --- INSERT" << endl;
				outfile << "\thideMenu(\"" << con->sref.substr(3, 3) << "\");" << endl;
				outfile << "};" << endl;
				outfile << endl;
			};

		} else if ((con->ixVScope == VecWznmVMControlScope::SHR) && (con->ixVBasetype == VecWznmVMControlBasetype::MRL)) {
			hasmrl = true;
		};
	};

	// generalized event handlers for shared controls
	outfile << "function handleMitClick(menshort, consref) {" << endl;
	outfile << "\tvar str = serializeDpchAppDo(srcdoc, \"DpchApp" << car->sref.substr(3) << "Do\", scrJref, consref + \"Click\");" << endl;
	outfile << "\tsendReq(str, doc, handleDpchAppDoReply);" << endl;
	outfile << endl;
	outfile << "\thideMenu(menshort);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	if (hasAction(dbswznm, VecWznmVMControlHkTbl::CAR, car->ref, "crdopen")) {
		outfile << "function handleMitCrdopenClick(menshort, consref) {" << endl;
		outfile << "\tvar str = serializeDpchAppDo(srcdoc, \"DpchApp" << car->sref.substr(3) << "Do\", scrJref, consref + \"Click\");" << endl;
		outfile << "\tsendReq(str, doc, handleDpchAppDoCrdopenReply);" << endl;
		outfile << endl;
		outfile << "\thideMenu(menshort);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (hasmrl) {
		outfile << "function handleMrlClick(menshort, consref) {" << endl;
		outfile << "\twindow.open(retrieveCi(srcdoc, \"ContInf" << car->sref.substr(3) << "\", consref), \"_blank\");" << endl;
		outfile << endl;
		outfile << "\thideMenu(menshort);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	outfile << "// IP evthdls --- IEND" << endl;

	// --- attachPnl
	outfile << "// IP attachPnl --- IBEGIN" << endl;
	if (car->refIxVTbl == VecWznmVMCardRefTbl::VOID) {
		first = true;
		for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
			pnl = pnls.nodes[i];

			if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) && pnl->Detach) {
				outfile << "\t";
				if (first) first = false; else outfile << "else ";
				outfile << "if (scrJrefPnld == scrJref" << pnl->sref.substr(3+4+3) << ") doc.getElementById(\"" << pnl->sref.substr(3+4+3) << "\").contentWindow.handleLoad();" << endl;
			};
		};
	} else {
		outfile << "\tdoc.getElementById(\"Rec\").contentWindow.reinitPnl(scrJrefPnld);" << endl;
	};
	outfile << "// IP attachPnl --- IEND" << endl;

	// --- showDlg.height
	outfile << "// IP showDlg.height --- IBEGIN" << endl;

	outfile << "\tif (";

	cnt = 0;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if ((con->ixVBasetype == VecWznmVMControlBasetype::MIT) && (con->refIxVTbl == VecWznmVMControlRefTbl::DLG)) {
			if (dbswznm->tblwznmmdialog->loadRecByRef(con->refUref, &dlg)) {
				if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref) + " AND ixVBasetype = "
							+ to_string(VecWznmVMControlBasetype::DSE), ref)) {
					if (cnt != 0) outfile << " || ";
					outfile << "(sref == \"" << dlg->sref << "\")";

					cnt++;
				};

				delete dlg;
			};
		};
	};
	if (cnt == 0) outfile << "false";

	outfile << ") myif.setAttribute(\"height\", \"585\");" << endl;
	outfile << "\telse myif.setAttribute(\"height\", \"555\");" << endl;

	outfile << "// IP showDlg.height --- IEND" << endl;

	// --- changeHeight
	outfile << "// IP changeHeight --- IBEGIN" << endl;

	first = true;
	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC)) {
			outfile << "\t";
			if (first) first = false; else outfile << "} else ";
			outfile << "if (pnlshort == \"" << pnl->sref.substr(3+4+3) << "\") {" << endl;
			outfile << "\t\tdoc.getElementById(\"td" << pnl->sref.substr(3+4+3) << "\").setAttribute(\"height\", \"\" + height);" << endl;
			outfile << "\t\tdoc.getElementById(\"" << pnl->sref.substr(3+4+3) << "\").setAttribute(\"height\", \"\" + height);" << endl;
		};
	};
	if (!first) outfile << "\t};" << endl;
	outfile << "// IP changeHeight --- IEND" << endl;

	// --- refresh
	outfile << "// IP refresh --- IBEGIN" << endl;

	dbswznm->tblwznmmdialog->loadRstBySQL("SELECT * FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(car->ref) + " ORDER BY sref ASC", false, dlgs);

	for (unsigned int i = 0; i < dlgs.nodes.size(); i++) {
		dlg = dlgs.nodes[i];
		outfile << "\tvar scrJrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << " = retrieveSi(srcdoc, \"StatShr" << car->sref.substr(3) << "\", \"scrJrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << "\");" << endl;
	};

	availcnt = 0;
	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype != VecWznmVMPanelBasetype::RECFORM) && (pnl->ixVBasetype != VecWznmVMPanelBasetype::RECLIST) && (pnl->Avail.length() > 0)) {
			outfile << "\tvar pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "Avail = (retrieveSi(srcdoc, \"StatShr" << car->sref.substr(3) << "\", \"pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "Avail\") == \"true\");" << endl;
			availcnt++;
		};
	};

	if (dlgs.nodes.size() > 0) {
		outfile << endl;

		for (unsigned int i = 0; i < dlgs.nodes.size(); i++) {
			dlg = dlgs.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "} else ";
			outfile << "if (scrJrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << " != \"\") {" << endl;
			outfile << "\t\tif (scrJrefDlg != scrJrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << ") showDlg(\"" << dlg->sref << "\", scrJrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << ");" << endl;
		};

		outfile << "\t} else if (scrJrefDlg != \"\") hideDlg();" << endl;
	};

	if (availcnt > 0) {
		outfile << endl;

		for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
			pnl = pnls.nodes[i];
			
			if ((pnl->ixVBasetype != VecWznmVMPanelBasetype::RECFORM) && (pnl->ixVBasetype != VecWznmVMPanelBasetype::RECLIST) && (pnl->Avail.length() > 0))
						outfile << "\tsetPnlAvail(\"" << pnl->sref.substr(3+4+3) << "\", pnl" << StrMod::lc(pnl->sref.substr(3+4+3)) << "Avail);" << endl;
		};
	};

	if (car->refIxVTbl != VecWznmVMCardRefTbl::VOID) {
		outfile << endl;
		outfile << "\tdoc.title = retrieveCi(srcdoc, \"ContInf" << car->sref.substr(3) << "\", \"MtxCrd" << car->sref.substr(3+4) << "\") + \" - " << StubWznm::getStubVerStd(dbswznm, refWznmMVersion) << "\";" << endl;
	};
	
	outfile << "// IP refresh --- IEND" << endl;

	// --- mergeDpchEngData
	outfile << "// IP mergeDpchEngData --- IBEGIN" << endl;
	wrSrcblksJs(dbswznm, outfile, car->refWznmMJob, "DpchEng" + car->sref.substr(3) + "Data");
	outfile << "// IP mergeDpchEngData --- IEND" << endl;

	// --- handleDpchEngSub.subs
	outfile << "// IP handleDpchEngSub.subs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
			outfile << "\t} else if (_scrJref == scrJref" << pnl->sref.substr(3+4+3) << ") {" << endl;
			outfile << "\t\tdoc.getElementById(\"" << pnl->sref.substr(3+4+3) << "\").contentWindow.handleDpchEng(dom, dpch);" << endl;
		};
	};
	outfile << "// IP handleDpchEngSub.subs --- IEND" << endl;

	// --- handleDpchEngSub.listrec*
	if (car->refIxVTbl != VecWznmVMCardRefTbl::VOID) outfile << "// IP handleDpchEngSub.listrec --- AFFIRM" << endl;
	else outfile << "// IP handleDpchEngSub.listrec --- REMOVE" << endl;

	// --- handleDpchEngSub.invalid*
	if (car->refIxVTbl == VecWznmVMCardRefTbl::VOID) outfile << "// IP handleDpchEngSub.invalid --- AFFIRM" << endl;
	else outfile << "// IP handleDpchEngSub.invalid --- REMOVE" << endl;

	// --- handleDpchAppInitReply.scrJrefs
	outfile << "// IP handleDpchAppInitReply.scrJrefs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype != VecWznmVMPanelBasetype::RECFORM) && (pnl->ixVBasetype != VecWznmVMPanelBasetype::RECLIST))
					outfile << "\t\t\t\tscrJref" << pnl->sref.substr(3+4+3) << " = retrieveSi(srcdoc, \"StatShr" << car->sref.substr(3) << "\", \"scrJref" << pnl->sref.substr(3+4+3) << "\");" << endl;
	};
	outfile << "// IP handleDpchAppInitReply.scrJrefs --- IEND" << endl;

	// --- handleDpchAppDoCrdopenReply*
	if (hasAction(dbswznm, VecWznmVMControlHkTbl::CAR, car->ref, "crdopen")) outfile << "// IP handleDpchAppDoCrdopenReply --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDoCrdopenReply --- REMOVE" << endl;

	// --- terminate*
	if (car->sref.find("Nav") == string::npos) outfile << "// IP terminate --- AFFIRM" << endl;
	else outfile << "// IP terminate --- REMOVE" << endl;

	// --- terminateCrdnav*
	if (car->sref.find("Nav") == (3+4)) outfile << "// IP terminateCrdnav --- AFFIRM" << endl;
	else outfile << "// IP terminateCrdnav --- REMOVE" << endl;
};

void WznmWrwebCrd::writeMenHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMCard* car
			, const ubigint refMen
		) {
	ListWznmMControl cons;
	WznmMControl* con = NULL;

	string action;

	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(refMen) + " ORDER BY supNum ASC", false, cons);

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVScope == VecWznmVMControlScope::APP) {
			if ((con->ixVBasetype == VecWznmVMControlBasetype::MIT) || (con->ixVBasetype == VecWznmVMControlBasetype::MRL))
						outfile << "\t\t\tfunction handle" << con->sref << "Click() {parent.window.handle" << con->sref << "Click();};" << endl;

		} else if (con->ixVScope == VecWznmVMControlScope::SHR) {
			if (con->ixVBasetype == VecWznmVMControlBasetype::MIT) {
				action = "";
				if (con->refIxVTbl == VecWznmVMControlRefTbl::DLG) action = "dlgopen";
				else dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "action", 0, action);

				outfile << "\t\t\tfunction handle" << con->sref << "Click() {parent.window.";

				if (action == "crdopen") {
					outfile << "handleMitCrdopenClick(\"" << con->sref.substr(3, 3) << "\",\"" << con->sref << "\");";
				} else {
					outfile << "handleMitClick(\"" << con->sref.substr(3, 3) << "\",\"" << con->sref << "\");";
				};
				
				outfile << "};" << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::MRL) {
				outfile << "\t\t\tfunction handle" << con->sref << "Click() {parent.window.handleMrlClick(\"" << con->sref.substr(3, 3) << "\",\"" << con->sref << "\");};" << endl;
			};
		};
	};
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- mits
	outfile << "<!-- IP mits - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if ((con->ixVBasetype == VecWznmVMControlBasetype::MIT) || (con->ixVBasetype == VecWznmVMControlBasetype::MRL)) {
			outfile << "\t\t\t<tr id=\"tr" << con->sref << "\" class=\"show\">" << endl;
			outfile << "\t\t\t\t<td height=\"20\" class=\"frame\"></td><td class=\"iframe\"></td>" << endl;
			outfile << "\t\t\t\t<td class=\"iframe\"><span id=\"" << con->sref << "\" class=\"item\" onclick=\"handle" << con->sref << "Click()\">" << con->sref << "</span></td>" << endl;
			outfile << "\t\t\t</tr>" << endl;
		} else if (con->ixVBasetype == VecWznmVMControlBasetype::MSP) {
			outfile << "\t\t\t<tr id=\"tr" << con->sref << "\" class=\"show\">" << endl;
			outfile << "\t\t\t\t<td height=\"1\" colspan=\"3\" class=\"frame\"></td>" << endl;
			outfile << "\t\t\t</tr>" << endl;
		} else if (con->ixVBasetype == VecWznmVMControlBasetype::MTX) {
			outfile << "\t\t\t<tr id=\"tr" << con->sref << "\" class=\"show\">" << endl;
			outfile << "\t\t\t\t<td height=\"20\" class=\"frame\"></td><td class=\"iframe\"></td>" << endl;
			outfile << "\t\t\t\t<td class=\"iframe\"><span id=\"" << con->sref << "\" class=\"itemdis\"\">" << con->sref << "</span></td>" << endl;
			outfile << "\t\t\t</tr>" << endl;
		};
	};
	outfile << "<!-- IP mits - IEND -->" << endl;
};
// IP cust --- IEND


