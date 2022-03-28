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

	//
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
		Wznm::getTagtits(dbswznm, tag->sref, "start", "", {}, refLcl, refsLcl, *lclTits, false);
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

	bool first;

	// --- cars
	outfile << "<!-- IP cars - IBEGIN -->" << endl;
	outfile << "\t*/" << endl;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->sref.substr(3+4).compare("Nav") != 0) outfile << "\timport " << car->sref << " from './" << car->sref << "/" << car->sref << "';" << endl;
	};

	outfile << "\t/*" << endl;
	outfile << "<!-- IP cars - IEND -->" << endl;

	// --- components
	outfile << "<!-- IP components - IBEGIN -->" << endl;
	outfile << "\t\t\t*/" << endl;

	first = true;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->sref.substr(3+4).compare("Nav") != 0) {
			if (first) first = false;
			else outfile << "," << endl;

			outfile << "\t\t\t" << car->sref;
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
	map<string, unsigned int> icsCars; // by Crdshort
	WznmMCard* car = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	ListWznmMControl con2s;
	WznmMControl* con2 = NULL;

	ubigint refMdl = 0;

	string action;

	string s;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) icsCars[cars.nodes[i]->sref.substr(3+4)] = i;

	// --- mits
	outfile << "<!-- IP mits - IBEGIN -->" << endl;

	auto it = icsCars.find("Nav");
	if (it != icsCars.end()) dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(cars.nodes[it->second]->ref)
			+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::MEN) + " ORDER BY hkNum ASC", false, cons);

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (i != 0) {
			outfile << "\t\t<v-divider/>" << endl;
			outfile << endl;
		};

		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(con->ref) + " ORDER BY hkNum ASC", false, con2s);

		for (unsigned int j = 0; j < con2s.nodes.size(); j++) {
			con2 = con2s.nodes[j];

			if ((con2->ixVScope == VecWznmVMControlScope::SHR) && (con2->ixVBasetype == VecWznmVMControlBasetype::MIT)) {
				dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con2->ref, "action", 0, action);

				if (action == "crdopen") {
					it = icsCars.find(con2->sref.substr(3+3));

					if (it != icsCars.end()) {
						car = cars.nodes[it->second];

						// preliminary: use principal locale as module header
						if (car->mdlRefWznmMModule != refMdl) {
							if (dbswznm->loadStringBySQL("SELECT Title FROM TblWznmMModule WHERE ref = " + to_string(car->mdlRefWznmMModule), s)) {
								outfile << "\t\t<v-list-item small disabled dense>" << endl;
								outfile << "\t\t\t<v-list-item-content>" << endl;
								outfile << "\t\t\t\t<v-list-item-title class=\"overline\">" << StrMod::cap(s) << "</v-list-item-title>" << endl;
								outfile << "\t\t\t</v-list-item-content>" << endl;
								outfile << "\t\t</v-list-item>" << endl;
								outfile << endl;
							};

							refMdl = car->mdlRefWznmMModule;
						};
					};
				};

				outfile << "\t\t<v-list-item" << endl;
				if (con2->Avail != "") outfile << "\t\t\tv-if=\"statshr." << con2->sref << "Avail\"" << endl;
				outfile << "\t\t\tactive-class=\"primary--text\"" << endl;
				outfile << "\t\t\tv-on:click=\"";
				if (action == "crdopen") outfile << "handleMitCrdopenClick";
				else outfile << "handleMitClick";
				outfile << "('" << con2->sref << "Click')\"" << endl;
				if (con2->Active != "") outfile << "\t\t\t:disabled=\"statshr." << con2->sref << "Active\"" << endl;
				outfile << "\t\t>" << endl;
				outfile << "\t\t\t<v-list-item-content>" << endl;
				outfile << "\t\t\t\t<v-list-item-title>{{tag." << con2->sref << "}}</v-list-item-title>" << endl;
				outfile << "\t\t\t</v-list-item-content>" << endl;

				if (con2->sref == "MitSesTrm") {
					// preliminary: session information as tooltip
					outfile << "\t\t\t<v-tooltip right>" << endl;
					outfile << "\t\t\t\t<template v-slot:activator=\"{on,attrs}\">" << endl;
					outfile << "\t\t\t\t\t<v-list-item-icon>" << endl;
					outfile << "\t\t\t\t\t\t<v-icon v-bind=\"attrs\" v-on=\"on\">mdi-information-outline</v-icon>" << endl;
					outfile << "\t\t\t\t\t</v-list-item-icon>" << endl;
					outfile << "\t\t\t\t</template>" << endl;
					outfile << "\t\t\t\t{{continf.MtxSesSes1 + \" \" + continf.MtxSesSes2 + \" \" + continf.MtxSesSes3}}" << endl;
					outfile << "\t\t\t</v-tooltip>" << endl;
				};

				outfile << "\t\t</v-list-item>" << endl;
				outfile << endl;
			};
		};
	};
	outfile << "<!-- IP mits - IEND -->" << endl;
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

		if (car->sref.substr(3+4).compare("Nav") != 0) {
			outfile << "mkdir $WEBROOT/vueapp" << prjshort << "/src/components/" << car->sref << endl;
			outfile << endl;

			outfile << "cp ../../vueapp" << prjshort << "/" << car->sref << "/*.vue $WEBROOT/vueapp" << prjshort << "/src/components/" << car->sref << "/" << endl;
			outfile << endl;
		};
	};

	outfile << "# IP cp.cars --- IEND" << endl;
};
// IP cust --- IEND
