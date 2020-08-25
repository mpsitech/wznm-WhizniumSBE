/**
	* \file WznmCtpWrstkit.cpp
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

#include "WznmCtpWrstkit.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmCtpWrstkit
 ******************************************************************************/

// IP cust --- IBEGIN
void WznmCtpWrstkit::addIJMModules(
			DbsWznm* dbswznm
			, IexWznmBui::ImeitemIMModule* mdl
			, const string& sref
			, const string& osrefWznmKTaggrp
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	map<ubigint,string> tagTits;

	WznmMLocale* lcl = NULL;

	Wznm::getTagtits(dbswznm, sref, osrefWznmKTaggrp, "", {}, refLcl, refsLcl, tagTits, false);

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];
		mdl->imeijmmodule.nodes.push_back(new IexWznmBui::ImeitemIJMModule(lcl->sref, tagTits[lcl->ref], ""));
	};
};

void WznmCtpWrstkit::addIAMTableTitles(
			DbsWznm* dbswznm
			, IexWznmDbs::ImeitemIMTable* tbl
			, const string& sref
			, const uint ixVType
			, const string& osrefWznmKTaggrp
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	map<ubigint,string> tagTits;

	WznmMLocale* lcl = NULL;

	vector<string> ss;

	Wznm::getTagtits(dbswznm, sref + "." + VecWznmVAMTableTitleType::getSref(ixVType), osrefWznmKTaggrp, "", {}, refLcl, refsLcl, tagTits, false);

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];

		StrMod::stringToVector(tagTits[lcl->ref], ss);
		if (ss.size() == 2) tbl->imeiamtabletitle.nodes.push_back(new IexWznmDbs::ImeitemIAMTableTitle(ixVType, lcl->sref, VecWznmVGender::getIx(ss[0]), ss[1]));
	};
};

void WznmCtpWrstkit::addIAMTablecolTitles(
			DbsWznm* dbswznm
			, IexWznmDbs::ImeitemIMTablecol* tco
			, const string& sref
			, const uint ixVType
			, const string& osrefWznmKTaggrp
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	map<ubigint,string> tagTits;

	WznmMLocale* lcl = NULL;

	if (osrefWznmKTaggrp == "stdtco") Wznm::getTagtits(dbswznm, sref + "." + VecWznmVAMTablecolTitleType::getSref(ixVType), "stdtco", "", {}, refLcl, refsLcl, tagTits, false);
	else Wznm::getTagtits(dbswznm, sref, osrefWznmKTaggrp, "", {}, refLcl, refsLcl, tagTits, false);

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];
		tco->imeiamtablecoltitle.nodes.push_back(new IexWznmDbs::ImeitemIAMTablecolTitle(ixVType, lcl->sref, tagTits[lcl->ref]));
	};
};

void WznmCtpWrstkit::addIAMVectorTitles(
			DbsWznm* dbswznm
			, IexWznmDbs::ImeitemIMVector2* vec
			, const string& sref
			, const uint ixVType
			, const string& osrefWznmKTaggrp
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	map<ubigint,string> tagTits;

	WznmMLocale* lcl = NULL;

	Wznm::getTagtits(dbswznm, sref, osrefWznmKTaggrp, "", {}, refLcl, refsLcl, tagTits, false);

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];
		vec->imeiamvectortitle2.nodes.push_back(new IexWznmDbs::ImeitemIAMVectorTitle2(ixVType, lcl->sref, tagTits[lcl->ref]));
	};
};

void WznmCtpWrstkit::addIJMVectoritems(
			DbsWznm* dbswznm
			, IexWznmDbs::ImeitemIMVectoritem2* vit
			, const string& sref
			, const string& osrefWznmKTaggrp
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	map<ubigint,string> tagTits;

	WznmMLocale* lcl = NULL;

	vector<string> ss;

	Wznm::getTagtits(dbswznm, sref, osrefWznmKTaggrp, "", {}, refLcl, refsLcl, tagTits, false);

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];

		StrMod::stringToVector(tagTits[lcl->ref], ss);
		if (ss.size() > 0) vit->imeijmvectoritem2.nodes.push_back(new IexWznmDbs::ImeitemIJMVectoritem2(lcl->sref, ss[ss.size()-1], ""));
	};
};

void WznmCtpWrstkit::addIAMRelationTitles(
			DbsWznm* dbswznm
			, IexWznmDbs::ImeitemIMRelation* rel
			, const string& sref
			, const uint ixVType
			, const string& osrefWznmKTaggrp
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	map<ubigint,string> tagTits;

	WznmMLocale* lcl = NULL;

	if (osrefWznmKTaggrp == "stdrel") Wznm::getTagtits(dbswznm, sref + "." + VecWznmVAMRelationTitleType::getSref(ixVType), "stdrel", "", {}, refLcl, refsLcl, tagTits, false);
	else Wznm::getTagtits(dbswznm, sref, osrefWznmKTaggrp, "", {}, refLcl, refsLcl, tagTits, false);

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];
		rel->imeiamrelationtitle.nodes.push_back(new IexWznmDbs::ImeitemIAMRelationTitle(ixVType, lcl->sref, tagTits[lcl->ref]));
	};
};

void WznmCtpWrstkit::addIJMImpexpcplxTitles(
			DbsWznm* dbswznm
			, IexWznmIex::ImeitemIMImpexpcplx* iex
			, const string& sref
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	map<ubigint,string> tagTits;

	WznmMLocale* lcl = NULL;

	Wznm::getTagtits(dbswznm, sref, "stdiex", "", {}, refLcl, refsLcl, tagTits, false);

	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];
		iex->imeijmimpexpcplxtitle.nodes.push_back(new IexWznmIex::ImeitemIJMImpexpcplxTitle(lcl->sref, tagTits[lcl->ref]));
	};
};
// IP cust --- IEND


