/**
	* \file RootWznm_blks.cpp
	* job handler for job RootWznm (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void RootWznm::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class RootWznm::DpchAppLogin
 ******************************************************************************/

RootWznm::DpchAppLogin::DpchAppLogin() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPROOTWZNMLOGIN)
		{
	m2mNotReg = false;
	chksuspsess = false;
};

string RootWznm::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(USERNAME)) ss.push_back("username");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(M2MNOTREG)) ss.push_back("m2mNotReg");
	if (has(CHKSUSPSESS)) ss.push_back("chksuspsess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWznm::DpchAppLogin::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppRootWznmLogin");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "username", "", username)) add(USERNAME);
		if (extractStringUclc(docctx, basexpath, "password", "", password)) add(PASSWORD);
		if (extractBoolUclc(docctx, basexpath, "m2mNotReg", "", m2mNotReg)) add(M2MNOTREG);
		if (extractBoolUclc(docctx, basexpath, "chksuspsess", "", chksuspsess)) add(CHKSUSPSESS);
	} else {
	};
};

/******************************************************************************
 class RootWznm::DpchEngData
 ******************************************************************************/

RootWznm::DpchEngData::DpchEngData(
			const ubigint jref
			, Feed* feedFEnsSps
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGROOTWZNMDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, FEEDFENSSPS};
	else this->mask = mask;

	if (find(this->mask, FEEDFENSSPS) && feedFEnsSps) this->feedFEnsSps = *feedFEnsSps;
};

string RootWznm::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(FEEDFENSSPS)) ss.push_back("feedFEnsSps");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWznm::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(FEEDFENSSPS)) {feedFEnsSps = src->feedFEnsSps; add(FEEDFENSSPS);};
};

void RootWznm::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngRootWznmData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(FEEDFENSSPS)) feedFEnsSps.writeXML(wr);
	xmlTextWriterEndElement(wr);
};



