/**
	* \file WznmWrwebBase.cpp
	* Wznm operation processor - write web UI JS/HTML code basics (implementation)
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

#include "WznmWrwebBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrweb;

/******************************************************************************
 namespace WznmWrwebBase
 ******************************************************************************/

DpchRetWznm* WznmWrwebBase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrwebBase* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMLocale lcls;

	fstream outfile;

	string s;

	Wznm::getVerlcls(dbswznm, refWznmMVersion, refLcl, refsLcl, lcls);

	// CrdXxxxStart_src.xml
	s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + "Start/Crd" + Prjshort + "Start_src.xml.ip";
	outfile.open(s.c_str(), ios::out);
	writeCssrcXmfile(dbswznm, outfile, Prjshort, refLcl, refsLcl, lcls);
	outfile.close();
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrwebBase::writeCssrcXmfile(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	WznmMLocale* lcl = NULL;
	WznmMLocale* lcl2 = NULL;

	ListWznmMTag tags;
	WznmMTag* tag = NULL;

	map<ubigint, map<ubigint,string>* > tagLclTits; // by refTag then refLcl
	map<ubigint,string>* lclTits = NULL;

	string s;

	// --- feedlcls
	outfile << "<!-- IP feedlcls - IBEGIN -->" << endl;
	
	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];

		outfile << "\t\t\t<FeedFPupLoginLocale." << lcl->sref << ">" << endl;

		for (unsigned int j = 0; j < lcls.nodes.size(); j++) {
			lcl2 = lcls.nodes[j];

			outfile << "\t\t\t\t<Fi num=\"" << (j+1) << "\">" << endl;
			outfile << "\t\t\t\t\t<sref>" << lcl2->sref << "</sref>" << endl;

			outfile << "\t\t\t\t\t<tit1>";
			if (dbswznm->tblwznmjmlocaletitle->loadTitByLocLo2(lcl2->ref, lcl->ref, s)) outfile << s;
			else outfile << lcl2->Title;
			outfile << "</tit1>" << endl;

			outfile << "\t\t\t\t</Fi>" << endl;
		};

		outfile << "\t\t\t</FeedFPupLoginLocale." << lcl->sref << ">" << endl;
	};

	outfile << "<!-- IP feedlcls - IEND -->" << endl;

	// --- tags
	dbswznm->tblwznmmtag->loadRstByGrp("start", false, tags);

	for (unsigned int i = 0; i < tags.nodes.size(); i++) {
		tag = tags.nodes[i];

		lclTits = new map<ubigint,string>;
		Wznm::getTagtits(dbswznm, tag->sref, "start", "", {}, refLcl, refsLcl, *lclTits, false);
		tagLclTits[tag->ref] = lclTits;
	};

	outfile << "<!-- IP tags - IBEGIN -->" << endl;

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];

		outfile << "\t\t\t<Tag." << lcl->sref << ">" << endl;

		for (unsigned int j = 0; j < tags.nodes.size(); j++) {
			tag = tags.nodes[j];
			outfile << "\t\t\t\t<Ti sref=\"" << tag->sref << "\">" << tagLclTits[tag->ref]->at(lcl->ref) << "</Ti>" << endl;
		};

		outfile << "\t\t\t</Tag." << lcl->sref << ">" << endl;
	};

	outfile << "<!-- IP tags - IEND -->" << endl;

	for (auto it = tagLclTits.begin(); it != tagLclTits.end(); it++) delete (*it).second;
};
// IP cust --- IEND
