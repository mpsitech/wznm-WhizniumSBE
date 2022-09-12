/**
	* \file QryWznmLibAMakefile_blks.cpp
	* job handler for job QryWznmLibAMakefile (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWznmLibAMakefile::StatApp
 ******************************************************************************/

void QryWznmLibAMakefile::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryWznmLibAMakefile";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["firstcol"] = firstcol;
	me["jnumFirstdisp"] = jnumFirstdisp;
	me["ncol"] = ncol;
	me["ndisp"] = ndisp;
};

void QryWznmLibAMakefile::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryWznmLibAMakefile";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppQryWznmLibAMakefile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "firstcol", firstcol);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstdisp", jnumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "ncol", ncol);
		writeUintAttr(wr, itemtag, "sref", "ndisp", ndisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class QryWznmLibAMakefile::StatShr
 ******************************************************************************/

QryWznmLibAMakefile::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->ntot = ntot;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

void QryWznmLibAMakefile::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWznmLibAMakefile";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ntot"] = ntot;
	me["jnumFirstload"] = jnumFirstload;
	me["nload"] = nload;
};

void QryWznmLibAMakefile::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWznmLibAMakefile";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryWznmLibAMakefile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmLibAMakefile::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmLibAMakefile::StatShr::diff(
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
 class QryWznmLibAMakefile::StgIac
 ******************************************************************************/

QryWznmLibAMakefile::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->jnum = jnum;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;
	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryWznmLibAMakefile::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacQryWznmLibAMakefile"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("jnum")) {jnum = me["jnum"].asUInt(); add(JNUM);};
		if (me.isMember("jnumFirstload")) {jnumFirstload = me["jnumFirstload"].asUInt(); add(JNUMFIRSTLOAD);};
		if (me.isMember("nload")) {nload = me["nload"].asUInt(); add(NLOAD);};
	};

	return basefound;
};

bool QryWznmLibAMakefile::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWznmLibAMakefile");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWznmLibAMakefile";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryWznmLibAMakefile::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmLibAMakefile";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["jnum"] = jnum;
	me["jnumFirstload"] = jnumFirstload;
	me["nload"] = nload;
};

void QryWznmLibAMakefile::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmLibAMakefile";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWznmLibAMakefile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmLibAMakefile::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmLibAMakefile::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
