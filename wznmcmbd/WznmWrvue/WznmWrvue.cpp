/**
	* \file WznmWrvue.cpp
	* Wznm operation pack global code (implementation)
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

#include "WznmWrvue.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrvue
 ******************************************************************************/

// IP cust --- IBEGIN
void WznmWrvue::wrIp(
			fstream& outfile
			, const int indent
			, const string& tag
			, const string& type
		) {
	outfile << string(indent, '\t') << "/*" << endl;
	outfile << string(indent, '\t') << "<!-- IP " << tag << " - " << type << " -->" << endl;
	outfile << string(indent, '\t') << "*/" << endl;
};

void WznmWrvue::wrIbegin(
			fstream& outfile
			, const int indent
			, const string& tag
			, const bool addbegin
		) {
	outfile << "<!-- IP " << tag << " - IBEGIN -->" << endl;
	if (addbegin) outfile << string(indent, '\t') << "<!-- IP " << tag << " - BEGIN -->" << endl;
	outfile << string(indent, '\t') << "*/" << endl;
};

void WznmWrvue::wrIend(
			fstream& outfile
			, const int indent
			, const string& tag
			, const bool addend
		) {
	outfile << string(indent, '\t') << "/*" << endl;
	if (addend) outfile << string(indent, '\t') << "<!-- IP " << tag << " - END -->" << endl;
	outfile << "<!-- IP " << tag << " - IEND -->" << endl;
};

void WznmWrvue::wrBasecon(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, const string& hksref
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const unsigned int ixIcsBasecons
			, const string& ditshort
		) {
	WznmMControl* con = NULL;

	unsigned int cplxtype;
	string baseconsref, baseconshort;
	bool ldyn, dyn, rdyn, vbar;
	unsigned int ix0, ix1;
	unsigned int ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView;
	vector<unsigned int> icsButs;
	unsigned int ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt;
	vector<unsigned int> icsVbarcons;

	WznmMControl* basecon = NULL;

	string consref;

	string indent;

	string s;

	bool other;

	basecon = cons.nodes[icsBasecons[ixIcsBasecons]];

	//if (basecon->ixVScope != VecWznmVMControlScope::SHR) continue;

	if (ditshort == "") indent = string(3, '\t');
	else indent = string(7, '\t');

	other = false;

	Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, ixIcsBasecons, ditshort, cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
				icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

	if (cplxtype == Concplxtype::INVALID) {

	} else if (cplxtype == Concplxtype::BUT_CLUST) {
		outfile << indent << "<v-row class=\"my-1\">" << endl;
		outfile << indent << "\t<v-col>" << endl;

		for (unsigned int i = 0; i < icsButs.size(); i++) {
			con = cons.nodes[icsButs[i]];
			consref = Wznm::getConsref(con, ditshort);

			s = "";
			dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "action", 0, s);

			if (i != 0) outfile << indent << "\t\t&#160;" << endl;
			outfile << indent << "\t\t<v-btn" << endl;
			if (s == "crdopen") outfile << indent << "\t\t\tv-on:click=\"handleButCrdopenClick(";
			else outfile << indent << "\t\t\tv-on:click=\"handleButClick(";
			if (ditshort != "") outfile << "'" << StrMod::lc(ditshort) << "', ";
			outfile << "'" << consref << "Click')\"" << endl;
			if (con->Active != "") outfile << indent << "\t\t\t:disabled=\"!statshr" << StrMod::lc(ditshort) << "." << consref << "Active\"" << endl;

			if (StrMod::srefInSrefs(con->srefsKOption, "icon")) {
				if (!dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "icon", 0, s))
							dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "stdicon", 0, s);

				outfile << indent << "\t\t\tfab" << endl;
				outfile << indent << "\t\t\tsmall" << endl;
				outfile << indent << "\t\t\tlight" << endl;
				outfile << indent << "\t\t\tcolor=\"primary\"" << endl;
				outfile << indent << "\t\t>" << endl;
				outfile << indent << "\t\t\t<v-icon color=\"white\">mdi-" << s << "</v-icon>" << endl;

			} else {
				outfile << indent << "\t\t\tclass=\"my-1\"" << endl;
				outfile << indent << "\t\t\tcolor=\"primary\"" << endl;
				outfile << indent << "\t\t>" << endl;
				outfile << indent << "\t\t\t{{tag" << StrMod::lc(ditshort) << "." << consref << "}}" << endl;
			};

			outfile << indent << "\t\t</v-btn>" << endl;
		};

		outfile << indent << "\t</v-col>" << endl;
		outfile << indent << "</v-row>" << endl;
		outfile << endl;

	} else if (cplxtype == Concplxtype::CHK) {
		outfile << indent << "<v-checkbox" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tclass=\"my-1\"" << endl;
		outfile << indent << "\tv-model=\"contiac" << StrMod::lc(ditshort) << "." << baseconsref << "\"" << endl;
		outfile << indent << "\tv-on:change='updateEng([\"contiac" << StrMod::lc(ditshort) << "\"])'" << endl;
		outfile << indent << "\t:label=\"tag" << StrMod::lc(ditshort) << ".Cpt" << baseconshort << "\"" << endl;
		if (basecon->Active != "") outfile << indent << "\t:disabled=\"!statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Active\"" << endl;
		outfile << indent << "/>" << endl;
		outfile << endl;

	} else if (cplxtype == Concplxtype::CUS) {
		s = "100";
		dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(basecon->ref, "height", 0, s);

		outfile << indent << "<div" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tclass=\"my-1\"" << endl;
		outfile << indent << "\tstyle=\"height:" << s << "px\"" << endl;
		outfile << indent << ">" << endl;
		outfile << indent << "\t<!-- IP div" << baseconshort << " - INSERT -->" << endl;
		outfile << indent << "</div>" << endl;
		outfile << endl;

	} else if (cplxtype == Concplxtype::DLD) {
		outfile << indent << "<v-btn" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tdownload" << endl;
		outfile << indent << "\t:href=\"hrefDld\"" << endl;
		if (basecon->Active != "") outfile << indent << "\t:disabled=\"!statshr" << StrMod::lc(ditshort) << ".DldActive\"" << endl;
		outfile << indent << "\tclass=\"my-1\"" << endl;
		outfile << indent << "\tcolor=\"primary\"" << endl;
		outfile << indent << ">" << endl;
		outfile << indent << "\t{{tag" << StrMod::lc(ditshort) << ".Dld}}" << endl;
		outfile << indent << "</v-btn>" << endl;

	} else if (cplxtype == Concplxtype::HDG) {
		outfile << indent << "<h3" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tclass=\"text-5 my-1\"" << endl;
		outfile << indent << ">" << endl;
		outfile << indent << "\t{{tag" << StrMod::lc(ditshort) << "." << baseconsref << "}}" << endl;
		outfile << indent << "</h3>" << endl;
		outfile << endl;

	} else if (cplxtype == Concplxtype::LST) {
		other = true;

	} else if (cplxtype == Concplxtype::LST_NOALT) {
		other = true;

	} else if (cplxtype == Concplxtype::LST_TXFALT) {
		other = true;

	} else if (cplxtype == Concplxtype::LST_TXTALT) {
		other = true;

	} else if (cplxtype == Concplxtype::PUP) {
		outfile << indent << "<v-select" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tclass=\"my-1\"" << endl;
		outfile << indent << "\tv-model=\"contapp" << StrMod::lc(ditshort) << ".fiF" << baseconsref << "\"" << endl;
		outfile << indent << "\t:items=\"feedF" << ditshort << baseconsref << "\"" << endl;
		outfile << indent << "\t:label='tag" << StrMod::lc(ditshort) << ".Cpt" << baseconshort << "'" << endl;
		outfile << indent << "\tv-on:change=\"handlePupChange(";
		if (ditshort != "") outfile << "'" <<  StrMod::lc(ditshort) << "', ";
		outfile << "'numF" << baseconsref << "', contapp" << StrMod::lc(ditshort) << ".fiF" << baseconsref << ")\"" << endl;
		if (basecon->Active != "") outfile << indent << "\t:disabled=\"!statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Active\"" << endl;
		outfile << indent << ">" << endl;
		outfile << indent << "\t<template v-slot:selection=\"{item}\">{{item.tit1}}</template>" << endl;
		outfile << indent << "\t<template v-slot:item=\"{item}\">{{item.tit1}}</template>" << endl;
		outfile << indent << "</v-select>" << endl;
		outfile << endl;

	} else if (cplxtype == Concplxtype::PUP_PUP) {
		other = true;

	} else if (cplxtype == Concplxtype::PUP_TXFALT) {
		other = true;

	} else if (cplxtype == Concplxtype::PUP_VBAR) {
		other = true;

	} else if (cplxtype == Concplxtype::SEP) {
		outfile << indent << "<v-divider";
		if (basecon->Avail != "") outfile << " v-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"";
		outfile << "/>" << endl;
		outfile << endl;

	} else if (cplxtype == Concplxtype::SLD) {
		outfile << indent << "<v-slider" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tclass=\"my-1\"" << endl;
		outfile << indent << "\tv-model=\"contiac" << StrMod::lc(ditshort) << "." << baseconsref << "\"" << endl;
		outfile << indent << "\tv-on:end='updateEng([\"contiac" << StrMod::lc(ditshort) << "\"])'" << endl;
		outfile << indent << "\t:label=\"tag" << StrMod::lc(ditshort) << ".Cpt" << baseconshort << "\"" << endl;
		outfile << indent << "\t:min=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Min\"" << endl;
		outfile << indent << "\t:max=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Max\"" << endl;
		if (basecon->Active != "") outfile << indent << "\t:disabled=\"!statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Active\"" << endl;
		outfile << indent << ">" << endl;
		outfile << indent << "\t<template v-slot:append>" << endl;
		outfile << indent << "\t\t<v-text-field" << endl;
		outfile << indent << "\t\t\tv-model=\"contiac" << StrMod::lc(ditshort) << "." << baseconsref << "\"" << endl;
		outfile << indent << "\t\t\tv-on:change='updateEng([\"contiac" << StrMod::lc(ditshort) << "\"])'" << endl;
		outfile << indent << "\t\t\tclass=\"mt-0 pt-0\"" << endl;
		outfile << indent << "\t\t\thide-details" << endl;
		outfile << indent << "\t\t\tsingle-line" << endl;
		outfile << indent << "\t\t\ttype=\"number\"" << endl;
		outfile << indent << "\t\t\tstyle=\"width: 80px\"" << endl;
		outfile << indent << "\t\t/>" << endl;
		outfile << indent << "\t</template>" << endl;
		outfile << indent << "</v-slider>" << endl;
		outfile << endl;

	} else if (cplxtype == Concplxtype::SPC) {
		other = true;

	} else if (cplxtype == Concplxtype::TXF) {
		outfile << indent << "<v-text-field" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tclass=\"my-1\"" << endl;
		outfile << indent << "\tv-model=\"contiac" << StrMod::lc(ditshort) << "." << baseconsref << "\"" << endl;
		outfile << indent << "\t:label=\"tag" << StrMod::lc(ditshort) << ".Cpt" << baseconshort << "\"" << endl;
		if (basecon->Active != "") outfile << indent << "\t:disabled=\"!statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Active\"" << endl;
		outfile << indent << "/>" << endl;
		outfile << endl;

	} else if (cplxtype == Concplxtype::TXT) {
		outfile << indent << "<v-text-field" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tclass=\"my-1\"" << endl;
		outfile << indent << "\treadonly" << endl;
		outfile << indent << "\toutlined" << endl;
		outfile << indent << "\tv-model=\"continf" << StrMod::lc(ditshort) << "." << baseconsref << "\"" << endl;
		outfile << indent << "\t:label=\"tag" << StrMod::lc(ditshort) << ".Cpt" << baseconshort << "\"" << endl;
		outfile << indent << "/>" << endl;
		outfile << endl;

	} else if (cplxtype == Concplxtype::TXT_PUP) {
		other = true;

	} else if (cplxtype == Concplxtype::TXT_TXFALT) {
		other = true;

	} else if (cplxtype == Concplxtype::ULD) {
		outfile << indent << "<v-file-input" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\toutlined" << endl;
		outfile << indent << "\tshow-size" << endl;
		outfile << indent << "\t:label=\"tag" << StrMod::lc(ditshort) << ".Cpt\"" << endl;
		outfile << indent << "\tv-model=\"contapp" << StrMod::lc(ditshort) << ".file\"" << endl;
		outfile << indent << ">" << endl;
		outfile << indent << "</v-file-input>" << endl;
		outfile << indent << "<v-btn" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tv-on:click=\"handleButUploadClick(";
		if (ditshort != "") outfile << "'" <<  StrMod::lc(ditshort) << "'";
		outfile << ")\"" << endl;
		outfile << indent << "\t:disabled=\"contapp" << StrMod::lc(ditshort) << ".file == null\"" << endl;
		outfile << indent << "\tcolor=\"primary\"" << endl;
		outfile << indent << ">" << endl;
		outfile << indent << "\t{{tag" << StrMod::lc(ditshort) << ".Uld}}" << endl;
		outfile << indent << "</v-btn>" << endl;

	} else if (cplxtype == Concplxtype::UPD) {
		other = true;
	};

	if (other) {
		// preliminary: manual implementation
		outfile << indent << "<div" << endl;
		if (basecon->Avail != "") outfile << indent << "\tv-if=\"statshr" << StrMod::lc(ditshort) << "." << baseconsref << "Avail\"" << endl;
		outfile << indent << "\tclass=\"my-1\"" << endl;
		outfile << indent << ">" << endl;
		outfile << indent << "\t<!-- IP div" << ditshort << baseconshort << " - INSERT -->" << endl;
		outfile << indent << "</div>" << endl;
		outfile << endl;
	};
};

void WznmWrvue::wrMergedpcheng(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, const ubigint refWznmMJob
			, string sub
			, const bool postprc
		) {
	// cf. WznmWrweb::wrSrcblksJs

	ubigint ref;

	WznmMJob* job = NULL;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ListWznmAMBlockItem bit2s;
	WznmAMBlockItem* bit2 = NULL;

	WznmMTable* tbl = NULL;
	WznmMBlock* blk = NULL;

	ListWznmMDialog dlgs;
	WznmMDialog* dlg = NULL;

	string suffix;

	string s;

	bool found;

	if (sub != "") sub += ".";

	if (dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job)) {
		if ((job->ixVBasetype == VecWznmVMJobBasetype::CRD) || (job->ixVBasetype == VecWznmVMJobBasetype::PNL)) s = "DpchEng" + job->sref.substr(3) + "Data";
		else s = "DpchEng" + job->sref + "Data";

		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
					+ " AND sref = '" + s + "'", ref)) dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, bits);

		if (job->ixVBasetype == VecWznmVMJobBasetype::CRD) dbswznm->tblwznmmdialog->loadRstByCar(job->refUref, false, dlgs);

		if (postprc && (dlgs.nodes.size() > 0)) {
			outfile << "\t\t\t\tvar dlgopen = false;" << endl;
			outfile << "\t\t\t\tvar dlgclose = false;" << endl;
			outfile << endl;

			outfile << "\t\t\t\tvar srefDlg = \"\";" << endl;
			outfile << "\t\t\t\tvar scrJrefDlg = \"\";" << endl;
			outfile << endl;
		};

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\t\t\tif (dpcheng." << StrMod::cap(bit->sref) << ") this." << sub << bit->sref << " = dpcheng." << StrMod::cap(bit->sref) << ";" << endl;

			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
				if (dbswznm->tblwznmmtable->loadRecByRef(bit->refWznmMTable, &tbl)) {
					outfile << "\t\t\t\tif (dpcheng.List" << tbl->sref.substr(3) << ") this." << sub << bit->sref << " = dpcheng.List" << tbl->sref.substr(3) << ";" << endl;
					delete tbl;
				};

			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &blk)) {
					if (postprc && (dlgs.nodes.size() > 0) && (blk->ixVBasetype == VecWznmVMBlockBasetype::STAT) && (blk->sref == ("StatShr" + job->sref.substr(3)))) {
						outfile << "\t\t\t\tif (dpcheng." << blk->sref << ") {" << endl;

						outfile << "\t\t\t\t\tif (this." << bit->sref << " != null) {" << endl;

						outfile << "\t\t\t\t\t\tdlgopen = ";
						if (dlgs.nodes.size() > 1) outfile << "(";
						for (unsigned int j = 0; j < dlgs.nodes.size(); j++) {
							dlg = dlgs.nodes[j];

							if (j != 0) outfile << " || ";
							outfile << "(dpcheng." << blk->sref << ".scrJrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << " != \"\")";
						};
						if (dlgs.nodes.size() > 1) outfile << ")";
						outfile << ";" << endl;

						outfile << "\t\t\t\t\t\tdlgclose = ";
						if (dlgs.nodes.size() > 1) outfile << "(";
						for (unsigned int j = 0; j < dlgs.nodes.size(); j++) {
							dlg = dlgs.nodes[j];

							if (j != 0) outfile << " || ";
							outfile << "(this." << bit->sref << ".scrJrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << " != \"\")";
						};
						if (dlgs.nodes.size() > 1) outfile << ")";
						outfile << ";" << endl;

						outfile << "\t\t\t\t\t\tif (dlgopen && dlgclose) {" << endl;
						outfile << "\t\t\t\t\t\t\tdlgopen = false;" << endl;
						outfile << "\t\t\t\t\t\t\tdlgclose = false;" << endl;
						outfile << "\t\t\t\t\t\t}" << endl;

						outfile << "\t\t\t\t\t\tif (dlgopen) {" << endl;

						for (unsigned int j = 0; j < dlgs.nodes.size(); j++) {
							dlg = dlgs.nodes[j];

							outfile << "\t\t\t\t\t\t\t";
							if (j != 0) outfile << "} else ";

							outfile << "if (dpcheng." << blk->sref << ".scrJrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << " != \"\") {" << endl;
							outfile << "\t\t\t\t\t\t\t\tsrefDlg = \"" << dlg->sref << "\";" << endl;
							outfile << "\t\t\t\t\t\t\t\tscrJrefDlg = dpcheng." << blk->sref << ".scrJrefDlg" << StrMod::lc(dlg->sref.substr(3+4+3)) << ";" << endl;
						};

						outfile << "\t\t\t\t\t\t\t}" << endl;
						outfile << "\t\t\t\t\t\t}" << endl;
						outfile << "\t\t\t\t\t}" << endl;

						outfile << "\t\t\t\t\tthis." << bit->sref << " = dpcheng." << blk->sref << ";" << endl;
						outfile << "\t\t\t\t}" << endl;

					} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::TAG) {
						outfile << "\t\t\t\tif (dpcheng." << blk->sref << ") {" << endl;
						outfile << "\t\t\t\t\t" << Prjshort << ".unescapeBlock(dpcheng." << blk->sref << ");" << endl;
						outfile << "\t\t\t\t\tthis." << sub << bit->sref << " = dpcheng." << blk->sref << ";" << endl;
						outfile << "\t\t\t\t}" << endl;

					} else outfile << "\t\t\t\tif (dpcheng." << blk->sref << ") this." << sub << bit->sref << " = dpcheng." << blk->sref << ";" << endl;

					delete blk;
				};
			};
		};

		if (postprc) {
			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &blk)) {
						if (blk->ixVBasetype == VecWznmVMBlockBasetype::CONT) {
							suffix = bit->sref.substr(7);

							dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bit2s);

							found = false;

							for (unsigned int j = 0; j < bit2s.nodes.size(); j++) {
								bit2 = bit2s.nodes[j];

								found = ((bit2->sref.find("numF") == 0) && (bit2->sref.find("Pup") != string::npos));
								if (!found) found = ((bit2->sref.find("numF") == 0) && (bit2->sref.find("Lst") != string::npos));
								if (!found) found = ((bit2->sref.find("numsF") == 0) && (bit2->sref.find("Lst") != string::npos));
								if (!found) found = ((bit2->sref.find("But") != string::npos) && ((bit2->sref.rfind("On") + 2) == bit2->sref.length()));

								if (found) break;
							};

							if (found) {
								outfile << "\t\t\t\tif (dpcheng." << blk->sref << ") {" << endl;

								for (unsigned int j = 0; j < bit2s.nodes.size(); j++) {
									bit2 = bit2s.nodes[j];

									if ((bit2->sref.find("numF") == 0) && ((bit2->sref.find("Pup") != string::npos) || (bit2->sref.find("Lst") != string::npos))) {
										outfile << "\t\t\t\t\tfor (let i = 0; i < this.feedF" << StrMod::cap(suffix) << bit2->sref.substr(3 + 1) << ".length; i++)" << endl;
										outfile << "\t\t\t\t\t\tif (this.feedF" << StrMod::cap(suffix) << bit2->sref.substr(3 + 1) << "[i].num == this." << bit->sref << "." << bit2->sref << ") {" << endl;
										outfile << "\t\t\t\t\t\t\tthis.contapp" << suffix << ".fi" << bit2->sref.substr(3) << " = this.feedF" << StrMod::cap(suffix) << bit2->sref.substr(3 + 1) << "[i];" << endl;
										outfile << "\t\t\t\t\t\t\tbreak;" << endl;
										outfile << "\t\t\t\t\t\t}" << endl;

									} else if ((bit2->sref.find("numsF") == 0) && (bit2->sref.find("Lst") != string::npos)) {
										// ...

									} else if ((bit2->sref.find("But") != string::npos) && ((bit2->sref.rfind("On") + 2) == bit2->sref.length())) {
										outfile << "\t\t\t\t\tif (!this." << bit->sref << "." << bit2->sref << ") this.contapp" << suffix << "." << bit2->sref << " = 0;" << endl;
										outfile << "\t\t\t\t\telse this.contapp" << suffix << "." << bit2->sref << " = 1;" << endl;
									};
								};

								outfile << "\t\t\t\t}" << endl;
							};
						};
					};
				};
			};

			if (dlgs.nodes.size() > 0) {
				outfile << endl;

				outfile << "\t\t\t\tif (dlgopen) this.$emit(\"dlgopen\", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});" << endl;
				outfile << "\t\t\t\telse if (dlgclose) this.$emit(\"dlgclose\");" << endl;
			};
		};

		delete job;
	};
};

void WznmWrvue::wrData(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, const ubigint refWznmMJob
		) {
	ubigint ref;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;
	WznmAMBlockItem* bit2 = NULL;

	ListWznmAMBlockItem bit3s;
	WznmAMBlockItem* bit3 = NULL;

	set<string> suffices;
	string suffix, suffix2;

	bool first, first2, found;

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(refWznmMJob)
				+ " AND sref LIKE 'DpchEng%Data'", ref)) dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, bits);

	first = true;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) || (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) || (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB)) {
			if (first) first = false;
			else outfile << endl;

			outfile << "\t\t\t" << bit->sref << ": null," << endl;
		};
	};

	// for contapp, look at existing rst, contiac.numFPup / contiac.numFLst / contiac.numsFLst, continf.But...On
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) suffix = "";
		else if ( (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) && ((bit->sref.find("contiac") == 0) || (bit->sref.find("continf") == 0)) ) suffix = bit->sref.substr(7);
		else if ((bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) && (bit->sref.find("tag") == 0)) suffix = bit->sref.substr(3);
		else continue;

		if (suffices.find(suffix) == suffices.end()) {
			first2 = true;

			for (unsigned int j = i; j < bits.nodes.size(); j++) {
				bit2 = bits.nodes[j];

				if (bit2->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) suffix2 = "";
				else if ( (bit2->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) && ((bit2->sref.find("contiac") == 0) || (bit2->sref.find("continf") == 0)) ) suffix2 = bit2->sref.substr(7);
				else if ((bit2->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) && (bit2->sref.find("tag") == 0)) suffix2 = bit2->sref.substr(3);
				else continue;

				if (suffix == suffix2) {
					found = (bit2->ixVBasetype == VecWznmVAMBlockItemBasetype::RST);
					if (!found) {
						dbswznm->tblwznmamblockitem->loadRstByBlk(bit2->refWznmMBlock, false, bit3s);

						for (unsigned int k = 0; k < bit3s.nodes.size(); k++) {
							bit3 = bit3s.nodes[k];

							found = ((bit3->sref.find("numF") == 0) && (bit3->sref.find("Pup") != string::npos));
							if (!found) found = ((bit3->sref.find("numF") == 0) && (bit3->sref.find("Lst") != string::npos));
							if (!found) found = ((bit3->sref.find("numsF") == 0) && (bit3->sref.find("Lst") != string::npos));
							if (!found) found = ((bit3->sref.find("But") != string::npos) && ((bit3->sref.rfind("On") + 2) == bit3->sref.length()));
							if (!found) found = ((bit2->sref.find("tag") == 0) && ((bit3->sref.rfind("Uld") + 3) == bit3->sref.length()));

							if (found) break;
						};
					};

					if (found) {
						if (first2) {
							if (first) first = false;
							else outfile << endl;

							outfile << "\t\t\tcontapp" << suffix << ": {" << endl;
						};

						if (bit2->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
							if (!first2) outfile << endl;

							outfile << "\t\t\t\ttcos: []," << endl;
							outfile << "\t\t\t\trows: []," << endl;

							first2 = false;

						} else {
							for (unsigned int k = 0; k < bit3s.nodes.size(); k++) {
								bit3 = bit3s.nodes[k];

								if ((bit3->sref.find("numF") == 0) && ((bit3->sref.find("Pup") != string::npos) || (bit3->sref.find("Lst") != string::npos))) {
									if (!first2) outfile << endl;
									outfile << "\t\t\t\tfi" << bit3->sref.substr(3) << ": null," << endl;
									first2 = false;

								} else if ((bit3->sref.find("numsF") == 0) && (bit3->sref.find("Lst") != string::npos)) {
									if (!first2) outfile << endl;
									outfile << "\t\t\t\tfis" << bit3->sref.substr(4) << ": []," << endl;
									first2 = false;

								} else if ((bit3->sref.find("But") != string::npos) && ((bit3->sref.rfind("On") + 2) == bit3->sref.length())) {
									if (!first2) outfile << endl;
									outfile << "\t\t\t\t" << bit3->sref << ": 0," << endl;
									first2 = false;

								} else if ((bit2->sref.find("tag") == 0) && ((bit3->sref.rfind("Uld") + 3) == bit3->sref.length())) {
									if (!first2) outfile << endl;
									outfile << "\t\t\t\tfile: null," << endl;
									first2 = false;
								};
							};
						};
					};
				};
			};

			if (!first2) {
				outfile << endl;
				outfile << "\t\t\t}," << endl;
			};

			suffices.insert(suffix);
		};
	};
};

string WznmWrvue::getButmdi(
			DbsWznm* dbswznm
			, const string& Prjshort
			, WznmMControl* con
		) {
	string retval;
	char c;

	retval = "mdi-void";

	// mapping elaborated so far
	map<string, string> iconMdis = {
		{"claim", "cog"}
		, {"clipboard", "clipboard"}
		, {"delete", "file-remove"}
		, {"duplicate", "file-multiple"}
		, {"down", "chevron-down-box"}
		, {"filter", "filter"}
		, {"minimize", "minus-circle"}
		, {"new", "file-plus"}
		, {"refresh", "refresh"}
		, {"regularize", "plus-circle"}
		, {"up", "chevron-up-box"}
		, {"view", "book-arrow-up"}
	};

	if (dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "mdi", 0, retval)) {
		retval = "mdi-" + retval;

	} else {
		if (!dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "stdicon", 0, retval)) {
			if (con->sref != "") {
				for (unsigned int i = con->sref.length(); i > 0; i--) {
					c = con->sref[i-1];
					if ((c >= 'A') && (c <= 'Z')) {
						retval = StrMod::uncap(con->sref.substr(i - 1));
						break;
					};
				};
			};
		};

		auto it = iconMdis.find(retval);
		if (it != iconMdis.end()) retval = it->second;

		retval = "mdi-" + retval;
	};

	return retval;
};
// IP cust --- IEND
