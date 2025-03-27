/**
	* \file VecWznmVOppack.cpp
	* vector VecWznmVOppack (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "VecWznmVOppack.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWznmVOppack
 ******************************************************************************/

uint VecWznmVOppack::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "wznmcompl") return WZNMCOMPL;
	if (s == "wznmcomplvis") return WZNMCOMPLVIS;
	if (s == "wznmctpgenjtr") return WZNMCTPGENJTR;
	if (s == "wznmctpgenui") return WZNMCTPGENUI;
	if (s == "wznmctpwrsrv") return WZNMCTPWRSRV;
	if (s == "wznmctpwrstkit") return WZNMCTPWRSTKIT;
	if (s == "wznmctpwrweb") return WZNMCTPWRWEB;
	if (s == "wznmgen") return WZNMGEN;
	if (s == "wznmprcfile") return WZNMPRCFILE;
	if (s == "wznmprctree") return WZNMPRCTREE;
	if (s == "wznmwrapi") return WZNMWRAPI;
	if (s == "wznmwrapp") return WZNMWRAPP;
	if (s == "wznmwrcsapi") return WZNMWRCSAPI;
	if (s == "wznmwrdbs") return WZNMWRDBS;
	if (s == "wznmwrjapi") return WZNMWRJAPI;
	if (s == "wznmwrpyapi") return WZNMWRPYAPI;
	if (s == "wznmwrsrv") return WZNMWRSRV;
	if (s == "wznmwrswapi") return WZNMWRSWAPI;
	if (s == "wznmwrvis") return WZNMWRVIS;
	if (s == "wznmwrvue") return WZNMWRVUE;
	if (s == "wznmwrweb") return WZNMWRWEB;

	return(0);
};

string VecWznmVOppack::getSref(
			const uint ix
		) {
	if (ix == WZNMCOMPL) return("WznmCompl");
	if (ix == WZNMCOMPLVIS) return("WznmComplvis");
	if (ix == WZNMCTPGENJTR) return("WznmCtpGenjtr");
	if (ix == WZNMCTPGENUI) return("WznmCtpGenui");
	if (ix == WZNMCTPWRSRV) return("WznmCtpWrsrv");
	if (ix == WZNMCTPWRSTKIT) return("WznmCtpWrstkit");
	if (ix == WZNMCTPWRWEB) return("WznmCtpWrweb");
	if (ix == WZNMGEN) return("WznmGen");
	if (ix == WZNMPRCFILE) return("WznmPrcfile");
	if (ix == WZNMPRCTREE) return("WznmPrctree");
	if (ix == WZNMWRAPI) return("WznmWrapi");
	if (ix == WZNMWRAPP) return("WznmWrapp");
	if (ix == WZNMWRCSAPI) return("WznmWrcsapi");
	if (ix == WZNMWRDBS) return("WznmWrdbs");
	if (ix == WZNMWRJAPI) return("WznmWrjapi");
	if (ix == WZNMWRPYAPI) return("WznmWrpyapi");
	if (ix == WZNMWRSRV) return("WznmWrsrv");
	if (ix == WZNMWRSWAPI) return("WznmWrswapi");
	if (ix == WZNMWRVIS) return("WznmWrvis");
	if (ix == WZNMWRVUE) return("WznmWrvue");
	if (ix == WZNMWRWEB) return("WznmWrweb");

	return("");
};

string VecWznmVOppack::getTitle(
			const uint ix
		) {
	if (ix == WZNMCOMPL) return("complement");
	if (ix == WZNMCOMPLVIS) return("complement visualization features");
	if (ix == WZNMCTPGENJTR) return("generate capability template-specific job tree");
	if (ix == WZNMCTPGENUI) return("generate capability template-specific user interface");
	if (ix == WZNMCTPWRSRV) return("write capability template-specific server code");
	if (ix == WZNMCTPWRSTKIT) return("write capability template-specific starter kit");
	if (ix == WZNMCTPWRWEB) return("write capability template-specific web UI code");
	if (ix == WZNMGEN) return("generate");
	if (ix == WZNMPRCFILE) return("process file");
	if (ix == WZNMPRCTREE) return("process file tree");
	if (ix == WZNMWRAPI) return("write API code");
	if (ix == WZNMWRAPP) return("write accessor app code");
	if (ix == WZNMWRCSAPI) return("write C# API code");
	if (ix == WZNMWRDBS) return("write database access code");
	if (ix == WZNMWRJAPI) return("write Java API code");
	if (ix == WZNMWRPYAPI) return("write Python API code");
	if (ix == WZNMWRSRV) return("write server code");
	if (ix == WZNMWRSWAPI) return("write Swift API code");
	if (ix == WZNMWRVIS) return("write visualization code");
	if (ix == WZNMWRVUE) return("write Vue.js UI code");
	if (ix == WZNMWRWEB) return("write web UI code");
	return(getSref(ix));

	return("");
};

string VecWznmVOppack::getComment(
			const uint ix
		) {

	return("");
};

void VecWznmVOppack::appendToFeed(
			const uint ix
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix));
};

void VecWznmVOppack::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 21; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};
