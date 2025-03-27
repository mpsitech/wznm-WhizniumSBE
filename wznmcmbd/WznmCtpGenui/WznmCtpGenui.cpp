/**
	* \file WznmCtpGenui.cpp
	* Wznm operation pack global code (implementation)
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

#include "WznmCtpGenui.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenui
 ******************************************************************************/

// IP cust --- IBEGIN
void WznmCtpGenui::addCjttag(
			DbsWznm* dbswznm
			, WznmMControl* con
			, const ubigint refWznmMCapability
			, const string& sref
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
			, const string& plhstr // ex. "&tag; &plh;"
			, const map<ubigint,string>& plhs
			, const bool esc
		) {
	// if the tag can be found, it is ensured that tagTits receives one entry for each ref in refsLcl
	ubigint ref;

	WznmMTag* tag = NULL;

	map<ubigint, string> tagTits;

	string s;

	if (dbswznm->tblwznmmtag->loadRecByCpbSrfGrp(refWznmMCapability, sref, "", &tag)) {
		dbswznm->tblwznmjmtagtitle->loadTitByTagLoc(tag->ref, refLcl, tag->Title);

		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			s = tag->Title;

			dbswznm->tblwznmjmtagtitle->loadTitByTagLoc(tag->ref, refsLcl[i], s);

			if (plhstr != "") {
				s = StrMod::replacePlh(plhstr, "tag", s);
				s = StrMod::replacePlh(s, "plh", getPlhByLcl(plhs, refsLcl[i], refLcl));
			};

			if (esc) tagTits[refsLcl[i]] = StrMod::esc(s);
			else tagTits[refsLcl[i]] = s;
		};

		delete tag;
	};

	if (!tagTits.empty()) {
		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			s = StrMod::cap(tagTits[refsLcl[i]]);
			ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refsLcl[i], s);

			if (refsLcl[i] == refLcl) {
				con->refJTitle = ref;
				con->Title = s;

				dbswznm->tblwznmmcontrol->updateRec(con);
			};
		};

	} else {
		ref = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, sref);
		con->refJTitle = ref;
		con->Title = sref;
		dbswznm->tblwznmmcontrol->updateRec(con);
	};
};

string WznmCtpGenui::getPlhByLcl(
			const map<ubigint,string>& plhs // by refLcl
			, const ubigint refLcl
			, const ubigint refLclDefault
		) {
	auto it = plhs.find(refLcl);
	if (it != plhs.end()) return it->second;

	it = plhs.find(refLclDefault);
	if (it != plhs.end()) return it->second;

	return "";
};
// IP cust --- IEND
