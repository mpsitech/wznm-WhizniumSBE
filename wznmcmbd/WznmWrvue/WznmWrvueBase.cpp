/**
	* \file WznmWrvueBase.cpp
	* Wznm operation processor - write Vue.js UI Vue code basics (implementation)
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

#include "WznmWrvueBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrvue;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrvueBase
 ******************************************************************************/

DpchRetWznm* WznmWrvueBase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrvueBase* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream vuefile;

	vector<ubigint> refs;

	ListWznmMCard cars;

	string s;

	fstream shfile;

	// cards
	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);

	// main_Vue.js, Xxxx_Vue.js, AppXxxx.vue, checkin_Vue.sh: plh only

	// CrdXxxxStart.vue
	s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + "Start/Crd" + Prjshort + "Start.vue.ip";
	vuefile.open(s.c_str(), ios::out);
	writeCsVue(dbswznm, vuefile, refWznmMVersion, Prjshort);
	vuefile.close();

	// SessXxxx.vue
	s = xchg->tmppath + "/" + folder + "/Sess" + Prjshort + ".vue.ip";
	vuefile.open(s.c_str(), ios::out);
	writeSessVue(dbswznm, vuefile, refWznmMVersion, Prjshort, cars);
	vuefile.close();

	// CrdXxxxNav.vue
	s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + "Nav/Crd" + Prjshort + "Nav.vue.ip";
	vuefile.open(s.c_str(), ios::out);
	writeCrdnavVue(dbswznm, vuefile, refWznmMVersion, Prjshort, cars);
	vuefile.close();

	// - this becomes WznmWrvueDeploy
	folder += "/../_rls/vueapp" + StrMod::lc(Prjshort) + "_any";

	// checkout_Vue.sh
	s = xchg->tmppath + "/" + folder + "/checkout.sh.ip";
	shfile.open(s.c_str(), ios::out);
	writeChkoutSh(dbswznm, shfile, refWznmMVersion, Prjshort, cars);
	shfile.close();
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrvueBase::writeCsVue(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMLocale lcls;

	Wznm::getVerlcls(dbswznm, refWznmMVersion, refLcl, refsLcl, lcls);

	WznmMLocale* lcl = NULL;
	WznmMLocale* lcl2 = NULL;

	ListWznmMTag tags;
	WznmMTag* tag = NULL;

	map<ubigint, map<ubigint,string>* > tagLclTits; // by refTag then refLcl
	map<ubigint,string>* lclTits = NULL;

	string s;

	// --- feedFPupLocale
	outfile << "<!-- IP feedFPupLocale - IBEGIN -->" << endl;
	outfile << "\t\t\t\t*/" << endl;

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];
		outfile << "\t\t\t\tif (this.numFPupLocale == " << (i+1) << ") return this.feedFPupLocales." << lcl->sref << ";" << endl;
	};

	outfile << "\t\t\t\t/*" << endl;
	outfile << "<!-- IP feedFPupLocale - IEND -->" << endl;

	// --- tag
	outfile << "<!-- IP tag - IBEGIN -->" << endl;
	outfile << "\t\t\t\t*/" << endl;

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];
		outfile << "\t\t\t\tif (this.numFPupLocale == " << (i+1) << ") return this.tags." << lcl->sref << ";" << endl;
	};

	outfile << "\t\t\t\t/*" << endl;
	outfile << "<!-- IP tag - IEND -->" << endl;

	// --- feedlcls
	outfile << "<!-- IP feedlcls - IBEGIN -->" << endl;
	outfile << "\t\t\t*/" << endl;

	if (lcls.nodes.size() > 0) {
		lcl = lcls.nodes[0];

		outfile << "\t\t\tfiFPupLocale: {" << endl;
		outfile << "\t\t\t\tnum: 1," << endl;
		outfile << "\t\t\t\tsref: \"" << lcl->sref << "\"," << endl;
		outfile << "\t\t\t\ttit1: \"" << lcl->Title << "\"" << endl;
		outfile << "\t\t\t}," << endl;
		outfile << endl;
	};

	outfile << "\t\t\tfeedFPupLocales: {" << endl;

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];

		outfile << "\t\t\t\t" << lcl->sref << ": [" << endl;

		for (unsigned int j = 0; j < lcls.nodes.size(); j++) {
			lcl2 = lcls.nodes[j];

			outfile << "\t\t\t\t\t{" << endl;

			outfile << "\t\t\t\t\t\tnum: " << (j+1) << "," << endl;
			outfile << "\t\t\t\t\t\tsref: \"" << lcl2->sref << "\"," << endl;

			outfile << "\t\t\t\t\t\ttit1: \"";
			if (dbswznm->tblwznmjmlocaletitle->loadTitByLocLo2(lcl2->ref, lcl->ref, s)) outfile << s;
			else outfile << lcl2->Title;
			outfile << "\"" << endl;

			outfile << "\t\t\t\t\t}";
			if ((j+1) < lcls.nodes.size()) outfile << ",";
			outfile << endl;
		};

		outfile << "\t\t\t\t]";
		if ((i+1) < lcls.nodes.size()) outfile << ",";
		outfile << endl;
	};

	outfile << "\t\t\t}," << endl;

	outfile << "\t\t\t/*" << endl;
	outfile << "<!-- IP feedlcls - IEND -->" << endl;

	// --- tags
	outfile << "<!-- IP tags - IBEGIN -->" << endl;
	outfile << "\t\t\t\t*/" << endl;

	dbswznm->tblwznmmtag->loadRstByGrp("start", false, tags);

	for (unsigned int i = 0; i < tags.nodes.size(); i++) {
		tag = tags.nodes[i];

		lclTits = new map<ubigint,string>;
		Wznm::getTagtits(dbswznm, 0, tag->sref, "start", "", {}, refLcl, refsLcl, *lclTits, false);
		tagLclTits[tag->ref] = lclTits;
	};

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];

		outfile << "\t\t\t\t" << lcl->sref << ": {" << endl;

		for (unsigned int j = 0; j < tags.nodes.size(); j++) {
			tag = tags.nodes[j];
			outfile << "\t\t\t\t\t" << tag->sref << ": \"" << tagLclTits[tag->ref]->at(lcl->ref) << "\"";
			if ((j+1) < tags.nodes.size()) outfile << ",";
			outfile << endl;
		};

		outfile << "\t\t\t\t}";
		if ((i+1) < lcls.nodes.size()) outfile << ",";
		outfile << endl;
	};

	outfile << "\t\t\t\t/*" << endl;
	outfile << "<!-- IP tags - IEND -->" << endl;
};

void WznmWrvueBase::writeSessVue(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMCard& cars
		) {
	WznmMCard* car = NULL;

	ListWznmMDialog dlgs;
	WznmMDialog* dlg = NULL;

	bool first;

	// --- import
	outfile << "<!-- IP import - IBEGIN -->" << endl;
	outfile << "\t*/" << endl;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		outfile << "\timport " << car->sref << " from './" << car->sref << "/" << car->sref << "';" << endl;

		dbswznm->tblwznmmdialog->loadRstByCar(car->ref, false, dlgs);
		for (unsigned int j = 0; j < dlgs.nodes.size(); j++) {
			dlg = dlgs.nodes[j];
			outfile << "\timport " << dlg->sref << " from './" << car->sref << "/" << dlg->sref << "';" << endl;
		};
	};

	outfile << "\t/*" << endl;
	outfile << "<!-- IP import - IEND -->" << endl;

	// --- components
	outfile << "<!-- IP components - IBEGIN -->" << endl;
	outfile << "\t\t\t*/" << endl;

	first = true;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (first) first = false;
		else outfile << "," << endl;

		outfile << "\t\t\t" << car->sref;

		dbswznm->tblwznmmdialog->loadRstByCar(car->ref, false, dlgs);
		for (unsigned int j = 0; j < dlgs.nodes.size(); j++) {
			dlg = dlgs.nodes[j];

			if (first) first = false;
			else outfile << "," << endl;

			outfile << "\t\t\t" << dlg->sref;
		};
	};

	if (!first) outfile << endl;

	outfile << "\t\t\t/*" << endl;
	outfile << "<!-- IP components - IEND -->" << endl;
};

void WznmWrvueBase::writeCrdnavVue(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMCard& cars
		) {
	WznmMCard* car = NULL;
	WznmMCard* carnav = NULL;

	ListWznmMPanel pnls;
	WznmMPanel* pnl = NULL;

	WznmMPanel* pnlpre = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;
	WznmMControl* con2 = NULL;

	set<string> unqsrefs;

	string s;

	bool first, first2, found;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];
		
		if (car->sref.substr(3 + 4) == "Nav") {
			carnav = car;

			dbswznm->tblwznmmpanel->loadRstByCar(car->ref, false, pnls);
			for (unsigned int j = 0; j < pnls.nodes.size(); j++) {
				pnl = pnls.nodes[j];

				if (pnl->sref.rfind("Pre") == (3 + 4 + 3)) {
					pnlpre = pnl;
					break;
				};
			};
		};
	};

	// --- pre*
	if (pnlpre) outfile << "<!-- IP pre - AFFIRM -->" << endl;
	else outfile << "<!-- IP pre - REMOVE -->" << endl;

	// --- mergeDpchEngData
	wrIbegin(outfile, 4, "mergeDpchEngData");
	wrMergedpcheng(dbswznm, Prjshort, outfile, carnav->refWznmMJob);
	wrIend(outfile, 4, "mergeDpchEngData");

	// --- mergeDpchEngData.pnls
	wrIbegin(outfile, 3, "mergeDpchEngData.pnls");
	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE)) {
			outfile << "\t\t\tmergeDpchEngData_pnl" << StrMod::lc(pnl->sref.substr(3 + 4 + 3)) << ": function(dpcheng) {" << endl;
			wrMergedpcheng(dbswznm, Prjshort, outfile, pnl->refWznmMJob, "pnl" + StrMod::lc(pnl->sref.substr(3 + 4 + 3)), false);
			outfile << "\t\t\t}," << endl;
			outfile << endl;
		};
	};
	wrIend(outfile, 3, "mergeDpchEngData.pnls");

	// --- handleDpchAppInitReply
	wrIbegin(outfile, 5, "handleDpchAppInitReply");

	first = true;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE)) {
			outfile << "\t\t\t\t\t";

			if (first) first = false;
			else outfile << "} else ";

			outfile << "if (dpcheng.scrJref == this.statshr.scrJref" << pnl->sref.substr(3 + 4 + 3) << ") {" << endl;
			outfile << "\t\t\t\t\t\tthis.mergeDpchEngData_pnl" << StrMod::lc(pnl->sref.substr(3 + 4 + 3)) << "(dpcheng);" << endl;
			outfile << "\t\t\t\t\t\tthis.statapp.initdone" << pnl->sref.substr(3 + 4 + 3) << " = true;" << endl;
		};
	};

	outfile << "\t\t\t\t\t";
	if (!first) outfile << "} else ";

	outfile << "if (dpcheng.scrJref == this.content.scrJref) {" << endl;
	outfile << "\t\t\t\t\t\tthis.mergeDpchEngData_content(dpcheng);" << endl;
	outfile << "\t\t\t\t\t\tthis.content.initdone = true;" << endl;
	outfile << "\t\t\t\t\t}" << endl;
	outfile << endl;

	first = true;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE)) {
			outfile << "\t\t\t\t\t";

			if (first) first = false;
			else outfile << "else ";

			outfile << "if (!this.statapp.initdone" << pnl->sref.substr(3 + 4 + 3) << ") this.initOther(this.statshr.scrJref" << pnl->sref.substr(3 + 4 + 3) << ");" << endl;
		};
	};

	wrIend(outfile, 5, "handleDpchAppInitReply");

	// --- handleDpchAppDoReply.pre*
	if (pnlpre) outfile << "<!-- IP handleDpchAppDoReply.pre - AFFIRM -->" << endl;
	else outfile << "<!-- IP handleDpchAppDoReply.pre - REMOVE -->" << endl;

	// --- data
	wrIbegin(outfile, 3, "data");
	wrData(dbswznm, Prjshort, outfile, carnav->refWznmMJob);
	wrIend(outfile, 3, "data");

	// --- data.MenPre
	wrIbegin(outfile, 3, "data.MenPre");
	if (pnlpre) {
		dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnlpre->ref, false, cons);

		outfile << "\t\t\tMenPre: [";

		first = true;

		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->ixVBasetype == VecWznmVMControlBasetype::TXT) {
				if (first) first = false;
				else outfile << ", ";

				outfile << "\"" << con->sref.substr(3, 3) << "\"";
			};
		};
		outfile << "]," << endl;
	};
	wrIend(outfile, 3, "data.MenPre");

	// --- data.MenCrd
	wrIbegin(outfile, 3, "data.MenCrd");
	outfile << "\t\t\tMenCrd: [" << endl;

	dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::CAR, carnav->ref, false, cons);

	unqsrefs.clear();
	for (unsigned int i = 0; i < cons.nodes.size(); i++) if (cons.nodes[i]->sref.find("MitCrd") == 0) unqsrefs.insert(cons.nodes[i]->sref); 

	first = true;

	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) {
			if (first) first = false;
			else outfile << "," << endl;

			outfile << "\t\t\t\t{" << endl;
			outfile << "\t\t\t\t\tpnlsref: \"pnl" << StrMod::lc(pnl->sref.substr(3 + 4 + 3)) << "\"," << endl;			

			outfile << "\t\t\t\t\tmits: [";

			dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, cons);

			first2 = true;

			for (unsigned int j = 0; j < cons.nodes.size(); j++) {
				con = cons.nodes[j];

				if (con->ixVBasetype == VecWznmVMControlBasetype::CPT)
					if (unqsrefs.find("MitCrd" + con->sref.substr(3)) != unqsrefs.end()) {
						if (first2) first2 = false;
						else outfile << ", ";

						outfile << "\"MitCrd" << con->sref.substr(3) << "\"";
					};
			};

			outfile << "]" << endl;			
			outfile << "\t\t\t\t}";
		};
	};

	if (!first) outfile << endl;
	outfile << "\t\t\t]," << endl;
	wrIend(outfile, 3, "data.MenCrd");

	// --- data.pnls
	wrIbegin(outfile, 3, "data.pnls");
	for (unsigned int i = 0; i < pnls.nodes.size(); i++) {
		pnl = pnls.nodes[i];

		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE)) {
			outfile << "\t\t\tpnl" << StrMod::lc(pnl->sref.substr(3 + 4 + 3)) << ": {" << endl;
			if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) outfile << "\t\t\t\tstatshr: null" << endl;
			outfile << "\t\t\t}," << endl;
			outfile << endl;
		};
	};
	wrIend(outfile, 3, "data.pnls");

	// --- data.mbars
	wrIbegin(outfile, 3, "data.mbars");
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->sref.substr(3+4).compare("Nav") != 0) {
			outfile << "\t\t\tMbar" << car->sref.substr(3 + 4) << ": [" << endl;

			dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::CAR, car->ref, false, cons);

			first = true;

			for (unsigned int j = 0; j < cons.nodes.size(); j++) {
				con = cons.nodes[j];

				if ((con->ixVBasetype == VecWznmVMControlBasetype::MEN) && (con->sref != "MenApp")) {
					found = false;

					for (unsigned int k = 0; k < cons.nodes.size(); k++) {
						con2 = cons.nodes[k];

						if ((con2->supRefWznmMControl == con->ref) && (con2->ixVBasetype == VecWznmVMControlBasetype::MIT)) {
							found = true;
							break;
						};
					};

					if (found) {
						if (first) first = false;
						else outfile << "," << endl;

						outfile << "\t\t\t\t{" << endl;
						outfile << "\t\t\t\t\tsref: \"" << con->sref << "\"," << endl;

						outfile << "\t\t\t\t\tmits: [";

						first2 = true;

						for (unsigned int k = 0; k < cons.nodes.size(); k++) {
							con2 = cons.nodes[k];

							if ((con2->supRefWznmMControl == con->ref) && (con2->ixVBasetype == VecWznmVMControlBasetype::MIT)) {
								if (first2) first2 = false;
								else outfile << ", ";

								outfile << "\"" << con2->sref << "\"";
							};
						};

						outfile << "]" << endl;

						outfile << "\t\t\t\t}";
					};
				};
			};

			if (!first) outfile << endl;
			outfile << "\t\t\t]," << endl;
			outfile << endl;
		};
	};
	wrIend(outfile, 3, "data.mbars");
};

void WznmWrvueBase::writeChkoutSh(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMCard& cars
		) {
	WznmMCard* car = NULL;

	string prjshort = StrMod::lc(Prjshort);

	// --- cp.cars
	outfile << "# IP cp.cars --- IBEGIN" << endl;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		outfile << "mkdir $WEBROOT/vueapp" << prjshort << "/src/components/" << car->sref << endl;
		outfile << endl;

		outfile << "cp ../../vueapp" << prjshort << "/" << car->sref << "/*.vue $WEBROOT/vueapp" << prjshort << "/src/components/" << car->sref << "/" << endl;
		outfile << endl;
	};

	outfile << "# IP cp.cars --- IEND" << endl;
};
// IP cust --- IEND
