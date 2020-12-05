/**
	* \file WznmWrwebPnl.cpp
	* Wznm operation processor - write web UI JS/HTML code for panel (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrwebPnl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrweb;

/******************************************************************************
 namespace WznmWrwebPnl
 ******************************************************************************/

DpchRetWznm* WznmWrwebPnl::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrwebPnl* dpchinv
		) {
	ubigint refWznmMPanel = dpchinv->refWznmMPanel;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream outfile;

	WznmMPanel* pnl = NULL;
	uint ixReltype;
	bool estapp = false;

	WznmMCard* car = NULL;
	bool haspst = false;

	bool hashdr, hasftr;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	vector<unsigned int> icsBasecons;

	uint cnt;
	string s;

	if (dbswznm->tblwznmmpanel->loadRecByRef(refWznmMPanel, &pnl)) {
		ixReltype = Wznm::getPnlreltype(dbswznm, pnl);

		dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, cons);
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->sref == "ButRegularize")) {
				estapp = (con->ixVScope == VecWznmVMControlScope::APP);
				break;
			};
		};

		if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) {
			// PnlXxxxYyyHeadbar_cont.xml
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_cont.xml.ip";
			outfile.open(s.c_str(), ios::out);
			writePhcXmfile(dbswznm, outfile, pnl);
			outfile.close();

			// PnlXxxxYyyHeadbar.js
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".js.ip";
			outfile.open(s.c_str(), ios::out);
			writePhJsfile(dbswznm, outfile, pnl);
			outfile.close();

		} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) {
			// PnlXxxxYyyZzzzz_cont_Headline.xml
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_cont.xml.ip";
			outfile.open(s.c_str(), ios::out);
			writePhlcXmfile(dbswznm, outfile, cons);
			outfile.close();

			// PnlXxxxYyyZzzzz_Headline.js
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".js.ip";
			outfile.open(s.c_str(), ios::out);
			writePhlJsfile(dbswznm, outfile, pnl, cons);
			outfile.close();

		} else if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM)) {
			// even detail panel has cpt in header
			hashdr = !((pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && (pnl->sref.find("Detail") != string::npos));

			hasftr = false;
			if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND hkIxVSection = "
						+ to_string(VecWznmVMControlHkSection::FTR) + " AND supRefWznmMControl = 0", cnt)) hasftr = (cnt > 0);

			Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT, VecWznmVMControlHkSection::CONTREGD}, 0, icsBasecons);

/*
			// DEBUG
			cout << "base control structure for panel '" << pnl->sref << "'" << endl;
			Wznm::showBasecons(dbswznm, cons, icsBasecons, "");
			cout << endl;
			//
*/

			// PnlXxxxYyyZzzzz_aside.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_aside.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePnlasHtfile(dbswznm, outfile, pnl);
			outfile.close();

			// PnlXxxxYyyZzzzz_b_Form/Recform.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_b.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePfbHtfile(outfile, hashdr, hasftr);
			outfile.close();

			// PnlXxxxYyyZzzzz_bcont_Form/Recform.xml
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_bcont.xml.ip";
			outfile.open(s.c_str(), ios::out);
			writePfbcXmfile(dbswznm, outfile, pnl, cons, icsBasecons, Prjshort);
			outfile.close();

			if (hasftr) {
				// PnlXxxxYyyZzzzz_bftr_Form/Recform.html (optional)
				s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_bftr.html.ip";
				outfile.open(s.c_str(), ios::out);
				writePfbfHtfile(dbswznm, outfile, cons, Prjshort);
				outfile.close();
			};

			if (hashdr) {
				// PnlXxxxYyyZzzzz_bhdr_Form/Recform.html (optional)
				s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_bhdr.html.ip";
				outfile.open(s.c_str(), ios::out);
				writePfbhHtfile(dbswznm, outfile, cons, Prjshort);
				outfile.close();
			};

			// PnlXxxxYyyZzzzz_bside.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_bside.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePnlbsHtfile(dbswznm, outfile, pnl);
			outfile.close();

			// PnlXxxxYyyZzzzz_Form/Recform.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".html.ip";
			outfile.open(s.c_str(), ios::out);
			writePfHtfile(dbswznm, outfile, pnl);
			outfile.close();

			// PnlXxxxYyyZzzzz_Form/Recform.js
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".js.ip";
			outfile.open(s.c_str(), ios::out);
			writePfJsfile(dbswznm, outfile, pnl, cons, icsBasecons, hashdr, hasftr, estapp, Prjshort);
			outfile.close();

			// PnlXxxxYyyZzzzz_LstXxx.xml
			for (unsigned int i = 0; i < cons.nodes.size(); i++) {
				con = cons.nodes[i];

				if (con->ixVBasetype == VecWznmVMControlBasetype::LST) {
					s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_" + con->sref + ".xml.ip";
					outfile.open(s.c_str(), ios::out);
					writeLstXmfile(outfile, con, (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM));
					outfile.close();
				};
			};

		} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
			if (dbswznm->tblwznmmcard->loadRecByRef(pnl->carRefWznmMCard, &car)) {
				haspst = (car->Active.length() > 0);
				delete car;
			};

			// PnlXxxxYyyList_a.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_a.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePlaHtfile(outfile, haspst);
			outfile.close();

			// PnlXxxxYyyList_bftr.xml
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_bftr.xml.ip";
			outfile.open(s.c_str(), ios::out);
			writePlbfXmfile(dbswznm, outfile, cons);
			outfile.close();

			// PnlXxxxYyyList_bhdr.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_bhdr.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePlbhHtfile(dbswznm, outfile, cons, haspst);
			outfile.close();

			// PnlXxxxYyyList_btbl.xml
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_btbl.xml.ip";
			outfile.open(s.c_str(), ios::out);
			writePlbtXmfile(dbswznm, outfile, cons);
			outfile.close();

			// PnlXxxxYyyList.js
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".js.ip";
			outfile.open(s.c_str(), ios::out);
			writePlJsfile(dbswznm, Prjshort, outfile, pnl, cons, haspst);
			outfile.close();

		} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) {
			// PnlXxxxYyyRec_lhs.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_lhs.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePrlhHtfile(dbswznm, outfile, pnl, Prjshort);
			outfile.close();

			// PnlXxxxYyyRec_rhs.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_rhs.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePrrhHtfile(dbswznm, outfile, pnl, Prjshort);
			outfile.close();

			// PnlXxxxYyyRec.js
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".js.ip";
			outfile.open(s.c_str(), ios::out);
			writePrJsfile(dbswznm, Prjshort, outfile, pnl, cons);
			outfile.close();

		} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
			// PnlXxxxYyyZzzzz_aside.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_aside.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePnlasHtfile(dbswznm, outfile, pnl);
			outfile.close();

			// PnlXxxxYyyZzzzz_bftr.xml
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_bftr.xml.ip";
			outfile.open(s.c_str(), ios::out);
			writePnlbfXmfile(dbswznm, outfile, cons);
			outfile.close();

			// PnlXxxxYyyZzzzz_bhdr.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_bhdr.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePnlbhHtfile(dbswznm, outfile, pnl, cons, ixReltype);
			outfile.close();

			// PnlXxxxYyyZzzzz_bside.html
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_bside.html.ip";
			outfile.open(s.c_str(), ios::out);
			writePnlbsHtfile(dbswznm, outfile, pnl);
			outfile.close();

			// PnlXxxxYyyZzzzz_btbl.xml
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + "_btbl.xml.ip";
			outfile.open(s.c_str(), ios::out);
			writePnlbtXmfile(dbswznm, outfile, cons);
			outfile.close();

			// PnlXxxxYyyZzzzz.js
			s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".js.ip";
			outfile.open(s.c_str(), ios::out);
			writePnlJsfile(dbswznm, Prjshort, outfile, pnl, cons, estapp);
			outfile.close();
		};

		delete pnl;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
// headbar panel
void WznmWrwebPnl::writePhcXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
		) {
	ListWznmMControl cons;
	WznmMControl* con = NULL;

	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(pnl->carRefWznmMCard)
				+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::MEN) + " ORDER BY hkNum ASC", false, cons);

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		outfile << "\t\t\tfunction handle" << con->sref << "Click() {parent.window.handle" << con->sref << "Click();};" << endl;
	};
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- cols
	outfile << "<!-- IP cols - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		outfile << "\t\t\t\t<col width=\"1\"/>" << endl;
		outfile << "\t\t\t\t<col id=\"col" << con->sref << "\" width=\"100\"/>" << endl;
	};
	outfile << "<!-- IP cols - IEND -->" << endl;

	// --- mens
	outfile << "<!-- IP mens - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		outfile << "\t\t\t\t<td class=\"menuline\" id=\"line" << con->sref << "\"></td>" << endl;
		outfile << "\t\t\t\t<td class=\"show\" id=\"td" << con->sref << "\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t<span class=\"";
		if (con->sref == "MenApp") outfile << "menuapp";
		else outfile << "menu"; 
		outfile << "\" id=\"" << con->sref << "\" onclick=\"handle" << con->sref << "Click()\">" << endl;
		outfile << "\t\t\t\t\t\t&nbsp;" << con->sref << "&nbsp;" << endl;
		outfile << "\t\t\t\t\t</span>" << endl;
		outfile << "\t\t\t\t</td>" << endl;
	};
	outfile << "<!-- IP mens - IEND -->" << endl;
};

void WznmWrwebPnl::writePhJsfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
		) {
	ListWznmMControl cons;
	WznmMControl* con = NULL;

	ListWznmMControl con2s;
	WznmMControl* con2 = NULL;

	unsigned int h;

	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(pnl->carRefWznmMCard)
				+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::MEN) + " ORDER BY hkNum ASC", false, cons);

	// --- getMenLeft
	outfile << "// IP getMenLeft --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		outfile << "\tif (short == \"" << con->sref.substr(3) << "\") return(left);" << endl;
		outfile << "\t";
		if (con->Avail != "") outfile << "if (getMenAvail(\"" << con->sref.substr(3) << "\")) ";
		outfile << "left += getMenCptwidth(\"" << con->sref.substr(3) << "\") + 1;" << endl;
		outfile << endl;
	};
	outfile << "// IP getMenLeft --- IEND" << endl;

	// --- init
	outfile << "// IP init --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		outfile << "\tw = getMenCptwidth(\"" << con->sref.substr(3) << "\"); contdoc.getElementById(\"col" << con->sref << "\").setAttribute(\"width\", \"\" + w); wFill -= w + 1;" << endl;

		outfile << "\tsetTextContent(contdoc, contdoc.getElementById(\"" << con->sref << "\"), \"\\\\u00a0\" + retrieveTi(srcdoc, \"Tag" << pnl->sref.substr(3) << "\", \"" << con->sref << "\") + \"\\\\u00a0\");" << endl;

		if (con->Avail != "") outfile << "\tif (!getMenAvail(\"" << con->sref.substr(3) << "\")) contdoc.getElementById(\"td" << con->sref << "\").setAttribute(\"class\", \"hide\");" << endl;
	};
	outfile << "// IP init --- IEND" << endl;

	// --- evthdls
	outfile << "// IP evthdls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		h = 0;

		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(con->ref) + " ORDER BY hkNum ASC", false, con2s);

		for (unsigned int j = 0; j < con2s.nodes.size(); j++) {
			con2 = con2s.nodes[j];

			if (con2->ixVBasetype == VecWznmVMControlBasetype::MIT) h += 20;
			else if (con2->ixVBasetype == VecWznmVMControlBasetype::MRL) h += 20;
			else if (con2->ixVBasetype == VecWznmVMControlBasetype::MSP) h += 1;
			else if (con2->ixVBasetype == VecWznmVMControlBasetype::MTX) h += 20;
		};

		outfile << "function handle" << con->sref << "Click() {" << endl;
		outfile << "\tgetCrdwnd().toggleMenu(\"" << con->sref.substr(3) << "\", getMenLeft(\"" << con->sref.substr(3) << "\"), parseInt(retrieveSi(srcdoc, \"StgInf" << pnl->sref.substr(3) << "\", \"" << con->sref << "Width\")), " << h << ");" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP evthdls --- IEND" << endl;

	// --- mergeDpchEngData
	outfile << "// IP mergeDpchEngData --- IBEGIN" << endl;
	wrSrcblksJs(dbswznm, outfile, pnl->refWznmMJob, "DpchEng" + pnl->sref.substr(3) + "Data");
	outfile << "// IP mergeDpchEngData --- IEND" << endl;
};

// headline panel
void WznmWrwebPnl::writePhlcXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
		) {
	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::CONT}, "", 1);
	outfile << "<!-- IP evthdls - IEND -->" << endl;
};

void WznmWrwebPnl::writePhlJsfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
		) {
	WznmMControl* con = NULL;

	string conshort;

	// --- init
	outfile << "// IP init --- IBEGIN" << endl;
	outfile << "// IP init --- INSERT" << endl;
	outfile << "// IP init --- IEND" << endl;

	// --- refresh
	outfile << "// IP refresh --- IBEGIN" << endl;

	if (pnl->sref.find("Nav") == (3+4)) {
		outfile << "\tvar line;" << endl;
		outfile << endl;

		outfile << "\tvar n = 0;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->ixVBasetype == VecWznmVMControlBasetype::TXT) {
				conshort = con->sref.substr(3, 3);

				outfile << "\tvar Txt" << conshort << "Avail = (retrieveSi(srcdoc, \"StatShr" << pnl->sref.substr(3) << "\", \"Txt" << conshort << "Avail\") == \"true\"); if (Txt" << conshort << "Avail) n++;" << endl;
			};
		};
		outfile << endl;

		outfile << "\tline = contdoc.getElementById(\"line\");" << endl;
		outfile << "\twhile (line.firstChild) line.removeChild(line.firstChild);" << endl;
		outfile << endl;

		outfile << "\tvar i = 0;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->ixVBasetype == VecWznmVMControlBasetype::TXT) {
				conshort = con->sref.substr(3, 3);

				outfile << "\tif (Txt" << conshort << "Avail) {" << endl;
				outfile << "\t\ti++;" << endl;
				outfile << endl;

				outfile << "\t\tline.appendChild(makeImgBut(\"But" << conshort << "Remove\", \"icon/close\"));" << endl;
				outfile << "\t\tif (i == n) line.appendChild(makeSpanCpt(\"\\u00a0\" + retrieveTi(srcdoc,  \"Tag" << pnl->sref.substr(3) << "\", \"Cpt" << conshort << "\") + \": \" + retrieveCi(srcdoc, \"ContInf" << pnl->sref.substr(3) << "\", \"Txt" << conshort << "\")));" << endl;
				outfile << "\t\telse line.appendChild(makeSpanCpt(\"\\u00a0\" + retrieveTi(srcdoc, \"Tag" << pnl->sref.substr(3) << "\", \"Cpt" << conshort << "\") + \": \" + retrieveCi(srcdoc, \"ContInf" << pnl->sref.substr(3) << "\", \"Txt" << conshort << "\") + \",\\u00a0\\u00a0\"));" << endl;
				outfile << "\t};" << endl;
				outfile << endl;
			};
		};

	} else {
		outfile << "// IP refresh --- INSERT" << endl;
	};

	outfile << "// IP refresh --- IEND" << endl;

	// --- mergeDpchEngData
	outfile << "// IP mergeDpchEngData --- IBEGIN" << endl;
	wrSrcblksJs(dbswznm, outfile, pnl->refWznmMJob, "DpchEng" + pnl->sref.substr(3) + "Data");
	outfile << "// IP mergeDpchEngData --- IEND" << endl;
};

// form / recform panel
void WznmWrwebPnl::writePfbHtfile(
			fstream& outfile
			, const bool hashdr
			, const bool hasftr
		) {
	// --- hdr*
	if (hashdr) outfile << "<!-- IP hdr - AFFIRM -->" << endl;
	else outfile << "<!-- IP hdr - REMOVE -->" << endl;

	// --- ftr*
	if (hasftr) outfile << "<!-- IP ftr - AFFIRM -->" << endl;
	else outfile << "<!-- IP ftr - REMOVE -->" << endl;
};

void WznmWrwebPnl::writePfbcXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const string& Prjshort
		) {
	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::CONT, VecWznmVMControlHkSection::CONTREGD}, "", 2);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- ctlrows
	outfile << "<!-- IP ctlrows - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < icsBasecons.size(); i++) wrBaseconXml(dbswznm, Prjshort, outfile, pnl->sref, cons, icsBasecons, i, "", pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM);
	outfile << "<!-- IP ctlrows - IEND -->" << endl;
};

void WznmWrwebPnl::writePfbfHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
			, const string& Prjshort
		) {
	WznmMControl* con = NULL;

	string s;

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::FTR}, "", 2);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- buts
	outfile << "<!-- IP buts - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->hkIxVSection == VecWznmVMControlHkSection::FTR)) {
			if (StrMod::srefInSrefs(con->srefsKOption, "icon")) {
				s = getButicon(dbswznm, Prjshort, con);

				outfile << "\t\t\t\t\t";
				if (i != 0) outfile << "&#160;";
				outfile << "<img id=\"" << con->sref << "\" class=\"ftr_but\" src=\"../" << s << ".png\" width=\"16\" height=\"16\" alt=\"" << con->sref
							<< "\" onmouseover=\"src='../" << s << "_hlt.png'\" onmouseout=\"src='../" << s << ".png'\" onclick=\"handle" << con->sref << "Click()\"/>" << endl;

			} else {
				outfile << "\t\t\t\t\t<span id=\"" << con->sref << "\" class=\"ftr_but\" onclick=\"handle" << con->sref << "Click()\">";
				if (i != 0) outfile << "&#160;&#160;";
				outfile << con->sref << "</span>" << endl;
			};
		};
	};
	outfile << "<!-- IP buts - IEND -->" << endl;
};

void WznmWrwebPnl::writePfbhHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
			, const string& Prjshort
		) {
	WznmMControl* con = NULL;

	string s;

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::HDR, VecWznmVMControlHkSection::HDRDETD, VecWznmVMControlHkSection::HDRREGD}, "", 2);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- buts
	outfile << "<!-- IP buts - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRDETD) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRREGD))) {
			if (StrMod::srefInSrefs(con->srefsKOption, "icon")) {
				s = getButicon(dbswznm, Prjshort, con);

				outfile << "\t\t\t\t\t";
				if (i != 0) outfile << "&#160;";
				outfile << "<img id=\"" << con->sref << "\" class=\"hdr_but\" src=\"../" << s << ".png\" width=\"16\" height=\"16\" alt=\"" << con->sref
							<< "\" onmouseover=\"src='../" << s << "_hlt.png'\" onmouseout=\"src='../" << s << ".png'\" onclick=\"handle" << con->sref << "Click()\"/>" << endl;

			} else {
				outfile << "\t\t\t\t\t<span id=\"" << con->sref << "\" class=\"hdr_but\" onclick=\"handle" << con->sref << "Click()\">";
				if (i != 0) outfile << "&#160;&#160;";
				outfile << con->sref << "</span>" << endl;
			};
		};
	};
	outfile << "<!-- IP buts - IEND -->" << endl;
};

void WznmWrwebPnl::writePfHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
		) {
	uint cnt;

	// --- scrs
	outfile << "<!-- IP scrs - IBEGIN -->" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::HSB), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/hsb.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::LST), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/lst.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::PUP), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/pup.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::RBU), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/rbu.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::SLD), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/sld.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::UPD), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/upd.js\" type=\"text/javascript\"></script>" << endl;
	if (getJobvecio(dbswznm, pnl->refWznmMJob)) outfile << "\t\t<script src=\"../script/vecio.js\" type=\"text/javascript\"></script>" << endl;
	if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND ixVBasetype = "
				+ to_string(VecWznmVMControlBasetype::VSB), cnt)) if (cnt > 0) outfile << "\t\t<script src=\"../script/vsb.js\" type=\"text/javascript\"></script>" << endl;
	outfile << "<!-- IP scrs - IEND -->" << endl;
};

void WznmWrwebPnl::writePfJsfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const bool hashdr
			, const bool hasftr
			, const bool estapp
			, const string& Prjshort
		) {
	WznmMControl* con = NULL;

	ListWznmMBlock dpchs;
	WznmMBlock* dpch = NULL;

	bool hasdyn;

	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB)
				+ " AND refUref = " + to_string(pnl->refWznmMJob) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") = " + to_string(VecWznmWScope::APP), false, dpchs);

	// --- minimize.estapp*
	if (estapp) outfile << "// IP minimize.estapp --- AFFIRM" << endl;
	else outfile << "// IP minimize.estapp --- REMOVE" << endl;

	// --- regularize.estapp*
	if (estapp) outfile << "// IP regularize.estapp --- AFFIRM" << endl;
	else outfile << "// IP regularize.estapp --- REMOVE" << endl;

	// --- initBD.hdrdoc*
	if (hashdr) outfile << "// IP initBD.hdrdoc --- AFFIRM" << endl;
	else outfile << "// IP initBD.hdrdoc --- REMOVE" << endl;

	// --- initBD.ftrdoc*
	if (hasftr) outfile << "// IP initBD.ftrdoc --- AFFIRM" << endl;
	else outfile << "// IP initBD.ftrdoc --- REMOVE" << endl;

	// --- initBD
	outfile << "// IP initBD --- IBEGIN" << endl;
	outfile << "\t// IP initBD --- BEGIN" << endl;

	if (hashdr) {
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRDETD) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRREGD)) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::CPT) {
					outfile << "\tinitCpt(hdrdoc, \"" << con->sref << "\", retrieveTi(srcdoc, \"Tag" << pnl->sref.substr(3) << "\", \"" << con->sref << "\"));" << endl;
				};
			};
		};
	};

	for (unsigned int i = 0; i < icsBasecons.size(); i++) wrBconiniJs(dbswznm, outfile, cons, icsBasecons, i, pnl->sref.substr(3), "");

	outfile << "\t// IP initBD --- END" << endl;
	outfile << "// IP initBD --- IEND" << endl;

	// --- init.estapp*
	if (estapp) outfile << "// IP init.estapp --- AFFIRM" << endl;
	else outfile << "// IP init.estapp --- REMOVE" << endl;

	// --- init.estshr*
	if (!estapp) outfile << "// IP init.estshr --- AFFIRM" << endl;
	else outfile << "// IP init.estshr --- REMOVE" << endl;

	// --- refreshBD.vars
	outfile << "// IP refreshBD.vars --- IBEGIN" << endl;
	outfile << "\t// IP refreshBD.vars --- BEGIN" << endl;
	hasdyn = false;

	if (hashdr) {
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRDETD) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRREGD)) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
					if (con->Active.length() > 0) outfile << "\tvar " << con->sref << "Active = (retrieveSi(srcdoc, \"" << Wznm::getConstatblk(con) << pnl->sref.substr(3) << "\", \"" << con->sref << "Active\") == \"true\");" << endl;
				};
			};
		};
	};

	for (unsigned int i = 0; i < icsBasecons.size(); i++) if (wrBconvarsJs(dbswznm, outfile, cons, icsBasecons, i, pnl->sref.substr(3), "")) hasdyn = true;

	if (hasftr) {
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->hkIxVSection == VecWznmVMControlHkSection::FTR) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
					if (con->Active.length() > 0) outfile << "\tvar " << con->sref << "Active = (retrieveSi(srcdoc, \"" << Wznm::getConstatblk(con) << pnl->sref.substr(3) << "\", \"" << con->sref << "Active\") == \"true\");" << endl;
				};
			};
		};
	};

	if (hasdyn) outfile << "\tvar mytd, first;" << endl;
	outfile << "\t// IP refreshBD.vars --- END" << endl;
	outfile << "// IP refreshBD.vars --- IEND" << endl;

	// --- refreshBD
	outfile << "// IP refreshBD --- IBEGIN" << endl;
	outfile << "\t// IP refreshBD --- BEGIN" << endl;

	if (hashdr) {
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRDETD) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRREGD)) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
					if ( (con->Active.length() > 0) || (StrMod::srefInSrefs(con->srefsKOption, "onoff")) ) {
						if (StrMod::srefInSrefs(con->srefsKOption, "icon")) outfile << "\trefreshButicon(hdrdoc, \"" << con->sref << "\", \"" << getButicon(dbswznm, Prjshort, con) << "\"";
						else outfile << "\trefreshBut(hdrdoc, \"" << con->sref << "\"";
						if (con->Active.length() > 0) outfile << ", " << con->sref << "Active"; else outfile << ", true";
						if (StrMod::srefInSrefs(con->srefsKOption, "onoff")) outfile << ", retrieveCi(srcdoc, \"ContInf" << pnl->sref.substr(3) << "\", \"" << con->sref << "On\") == \"true\""; else outfile << ", false";
						outfile << ");" << endl;
					};
				};
			};
		};
	};

	for (unsigned int i = 0; i < icsBasecons.size(); i++) wrBconrefrJs(dbswznm, Prjshort, outfile, pnl->sref, cons, icsBasecons, i, pnl->sref.substr(3), "", pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM);

	if (hasftr) {
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->hkIxVSection == VecWznmVMControlHkSection::FTR) {
				if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
					if ( (con->Active.length() > 0) || (StrMod::srefInSrefs(con->srefsKOption, "onoff")) ) {
						if (StrMod::srefInSrefs(con->srefsKOption, "icon")) outfile << "\trefreshButicon(ftrdoc, \"" << con->sref << "\", \"" << getButicon(dbswznm, Prjshort, con) << "\"";
						else outfile << "\trefreshBut(ftrdoc, \"" << con->sref << "\"";
						if (con->Active.length() > 0) outfile << ", " << con->sref << "Active"; else outfile << ", true";
						if (StrMod::srefInSrefs(con->srefsKOption, "onoff")) outfile << ", retrieveCi(srcdoc, \"ContInf" << pnl->sref.substr(3) << "\", \"" << con->sref << "On\") == \"true\""; else outfile << ", false";
						outfile << ");" << endl;
					};
				};
			};
		};
	};

	outfile << "\t// IP refreshBD --- END" << endl;
	outfile << "// IP refreshBD --- IEND" << endl;

	// --- refresh.estapp*
	if (estapp) outfile << "// IP refresh.estapp --- AFFIRM" << endl;
	else outfile << "// IP refresh.estapp --- REMOVE" << endl;

	// --- refresh.estshr*
	if (!estapp) outfile << "// IP refresh.estshr --- AFFIRM" << endl;
	else outfile << "// IP refresh.estshr --- REMOVE" << endl;

	// --- evthdls
	outfile << "// IP evthdls --- IBEGIN" << endl;
	wrEvthdlsJs(dbswznm, Prjshort, outfile, cons, pnl->sref.substr(3), false, pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM);
	outfile << "// IP evthdls --- IEND" << endl;

	// --- mergeDpchEngData
	outfile << "// IP mergeDpchEngData --- IBEGIN" << endl;
	wrSrcblksJs(dbswznm, outfile, pnl->refWznmMJob, "DpchEng" + pnl->sref.substr(3) + "Data");
	outfile << "// IP mergeDpchEngData --- IEND" << endl;

	// --- handleDpchEng.estapp*
	if (estapp) outfile << "// IP handleDpchEng.estapp --- AFFIRM" << endl;
	else outfile << "// IP handleDpchEng.estapp --- REMOVE" << endl;

	// --- handleDpchEng.estshr*
	if (!estapp) outfile << "// IP handleDpchEng.estshr --- AFFIRM" << endl;
	else outfile << "// IP handleDpchEng.estshr --- REMOVE" << endl;

	// --- handleDpchEng
	outfile << "// IP handleDpchEng --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + pnl->sref.substr(3) + "Data") != 0) {
			outfile << "\t} else if (dpch == \"" << dpch->sref << "\") {" << endl;
			outfile << "\t\thandle" << dpch->sref << "(dom);" << endl;
		};
	};
	outfile << "// IP handleDpchEng --- IEND" << endl;

	// --- dpchhdls
	outfile << "// IP dpchhdls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + pnl->sref.substr(3) + "Data") != 0) {
			outfile << "function handle" << dpch->sref << "(dom) {" << endl;
			outfile << "\t// IP handle" << dpch->sref << " --- INSERT" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP dpchhdls --- IEND" << endl;

	// --- handleDpchAppDataDoReply.estapp*
	if (estapp) outfile << "// IP handleDpchAppDataDoReply.estapp --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDataDoReply.estapp --- REMOVE" << endl;

	// --- handleDpchAppDataDoReply.estshr*
	if (!estapp) outfile << "// IP handleDpchAppDataDoReply.estshr --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDataDoReply.estshr --- REMOVE" << endl;

	// --- handleDpchAppDataDoReply
	outfile << "// IP handleDpchAppDataDoReply --- IBEGIN" << endl;
	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + pnl->sref.substr(3) + "Data") != 0) {
			outfile << "\t\t\t} else if (blk.nodeName == \"" << dpch->sref << "\") {" << endl;
			outfile << "\t\t\t\thandle" << dpch->sref << "(dom);" << endl;
		};
	};
	outfile << "// IP handleDpchAppDataDoReply --- IEND" << endl;

	// --- handleDpchAppDoCrdopenReply*
	if (hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, pnl->ref, "crdopen")) outfile << "// IP handleDpchAppDoCrdopenReply --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDoCrdopenReply --- REMOVE" << endl;

	// --- handleDpchAppDoDlgopenReply*
	if (hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, pnl->ref, "dlgopen")) outfile << "// IP handleDpchAppDoDlgopenReply --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDoDlgopenReply --- REMOVE" << endl;
};

// list panel
void WznmWrwebPnl::writePlaHtfile(
			fstream& outfile
			, const bool haspst
		) {
	// --- pre*
	if (haspst) outfile << "<!-- IP pre - AFFIRM -->" << endl;
	else outfile << "<!-- IP pre - REMOVE -->" << endl;
};

void WznmWrwebPnl::writePlbfXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
		) {
	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::FTR}, "", 2);
	outfile << "<!-- IP evthdls - IEND -->" << endl;
};

void WznmWrwebPnl::writePlbhHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
			, const bool haspst
		) {
	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::HDR}, "", 2);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- pre*
	if (haspst) outfile << "<!-- IP pre - AFFIRM -->" << endl;
	else outfile << "<!-- IP pre - REMOVE -->" << endl;
};

void WznmWrwebPnl::writePlbtXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
		) {
	WznmMControl* con = NULL;

	unsigned int ncol, w, j;

	ncol = 0;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) if (cons.nodes[i]->ixVBasetype == VecWznmVMControlBasetype::TCO) ncol++;

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::TBL}, "", 2);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- colgrp
	outfile << "<!-- IP colgrp - IBEGIN -->" << endl;
	// total width: 901
	if (ncol > 0) {
		w = 901 / ncol;
		w = w - (w%5);

		j = 0;
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) {
				j++;

				if (j == ncol) outfile << "\t\t\t\t<col width=\"" << (901 - (ncol-1)*w) << "\"></col>" << endl;
				else outfile << "\t\t\t\t<col width=\"" << w << "\"></col>" << endl;
			};
		};
	};
	outfile << "<!-- IP colgrp - IEND -->" << endl;

	// --- cols
	outfile << "<!-- IP cols - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) outfile << "\t\t\t\t<td class=\"col\" id=\"" << con->sref << "\">" << con->sref << "</td>" << endl;
	};
	outfile << "<!-- IP cols - IEND -->" << endl;
};

void WznmWrwebPnl::writePlJsfile(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
			, const bool haspst
		) {
	WznmMControl* con = NULL;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	string s;

	unsigned int ix;

	bool found;

	// find table order vector items
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVBasetype == VecWznmVMControlBasetype::TOS) {
			dbswznm->tblwznmmvectoritem->loadRstBySQL("SELECT TblWznmMVectoritem.* FROM TblWznmMVectoritem, TblWznmMVector, TblWznmMFeed  WHERE TblWznmMFeed.ref = " + to_string(con->refWznmMFeed)
						+ " AND TblWznmMVector.ref = TblWznmMFeed.srcUref AND TblWznmMVectoritem.vecRefWznmMVector = TblWznmMVector.ref ORDER BY TblWznmMVectoritem.vecNum ASC", false, vits);

			break;
		};
	};

	// --- refreshA.pre*
	if (haspst) outfile << "// IP refreshA.pre --- AFFIRM" << endl;
	else outfile << "// IP refreshA.pre --- REMOVE" << endl;

	// --- refreshA.nopre*
	if (!haspst) outfile << "// IP refreshA.nopre --- AFFIRM" << endl;
	else outfile << "// IP refreshA.nopre --- REMOVE" << endl;

	// --- refreshB.pre*
	if (haspst) outfile << "// IP refreshB.pre --- AFFIRM" << endl;
	else outfile << "// IP refreshB.pre --- REMOVE" << endl;

	// --- refreshB.colsDecl
	outfile << "// IP refreshB.colsDecl --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) outfile << "\t\tvar " << con->sref << "Width = parseInt(retrieveSi(srcdoc, \"StgIac" << pnl->sref.substr(3) << "\", \"" << con->sref << "Width\"));" << endl;
	};
	outfile << "// IP refreshB.colsDecl --- IEND" << endl;

	// --- refreshB.colsLineup
	outfile << "// IP refreshB.colsLineup --- IBEGIN" << endl;
	ix = 1;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) {
			outfile << "\t\t\t";
			if (ix != 1) outfile << "} else ";
			outfile << "if (i == " << (ix++) << ") {" << endl;

			outfile << "\t\t\t\tdoc.cols.push(\"" << con->sref << "\"); doc.widths.push(" << con->sref << "Width);";

			s = "";
			dbswznm->loadStringBySQL("SELECT Short FROM TblWznmMQuerycol WHERE ref = " + to_string(con->refUref), s);

			outfile << " doc.fs.push(\"" << s << "\");";

			s = StrMod::lc(s);

			found = false;
			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];

				if (vit->sref.compare(s) == 0) {
					outfile << " doc.tos.push(" << vit->vecNum << ");";

					found = true;
					break;
				};
			};
			if (!found) outfile << " doc.tos.push(0);";

			outfile << " wtot += " << con->sref << "Width;" << endl;
		};
	};
	outfile << "// IP refreshB.colsLineup --- IEND" << endl;

	// --- evthdls
	outfile << "// IP evthdls --- IBEGIN" << endl;
/// HERE
	wrEvthdlsJs(dbswznm, Prjshort, outfile, cons, pnl->sref.substr(3), true, false);
	outfile << "// IP evthdls --- IEND" << endl;

	// --- mergeDpchEngData
	outfile << "// IP mergeDpchEngData --- IBEGIN" << endl;
	wrSrcblksJs(dbswznm, outfile, pnl->refWznmMJob, "DpchEng" + pnl->sref.substr(3) + "Data");
	outfile << "// IP mergeDpchEngData --- IEND" << endl;

	// --- handleDpchAppDoDlgopenReply*
	if (hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, pnl->ref, "dlgopen")) outfile << "// IP handleDpchAppDoDlgopenReply --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDoDlgopenReply --- REMOVE" << endl;
};

// rec panel
void WznmWrwebPnl::writePrlhHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
			, const string& Prjshort
		) {
	ListWznmMPanel crdpnls;
	WznmMPanel* crdpnl = NULL;

	// --- pnls
	outfile << "<!-- IP pnls - IBEGIN -->" << endl;
	dbswznm->tblwznmmpanel->loadRstByCar(pnl->carRefWznmMCard, false, crdpnls);
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if (Wznm::getPnllhs(dbswznm, crdpnl)) {
			outfile << "\t\t\t<tr class=\"show\" id=\"spc" << crdpnl->sref.substr(3+4+3) << "\">" << endl;
			outfile << "\t\t\t\t<td colspan=\"3\" height=\"5\"></td>" << endl;
			outfile << "\t\t\t</tr>" << endl;

			outfile << "\t\t\t<tr class=\"show\" id=\"tr" << crdpnl->sref.substr(3+4+3) << "\">" << endl;
			outfile << "\t\t\t\t<td id=\"td" << crdpnl->sref.substr(3+4+3) << "\" height=\"30\"></td>" << endl;
			outfile << "\t\t\t\t<td class=\"pnl\"><iframe id=\"" << crdpnl->sref.substr(3+4+3) << "\" src=\"\" width=\"460\" height=\"30\" frameborder=\"0\" scrolling=\"no\">This page needs a web-browser capable of displaying inline frames!</iframe></td>" << endl;
			outfile << "\t\t\t\t<td></td>" << endl;
			outfile << "\t\t\t</tr>" << endl;
		};
	};
	outfile << "<!-- IP pnls - IEND -->" << endl;
};

void WznmWrwebPnl::writePrrhHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
			, const string& Prjshort
		) {
	ListWznmMPanel crdpnls;
	WznmMPanel* crdpnl = NULL;

	// --- pnls
	outfile << "<!-- IP pnls - IBEGIN -->" << endl;
	dbswznm->tblwznmmpanel->loadRstByCar(pnl->carRefWznmMCard, false, crdpnls);
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if (Wznm::getPnlrhs(dbswznm, crdpnl)) {
			outfile << "\t\t\t<tr class=\"show\" id=\"spc" << crdpnl->sref.substr(3+4+3) << "\">" << endl;
			outfile << "\t\t\t\t<td colspan=\"3\" height=\"5\"></td>" << endl;
			outfile << "\t\t\t</tr>" << endl;

			outfile << "\t\t\t<tr class=\"show\" id=\"tr" << crdpnl->sref.substr(3+4+3) << "\">" << endl;
			outfile << "\t\t\t\t<td id=\"td" << crdpnl->sref.substr(3+4+3) << "\" height=\"30\"></td>" << endl;
			outfile << "\t\t\t\t<td class=\"pnl\"><iframe id=\"" << crdpnl->sref.substr(3+4+3) << "\" src=\"\" width=\"460\" height=\"30\" frameborder=\"0\" scrolling=\"no\">This page needs a web-browser capable of displaying inline frames!</iframe></td>" << endl;
			outfile << "\t\t\t\t<td></td>" << endl;
			outfile << "\t\t\t</tr>" << endl;
		};
	};
	outfile << "<!-- IP pnls - IEND -->" << endl;
};

void WznmWrwebPnl::writePrJsfile(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
		) {
	ListWznmMPanel crdpnls;
	WznmMPanel* crdpnl = NULL;

	unsigned int pnlcnt;

	unsigned int availcnt;

	bool first;

	dbswznm->tblwznmmpanel->loadRstByCar(pnl->carRefWznmMCard, false, crdpnls);

	availcnt = 0;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) if (crdpnls.nodes[i]->Avail.length() > 0) availcnt++;

	// --- updateScrJrefs
	outfile << "// IP updateScrJrefs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST))
					outfile << "\tscrJref" << crdpnl->sref.substr(3+4+3) << " = retrieveSi(srcdoc, \"StatShr" << pnl->sref.substr(3) << "\", \"scrJref" << crdpnl->sref.substr(3+4+3) << "\");" << endl;
	};
	outfile << "// IP updateScrJrefs --- IEND" << endl;

	// --- resetInitdones
	outfile << "// IP resetInitdones --- IBEGIN" << endl;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST))
					outfile << "\tsetSi(srcdoc, \"StatApp" << pnl->sref.substr(3) << "\", \"initdone" << crdpnl->sref.substr(3+4+3) << "\", \"false\");" << endl;
	};
	outfile << "// IP resetInitdones --- IEND" << endl;

	// --- resetHeights
	outfile << "// IP resetHeights --- IBEGIN" << endl;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST))
					outfile << "\theight" << crdpnl->sref.substr(3+4+3) << " = 30;" << endl;
	};
	outfile << "// IP resetHeights --- IEND" << endl;

	// --- checkInitdone
	outfile << "// IP checkInitdone --- IBEGIN" << endl;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST))
					outfile << "\tvar initdone" << crdpnl->sref.substr(3+4+3) << " = (retrieveSi(srcdoc, \"StatApp" << pnl->sref.substr(3) << "\", \"initdone" << crdpnl->sref.substr(3+4+3) << "\") == \"true\");" << endl;
	};
	outfile << endl;

	pnlcnt = 0;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
			outfile << "\t";
			if (pnlcnt != 0) outfile << "} else ";

			outfile << "if (!initdone" << crdpnl->sref.substr(3+4+3) << ") {" << endl;
			outfile << "\t\t";

			if (Wznm::getPnlrhs(dbswznm, crdpnl)) outfile << "rhsdoc";
			else outfile << "lhsdoc";

			outfile << ".getElementById(\"" << crdpnl->sref.substr(3+4+3) << "\").src = \"./" << crdpnl->sref << ".html?scrJref=\" + scrJref" << crdpnl->sref.substr(3+4+3) << ";" << endl;

			pnlcnt++;
		};
	};
	outfile << "// IP checkInitdone --- IEND" << endl;

	// --- reinitPnl
	outfile << "// IP reinitPnl --- IBEGIN" << endl;
	first = true;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if (crdpnl->Detach && ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST))) {
			outfile << "\t";
			if (first) first = false; else outfile << "else ";
			outfile << "if (scrJrefPnl == scrJref" << crdpnl->sref.substr(3+4+3) << ") ";

			if (Wznm::getPnlrhs(dbswznm, crdpnl)) outfile << "rhsdoc";
			else outfile << "lhsdoc";

			outfile << ".getElementById(\"" << crdpnl->sref.substr(3+4+3) << "\").contentWindow.handleLoad();" << endl;
		};
	};
	outfile << "// IP reinitPnl --- IEND" << endl;

	// --- setPnlAvail.lhsrhsdoc
	outfile << "// IP setPnlAvail.lhsrhsdoc --- IBEGIN" << endl;
	outfile << "\tif (";

	first = true;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if (Wznm::getPnllhs(dbswznm, crdpnl)) {
			if (first) first = false;
			else outfile << " || ";

			outfile << "(short == \"" << crdpnl->sref.substr(3+4+3) << "\")";
		};
	};
	if (first) outfile << "false";

	outfile << ") lhsrhsdoc = lhsdoc;" << endl;
	outfile << "// IP setPnlAvail.lhsrhsdoc --- IEND" << endl;

	// --- setPnlAvail.heights
	outfile << "// IP setPnlAvail.heights --- IBEGIN" << endl;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		outfile << "\t\t";
		if (i != 0) outfile << "else ";
		outfile << "if (short == \"" << crdpnl->sref.substr(3+4+3) << "\") height" << crdpnl->sref.substr(3+4+3) << " = height;" << endl;
	};
	outfile << "// IP setPnlAvail.heights --- IEND" << endl;

	// --- changeHeight.lhsrhsdoc
	outfile << "// IP changeHeight.lhsrhsdoc --- IBEGIN" << endl;
	outfile << "\tif (";

	first = true;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if (Wznm::getPnllhs(dbswznm, crdpnl)) {
			if (first) first = false;
			else outfile << " || ";

			outfile << "(pnlshort == \"" << crdpnl->sref.substr(3+4+3) << "\")";
		};
	};
	if (first) outfile << "false";

	outfile << ") lhsrhsdoc = lhsdoc;" << endl;
	outfile << "// IP changeHeight.lhsrhsdoc --- IEND" << endl;

	// --- changeHeight.heights
	outfile << "// IP changeHeight.heights --- IBEGIN" << endl;
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "else ";
		outfile << "if (pnlshort == \"" << crdpnl->sref.substr(3+4+3) << "\") height" << crdpnl->sref.substr(3+4+3) << " = height;" << endl;
	};
	outfile << "// IP changeHeight.heights --- IEND" << endl;

	// --- updateHeight
	outfile << "// IP updateHeight --- IBEGIN" << endl;
	outfile << "\theightLhs = ";
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];
		if (Wznm::getPnllhs(dbswznm, crdpnl)) outfile << "height" << crdpnl->sref.substr(3+4+3) << "+13 + ";
	};
	outfile << "5;" << endl;

	outfile << "\theightRhs = ";
	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];
		if (Wznm::getPnlrhs(dbswznm, crdpnl)) outfile << "height" << crdpnl->sref.substr(3+4+3) << "+13 + ";
	};
	outfile << "5;" << endl;
	outfile << "// IP updateHeight --- IEND" << endl;

	// --- refreshB.availDecls
	outfile << "// IP refreshB.availDecls --- IBEGIN" << endl;
	if (availcnt > 0) {
		outfile << "\tvar updh = false;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
			crdpnl = crdpnls.nodes[i];
			if (crdpnl->Avail.length() > 0) outfile << "\tvar pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << "Avail = (retrieveSi(srcdoc, \"StatShr" << pnl->sref.substr(3)
						<< "\", \"pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << "Avail\") == \"true\");" << endl;
		};
	};
	outfile << "// IP refreshB.availDecls --- IEND" << endl;

	// --- refreshB.avails
	outfile << "// IP refreshB.avails --- IBEGIN" << endl;
	if (availcnt > 0) {
		for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
			crdpnl = crdpnls.nodes[i];
			if (crdpnl->Avail.length() > 0) outfile << "\tif (setPnlAvail(\"" << crdpnl->sref.substr(3+4+3) << "\", pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << "Avail)) updh = true;" << endl;
		};
		outfile << endl;

		outfile << "\tif (updh) updateHeight();" << endl;
	};
	outfile << "// IP refreshB.avails --- IEND" << endl;

	// --- evthdls
	outfile << "// IP evthdls --- IBEGIN" << endl;
	wrEvthdlsJs(dbswznm, Prjshort, outfile, cons, pnl->sref.substr(3), false, false);
	outfile << "// IP evthdls --- IEND" << endl;

	// --- mergeDpchEngData
	outfile << "// IP mergeDpchEngData --- IBEGIN" << endl;
	wrSrcblksJs(dbswznm, outfile, pnl->refWznmMJob, "DpchEng" + pnl->sref.substr(3) + "Data");
	outfile << "// IP mergeDpchEngData --- IEND" << endl;

	// --- handleDpchEng.subs
	outfile << "// IP handleDpchEng.subs --- IBEGIN" << endl;
	pnlcnt = 0;

	for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
		crdpnl = crdpnls.nodes[i];

		if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
			outfile << "\t\t\t";
			if (pnlcnt != 0) outfile << "} else ";

			outfile << "if (_scrJref == scrJref" << crdpnl->sref.substr(3+4+3) << ") {" << endl;

			outfile << "\t\t\t\tif (getInitdone(\"" << crdpnl->sref.substr(3+4+3) << "\")) ";
			if (Wznm::getPnllhs(dbswznm, crdpnl)) outfile << "lhsdoc";
			else outfile << "rhsdoc";
			outfile << ".getElementById(\"" << crdpnl->sref.substr(3+4+3) << "\").contentWindow.handleDpchEng(dom, dpch);" << endl;

			pnlcnt++;
		};
	};
	outfile << "// IP handleDpchEng.subs --- IEND" << endl;

	// --- handleDpchAppDoDlgopenReply*
	if (hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, pnl->ref, "dlgopen")) outfile << "// IP handleDpchAppDoDlgopenReply --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDoDlgopenReply --- REMOVE" << endl;
};

// reclist panel
void WznmWrwebPnl::writePnlasHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
		) {
	ListWznmMControl cons;

	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref)
				+ " AND sref = 'ButRegularize'", false, cons);

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::SIDE}, "", 1);
	outfile << "<!-- IP evthdls - IEND -->" << endl;
};

void WznmWrwebPnl::writePnlbfXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
		) {
	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::FTR}, "", 2);
	outfile << "<!-- IP evthdls - IEND -->" << endl;
};

void WznmWrwebPnl::writePnlbhHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
			, const uint ixReltype
		) {
	WznmMControl* con = NULL;

	bool updown = false;
	bool view = false;
	bool _new = false;
	bool duplicate = false;
	bool _delete = false;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) && (con->sref == "ButUp")) updown = true;
		if ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) && (con->sref == "ButView")) view = true;
		if ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) && (con->sref == "ButNew")) _new = true;
		if ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) && (con->sref == "ButDuplicate")) duplicate = true;
		if ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) && (con->sref == "ButDelete")) _delete = true;
	};

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::HDR}, "", 2);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- ButUpDown*
	if (updown) outfile << "<!-- IP ButUpDown - AFFIRM -->" << endl;
	else outfile << "<!-- IP ButUpDown - REMOVE -->" << endl;

	// --- ButView*
	if (view) outfile << "<!-- IP ButView - AFFIRM -->" << endl;
	else outfile << "<!-- IP ButView - REMOVE -->" << endl;

	// --- ButAddSub*
	if (ixReltype == VecWznmVMRelationBasetype::MN) outfile << "<!-- IP ButAddSub - AFFIRM -->" << endl;
	else outfile << "<!-- IP ButAddSub - REMOVE -->" << endl;

	// --- ButNew*
	if (_new) outfile << "<!-- IP ButNew - AFFIRM -->" << endl;
	else outfile << "<!-- IP ButNew - REMOVE -->" << endl;

	// --- ButDuplicate*
	if (duplicate) outfile << "<!-- IP ButDuplicate - AFFIRM -->" << endl;
	else outfile << "<!-- IP ButDuplicate - REMOVE -->" << endl;

	// --- ButDelete*
	if (_delete) outfile << "<!-- IP ButDelete - AFFIRM -->" << endl;
	else outfile << "<!-- IP ButDelete - REMOVE -->" << endl;
};

void WznmWrwebPnl::writePnlbsHtfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
		) {
	ListWznmMControl cons;

	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref)
				+ " AND sref = 'ButMinimize'", false, cons);

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::SIDE}, "", 1);
	outfile << "<!-- IP evthdls - IEND -->" << endl;
};

void WznmWrwebPnl::writePnlbtXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
		) {
	WznmMControl* con = NULL;

	unsigned int ncol, w, j;

	ncol = 0;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) if (cons.nodes[i]->ixVBasetype == VecWznmVMControlBasetype::TCO) ncol++;

	// --- evthdls
	outfile << "<!-- IP evthdls - IBEGIN -->" << endl;
	wrEvthdlsXml(dbswznm, outfile, cons, {VecWznmVMControlHkSection::TBL}, "", 2);
	outfile << "<!-- IP evthdls - IEND -->" << endl;

	// --- colgrp
	outfile << "<!-- IP colgrp - IBEGIN -->" << endl;
	// total width: 405
	if (ncol > 0) {
		w = 405 / ncol;
		w = w - (w%5);

		j = 0;
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) {
				j++;

				if (j == ncol) outfile << "\t\t\t\t<col width=\"" << (405 - (ncol-1)*w) << "\"></col>" << endl;
				else outfile << "\t\t\t\t<col width=\"" << w << "\"></col>" << endl;
			};
		};
	};
	outfile << "<!-- IP colgrp - IEND -->" << endl;

	// --- cols
	outfile << "<!-- IP cols - IBEGIN -->" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) outfile << "\t\t\t\t<td class=\"col\" id=\"" << con->sref << "\">" << con->sref << "</td>" << endl;
	};
	outfile << "<!-- IP cols - IEND -->" << endl;
};

void WznmWrwebPnl::writePnlJsfile(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMPanel* pnl
			, ListWznmMControl& cons
			, const bool estapp
		) {
	WznmMControl* con = NULL;

	string s;

	unsigned int ix;

	// --- minimize.estapp*
	if (estapp) outfile << "// IP minimize.estapp --- AFFIRM" << endl;
	else outfile << "// IP minimize.estapp --- REMOVE" << endl;

	// --- regularize.estapp*
	if (estapp) outfile << "// IP regularize.estapp --- AFFIRM" << endl;
	else outfile << "// IP regularize.estapp --- REMOVE" << endl;

	// --- init.estapp*
	if (estapp) outfile << "// IP init.estapp --- AFFIRM" << endl;
	else outfile << "// IP init.estapp --- REMOVE" << endl;

	// --- init.estshr*
	if (!estapp) outfile << "// IP init.estshr --- AFFIRM" << endl;
	else outfile << "// IP init.estshr --- REMOVE" << endl;

	// --- refreshBD.colsDecl
	outfile << "// IP refreshBD.colsDecl --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];
		if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) outfile << "\t\tvar " << con->sref << "Width = parseInt(retrieveSi(srcdoc, \"StgIac" << pnl->sref.substr(3) << "\", \"" << con->sref << "Width\"));" << endl;
	};
	outfile << "// IP refreshBD.colsDecl --- IEND" << endl;

	// --- refreshBD.colsLineup
	outfile << "// IP refreshBD.colsLineup --- IBEGIN" << endl;
	ix = 1;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVBasetype == VecWznmVMControlBasetype::TCO) {
			outfile << "\t\t\t";
			if (ix != 1) outfile << "} else ";
			outfile << "if (i == " << (ix++) << ") {" << endl;

			outfile << "\t\t\t\tdoc.cols.push(\"" << con->sref << "\"); doc.widths.push(" << con->sref << "Width);";

			if (dbswznm->loadStringBySQL("SELECT Short FROM TblWznmMQuerycol WHERE ref = " + to_string(con->refUref), s)) outfile << " doc.fs.push(\"" << s << "\");";

			outfile << " wtot += " << con->sref << "Width;" << endl;
		};
	};
	outfile << "// IP refreshBD.colsLineup --- IEND" << endl;

	// --- refresh.estapp*
	if (estapp) outfile << "// IP refresh.estapp --- AFFIRM" << endl;
	else outfile << "// IP refresh.estapp --- REMOVE" << endl;

	// --- refresh.estshr*
	if (!estapp) outfile << "// IP refresh.estshr --- AFFIRM" << endl;
	else outfile << "// IP refresh.estshr --- REMOVE" << endl;

	// --- evthdls
	outfile << "// IP evthdls --- IBEGIN" << endl;
	wrEvthdlsJs(dbswznm, Prjshort, outfile, cons, pnl->sref.substr(3), false, false);
	outfile << "// IP evthdls --- IEND" << endl;

	// --- mergeDpchEngData
	outfile << "// IP mergeDpchEngData --- IBEGIN" << endl;
	wrSrcblksJs(dbswznm, outfile, pnl->refWznmMJob, "DpchEng" + pnl->sref.substr(3) + "Data");
	outfile << "// IP mergeDpchEngData --- IEND" << endl;

	// --- handleDpchEng.estapp*
	if (estapp) outfile << "// IP handleDpchEng.estapp --- AFFIRM" << endl;
	else outfile << "// IP handleDpchEng.estapp --- REMOVE" << endl;

	// --- handleDpchEng.estshr*
	if (!estapp) outfile << "// IP handleDpchEng.estshr --- AFFIRM" << endl;
	else outfile << "// IP handleDpchEng.estshr --- REMOVE" << endl;

	// --- handleDpchAppDataDoReply.estapp*
	if (estapp) outfile << "// IP handleDpchAppDataDoReply.estapp --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDataDoReply.estapp --- REMOVE" << endl;

	// --- handleDpchAppDataDoReply.estshr*
	if (!estapp) outfile << "// IP handleDpchAppDataDoReply.estshr --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDataDoReply.estshr --- REMOVE" << endl;

	// --- handleDpchAppDoCrdopenReply*
	if (hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, pnl->ref, "crdopen")) outfile << "// IP handleDpchAppDoCrdopenReply --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDoCrdopenReply --- REMOVE" << endl;

	// --- handleDpchAppDoDlgopenReply*
	if (hasAction(dbswznm, VecWznmVMControlHkTbl::PNL, pnl->ref, "dlgopen")) outfile << "// IP handleDpchAppDoDlgopenReply --- AFFIRM" << endl;
	else outfile << "// IP handleDpchAppDoDlgopenReply --- REMOVE" << endl;
};
// IP cust --- IEND



