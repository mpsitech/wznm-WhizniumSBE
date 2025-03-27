/**
	* \file QryWznmPrjPrj1NVersion_blks.cpp
	* job handler for job QryWznmPrjPrj1NVersion (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWznmPrjPrj1NVersion::StatApp
 ******************************************************************************/

void QryWznmPrjPrj1NVersion::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryWznmPrjPrj1NVersion";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["firstcol"] = (Json::Value::UInt) firstcol;
	me["jnumFirstdisp"] = (Json::Value::UInt) jnumFirstdisp;
	me["ncol"] = (Json::Value::UInt) ncol;
	me["ndisp"] = (Json::Value::UInt) ndisp;
};

void QryWznmPrjPrj1NVersion::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryWznmPrjPrj1NVersion";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppQryWznmPrjPrj1NVersion";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "firstcol", firstcol);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstdisp", jnumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "ncol", ncol);
		writeUintAttr(wr, itemtag, "sref", "ndisp", ndisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class QryWznmPrjPrj1NVersion::StatShr
 ******************************************************************************/

QryWznmPrjPrj1NVersion::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
			, ntot(ntot)
			, jnumFirstload(jnumFirstload)
			, nload(nload)
		{
	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

void QryWznmPrjPrj1NVersion::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWznmPrjPrj1NVersion";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ntot"] = (Json::Value::UInt) ntot;
	me["jnumFirstload"] = (Json::Value::UInt) jnumFirstload;
	me["nload"] = (Json::Value::UInt) nload;
};

void QryWznmPrjPrj1NVersion::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWznmPrjPrj1NVersion";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryWznmPrjPrj1NVersion";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmPrjPrj1NVersion::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmPrjPrj1NVersion::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryWznmPrjPrj1NVersion::StgIac
 ******************************************************************************/

QryWznmPrjPrj1NVersion::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
			, jnum(jnum)
			, jnumFirstload(jnumFirstload)
			, nload(nload)
		{
	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryWznmPrjPrj1NVersion::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacQryWznmPrjPrj1NVersion"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("jnum")) {jnum = me["jnum"].asUInt(); add(JNUM);};
		if (me.isMember("jnumFirstload")) {jnumFirstload = me["jnumFirstload"].asUInt(); add(JNUMFIRSTLOAD);};
		if (me.isMember("nload")) {nload = me["nload"].asUInt(); add(NLOAD);};
	};

	return basefound;
};

bool QryWznmPrjPrj1NVersion::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWznmPrjPrj1NVersion");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWznmPrjPrj1NVersion";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryWznmPrjPrj1NVersion::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmPrjPrj1NVersion";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["jnum"] = (Json::Value::UInt) jnum;
	me["jnumFirstload"] = (Json::Value::UInt) jnumFirstload;
	me["nload"] = (Json::Value::UInt) nload;
};

void QryWznmPrjPrj1NVersion::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmPrjPrj1NVersion";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWznmPrjPrj1NVersion";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmPrjPrj1NVersion::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmPrjPrj1NVersion::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
