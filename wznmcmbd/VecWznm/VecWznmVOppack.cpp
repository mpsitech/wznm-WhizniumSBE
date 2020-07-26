/**
	* \file VecWznmVOppack.cpp
	* vector VecWznmVOppack (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
	if (s == "wznmwrdbs") return WZNMWRDBS;
	if (s == "wznmwrjapi") return WZNMWRJAPI;
	if (s == "wznmwrsrv") return WZNMWRSRV;
	if (s == "wznmwrweb") return WZNMWRWEB;

	return(0);
};

string VecWznmVOppack::getSref(
			const uint ix
		) {
	if (ix == WZNMCOMPL) return("WznmCompl");
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
	if (ix == WZNMWRDBS) return("WznmWrdbs");
	if (ix == WZNMWRJAPI) return("WznmWrjapi");
	if (ix == WZNMWRSRV) return("WznmWrsrv");
	if (ix == WZNMWRWEB) return("WznmWrweb");

	return("");
};

string VecWznmVOppack::getTitle(
			const uint ix
		) {
	if (ix == WZNMCOMPL) return("complement");
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
	if (ix == WZNMWRDBS) return("write database access code");
	if (ix == WZNMWRJAPI) return("write Java API code");
	if (ix == WZNMWRSRV) return("write server code");
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

	for (unsigned int i = 1; i <= 15; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

