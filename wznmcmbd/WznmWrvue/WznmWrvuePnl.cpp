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
	fstream vuefile;

	WznmMPanel* pnl = NULL;

	string s;

	if (dbswznm->tblwznmmpanel->loadRecByRef(refWznmMPanel, &pnl)) {
		s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".vue.ip";
		vuefile.open(s.c_str(), ios::out);
		writePnlVue(dbswznm, vuefile, pnl, Prjshort);
		vuefile.close();

		delete pnl;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrvuePnl::writePnlVue(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMPanel* pnl
			, const string& Prjshort
		) {
	ListWznmMControl cons;
	WznmMControl* con = NULL;

	vector<unsigned int> icsBasecons;

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

	unsigned int w;
	string s, s2;

	bool found, other;

	// --- hdr
	outfile << "<!-- IP hdr - IBEGIN -->" << endl;

	// preliminary: consider special case of ButClaim
	dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, cons);

	found = false;

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && ((con->hkIxVSection == VecWznmVMControlHkSection::HDR) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRDETD) || (con->hkIxVSection == VecWznmVMControlHkSection::HDRREGD))) {
			if (con->sref == "ButClaim") {
				found = true;
				break;
			};
		};
	};

	outfile << "\t\t\t\t<v-col cols=\"";
	if (!found) outfile << 12;
	else outfile << 11;
	outfile << "\">" << endl;
	outfile << "\t\t\t\t\t<div>{{tag.Cpt}}</div>" << endl;
	outfile << "\t\t\t\t</v-col>" << endl;

	if (found) {
		outfile << "\t\t\t\t<v-col align=\"end\">" << endl;
		outfile << "\t\t\t\t\t<v-btn-toggle v-model=\"contapp." << con->sref << "On\">" << endl;
		outfile << "\t\t\t\t\t\t<v-btn" << endl;
		outfile << "\t\t\t\t\t\t\tfab" << endl;
		outfile << "\t\t\t\t\t\t\tsmall" << endl;
		outfile << "\t\t\t\t\t\t\tlight" << endl;
		outfile << "\t\t\t\t\t\t\tcolor=\"primary\"" << endl;
		outfile << "\t\t\t\t\t\t\tv-on:click=\"handleButClick('" << con->sref << "Click')\"" << endl;
		outfile << "\t\t\t\t\t\t\t:value=\"1\"" << endl;
		if (con->Active != "") outfile << "\t\t\t\t\t\t\t:disabled=\"!statshr." << con->sref << "Active\"" << endl;
		outfile << "\t\t\t\t\t\t>" << endl;
		outfile << "\t\t\t\t\t\t\t<v-icon color=\"white\">{{contapp." << con->sref << "On ? 'mdi-cog' : 'mdi-cog-off'}}</v-icon>" << endl;
		outfile << "\t\t\t\t\t\t</v-btn>" << endl;
		outfile << "\t\t\t\t\t</v-btn-toggle>" << endl;
		outfile << "\t\t\t\t</v-col>" << endl;
	};

	outfile << "<!-- IP hdr - IEND -->" << endl;

	// --- cont
	outfile << "<!-- IP cont - IBEGIN -->" << endl;

	Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT, VecWznmVMControlHkSection::CONTREGD}, 0, icsBasecons);

	for (unsigned int i = 0; i < icsBasecons.size(); i++) {
		basecon = cons.nodes[icsBasecons[i]];

		//if (basecon->ixVScope != VecWznmVMControlScope::SHR) continue;

		other = false;

		Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
					icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

		if (cplxtype == Concplxtype::INVALID) {

		} else if (cplxtype == Concplxtype::BUT_CLUST) {
			outfile << "\t\t\t<v-row class=\"my-2\">" << endl;
			outfile << "\t\t\t\t<v-col>" << endl;

			for (unsigned int i = 0; i < icsButs.size(); i++) {
				con = cons.nodes[icsButs[i]];
				consref = Wznm::getConsref(con, "");

				if (i != 0) outfile << "\t\t\t\t\t&#160;" << endl;

				if (StrMod::srefInSrefs(con->srefsKOption, "icon")) {
					if (!dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "icon", 0, s))
								dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, "stdicon", 0, s);

					outfile << "\t\t\t\t\t<v-btn" << endl;
					outfile << "\t\t\t\t\t\tfab" << endl;
					outfile << "\t\t\t\t\t\tsmall" << endl;
					outfile << "\t\t\t\t\t\tlight" << endl;
					outfile << "\t\t\t\t\t\tcolor=\"primary\"" << endl;
					outfile << "\t\t\t\t\t\tv-on:click=\"handleButClick('" << consref << "Click')\"" << endl;
					if (con->Active != "") outfile << "\t\t\t\t\t\t:disabled=\"!statshr." << consref << "Active\"" << endl;
					outfile << "\t\t\t\t\t>" << endl;
					outfile << "\t\t\t\t\t\t<v-icon color=\"white\">mdi-" << s << "</v-icon>" << endl;
					outfile << "\t\t\t\t\t</v-btn>" << endl;

				} else {
					outfile << "\t\t\t\t\t<v-btn" << endl;
					outfile << "\t\t\t\t\t\tclass=\"my-2\"" << endl;
					outfile << "\t\t\t\t\t\tcolor=\"primary\"" << endl;
					outfile << "\t\t\t\t\t\tv-on:click=\"handleButClick('" << consref << "Click')\"" << endl;
					if (con->Active != "") outfile << "\t\t\t\t\t\t:disabled=\"!statshr." << consref << "Active\"" << endl;
					outfile << "\t\t\t\t\t>" << endl;
					outfile << "\t\t\t\t\t\t{{tag." << consref << "}}" << endl;
					outfile << "\t\t\t\t\t</v-btn>" << endl;
				};
			};

			outfile << "\t\t\t\t</v-col>" << endl;
			outfile << "\t\t\t</v-row>" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::CHK) {
			outfile << "\t\t\t<v-checkbox" << endl;
			if (con->Avail != "") outfile << "\t\t\t\tv-if=\"statshr." << baseconsref << "Avail\"" << endl;
			outfile << "\t\t\t\tclass=\"my-2\"" << endl;
			outfile << "\t\t\t\tv-model=\"contiac." << baseconsref << "\"" << endl;
			outfile << "\t\t\t\tv-on:change='updateEng([\"contiac\"])'" << endl;
			outfile << "\t\t\t\t:label=\"tag." << baseconsref << "\"" << endl;
			if (con->Active != "") outfile << "\t\t\t\t:disabled=\"!statshr." << baseconsref << "Active\"" << endl;
			outfile << "\t\t\t/>" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::CUS) {
			s = "100";
			dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(basecon->ref, "height", 0, s);

			outfile << "\t\t\t<div" << endl;
			if (con->Avail != "") outfile << "\t\t\t\tv-if=\"statshr." << baseconsref << "Avail\"" << endl;
			outfile << "\t\t\t\tclass=\"my-2\"" << endl;
			outfile << "\t\t\t\tstyle=\"height:" << s << "px\"" << endl;
			outfile << "\t\t\t>" << endl;
			outfile << "\t\t\t\t<!-- IP div" << baseconshort << " - INSERT -->" << endl;
			outfile << "\t\t\t</div>" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::DLD) {
			other = true;

		} else if (cplxtype == Concplxtype::HDG) {
			outfile << "\t\t\t<h3" << endl;
			if (con->Avail != "") outfile << "\t\t\t\tv-if=\"statshr." << baseconsref << "Avail\"" << endl;
			outfile << "\t\t\t\tclass=\"text-5 my-2\"" << endl;
			outfile << "\t\t\t>" << endl;
			outfile << "\t\t\t\t{{tag." << baseconsref << "}}" << endl;
			outfile << "\t\t\t</h3>" << endl;
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
			outfile << "\t\t\t<v-select" << endl;
			if (con->Avail != "") outfile << "\t\t\t\tv-if=\"statshr." << baseconsref << "Avail\"" << endl;
			outfile << "\t\t\t\tclass=\"my-2\"" << endl;
			outfile << "\t\t\t\tv-model=\"contapp.fiF" << baseconsref << "\"" << endl;
			outfile << "\t\t\t\t:items=\"FeedF" << baseconsref << "\"" << endl;
			outfile << "\t\t\t\t:label='tag.Cpt" << baseconshort << "'" << endl;
			outfile << "\t\t\t\tv-on:change=\"handlePupChange('numF" << baseconsref << "', fiF" << baseconsref << ")\"" << endl;
			if (con->Active != "") outfile << "\t\t\t\t:disabled=\"!statshr." << baseconsref << "Active\"" << endl;
			outfile << "\t\t\t>" << endl;
			outfile << "\t\t\t\t<template v-slot:selection=\"{item}\">{{item.tit1}}</template>" << endl;
			outfile << "\t\t\t\t<template v-slot:item=\"{item}\">{{item.tit1}}</template>" << endl;
			outfile << "\t\t\t</v-select>" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::PUP_PUP) {
			other = true;

		} else if (cplxtype == Concplxtype::PUP_TXFALT) {
			other = true;

		} else if (cplxtype == Concplxtype::PUP_VBAR) {
			other = true;

		} else if (cplxtype == Concplxtype::SEP) {
			outfile << "\t\t\t<v-divider";
			if (con->Avail != "") outfile << " v-if\"statshr." << baseconsref << "Avail\"";
			outfile << "/>" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::SLD) {
			outfile << "\t\t\t<v-slider" << endl;
			if (con->Avail != "") outfile << "\t\t\t\tv-if=\"statshr." << baseconsref << "Avail\"" << endl;
			outfile << "\t\t\t\tclass=\"my-2\"" << endl;
			outfile << "\t\t\t\tv-model=\"contiac." << baseconsref << "\"" << endl;
			outfile << "\t\t\t\tv-on:end='updateEng([\"contiac\"])'" << endl;
			outfile << "\t\t\t\t:label=\"tag.Cpt" << baseconshort << "\"" << endl;
			outfile << "\t\t\t\t:min=\"statshr." << baseconsref << "Min\"" << endl;
			outfile << "\t\t\t\t:max=\"statshr." << baseconsref << "Max\"" << endl;
			if (con->Active != "") outfile << "\t\t\t\t:disabled=\"!statshr." << baseconsref << "Active\"" << endl;
			outfile << "\t\t\t>" << endl;
			outfile << "\t\t\t\t<template v-slot:append>" << endl;
			outfile << "\t\t\t\t\t<v-text-field" << endl;
			outfile << "\t\t\t\t\t\tv-model=\"contiac." << baseconsref << "\"" << endl;
			outfile << "\t\t\t\t\t\tv-on:change='updateEng([\"contiac\"])'" << endl;
			outfile << "\t\t\t\t\t\tclass=\"mt-0 pt-0\"" << endl;
			outfile << "\t\t\t\t\t\thide-details" << endl;
			outfile << "\t\t\t\t\t\tsingle-line" << endl;
			outfile << "\t\t\t\t\t\ttype=\"number\"" << endl;
			outfile << "\t\t\t\t\t\tstyle=\"width: 80px\"" << endl;
			outfile << "\t\t\t\t\t/>" << endl;
			outfile << "\t\t\t\t</template>" << endl;
			outfile << "\t\t\t</v-slider>" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::SPC) {
			other = true;

		} else if (cplxtype == Concplxtype::TXF) {
			outfile << "\t\t\t<v-text-field" << endl;
			if (con->Avail != "") outfile << "\t\t\t\tv-if=\"statshr." << baseconsref << "Avail\"" << endl;
			outfile << "\t\t\t\tclass=\"my-2\"" << endl;
			outfile << "\t\t\t\tv-model=\"" << baseconsref << "\"" << endl;
			outfile << "\t\t\t\t:label=\"tag.Cpt" << baseconshort << "\"" << endl;
			if (con->Active != "") outfile << "\t\t\t\t:disabled=\"!statshr." << baseconsref << "Active\"" << endl;
			outfile << "\t\t\t/>" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::TXT) {
			outfile << "\t\t\t<v-text-field" << endl;
			if (con->Avail != "") outfile << "\t\t\t\tv-if=\"statshr." << baseconsref << "Avail\"" << endl;
			outfile << "\t\t\t\tclass=\"my-2\"" << endl;
			outfile << "\t\t\t\treadonly" << endl;
			outfile << "\t\t\t\toutlined" << endl;
			outfile << "\t\t\t\tv-model=\"continf." << baseconsref << "\"" << endl;
			outfile << "\t\t\t\t:label=\"tag.Cpt" << baseconshort << "\"" << endl;
			outfile << "\t\t\t/>" << endl;
			outfile << endl;

		} else if (cplxtype == Concplxtype::TXT_PUP) {
			other = true;

		} else if (cplxtype == Concplxtype::TXT_TXFALT) {
			other = true;

		} else if (cplxtype == Concplxtype::ULD) {
			other = true;

		} else if (cplxtype == Concplxtype::UPD) {
			other = true;
		};

		if (other) {
			// preliminary: manual implementation
			outfile << "\t\t\t<div" << endl;
			if (con->Avail != "") outfile << "\t\t\t\tv-if=\"statshr." << baseconsref << "Avail\"" << endl;
			outfile << "\t\t\t\tclass=\"my-2\"" << endl;
			outfile << "\t\t\t>" << endl;
			outfile << "\t\t\t\t<!-- IP div" << baseconshort << " - INSERT -->" << endl;
			outfile << "\t\t\t</div>" << endl;
			outfile << endl;
		};
	};

	outfile << "<!-- IP cont - IEND -->" << endl;

	// --- mergeDpchEngData
	outfile << "<!-- IP mergeDpchEngData - IBEGIN -->" << endl;
	outfile << "\t\t\t\t*/" << endl;

	// cf. WznmWrweb::wrSrcblksJs

	ubigint ref;

	ListWznmMBlock dpchs;
	WznmMBlock* dpch = NULL;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ListWznmAMBlockItem bit2s;
	WznmAMBlockItem* bit2 = NULL;

	WznmMTable* tbl = NULL;
	WznmMBlock* blk = NULL;

	set<string> srefFis, srefButons;

	bool first;

	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB)
				+ " AND refUref = " + to_string(pnl->refWznmMJob) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") = " + to_string(VecWznmWScope::APP), false, dpchs);

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(pnl->refWznmMJob)
				+ " AND sref = 'DpchEng" + pnl->sref.substr(3) + "Data'", ref)) dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, bits);

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
			outfile << "\t\t\t\tif (dpcheng." << bit->sref << ") this." << bit->sref << " = dpcheng." << bit->sref << ";" << endl;

		} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
			if (dbswznm->tblwznmmtable->loadRecByRef(bit->refWznmMTable, &tbl)) {
				outfile << "\t\t\t\tif (dpcheng.List" << tbl->sref.substr(3) << ") this." << bit->sref << " = dpcheng.List" << tbl->sref.substr(3) << ";" << endl;
				delete tbl;
			};

		} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
			if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &blk)) {
				if (blk->ixVBasetype == VecWznmVMBlockBasetype::TAG) {
					outfile << "\t\t\t\tif (dpcheng." << blk->sref << ") {" << endl;
					outfile << "\t\t\t\t\t" << Prjshort << ".unescapeBlock(dpcheng." << blk->sref << ");" << endl;
					outfile << "\t\t\t\t\tthis." << bit->sref << " = dpcheng." << blk->sref << ";" << endl;
					outfile << "\t\t\t\t};" << endl;

				} else outfile << "\t\t\t\tif (dpcheng." << blk->sref << ") this." << bit->sref << " = dpcheng." << blk->sref << ";" << endl;

				delete blk;
			};
		};
	};

	// preliminary: analyze contiac and continf for items that mandate special treatment
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
			if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &blk)) {
				if (blk->ixVBasetype == VecWznmVMBlockBasetype::CONT) {
					dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bit2s);

					if (blk->sref.find("ContIac") == 0) {
						for (unsigned int j = 0; j < bit2s.nodes.size(); j++) {
							bit2 = bit2s.nodes[j];
							if (bit2->sref.find("numFPup") == 0) srefFis.insert(bit2->sref);
						};

					} else if (blk->sref.find("ContInf") == 0) {
						for (unsigned int j = 0; j < bit2s.nodes.size(); j++) {
							bit2 = bit2s.nodes[j];
							if ((bit2->sref.find("But") == 0) && ((bit2->sref.rfind("On") + 2) == bit2->sref.length())) srefButons.insert(bit2->sref);
						};
					};
				};

				delete blk;
			};
		};
	};

	if (!srefFis.empty()) {
		outfile << endl;

		outfile << "\t\t\t\tif (dpcheng.ContIac" << pnl->sref.substr(3) << ") {" << endl;

		for (auto it = srefFis.begin(); it != srefFis.end(); it++) {
			outfile << "\t\t\t\t\tfor (var i = 0; i < this.Feed" << (*it).substr(3) << ".length; i++)" << endl;
			outfile << "\t\t\t\t\t\tif (this.Feed" << (*it).substr(3) << "[i].num == this.contiac." << (*it) << ") {" << endl;
			outfile << "\t\t\t\t\t\t\tthis.contapp.fi" << (*it).substr(3) << " = this.Feed" << (*it).substr(3) << "[i];" << endl;
			outfile << "\t\t\t\t\t\t\tbreak;" << endl;
			outfile << "\t\t\t\t\t\t}" << endl;
		};

		outfile << "\t\t\t\t}" << endl;
	};

	if (!srefButons.empty()) {
		outfile << endl;

		outfile << "\t\t\t\tif (dpcheng.ContInf" << pnl->sref.substr(3) << ") {" << endl;

		for (auto it = srefButons.begin(); it != srefButons.end(); it++) {
			outfile << "\t\t\t\t\tif (!this.continf." << (*it) << ") this.contapp." << (*it) << " = 0;" << endl;
			outfile << "\t\t\t\t\telse this.contapp." << (*it) << " = 1;" << endl;
		};

		outfile << "\t\t\t\t}" << endl;
	};

	outfile << "\t\t\t\t/*" << endl;
	outfile << "<!-- IP mergeDpchEngData - IEND -->" << endl;

	// --- dpchhdls
	outfile << "<!-- IP dpchhdls - IBEGIN -->" << endl;
	outfile << "\t\t\t*/" << endl;

	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		if (dpch->sref.compare("DpchEng" + pnl->sref.substr(3) + "Data") != 0) {
			outfile << endl;

			outfile << "\t\t\thandleDpchEng" << dpch->sref.substr(4+3+pnl->sref.substr(3).length()) << ": function(dpcheng) {" << endl;
			outfile << "\t\t\t\t/*" << endl;
			outfile << "\t\t\t\t<!-- IP handleDpchEng" << dpch->sref.substr(4+3+pnl->sref.substr(3).length()) << " - INSERT -->" << endl;
			outfile << "\t\t\t\t*/" << endl;
			outfile << "\t\t\t}," << endl;
		};
	};

	outfile << "\t\t\t/*" << endl;
	outfile << "<!-- IP dpchhdls - IEND -->" << endl;

	// --- handleUpdate
	outfile << "<!-- IP handleUpdate - IBEGIN -->" << endl;
	outfile << "\t\t\t\t*/" << endl;

	for (unsigned int i = 0; i < dpchs.nodes.size(); i++) {
		dpch = dpchs.nodes[i];

		outfile << "\t\t\t\t";
		if (i != 0) outfile << "else ";
		outfile << "if (obj.srefIx" << Prjshort << "VDpch == \"" << dpch->sref << "\") this.";
		if (dpch->sref.compare("DpchEng" + pnl->sref.substr(3) + "Data") == 0) outfile << "mergeDpchEngData";
		else outfile << "handleDpchEng" << dpch->sref.substr(4+3+pnl->sref.substr(3).length());
		outfile << "(obj.dpcheng);" << endl;
	};

	outfile << "\t\t\t\t/*" << endl;
	outfile << "<!-- IP handleUpdate - IEND -->" << endl;

	// --- data
	outfile << "<!-- IP data - IBEGIN -->" << endl;
	outfile << "\t\t\t*/" << endl;

	if (!srefFis.empty() || !srefButons.empty()) {
		outfile << "\t\t\tcontapp: {" << endl;

		first = true;

		for (auto it = srefFis.begin(); it != srefFis.end(); it++) {
			if (first) first = false;
			else outfile << endl;
			outfile << "\t\t\t\tfi" << (*it).substr(3) << ": null," << endl;
		};

		for (auto it = srefButons.begin(); it != srefButons.end(); it++) {
			if (first) first = false;
			else outfile << endl;
			outfile << "\t\t\t\t" << (*it) << ": 0," << endl;
		};

		outfile << "\t\t\t}," << endl;
		outfile << endl;
	};

	first = true;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) || (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) || (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB)) {
			if (first) first = false;
			else outfile << endl;

			outfile << "\t\t\t" << bit->sref << ": null," << endl;
		};
	};

	outfile << "\t\t\t/*" << endl;
	outfile << "<!-- IP data - IEND -->" << endl;
};
// IP cust --- IEND
