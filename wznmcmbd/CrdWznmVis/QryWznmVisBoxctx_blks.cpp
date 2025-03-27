/**
	* \file QryWznmVisBoxctx_blks.cpp
	* job handler for job QryWznmVisBoxctx (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWznmVisBoxctx::StatShr
 ******************************************************************************/

QryWznmVisBoxctx::StatShr::StatShr(
			const uint ntot
		) :
			Block()
			, ntot(ntot)
		{
	mask = {NTOT};
};

void QryWznmVisBoxctx::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWznmVisBoxctx";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ntot"] = (Json::Value::UInt) ntot;
};

void QryWznmVisBoxctx::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWznmVisBoxctx";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryWznmVisBoxctx";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmVisBoxctx::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);

	return(items);
};

set<uint> QryWznmVisBoxctx::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryWznmVisBoxctx::StgIac
 ******************************************************************************/

QryWznmVisBoxctx::StgIac::StgIac(
			const uint jnum
		) :
			Block()
			, jnum(jnum)
		{
	mask = {JNUM};
};

bool QryWznmVisBoxctx::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacQryWznmVisBoxctx"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("jnum")) {jnum = me["jnum"].asUInt(); add(JNUM);};
	};

	return basefound;
};

bool QryWznmVisBoxctx::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWznmVisBoxctx");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWznmVisBoxctx";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
	};

	return basefound;
};

void QryWznmVisBoxctx::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmVisBoxctx";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["jnum"] = (Json::Value::UInt) jnum;
};

void QryWznmVisBoxctx::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmVisBoxctx";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWznmVisBoxctx";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmVisBoxctx::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);

	return(items);
};

set<uint> QryWznmVisBoxctx::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
