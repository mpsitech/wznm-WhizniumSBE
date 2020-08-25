/**
	* \file WznmWrweb.cpp
	* Wznm operation pack global code (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrweb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmWrweb
 ******************************************************************************/

// IP cust --- IBEGIN
void WznmWrweb::writeLstXmfile(
			fstream& outfile
			, WznmMControl* con
			, const bool large
		) {
	// --- evthdls*
	if ((con->hkIxVTbl != VecWznmVMControlHkTbl::DLG) || (con->supRefWznmMControl == 0)) outfile << "<!-- IP evthdls - AFFIRM -->" << endl;
	else outfile << "<!-- IP evthdls - REMOVE -->" << endl;

	// --- ditevthdls*
	if ((con->hkIxVTbl == VecWznmVMControlHkTbl::DLG) && (con->supRefWznmMControl != 0)) outfile << "<!-- IP ditevthdls - AFFIRM -->" << endl;
	else outfile << "<!-- IP ditevthdls - REMOVE -->" << endl;

	// --- colgrp
	outfile << "<!-- IP colgrp - IBEGIN -->" << endl;
	if (StrMod::srefInSrefs(con->srefsKOption, "bicol")) {
		if (large) {
			outfile << "\t\t\t\t<col width=\"174\"/>" << endl;
			outfile << "\t\t\t\t<col width=\"150\"/>" << endl;
		} else {
			outfile << "\t\t\t\t<col width=\"94\"/>" << endl;
			outfile << "\t\t\t\t<col width=\"85\"/>" << endl;
		};
	} else if (StrMod::srefInSrefs(con->srefsKOption, "tricol")) {
		if (large) {
			outfile << "\t\t\t\t<col width=\"124\"/>" << endl;
			outfile << "\t\t\t\t<col width=\"100\"/>" << endl;
			outfile << "\t\t\t\t<col width=\"100\"/>" << endl;
		} else {
			outfile << "\t\t\t\t<col width=\"69\"/>" << endl;
			outfile << "\t\t\t\t<col width=\"55\"/>" << endl;
			outfile << "\t\t\t\t<col width=\"55\"/>" << endl;
		};
	} else {
		if (large) {
			outfile << "\t\t\t\t<col width=\"324\"/>" << endl;
		} else {
			outfile << "\t\t\t\t<col width=\"179\"/>" << endl;
		};
	};
	outfile << "<!-- IP colgrp - IEND -->" << endl;
};

void WznmWrweb::wrEvthdlsXml(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
			, const set<uint>& hkIcsVSection
			, const string& ditshort
			, const unsigned int pl
			, const bool ditempty
		) {
	WznmMControl* con = NULL;

	string parent, consref, action, shr, log, rast, consize;

	for (unsigned int i = 0; i < pl; i++) parent += "parent.";

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (hkIcsVSection.find(con->hkIxVSection) != hkIcsVSection.end()) {
			consref = Wznm::getConsref(con, ditshort);

			if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
				if (con->ixVScope == VecWznmVMControlScope::APP) {
					if (StrMod::srefInSrefs(con->srefsKOption, "mdnup")) {
						outfile << "\t\t\tfunction handle" << consref << "Mdn() {" << parent << "window.handle" << con->sref << "Mdn();};" << endl;
						outfile << "\t\t\tfunction handle" << consref << "Mup() {" << parent << "window.handle" << con->sref << "Mup();};" << endl;

					} else {
						outfile << "\t\t\tfunction handle" << consref << "Click() {" << parent << "window.";

						if ((con->sref.length() > 8) && ((con->sref.rfind("Collapse")+8) == con->sref.length())) {
							outfile << "handleButCollapseClick(" << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << wrEvthdlsXml_altbconsref(cons, con, ditshort, consref) << "\");";
						} else if ((con->sref.length() > 6) && ((con->sref.rfind("Expand")+6) == con->sref.length())) {
							outfile << "handleButExpandClick(" << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << wrEvthdlsXml_altbconsref(cons, con, ditshort, consref) << "\");";
						} else if ((con->sref.length() > 6) && ((con->sref.rfind("Toggle")+6) == con->sref.length())) {
							outfile << "handleButToggleClick(" << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << wrEvthdlsXml_altbconsref(cons, con, ditshort, consref) << "\");";

						} else {
							outfile << "handle" << con->sref << "Click();";
						};

						outfile << "};" << endl;
					};

				} else if (con->ixVScope == VecWznmVMControlScope::SHR) {
					if (StrMod::srefInSrefs(con->srefsKOption, "mdnup")) {
						outfile << "\t\t\tfunction handle" << consref << "Mdn() {" << parent << "window.handleButMdn(" << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
						outfile << "\t\t\tfunction handle" << consref << "Mup() {" << parent << "window.handleButMup(" << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;

					} else {
						action = "";
						dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "action", 0, action);

						outfile << "\t\t\tfunction handle" << consref << "Click() {" << parent << "window.";

						if (action == "crdopen") {
							outfile << "handleButCrdopenClick(\"" << con->sref << "\");";
						} else if (action == "dlgopen") {
							outfile << "handleButDlgopenClick(\"" << con->sref << "\");";
						} else {
							outfile << "handleButClick(" << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");";
						};

						outfile << "};" << endl;
					};
				};

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::CHK) {
				if (con->ixVScope == VecWznmVMControlScope::APP) {
					outfile << "\t\t\tfunction handle" << consref << "Change() {" << parent << "window.handle" << con->sref << "Change();};" << endl;
				} else if (con->ixVScope == VecWznmVMControlScope::SHR) {
					outfile << "\t\t\tfunction handle" << consref << "Change() {" << parent << "window.handleChkChange(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
				};

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::DSE) {
				outfile << "\t\t\tfunction handleDseSelect(numFDse) {" << parent << "window.handleDseSelect(numFDse);};" << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::LSB) {
				// handled in LstXyz.xml

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::LST) {
				// handled in LstXyz.xml

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::PUP) {
				if (con->ixVScope == VecWznmVMControlScope::APP) {
					outfile << "\t\t\tfunction handle" << consref << "Change() {" << parent << "window.handle" << con->sref << "Change();};" << endl;
				} else if (con->ixVScope == VecWznmVMControlScope::SHR) {
					outfile << "\t\t\tfunction handle" << consref << "Change() {" << parent << "window.handlePupChange(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\",\"" << getConsize(con) << "\");};" << endl;
				};

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::RBU) {
				if (con->ixVScope == VecWznmVMControlScope::APP) {
					outfile << "\t\t\tfunction handle" << consref << "Select(num) {" << parent << "window.handle" << con->sref << "Select(num);};" << endl;
				} else if (con->ixVScope == VecWznmVMControlScope::SHR) {
					outfile << "\t\t\tfunction handle" << consref << "Select(num) {" << parent << "window.handleRbuSelect(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\",num);};" << endl;
				};

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::SLD) {
				if (con->ixVScope == VecWznmVMControlScope::SHR) shr = "true"; else shr = "false";
				if (StrMod::srefInSrefs(con->srefsKOption, "log")) log = "true"; else log = "false";
				if (StrMod::srefInSrefs(con->srefsKOption, "rast")) rast = "true"; else rast = "false";

				outfile << "\t\t\tfunction handle" << consref << "JpleftMov() {" << parent << "window.handleSldJpleftMov(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "JpleftMou() {" << parent << "window.handleSldJpleftMou(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "JpleftClick(evt) {" << parent << "window.handleSldJpleftClick(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << "," << log << "," << rast << ",evt);};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "JprightMov() {" << parent << "window.handleSldJprightMov(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "JprightMou() {" << parent << "window.handleSldJprightMou(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "JprightClick(evt) {" << parent << "window.handleSldJprightClick(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << "," << log << "," << rast << ",evt);};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "Mov() {" << parent << "window.handleSldMov(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "Mou() {" << parent << "window.handleSldMou(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "Mdn() {" << parent << "window.handleSldMdn(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "Move(evt) {" << parent << "window.handleSldMove(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << "," << log << "," << rast << ",evt);};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "Mup() {" << parent << "window.handleSldMup(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << ");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "ValKey(evt) {return " << parent << "window.handleSldValKey(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << "," << log << "," << rast << ",evt);};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "ValChange() {" << parent << "window.handleSldValChange(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << "," << log << "," << rast << ");};" << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::TBL) {
				outfile << "\t\t\tfunction handleTblSelect(jnum) {" << parent << "window.handleTblSelect(jnum);};" << endl;
				outfile << "\t\t\tfunction handleTblCpreviousClick() {" << parent << "window.handleTblCpreviousClick();};" << endl;
				outfile << "\t\t\tfunction handleTblCnextClick() {" << parent << "window.handleTblCnextClick();};" << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::TOS) {
				outfile << "\t\t\tfunction handleTosSelect(numFTos) {" << parent << "window.handleTosSelect(numFTos);};" << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::TRS) {
				outfile << "\t\t\tfunction handleTrsFirstClick() {" << parent << "window.handleTrsFirstClick();};" << endl;
				outfile << "\t\t\tfunction handleTrsPreviousClick() {" << parent << "window.handleTrsPreviousClick();};" << endl;
				outfile << "\t\t\tfunction handleTrsNextClick() {" << parent << "window.handleTrsNextClick();};" << endl;
				outfile << "\t\t\tfunction handleTrsLastClick() {" << parent << "window.handleTrsLastClick();};" << endl;
				outfile << "\t\t\tfunction handleTrsGotoClick() {" << parent << "window.handleTrsGotoClick();};" << endl;
				outfile << "\t\t\tfunction handleTrsRowMou() {" << parent << "window.handleTrsRowMou();};" << endl;
				outfile << "\t\t\tfunction handleTrsRowKey(evt) {return " << parent << "window.handleTrsRowKey(evt);};" << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::TSB) {
				outfile << "\t\t\tfunction setTsbPos(pos) {" << parent << "window.setTsbPos(pos);};" << endl;
				outfile << "\t\t\tfunction handleTsbUpClick() {" << parent << "window.handleTsbUpClick();};" << endl;
				outfile << "\t\t\tfunction handleTsbJpupClick() {" << parent << "window.handleTsbJpupClick();};" << endl;
				outfile << "\t\t\tfunction handleTsbJpdownClick() {" << parent << "window.handleTsbJpdownClick();};" << endl;
				outfile << "\t\t\tfunction handleTsbDownClick() {" << parent << "window.handleTsbDownClick();};" << endl;
				outfile << "\t\t\tfunction handleTsbMdn() {" << parent << "window.handleTsbMdn();};" << endl;
				outfile << "\t\t\tfunction handleTsbMup(evt) {" << parent << "window.handleTsbMup(evt);};" << endl;
				outfile << "\t\t\tfunction handleTsbMove(evt) {" << parent << "window.handleTsbMove(evt);};" << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::TXF) {
				if (con->ixVScope == VecWznmVMControlScope::APP) {
					outfile << "\t\t\tfunction handle" << consref << "Key(evt) {return " << parent << "window.handle" << con->sref << "Key(evt);};" << endl;
					outfile << "\t\t\tfunction handle" << consref << "Change() {" << parent << "window.handle" << con->sref << "Change();};" << endl;

				} else if (con->ixVScope == VecWznmVMControlScope::SHR) {
					consize = getConsize(con);
					
					if (consize == "t") {
						outfile << "\t\t\tfunction handle" << consref << "Key(evt) {return " << parent << "window.handleTxftKey(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\",evt);};" << endl;
						outfile << "\t\t\tfunction handle" << consref << "Change() {" << parent << "window.handleTxftChange(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\");};" << endl;
					} else {
						outfile << "\t\t\tfunction handle" << consref << "Key(evt) {return " << parent << "window.handleTxfKey(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\",\"" << getConsize(con) << "\",evt);};" << endl;
						outfile << "\t\t\tfunction handle" << consref << "Change() {" << parent << "window.handleTxfChange(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\",\"" << getConsize(con) << "\");};" << endl;
					};
				};

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::UPD) {
				if (con->ixVScope == VecWznmVMControlScope::SHR) shr = "true"; else shr = "false";

				outfile << "\t\t\tfunction handle" << consref << "ValKey(evt) {return " << parent << "window.handleUpdValKey(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << ",evt);};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "ValChange() {" << parent << "window.handleUpdValChange(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << ");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "UpClick() {" << parent << "window.handleUpdUpClick(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << ");};" << endl;
				outfile << "\t\t\tfunction handle" << consref << "DownClick() {" << parent << "window.handleUpdDownClick(document," << wrEvthdlsXml_ditshort(ditshort, ditempty) << "\"" << consref << "\"," << shr << ");};" << endl;
			};
		};
	};
};

string WznmWrweb::wrEvthdlsXml_ditshort(
			const string& ditshort
			, const bool ditempty
		) {
	if ((ditshort != "") || ditempty) return("\"" + ditshort + "\",");
	else return("");
};

string WznmWrweb::wrEvthdlsXml_altbconsref(
			ListWznmMControl& cons
			, WznmMControl* con
			, const string& ditshort
			, const string& consref
		) {
	string retval = consref;

	WznmMControl* cptcon = NULL;
	WznmMControl* basecon = NULL;

	bool found;

	if (con->supRefWznmMControl != 0) {
		found = false;

		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			cptcon = cons.nodes[i];

			if ((cptcon->ref == con->supRefWznmMControl) && (cptcon->ref != con->ref) && (cptcon->ixVBasetype == VecWznmVMControlBasetype::CPT)) {
				found = true;
				break;
			};
		};

		if (found) {
			for (unsigned int i = 0; i < cons.nodes.size(); i++) {
				basecon = cons.nodes[i];

				if ((basecon->ref == cptcon->supRefWznmMControl) && (basecon->ref != cptcon->ref)) {
					retval = Wznm::getConsref(basecon, ditshort);
					break;
				};
			};
		};
	};

	return retval;
};

void WznmWrweb::wrBaseconXml(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, const string& hksref
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const unsigned int ixIcsBasecons
			, const string& ditshort
			, const bool large
		) {
	unsigned int cplxtype;
	string baseconsref, baseconshort;
	bool ldyn, dyn, rdyn, vbar;
	unsigned int ix0, ix1;
	unsigned int ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView;
	vector<unsigned int> icsButs;
	unsigned int ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt;
	vector<unsigned int> icsVbarcons;

	WznmMControl* basecon = NULL;
	WznmMControl* con = NULL;

	string consref;

	unsigned int w;
	string s, s2;

	basecon = cons.nodes[icsBasecons[ixIcsBasecons]];

	Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, ixIcsBasecons, ditshort, cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
				icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

	if (cplxtype == Concplxtype::INVALID) {

	} else if (cplxtype == Concplxtype::BUT_CLUST) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		if ((ixCpt+1) != 0) {
			outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
			con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
			outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
			outfile << "\t\t\t\t\t</td>" << endl;

			outfile << "\t\t\t\t\t<td></td>" << endl;

		} else {
			outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
		};

		if (dyn) {
			outfile << "\t\t\t\t\t<td id=\"dyn" << baseconshort << "\" colspan=\"8\" align=\"left\">" << endl;
			outfile << "\t\t\t\t\t</td>" << endl;

		} else {
			outfile << "\t\t\t\t\t<td colspan=\"8\" align=\"left\">" << endl;
			wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
			outfile << "\t\t\t\t\t</td>" << endl;
		};

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::CHK) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<input id=\"" << baseconsref << "\" class=\"chk\" name=\"" << baseconsref << "\" type=\"checkbox\" checked=\"checked\" onchange=\"handle" << baseconsref << "Change()\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		if (vbar) {
			outfile << "\t\t\t\t\t<td colspan=\"5\"></td>" << endl;
			outfile << "\t\t\t\t\t<td bgcolor=\"#000000\"></td>" << endl;
			outfile << "\t\t\t\t\t<td></td>" << endl;
		} else outfile << "\t\t\t\t\t<td colspan=\"7\"></td>" << endl;

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::CUS) {
		w = (large ? 690 : 440); // to be improved

		s = "100";
		dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(basecon->ref, "height", 0, s);

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		if (StrMod::srefInSrefs(basecon->srefsKOption, "iframe")) {
			outfile << "\t\t\t\t\t<td id=\"td" << baseconshort << "\" colspan=\"11\" height=\"" << s << "\">" << endl;
			outfile << "\t\t\t\t\t\t<iframe id=\"Cus" << baseconshort << "\" name=\"Cus" << baseconshort << "\" src=\"./" << hksref << ditshort << "_" << Wznm::getConsref(basecon, ditshort) << ".xml\" width=\"" << w << "\" height=\"" << s << "\" frameborder=\"0\" scrolling=\"no\">This page needs a web-browser capable of displaying inline frames!</iframe>" << endl;
			outfile << "\t\t\t\t\t</td>" << endl;
		} else {
			outfile << "\t\t\t\t\t<!-- IP tr" << baseconshort << " - BEGIN -->" << endl;
			outfile << "\t\t\t\t\t<td id=\"td" << baseconshort << "\" height=\"" << s << "\" colspan=\"11\"></td>" << endl;
			outfile << "\t\t\t\t\t<!-- IP tr" << baseconshort << " - END -->" << endl;
		};
		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::DLD) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"5\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<a id=\"" << baseconsref << "\" class=\"but\" href=\"/download/0\" download=\"file\" target=\"_blank\">" << baseconsref << "</a>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"3\"></td>" << endl;
		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::HDG) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;

		if (dyn) {
			outfile << "\t\t\t\t\t<td id=\"dyn" << baseconshort << "\" colspan=\"8\" align=\"left\">" << endl;
			outfile << "\t\t\t\t\t</td>" << endl;

		} else {
			outfile << "\t\t\t\t\t<td colspan=\"8\" align=\"left\">" << endl;
			outfile << "\t\t\t\t\t\t<span id=\"" << baseconsref << "\" class=\"cpt\">" << baseconsref << "</span>&#160;&#160;" << endl;
			wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
			outfile << "\t\t\t\t\t</td>" << endl;
		};

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::LST) {
		w = (large ? 340 : 190);

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		if ((ixChk+1) != 0) {
			con = cons.nodes[ixChk]; consref = Wznm::getConsref(con, ditshort);
			outfile << "\t\t\t\t\t\t<input id=\"" << consref << "\" class=\"chk\" name=\"" << consref << "\" type=\"checkbox\" checked=\"checked\" onchange=\"handle" << consref << "Change()\"/>" << endl;
		};
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td rowspan=\"2\" colspan=\"5\">" << endl;

		outfile << "\t\t\t\t\t\t<iframe id=\"" << baseconsref << "\" name=\"" << baseconsref << "\" src=\"./" << hksref << ditshort << "_" << Wznm::getConsref(basecon, ditshort) << ".xml\" width=\"" << w << "\" height=\"92\" frameborder=\"0\" scrolling=\"no\">This page needs a web-browser capable of displaying inline frames!</iframe>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (vbar) {
			outfile << "\t\t\t\t\t<td bgcolor=\"#000000\"></td>" << endl;
			outfile << "\t\t\t\t\t<td></td>" << endl;

		} else {
			if (icsButs.size() > 0) {
				if (rdyn) {
					outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"2\" align=\"left\">" << endl;
					outfile << "\t\t\t\t\t</td>" << endl;

				} else {
					outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
					wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
					outfile << "\t\t\t\t\t</td>" << endl;
				};

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
			};
		};

		outfile << "\t\t\t\t</tr>" << endl;

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "2\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"3\" height=\"67\"></td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"3\"></td>" << endl;
		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::LST_NOALT) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"ldyn" << baseconshort << "\" align=\"right\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"dyn" << baseconshort << "\" rowspan=\"1\" colspan=\"5\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (icsButs.size() > 0) {
			outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"2\" align=\"left\">" << endl;
			outfile << "\t\t\t\t\t</td>" << endl;

		} else {
			outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
		};

		outfile << "\t\t\t\t</tr>" << endl;

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "2\" class=\"hide\">" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"3\" height=\"67\"></td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"3\"></td>" << endl;
		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::LST_TXFALT) {
		// exact copy of LST_NOALT
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"ldyn" << baseconshort << "\" align=\"right\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"dyn" << baseconshort << "\" rowspan=\"1\" colspan=\"5\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (icsButs.size() > 0) {
			if (rdyn) {
				outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"2\" align=\"left\">" << endl;
				outfile << "\t\t\t\t\t</td>" << endl;

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
				wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
				outfile << "\t\t\t\t\t</td>" << endl;
			};

		} else {
			outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
		};

		outfile << "\t\t\t\t</tr>" << endl;

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "2\" class=\"hide\">" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"3\" height=\"67\"></td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"3\"></td>" << endl;
		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::LST_TXTALT) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"ldyn" << baseconshort << "\" align=\"right\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"dyn" << baseconshort << "\" rowspan=\"1\" colspan=\"5\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (vbar) {
			outfile << "\t\t\t\t\t<td bgcolor=\"#000000\"></td>" << endl;
			outfile << "\t\t\t\t\t<td></td>" << endl;

		} else {
			if (icsButs.size() > 0) {
				if (rdyn) {
					outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"2\" align=\"left\">" << endl;
					outfile << "\t\t\t\t\t</td>" << endl;

				} else {
					outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
					wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
					outfile << "\t\t\t\t\t</td>" << endl;
				};

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
			};
		};

		outfile << "\t\t\t\t</tr>" << endl;

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "2\" class=\"hide\">" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"3\" height=\"67\"></td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"3\"></td>" << endl;
		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::PUP) {
		// size parameter: '' vs. 's' vs. 'xs'
		s = ""; w = 5;
		if (StrMod::srefInSrefs(basecon->srefsKOption, "s")) {s = "s"; w = 3;}
		else if (StrMod::srefInSrefs(basecon->srefsKOption, "xs")) {s = "xs"; w = 1;};

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;
		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		if ((ixChk+1) != 0) {
			con = cons.nodes[ixChk]; consref = Wznm::getConsref(con, ditshort);
			outfile << "\t\t\t\t\t\t<input id=\"" << consref << "\" class=\"chk\" name=\"" << consref << "\" type=\"checkbox\" checked=\"checked\" onchange=\"handle" << consref << "Change()\"/>" << endl;
		};
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"" << w << "\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<select id=\"" << baseconsref << "\" class=\"pup" << s << "\" size=\"1\" onchange=\"handle" << baseconsref << "Change()\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (vbar) {
			if (w != 5) outfile << "\t\t\t\t\t<td colspan=\"" << (5-w) << "\"></td>" << endl;
			outfile << "\t\t\t\t\t<td bgcolor=\"#000000\"></td>" << endl;
			outfile << "\t\t\t\t\t<td></td>" << endl;

		} else {
			if (icsButs.size() > 0) {
				if (rdyn) {
					outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"" << (7-w) << "\" align=\"left\">" << endl;
					outfile << "\t\t\t\t\t</td>" << endl;

				} else {
					outfile << "\t\t\t\t\t<td colspan=\"" << (7-w) << "\" align=\"left\">" << endl;
					wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
					outfile << "\t\t\t\t\t</td>" << endl;
				};

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"" << (7-w) << "\"></td>" << endl;
			};
		};

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::PUP_PUP) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;
		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		if ((ixChk+1) != 0) {
			con = cons.nodes[ixChk]; consref = Wznm::getConsref(con, ditshort);
			outfile << "\t\t\t\t\t\t<input id=\"" << consref << "\" class=\"chk\" name=\"" << consref << "\" type=\"checkbox\" checked=\"checked\" onchange=\"handle" << consref << "Change()\"/>" << endl;
		};
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		con = cons.nodes[ixPup]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<select id=\"" << consref << "\" class=\"pupxs\" size=\"1\" onchange=\"handle" << consref << "Change()\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"3\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<select id=\"" << baseconsref << "\" class=\"pups\" size=\"1\" onchange=\"handle" << baseconsref << "Change()\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (icsButs.size() > 0) {
			if (rdyn) {
				outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"2\" align=\"left\">" << endl;
				outfile << "\t\t\t\t\t</td>" << endl;

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
				wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
				outfile << "\t\t\t\t\t</td>" << endl;
			};

		} else {
			outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
		};

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::PUP_TXFALT) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		con = cons.nodes[ixButToggle]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t&#160;<img id=\"" << consref << "\" class=\"but\" src=\"../icon/toggle.png\" width=\"16\" height=\"16\" valign=\"bottom\" alt=\"" << consref << "\" onmouseover=\"src='../icon/toggle_hlt.png'\" onmouseout=\"src='../icon/toggle.png'\" onclick=\"handle" << consref << "Click()\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"dyn" << baseconshort << "\" colspan=\"5\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (icsButs.size() > 0) {
			if (rdyn) {
				outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"2\" align=\"left\">" << endl;
				outfile << "\t\t\t\t\t</td>" << endl;

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
				wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
				outfile << "\t\t\t\t\t</td>" << endl;
			};

		} else {
			outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
		};

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::PUP_VBAR) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"3\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<select class=\"pups\" id=\"" << baseconsref << "\" size=\"1\" onchange=\"handle" << baseconsref << "Change()\">" << endl;
		outfile << "\t\t\t\t\t\t</select>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;
		outfile << "\t\t\t\t\t<td bgcolor=\"#000000\"></td>" << endl;
		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::RBU) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"" << baseconsref << "\" colspan=\"5\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		if (vbar) {
			outfile << "\t\t\t\t\t<td></td>" << endl;
			outfile << "\t\t\t\t\t<td bgcolor=\"#000000\"></td>" << endl;
			outfile << "\t\t\t\t\t<td></td>" << endl;
		} else outfile << "\t\t\t\t\t<td colspan=\"3\"></td>" << endl;

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::SEP) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "1\" class=\"show\"><td colspan=\"11\" height=\"3\"></td></tr>" << endl;
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "2\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"1\"></td>" << endl;
		outfile << "\t\t\t\t\t<td colspan=\"10\" bgcolor=\"#7f7f7f\"></td>" << endl;
		outfile << "\t\t\t\t</tr>" << endl;
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "3\" class=\"show\"><td colspan=\"11\" height=\"3\"></td></tr>" << endl;

	} else if (cplxtype == Concplxtype::SLD) {
		w = (large ? 340 : 190);

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		if ((ixChk+1) != 0) {
			con = cons.nodes[ixChk]; consref = Wznm::getConsref(con, ditshort);
			outfile << "\t\t\t\t\t\t<input id=\"" << consref << "\" class=\"chk\" name=\"" << consref << "\" type=\"checkbox\" checked=\"checked\" onchange=\"handle" << consref << "Change()\"/>" << endl;
		};
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"td" << baseconsref << "\" colspan=\"5\">" << endl;
		outfile << "\t\t\t\t\t\t<svg class=\"svg\" width=\"" << w << "\" height=\"25\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
		outfile << "\t\t\t\t\t\t\t<line class=\"sldlinact\" x1=\"0\" y1=\"12.5\" x2=\"5\" y2=\"12.5\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t<line class=\"sldlinact\" x1=\"" << (w-5) << "\" y1=\"12.5\" x2=\"" << w << "\" y2=\"12.5\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t<g id=\"" << baseconsref << "Jpleft\" class=\"sld\" onmouseover=\"handle" << baseconsref << "JpleftMov()\" onmouseout=\"handle" << baseconsref << "JpleftMou()\" onclick=\"handle" << baseconsref << "JpleftClick(event)\">" << endl;
		outfile << "\t\t\t\t\t\t\t\t<rect id=\"" << baseconsref << "Jpleftr\" class=\"sldr\" x=\"5\" y=\"2\" width=\"" << ((w-10)/2) << "\" height=\"18\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t\t<line id=\"" << baseconsref << "Jpleftl\" class=\"sldl\" x1=\"5\" y1=\"12.5\" x2=\"" << ((w-10)/2+2.5) << "\" y2=\"12.5\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t</g>" << endl;
		outfile << "\t\t\t\t\t\t\t<g id=\"" << baseconsref << "Jpright\" class=\"sld\" onmouseover=\"handle" << baseconsref << "JprightMov()\" onmouseout=\"handle" << baseconsref << "JprightMou()\" onclick=\"handle" << baseconsref << "JprightClick(event)\">" << endl;
		outfile << "\t\t\t\t\t\t\t\t<rect id=\"" << baseconsref << "Jprightr\" class=\"sldr\" x=\"" << (w/2) << "\" y=\"2\" width=\"" << ((w-10)/2) << "\" height=\"18\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t\t<line id=\"" << baseconsref << "Jprightl\" class=\"sldl\" x1=\"" << ((w-10)/2+7.5) << "\" y1=\"12.5\" x2=\"" << (w-5) << "\" y2=\"12.5\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t</g>" << endl;
		outfile << "\t\t\t\t\t\t\t<g id=\"" << baseconsref << "\" class=\"sld\" transform=\"translate(" << (w/2) << " 0)\" onmouseover=\"handle" << baseconsref << "Mov()\" onmouseout=\"handle" << baseconsref << "Mou()\" onmousedown=\"handle" << baseconsref << "Mdn()\">" << endl;
		outfile << "\t\t\t\t\t\t\t\t<rect id=\"" << baseconsref << "R\" class=\"sldr\" x=\"-3\" y=\"2\" width=\"6\" height=\"21\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t\t<g id=\"" << baseconsref << "Bar\" class=\"sldl\">" << endl;
		outfile << "\t\t\t\t\t\t\t\t\t<line x1=\"-2\" y1=\"2\" x2=\"-2\" y2=\"23\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t\t\t<line x1=\"2\" y1=\"2\" x2=\"2\" y2=\"23\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t\t</g>" << endl;
		outfile << "\t\t\t\t\t\t\t</g>" << endl;
		outfile << "\t\t\t\t\t\t</svg>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<input id=\"" << baseconsref << "Val\" class=\"txfxs\" type=\"text\" value=\"" << baseconsref << "Val\" onchange=\"handle" << baseconsref << "ValChange()\" onkeypress=\"return handle" << baseconsref << "ValKey(event)\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::SPC) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "1\"><td colspan=\"11\" height=\"";
		if (dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(basecon->ref, "height", 0, s)) outfile << s; else outfile << "10";
		outfile << "\"></td></tr>" << endl;

	} else if (cplxtype == Concplxtype::TXF) {
		// size parameter: '' vs. 't' vs. 's' vs. 'xs'
		s = ""; w = 5;
		if (StrMod::srefInSrefs(basecon->srefsKOption, "t")) s = "t";
		else if (StrMod::srefInSrefs(basecon->srefsKOption, "s")) {s = "s"; w = 3;}
		else if (StrMod::srefInSrefs(basecon->srefsKOption, "xs")) {s = "xs"; w = 1;};

		// optional password mode
		s2 = "text";
		if (StrMod::srefInSrefs(basecon->srefsKOption, "pwd")) s2 = "password";

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"";
		if (s == "t") outfile << "75"; else outfile << "25";
		outfile << "\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\"";
		if (s == "t") outfile << " valign=\"top\"";
		outfile << ">" << endl;
		if ((ixChk+1) != 0) {
			con = cons.nodes[ixChk]; consref = Wznm::getConsref(con, ditshort);
			outfile << "\t\t\t\t\t\t<input id=\"" << consref << "\" class=\"chk\" name=\"" << consref << "\" type=\"checkbox\" checked=\"checked\" onchange=\"handle" << consref << "Change()\"/>" << endl;
		};
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"" << w << "\" align=\"left\">" << endl;
		if (s == "t") outfile << "\t\t\t\t\t\t<textarea id=\"" << baseconsref << "\" class=\"txf\" rows=\"4\" cols=\"20\" type=\"text\" value=\"" << baseconsref << "\" onchange=\"handle" << baseconsref << "Change()\" onkeypress=\"return handle" << baseconsref << "Key(event)\"/>" << endl;
		else outfile << "\t\t\t\t\t\t<input id=\"" << baseconsref << "\" class=\"txf" << s << "\" type=\"" << s2 << "\" value=\"" << baseconsref << "\" onchange=\"handle" << baseconsref << "Change()\" onkeypress=\"return handle" << baseconsref << "Key(event)\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (vbar) {
			if (w != 5) outfile << "\t\t\t\t\t<td colspan=\"" << (5-w) << "\"></td>" << endl;
			outfile << "\t\t\t\t\t<td bgcolor=\"#000000\"></td>" << endl;
			outfile << "\t\t\t\t\t<td></td>" << endl;

		} else {
			if (icsButs.size() > 0) {
				if (rdyn) {
					outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"" << (7-w) << "\" align=\"left\"";
					if (s == "t") outfile << " valign=\"top\"";
					outfile << ">" << endl;
					outfile << "\t\t\t\t\t</td>" << endl;

				} else {
					outfile << "\t\t\t\t\t<td colspan=\"" << (7-w) << "\" align=\"left\"";
					if (s == "t") outfile << " valign=\"top\"";
					outfile << ">" << endl;
					wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
					outfile << "\t\t\t\t\t</td>" << endl;
				};

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"" << (7-w) << "\"></td>" << endl;
			};
		};

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::TXT) {
		// size parameter: '' vs. 't' vs. 's' vs. 'xs'
		s = ""; w = 5;
		if (StrMod::srefInSrefs(basecon->srefsKOption, "t")) s = "t";
		else if (StrMod::srefInSrefs(basecon->srefsKOption, "s")) {s = "s"; w = 3;}
		else if (StrMod::srefInSrefs(basecon->srefsKOption, "xs")) {s = "xs"; w = 1;};

		// optional password mode
		s2 = "text";
		if (StrMod::srefInSrefs(basecon->srefsKOption, "pwd")) s2 = "password";

		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"";
		if (s == "t") outfile << "75"; else outfile << "25";
		outfile << "\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\"";
		if (s == "t") outfile << " valign=\"top\"";
		outfile << ">" << endl;
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"" << w << "\" align=\"left\">" << endl;
		if (s == "t") outfile << "\t\t\t\t\t\t<textarea id=\"" << baseconsref << "\" class=\"txfnoed\" rows=\"4\" cols=\"20\" type=\"text\" readonly=\"readonly\" value=\"" << baseconsref << "\"/>" << endl;
		else outfile << "\t\t\t\t\t\t<input id=\"" << baseconsref << "\" class=\"txf" << s << "noed\" type=\"" << s2 << "\" readonly=\"readonly\" value=\"" << baseconsref << "\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (vbar) {
			if (w != 5) outfile << "\t\t\t\t\t<td colspan=\"" << (5-w) << "\"></td>" << endl;
			outfile << "\t\t\t\t\t<td bgcolor=\"#000000\"></td>" << endl;
			outfile << "\t\t\t\t\t<td></td>" << endl;

		} else {
			if (icsButs.size() > 0) {
				if (rdyn) {
					outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"" << (7-w) << "\" align=\"left\"";
					if (s == "t") outfile << " valign=\"top\"";
					outfile << ">" << endl;
					outfile << "\t\t\t\t\t</td>" << endl;

				} else {
					outfile << "\t\t\t\t\t<td colspan=\"" << (7-w) << "\" align=\"left\"";
					if (s == "t") outfile << " valign=\"top\"";
					outfile << ">" << endl;
					wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
					outfile << "\t\t\t\t\t</td>" << endl;
				};

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"" << (7-w) << "\"></td>" << endl;
			};
		};

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::TXT_PUP) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;
		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		if ((ixChk+1) != 0) {
			con = cons.nodes[ixChk]; consref = Wznm::getConsref(con, ditshort);
			outfile << "\t\t\t\t\t\t<input id=\"" << consref << "\" class=\"chk\" name=\"" << consref << "\" type=\"checkbox\" checked=\"checked\" onchange=\"handle" << consref << "Change()\"/>" << endl;
		};
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		con = cons.nodes[ixPup]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<select id=\"" << consref << "\" class=\"pupxs\" size=\"1\" onchange=\"handle" << consref << "Change()\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"3\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<input id=\"" << baseconsref << "\" class=\"txfsnoed\" type=\"text\" readonly=\"readonly\" value=\"" << baseconsref << "\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (icsButs.size() > 0) {
			if (rdyn) {
				outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"2\" align=\"left\">" << endl;
				outfile << "\t\t\t\t\t</td>" << endl;

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
				wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
				outfile << "\t\t\t\t\t</td>" << endl;
			};

		} else {
			outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
		};

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::TXT_TXFALT) {
		// exact copy of PUP_TXFALT
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		con = cons.nodes[ixButToggle]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t&#160;<img id=\"" << consref << "\" class=\"but\" src=\"../icon/toggle.png\" width=\"16\" height=\"16\" valign=\"bottom\" alt=\"" << consref << "\" onmouseover=\"src='../icon/toggle_hlt.png'\" onmouseout=\"src='../icon/toggle.png'\" onclick=\"handle" << consref << "Click()\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"dyn" << baseconshort << "\" colspan=\"5\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		if (icsButs.size() > 0) {
			if (rdyn) {
				outfile << "\t\t\t\t\t<td id=\"rdyn" << baseconshort << "\" colspan=\"2\" align=\"left\">" << endl;
				outfile << "\t\t\t\t\t</td>" << endl;

			} else {
				outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
				wrBaseconXml_buts(dbswznm, Prjshort, outfile, cons, icsButs, ditshort);
				outfile << "\t\t\t\t\t</td>" << endl;
			};

		} else {
			outfile << "\t\t\t\t\t<td colspan=\"2\"></td>" << endl;
		};

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::ULD) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"5\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<input id=\"" << baseconsref << "\" class=\"uld\" type=\"file\" maxlength=\"1000000\" name=\"file\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"2\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<input id=\"" << baseconshort << "But\" class=\"but\" type=\"submit\" value=\"" << baseconshort << "But\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t</tr>" << endl;

	} else if (cplxtype == Concplxtype::UPD) {
		outfile << "\t\t\t\t<tr id=\"tr" << baseconshort << "\" class=\"show\">" << endl;
		outfile << "\t\t\t\t\t<td height=\"25\"></td>" << endl;

		outfile << "\t\t\t\t\t<td align=\"right\">" << endl;
		if ((ixChk+1) != 0) {
			con = cons.nodes[ixChk]; consref = Wznm::getConsref(con, ditshort);
			outfile << "\t\t\t\t\t\t<input id=\"" << consref << "\" class=\"chk\" name=\"" << consref << "\" type=\"checkbox\" checked=\"checked\" onchange=\"handle" << consref << "Change()\"/>" << endl;
		};
		con = cons.nodes[ixCpt]; consref = Wznm::getConsref(con, ditshort);
		outfile << "\t\t\t\t\t\t<span id=\"" << consref << "\" class=\"cpt\">" << consref << "</span>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"3\" align=\"left\">" << endl;
		outfile << "\t\t\t\t\t\t<input id=\"" << baseconsref << "Val\" class=\"txfs\" type=\"text\" value=\"" << baseconsref << "Val\" onchange=\"handle" << baseconsref << "ValChange()\" onkeypress=\"return handle" << baseconsref << "ValKey(event)\"/>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td></td>" << endl;

		outfile << "\t\t\t\t\t<td id=\"td" << baseconsref << "\">" << endl;
		outfile << "\t\t\t\t\t\t<svg class=\"svg\" width=\"16\" height=\"25\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
		outfile << "\t\t\t\t\t\t\t<g id=\"" << baseconsref << "Up\" class=\"upd\" onclick=\"handle" << baseconsref << "UpClick()\">" << endl;
		outfile << "\t\t\t\t\t\t\t\t<rect x=\"0\" y=\"5\" width=\"16\" height=\"4\" fill=\"white\" stroke=\"none\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t\t<line x1=\"0\" y1=\"9\" x2=\"8\" y2=\"5\" stroke-width=\"1\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t\t<line x1=\"8\" y1=\"5\" x2=\"16\" y2=\"9\" stroke-width=\"1\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t</g>" << endl;
		outfile << "\t\t\t\t\t\t\t<g id=\"" << baseconsref << "Down\" class=\"upd\" onclick=\"handle" << baseconsref << "DownClick()\">" << endl;
		outfile << "\t\t\t\t\t\t\t\t<rect x=\"0\" y=\"17\" width=\"16\" height=\"4\" fill=\"white\" stroke=\"none\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t\t<line x1=\"0\" y1=\"17\" x2=\"8\" y2=\"21\" stroke-width=\"1\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t\t<line x1=\"8\" y1=\"21\" x2=\"16\" y2=\"17\" stroke-width=\"1\"/>" << endl;
		outfile << "\t\t\t\t\t\t\t</g>" << endl;
		outfile << "\t\t\t\t\t\t</svg>" << endl;
		outfile << "\t\t\t\t\t</td>" << endl;

		outfile << "\t\t\t\t\t<td colspan=\"3\"></td>" << endl;

		outfile << "\t\t\t\t</tr>" << endl;
	};
};

void WznmWrweb::wrBaseconXml_buts(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, ListWznmMControl& cons
			, vector<unsigned int>& icsButs
			, const string& ditshort
		) {
	WznmMControl* con = NULL;
	string consref;

	string s;

	for (unsigned int i = 0; i < icsButs.size(); i++) {
		con = cons.nodes[icsButs[i]];
		consref = Wznm::getConsref(con, ditshort);

		if (StrMod::srefInSrefs(con->srefsKOption, "icon")) {
			s = getButicon(dbswznm, Prjshort, con);

			outfile << "\t\t\t\t\t\t";
			if (i != 0) outfile << "&#160;";
			outfile << "<img id=\"" << consref << "\" class=\"but\" src=\"../" << s << ".png\" width=\"16\" height=\"16\" alt=\"" << consref
						<< "\" onmouseover=\"src='../" << s << "_hlt.png'\" onmouseout=\"src='../" << s << ".png'\" onclick=\"handle" << consref << "Click()\"/>" << endl;

		} else {
			outfile << "\t\t\t\t\t\t";
			if (i != 0) outfile << "&#160;&#160;";
			outfile << "<span id=\"" << consref << "\" class=\"but\" onclick=\"handle" << consref << "Click()\">" << consref << "</span>" << endl;
		};
	};
};

void WznmWrweb::wrBconiniJs(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const unsigned int ixIcsBasecons
			, const string& hkroot
			, const string& ditshort
		) {
	unsigned int cplxtype;
	string baseconsref, baseconshort;
	bool ldyn, dyn, rdyn, vbar;
	unsigned int ix0, ix1;
	unsigned int ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView;
	vector<unsigned int> icsButs;
	unsigned int ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt;
	vector<unsigned int> icsVbarcons;

	WznmMControl* basecon = NULL;

	string doc;

	string consref;

	basecon = cons.nodes[icsBasecons[ixIcsBasecons]];

	Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, ixIcsBasecons, ditshort, cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
				icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

	doc = getCondoc(basecon);

	if (cplxtype == Concplxtype::INVALID) {

	} else if (cplxtype == Concplxtype::BUT_CLUST) {
		if ((ixCpt+1) != 0) wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		if (!dyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::CHK) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::CUS) {

	} else if (cplxtype == Concplxtype::DLD) {
		outfile << "\tsetTextContent(" << doc << ", " << doc << ".getElementById(\"" << baseconsref << "\"), retrieveTi(srcdoc, \"Tag" << hkroot << ditshort << "\", \"" << baseconsref << "\"));" << endl;

	} else if (cplxtype == Concplxtype::HDG) {
		if (!dyn) {
			wrBconiniJs_cpt(outfile, cons, icsBasecons[ixIcsBasecons], hkroot, ditshort, doc);
			wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);
		};

	} else if (cplxtype == Concplxtype::LST) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::LST_NOALT) {

	} else if (cplxtype == Concplxtype::LST_TXFALT) {
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::LST_TXTALT) {
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::PUP) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		wrBconiniJs_pup(dbswznm, outfile, basecon, hkroot, ditshort, doc);
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::PUP_PUP) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		wrBconiniJs_pup(dbswznm, outfile, cons.nodes[ixPup], hkroot, ditshort, doc);
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::PUP_TXFALT) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::PUP_VBAR) {
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::RBU) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		wrBconiniJs_rbu(dbswznm, outfile, basecon, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::SEP) {

	} else if (cplxtype == Concplxtype::SLD) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::SPC) {

	} else if (cplxtype == Concplxtype::TXF) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::TXT) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::TXT_PUP) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		wrBconiniJs_pup(dbswznm, outfile, cons.nodes[ixPup], hkroot, ditshort, doc);
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::TXT_TXFALT) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		if (!rdyn) wrBconiniJs_buts(outfile, cons, icsButs, hkroot, ditshort, doc);

	} else if (cplxtype == Concplxtype::ULD) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
		outfile << "\t" << doc << ".getElementById(\"form\").setAttribute(\"action\", \"/upload/\" + scrJref);" << endl;
		outfile << "\t" << doc << ".getElementById(\"" << baseconshort << "But\").value = retrieveTi(srcdoc, \"Tag" << hkroot << ditshort << "\", \"" << baseconsref << "\");" << endl;

	} else if (cplxtype == Concplxtype::UPD) {
		wrBconiniJs_cpt(outfile, cons, ixCpt, hkroot, ditshort, doc);
	};
};

void WznmWrweb::wrBconiniJs_buts(
			fstream& outfile
			, ListWznmMControl& cons
			, vector<unsigned int>& icsButs
			, const string& hkroot
			, const string& ditshort
			, const string& doc
		) {
	WznmMControl* con = NULL;
	string consref;

	for (unsigned int i = 0; i < icsButs.size(); i++) {
		con = cons.nodes[icsButs[i]];
		consref = Wznm::getConsref(con, ditshort);

		if (!StrMod::srefInSrefs(con->srefsKOption, "icon")) {
			outfile << "\tinitBut(" << doc << ", \"" << consref << "\", retrieveTi(srcdoc, \"Tag" << hkroot << ditshort << "\", \"" << consref << "\"));" << endl;
		};
	};
};

void WznmWrweb::wrBconiniJs_cpt(
			fstream& outfile
			, ListWznmMControl& cons
			, const unsigned int ixCpt
			, const string& hkroot
			, const string& ditshort
			, const string& doc
		) {
	WznmMControl* con = NULL;
	string consref;

	con = cons.nodes[ixCpt];
	consref = Wznm::getConsref(con, ditshort);

	outfile << "\tinitCpt(" << doc << ", \"" << consref << "\", retrieveTi(srcdoc, \"Tag" << hkroot << ditshort << "\", \"" << consref << "\"));" << endl;
};

void WznmWrweb::wrBconiniJs_pup(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMControl* con
			, const string& hkroot
			, const string& ditshort
			, const string& doc
		) {
	string consref;

	string numSel;
	string act;

	consref = Wznm::getConsref(con, ditshort);

	if (hasStfeed(dbswznm, con)) {
		if (con->ixVScope == VecWznmVMControlScope::SHR) numSel = "retrieveCi(srcdoc, \"ContIac" + hkroot + ditshort + "\", \"numF" + consref + "\")";
		else numSel = "1";

		if (con->Active != "") act = "retrieveSi(srcdoc, \"StatShr" + hkroot + ditshort + "\", \"" + consref + "Active\")";
		else act = "true";

		outfile << "\trefreshPup(" << doc << ", srcdoc, \"" << consref << "\", \"" << getConsize(con) << "\", \"FeedF" << con->sref << "\", " << numSel << ", " << act << ", false);" << endl;
	};
};

void WznmWrweb::wrBconiniJs_rbu(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMControl* con
			, const string& hkroot
			, const string& ditshort
			, const string& doc
		) {
	string consref;

	string numSel;
	string act;

	consref = Wznm::getConsref(con, ditshort);

	if (hasStfeed(dbswznm, con)) {
		if (con->ixVScope == VecWznmVMControlScope::SHR) numSel = "retrieveCi(srcdoc, \"ContIac" + hkroot + ditshort + "\", \"numF" + consref + "\")";
		else numSel = "1";

		if (con->Active != "") act = "retrieveSi(srcdoc, \"StatShr" + hkroot + ditshort + "\", \"" + consref + "Active\")";
		else act = "true";

		outfile << "\trefreshRbu(" << doc << ", srcdoc, \"" << consref << "\", \"FeedF" << con->sref << "\", " << numSel << ", " << act << ");" << endl;
	};
};

bool WznmWrweb::wrBconvarsJs(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const unsigned int ixIcsBasecons
			, const string& hkroot
			, const string& ditshort
		) {
	unsigned int cplxtype;
	string baseconsref, baseconshort;
	bool ldyn, dyn, rdyn, vbar;
	unsigned int ix0, ix1;
	unsigned int ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView;
	vector<unsigned int> icsButs;
	unsigned int ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt;
	vector<unsigned int> icsVbarcons;

	WznmMControl* con = NULL;

	string consref;

	bool found;

	Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, ixIcsBasecons, ditshort, cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
				icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

	// alt flag
	if ( (cplxtype == Concplxtype::LST_NOALT) || (cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::LST_TXTALT) || (cplxtype == Concplxtype::PUP_TXFALT)
							|| (cplxtype == Concplxtype::TXT_TXFALT) )
				outfile << "\tvar " << baseconsref << "Alt = (retrieveSi(srcdoc, \"StatApp" << hkroot << ditshort << "\", \"" << baseconsref << "Alt\") == \"true\");" << endl;

	// valid flag
	if ((cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::PUP_TXFALT) || (cplxtype == Concplxtype::TXT_TXFALT))
				outfile << "\tvar Txf" << baseconshort << "Valid = (retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"Txf" << baseconshort << "Valid\") == \"true\");" << endl;

	// avail/active flags of sub-controls
	if (cplxtype != Concplxtype::INVALID) {
		for (unsigned int i=ix0;i<=ix1; i++) {
			con = cons.nodes[i];
			consref = Wznm::getConsref(con, ditshort);

			if (i == ixButView) {
				if ( (cplxtype == Concplxtype::LST_NOALT) || (cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::LST_TXTALT) || (cplxtype == Concplxtype::PUP_TXFALT)
							|| (cplxtype == Concplxtype::TXT_TXFALT) ) {
					
					outfile << "\tvar " << consref << "Avail = !" << baseconsref << "Alt";
					if (con->Avail != "") outfile << " && (retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"" << consref << "Avail\") == \"true\");";
					outfile << ";" << endl;

				} else {
					if (con->Avail != "") outfile << "\tvar " << consref << "Avail = (retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"" << consref << "Avail\") == \"true\");" << endl;
				};

			} else {
				if (con->Avail != "") outfile << "\tvar " << consref << "Avail = (retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"" << consref << "Avail\") == \"true\");" << endl;
			};

			if (con->Active != "") outfile << "\tvar " << consref << "Active = (retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"" << consref << "Active\") == \"true\");" << endl;
		};
	};

	// avail of BUT_CLUST base control
	if ((cplxtype == Concplxtype::BUT_CLUST) && (icsButs.size() > 1)) {
		found = true;

		for (unsigned int i = 0; i < icsButs.size(); i++) {
			con = cons.nodes[icsButs[i]];

			if (con->Avail == "") {
				found = false;
				break;
			};
		};

		if (found) {
			outfile << "\tvar " << baseconshort << "Avail = (";
			for (unsigned int i = 0; i < icsButs.size(); i++) {
				con = cons.nodes[icsButs[i]];
				consref = Wznm::getConsref(con, ditshort);

				if (i != 0) outfile << " || ";
				outfile << consref << "Avail";
			};
			outfile << ");" << endl;
		};
	};

	// height of CUS base control
	if (cplxtype == Concplxtype::CUS) {
		con = cons.nodes[icsBasecons[ixIcsBasecons]];

		if (StrMod::srefInSrefs(con->srefsKOption, "varh")) outfile << "\tvar " << baseconsref << "Height = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"" << baseconsref << "Height\"));" << endl;
	};

	outfile << endl;

	return(ldyn || dyn || rdyn);
};

void WznmWrweb::wrBconrefrJs(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, const string& hksref
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const unsigned int ixIcsBasecons
			, const string& hkroot
			, const string& ditshort
			, const bool _large
		) {
	unsigned int cplxtype;
	string baseconsref, baseconshort, baseconsize;
	bool ldyn, dyn, rdyn, vbar;
	unsigned int ix0, ix1;
	unsigned int ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView;
	vector<unsigned int> icsButs;
	unsigned int ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt;
	vector<unsigned int> icsVbarcons;

	WznmMControl* basecon = NULL;
	WznmMControl* con = NULL;

	string doc;

	string consref, consize;

	bool hasavail;
	string active;

	string indent;

	string large;

	if (_large) large = "true"; else large = "false";

	basecon = cons.nodes[icsBasecons[ixIcsBasecons]];

	Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, ixIcsBasecons, ditshort, cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
				icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

	doc = getCondoc(basecon);

	// - availability of entire <tr>
	hasavail = false;
	active = "true";

	if ((cplxtype == Concplxtype::BUT_CLUST) && (icsButs.size() > 1)) {
		hasavail = true;

		for (unsigned int i = 0; i < icsButs.size(); i++) {
			con = cons.nodes[icsButs[i]];

			if (con->Avail == "") {
				hasavail = false;
				break;
			};
		};

	} else if (cplxtype != Concplxtype::INVALID) {
		hasavail = (basecon->Avail != "");
		if (basecon->Active != "") active = baseconsref + "Active";
	};

	if (hasavail) {
		outfile << "\t";
		if (basecon->hkIxVTbl == VecWznmVMControlHkTbl::PNL) outfile << "height -= ";
		
		if ((cplxtype == Concplxtype::BUT_CLUST) && (icsButs.size() > 1)) {
			outfile << "setCtlAvail(" << doc << ", \"" << baseconshort << "\", " << baseconshort << "Avail, " << Wznm::getConheight(dbswznm, basecon) << ");" << endl;
		} else if (cplxtype == Concplxtype::SEP) {
			outfile << "setCtlAvail(" << doc << ", \"" << baseconshort << "1\", " << baseconsref << "Avail, 0);" << endl;
			outfile << "\tsetCtlAvail(" << doc << ", \"" << baseconshort << "2\", " << baseconsref << "Avail, " << Wznm::getConheight(dbswznm, basecon) << ");" << endl;
			outfile << "\tsetCtlAvail(" << doc << ", \"" << baseconshort << "3\", " << baseconsref << "Avail, 0);" << endl;
		} else {
			outfile << "setCtlAvail(" << doc << ", \"" << baseconshort << "\", " << baseconsref << "Avail, " << Wznm::getConheight(dbswznm, basecon) << ");" << endl;
		};
	};

	if ((cplxtype == Concplxtype::LST_NOALT) || (cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::LST_TXTALT)) {
		outfile << "\t";
		if (basecon->hkIxVTbl == VecWznmVMControlHkTbl::PNL) outfile << "height -= ";

		outfile << "setCtlAvail(" << doc << ", \"" << baseconshort << "2\", ";
		if (hasavail) outfile << baseconsref << "Avail && ";
		outfile << "!" << baseconsref << "Alt";
		if (hasavail) outfile << ", (" << baseconsref << "Avail) ? 71 : 0";
		else outfile << ", 71";
		outfile << ");" << endl;
	};

	if (hasavail) {
		if ((cplxtype == Concplxtype::BUT_CLUST) && (icsButs.size() > 1)) {
			outfile << "\tif (" << baseconshort << "Avail) {" << endl;
		} else {
			outfile << "\tif (" << baseconsref << "Avail) {" << endl;
		};

		indent = "\t\t";
	
	} else indent = "\t";
	
	// - ldyn
	if (ldyn) {
		if ((cplxtype == Concplxtype::LST_NOALT) || (cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::LST_TXTALT)) {
			outfile << indent << "if ( (" << baseconsref << "Alt == !" << doc << ".getElementById(\"But" << baseconshort << "Expand\")) || (!" << baseconsref << "Alt == !" << doc << ".getElementById(\"But" << baseconshort << "Collapse\")) ) {" << endl;
			outfile << indent << "\tmytd = " << doc << ".getElementById(\"ldyn" << baseconshort << "\");" << endl;
			outfile << indent << "\tclearElem(mytd);" << endl;
			outfile << endl;

			outfile << indent << "\tmytd.appendChild(makeSpanCpt(" << doc << ", \"Cpt" << baseconshort << "\", retrieveTi(srcdoc, \"Tag" << hkroot << ditshort << "\", \"Cpt" << baseconshort << "\")));" << endl;
			outfile << endl;

			outfile << indent << "\tmytd.appendChild(" << doc << ".createTextNode(\"\\u00a0\"));" << endl;
			outfile << indent << "\tif (" << baseconsref << "Alt) mytd.appendChild(makeImgBut(" << doc << ", \"But" << baseconshort << "Expand\", \"icon/expand\"));" << endl;
			outfile << indent << "\telse mytd.appendChild(makeImgBut(" << doc << ", \"But" << baseconshort << "Collapse\", \"icon/collapse\"));" << endl;
			outfile << indent << "};" << endl;
			outfile << endl;
		};
	};

	// - dyn
	if (dyn) {
		if (cplxtype == Concplxtype::BUT_CLUST) {
			wrBconrefrJs_buts(dbswznm, Prjshort, outfile, cons, ixHdg, ixButView, icsButs, hkroot, ditshort, baseconsref, baseconshort, false, doc, true, false, indent);

		} else if (cplxtype == Concplxtype::HDG) {
			wrBconrefrJs_buts(dbswznm, Prjshort, outfile, cons, ixHdg, ixButView, icsButs, hkroot, ditshort, baseconsref, baseconshort, false, doc, true, false, indent);

		} else if (cplxtype == Concplxtype::LST_NOALT) {
			outfile << indent << "if (!" << baseconsref << "Alt == !" << doc << ".getElementById(\"" << baseconsref << "\")) {" << endl;
			if (rdyn) {
				outfile << indent << "\tmytd = " << doc << ".getElementById(\"rdyn" << baseconshort << "\");" << endl;
				outfile << indent << "\tclearElem(mytd);" << endl;
			};
			outfile << indent << "\tmytd = " << doc << ".getElementById(\"dyn" << baseconshort << "\");" << endl;
			outfile << indent << "\tclearElem(mytd);" << endl;
			outfile << endl;

			outfile << indent << "\tif (" << baseconsref << "Alt) {" << endl;
			outfile << indent << "\t\tmytd.setAttribute(\"rowspan\", \"1\");" << endl;
			outfile << indent << "\t} else {" << endl;
			outfile << indent << "\t\tmytd.setAttribute(\"rowspan\", \"2\");" << endl;
			outfile << indent << "\t\tmytd.appendChild(makeIframeLst(" << doc << ", \"" << baseconsref << "\", \"./" << hksref << ditshort << "_" << Wznm::getConsref(basecon, ditshort) << ".xml\", " << large << "));" << endl;
			outfile << indent << "\t};" << endl;
			outfile << endl;

			outfile << indent << "} else {" << endl;
			if (StrMod::srefInSrefs(basecon->srefsKOption, "multsel")) {
				outfile << indent << "\tif (!" << baseconsref << "Alt) refreshLst(" << doc << ".getElementById(\"" << baseconsref << "\").contentWindow.document, srcdoc, " << getLstncol(basecon) << ", " << large << ", true, \"FeedF" << basecon->sref << "\"," << endl;
				outfile << indent << "\t\t\t\tparseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << ditshort << "\", \"" << baseconsref << "NumFirstdisp\")), parseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numsF" << baseconsref << "\")));" << endl;
			} else {
				outfile << indent << "\tif (!" << baseconsref << "Alt) refreshLst(" << doc << ".getElementById(\"" << baseconsref << "\").contentWindow.document, srcdoc, " << getLstncol(basecon) << ", " << large << ", false, \"FeedF" << basecon->sref << "\"," << endl;
				outfile << indent << "\t\t\t\tparseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << ditshort << "\", \"" << baseconsref << "NumFirstdisp\")), [parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numF" << baseconsref << "\"))]);" << endl;
			};
			outfile << indent << "};" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::LST_TXFALT) {
			con = cons.nodes[ixTxf];
			consref = Wznm::getConsref(con, ditshort);

			outfile << indent << "if ( (" << baseconsref << "Alt == !" << doc << ".getElementById(\"" << consref << "\")) || (!" << baseconsref << "Alt == !" << doc << ".getElementById(\"" << baseconsref << "\")) ) {" << endl;
			outfile << indent << "\tmytd = " << doc << ".getElementById(\"dyn" << baseconshort << "\");" << endl;
			outfile << indent << "\tclearElem(mytd);" << endl;
			outfile << endl;

			outfile << indent << "\tif (" << baseconsref << "Alt) {" << endl;
			outfile << indent << "\t\tmytd.setAttribute(\"rowspan\", \"1\");" << endl;
			outfile << indent << "\t\tmytd.appendChild(makeInputTxf(" << doc << ", \"" << consref << "\", \"\"));" << endl;
			outfile << indent << "\t} else {" << endl;
			outfile << indent << "\t\tmytd.setAttribute(\"rowspan\", \"2\");" << endl;
			outfile << indent << "\t\tmytd.appendChild(makeIframeLst(" << doc << ", \"" << baseconsref << "\", \"./" << hksref << ditshort << "_" << Wznm::getConsref(basecon, ditshort) << ".xml\", " << large << "));" << endl;
			outfile << indent << "\t};" << endl;
			outfile << endl;

			outfile << indent << "} else {" << endl;
			if (StrMod::srefInSrefs(basecon->srefsKOption, "multsel")) {
				outfile << indent << "\tif (!" << baseconsref << "Alt) refreshLst(" << doc << ".getElementById(\"" << baseconsref << "\").contentWindow.document, srcdoc, " << getLstncol(basecon) << ", " << large << ", true, \"FeedF" << basecon->sref << "\"," << endl;
				outfile << indent << "\t\t\t\tparseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << ditshort << "\", \"" << baseconsref << "NumFirstdisp\")), parseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numsF" << baseconsref << "\")));" << endl;
			} else {
				outfile << indent << "\tif (!" << baseconsref << "Alt) refreshLst(" << doc << ".getElementById(\"" << baseconsref << "\").contentWindow.document, srcdoc, " << getLstncol(basecon) << ", " << large << ", false, \"FeedF" << basecon->sref << "\"," << endl;
				outfile << indent << "\t\t\t\tparseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << ditshort << "\", \"" << baseconsref << "NumFirstdisp\")), [parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numF" << baseconsref << "\"))]);" << endl;
			};
			outfile << indent << "};" << endl;
			outfile << endl;

			outfile << indent << "if (" << baseconsref << "Alt) refreshTxf(" << doc << ", \"" << consref << "\", \"\", retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << consref << "\"), " << active << ", false, " << consref << "Valid);" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::LST_TXTALT) {
			con = cons.nodes[ixTxt];
			consref = Wznm::getConsref(con, ditshort);

			outfile << indent << "if ( (" << baseconsref << "Alt == !" << doc << ".getElementById(\"" << consref << "\")) || (!" << baseconsref << "Alt == !" << doc << ".getElementById(\"" << baseconsref << "\")) ) {" << endl;
			outfile << indent << "\tmytd = " << doc << ".getElementById(\"dyn" << baseconshort << "\");" << endl;
			outfile << indent << "\tclearElem(mytd);" << endl;
			outfile << endl;

			outfile << indent << "\tif (" << baseconsref << "Alt) {" << endl;
			outfile << indent << "\t\tmytd.setAttribute(\"rowspan\", \"1\");" << endl;
			outfile << indent << "\t\tmytd.appendChild(makeInputTxt(" << doc << ", \"" << consref << "\", \"\"));" << endl;
			outfile << indent << "\t} else {" << endl;
			outfile << indent << "\t\tmytd.setAttribute(\"rowspan\", \"2\");" << endl;
			outfile << indent << "\t\tmytd.appendChild(makeIframeLst(" << doc << ", \"" << baseconsref << "\", \"./" << hksref << ditshort << "_" << Wznm::getConsref(basecon, ditshort) << ".xml\", " << large << "));" << endl;
			outfile << indent << "\t};" << endl;
			outfile << endl;

			outfile << indent << "} else {" << endl;
			if (StrMod::srefInSrefs(basecon->srefsKOption, "multsel")) {
				outfile << indent << "\tif (!" << baseconsref << "Alt) refreshLst(" << doc << ".getElementById(\"" << baseconsref << "\").contentWindow.document, srcdoc, " << getLstncol(basecon) << ", " << large << ", true, \"FeedF" << basecon->sref << "\"," << endl;
				outfile << indent << "\t\t\t\tparseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << ditshort << "\", \"" << baseconsref << "NumFirstdisp\")), parseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numsF" << baseconsref << "\")));" << endl;
			} else {
				outfile << indent << "\tif (!" << baseconsref << "Alt) refreshLst(" << doc << ".getElementById(\"" << baseconsref << "\").contentWindow.document, srcdoc, " << getLstncol(basecon) << ", " << large << ", false, \"FeedF" << basecon->sref << "\"," << endl;
				outfile << indent << "\t\t\t\tparseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << ditshort << "\", \"" << baseconsref << "NumFirstdisp\")), [parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numF" << baseconsref << "\"))]);" << endl;
			};
			outfile << indent << "};" << endl;
			outfile << endl;

			outfile << indent << "if (" << baseconsref << "Alt) refreshTxt(" << doc << ", \"" << consref << "\", retrieveCi(srcdoc, \"ContInf" << hkroot << ditshort << "\", \"" << consref << "\"));" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::PUP_TXFALT) {
			con = cons.nodes[ixTxf];
			consref = Wznm::getConsref(con, ditshort);

			outfile << indent << "if ( (" << baseconsref << "Alt == !" << doc << ".getElementById(\"" << consref << "\")) || (!" << baseconsref << "Alt == !" << doc << ".getElementById(\"" << baseconsref << "\")) ) {" << endl;
			outfile << indent << "\tmytd = " << doc << ".getElementById(\"dyn" << baseconshort << "\");" << endl;
			outfile << indent << "\tclearElem(mytd);" << endl;
			outfile << endl;

			outfile << indent << "\tif (" << baseconsref << "Alt) mytd.appendChild(makeInputTxf(" << doc << ", \"" << consref << "\", \"\"));" << endl;
			outfile << indent << "\telse mytd.appendChild(makeSelectPup(" << doc << ", \"" << baseconsref << "\", \"\"));" << endl;
			outfile << indent << "};" << endl;
			outfile << endl;

			outfile << indent << "if (" << baseconsref << "Alt) refreshTxf(" << doc << ", \"" << consref << "\", \"\", retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << consref << "\"), " << active << ", false, " << consref << "Valid);" << endl;
			outfile << indent << "else refreshPup(" << doc << ", srcdoc, \"" << baseconsref << "\", \"\", \"FeedF" << basecon->sref << "\", retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numF" << baseconsref << "\"), true, false);" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::TXT_TXFALT) {
			con = cons.nodes[ixTxf];

			consref = Wznm::getConsref(con, ditshort);
			consize = getConsize(con);

			outfile << indent << "if ( (" << baseconsref << "Alt == !" << doc << ".getElementById(\"" << consref << "\")) || (!" << baseconsref << "Alt == !" << doc << ".getElementById(\"" << baseconsref << "\")) ) {" << endl;
			outfile << indent << "\tmytd = " << doc << ".getElementById(\"dyn" << baseconshort << "\");" << endl;
			outfile << indent << "\tclearElem(mytd);" << endl;
			outfile << endl;

			outfile << indent << "\tif (" << baseconsref << "Alt) mytd.appendChild(makeInputTxf(" << doc << ", \"" << consref << "\", \"" << consize << "\"));" << endl;
			outfile << indent << "\telse mytd.appendChild(makeInputTxt(" << doc << ", \"" << baseconsref << "\", \"" << consize << "\"));" << endl;
			outfile << indent << "};" << endl;
			outfile << endl;

			if (consize == "t") {
				outfile << indent << "if (" << baseconsref << "Alt) refreshTxft(" << doc << ", \"" << consref << "\", retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << consref << "\"), " << active << ", false, " << consref << "Valid);" << endl;
				outfile << indent << "else refreshTxtt(" << doc << ", \"" << baseconsref << "\", retrieveCi(srcdoc, \"ContInf" << hkroot << ditshort << "\", \"" << baseconsref << "\"));" << endl;
			} else {
				outfile << indent << "if (" << baseconsref << "Alt) refreshTxf(" << doc << ", \"" << consref << "\", \"" << consize << "\", retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << consref << "\"), " << active << ", false, " << consref << "Valid);" << endl;
				outfile << indent << "else refreshTxt(" << doc << ", \"" << baseconsref << "\", retrieveCi(srcdoc, \"ContInf" << hkroot << ditshort << "\", \"" << baseconsref << "\"));" << endl;
			};
			outfile << endl;
		};
	};

	// - rdyn
	if (rdyn) {
		if ((cplxtype == Concplxtype::LST_NOALT) || (cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::LST_TXTALT) || (cplxtype == Concplxtype::TXT_TXFALT)) {
			wrBconrefrJs_buts(dbswznm, Prjshort, outfile, cons, ixHdg, ixButView, icsButs, hkroot, ditshort, baseconsref, baseconshort, true, doc, (cplxtype == Concplxtype::LST_NOALT), true, indent);

		} else if ((cplxtype == Concplxtype::LST) || (cplxtype == Concplxtype::PUP) || (cplxtype == Concplxtype::PUP_PUP) || (cplxtype == Concplxtype::PUP_TXFALT)
					|| (cplxtype == Concplxtype::PUP_VBAR) || (cplxtype == Concplxtype::TXF) || (cplxtype == Concplxtype::TXT) || (cplxtype == Concplxtype::TXT_PUP)) {

			wrBconrefrJs_buts(dbswznm, Prjshort, outfile, cons, ixHdg, ixButView, icsButs, hkroot, ditshort, baseconsref, baseconshort, false, doc, false, true, indent);
		};
	};

	// - height of CUS base control
	if ((cplxtype == Concplxtype::CUS) && StrMod::srefInSrefs(basecon->srefsKOption, "varh")) {
		outfile << indent << "mytd = " << doc << ".getElementById(\"td" << baseconshort << "\");" << endl;
		outfile << indent << "mytd.setAttribute(\"height\", \"\" + " << baseconsref << "Height);" << endl;
		if (basecon->hkIxVTbl == VecWznmVMControlHkTbl::PNL) outfile << indent << "height += " << baseconsref << "Height-100;" << endl;
	};

	// - content
	if (cplxtype == Concplxtype::CHK) {
		outfile << indent << "refreshChk(" << doc << ", \"" << baseconsref << "\", (retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << baseconsref << "\") == \"true\"), " << active << ");" << endl;

	} else if (cplxtype == Concplxtype::DLD) {
		outfile << indent << "refreshDld(" << doc << ", \"" << baseconsref << "\", scrJref, retrieveCi(srcdoc, \"ContInf" << hkroot << ditshort << "\", \"" << baseconsref << "\"), " << active << ");" << endl;

	} else if (cplxtype == Concplxtype::LST) {
		if (StrMod::srefInSrefs(basecon->srefsKOption, "multsel")) {
			outfile << indent << "refreshLst(" << doc << ".getElementById(\"" << baseconsref << "\").contentWindow.document, srcdoc, " << getLstncol(basecon) << ", " << large << ", true, \"FeedF" << basecon->sref << "\"," << endl;
			outfile << indent << "\t\t\tparseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << ditshort << "\", \"" << baseconsref << "NumFirstdisp\")), parseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numsF" << baseconsref << "\")));" << endl;
		} else {
			outfile << indent << "refreshLst(" << doc << ".getElementById(\"" << baseconsref << "\").contentWindow.document, srcdoc, " << getLstncol(basecon) << ", " << large << ", false, \"FeedF" << basecon->sref << "\"," << endl;
			outfile << indent << "\t\t\tparseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << ditshort << "\", \"" << baseconsref << "NumFirstdisp\")), [parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numF" << baseconsref << "\"))]);" << endl;
		};

	} else if (cplxtype == Concplxtype::LST_NOALT) {
		// handled in dyn
	} else if (cplxtype == Concplxtype::LST_TXFALT) {
		// handled in dyn
	} else if (cplxtype == Concplxtype::LST_TXTALT) {
		// handled in dyn

	} else if (cplxtype == Concplxtype::PUP) {
		wrBconrefrJs_pup(dbswznm, outfile, basecon, hkroot, ditshort, doc, active, indent);

	} else if (cplxtype == Concplxtype::PUP_PUP) {
		outfile << indent << "refreshPup(" << doc << ", srcdoc, \"" << baseconsref << "\", \"s\", \"FeedF" << basecon->sref << "\", retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numF" << baseconsref << "\"), " << active << ", false);" << endl;

		con = cons.nodes[ixPup];
		wrBconrefrJs_pup(dbswznm, outfile, con, hkroot, ditshort, doc, active, indent);

	} else if (cplxtype == Concplxtype::PUP_TXFALT) {
		// handled in dyn

	} else if (cplxtype == Concplxtype::PUP_VBAR) {
		outfile << indent << "refreshPup(" << doc << ", srcdoc, \"" << baseconsref << "\", \"s\", \"FeedF" << basecon->sref << "\", retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"numF" << baseconsref << "\"), " << active << ", false);" << endl;

	} else if (cplxtype == Concplxtype::RBU) {
		wrBconrefrJs_rbu(dbswznm, outfile, basecon, hkroot, ditshort, doc, active, indent);

	} else if (cplxtype == Concplxtype::SLD) {
		if (basecon->ixVScope == VecWznmVMControlScope::SHR) {
			outfile << indent << "refreshSld(" << doc << ", \"" << baseconsref << "\", " << large;
			if (StrMod::srefInSrefs(basecon->srefsKOption, "log")) outfile << ", true"; else outfile << ", false";
			outfile << ", parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"" << baseconsref << "Min\")), parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"" << baseconsref << "Max\")), parseFloat(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << baseconsref << "\")), " << active << ", false);" << endl;
		};

	} else if (cplxtype == Concplxtype::TXF) {
		baseconsize = getConsize(basecon);

		if (baseconsize == "t") outfile << indent << "refreshTxft(" << doc << ", \"" << baseconsref << "\", retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << baseconsref << "\"), " << active << ", false, true);" << endl;
		else outfile << indent << "refreshTxf(" << doc << ", \"" << baseconsref << "\", \"" << baseconsize << "\", retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << baseconsref << "\"), " << active << ", false, true);" << endl;

	} else if (cplxtype == Concplxtype::TXT) {
		baseconsize = getConsize(basecon);

		if (baseconsize == "t") outfile << indent << "refreshTxtt(" << doc << ", \"" << baseconsref << "\", retrieveCi(srcdoc, \"ContInf" << hkroot << ditshort << "\", \"" << baseconsref << "\"));" << endl;
		else outfile << indent << "refreshTxt(" << doc << ", \"" << baseconsref << "\", retrieveCi(srcdoc, \"ContInf" << hkroot << ditshort << "\", \"" << baseconsref << "\"));" << endl;

	} else if (cplxtype == Concplxtype::TXT_PUP) {
		outfile << indent << "refreshTxt(" << doc << ", \"" << baseconsref << "\", retrieveCi(srcdoc, \"ContInf" << hkroot << ditshort << "\", \"" << baseconsref << "\"));" << endl;

		con = cons.nodes[ixPup];
		wrBconrefrJs_pup(dbswznm, outfile, con, hkroot, ditshort, doc, active, indent);

	} else if (cplxtype == Concplxtype::TXT_TXFALT) {
		// handled in dyn

	} else if (cplxtype == Concplxtype::UPD) {
		if (basecon->ixVScope == VecWznmVMControlScope::SHR)
					outfile << indent << "refreshUpd(" << doc << ", \"" << baseconsref << "\", parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"" << baseconsref << "Min\")), parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << ditshort << "\", \"" << baseconsref << "Max\")), parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << baseconsref << "\")), " << active << ", false);" << endl;
	};

	if (((cplxtype == Concplxtype::LST) || (cplxtype == Concplxtype::PUP) || (cplxtype == Concplxtype::SLD) || (cplxtype == Concplxtype::TXF) || (cplxtype == Concplxtype::UPD)) && ((ixChk+1) != 0)) {
		con = cons.nodes[ixChk];
		consref = Wznm::getConsref(con, ditshort);

		outfile << indent << "refreshChk(" << doc << ", \"" << consref << "\", (retrieveCi(srcdoc, \"ContIac" << hkroot << ditshort << "\", \"" << consref << "\") == \"true\"), " << active << ");" << endl;
	};

	outfile << endl;

	// - active flag (but/dld/uld only, for now)
	for (unsigned int i = 0; i < icsButs.size(); i++) {
		con = cons.nodes[icsButs[i]];
		consref = Wznm::getConsref(con, ditshort);

		if (con->Active != "") {
			outfile << indent;

			if ( (con->Avail != "") || ((icsButs[i] == ixButView) && ((cplxtype == Concplxtype::LST_NOALT) || (cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::LST_TXTALT) || (cplxtype == Concplxtype::TXT_TXFALT))) ) outfile << "if (" << consref << "Avail) ";

			if (StrMod::srefInSrefs(con->srefsKOption, "icon")) outfile << "refreshButicon(" << doc << ", \"" << consref << "\", \"" << getButicon(dbswznm, Prjshort, con) << "\", " << consref << "Active, false);" << endl;
			else outfile << "refreshBut(" << doc << ", \"" << consref << "\", " << consref << "Active, false);" << endl;
		};
	};

	if (basecon->Active != "") {
		// avail is guaranteed

		if (cplxtype == Concplxtype::ULD) {
			outfile << indent << "if (" << baseconsref << "Active) {" << endl;
			outfile << indent << "\t" << doc << ".getElementById(\"" << baseconshort << "But\").setAttribute(\"class\", \"but\");" << endl;
			outfile << indent << "\t" << doc << ".getElementById(\"" << baseconshort << "But\").setAttribute(\"type\", \"submit\");" << endl;
			outfile << indent << "} else {" << endl;
			outfile << indent << "\t" << doc << ".getElementById(\"" << baseconshort << "But\").setAttribute(\"class\", \"butinact\");" << endl;
			outfile << indent << "\t" << doc << ".getElementById(\"" << baseconshort << "But\").setAttribute(\"type\", \"reset\");" << endl;
			outfile << indent << "};" << endl;
		};
	};

	outfile << endl;

	if (hasavail) {
		if ( (cplxtype == Concplxtype::LST) || (cplxtype == Concplxtype::LST_NOALT) || (cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::LST_TXTALT) ) {
			outfile << "\t} else setCtlAvail(" << doc << ", \"" << baseconshort << "2\", false, 0);" << endl;
		} else {
			outfile << "\t};" << endl;
		};
	};
	outfile << endl;
};

void WznmWrweb::wrBconrefrJs_buts(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, ListWznmMControl& cons
			, const unsigned int ixHdg
			, const unsigned int ixButView
			, vector<unsigned int>& icsButs
			, const string& hkroot
			, const string& ditshort
			, const string& baseconsref
			, const string& baseconshort
			, const bool alt
			, const string& doc
			, const bool dyn
			, const bool rdyn
			, string indent
		) {
	WznmMControl* con = NULL;
	
	string consref;

	bool hasavail;
	bool hasicon;

	outfile << indent << "if (";

	for (unsigned int i = 0; i < icsButs.size(); i++) {
		con = cons.nodes[icsButs[i]];
		consref = Wznm::getConsref(con, ditshort);

		hasavail = ( (con->Avail != "") || ((icsButs[i]==ixButView) && alt) );

		if (i != 0) outfile << " || ";

		if (hasavail) outfile << "(" << consref << "Avail == !" << doc << ".getElementById(\"" << consref << "\"))";
		else outfile << "!" << doc << ".getElementById(\"" << consref << "\")";
	};

	outfile << ") {" << endl;

	if (dyn && rdyn) {
		outfile << indent << "\tif (" << baseconsref << "Alt) mytd = " << doc << ".getElementById(\"dyn" << baseconshort << "\");" << endl;
		outfile << indent << "\telse mytd = " << doc << ".getElementById(\"rdyn" << baseconshort << "\");" << endl;
	} else if (dyn) outfile << indent << "\tmytd = " << doc << ".getElementById(\"dyn" << baseconshort << "\");" << endl;
	else if (rdyn) outfile << indent << "\tmytd = " << doc << ".getElementById(\"rdyn" << baseconshort << "\");" << endl;

	outfile << indent << "\tclearElem(mytd);" << endl;
	outfile << endl;

	if ((ixHdg+1) != 0) {
		con = cons.nodes[ixHdg];
		consref = Wznm::getConsref(con, ditshort);

		outfile << indent << "\tmytd.appendChild(makeSpanCpt(" << doc << ", \"" << consref << "\", retrieveTi(srcdoc, \"Tag" << hkroot << ditshort << "\", \"" << consref << "\")));" << endl;
		outfile << indent << "\tmytd.appendChild(" << doc << ".createTextNode(\"\\u00a0\\u00a0\"));" << endl;
		outfile << endl;
	};

	outfile << indent << "\tfirst = true;" << endl;

	for (unsigned int i = 0; i < icsButs.size(); i++) {
		con = cons.nodes[icsButs[i]];
		consref = Wznm::getConsref(con, ditshort);

		hasavail = ( (con->Avail != "") || ((icsButs[i]==ixButView) && alt) );
		hasicon = StrMod::srefInSrefs(con->srefsKOption, "icon");

		outfile << endl;

		if (hasavail) {
			outfile << indent << "\tif (" << consref << "Avail) {" << endl;
			indent = indent + "\t";
		};

		outfile << indent << "\tif (first) first = false;" << endl;
		outfile << indent << "\telse mytd.appendChild(" << doc << ".createTextNode(\"";
		if (!hasicon) outfile << "\\u00a0";
		outfile << "\\u00a0\"));" << endl;

		if (hasicon) outfile << indent << "\tmytd.appendChild(makeImgBut(" << doc << ", \"" << consref << "\", \"" << getButicon(dbswznm, Prjshort, con) << "\"));" << endl;
		else outfile << indent << "\tmytd.appendChild(makeSpanBut(" << doc << ", \"" << consref << "\", retrieveTi(srcdoc, \"Tag" << hkroot << ditshort << "\", \"" << consref << "\")));" << endl;

		if (hasavail) {
			indent = indent.substr(1);
			outfile << indent << "\t};" << endl;
		};
	};

	outfile << indent << "};" << endl;
	outfile << endl;
};

void WznmWrweb::wrBconrefrJs_pup(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMControl* con
			, const string& hkroot
			, const string& ditshort
			, const string& doc
			, const string& active
			, const string& indent
		) {
	string consref;

	consref = Wznm::getConsref(con, ditshort);

	if (hasStfeed(dbswznm, con)) {
		outfile << indent << doc << ".getElementById(\"" << consref << "\").value = retrieveCi(srcdoc, \"ContIac" + hkroot + ditshort + "\", \"numF" + consref + "\");" << endl;
	} else {
		outfile << indent << "refreshPup(" << doc << ", srcdoc, \"" << consref << "\", \"" << getConsize(con) << "\", \"FeedF" << con->sref << "\", retrieveCi(srcdoc, \"ContIac" + hkroot + ditshort + "\", \"numF" + consref + "\"), " << active << ", false);" << endl;
	};
};

void WznmWrweb::wrBconrefrJs_rbu(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMControl* con
			, const string& hkroot
			, const string& ditshort
			, const string& doc
			, const string& active
			, const string& indent
		) {
	string consref;

	consref = Wznm::getConsref(con, ditshort);

	if (hasStfeed(dbswznm, con)) {
		outfile << indent << "setRbuValue(" << doc << ", \"" << consref << "\", retrieveCi(srcdoc, \"ContIac" + hkroot + ditshort + "\", \"numF" + consref + "\"), " << active << ");" << endl;
	} else {
		outfile << indent << "refreshRbu(" << doc << ", srcdoc, \"" << consref << "\", \"FeedF" << con->sref << "\", retrieveCi(srcdoc, \"ContIac" + hkroot + ditshort + "\", \"numF" + consref + "\"), " << active << ");" << endl;
	};
};

void WznmWrweb::wrEvthdlsJs( // ALL cons
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, ListWznmMControl& cons
			, const string& hkroot
			, const bool pnllist
			, const bool _large
		) {
	ubigint ref;

	WznmMControl* con = NULL;
	WznmMControl* con2 = NULL;

	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	set<uint> contypes;
	bool hasdse, hasbutmdnup, hastxf, hastxft;

	set<string> appactions;
	set<string> actions;

	string large;

	string s;

	bool first, found;

	if (_large) large = "true"; else large = "false";

	// --- specific event handlers (by dit for dialogs)
	outfile << "// --- specific event handlers for app controls" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVBasetype == VecWznmVMControlBasetype::DIT) {
			outfile << "// --- specific event handlers for app controls of dialog item " << con->sref.substr(3) << endl;
			outfile << endl;
		};

		if (con->ixVScope == VecWznmVMControlScope::APP) {
			if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
				if ((con->sref.length() > 8) && ((con->sref.rfind("Collapse")+8) == con->sref.length())) {
				} else if ((con->sref.length() > 6) && ((con->sref.rfind("Expand")+6) == con->sref.length())) {
				} else if ((con->sref.length() > 6) && ((con->sref.rfind("Toggle")+6) == con->sref.length())) {

				} else {
					if (StrMod::srefInSrefs(con->srefsKOption, "mdnup")) {
						// Mdn
						outfile << "function handle" << con->sref << "Mdn() {" << endl;
						outfile << "\t// IP handle" << con->sref << "Mdn --- INSERT" << endl;
						outfile << "};" << endl;
						outfile << endl;

						// Mup
						outfile << "function handle" << con->sref << "Mup() {" << endl;
						outfile << "\t// IP handle" << con->sref << "Mup --- INSERT" << endl;
						outfile << "};" << endl;
						outfile << endl;

					} else {
						// Click (some known standard event handlers)
						outfile << "function handle" << con->sref << "Click() {" << endl;

						if ((con->sref.length() > 6) && ((con->sref.rfind("Attach") + 6) == con->sref.length())) {
							// ...

						} else if ((con->sref.length() > 9) && ((con->sref.rfind("Clipboard") + 9) == con->sref.length())) {
							found = false;

							for (unsigned int j = 0; j < cons.nodes.size(); j++) {
								con2 = cons.nodes[j];

								if ((con2->ixVBasetype == VecWznmVMControlBasetype::TCO) && (con2->refIxVTbl == VecWznmVMControlRefTbl::QCO)) {
									found = dbswznm->loadRefBySQL("SELECT qryRefWznmMQuery FROM TblWznmMQuerycol WHERE ref = " + to_string(con2->refUref), ref);
									break;
								};
							};

							if (found) {
								dbswznm->tblwznmmquerycol->loadRstByQry(ref, false, qcos);

								outfile << "\tcopyToClipboard(document, srcdoc, \"" << hkroot << "\", \"List" << Prjshort << "Q" << hkroot.substr(4) << "\", retrieveTi(srcdoc, \"Tag" << hkroot << "\", \"TxtRecord1\"), retrieveTi(srcdoc, \"Tag" << hkroot << "\", \"TxtRecord2\")," << endl;

								// tags
								outfile << "\t\t\t\t[";
								first = true;

								for (unsigned int j = 0; j < qcos.nodes.size(); j++) {
									qco = qcos.nodes[j];

									if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
										if (first) first = false;
										else outfile << ",";

										outfile << "\"";

										for (unsigned int k = 0; k < cons.nodes.size(); k++) {
											con2 = cons.nodes[k];

											if ((con2->ixVBasetype == VecWznmVMControlBasetype::TCO) && (con2->refUref == qco->ref)) {
												outfile << con2->sref.substr(3);
												break;
											};
										};

										outfile << "\"";
									};
								};
								outfile << "]," << endl;

								// tcos
								outfile << "\t\t\t\t[";
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

						} else if ((con->sref.length() > 6) && ((con->sref.rfind("Detach") + 6) == con->sref.length())) {
							// ...

						} else if ((con->sref.length() > 8) && ((con->sref.rfind("Minimize") + 8) == con->sref.length())) {
							outfile << "\tminimize(true);" << endl;

						} else if ((con->sref.length() > 10) && ((con->sref.rfind("Regularize") + 10) == con->sref.length())) {
							outfile << "\tregularize(true);" << endl;

						} else {
							outfile << "\t// IP handle" << con->sref << "Click --- INSERT" << endl;
						};

						outfile << "};" << endl;
						outfile << endl;
					};
				};

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::CHK) {
				outfile << "function handle" << con->sref << "Change() {" << endl;
				outfile << "\t// IP handle" << con->sref << "Change --- INSERT" << endl;
				outfile << "};" << endl;
				outfile << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::CUS) {
				if (StrMod::srefInSrefs(con->srefsKOption, "iframe")) {
					outfile << "function handle" << con->sref << "Load(cusdoc) {" << endl;
					outfile << "\t// IP handle" << con->sref << "Load --- INSERT" << endl;
					outfile << "};" << endl;
					outfile << endl;
				};

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::LSB) {
				// ...

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::LST) {
				// ...

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::PUP) {
				outfile << "function handle" << con->sref << "Change() {" << endl;
				outfile << "\t// IP handle" << con->sref << "Change --- INSERT" << endl;
				outfile << "};" << endl;
				outfile << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::RBU) {
				outfile << "function handle" << con->sref << "Select(num) {" << endl;
				outfile << "\t// IP handle" << con->sref << "Select --- INSERT" << endl;
				outfile << "};" << endl;
				outfile << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::SLD) {
				outfile << "function handle" << con->sref << "Change(val) {" << endl;
				outfile << "\t// IP handle" << con->sref << "Change --- INSERT" << endl;
				outfile << "};" << endl;
				outfile << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::TXF) {
				outfile << "function handle" << con->sref << "Key(evt) {" << endl;
				outfile << "\t// IP handle" << con->sref << "Key --- INSERT" << endl;
				outfile << "\treturn true;" << endl;
				outfile << "};" << endl;
				outfile << endl;

				outfile << "function handle" << con->sref << "Change() {" << endl;
				outfile << "\t// IP handle" << con->sref << "Change --- INSERT" << endl;
				outfile << "};" << endl;
				outfile << endl;

			} else if (con->ixVBasetype == VecWznmVMControlBasetype::UPD) {
				outfile << "function handle" << con->sref << "Change() {" << endl;
				outfile << "\t// IP handle" << con->sref << "Change --- INSERT" << endl;
				outfile << "};" << endl;
				outfile << endl;
			};
		};
	};

	// --- generalized event handlers
	hasbutmdnup = false;
	hastxf = false;
	hastxft = false;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVScope == VecWznmVMControlScope::APP) {
			if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
				if ((con->sref.length() > 8) && ((con->sref.rfind("Collapse")+8) == con->sref.length())) appactions.insert("collapse");
				else if ((con->sref.length() > 6) && ((con->sref.rfind("Expand")+6) == con->sref.length())) appactions.insert("expand");
				else if ((con->sref.length() > 6) && ((con->sref.rfind("Toggle")+6) == con->sref.length())) appactions.insert("toggle");
			} else if ( (con->ixVBasetype == VecWznmVMControlBasetype::LSB) || (con->ixVBasetype == VecWznmVMControlBasetype::SLD) || (con->ixVBasetype == VecWznmVMControlBasetype::TBL)
						|| (con->ixVBasetype == VecWznmVMControlBasetype::TRS) || (con->ixVBasetype == VecWznmVMControlBasetype::TSB) || (con->ixVBasetype == VecWznmVMControlBasetype::UPD) ) {
				add(contypes, con->ixVBasetype);
			};

		} else if (con->ixVScope == VecWznmVMControlScope::SHR) {
			add(contypes, con->ixVBasetype);
			if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
				if (StrMod::srefInSrefs(con->srefsKOption, "mdnup")) hasbutmdnup = true;
				if (dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "action", 0, s)) actions.insert(s);
			} else if (con->ixVBasetype == VecWznmVMControlBasetype::TXF) {
				if (getConsize(con) == "t") hastxft = true; else hastxf = true;
			};
		};
	};

	hasdse = has(contypes, VecWznmVMControlBasetype::DSE);

	// -- generalized event handlers for app controls
	outfile << "// --- generalized event handlers for app controls" << endl;
	outfile << endl;

	if (appactions.find("collapse") != appactions.end()) {
		if (hasdse) {
			outfile << "function handleButCollapseClick(ditshort, basectlsref) {" << endl;
			outfile << "\tsetSi(srcdoc, \"StatApp" << hkroot << "\" + ditshort, basectlsref + \"Alt\", \"true\");" << endl;
		} else {
			outfile << "function handleButCollapseClick(basectlsref) {" << endl;
			outfile << "\tsetSi(srcdoc, \"StatApp" << hkroot << "\", basectlsref + \"Alt\", \"true\");" << endl;
		};

		outfile << "\trefresh();" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (appactions.find("expand") != appactions.end()) {
		if (hasdse) {
			outfile << "function handleButExpandClick(ditshort, basectlsref) {" << endl;
			outfile << "\tsetSi(srcdoc, \"StatApp" << hkroot << "\" + ditshort, basectlsref + \"Alt\", \"false\");" << endl;
		} else {
			outfile << "function handleButExpandClick(basectlsref) {" << endl;
			outfile << "\tsetSi(srcdoc, \"StatApp" << hkroot << "\", basectlsref + \"Alt\", \"false\");" << endl;
		};

		outfile << "\trefresh();" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (appactions.find("toggle") != appactions.end()) {
		if (hasdse) outfile << "function handleButToggleClick(ditshort, basectlsref) {" << endl;
		else outfile << "function handleButToggleClick(basectlsref) {" << endl;

		outfile << "\tvar alt;" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "\tif (retrieveSi(srcdoc, \"StatApp" << hkroot << "\" + ditshort, basectlsref + \"Alt\") == \"true\") alt = \"false\"; else alt = \"true\";" << endl;
			outfile << "\tsetSi(srcdoc, \"StatApp" << hkroot << "\" + ditshort, basectlsref + \"Alt\", alt);" << endl;
		} else {
			outfile << "\tif (retrieveSi(srcdoc, \"StatApp" << hkroot << "\", basectlsref + \"Alt\") == \"true\") alt = \"false\"; else alt = \"true\";" << endl;
			outfile << "\tsetSi(srcdoc, \"StatApp" << hkroot << "\", basectlsref + \"Alt\", alt);" << endl;
		};

		outfile << endl;

		outfile << "\trefresh();" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::LSB)) {
		outfile << "function setLsbPos(lstdoc, pos) {" << endl;
		outfile << "\tvar vpos = (16 + Math.round(pos * (90-2*16)));" << endl;
		outfile << endl;

		outfile << "\tlstdoc.getElementById(\"LsbJpupr\").setAttribute(\"height\", \"\" + (vpos-10));" << endl;
		outfile << "\tlstdoc.getElementById(\"LsbJpupl\").setAttribute(\"y2\", \"\" + vpos);" << endl;
		outfile << endl;

		outfile << "\tlstdoc.getElementById(\"LsbJpdownr\").setAttribute(\"y\", \"\" + vpos);" << endl;
		outfile << "\tlstdoc.getElementById(\"LsbJpdownr\").setAttribute(\"height\", \"\" + (90-vpos-10));" << endl;
		outfile << "\tlstdoc.getElementById(\"LsbJpdownl\").setAttribute(\"y1\", \"\" + vpos);" << endl;
		outfile << endl;

		outfile << "\tlstdoc.getElementById(\"Lsb\").setAttribute(\"transform\", \"translate(0 \" + vpos + \")\");" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "function handleLsbUpClick(lstdoc, ditshort, basectlsref, ncol, multsel) {" << endl;
			outfile << "\tchangeLstNumFirstdisp(lstdoc, ditshort, basectlsref, ncol, multsel, 0, -1);" << endl;
		} else {
			outfile << "function handleLsbUpClick(lstdoc, basectlsref, ncol, multsel) {" << endl;
			outfile << "\tchangeLstNumFirstdisp(lstdoc, basectlsref, multsel, ncol, 0, -1);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "function handleLsbJpupClick(lstdoc, ditshort, basectlsref, ncol, multsel) {" << endl;
			outfile << "\tchangeLstNumFirstdisp(lstdoc, ditshort, basectlsref, ncol, multsel, 0, -4);" << endl;
		} else {
			outfile << "function handleLsbJpupClick(lstdoc, basectlsref, ncol, multsel) {" << endl;
			outfile << "\tchangeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, -4);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "function handleLsbJpdownClick(lstdoc, ditshort, basectlsref, ncol, multsel) {" << endl;
			outfile << "\tchangeLstNumFirstdisp(lstdoc, ditshort, basectlsref, ncol, multsel, 0, 4);" << endl;
		} else {
			outfile << "function handleLsbJpdownClick(lstdoc, basectlsref, ncol, multsel) {" << endl;
			outfile << "\tchangeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 4);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "function handleLsbDownClick(lstdoc, ditshort, basectlsref, ncol, multsel) {" << endl;
			outfile << "\tchangeLstNumFirstdisp(lstdoc, ditshort, basectlsref, ncol, multsel, 0, 1);" << endl;
		} else {
			outfile << "function handleLsbDownClick(lstdoc, basectlsref, ncol, multsel) {" << endl;
			outfile << "\tchangeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 1);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleLsbMdn(lstdoc, basectlsref) {" << endl;
		
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->ixVBasetype == VecWznmVMControlBasetype::LST) {
				s = getCondoc(con);
				break;
			};
		};
		
		outfile << "\tlstdoc.getElementById(\"tdLsb\").onmousemove = " << s << ".getElementById(basectlsref).contentWindow.handleLsbMove;" << endl;
		outfile << "\tlstdoc.getElementById(\"tdLsb\").onmouseup = " << s << ".getElementById(basectlsref).contentWindow.handleLsbMup;" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleLsbMove(lstdoc, evt) {" << endl;
		outfile << "\tif ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {" << endl;
		outfile << "\t\tvar pos = (evt.clientY-16)/(90-2*16);" << endl;
		outfile << "\t\tsetLsbPos(lstdoc, pos);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleLsbMup(lstdoc, ditshort, basectlsref, ncol, multsel, evt) {" << endl;
		else outfile << "function handleLsbMup(lstdoc, basectlsref, ncol, multsel, evt) {" << endl;
		outfile << "\tlstdoc.getElementById(\"tdLsb\").removeAttribute(\"onmousemove\");" << endl;
		outfile << "\tlstdoc.getElementById(\"tdLsb\").removeAttribute(\"onmouseup\");" << endl;
		outfile << endl;

		if (hasdse) outfile << "\tvar cnt = getFeedSize(srcdoc, \"FeedF\" + ditshort + basectlsref);" << endl;
		else outfile << "\tvar cnt = getFeedSize(srcdoc, \"FeedF\" + basectlsref);" << endl;
		outfile << endl;

		outfile << "\tvar pos = (evt.clientY-16)/(90-2*16);" << endl;
		if (hasdse) outfile << "\tchangeLstNumFirstdisp(lstdoc, ditshort, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);" << endl;
		else outfile << "\tchangeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::TBL)) {
		outfile << "function handleTblSelect(jnum) {" << endl;
		outfile << "\tvar jnumFirstdisp, jnumLastdisp, jnumFirstload;" << endl;
		outfile << endl;

		outfile << "\tvar oldJnum = parseInt(retrieveSi(srcdoc, \"StgIacQry" << hkroot << "\", \"jnum\"));" << endl;
		outfile << "\tvar oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, \"StatAppQry" << hkroot << "\", \"jnumFirstdisp\"));" << endl;
		outfile << "\tvar oldJnumFirstload = parseInt(retrieveSi(srcdoc, \"StatShrQry" << hkroot << "\", \"jnumFirstload\"));" << endl;
		outfile << endl;

		outfile << "\tvar ndisp = parseInt(retrieveSi(srcdoc, \"StatAppQry" << hkroot << "\", \"ndisp\"));" << endl;
		outfile << "\tvar nload = parseInt(retrieveSi(srcdoc, \"StatShrQry" << hkroot << "\", \"nload\"));" << endl;
		outfile << "\tvar ntot = parseInt(retrieveSi(srcdoc, \"StatShrQry" << hkroot << "\", \"ntot\"));" << endl;
		outfile << endl;

		outfile << "\tif (ntot == 0) return;" << endl;
		outfile << endl;

		outfile << "\tif (jnum < 0) jnum = 0;" << endl;
		outfile << "\tif (jnum > ntot) jnum = ntot;" << endl;
		outfile << endl;

		outfile << "\tif (oldJnum != jnum) {" << endl;
		outfile << "\t\tsetSi(srcdoc, \"StgIacQry" << hkroot << "\", \"jnum\", jnum);" << endl;
		outfile << endl;

		outfile << "\t\tif (jnum != 0) {" << endl;
		outfile << "\t\t\tif (!((jnum >= oldJnumFirstdisp) && (jnum <= (oldJnumFirstdisp+ndisp-1)))) {" << endl;
		outfile << "\t\t\t\tjnumFirstdisp = jnum - Math.ceil(0.5*ndisp) + 1;" << endl;
		outfile << "\t\t\t\tif ((jnumFirstdisp+ndisp-1) > ntot) jnumFirstdisp = ntot-ndisp+1;" << endl;
		outfile << "\t\t\t\tif (jnumFirstdisp < 1) jnumFirstdisp = 1;" << endl;
		outfile << endl;

		outfile << "\t\t\t\tsetSi(srcdoc, \"StatAppQry" << hkroot << "\", \"jnumFirstdisp\", jnumFirstdisp);" << endl;
		outfile << endl;

		outfile << "\t\t\t\tjnumLastdisp = jnumFirstdisp + ndisp - 1;" << endl;
		outfile << "\t\t\t\tif (jnumLastdisp > ntot) jnumLastdisp = ntot;" << endl;
		outfile << endl;

		outfile << "\t\t\t\tif (!((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1)))) {" << endl;
		outfile << "\t\t\t\t\tjnumFirstload = jnum - Math.ceil(0.5*nload) + 1;" << endl;
		outfile << "\t\t\t\t\tif (jnumFirstload < 1) jnumFirstload = 1;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\tsetSi(srcdoc, \"StgIacQry" << hkroot << "\", \"jnumFirstload\", jnumFirstload);" << endl;
		outfile << "\t\t\t\t};" << endl;
		outfile << "\t\t\t};" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;

		outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"StgIacQry" << hkroot << "\");" << endl;
		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function changeTblJnumFirstdisp(jnumFirstdisp, dJnumFirstdisp, dpgJnumFirstdisp) {" << endl;
		outfile << "\tvar jnumLastdisp, jnumFirstload;" << endl;
		outfile << endl;

		outfile << "\tvar oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, \"StatAppQry" << hkroot << "\", \"jnumFirstdisp\"));" << endl;
		outfile << "\tvar oldJnumFirstload = parseInt(retrieveSi(srcdoc, \"StatShrQry" << hkroot << "\", \"jnumFirstload\"));" << endl;
		outfile << endl;

		outfile << "\tvar ndisp = parseInt(retrieveSi(srcdoc, \"StatAppQry" << hkroot << "\", \"ndisp\"));" << endl;
		outfile << "\tvar nload = parseInt(retrieveSi(srcdoc, \"StatShrQry" << hkroot << "\", \"nload\"));" << endl;
		outfile << "\tvar ntot = parseInt(retrieveSi(srcdoc, \"StatShrQry" << hkroot << "\", \"ntot\"));" << endl;
		outfile << endl;

		outfile << "\tif (ntot == 0) return;" << endl;
		outfile << endl;

		outfile << "\tif (dpgJnumFirstdisp < 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp + 1;" << endl;
		outfile << "\telse if (dpgJnumFirstdisp > 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp - 1;" << endl;
		outfile << "\telse if (dJnumFirstdisp != 0) jnumFirstdisp = oldJnumFirstdisp + dJnumFirstdisp;" << endl;
		outfile << endl;

		outfile << "\tif (jnumFirstdisp > (ntot-ndisp+1)) jnumFirstdisp = ntot-ndisp+1;" << endl;
		outfile << "\tif (jnumFirstdisp < 1) jnumFirstdisp = 1;" << endl;
		outfile << endl;

		outfile << "\tif (oldJnumFirstdisp != jnumFirstdisp) {" << endl;
		outfile << "\t\tsetSi(srcdoc, \"StatAppQry" << hkroot << "\", \"jnumFirstdisp\", jnumFirstdisp);" << endl;
		outfile << endl;

		outfile << "\t\tjnumLastdisp = jnumFirstdisp + ndisp - 1;" << endl;
		outfile << "\t\tif (jnumLastdisp > ntot) jnumLastdisp = ntot;" << endl;
		outfile << endl;

		outfile << "\t\tif ((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1))) {" << endl;

		if (pnllist) outfile << "\t\t\trefreshB(false);" << endl;
		else outfile << "\t\t\trefreshBD((retrieveSi(srcdoc, \"StatApp" << hkroot << "\", \"srefIx" << Prjshort << "VExpstate\") == \"regd\"), false);" << endl;

		outfile << endl;

		outfile << "\t\t} else {" << endl;
		outfile << "\t\t\tjnumFirstload = jnumFirstdisp - Math.ceil(0.5*(nload-ndisp));" << endl;
		outfile << "\t\t\tif (jnumFirstload < 1) jnumFirstload = 1;" << endl;
		outfile << endl;

		outfile << "\t\t\tsetSi(srcdoc, \"StgIacQry" << hkroot << "\", \"jnumFirstload\", jnumFirstload);" << endl;
		outfile << endl;

		outfile << "\t\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"StgIacQry" << hkroot << "\");" << endl;
		outfile << "\t\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "\t\t};" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTblCpreviousClick() {" << endl;
		outfile << "\tvar oldFirstcol = parseInt(retrieveSi(srcdoc, \"StatAppQry" << hkroot << "\", \"firstcol\"));" << endl;
		outfile << endl;

		outfile << "\tsetSi(srcdoc, \"StatAppQry" << hkroot << "\", \"firstcol\", \"\" + (oldFirstcol-1));" << endl;
		outfile << endl;

		if (pnllist) outfile << "\trefreshB(true);" << endl;
		else outfile << "\trefreshBD((retrieveSi(srcdoc, \"StatApp" << hkroot << "\", \"srefIx" << Prjshort << "VExpstate\") == \"regd\"), true);" << endl;

		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTblCnextClick() {" << endl;
		outfile << "\tvar oldFirstcol = parseInt(retrieveSi(srcdoc, \"StatAppQry" << hkroot << "\", \"firstcol\"));" << endl;
		outfile << endl;

		outfile << "\tsetSi(srcdoc, \"StatAppQry" << hkroot << "\", \"firstcol\", \"\" + (oldFirstcol+1));" << endl;
		outfile << endl;

		if (pnllist) outfile << "\trefreshB(true);" << endl;
		else outfile << "\trefreshBD((retrieveSi(srcdoc, \"StatApp" << hkroot << "\", \"srefIx" << Prjshort << "VExpstate\") == \"regd\"), true);" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::TRS)) {
		outfile << "function handleTrsFirstClick() {" << endl;
		outfile << "\thandleTblSelect(1);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTrsPreviousClick() {" << endl;
		outfile << "\tvar jnum = parseInt(retrieveSi(srcdoc, \"StgIacQry" << hkroot << "\", \"jnum\"));" << endl;
		outfile << endl;

		outfile << "\thandleTblSelect(jnum-1);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTrsNextClick() {" << endl;
		outfile << "\tvar jnum = parseInt(retrieveSi(srcdoc, \"StgIacQry" << hkroot << "\", \"jnum\"));" << endl;
		outfile << endl;

		outfile << "\thandleTblSelect(jnum+1);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTrsLastClick() {" << endl;
		outfile << "\tvar ntot = parseInt(retrieveSi(srcdoc, \"StatShrQry" << hkroot << "\", \"ntot\"));" << endl;
		outfile << endl;

		outfile << "\thandleTblSelect(ntot);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTrsGotoClick() {" << endl;
		outfile << "\tftrdoc.getElementById(\"TrsGoto\").style.display = \"none\";" << endl;
		outfile << endl;

		outfile << "\tvar elem = ftrdoc.getElementById(\"TrsRow\");" << endl;
		outfile << "\telem.style.display = \"inline\";" << endl;
		outfile << "\telem.focus();" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTrsRowMou() {" << endl;
		outfile << "\tvar elem = ftrdoc.getElementById(\"TrsRow\");" << endl;
		outfile << "\telem.value = \"\";" << endl;
		outfile << "\telem.style.display = \"none\";" << endl;
		outfile << endl;

		outfile << "\tftrdoc.getElementById(\"TrsGoto\").style.display = \"inline\";" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTrsRowKey(evt) {" << endl;
		outfile << "\tif (evt.keyCode == 13) {" << endl;
		outfile << "\t\thandleTblSelect(parseInt(ftrdoc.getElementById(\"TrsRow\").value));" << endl;
		outfile << endl;

		outfile << "\t\thandleTrsRowMou();" << endl;
		outfile << "\t\treturn false;" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn true;" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::TSB)) {
		outfile << "function setTsbPos(pos) {" << endl;
		outfile << "\tvar ndisp = parseInt(retrieveSi(srcdoc, \"StatAppQry" << hkroot << "\", \"ndisp\"));" << endl;
		outfile << "\tvar vpos = (18 + Math.round(pos * (18*(ndisp-2))));" << endl;
		outfile << endl;

		outfile << "\ttbldoc.getElementById(\"TsbJpupr\").setAttribute(\"height\", \"\" + (vpos-10));" << endl;
		outfile << "\ttbldoc.getElementById(\"TsbJpupl\").setAttribute(\"y2\", \"\" + vpos);" << endl;
		outfile << endl;

		outfile << "\ttbldoc.getElementById(\"TsbJpdownr\").setAttribute(\"y\", \"\" + vpos);" << endl;
		outfile << "\ttbldoc.getElementById(\"TsbJpdownr\").setAttribute(\"height\", \"\" + (18*ndisp-vpos-11));" << endl;
		outfile << "\ttbldoc.getElementById(\"TsbJpdownl\").setAttribute(\"y1\", \"\" + vpos);" << endl;
		outfile << endl;

		outfile << "\ttbldoc.getElementById(\"Tsb\").setAttribute(\"transform\", \"translate(0 \" + vpos + \")\");" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTsbUpClick() {" << endl;
		outfile << "\tchangeTblJnumFirstdisp(0, -1, 0);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTsbJpupClick() {" << endl;
		outfile << "\tchangeTblJnumFirstdisp(0, 0, -1);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTsbJpdownClick() {" << endl;
		outfile << "\tchangeTblJnumFirstdisp(0, 0, 1);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTsbDownClick() {" << endl;
		outfile << "\tchangeTblJnumFirstdisp(0, 1, 0);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTsbMdn() {" << endl;
		outfile << "\ttbldoc.getElementById(\"tdTsb\").onmousemove = handleTsbMove;" << endl;
		outfile << "\ttbldoc.getElementById(\"tdTsb\").onmouseup = handleTsbMup;" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTsbMove(evt) {" << endl;
		outfile << "\tvar ndisp = parseInt(retrieveSi(srcdoc, \"StatAppQry" << hkroot << "\", \"ndisp\"));" << endl;
		outfile << endl;

		outfile << "\tif ((evt.clientY >= (18+20)) && (evt.clientY <= (18*(ndisp-1)+20))) {" << endl;
		outfile << "\t\tpos = ((evt.clientY-20) - 18) / (18*(ndisp-2));" << endl;
		outfile << "\t\tsetTsbPos(pos);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "function handleTsbMup(evt) {" << endl;
		outfile << "\ttbldoc.getElementById(\"tdTsb\").removeAttribute(\"onmousemove\");" << endl;
		outfile << "\ttbldoc.getElementById(\"tdTsb\").removeAttribute(\"onmouseup\");" << endl;
		outfile << endl;

		outfile << "\tvar ntot = parseInt(retrieveSi(srcdoc, \"StatShrQry" << hkroot << "\", \"ntot\"));" << endl;
		outfile << "\tvar ndisp = parseInt(retrieveSi(srcdoc, \"StatAppQry" << hkroot << "\", \"ndisp\"));" << endl;
		outfile << endl;

		outfile << "\tvar pos = ((evt.clientY-20) - 18) / (18*(ndisp-2));" << endl;
		outfile << endl;

		outfile << "\tchangeTblJnumFirstdisp(Math.round(pos*(ntot-ndisp))+1, 0, 0);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	// -- generalized event handlers for shared controls
	outfile << "// --- generalized event handlers for shared controls" << endl;
	outfile << endl;

	if (has(contypes, VecWznmVMControlBasetype::BUT)) {
		if (hasdse) {
			outfile << "function handleButClick(ditshort, ctlsref) {" << endl;
			outfile << "\tvar str = serializeDpchAppDoDlg(srcdoc, \"DpchApp" << hkroot << "Do\", scrJref, ditshort, ctlsref + \"Click\");" << endl;
		} else {
			outfile << "function handleButClick(ctlsref) {" << endl;
			outfile << "\tvar str = serializeDpchAppDo(srcdoc, \"DpchApp" << hkroot << "Do\", scrJref, ctlsref + \"Click\");" << endl;
		};

		outfile << "\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasbutmdnup) {
			if (hasdse) {
				outfile << "function handleButMdn(ditshort, ctlsref) {" << endl;
				outfile << "\tvar str = serializeDpchAppDoDlg(srcdoc, \"DpchApp" << hkroot << "Do\", scrJref, ditshort, ctlsref + \"Mdn\");" << endl;
			} else {
				outfile << "function handleButMdn(ctlsref) {" << endl;
				outfile << "\tvar str = serializeDpchAppDo(srcdoc, \"DpchApp" << hkroot << "Do\", scrJref, ctlsref + \"Mdn\");" << endl;
			};

			outfile << "\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
			outfile << "};" << endl;
			outfile << endl;

			if (hasdse) {
				outfile << "function handleButMup(ditshort, ctlsref) {" << endl;
				outfile << "\tvar str = serializeDpchAppDoDlg(srcdoc, \"DpchApp" << hkroot << "Do\", scrJref, ditshort, ctlsref + \"Mup\");" << endl;
			} else {
				outfile << "function handleButMup(ctlsref) {" << endl;
				outfile << "\tvar str = serializeDpchAppDo(srcdoc, \"DpchApp" << hkroot << "Do\", scrJref, ctlsref + \"Mup\");" << endl;
			};

			outfile << "\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};

		// crdopen (non-dlg)
		if (actions.find("crdopen") != actions.end()) {
			outfile << "function handleButCrdopenClick(ctlsref) {" << endl;
			outfile << "\tvar str = serializeDpchAppDo(srcdoc, \"DpchApp" << hkroot << "Do\", scrJref, ctlsref + \"Click\");" << endl;
			outfile << "\tsendReq(str, doc, handleDpchAppDoCrdopenReply);" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};

		// dlgopen (non-dlg)
		if (actions.find("dlgopen") != actions.end()) {
			outfile << "function handleButDlgopenClick(ctlsref) {" << endl;
			outfile << "\tvar str = serializeDpchAppDo(srcdoc, \"DpchApp" << hkroot << "Do\", scrJref, ctlsref + \"Click\");" << endl;
			outfile << "\tsendReq(str, doc, handleDpchAppDoDlgopenReply);" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
	};

	if (has(contypes, VecWznmVMControlBasetype::CHK)) {
		if (hasdse) outfile << "function handleChkChange(_doc, ditshort, ctlsref) {" << endl;
		else outfile << "function handleChkChange(_doc, ctlsref) {" << endl;

		outfile << "\tvar elem = _doc.getElementById(ctlsref);" << endl;
		outfile << "\tvar checked;" << endl;
		outfile << endl;

		outfile << "\telem.setAttribute(\"class\", \"chkmod\");" << endl;
		outfile << endl;

		outfile << "\tif (elem.checked == true) checked = \"true\"; else checked = \"false\";" << endl;

		if (hasdse) {
			outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, checked);" << endl;
			outfile << endl;
			outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		} else {
			outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, checked);" << endl;
			outfile << endl;
			outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		};

		outfile << "\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (hasdse) {
		outfile << "function handleDseSelect(numFDse) {" << endl;
		outfile << "\tvar oldNumFDse = parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"numFDse\"));" << endl;
		outfile << endl;

		outfile << "\tif (oldNumFDse != numFDse) {" << endl;
		outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", \"numFDse\", \"\" + numFDse);" << endl;
		outfile << endl;

		outfile << "\t\tsetSi(srcdoc, \"StatApp" << hkroot << "\", \"initdone\", \"false\");" << endl;
		outfile << endl;

		outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::LST)) {
		if (hasdse) {
			outfile << "function handleLstLoad(lstdoc, ditshort, ctlsref, ncol, multsel) {" << endl;
			outfile << "\tif (multsel) {" << endl;
			outfile << "\t\trefreshLst(lstdoc, srcdoc, ncol, " << large << ", multsel, \"FeedF\" + ditshort + ctlsref, parseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << "\" + ditshort, ctlsref + \"NumFirstdisp\"))," << endl;
			outfile << "\t\t\t\t\tparseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numsF\" + ctlsref)));" << endl;
			outfile << "\t} else {" << endl;
			outfile << "\t\trefreshLst(lstdoc, srcdoc, ncol, " << large << ", multsel, \"FeedF\" + ditshort + ctlsref, parseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << "\" + ditshort, ctlsref + \"NumFirstdisp\"))," << endl;
			outfile << "\t\t\t\t\t[parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numF\" + ctlsref))]);" << endl;
			outfile << "\t};" << endl;
		} else {
			outfile << "function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {" << endl;
			outfile << "\tif (multsel) {" << endl;
			outfile << "\t\trefreshLst(lstdoc, srcdoc, ncol, " << large << ", multsel, \"FeedF\" + ctlsref, parseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << "\", ctlsref + \"NumFirstdisp\"))," << endl;
			outfile << "\t\t\t\t\tparseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"numsF\" + ctlsref)));" << endl;
			outfile << "\t} else {" << endl;
			outfile << "\t\trefreshLst(lstdoc, srcdoc, ncol, " << large << ", multsel, \"FeedF\" + ctlsref, parseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << "\", ctlsref + \"NumFirstdisp\"))," << endl;
			outfile << "\t\t\t\t\t[parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"numF\" + ctlsref))]);" << endl;
			outfile << "\t};" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleLstSelect(ditshort, ctlsref, multsel, num) {" << endl;
		else outfile << "function handleLstSelect(ctlsref, multsel, num) {" << endl;

		outfile << "\tvar found, oldNumFLst, numsFLst, oldNumsFLst;" << endl;
		outfile << endl;

		outfile << "\tif (multsel) {" << endl;
		if (hasdse) outfile << "\t\toldNumsFLst = parseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numsF\" + ctlsref));" << endl;
		else outfile << "\t\toldNumsFLst = parseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"numsF\" + ctlsref));" << endl;
		outfile << endl;

		outfile << "\t\tfound = false;" << endl;
		outfile << endl;

		outfile << "\t\tfor (var i = 0; i < oldNumsFLst.length; i++) {" << endl;
		outfile << "\t\t\tif (oldNumsFLst[i] == num) {" << endl;
		outfile << "\t\t\t\tnumsFLst = new Uint32Array(oldNumsFLst.length-1);" << endl;
		outfile << endl;

		outfile << "\t\t\t\tfor (var j = 0; j < oldNumsFLst.length; j++)" << endl;
		outfile << "\t\t\t\t\tif (j < i) numsFLst[j] = oldNumsFLst[j];" << endl;
		outfile << "\t\t\t\t\telse if (j > i) numsFLst[j-1] = oldNumsFLst[j];" << endl;
		outfile << endl;

		outfile << "\t\t\t\tfound = true;" << endl;
		outfile << "\t\t\t\tbreak;" << endl;
		outfile << "\t\t\t};" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;

		outfile << "\t\tif (!found) {" << endl;
		outfile << "\t\t\tnumsFLst = new Uint32Array(oldNumsFLst.length+1);" << endl;
		outfile << endl;

		outfile << "\t\t\tfor (var i = 0; i < oldNumsFLst.length; i++) numsFLst[i] = oldNumsFLst[i];" << endl;
		outfile << "\t\t\tnumsFLst[oldNumsFLst.length] = num;" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numsF\" + ctlsref, encodeUintvec(numsFLst));" << endl;
		else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", \"numsF\" + ctlsref, encodeUintvec(numsFLst));" << endl;
		outfile << endl;

		outfile << "\t} else {" << endl;
		if (hasdse) outfile << "\t\toldNumFLst = parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numF\" + ctlsref));" << endl;
		else outfile << "\t\toldNumFLst = parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"numF\" + ctlsref));" << endl;
		outfile << "\t\tif (num == oldNumFLst) num = 0;" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numF\" + ctlsref, num);" << endl;
		else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", \"numF\" + ctlsref, num);" << endl;

		outfile << "\t};" << endl;
		outfile << endl;

		if (hasdse) outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "function changeLstNumFirstdisp(lstdoc, ditshort, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {" << endl;
			outfile << "\tvar oldNumFirstdisp = parseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << "\" + ditshort, ctlsref + \"NumFirstdisp\"));" << endl;
		} else {
			outfile << "function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {" << endl;
			outfile << "\tvar oldNumFirstdisp = parseInt(retrieveSi(srcdoc, \"StatApp" << hkroot << "\", ctlsref + \"NumFirstdisp\"));" << endl;
		};
		outfile << "\tif (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;" << endl;
		outfile << endl;

		if (hasdse) outfile << "\tvar cnt = getFeedSize(srcdoc, \"FeedF\" + ditshort + ctlsref);" << endl;
		else outfile << "\tvar cnt = getFeedSize(srcdoc, \"FeedF\" + ctlsref);" << endl;
		outfile << endl;

		outfile << "\tif (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;" << endl;
		outfile << "\tif (numFirstdisp < 1) numFirstdisp = 1;" << endl;
		outfile << endl;

		outfile << "\tif (numFirstdisp != oldNumFirstdisp) {" << endl;
		if (hasdse) {
			outfile << "\t\tsetSi(srcdoc, \"StatApp" << hkroot << "\" + ditshort, ctlsref + \"NumFirstdisp\", \"\" + numFirstdisp);" << endl;
			outfile << endl;

			outfile << "\t\tif (multsel) refreshLst(lstdoc, srcdoc, ncol, " << large << ", multsel, \"FeedF\" + ditshort + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numsF\" + ctlsref)));" << endl;
			outfile << "\t\telse refreshLst(lstdoc, srcdoc, ncol, " << large << ", multsel, \"FeedF\" + ditshort + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numF\" + ctlsref))]);" << endl;

		} else {
			outfile << "\t\tsetSi(srcdoc, \"StatApp" << hkroot << "\", ctlsref + \"NumFirstdisp\", \"\" + numFirstdisp);" << endl;
			outfile << endl;

			outfile << "\t\tif (multsel) refreshLst(lstdoc, srcdoc, ncol, " << large << ", multsel, \"FeedF\" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"numsF\" + ctlsref)));" << endl;
			outfile << "\t\telse refreshLst(lstdoc, srcdoc, ncol, " << large << ", multsel, \"FeedF\" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"numF\" + ctlsref))]);" << endl;
		};
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::PUP)) {
		if (hasdse) outfile << "function handlePupChange(_doc, ditshort, ctlsref, size) {" << endl;
		else outfile << "function handlePupChange(_doc, ctlsref, size) {" << endl;
		outfile << "\tvar elem = _doc.getElementById(ctlsref);" << endl;
		outfile << endl;

		outfile << "\telem.setAttribute(\"class\", \"pup\" + size + \"mod\");" << endl;
		if (hasdse) outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numF\" + ctlsref, elem.value);" << endl;
		else outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\", \"numF\" + ctlsref, elem.value);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::RBU)) {
		if (hasdse) outfile << "function handleRbuSelect(_doc, ditshort, ctlsref, num) {" << endl;
		else outfile << "function handleRbuSelect(_doc, ctlsref, num) {" << endl;

		if (hasdse) outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, \"numF\" + ctlsref, \"\" + num);" << endl;
		else outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\", \"numF\" + ctlsref, \"\" + num);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::SLD)) {
		if (hasdse) outfile << "function handleSldJpleftMov(_doc, ditshort, ctlsref) {" << endl;
		else outfile << "function handleSldJpleftMov(_doc, ctlsref) {" << endl;
		outfile << "\tif (_doc.getElementById(\"td\" + ctlsref).onmousemove == null) {" << endl;
		outfile << "\t\t_doc.getElementById(ctlsref + \"Jpleftl\").setAttribute(\"class\", \"sldlhlt\");" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldJpleftMou(_doc, ditshort, ctlsref) {" << endl;
		else outfile << "function handleSldJpleftMou(_doc, ctlsref) {" << endl;
		outfile << "\t_doc.getElementById(ctlsref + \"Jpleftl\").setAttribute(\"class\", \"sldl\");" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldJpleftClick(_doc, ditshort, ctlsref, shr, log, _rast, evt) {" << endl;
		else outfile << "function handleSldJpleftClick(_doc, ctlsref, shr, log, _rast, evt) {" << endl;
		outfile << "\tvar pos, oldVal, val;" << endl;
		outfile << endl;

		outfile << "\tvar min, max, rast;" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "\tif (shr) oldVal = parseFloat(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref));" << endl;
			outfile << "\telse oldVal = parseFloat(_doc.getElementById(ctlsref + \"Val\").value);" << endl;
			outfile << "\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Max\"));" << endl;
		} else {
			outfile << "\tif (shr) oldVal = parseFloat(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref));" << endl;
			outfile << "\telse oldVal = parseFloat(_doc.getElementById(ctlsref + \"Val\").value);" << endl;
			outfile << "\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Max\"));" << endl;
		};
		outfile << endl;

		if (hasdse) outfile << "\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Rast\"));" << endl;
		else outfile << "\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Rast\"));" << endl;
		outfile << endl;

		outfile << "\tif (_rast) {" << endl;
		outfile << "\t\tif (log) val = oldVal / rast;" << endl;
		outfile << "\t\telse val = oldVal - rast;" << endl;
		outfile << endl;

		outfile << "\t\tif (val < min) val = min;" << endl;
		outfile << "\t\tif (val > max) val = max;" << endl;
		outfile << endl;

		outfile << "\t} else {" << endl;
		outfile << "\t\tpos = getSldPosFromEvtx(" << large << ", evt.clientX);" << endl;
		outfile << "\t\tval = getSldValFromPos(min, max, rast, pos);" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\tpos = getSldPosFromVal(min, max, val);" << endl;
		outfile << endl;

		outfile << "\tsetSldPos(_doc, ctlsref, " << large << ", pos);" << endl;
		outfile << "\tsetSldVal(_doc, ctlsref, val, true, true);" << endl;
		outfile << endl;

		outfile << "\tif (shr) {" << endl;
		if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
		else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << endl;

		outfile << "\t} else {" << endl;
		if (hasdse) outfile << "\t\twindow[\"handle\" + ditshort + ctlsref + \"Change\"](val);" << endl;
		else outfile << "\t\twindow[\"handle\" + ctlsref + \"Change\"](val);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldJprightMov(_doc, ditshort, ctlsref) {" << endl;
		else outfile << "function handleSldJprightMov(_doc, ctlsref) {" << endl;
		outfile << "\tif (_doc.getElementById(\"td\" + ctlsref).onmousemove == null) {" << endl;
		outfile << "\t\t_doc.getElementById(ctlsref + \"Jprightl\").setAttribute(\"class\", \"sldlhlt\");" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldJprightMou(_doc, ditshort, ctlsref) {" << endl;
		else outfile << "function handleSldJprightMou(_doc, ctlsref) {" << endl;
		outfile << "\t_doc.getElementById(ctlsref + \"Jprightl\").setAttribute(\"class\", \"sldl\");" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldJprightClick(_doc, ditshort, ctlsref, shr, log, _rast, evt) {" << endl;
		else outfile << "function handleSldJprightClick(_doc, ctlsref, shr, log, _rast, evt) {" << endl;
		outfile << "\tvar pos, oldVal, val;" << endl;
		outfile << endl;

		outfile << "\tvar min, max, rast;" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "\tif (shr) oldVal = parseFloat(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref));" << endl;
			outfile << "\telse oldVal = parseFloat(_doc.getElementById(ctlsref + \"Val\").value);" << endl;
			outfile << "\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Max\"));" << endl;
		} else {
			outfile << "\tif (shr) oldVal = parseFloat(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref));" << endl;
			outfile << "\telse oldVal = parseFloat(_doc.getElementById(ctlsref + \"Val\").value);" << endl;
			outfile << "\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Max\"));" << endl;
		};
		outfile << endl;

		if (hasdse) outfile << "\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Rast\"));" << endl;
		else outfile << "\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Rast\"));" << endl;
		outfile << endl;

		outfile << "\tif (_rast) {" << endl;
		outfile << "\t\tif (log) val = oldVal * rast;" << endl;
		outfile << "\t\telse val = oldVal + rast;" << endl;
		outfile << endl;

		outfile << "\t\tif (val < min) val = min;" << endl;
		outfile << "\t\tif (val > max) val = max;" << endl;
		outfile << endl;

		outfile << "\t} else {" << endl;
		outfile << "\t\tpos = getSldPosFromEvtx(" << large << ", evt.clientX);" << endl;
		outfile << "\t\tval = getSldValFromPos(min, max, rast, pos);" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\tpos = getSldPosFromVal(min, max, val);" << endl;
		outfile << endl;

		outfile << "\tsetSldPos(_doc, ctlsref, " << large << ", pos);" << endl;
		outfile << "\tsetSldVal(_doc, ctlsref, val, true, true);" << endl;
		outfile << endl;

		outfile << "\tif (shr) {" << endl;
		if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
		else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << endl;

		outfile << "\t} else {" << endl;
		if (hasdse) outfile << "\t\twindow[\"handle\" + ditshort + ctlsref + \"Change\"](val);" << endl;
		else outfile << "\t\twindow[\"handle\" + ctlsref + \"Change\"](val);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldMov(_doc, ditshort, ctlsref) {" << endl;
		else outfile << "function handleSldMov(_doc, ctlsref) {" << endl;
		outfile << "\t_doc.getElementById(ctlsref + \"Bar\").setAttribute(\"class\", \"sldlhlt\");" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldMou(_doc, ditshort, ctlsref) {" << endl;
		else outfile << "function handleSldMou(_doc, ctlsref) {" << endl;
		outfile << "\tif (_doc.getElementById(\"td\" + ctlsref).onmousemove == null) {" << endl;
		outfile << "\t\t_doc.getElementById(ctlsref + \"Bar\").setAttribute(\"class\", \"sldl\");" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldMdn(_doc, ditshort, ctlsref) {" << endl;
		else outfile << "function handleSldMdn(_doc, ctlsref) {" << endl;
		outfile << "\t_doc.getElementById(\"td\" + ctlsref).setAttribute(\"onmousemove\", \"handle\" + ctlsref + \"Move(event)\");" << endl;
		outfile << "\t_doc.getElementById(\"td\" + ctlsref).setAttribute(\"onmouseup\", \"handle\" + ctlsref + \"Mup(event)\");" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldMove(_doc, ditshort, ctlsref, shr, log, _rast, evt) {" << endl;
		else outfile << "function handleSldMove(_doc, ctlsref, shr, log, _rast, evt) {" << endl;
		outfile << "\tvar pos, val;" << endl;
		outfile << endl;

		outfile << "\tvar min, max, rast;" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Max\"));" << endl;
		} else {
			outfile << "\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Max\"));" << endl;
		};
		outfile << endl;

		if (hasdse) outfile << "\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Rast\"));" << endl;
		else outfile << "\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Rast\"));" << endl;
		outfile << "\telse rast = 0.0;" << endl;
		outfile << endl;

		outfile << "\tpos = getSldPosFromEvtx(" << large << ", evt.clientX);" << endl;
		outfile << endl;

		outfile << "\tif (log) val = getSldLogvalFromPos(min, max, rast, pos);" << endl;
		outfile << "\telse val = getSldValFromPos(min, max, rast, pos);" << endl;
		outfile << endl;

		outfile << "\tsetSldPos(_doc, ctlsref, " << large << ", pos);" << endl;
		outfile << "\tsetSldVal(_doc, ctlsref, val, true, true);" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "\tif (shr) setCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
			outfile << "\telse window[\"handle\" + ditshort + ctlsref + \"Change\"](val);" << endl;
		} else {
			outfile << "\tif (shr) setCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;
			outfile << "\telse window[\"handle\" + ctlsref + \"Change\"](val);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldMup(_doc, ditshort, ctlsref, shr) {" << endl;
		else outfile << "function handleSldMup(_doc, ctlsref, shr) {" << endl;
		outfile << "\t_doc.getElementById(\"td\" + ctlsref).onmousemove = null;" << endl;
		outfile << "\t_doc.getElementById(\"td\" + ctlsref).onmouseup = null;" << endl;
		outfile << endl;

		outfile << "\tif (shr) {" << endl;
		if (hasdse) outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldValKey(_doc, ditshort, ctlsref, shr, log, _rast, evt) {" << endl;
		else outfile << "function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {" << endl;
		outfile << "\tvar elem = _doc.getElementById(ctlsref + \"Val\");" << endl;
		outfile << endl;

		outfile << "\tvar pos, val;" << endl;
		outfile << endl;

		outfile << "\tvar min, max, rast;" << endl;
		outfile << endl;

		outfile << "\telem.setAttribute(\"class\", \"txfxsmod\");" << endl;
		outfile << endl;

		outfile << "\tif (evt.keyCode == 13) {" << endl;
		if (hasdse) {
			outfile << "\t\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Min\"));" << endl;
			outfile << "\t\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Max\"));" << endl;
		} else {
			outfile << "\t\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Min\"));" << endl;
			outfile << "\t\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Max\"));" << endl;
		};
		outfile << endl;

		if (hasdse) outfile << "\t\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Rast\"));" << endl;
		else outfile << "\t\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Rast\"));" << endl;
		outfile << "\t\telse rast = 0.0;" << endl;
		outfile << endl;

		outfile << "\t\tval = parseFloat(elem.value);" << endl;
		outfile << "\t\tif (isNaN(val)) val = 0.0;" << endl;
		outfile << endl;

		outfile << "\t\tif (log) {" << endl;
		outfile << "\t\t\tval = alignSldLogval(min, max, rast, val);" << endl;
		outfile << "\t\t\tpos = getSldPosFromLogval(min, max, val);" << endl;
		outfile << "\t\t} else {" << endl;
		outfile << "\t\t\tval = alignSldVal(min, max, rast, val);" << endl;
		outfile << "\t\t\tpos = getSldPosFromVal(min, max, val);" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;

		outfile << "\t\tsetSldPos(_doc, ctlsref, " << large << ", pos);" << endl;
		outfile << "\t\tsetSldVal(_doc, ctlsref, val, true, true);" << endl;
		outfile << endl;

		outfile << "\t\tif (shr) {" << endl;
		if (hasdse) outfile << "\t\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
		else outfile << "\t\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\t\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << endl;

		outfile << "\t\t} else {" << endl;
		if (hasdse) outfile << "\t\t\twindow[\"handle\" + ditshort + ctlsref + \"Change\"](val);" << endl;
		else outfile << "\t\t\twindow[\"handle\" + ctlsref + \"Change\"](val);" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;

		outfile << "\t\treturn false;" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn true;" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleSldValChange(_doc, ditshort, ctlsref, shr, log, _rast) {" << endl;
		else outfile << "function handleSldValChange(_doc, ctlsref, shr, log, _rast) {" << endl;
		outfile << "\tvar elem = _doc.getElementById(ctlsref + \"Val\");" << endl;
		outfile << endl;

		outfile << "\tvar pos, val;" << endl;
		outfile << endl;

		outfile << "\tvar min, max, rast;" << endl;
		outfile << endl;

		outfile << "\telem.setAttribute(\"class\", \"txfxsmod\");" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Max\"));" << endl;
		} else {
			outfile << "\tmin = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Max\"));" << endl;
		};
		outfile << endl;

		if (hasdse) outfile << "\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Rast\"));" << endl;
		else outfile << "\tif (_rast) rast = parseFloat(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Rast\"));" << endl;
		outfile << "\telse rast = 0.0;" << endl;
		outfile << endl;

		outfile << "\tval = parseFloat(elem.value);" << endl;
		outfile << "\tif (isNaN(val)) val = 0.0;" << endl;
		outfile << endl;

		outfile << "\tif (log) {" << endl;
		outfile << "\t\tval = alignSldLogval(min, max, rast, val);" << endl;
		outfile << "\t\tpos = getSldPosFromLogval(min, max, val);" << endl;
		outfile << "\t} else {" << endl;
		outfile << "\t\tval = alignSldVal(min, max, rast, val);" << endl;
		outfile << "\t\tpos = getSldPosFromVal(min, max, val);" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\tsetSldPos(_doc, ctlsref, " << large << ", pos);" << endl;
		outfile << "\tsetSldVal(_doc, ctlsref, val, true, true);" << endl;
		outfile << endl;

		outfile << "\tif (shr) {" << endl;
		if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
		else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << endl;

		outfile << "\t} else {" << endl;
		if (hasdse) outfile << "\twindow[\"handle\" + ditshort + ctlsref + \"Change\"](val);" << endl;
		else outfile << "\twindow[\"handle\" + ctlsref + \"Change\"](val);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::TOS)) {
		outfile << "function handleTosSelect(numFTos) {" << endl;
		outfile << "\tvar oldNumFTos = parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", \"numFTos\"));" << endl;
		outfile << endl;

		outfile << "\tif (oldNumFTos != numFTos) {" << endl;
		outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", \"numFTos\", \"\" + numFTos);" << endl;
		outfile << endl;

		outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (has(contypes, VecWznmVMControlBasetype::TXF)) {
		if (hastxf) {
			if (hasdse) outfile << "function handleTxfKey(_doc, ditshort, ctlsref, size, evt) {" << endl;
			else outfile << "function handleTxfKey(_doc, ctlsref, size, evt) {" << endl;
			outfile << "\tvar elem = _doc.getElementById(ctlsref);" << endl;
			outfile << endl;

			outfile << "\telem.setAttribute(\"class\", \"txf\" + size + \"mod\");" << endl;
			outfile << endl;

			outfile << "\tif (evt.keyCode == 13) {" << endl;
			if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, elem.value);" << endl;
			else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, elem.value);" << endl;
			outfile << endl;

			if (hasdse) outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
			else outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
			outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
			outfile << endl;

			outfile << "\t\treturn false;" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

			outfile << "\treturn true;" << endl;
			outfile << "};" << endl;
			outfile << endl;

			if (hasdse) outfile << "function handleTxfChange(_doc, ditshort, ctlsref, size) {" << endl;
			else outfile << "function handleTxfChange(_doc, ctlsref, size) {" << endl;
			outfile << "\tvar elem = _doc.getElementById(ctlsref);" << endl;
			outfile << endl;

			outfile << "\telem.setAttribute(\"class\", \"txf\" + size + \"mod\");" << endl;
			outfile << endl;

			if (hasdse) outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, elem.value);" << endl;
			else outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, elem.value);" << endl;
			outfile << endl;

			if (hasdse) outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
			else outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
			outfile << "\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
		
		if (hastxft) {
			if (hasdse) outfile << "function handleTxftKey(_doc, ditshort, ctlsref, evt) {" << endl;
			else outfile << "function handleTxftKey(_doc, ctlsref, evt) {" << endl;
			outfile << "\tvar elem = _doc.getElementById(ctlsref);" << endl;
			outfile << endl;

			outfile << "\telem.setAttribute(\"class\", \"txfmod\");" << endl;
			outfile << endl;

			outfile << "\treturn true;" << endl;
			outfile << "};" << endl;
			outfile << endl;

			if (hasdse) outfile << "function handleTxftChange(_doc, ditshort, ctlsref) {" << endl;
			else outfile << "function handleTxftChange(_doc, ctlsref) {" << endl;
			outfile << "\tvar elem = _doc.getElementById(ctlsref);" << endl;
			outfile << endl;

			outfile << "\telem.setAttribute(\"class\", \"txfmod\");" << endl;
			outfile << endl;

			if (hasdse) outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, elem.value.replace(/\\n/g, \";\"));" << endl;
			else outfile << "\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, elem.value.replace(/\\n/g, \";\"));" << endl;
			outfile << endl;

			if (hasdse) outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
			else outfile << "\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
			outfile << "\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
	};

	if (has(contypes, VecWznmVMControlBasetype::UPD)) {
		if (hasdse) outfile << "function handleUpdValKey(_doc, ditshort, ctlsref, shr, evt) {" << endl;
		else outfile << "function handleUpdValKey(_doc, ctlsref, shr, evt) {" << endl;
		outfile << "\tvar elem = _doc.getElementById(ctlsref + \"Val\");" << endl;
		outfile << endl;

		outfile << "\tvar val;" << endl;
		outfile << endl;

		outfile << "\tvar min, max;" << endl;
		outfile << endl;

		outfile << "\telem.setAttribute(\"class\", \"txfsmod\");" << endl;
		outfile << endl;

		outfile << "\tif (evt.keyCode == 13) {" << endl;
		if (hasdse) {
			outfile << "\t\tmin = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Min\"));" << endl;
			outfile << "\t\tmax = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Max\"));" << endl;
		} else {
			outfile << "\t\tmin = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Min\"));" << endl;
			outfile << "\t\tmax = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Max\"));" << endl;
		};
		outfile << endl;

		outfile << "\t\tval = parseInt(elem.value);" << endl;
		outfile << "\t\tif (isNaN(val)) val = 0;" << endl;
		outfile << "\t\tif (val < min) val = min;" << endl;
		outfile << "\t\tif (val > max) val = max;" << endl;
		
		outfile << endl;

		outfile << "\t\trefreshUpd(_doc, ctlsref, min, max, val, true, true);" << endl;
		outfile << endl;

		outfile << "\t\tif (shr) {" << endl;
		if (hasdse) outfile << "\t\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
		else outfile << "\t\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\t\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << endl;

		outfile << "\t\t} else {" << endl;
		if (hasdse) outfile << "\t\t\twindow[\"handle\" + ditshort + ctlsref + \"Change\"](val);" << endl;
		else outfile << "\t\t\twindow[\"handle\" + ctlsref + \"Change\"](val);" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;

		outfile << "\t\treturn false;" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn true;" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleUpdValChange(_doc, ditshort, ctlsref, shr) {" << endl;
		else outfile << "function handleUpdValChange(_doc, ctlsref, shr) {" << endl;
		outfile << "\tvar elem = _doc.getElementById(ctlsref + \"Val\");" << endl;
		outfile << endl;

		outfile << "\tvar val;" << endl;
		outfile << endl;

		outfile << "\tvar min, max;" << endl;
		outfile << endl;

		outfile << "\telem.setAttribute(\"class\", \"txfsmod\");" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "\tmin = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Max\"));" << endl;
		} else {
			outfile << "\tmin = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Max\"));" << endl;
		};
		outfile << endl;

		outfile << "\tval = parseInt(elem.value);" << endl;
		outfile << "\tif (isNaN(val)) val = 0;" << endl;
		outfile << "\tif (val < min) val = min;" << endl;
		outfile << "\tif (val > max) val = max;" << endl;
		outfile << endl;

		outfile << "\trefreshUpd(_doc, ctlsref, min, max, val, true, true);" << endl;
		outfile << endl;

		outfile << "\tif (shr) {" << endl;
		if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
		else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\t\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;

		if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
		else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;

		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << endl;

		outfile << "\t} else {" << endl;
		if (hasdse) outfile << "\t\twindow[\"handle\" + ditshort + ctlsref + \"Change\"](val);" << endl;
		else outfile << "\t\twindow[\"handle\" + ctlsref + \"Change\"](val);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleUpdUpClick(_doc, ditshort, ctlsref, shr) {" << endl;
		else outfile << "function handleUpdUpClick(_doc, ctlsref, shr) {" << endl;
		outfile << "\tvar oldVal, val;" << endl;
		outfile << endl;

		outfile << "\tvar min, max;" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "\tif (shr) oldVal = parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref));" << endl;
			outfile << "\telse oldVal = parseInt(_doc.getElementById(ctlsref + \"Val\").value);" << endl;
			outfile << "\tmin = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Max\"));" << endl;
		} else {
			outfile << "\tif (shr) oldVal = parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref));" << endl;
			outfile << "\telse oldVal = parseInt(_doc.getElementById(ctlsref + \"Val\").value);" << endl;
			outfile << "\tmin = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Max\"));" << endl;
		};
		outfile << endl;

		outfile << "\tval = oldVal + 1;" << endl;
		outfile << "\tif (val < min) val = min;" << endl;
		outfile << "\tif (val > max) val = max;" << endl;
		outfile << endl;

		outfile << "\trefreshUpd(_doc, ctlsref, min, max, val, true, true);" << endl;
		outfile << endl;

		outfile << "\tif (shr) {" << endl;
		if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
		else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << endl;

		outfile << "\t} else {" << endl;
		if (hasdse) outfile << "\t\twindow[\"handle\" + ditshort + ctlsref + \"Change\"](val);" << endl;
		else outfile << "\t\twindow[\"handle\" + ctlsref + \"Change\"](val);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (hasdse) outfile << "function handleUpdDownClick(_doc, ditshort, ctlsref, shr) {" << endl;
		else outfile << "function handleUpdDownClick(_doc, ctlsref, shr) {" << endl;
		outfile << "\tvar oldVal, val;" << endl;
		outfile << endl;

		outfile << "\tvar min, max;" << endl;
		outfile << endl;

		if (hasdse) {
			outfile << "\tif (shr) oldVal = parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref));" << endl;
			outfile << "\telse oldVal = parseInt(_doc.getElementById(ctlsref + \"Val\").value);" << endl;
			outfile << "\tmin = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\" + ditshort, ctlsref + \"Max\"));" << endl;
		} else {
			outfile << "\tif (shr) oldVal = parseInt(retrieveCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref));" << endl;
			outfile << "\telse oldVal = parseInt(_doc.getElementById(ctlsref + \"Val\").value);" << endl;
			outfile << "\tmin = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Min\"));" << endl;
			outfile << "\tmax = parseInt(retrieveSi(srcdoc, \"StatShr" << hkroot << "\", ctlsref + \"Max\"));" << endl;
		};
		outfile << endl;

		outfile << "\tval = oldVal - 1;" << endl;
		outfile << "\tif (val < min) val = min;" << endl;
		outfile << "\tif (val > max) val = max;" << endl;
		outfile << endl;

		outfile << "\trefreshUpd(_doc, ctlsref, min, max, val, true, true);" << endl;
		outfile << endl;

		outfile << "\tif (shr) {" << endl;
		if (hasdse) outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\" + ditshort, ctlsref, \"\" + val);" << endl;
		else outfile << "\t\tsetCi(srcdoc, \"ContIac" << hkroot << "\", ctlsref, \"\" + val);" << endl;
		outfile << endl;

		if (hasdse) outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\" + ditshort);" << endl;
		else outfile << "\t\tvar str = serializeDpchAppData(srcdoc, \"DpchApp" << hkroot << "Data\", scrJref, \"ContIac" << hkroot << "\");" << endl;
		outfile << "\t\tsendReq(str, doc, handleDpchAppDataDoReply);" << endl;
		outfile << endl;

		outfile << "\t} else {" << endl;
		if (hasdse) outfile << "\t\twindow[\"handle\" + ditshort + ctlsref + \"Change\"](val);" << endl;
		else outfile << "\t\twindow[\"handle\" + ctlsref + \"Change\"](val);" << endl;
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
};

void WznmWrweb::wrSrcblksJs(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMJob
			, const string& srefDpcheng
		) {
	ubigint ref;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	WznmMTable* tbl = NULL;
	WznmMBlock* blk = NULL;

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(refWznmMJob)
				+ " AND sref = '" + srefDpcheng + "'", ref)) dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, bits);

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
			// existence of feed not required so that FeedFMcbAlert is handled appropriately
			outfile << "\tif (updateSrcblock(dom, \"" << srefDpcheng << "\", \"" << StrMod::cap(bit->sref) << "\", srcdoc)) mask.push(\"" << bit->sref << "\");" << endl;

		} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
			if (dbswznm->tblwznmmtable->loadRecByRef(bit->refWznmMTable, &tbl)) {
				outfile << "\tif (updateSrcblock(dom, \"" << srefDpcheng << "\", \"List" << tbl->sref.substr(3) << "\", srcdoc)) mask.push(\"" << bit->sref << "\");" << endl;
				delete tbl;
			};

		} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
			if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &blk)) {
				outfile << "\tif (updateSrcblock(dom, \"" << srefDpcheng << "\", \"" << blk->sref << "\", srcdoc)) mask.push(\"" << bit->sref << "\");" << endl;
				delete blk;
			};
		};
	};
};

bool WznmWrweb::getJobvecio(
			DbsWznm* dbswznm
			, const ubigint refWznmMJob
		) {
	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	bool found;

	dbswznm->tblwznmamblockitem->loadRstBySQL("SELECT TblWznmAMBlockItem.* FROM TblWznmMBlock, TblWznmAMBlockItem WHERE TblWznmAMBlockItem.blkRefWznmMBlock = TblWznmMBlock.ref AND TblWznmMBlock.refIxVTbl = "
				+ to_string(VecWznmVMBlockRefTbl::JOB) + " AND TblWznmMBlock.refUref = " + to_string(refWznmMJob), false, bits);

	found = false;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
			found = ( (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) || (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) || (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC)
						|| (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) || (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) || (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC)
						|| (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) || (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC)
						|| (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) || (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) );

		} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
			// append to bits
			dbswznm->tblwznmamblockitem->loadRstByBlk(bit->refWznmMBlock, true, bits);
		};

		if (found) break;
	};

	return found;
};

string WznmWrweb::getCondoc(
			WznmMControl* con
		) {
	if (con->hkIxVSection == VecWznmVMControlHkSection::SIDE) return("sidedoc");
	else if ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRDETD) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRREGD)) return("hdrdoc");
	else if ((con->hkIxVSection == VecWznmVMControlHkSection::CONT) || (con->hkIxVSection == VecWznmVMControlHkSection::CONTDETD) || (con->hkIxVSection == VecWznmVMControlHkSection::CONTREGD)) {
		if (con->hkIxVTbl == VecWznmVMControlHkTbl::DLG) return("contdoc");
		else if (con->hkIxVTbl == VecWznmVMControlHkTbl::PNL) return("contcontdoc");
	} else if (con->hkIxVSection == VecWznmVMControlHkSection::TBL) return("tbldoc");
	else if (con->hkIxVSection == VecWznmVMControlHkSection::FTR) return("ftrdoc");

	return("");
};

string WznmWrweb::getConsize(
			WznmMControl* con
		) {
	if (StrMod::srefInSrefs(con->srefsKOption, "s")) return("s");
	else if (StrMod::srefInSrefs(con->srefsKOption, "t")) return("t");
	else if (StrMod::srefInSrefs(con->srefsKOption, "xs")) return("xs");

	return("");
};

string WznmWrweb::getButicon(
			DbsWznm* dbswznm
			, const string& Prjshort
			, WznmMControl* con
		) {
	string retval;
	char c;

	retval = "icon/void";

	if (dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "icon", 0, retval)) {
		retval = "icon" + StrMod::lc(Prjshort) + "/" + retval;

	} else {
		if (!dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "stdicon", 0, retval)) {
			if (con->sref != "") {
				for (unsigned int i=con->sref.length();i>0;i--) {
					c = con->sref[i-1];
					if ((c >= 'A') && (c <= 'Z')) {
						retval = StrMod::uncap(con->sref.substr(i-1));
						break;
					};
				};
			};
		};

		retval = "icon/" + retval;
	};

	return retval;
};

string WznmWrweb::getLstncol(
			WznmMControl* con
		) {
	if (StrMod::srefInSrefs(con->srefsKOption, "bicol")) return("2");
	else if (StrMod::srefInSrefs(con->srefsKOption, "tricol")) return("3");
	else return("1");
};

bool WznmWrweb::hasAction(
			DbsWznm* dbswznm
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string& action
		) {
	bool found = false;

	ListWznmAMControlPar conApars;
	WznmAMControlPar* conApar = NULL;

	uint cnt;

	if (action.compare("dlgopen") == 0) {
		// dialog open implied by control with corresponding reference
		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " AND refIxVTbl = " + to_string(VecWznmVMControlRefTbl::DLG), cnt);
		found = (cnt > 0);
	};
	
	if (!found) {
		dbswznm->tblwznmamcontrolpar->loadRstBySQL("SELECT TblWznmAMControlPar.* FROM TblWznmAMControlPar, TblWznmMControl WHERE TblWznmAMControlPar.refWznmMControl = TblWznmMControl.ref AND TblWznmMControl.hkIxVTbl = "
					+ to_string(hkIxVTbl) + " AND TblWznmMControl.hkUref = " + to_string(hkUref) + " AND TblWznmAMControlPar.x1SrefKKey = 'action'", false, conApars);

		for (unsigned int i = 0; i < conApars.nodes.size(); i++) {
			conApar = conApars.nodes[i];

			if (conApar->osrefKVal.compare(action) == 0) {
				found = true;
				break;
			};
		};
	};

	return(found);
};

bool WznmWrweb::hasStfeed(
			DbsWznm* dbswznm
			, WznmMControl* con
		) {
	bool retval = false;

	WznmMFeed* fed = NULL;
	WznmMVector* vec = NULL;

	if (dbswznm->tblwznmmfeed->loadRecByRef(con->refWznmMFeed, &fed)) {
		if (fed->srcIxVTbl == VecWznmVMFeedSrcTbl::VEC) {
			if (dbswznm->tblwznmmvector->loadRecByRef(fed->srcUref, &vec)) {
				retval = ((vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) || (vec->ixVBasetype == VecWznmVMVectorBasetype::OR));
				delete vec;
			};
		};
		delete fed;
	};

	return retval;
};
// IP cust --- IEND


