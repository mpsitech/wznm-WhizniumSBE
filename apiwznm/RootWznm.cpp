/**
	* \file RootWznm.cpp
	* API code for job RootWznm (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "RootWznm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class RootWznm::VecVSge
 ******************************************************************************/

uint RootWznm::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "sync") return SYNC;

	return(0);
};

string RootWznm::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == SYNC) return("sync");

	return("");
};

/******************************************************************************
 class RootWznm::DpchAppLogin
 ******************************************************************************/

RootWznm::DpchAppLogin::DpchAppLogin(
			const string& scrJref
			, const string& username
			, const string& password
			, const bool m2mNotReg
			, const bool chksuspsess
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPROOTWZNMLOGIN, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, USERNAME, PASSWORD, M2MNOTREG, CHKSUSPSESS};
	else this->mask = mask;

	this->username = username;
	this->password = password;
	this->m2mNotReg = m2mNotReg;
	this->chksuspsess = chksuspsess;
};

string RootWznm::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(USERNAME)) ss.push_back("username");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(M2MNOTREG)) ss.push_back("m2mNotReg");
	if (has(CHKSUSPSESS)) ss.push_back("chksuspsess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWznm::DpchAppLogin::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppRootWznmLogin");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(USERNAME)) writeString(wr, "username", username);
		if (has(PASSWORD)) writeString(wr, "password", password);
		if (has(M2MNOTREG)) writeBool(wr, "m2mNotReg", m2mNotReg);
		if (has(CHKSUSPSESS)) writeBool(wr, "chksuspsess", chksuspsess);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class RootWznm::DpchEngData
 ******************************************************************************/

RootWznm::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGROOTWZNMDATA)
		{
	feedFEnsSps.tag = "FeedFEnsSps";
};

string RootWznm::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(FEEDFENSSPS)) ss.push_back("feedFEnsSps");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWznm::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngRootWznmData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (feedFEnsSps.readXML(docctx, basexpath, true)) add(FEEDFENSSPS);
	} else {
		feedFEnsSps.clear();
	};
};

