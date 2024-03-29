/**
	* \file Wznmcmbd.cpp
	* inter-thread exchange object for Wznm combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wznmd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace DpchWznmdAck
 ******************************************************************************/

void DpchWznmdAck::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchWznmdAck");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchWznmdQuit
 ******************************************************************************/

void DpchWznmdQuit::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchWznmdQuit");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchWznmdReg
 ******************************************************************************/

void DpchWznmdReg::writeXML(
			xmlTextWriter* wr
			, const ubigint nref
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchWznmdReg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrNref", Scr::scramble(nref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchWznmopdReg
 ******************************************************************************/

DpchWznmopdReg::DpchWznmopdReg() :
			DpchWznm(VecWznmVDpch::DPCHWZNMOPDREG)
		{
};

bool DpchWznmopdReg::all(
			const set<uint>& items
		) {
	if (!find(items, PORT)) return false;
	if (!find(items, IXWZNMVOPENGTYPE)) return false;
	if (!find(items, OPPRCN)) return false;

	return true;
};

void DpchWznmopdReg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVOpengtype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchWznmopdReg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractUsmallintUclc(docctx, basexpath, "port", "", port)) add(PORT);
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVOpengtype", "", srefIxWznmVOpengtype)) {
			ixWznmVOpengtype = VecWznmVOpengtype::getIx(srefIxWznmVOpengtype);
			add(IXWZNMVOPENGTYPE);
		};
		if (extractUsmallintUclc(docctx, basexpath, "opprcn", "", opprcn)) add(OPPRCN);
	};
};

/******************************************************************************
 class DpchWznmopdUnreg
 ******************************************************************************/

DpchWznmopdUnreg::DpchWznmopdUnreg() :
			DpchWznm(VecWznmVDpch::DPCHWZNMOPDUNREG)
		{
};

bool DpchWznmopdUnreg::all(
			const set<uint>& items
		) {
	if (!find(items, NREF)) return false;

	return true;
};

void DpchWznmopdUnreg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrNref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchWznmopdUnreg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrNref", "", scrNref)) {
			nref = Scr::descramble(scrNref);
			add(NREF);
		};
	};
};

/******************************************************************************
 class DpchAppWznm
 ******************************************************************************/

DpchAppWznm::DpchAppWznm(
			const uint ixWznmVDpch
		) :
			DpchWznm(ixWznmVDpch)
		{
	jref = 0;
};

DpchAppWznm::~DpchAppWznm() {
};

bool DpchAppWznm::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchAppWznm::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchAppWznm::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup[VecWznmVDpch::getSref(ixWznmVDpch)];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
	};
};

void DpchAppWznm::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrJref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecWznmVDpch::getSref(ixWznmVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
	};
};

/******************************************************************************
 class DpchAppWznmAlert
 ******************************************************************************/

DpchAppWznmAlert::DpchAppWznmAlert() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMALERT)
		{
};

bool DpchAppWznmAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

string DpchAppWznmAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(NUMFMCB)) ss.push_back("numFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchAppWznmAlert::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmAlert"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
		if (me.isMember("numFMcb")) {numFMcb = me["numFMcb"].asInt(); add(NUMFMCB);};
	};
};

void DpchAppWznmAlert::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractUintUclc(docctx, basexpath, "numFMcb", "", numFMcb)) add(NUMFMCB);
	} else {
	};
};

/******************************************************************************
 class DpchAppWznmInit
 ******************************************************************************/

DpchAppWznmInit::DpchAppWznmInit() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMINIT)
		{
};

/******************************************************************************
 class DpchAppWznmResume
 ******************************************************************************/

DpchAppWznmResume::DpchAppWznmResume() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRESUME)
		{
};

/******************************************************************************
 class DpchEngWznm
 ******************************************************************************/

DpchEngWznm::DpchEngWznm(
			const uint ixWznmVDpch
			, const ubigint jref
		) :
			DpchWznm(ixWznmVDpch)
		{
	this->jref = jref;

	mask = {JREF};
};

DpchEngWznm::~DpchEngWznm() {
};

bool DpchEngWznm::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchEngWznm::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchEngWznm::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngWznm* src = dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
};

void DpchEngWznm::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup[VecWznmVDpch::getSref(ixWznmVDpch)] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
};

void DpchEngWznm::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	string tag = VecWznmVDpch::getSref(ixWznmVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWznmAck
 ******************************************************************************/

DpchEngWznmAck::DpchEngWznmAck(
			const ubigint jref
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMACK, jref)
		{
};

/******************************************************************************
 class DpchEngWznmAlert
 ******************************************************************************/

DpchEngWznmAlert::DpchEngWznmAlert(
			const ubigint jref
			, ContInfWznmAlert* continf
			, Feed* feedFMcb
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMALERT, jref)
		{
	if (continf) this->continf = *continf;
	if (feedFMcb) this->feedFMcb = *feedFMcb;

	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFMCB};
	else this->mask = mask;
};

bool DpchEngWznmAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

string DpchEngWznmAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFMCB)) ss.push_back("feedFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWznmAlert::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngWznmAlert* src = (DpchEngWznmAlert*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFMCB)) {feedFMcb = src->feedFMcb; add(FEEDFMCB);};
};

void DpchEngWznmAlert::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmAlert"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFMCB)) feedFMcb.writeJSON(me);
};

void DpchEngWznmAlert::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFMCB)) feedFMcb.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWznmConfirm
 ******************************************************************************/

DpchEngWznmConfirm::DpchEngWznmConfirm(
			const bool accepted
			, const ubigint jref
			, const string& sref
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMCONFIRM, jref)
		{
	this->accepted = accepted;
	this->jref = jref;
	this->sref = sref;

	if (find(mask, ALL)) this->mask = {ACCEPTED, JREF, SREF};
	else this->mask = mask;
};

bool DpchEngWznmConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

string DpchEngWznmConfirm::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(ACCEPTED)) ss.push_back("accepted");
	if (has(JREF)) ss.push_back("jref");
	if (has(SREF)) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWznmConfirm::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngWznmConfirm* src = (DpchEngWznmConfirm*) dpcheng;

	if (src->has(ACCEPTED)) {accepted = src->accepted; add(ACCEPTED);};
	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(SREF)) {sref = src->sref; add(SREF);};
};

void DpchEngWznmConfirm::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmConfirm"] = Json::Value(Json::objectValue);

	if (has(ACCEPTED)) me["accepted"] = accepted;
	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(SREF)) me["sref"] = sref;
};

void DpchEngWznmConfirm::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmConfirm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(ACCEPTED)) writeBool(wr, "accepted", accepted);
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(SREF)) writeString(wr, "sref", sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWznmSuspend
 ******************************************************************************/

DpchEngWznmSuspend::DpchEngWznmSuspend(
			const ubigint jref
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSUSPEND, jref)
		{
};

/******************************************************************************
 class StgWznmAppearance
 ******************************************************************************/

StgWznmAppearance::StgWznmAppearance(
			const usmallint histlength
			, const bool suspsess
			, const uint sesstterm
			, const uint sesstwarn
			, const uint roottterm
		) :
			Block()
		{
	this->histlength = histlength;
	this->suspsess = suspsess;
	this->sesstterm = sesstterm;
	this->sesstwarn = sesstwarn;
	this->roottterm = roottterm;
	mask = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
};

bool StgWznmAppearance::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWznmAppearance");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWznmAppearance";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "histlength", histlength)) add(HISTLENGTH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "suspsess", suspsess)) add(SUSPSESS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstterm", sesstterm)) add(SESSTTERM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstwarn", sesstwarn)) add(SESSTWARN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "roottterm", roottterm)) add(ROOTTTERM);
	};

	return basefound;
};

void StgWznmAppearance::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWznmAppearance";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWznmAppearance";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "histlength", histlength);
		writeBoolAttr(wr, itemtag, "sref", "suspsess", suspsess);
		writeUintAttr(wr, itemtag, "sref", "sesstterm", sesstterm);
		writeUintAttr(wr, itemtag, "sref", "sesstwarn", sesstwarn);
		writeUintAttr(wr, itemtag, "sref", "roottterm", roottterm);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWznmAppearance::comm(
			const StgWznmAppearance* comp
		) {
	set<uint> items;

	if (histlength == comp->histlength) insert(items, HISTLENGTH);
	if (suspsess == comp->suspsess) insert(items, SUSPSESS);
	if (sesstterm == comp->sesstterm) insert(items, SESSTTERM);
	if (sesstwarn == comp->sesstwarn) insert(items, SESSTWARN);
	if (roottterm == comp->roottterm) insert(items, ROOTTTERM);

	return(items);
};

set<uint> StgWznmAppearance::diff(
			const StgWznmAppearance* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWznmAppsrv
 ******************************************************************************/

StgWznmAppsrv::StgWznmAppsrv(
			const usmallint port
			, const bool https
			, const string& cors
		) :
			Block()
		{
	this->port = port;
	this->https = https;
	this->cors = cors;
	mask = {PORT, HTTPS, CORS};
};

bool StgWznmAppsrv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWznmAppsrv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWznmAppsrv";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "https", https)) add(HTTPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "cors", cors)) add(CORS);
	};

	return basefound;
};

void StgWznmAppsrv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWznmAppsrv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWznmAppsrv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeBoolAttr(wr, itemtag, "sref", "https", https);
		writeStringAttr(wr, itemtag, "sref", "cors", cors);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWznmAppsrv::comm(
			const StgWznmAppsrv* comp
		) {
	set<uint> items;

	if (port == comp->port) insert(items, PORT);
	if (https == comp->https) insert(items, HTTPS);
	if (cors == comp->cors) insert(items, CORS);

	return(items);
};

set<uint> StgWznmAppsrv::diff(
			const StgWznmAppsrv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PORT, HTTPS, CORS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWznmd
 ******************************************************************************/

StgWznmd::StgWznmd(
			const usmallint jobprcn
			, const usmallint opengsrvport
			, const bool appsrv
		) :
			Block()
		{
	this->jobprcn = jobprcn;
	this->opengsrvport = opengsrvport;
	this->appsrv = appsrv;
	mask = {JOBPRCN, OPENGSRVPORT, APPSRV};
};

bool StgWznmd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWznmd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWznmd";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jobprcn", jobprcn)) add(JOBPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opengsrvport", opengsrvport)) add(OPENGSRVPORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrv", appsrv)) add(APPSRV);
	};

	return basefound;
};

void StgWznmd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWznmd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWznmd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "jobprcn", jobprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "opengsrvport", opengsrvport);
		writeBoolAttr(wr, itemtag, "sref", "appsrv", appsrv);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWznmd::comm(
			const StgWznmd* comp
		) {
	set<uint> items;

	if (jobprcn == comp->jobprcn) insert(items, JOBPRCN);
	if (opengsrvport == comp->opengsrvport) insert(items, OPENGSRVPORT);
	if (appsrv == comp->appsrv) insert(items, APPSRV);

	return(items);
};

set<uint> StgWznmd::diff(
			const StgWznmd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JOBPRCN, OPENGSRVPORT, APPSRV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWznmDatabase
 ******************************************************************************/

StgWznmDatabase::StgWznmDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) :
			Block()
		{
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgWznmDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWznmDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWznmDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgWznmDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWznmDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWznmDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWznmDatabase::comm(
			const StgWznmDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgWznmDatabase::diff(
			const StgWznmDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWznmPath
 ******************************************************************************/

StgWznmPath::StgWznmPath(
			const string& acvpath
			, const string& keypath
			, const string& monpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) :
			Block()
		{
	this->acvpath = acvpath;
	this->keypath = keypath;
	this->monpath = monpath;
	this->tmppath = tmppath;
	this->webpath = webpath;
	this->helpurl = helpurl;
	mask = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgWznmPath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWznmPath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWznmPath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "keypath", keypath)) add(KEYPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "monpath", monpath)) add(MONPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgWznmPath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWznmPath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWznmPath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "keypath", keypath);
		writeStringAttr(wr, itemtag, "sref", "monpath", monpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWznmPath::comm(
			const StgWznmPath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (keypath == comp->keypath) insert(items, KEYPATH);
	if (monpath == comp->monpath) insert(items, MONPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgWznmPath::diff(
			const StgWznmPath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWznmTenant
 ******************************************************************************/

StgWznmTenant::StgWznmTenant(
			const string& orgname
			, const string& orgweb
		) :
			Block()
		{
	this->orgname = orgname;
	this->orgweb = orgweb;
	mask = {ORGNAME, ORGWEB};
};

bool StgWznmTenant::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWznmTenant");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWznmTenant";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "orgname", orgname)) add(ORGNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "orgweb", orgweb)) add(ORGWEB);
	};

	return basefound;
};

void StgWznmTenant::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWznmTenant";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWznmTenant";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "orgname", orgname);
		writeStringAttr(wr, itemtag, "sref", "orgweb", orgweb);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWznmTenant::comm(
			const StgWznmTenant* comp
		) {
	set<uint> items;

	if (orgname == comp->orgname) insert(items, ORGNAME);
	if (orgweb == comp->orgweb) insert(items, ORGWEB);

	return(items);
};

set<uint> StgWznmTenant::diff(
			const StgWznmTenant* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ORGNAME, ORGWEB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 namespace AlrWznm
 ******************************************************************************/

DpchEngWznmAlert* AlrWznm::prepareAlrAbt(
			const ubigint jref
			, const uint ixWznmVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfWznmAlert continf;
	// IP prepareAlrAbt --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "WhizniumSBE version v1.1.9 released on 11-9-2022";
		continf.TxtMsg2 = "\\u00a9 MPSI Technologies GmbH";
		continf.TxtMsg4 = "contributors: Alexander Wirthmueller";
		continf.TxtMsg6 = "libraries: apiwzlm 1.0.0, curl 7.65, git2 0.24.0, jsoncpp 1.8.4 and openssl 1.1.1";
		continf.TxtMsg8 = "WhizniumSBE implements all functionality of the Whiznium Service Builder's Edition framework for automated code generation and iteration.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::CLOSE, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrAbt --- END
	return(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));
};

DpchEngWznmAlert* AlrWznm::prepareAlrIer(
			const ubigint jref
			, const uint ixWznmVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfWznmAlert continf;
	// IP prepareAlrIer --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::IMPERR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::CANCEL, ixWznmVLocale, feedFMcbAlert);
	VecWznmVTag::appendToFeed(VecWznmVTag::REVERSE, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrIer --- END
	return(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));
};

DpchEngWznmAlert* AlrWznm::prepareAlrPer(
			const ubigint jref
			, const uint ixWznmVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfWznmAlert continf;
	// IP prepareAlrPer --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::PRSERR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrPer --- END
	return(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));
};

DpchEngWznmAlert* AlrWznm::prepareAlrSav(
			const ubigint jref
			, const uint ixWznmVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfWznmAlert continf;
	// IP prepareAlrSav --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::QUEST, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Save changes?";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::CANCEL, ixWznmVLocale, feedFMcbAlert);
	VecWznmVTag::appendToFeed(VecWznmVTag::FLS, ixWznmVLocale, feedFMcbAlert);
	VecWznmVTag::appendToFeed(VecWznmVTag::TRU, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrSav --- END
	return(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));
};

DpchEngWznmAlert* AlrWznm::prepareAlrTrm(
			const ubigint jref
			, const uint ixWznmVLocale
			, const uint sesstterm
			, const uint sesstwarn
			, Feed& feedFMcbAlert
		) {
	ContInfWznmAlert continf;
	// IP prepareAlrTrm --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ANNOUNCE, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Your session has been inactive for " + prepareAlrTrm_dtToString(ixWznmVLocale, sesstterm) + ". It will be terminated in " + prepareAlrTrm_dtToString(ixWznmVLocale, sesstwarn) + ".";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrTrm --- END
	return(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));
};

string AlrWznm::prepareAlrTrm_dtToString(
			const uint ixWznmVLocale
			, const time_t dt
		) {
	string s;

	if ((dt%3600) == 0) {
		s = to_string(dt/3600);

		if (dt == 3600) s += " " + VecWznmVTag::getTitle(VecWznmVTag::HOUR, ixWznmVLocale);
		else s += " " + VecWznmVTag::getTitle(VecWznmVTag::HOURS, ixWznmVLocale);

	} else if ((dt%60) == 0) {
		s = to_string(dt/60);

		if (dt == 60) s += " " + VecWznmVTag::getTitle(VecWznmVTag::MINUTE, ixWznmVLocale);
		else s += " " + VecWznmVTag::getTitle(VecWznmVTag::MINUTES, ixWznmVLocale);

	} else {
		s = to_string(dt);

		if (dt == 1) s += " " + VecWznmVTag::getTitle(VecWznmVTag::SECOND, ixWznmVLocale);
		else s += " " + VecWznmVTag::getTitle(VecWznmVTag::SECONDS, ixWznmVLocale);
	};

	return s;
};

/******************************************************************************
 class ReqWznm
 ******************************************************************************/

ReqWznm::ReqWznm(
			const uint ixVBasetype
			, const uint ixVState
			, const string& ip
		) :
			cReady("cReady", "ReqWznm", "ReqWznm")
		{
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	retain = !((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::DPCHAPP) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD) || (ixVBasetype == VecVBasetype::METHOD));

	file = NULL;
	filelen = 0;

	request = NULL;
	requestlen = 0;

	jsonNotXml = false;

	jref = 0;

	wref = 0;

	call = NULL;

	weak = false;

	dpchapp = NULL;

	dpcheng = NULL;
	ixWznmVLocale = VecWznmVLocale::ENUS;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;
	
	method = NULL;
};

ReqWznm::~ReqWznm() {
	if (pp) MHD_destroy_post_processor(pp);

	if (file) {
		if (file->is_open()) file->close();
		delete file;
	};

	if (call) delete call;

	if (request) delete[] request;

	if (dpchapp) delete dpchapp;

	if (dpcheng) delete dpcheng;

	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	if (reply) delete[] reply;

	if (method) delete method;
};

void ReqWznm::setStateReply() {
	cReady.lockMutex("ReqWznm", "setStateReply", "jref=" + to_string(jref));
	ixVState = VecVState::REPLY;
	cReady.unlockMutex("ReqWznm", "setStateReply", "jref=" + to_string(jref));

	cReady.signal("ReqWznm", "setStateReply", "jref=" + to_string(jref));
};

/******************************************************************************
 class ReqopengconWznm
 ******************************************************************************/

ReqopengconWznm::ReqopengconWznm(
			const uint ixVState
			, const string& ip
		) {
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	request = NULL;
	requestlen = 0;

	dpchopd = NULL;

	reply = NULL;
	replylen = 0;
};

ReqopengconWznm::~ReqopengconWznm() {
	if (pp) MHD_destroy_post_processor(pp);

	if (request) delete[] request;

	if (dpchopd) delete dpchopd;

	if (reply) delete[] reply;
};

/******************************************************************************
 class DcolWznm
 ******************************************************************************/

DcolWznm::DcolWznm(
			const ubigint jref
			, const uint ixWznmVLocale
		) :
			mAccess("dcol.mAccess", "DcolWznm", "DcolWznm", "jref=" + to_string(jref))
		{
	this->jref = jref;
	this->ixWznmVLocale = ixWznmVLocale;

	hot = false;

	req = NULL;
};

DcolWznm::~DcolWznm() {
	for (auto it = dpchs.begin(); it != dpchs.end(); it++) delete(*it);

	if (req) req->cReady.signal("DcolWznm", "~DcolWznm", "jref=" + to_string(jref));

	mAccess.lock("DcolWznm", "~DcolWznm", "jref=" + to_string(jref));
	mAccess.unlock("DcolWznm", "~DcolWznm", "jref=" + to_string(jref));
};

void DcolWznm::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void DcolWznm::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class JobWznm
 ******************************************************************************/

JobWznm::JobWznm(
			XchgWznm* xchg
			, const uint ixWznmVJob
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			mAccess("mAccess", VecWznmVJob::getSref(ixWznmVJob), VecWznmVJob::getSref(ixWznmVJob), "jrefSup=" + to_string(jrefSup))
			, mOps("mOps", VecWznmVJob::getSref(ixWznmVJob), VecWznmVJob::getSref(ixWznmVJob), "jrefSup=" + to_string(jrefSup))
		{
	this->xchg = xchg;

	jref = 0;

	this->ixWznmVJob = ixWznmVJob;

	this->ixWznmVLocale = ixWznmVLocale;

	muteRefresh = false;

	ixVSge = 1;
	nextIxVSgeSuccess = 1;
	nextIxVSgeFailure = 1;

	opN = 0;
	opNSuccess = 0;
	opNFailure = 0;

	wrefLast = 0;
	wrefMin = 0;

	reqCmd = NULL;
};

JobWznm::~JobWznm() {
	if (reqCmd) delete reqCmd;

	mAccess.lock(VecWznmVJob::getSref(ixWznmVJob), "~" + VecWznmVJob::getSref(ixWznmVJob), "jref=" + to_string(jref));
	mAccess.unlock(VecWznmVJob::getSref(ixWznmVJob), "~" + VecWznmVJob::getSref(ixWznmVJob), "jref=" + to_string(jref));
};

ubigint JobWznm::insertSubjob(
			map<ubigint, JobWznm*>& subjobs
			, JobWznm* subjob
		) {
	subjobs[subjob->jref] = subjob;

	return subjob->jref;
};

bool JobWznm::eraseSubjobByJref(
			map<ubigint, JobWznm*>& subjobs
			, const ubigint _jref
		) {
	auto it = subjobs.find(_jref);

	if (it != subjobs.end()) {
		delete it->second;
		subjobs.erase(it);

		return true;
	};

	return false;
};

DpchEngWznm* JobWznm::getNewDpchEng(
			set<uint> items
		) {
	return new DpchEngWznmConfirm(true, jref, "");
};

void JobWznm::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
};

void JobWznm::refreshWithDpchEng(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
			, const bool unmute
		) {
	set<uint> moditems;

	DpchEngWznm* _dpcheng = NULL;

	refresh(dbswznm, moditems, unmute);
	if (muteRefresh) return;

	if (dpcheng) {
		_dpcheng = getNewDpchEng(moditems);

		if (*dpcheng) {
			if (_dpcheng->ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONFIRM) delete _dpcheng;
			else if (_dpcheng->ixWznmVDpch == (*dpcheng)->ixWznmVDpch) {
				(*dpcheng)->merge(_dpcheng);
				delete _dpcheng;

			} else xchg->submitDpch(_dpcheng);

		} else *dpcheng = _dpcheng;

	} else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
};

string JobWznm::getSquawk(
			DbsWznm* dbswznm
		) {
	return "";
};

void JobWznm::handleRequest(
			DbsWznm* dbswznm
			, ReqWznm* req
		) {
};

void JobWznm::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
};

void JobWznm::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

bool JobWznm::trylockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return mAccess.trylock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobWznm::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobWznm::lockAccess(
			const string& srefMember
		) {
	mAccess.lock(VecWznmVJob::getSref(ixWznmVJob), srefMember, "jref=" + to_string(jref));
};

bool JobWznm::trylockAccess(
			const string& srefMember
		) {
	return mAccess.trylock(VecWznmVJob::getSref(ixWznmVJob), srefMember, "jref=" + to_string(jref));
};

void JobWznm::unlockAccess(
			const string& srefMember
		) {
	mAccess.unlock(VecWznmVJob::getSref(ixWznmVJob), srefMember, "jref=" + to_string(jref));
};

void JobWznm::setStage(
			DbsWznm* dbswznm
			, const uint _ixVSge
		) {
	xchg->setJobStage(dbswznm, this, _ixVSge);
};

void JobWznm::clearInvs() {
	for (unsigned int i = 0; i < invs.size(); i++) delete invs[i];
	invs.clear();
};

ubigint JobWznm::addInv(
			DpchInvWznm* inv
		) {
	inv->oref = xchg->orefseq.getNewRef();
	inv->jref = jref;

	invs.push_back(inv);

	opN++;

	return(inv->oref);
};

void JobWznm::addInvs(
			vector<DpchInvWznm*>& _invs
		) {
	for (unsigned int i = 0; i < _invs.size(); i++) addInv(_invs[i]);
};

void JobWznm::submitInvs(
			DbsWznm* dbswznm
			, const uint nextIxVSgeEmpty
			, uint& _ixVSge
		) {
	if (opN == 0) {
		_ixVSge = nextIxVSgeEmpty;

	} else {
		xchg->addInvs(dbswznm, this, invs);
		invs.clear();
	};
};

void JobWznm::clearOps() {
	mOps.lock(VecWznmVJob::getSref(ixWznmVJob), "clearOps", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) delete(*it);
	ops.clear();

	mOps.unlock(VecWznmVJob::getSref(ixWznmVJob), "clearOps", "jref=" + to_string(jref));
};

void JobWznm::addOp(
			DbsWznm* dbswznm
			, DpchInvWznm* inv
		) {
	string squawk;

	mOps.lock(VecWznmVJob::getSref(ixWznmVJob), "addOp", "jref=" + to_string(jref));

	// generate squawk
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLBSCUI) {
		squawk = SqkWznmCompl::getSquawkBscui(dbswznm, (DpchInvWznmComplBscui*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLCTPCPY) {
		squawk = SqkWznmCompl::getSquawkCtpcpy(dbswznm, (DpchInvWznmComplCtpcpy*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLDBS) {
		squawk = SqkWznmCompl::getSquawkDbs(dbswznm, (DpchInvWznmComplDbs*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLDEPLOY) {
		squawk = SqkWznmCompl::getSquawkDeploy(dbswznm, (DpchInvWznmComplDeploy*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLIEX) {
		squawk = SqkWznmCompl::getSquawkIex(dbswznm, (DpchInvWznmComplIex*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLJTR) {
		squawk = SqkWznmCompl::getSquawkJtr(dbswznm, (DpchInvWznmComplJtr*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPGENJTR) {
		squawk = SqkWznmCtpGenjtr::getSquawk(dbswznm, (DpchInvWznmCtpGenjtr*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPGENUI) {
		squawk = SqkWznmCtpGenui::getSquawk(dbswznm, (DpchInvWznmCtpGenui*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRSRV) {
		squawk = SqkWznmCtpWrsrv::getSquawk(dbswznm, (DpchInvWznmCtpWrsrv*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRSTKIT) {
		squawk = SqkWznmCtpWrstkit::getSquawk(dbswznm, (DpchInvWznmCtpWrstkit*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRWEB) {
		squawk = SqkWznmCtpWrweb::getSquawk(dbswznm, (DpchInvWznmCtpWrweb*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENBASE) {
		squawk = SqkWznmGen::getSquawkBase(dbswznm, (DpchInvWznmGenBase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENCAL) {
		squawk = SqkWznmGen::getSquawkCal(dbswznm, (DpchInvWznmGenCal*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENCHK) {
		squawk = SqkWznmGen::getSquawkChk(dbswznm, (DpchInvWznmGenChk*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENDETUI) {
		squawk = SqkWznmGen::getSquawkDetui(dbswznm, (DpchInvWznmGenDetui*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENJOB) {
		squawk = SqkWznmGen::getSquawkJob(dbswznm, (DpchInvWznmGenJob*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENQTB) {
		squawk = SqkWznmGen::getSquawkQtb(dbswznm, (DpchInvWznmGenQtb*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENSYSVEC) {
		squawk = SqkWznmGen::getSquawkSysvec(dbswznm, (DpchInvWznmGenSysvec*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCFILECONCAT) {
		squawk = SqkWznmPrcfile::getSquawkConcat(dbswznm, (DpchInvWznmPrcfileConcat*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCFILEPLHRPL) {
		squawk = SqkWznmPrcfile::getSquawkPlhrpl(dbswznm, (DpchInvWznmPrcfilePlhrpl*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEEXTRACT) {
		squawk = SqkWznmPrctree::getSquawkExtract(dbswznm, (DpchInvWznmPrctreeExtract*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEMERGE) {
		squawk = SqkWznmPrctree::getSquawkMerge(dbswznm, (DpchInvWznmPrctreeMerge*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEVALIDATE) {
		squawk = SqkWznmPrctree::getSquawkValidate(dbswznm, (DpchInvWznmPrctreeValidate*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIBASE) {
		squawk = SqkWznmWrapi::getSquawkBase(dbswznm, (DpchInvWznmWrapiBase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIDEPLOY) {
		squawk = SqkWznmWrapi::getSquawkDeploy(dbswznm, (DpchInvWznmWrapiDeploy*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIJOB) {
		squawk = SqkWznmWrapi::getSquawkJob(dbswznm, (DpchInvWznmWrapiJob*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIQTB) {
		squawk = SqkWznmWrapi::getSquawkQtb(dbswznm, (DpchInvWznmWrapiQtb*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPDOM) {
		squawk = SqkWznmWrapp::getSquawkDom(dbswznm, (DpchInvWznmWrappDom*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPMAIN) {
		squawk = SqkWznmWrapp::getSquawkMain(dbswznm, (DpchInvWznmWrappMain*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPSTDVEC) {
		squawk = SqkWznmWrapp::getSquawkStdvec(dbswznm, (DpchInvWznmWrappStdvec*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRCSAPIBASE) {
		squawk = SqkWznmWrcsapi::getSquawkBase(dbswznm, (DpchInvWznmWrcsapiBase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRCSAPIJOB) {
		squawk = SqkWznmWrcsapi::getSquawkJob(dbswznm, (DpchInvWznmWrcsapiJob*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRCSAPIQTB) {
		squawk = SqkWznmWrcsapi::getSquawkQtb(dbswznm, (DpchInvWznmWrcsapiQtb*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRCSAPIVEC) {
		squawk = SqkWznmWrcsapi::getSquawkVec(dbswznm, (DpchInvWznmWrcsapiVec*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSDBS) {
		squawk = SqkWznmWrdbs::getSquawkDbs(dbswznm, (DpchInvWznmWrdbsDbs*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSDEPLOY) {
		squawk = SqkWznmWrdbs::getSquawkDeploy(dbswznm, (DpchInvWznmWrdbsDeploy*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSDIFFSQL) {
		squawk = SqkWznmWrdbs::getSquawkDiffsql(dbswznm, (DpchInvWznmWrdbsDiffsql*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSSQL) {
		squawk = SqkWznmWrdbs::getSquawkSql(dbswznm, (DpchInvWznmWrdbsSql*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSTBL) {
		squawk = SqkWznmWrdbs::getSquawkTbl(dbswznm, (DpchInvWznmWrdbsTbl*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIBASE) {
		squawk = SqkWznmWrjapi::getSquawkBase(dbswznm, (DpchInvWznmWrjapiBase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIJOB) {
		squawk = SqkWznmWrjapi::getSquawkJob(dbswznm, (DpchInvWznmWrjapiJob*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIQTB) {
		squawk = SqkWznmWrjapi::getSquawkQtb(dbswznm, (DpchInvWznmWrjapiQtb*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIVEC) {
		squawk = SqkWznmWrjapi::getSquawkVec(dbswznm, (DpchInvWznmWrjapiVec*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRPYAPIBASE) {
		squawk = SqkWznmWrpyapi::getSquawkBase(dbswznm, (DpchInvWznmWrpyapiBase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRPYAPIJOB) {
		squawk = SqkWznmWrpyapi::getSquawkJob(dbswznm, (DpchInvWznmWrpyapiJob*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRPYAPIQTB) {
		squawk = SqkWznmWrpyapi::getSquawkQtb(dbswznm, (DpchInvWznmWrpyapiQtb*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRPYAPIVEC) {
		squawk = SqkWznmWrpyapi::getSquawkVec(dbswznm, (DpchInvWznmWrpyapiVec*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVBASE) {
		squawk = SqkWznmWrsrv::getSquawkBase(dbswznm, (DpchInvWznmWrsrvBase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVCMBENGBASE) {
		squawk = SqkWznmWrsrv::getSquawkCmbengbase(dbswznm, (DpchInvWznmWrsrvCmbengbase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVCRD) {
		squawk = SqkWznmWrsrv::getSquawkCrd(dbswznm, (DpchInvWznmWrsrvCrd*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVDDS) {
		squawk = SqkWznmWrsrv::getSquawkDds(dbswznm, (DpchInvWznmWrsrvDds*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVDEPLOY) {
		squawk = SqkWznmWrsrv::getSquawkDeploy(dbswznm, (DpchInvWznmWrsrvDeploy*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVDLG) {
		squawk = SqkWznmWrsrv::getSquawkDlg(dbswznm, (DpchInvWznmWrsrvDlg*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVENGBASE) {
		squawk = SqkWznmWrsrv::getSquawkEngbase(dbswznm, (DpchInvWznmWrsrvEngbase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVIEX) {
		squawk = SqkWznmWrsrv::getSquawkIex(dbswznm, (DpchInvWznmWrsrvIex*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVINIXML) {
		squawk = SqkWznmWrsrv::getSquawkInixml(dbswznm, (DpchInvWznmWrsrvInixml*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVJOB) {
		squawk = SqkWznmWrsrv::getSquawkJob(dbswznm, (DpchInvWznmWrsrvJob*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVOP) {
		squawk = SqkWznmWrsrv::getSquawkOp(dbswznm, (DpchInvWznmWrsrvOp*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVOPENGBASE) {
		squawk = SqkWznmWrsrv::getSquawkOpengbase(dbswznm, (DpchInvWznmWrsrvOpengbase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVOPK) {
		squawk = SqkWznmWrsrv::getSquawkOpk(dbswznm, (DpchInvWznmWrsrvOpk*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVPNL) {
		squawk = SqkWznmWrsrv::getSquawkPnl(dbswznm, (DpchInvWznmWrsrvPnl*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVPREF) {
		squawk = SqkWznmWrsrv::getSquawkPref(dbswznm, (DpchInvWznmWrsrvPref*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVQRY) {
		squawk = SqkWznmWrsrv::getSquawkQry(dbswznm, (DpchInvWznmWrsrvQry*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVROOTSESS) {
		squawk = SqkWznmWrsrv::getSquawkRootsess(dbswznm, (DpchInvWznmWrsrvRootsess*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVUA) {
		squawk = SqkWznmWrsrv::getSquawkUa(dbswznm, (DpchInvWznmWrsrvUa*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVVEC) {
		squawk = SqkWznmWrsrv::getSquawkVec(dbswznm, (DpchInvWznmWrsrvVec*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSWAPIBASE) {
		squawk = SqkWznmWrswapi::getSquawkBase(dbswznm, (DpchInvWznmWrswapiBase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSWAPIJOB) {
		squawk = SqkWznmWrswapi::getSquawkJob(dbswznm, (DpchInvWznmWrswapiJob*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSWAPIQTB) {
		squawk = SqkWznmWrswapi::getSquawkQtb(dbswznm, (DpchInvWznmWrswapiQtb*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSWAPIVEC) {
		squawk = SqkWznmWrswapi::getSquawkVec(dbswznm, (DpchInvWznmWrswapiVec*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVUEBASE) {
		squawk = SqkWznmWrvue::getSquawkBase(dbswznm, (DpchInvWznmWrvueBase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVUECRD) {
		squawk = SqkWznmWrvue::getSquawkCrd(dbswznm, (DpchInvWznmWrvueCrd*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVUEDLG) {
		squawk = SqkWznmWrvue::getSquawkDlg(dbswznm, (DpchInvWznmWrvueDlg*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVUEPNL) {
		squawk = SqkWznmWrvue::getSquawkPnl(dbswznm, (DpchInvWznmWrvuePnl*) inv);
	};
	if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBBASE) {
		squawk = SqkWznmWrweb::getSquawkBase(dbswznm, (DpchInvWznmWrwebBase*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBCRD) {
		squawk = SqkWznmWrweb::getSquawkCrd(dbswznm, (DpchInvWznmWrwebCrd*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBDEPLOY) {
		squawk = SqkWznmWrweb::getSquawkDeploy(dbswznm, (DpchInvWznmWrwebDeploy*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBDLG) {
		squawk = SqkWznmWrweb::getSquawkDlg(dbswznm, (DpchInvWznmWrwebDlg*) inv);
	} else if (inv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBPNL) {
		squawk = SqkWznmWrweb::getSquawkPnl(dbswznm, (DpchInvWznmWrwebPnl*) inv);
	};

	// append to op list
	ops.push_back(new Op(inv->oref, inv->ixWznmVDpch, squawk));

	mOps.unlock(VecWznmVJob::getSref(ixWznmVJob), "addOp", "jref=" + to_string(jref));
};

void JobWznm::removeOp(
			const ubigint oref
		) {
	Op* op = NULL;

	mOps.lock(VecWznmVJob::getSref(ixWznmVJob), "removeOp", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) {
		op = *it;

		if (op->oref == oref) {
			// found
			ops.erase(it);

			// keep squawk of this op
			opsqkLast = op->squawk;

			delete op;
			
			break;
		};
	};

	mOps.unlock(VecWznmVJob::getSref(ixWznmVJob), "removeOp", "jref=" + to_string(jref));
};

string JobWznm::getOpsqkLast() {
	string retval;

	mOps.lock(VecWznmVJob::getSref(ixWznmVJob), "getOpsqkLast", "jref=" + to_string(jref));

	retval = opsqkLast;

	mOps.unlock(VecWznmVJob::getSref(ixWznmVJob), "getOpsqkLast", "jref=" + to_string(jref));

	return retval;
};

void JobWznm::callback(
			const uint nextIxVSge
		) {
	nextIxVSgeSuccess = nextIxVSge;
	wrefLast = xchg->addWakeup(jref, "callback", 0);
};

void JobWznm::invalidateWakeups() {
	wrefMin = wrefLast + 1;
};

/******************************************************************************
 class CsjobWznm
 ******************************************************************************/

CsjobWznm::CsjobWznm(
			XchgWznm* xchg
			, const uint ixWznmVJob
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, ixWznmVJob, jrefSup, ixWznmVLocale)
		{
	srvNotCli = false;
	srv = NULL;
};

bool CsjobWznm::handleClaim(
			DbsWznm* dbswznm
			, map<ubigint,Claim*>& claims
			, const ubigint jrefNewest
		) {
	return false;
};

/******************************************************************************
 class ShrdatWznm
 ******************************************************************************/

ShrdatWznm::ShrdatWznm(
			const string& srefSupclass
			, const string& srefObject
		) :
			rwmAccess("shrdat.mAccess", srefSupclass + "::" + srefObject, srefObject)
		{
	this->srefSupclass = srefSupclass;
	this->srefObject = srefObject;
};

ShrdatWznm::~ShrdatWznm() {
};

void ShrdatWznm::init(
			XchgWznm* xchg
			, DbsWznm* dbswznm
		) {
};

void ShrdatWznm::term(
			XchgWznm* xchg
		) {
};

void ShrdatWznm::rlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.rlock(srefObject, srefMember, args);
};

void ShrdatWznm::runlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.runlock(srefObject, srefMember,args);
};

void ShrdatWznm::rlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.rlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWznm::runlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.runlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWznm::wlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wlock(srefObject, srefMember, args);
};

void ShrdatWznm::wunlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wunlock(srefObject, srefMember, args);
};

void ShrdatWznm::wlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWznm::wunlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wunlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class StmgrWznm
 ******************************************************************************/

StmgrWznm::StmgrWznm(
			XchgWznm* xchg
			, const ubigint jref
			, const uint ixVNonetype
		) :
			mAccess("stmgr.mAccess", "StmgrWznm", "StmgrWznm", "jref=" + to_string(jref))
		{
	this->xchg = xchg;

	this->jref = jref;
	this->ixVNonetype = ixVNonetype;

	stcch = new Stcch(true);
};

StmgrWznm::~StmgrWznm() {
	delete stcch;

	mAccess.lock("StmgrWznm", "~StmgrWznm", "jref=" + to_string(jref));
	mAccess.unlock("StmgrWznm", "~StmgrWznm", "jref=" + to_string(jref));
};

void StmgrWznm::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	set<uint> icsWznmVStub;
	pair<multimap<stcchitemref_t,Stcchitem*>::iterator,multimap<stcchitemref_t,Stcchitem*>::iterator> rng;

	bool notif = false;

	begin();

	if (call->ixVCall == VecWznmVCall::CALLWZNMAPPUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMAPPSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMAPPSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMBLKUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMBLKSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCALUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCALSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCARUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCARSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCHKUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCHKSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCMPUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCMPSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCONUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCONSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCONSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCONSREF);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCPBUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCPBSREF);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCPBSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCAPSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCTPSREF);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMCTPSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMDLGUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMDLGSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMEVTUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMEVTSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFEDUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMFEDSREF);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMFEDSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMFEDSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFILUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMFILSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIELUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMIELSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMIELSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIEXUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMIEXSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMIMEUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMIMESTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMJOBUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMJOBSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMLIBUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMLIBSREF);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMLIBSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMLIBSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMLOCUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMLOCSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMLOCSREF);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMLOCSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMCHUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMMCHSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMMCHSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMMCHSREF);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMDLUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMMDLSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMMTDUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMMTDSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPKUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMOPKSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMOPXUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMOPXSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPNLUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMPNLSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPRJUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMPRJSHORT);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMPRJSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMPRJSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPRSUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMPRSSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMPRSSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMPSTUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMPSTSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMPSTSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQCOUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMQCOSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMQCOSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQMDUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMQMDSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMQMDSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMQRYUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMQRYSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRELUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMRELSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMRELSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRLSUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMRLSSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRTBUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMRTBSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMRTBSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRTDUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMRTDSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMRTDSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRTJUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMRTJSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMRTJSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSBSUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSBSSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSEQUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSEQSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSEQSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSESUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSESSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSESMENU);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSESSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSESMENU);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSGEUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSGESTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSGESTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSQKUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSQKSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTBUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSTBSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSTEUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSTESTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMSTESTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTAGUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMTAGSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTBLUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMTBLSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMTCOUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMTCOSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMTCOSREF);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMTCOSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMUSGUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMUSGSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMGROUP);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMUSRUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMUSRSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMOWNER);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMUSRSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVECUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMVECSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVERUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMVERSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMVERNO);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMVERSHORT);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMVERSTD);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMVITUPD_REFEQ) {
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMVITSTD);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMVITSREF);
		insert(icsWznmVStub, VecWznmVStub::STUBWZNMVITSTD);
	};

	for (auto it = icsWznmVStub.begin(); it != icsWznmVStub.end(); it++) {
		rng = stcch->nodes.equal_range(stcchitemref_t(*it, call->argInv.ref, 0));
		for (auto it2 = rng.first; it2 != rng.second; it2++) if (refresh(dbswznm, it2->second)) notif = true;
	};

	commit();

	if (notif) xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMSTUBCHG, jref);
};

bool StmgrWznm::refresh(
			DbsWznm* dbswznm
			, Stcchitem* stit
		) {
	set<stcchitemref_t> strefsSub_backup;
	string stub_backup;

	while (!stit->strefsSup.empty()) stcch->unlink(*stit->strefsSup.begin(), stit->stref);

	strefsSub_backup = stit->strefsSub;
	stub_backup = stit->stub;

	StubWznm::getStub(dbswznm, stit->stref.ixVStub, stit->stref.ref, stit->stref.ixVLocale, ixVNonetype, stcch, NULL, true);

	if (stit->stub != stub_backup) {
		for (auto it = strefsSub_backup.begin(); it != strefsSub_backup.end(); it++) refresh(dbswznm, stcch->getStitByStref(*it));
		return true;
	} else return false;
};

void StmgrWznm::begin() {
	stcch->begin();
};

void StmgrWznm::commit() {
	for (auto it = stcch->icsVStubNew.begin(); it != stcch->icsVStubNew.end(); it++) {
		if (*it == VecWznmVStub::STUBWZNMAPPSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMAPPUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMAPPUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMBLKSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMBLKUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCALSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCALUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCAPSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCPBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCARSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCARUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCHKSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCHKUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCMPSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCMPUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCONSREF) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCONUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCONSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCONUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCONUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCPBSREF) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCPBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCPBSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCPBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCTPSREF) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCPBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMCTPSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMCPBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMDLGSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMDLGUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMEVTSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMEVTUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMFEDSREF) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMFEDUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMFEDSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMFEDUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMFEDUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMFILSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMFILUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMGROUP) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMUSGUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMIELSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMIELUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMIELUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMIEXSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMIEXUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMIMESTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMIMEUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMJOBSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMJOBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMLIBSREF) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMLIBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMLIBSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMLIBUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMLIBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMLOCSREF) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMLOCUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMLOCSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMLOCUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMLOCUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMMCHSREF) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMMCHUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMMCHSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMMCHUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMMCHUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMMDLSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMMDLUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMMTDSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMMTDUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMOPKSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMOPKUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMOPXSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMOPXUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMOWNER) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMUSRUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMPNLSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMPNLUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMPRJSHORT) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMPRJUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMPRJSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMPRJUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMPRJUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMPRSSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMPRSUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMPRSUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMPSTSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMPSTUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMPSTUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMQCOSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMQCOUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMQCOUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMQMDSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMQMDUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMQMDUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMQRYSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMQRYUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMRELSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMRELUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMRELUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMRLSSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMRLSUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMRTBSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMRTBUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMRTBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMRTDSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMRTDUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMRTDUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMRTJSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMRTJUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMRTJUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMSBSSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSBSUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMSEQSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSEQUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSEQUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMSESMENU) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSESUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSESUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMSESSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSESUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSESUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMSGESTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSGEUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSGEUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMSQKSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSQKUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMSTBSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSTBUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMSTESTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSTEUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMSTEUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMTAGSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMTAGUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMTBLSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMTBLUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMTCOSREF) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMTCOUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMTCOSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMTCOUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMTCOUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMUSGSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMUSGUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMUSRSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMUSRUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMUSRUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMVECSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMVECUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMVERNO) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMVERUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMVERSHORT) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMVERUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMVERSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMVERUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMVERUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMVITSREF) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMVITUPD_REFEQ, jref);
		} else if (*it == VecWznmVStub::STUBWZNMVITSTD) {
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMVITUPD_REFEQ, jref);
			xchg->addClstnStmgr(VecWznmVCall::CALLWZNMVITUPD_REFEQ, jref);
		};
	};

	stcch->commit();
};

void StmgrWznm::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void StmgrWznm::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class WakeupWznm
 ******************************************************************************/

WakeupWznm::WakeupWznm(
			XchgWznm* xchg
			, const ubigint wref
			, const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) {
	this->xchg = xchg;
	this->wref = wref;
	this->jref = jref;
	this->sref = sref;
	this->deltat = deltat;
	this->weak = weak;
};

/******************************************************************************
 class ExtcallWznm
 ******************************************************************************/

ExtcallWznm::ExtcallWznm(
			XchgWznm* xchg
			, Call* call
		) {
	this->xchg = xchg;
	this->call = call;
};

/******************************************************************************
 class NodeWznm
 ******************************************************************************/

NodeWznm::NodeWznm(
			const ubigint nref
			, const string& ip
			, const uint port
			, const uint opprcn
			, const uint ixWznmVOpengtype
		) {
	this->nref = nref;
	this->ip = ip;
	this->port = port;
	this->opprcn = opprcn;
	this->ixWznmVOpengtype = ixWznmVOpengtype;

	vector<uint> icsWznmVOppack;
	
	OpengWznm::getIcsWznmVOppackByIxWznmVOpengtype(ixWznmVOpengtype, icsWznmVOppack);
	for (unsigned int i = 0; i < icsWznmVOppack.size(); i++) OpengWznm::getIcsWznmVDpchByIxWznmVOppack(icsWznmVOppack[i], icsWznmVDpch);

	ixVState = VecVState::IDLE;
};

NodeWznm::~NodeWznm() {
};

// IP ShrdatJobprc.subs --- INSERT

/******************************************************************************
 class XchgWznmd::ShrdatJobprc
 ******************************************************************************/

XchgWznmd::ShrdatJobprc::ShrdatJobprc() :
			ShrdatWznm("XchgWznm", "ShrdatJobprc")
		{
};

void XchgWznmd::ShrdatJobprc::init(
			XchgWznm* xchg
			, DbsWznm* dbswznm
		) {
	// IP ShrdatJobprc.init --- INSERT
};

void XchgWznmd::ShrdatJobprc::term(
			XchgWznm* xchg
		) {
	// IP ShrdatJobprc.term --- INSERT
};

/******************************************************************************
 class XchgWznmd
 ******************************************************************************/

XchgWznmd::XchgWznmd() :
			cStable("cStable", "XchgWznmd", "XchgWznmd")
			, mLogfile("mLogfile", "XchgWznmd", "XchgWznmd")
			, cOpengcli("cOpengcli", "XchgWznmd", "XchgWznmd")
			, cJobprcs("cJobprcs", "XchgWznmd", "XchgWznmd")
			, cOpprcs("cOpprcs", "XchgWznmd", "XchgWznmd")
			, mReqs("mReqs", "XchgWznmd", "XchgWznmd")
			, orefseq("orefseq")
			, mInvs("mInvs", "XchgWznmd", "XchgWznmd")
			, rwmPresets("rwmPresets", "XchgWznmd", "XchgWznmd")
			, rwmStmgrs("rwmStmgrs", "XchgWznmd", "XchgWznmd")
			, rwmClstns("rwmClstns", "XchgWznmd", "XchgWznmd")
			, rwmDcols("rwmDcols", "XchgWznmd", "XchgWznmd")
			, jrefseq("jrefseq")
			, rwmJobs("rwmJobs", "XchgWznmd", "XchgWznmd")
			, rwmCsjobinfos("rwmCsjobinfos", "XchgWznmd", "XchgWznmd")
			, wrefseq("wrefseq")
			, nrefseq("nrefseq")
			, rwmNodes("rwmNodes", "XchgWznmd", "XchgWznmd")
		{
	// root job
	jrefRoot = 0;

	// job receiving commands
	jrefCmd = 0;

	termOpengcli = false;

	// client-server job information
	csjobinfos[VecWznmVJob::JOBWZNMLICENSE] = new Csjobinfo(VecWznmVJob::JOBWZNMLICENSE);

};

XchgWznmd::~XchgWznmd() {
	// empty out lists
	for (auto it = reqs.begin(); it != reqs.end(); it++) delete(*it);
	for (auto it = invs.begin(); it != invs.end(); it++) delete(*it);
	for (auto it = presets.begin(); it != presets.end(); it++) delete(it->second);
	for (auto it = stmgrs.begin(); it != stmgrs.end(); it++) delete(it->second);
	for (auto it = clstns.begin(); it != clstns.end(); it++) delete(it->second);
	for (auto it = dcols.begin(); it != dcols.end(); it++) delete(it->second);
	for (auto it = jobs.begin(); it != jobs.end(); it++) delete(it->second);
	for (auto it = jobinfos.begin(); it != jobinfos.end(); it++) delete(it->second);
	for (auto it = csjobinfos.begin(); it != csjobinfos.end(); it++) delete(it->second);
	for (auto it = nodes.begin(); it != nodes.end(); it++) delete(it->second);
};

// IP cust --- INSERT

void XchgWznmd::startMon() {
	JobWznm* job = NULL;
	Jobinfo* jobinfo = NULL;

	DcolWznm* dcol = NULL;
	bool Dcol;

	StmgrWznm* stmgr = NULL;
	bool Stmgr;

	Clstn* clstn = NULL;
	Preset* preset = NULL;
	NodeWznm* node = NULL;

	mon.start("WhizniumSBE v1.1.9", stgwznmpath.monpath);

	rwmJobs.rlock("XchgWznmd", "startMon");
	for (auto it = jobs.begin(); it != jobs.end(); it++) {
		job = it->second;
		jobinfo = jobinfos[job->jref];

		dcol = getDcolByJref(job->jref, false);
		if (dcol) {
			Dcol = true;
			dcol->unlockAccess("XchgWznmd", "startMon");
		} else Dcol = false;

		stmgr = getStmgrByJref(job->jref);
		if (stmgr) {
			Stmgr = true;
			stmgr->unlockAccess("XchgWznmd", "startMon");
		} else Stmgr = false;

		if (getCsjobNotJob(job->ixWznmVJob)) mon.insertJob(jobinfo->jrefSup, VecWznmVJob::getSref(job->ixWznmVJob), job->jref, true, ((CsjobWznm*) job)->srvNotCli, Dcol, Stmgr);
		else mon.insertJob(jobinfo->jrefSup, VecWznmVJob::getSref(job->ixWznmVJob), job->jref, false, false, Dcol, Stmgr);
	};
	rwmJobs.runlock("XchgWznmd", "startMon");

	rwmClstns.rlock("XchgWznmd", "startMon");
	for (auto it = clstns.begin(); it != clstns.end(); it++) {
		clstn = it->second;
		mon.insertClstn(clstn->cref.jref, Clstn::VecVTarget::getSref(clstn->cref.ixVTarget), VecWznmVCall::getSref(clstn->cref.ixVCall), Clstn::VecVJobmask::getSref(clstn->cref.ixVJobmask), clstn->cref.jrefTrig, clstn->cref.arg, clstn->cref.ixVSge, Clstn::VecVJactype::getSref(clstn->ixVJactype));
	};
	rwmClstns.runlock("XchgWznmd", "startMon");

	rwmPresets.rlock("XchgWznmd", "startMon");
	for (auto it = presets.begin(); it != presets.end(); it++) {
		preset = it->second;
		mon.insertPreset(preset->pref.jref, VecWznmVPreset::getSref(preset->pref.ixVPreset), preset->arg);
	};
	rwmPresets.runlock("XchgWznmd", "startMon");

	rwmNodes.rlock("XchgWznmd", "startMon");
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		node = it->second;
		mon.insertNode(node->nref, node->ip, node->port, node->opprcn);
	};
	rwmNodes.runlock("XchgWznmd", "startMon");

	triggerCall(NULL, VecWznmVCall::CALLWZNMMONSTATCHG, jrefRoot);
};

void XchgWznmd::stopMon() {
	mon.stop();

	triggerCall(NULL, VecWznmVCall::CALLWZNMMONSTATCHG, jrefRoot);
};

void XchgWznmd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	mLogfile.lock("XchgWznmd", "appendToLogfile");

	time(&rawtime);

	logfile.open(exedir + "/log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	mLogfile.unlock("XchgWznmd", "appendToLogfile");
};

void XchgWznmd::addReq(
			ReqWznm* req
		) {
	if (jrefRoot == 0) return;

	mReqs.lock("XchgWznmd", "addReq", "jref=" + to_string(req->jref));

	req->ixVState = ReqWznm::VecVState::WAITPRC;
	reqs.push_back(req);

	mReqs.unlock("XchgWznmd", "addReq", "jref=" + to_string(req->jref));

	cJobprcs.signal("XchgWznmd", "addReq", "jref=" + to_string(req->jref));
};

ReqWznm* XchgWznmd::pullFirstReq() {
	ReqWznm* req;

	// get first element from list
	mReqs.lock("XchgWznmd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqWznm::VecVState::PRC;
		reqs.pop_front();
	};

	mReqs.unlock("XchgWznmd", "pullFirstReq");

	return req;
};

void XchgWznmd::addInvs(
			DbsWznm* dbswznm
			, JobWznm* job
			, vector<DpchInvWznm*>& dpchinvs
		) {
	// append to inv list and signal the news (note the double-lock)
	mInvs.lock("XchgWznmd", "addInvs", "jref=" + to_string(job->jref));
	job->mOps.lock("XchgWznmd", "addInvs", "jref=" + to_string(job->jref));

	for (unsigned int i = 0; i < dpchinvs.size(); i++) {
		job->addOp(dbswznm, dpchinvs[i]);

		invs.push_back(dpchinvs[i]);

		mon.eventAddInv(job->jref, VecWznmVDpch::getSref(dpchinvs[i]->ixWznmVDpch), "", dpchinvs[i]->oref);
	};

	job->mOps.unlock("XchgWznmd", "addInvs", "jref=" + to_string(job->jref));
	mInvs.unlock("XchgWznmd", "addInvs", "jref=" + to_string(job->jref));

	cOpprcs.broadcast("XchgWznmd", "addInvs", "jref=" + to_string(job->jref));
};

DpchInvWznm* XchgWznmd::pullFirstInv(
			NodeWznm* node
		) {
	bool match = false;

	DpchInvWznm* inv;

	// get first matching element from list
	mInvs.lock("XchgWznmd", "pullFirstInv");

	for (auto it = invs.begin(); it != invs.end(); it++) {
		inv = *it;

		if (node->icsWznmVDpch.find(inv->ixWznmVDpch) != node->icsWznmVDpch.end()) {
			// match found

			// remove inv from list
			invs.erase(it);

			match = true;
			break;
		};
	};

	mInvs.unlock("XchgWznmd", "pullFirstInv");

	if (match) return inv;
	else return NULL;
};

void XchgWznmd::returnInv(
			DpchInvWznm* dpchinv
		) {
	// un-successful execution of op returns

	// append to inv list and signal the news
	mInvs.lock("XchgWznmd", "returnInv", "oref=" + to_string(dpchinv->oref));
	invs.push_back(dpchinv);
	mInvs.unlock("XchgWznmd", "returnInv", "oref=" + to_string(dpchinv->oref));

	cOpprcs.broadcast("XchgWznmd", "returnInv", "oref=" + to_string(dpchinv->oref));
};

Preset* XchgWznmd::addPreset(
			const uint ixWznmVPreset
			, const ubigint jref
			, const Arg& arg
		) {
	presetref_t pref(jref, ixWznmVPreset);
	Preset* preset;

	// create new presetting (override value if exists) and append to presetting list
	preset = getPresetByPref(pref);

	rwmPresets.wlock("XchgWznmd", "addPreset", "jref=" + to_string(jref));

	if (preset) {
		preset->arg = arg;

		mon.eventChangePreset(jref, VecWznmVPreset::getSref(ixWznmVPreset), arg);

	} else {
		preset = new Preset(pref, arg);
		presets.insert(pair<presetref_t,Preset*>(pref, preset));

		mon.eventAddPreset(jref, VecWznmVPreset::getSref(ixWznmVPreset), arg);
	};

	rwmPresets.wunlock("XchgWznmd", "addPreset", "jref=" + to_string(jref));

	return(preset);
};

Preset* XchgWznmd::addIxPreset(
			const uint ixWznmVPreset
			, const ubigint jref
			, const uint ix
		) {
	return(addPreset(ixWznmVPreset, jref, Arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX)));
};

Preset* XchgWznmd::addRefPreset(
			const uint ixWznmVPreset
			, const ubigint jref
			, const ubigint ref
		) {
	return(addPreset(ixWznmVPreset, jref, Arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF)));
};

Preset* XchgWznmd::addRefsPreset(
			const uint ixWznmVPreset
			, const ubigint jref
			, const vector<ubigint>& refs
		) {
	Arg arg(0, 0, refs, "", 0, 0.0, false, "", Arg::REFS);

	return(addPreset(ixWznmVPreset, jref, arg));
};

Preset* XchgWznmd::addSrefPreset(
			const uint ixWznmVPreset
			, const ubigint jref
			, const string& sref
		) {
	return(addPreset(ixWznmVPreset, jref, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF)));
};

Preset* XchgWznmd::addIntvalPreset(
			const uint ixWznmVPreset
			, const ubigint jref
			, const int intval
		) {
	return(addPreset(ixWznmVPreset, jref, Arg(0, 0, {}, "", intval, 0.0, false, "", Arg::INTVAL)));
};

Preset* XchgWznmd::addDblvalPreset(
			const uint ixWznmVPreset
			, const ubigint jref
			, const double dblval
		) {
	return(addPreset(ixWznmVPreset, jref, Arg(0, 0, {}, "", 0, dblval, false, "", Arg::DBLVAL)));
};

Preset* XchgWznmd::addBoolvalPreset(
			const uint ixWznmVPreset
			, const ubigint jref
			, const bool boolval
		) {
	return(addPreset(ixWznmVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, boolval, "", Arg::BOOLVAL)));
};

Preset* XchgWznmd::addTxtvalPreset(
			const uint ixWznmVPreset
			, const ubigint jref
			, const string& txtval
		) {
	return(addPreset(ixWznmVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, false, txtval, Arg::TXTVAL)));
};

Preset* XchgWznmd::getPresetByPref(
			const presetref_t& pref
		) {
	Preset* preset = NULL;

	rwmPresets.rlock("XchgWznmd", "getPresetByPref");

	auto it = presets.find(pref);
	if (it != presets.end()) preset = it->second;

	rwmPresets.runlock("XchgWznmd", "getPresetByPref");

	return preset;
};

Arg XchgWznmd::getPreset(
			const uint ixWznmVPreset
			, ubigint jref
		) {
	Arg arg;

	Jobinfo* jobinfo = NULL;
	Preset* preset = NULL;

	if ( (ixWznmVPreset == VecWznmVPreset::PREWZNMSYSDATE) || (ixWznmVPreset == VecWznmVPreset::PREWZNMSYSTIME) || (ixWznmVPreset == VecWznmVPreset::PREWZNMSYSSTAMP) ) {
		time_t rawtime;
		time(&rawtime);

		if (ixWznmVPreset == VecWznmVPreset::PREWZNMSYSSTAMP) {
			arg.mask = Arg::REF;
			arg.ref = rawtime;

		} else {
			arg.mask = Arg::INTVAL;

			if (ixWznmVPreset == VecWznmVPreset::PREWZNMSYSDATE) arg.intval = (rawtime-rawtime%(3600*24))/(3600*24);
			else arg.intval = rawtime%(3600*24);
		};

	} else {
		rwmJobs.rlock("XchgWznmd", "getPreset", "jref=" + to_string(jref));
		rwmPresets.rlock("XchgWznmd", "getPreset", "jref=" + to_string(jref));

		jobinfo = getJobinfoByJref(jref);

		if (jobinfo && (ixWznmVPreset == VecWznmVPreset::PREWZNMIXLCL)) {
			arg.mask = Arg::IX;
			arg.ix = jobs[jref]->ixWznmVLocale;

		} else {
			while (jobinfo && !preset) {
				preset = getPresetByPref(presetref_t(jref, ixWznmVPreset));

				if (preset) arg = preset->arg;
				else {
					jref = jobinfo->jrefSup;
					jobinfo = getJobinfoByJref(jref);
				};
			};
		};

		rwmPresets.runlock("XchgWznmd", "getPreset", "jref=" + to_string(jref));
		rwmJobs.runlock("XchgWznmd", "getPreset", "jref=" + to_string(jref));
	};

	return(arg);
};

uint XchgWznmd::getIxPreset(
			const uint ixWznmVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWznmVPreset, jref);

	if (arg.mask & Arg::IX) return(arg.ix);
	else return(0);
};

ubigint XchgWznmd::getRefPreset(
			const uint ixWznmVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWznmVPreset, jref);

	if (arg.mask & Arg::REF) return(arg.ref);
	else return(0);
};

vector<ubigint> XchgWznmd::getRefsPreset(
			const uint ixWznmVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWznmVPreset, jref);
	vector<ubigint> empty;

	if (arg.mask & Arg::REFS) return(arg.refs);
	else return(empty);
};

string XchgWznmd::getSrefPreset(
			const uint ixWznmVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWznmVPreset, jref);

	if (arg.mask & Arg::SREF) return(arg.sref);
	else return("");
};

int XchgWznmd::getIntvalPreset(
			const uint ixWznmVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWznmVPreset, jref);

	if (arg.mask & Arg::INTVAL) return(arg.intval);
	else return(intvalInvalid);
};

double XchgWznmd::getDblvalPreset(
			const uint ixWznmVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWznmVPreset, jref);

	if (arg.mask & Arg::DBLVAL) return(arg.dblval);
	else return(dblvalInvalid);
};

bool XchgWznmd::getBoolvalPreset(
			const uint ixWznmVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWznmVPreset, jref);

	if (arg.mask & Arg::BOOLVAL) return(arg.boolval);
	else return(false);
};

string XchgWznmd::getTxtvalPreset(
			const uint ixWznmVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWznmVPreset, jref);

	if (arg.mask & Arg::TXTVAL) return(arg.txtval);
	else return("");
};

void XchgWznmd::getPresetsByJref(
			const ubigint jref
			, vector<uint>& icsWznmVPreset
			, vector<Arg>& args
		) {
	Preset* preset = NULL;

	icsWznmVPreset.clear();
	args.clear();

	rwmPresets.rlock("XchgWznmd", "getPresetsByJref", "jref=" + to_string(jref));

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		preset = it->second;

		icsWznmVPreset.push_back(preset->pref.ixVPreset);
		args.push_back(preset->arg);
	};

	rwmPresets.runlock("XchgWznmd", "getPresetsByJref", "jref=" + to_string(jref));
};

void XchgWznmd::removePreset(
			const uint ixWznmVPreset
			, const ubigint jref
		) {
	rwmPresets.wlock("XchgWznmd", "removePreset", "jref=" + to_string(jref) + ",srefIxWznmVPreset=" + VecWznmVPreset::getSref(ixWznmVPreset));

	auto it = presets.find(presetref_t(jref, ixWznmVPreset));
	if (it != presets.end()) {
		delete it->second;
		presets.erase(it);

		mon.eventRemovePreset(jref, VecWznmVPreset::getSref(ixWznmVPreset));
	};

	rwmPresets.wunlock("XchgWznmd", "removePreset", "jref=" + to_string(jref) + ",srefIxWznmVPreset=" + VecWznmVPreset::getSref(ixWznmVPreset));
};

void XchgWznmd::removePresetsByJref(
			const ubigint jref
		) {
	rwmPresets.wlock("XchgWznmd", "removePresetsByJref", "jref=" + to_string(jref));

	uint ixVPreset;

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVPreset = it->second->pref.ixVPreset;
		delete it->second;

		mon.eventRemovePreset(jref, VecWznmVPreset::getSref(ixVPreset));
	};
	presets.erase(rng.first, rng.second);

	rwmPresets.wunlock("XchgWznmd", "removePresetsByJref", "jref=" + to_string(jref));
};

StmgrWznm* XchgWznmd::addStmgr(
			const ubigint jref
			, const uint ixVNonetype
		) {
	StmgrWznm* stmgr = NULL;

	// create new stmgr and append to stmgr list
	stmgr = getStmgrByJref(jref);

	if (!stmgr) {
		rwmStmgrs.wlock("XchgWznmd", "addStmgr", "jref=" + to_string(jref));

		stmgr = new StmgrWznm(this, jref, ixVNonetype);
		stmgrs[jref] = stmgr;

		rwmStmgrs.wunlock("XchgWznmd", "addStmgr", "jref=" + to_string(jref));

		mon.eventAddStmgr(jref);
	};

	return(stmgr);
};

StmgrWznm* XchgWznmd::getStmgrByJref(
			const ubigint jref
		) {
	StmgrWznm* stmgr = NULL;

	rwmStmgrs.rlock("XchgWznmd", "getStmgrByJref", "jref=" + to_string(jref));

	auto it = stmgrs.find(jref);

	if (it != stmgrs.end()) {
		stmgr = it->second;
		stmgr->lockAccess("XchgWznmd", "getStmgrByJref");
	};

	rwmStmgrs.runlock("XchgWznmd", "getStmgrByJref", "jref=" + to_string(jref));

	return(stmgr);
};

void XchgWznmd::removeStmgrByJref(
			const ubigint jref
		) {
	rwmStmgrs.wlock("XchgWznmd", "removeStmgrByJref", "jref=" + to_string(jref));

	removeClstnsByJref(jref, Clstn::VecVTarget::STMGR);

	auto it = stmgrs.find(jref);
	if (it != stmgrs.end()) {
		delete it->second;
		stmgrs.erase(it);

		mon.eventRemoveStmgr(jref);
	};

	rwmStmgrs.wunlock("XchgWznmd", "removeStmgrByJref", "jref=" + to_string(jref));
};

Clstn* XchgWznmd::addClstn(
			const uint ixWznmVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const Arg& arg
			, const uint ixVSge
			, const uint ixVJactype
		) {
	clstnref_t cref(ixWznmVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, arg, ixVSge);
	clstnref2_t cref2(cref);

	multimap<clstnref_t,Clstn*>::iterator it;
	Clstn* clstn = NULL;

	rwmClstns.wlock("XchgWznmd", "addClstn", "jref=" + to_string(jref) + ",srefIxWznmVCall=" + VecWznmVCall::getSref(ixWznmVCall));

	if (!chgarg) it = clstns.end();
	else {
		Arg argFind = arg;
		argFind.clearContent();

		clstnref_t crefFind(ixWznmVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, argFind, ixVSge);

		it = clstns.find(crefFind);
	};

	if (it == clstns.end()) {
		// create new clstn and append to clstn list
		clstn = new Clstn(cref, ixVJactype);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(jref, "job", VecWznmVCall::getSref(ixWznmVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));

	} else {
		// change clstn argument
		clstn = it->second;
		clstn->cref = cref;

		cref2sClstns.erase(clstnref2_t(it->first));
		clstns.erase(it->first);

		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));
		
		mon.eventChangeClstnArg(jref, "job", VecWznmVCall::getSref(ixWznmVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));
	};

	rwmClstns.wunlock("XchgWznmd", "addClstn", "jref=" + to_string(jref) + ",srefIxWznmVCall=" + VecWznmVCall::getSref(ixWznmVCall));

	return(clstn);
};

Clstn* XchgWznmd::addIxClstn(
			const uint ixWznmVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX);

	return(addClstn(ixWznmVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWznmd::addRefClstn(
			const uint ixWznmVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF);

	return(addClstn(ixWznmVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWznmd::addIxRefClstn(
			const uint ixWznmVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);

	return(addClstn(ixWznmVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWznmd::addIxRefSrefClstn(
			const uint ixWznmVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const string& sref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, sref, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);

	return(addClstn(ixWznmVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWznmd::addClstnStmgr(
			const uint ixWznmVCall
			, const ubigint jref
		) {
	clstnref_t cref(ixWznmVCall, jref, Clstn::VecVTarget::STMGR, Clstn::VecVJobmask::ALL);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	clstn = getClstnByCref(cref);

	if (!clstn) {
		rwmClstns.wlock("XchgWznmd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxWznmVCall=" + VecWznmVCall::getSref(ixWznmVCall));

		clstn = new Clstn(cref, Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		rwmClstns.wunlock("XchgWznmd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxWznmVCall=" + VecWznmVCall::getSref(ixWznmVCall));

		mon.eventAddClstn(jref, "stmgr", VecWznmVCall::getSref(ixWznmVCall), Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::ALL), 0, Arg(), 0, Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	return(clstn);
};

Clstn* XchgWznmd::getClstnByCref(
			const clstnref_t& cref
		) {
	Clstn* clstn = NULL;

	rwmClstns.rlock("XchgWznmd", "getClstnByCref");

	auto it = clstns.find(cref);
	if (it != clstns.end()) clstn = it->second;

	rwmClstns.runlock("XchgWznmd", "getClstnByCref");

	return clstn;
};

void XchgWznmd::getClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
			, vector<uint>& icsWznmVCall
			, vector<uint>& icsVJobmask
		) {
	Clstn* clstn = NULL;

	icsWznmVCall.clear();
	icsVJobmask.clear();

	rwmClstns.rlock("XchgWznmd", "getClstnsByJref", "jref=" + to_string(jref));

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = getClstnByCref(it->second);

		if (clstn) {
			icsWznmVCall.push_back(clstn->cref.ixVCall);
			icsVJobmask.push_back(clstn->cref.ixVJobmask);
		};
	};

	rwmClstns.runlock("XchgWznmd", "getClstnsByJref", "jref=" + to_string(jref));
};

void XchgWznmd::removeClstns(
			const uint ixWznmVCall
			, const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgWznmd", "removeClstns", "jref=" + to_string(jref));

	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = clstns.equal_range(clstnref_t(ixWznmVCall, jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVJobmask = it->second->cref.ixVJobmask;
		jrefTrig = it->second->cref.jrefTrig;
		arg = it->second->cref.arg;
		ixVSge = it->second->cref.ixVSge;
		ixVJactype = it->second->ixVJactype;

		cref2sClstns.erase(clstnref2_t(it->first));
		delete it->second;

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecWznmVCall::getSref(ixWznmVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	clstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgWznmd", "removeClstns", "jref=" + to_string(jref));
};

void XchgWznmd::removeClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgWznmd", "removeClstnsByJref", "jref=" + to_string(jref));

	uint ixVCall;
	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		auto it2 = clstns.find(it->second);

		ixVCall = it2->second->cref.ixVCall;
		ixVJobmask = it2->second->cref.ixVJobmask;
		jrefTrig = it2->second->cref.jrefTrig;
		arg = it2->second->cref.arg;
		ixVSge = it2->second->cref.ixVSge;
		ixVJactype = it2->second->ixVJactype;

		delete it2->second;
		clstns.erase(it2);

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecWznmVCall::getSref(ixVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	cref2sClstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgWznmd", "removeClstnsByJref", "jref=" + to_string(jref));
};

void XchgWznmd::findJrefsByCall(
			Call* call
			, vector<ubigint>& jrefTrigs
			, vector<ubigint>& jrefs
			, vector<uint>& icsVTarget
			, vector<uint>& icsVJactype
		) {
	Clstn* clstn = NULL;

	set<ubigint> jrefsClissrv;

	ubigint jrefTrig;
	bool match;

	rwmJobs.rlock("XchgWznmd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmClstns.rlock("XchgWznmd", "findJrefsByCall", "jref=" + to_string(call->jref));

	jrefsClissrv = getCsjobClisByJref(call->jref);
	jrefsClissrv.insert(call->jref);

	auto rng = clstns.equal_range(clstnref_t(call->ixVCall, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = it->second;

		jrefTrig = call->jref;

		if (clstn->cref.ixVTarget == Clstn::VecVTarget::JOB) {
			match = true;

			if (clstn->cref.arg.mask & Arg::IX) if (clstn->cref.arg.ix != call->argInv.ix) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::REF) if (clstn->cref.arg.ref != call->argInv.ref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::INTVAL) if (clstn->cref.arg.intval != call->argInv.intval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::DBLVAL) if (clstn->cref.arg.dblval != call->argInv.dblval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::BOOLVAL) if (clstn->cref.arg.boolval != call->argInv.boolval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::TXTVAL) if (clstn->cref.arg.txtval != call->argInv.txtval) match = false;

			if (match) if (clstn->cref.ixVSge != 0) if (clstn->cref.ixVSge != jobinfos[clstn->cref.jref]->ixVSge) match = false;

			if (match) {
				match = false;

				if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::ALL) {
					// don't care about jrefsClissrv
					match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::IMM) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// check if trigger job is immediate sub-job to listener job
						if (clstn->cref.jref == jobinfos[*it]->jrefSup) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SELF) {
					// check if trigger job is equivalent to listener job
					if (clstn->cref.jref == call->jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// require specific jref
						if (clstn->cref.jrefTrig == (*it)) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::TREE) {
					if (clstn->cref.jref == call->jref) match = true;
					else {
						for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
							// check if trigger job is down the tree from listener job
							if (getJobSup(clstn->cref.jref, *it)) {
								jrefTrig = *it;
								match = true;
								break;
							};
						};
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(clstn->ixVJactype);
			};

		} else if (clstn->cref.ixVTarget == Clstn::VecVTarget::STMGR) {
			jrefTrigs.push_back(jrefTrig);
			jrefs.push_back(clstn->cref.jref);
			icsVTarget.push_back(clstn->cref.ixVTarget);
			icsVJactype.push_back(0);

		} else {
			// targets DDSPUB and UASRV
			match = true;

			if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;

			if (match) if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
				match = false;

				for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
					// require specific jref
					if (clstn->cref.jrefTrig == (*it)) {
						jrefTrig = *it;
						match = true;
						break;
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(0);
			};
		};
	};

	rwmClstns.runlock("XchgWznmd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmJobs.runlock("XchgWznmd", "findJrefsByCall", "jref=" + to_string(call->jref));
};

void XchgWznmd::triggerCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	vector<ubigint> jrefTrigs;
	vector<ubigint> jrefs;
	vector<uint> icsVTarget;
	vector<uint> icsVJactype;

	uint ixVTarget;
	ubigint jref;
	uint ixVJactype;

	JobWznm* job = NULL;

	StmgrWznm* stmgr = NULL;

	ubigint eref;

	Arg argRet_old;

	eref = mon.eventTriggerCall(call->jref, VecWznmVCall::getSref(call->ixVCall), call->argInv);

	findJrefsByCall(call, jrefTrigs, jrefs, icsVTarget, icsVJactype);

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		call->jref = jrefTrigs[i];
		jref = jrefs[i];
		ixVTarget = icsVTarget[i];
		ixVJactype = icsVJactype[i];

		if (ixVTarget == Clstn::VecVTarget::JOB) {
			job = getJobByJref(jref);
			if (job) {
				if (ixVJactype != Clstn::VecVJactype::WEAK) {
					if (ixVJactype == Clstn::VecVJactype::LOCK) {
						job->lockAccess("XchgWznmd", "triggerCall");

					} else if (ixVJactype == Clstn::VecVJactype::TRY) {
						if (!job->trylockAccess("XchgWznmd", "triggerCall")) continue;
					};
				};

				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				job->handleCall(dbswznm, call);

				if (call->argRet != argRet_old) mon.eventRetCall(eref, jref, call->argRet);
			};

			if (ixVJactype != Clstn::VecVJactype::WEAK) {
				job = getJobByJref(jref);
				if (job) job->unlockAccess("XchgWznmd", "triggerCall");
			};

		} else if (ixVTarget == Clstn::VecVTarget::STMGR) {
			stmgr = getStmgrByJref(jref);

			if (stmgr) {
				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				stmgr->handleCall(dbswznm, call);

				if (!(call->argRet == argRet_old)) mon.eventRetCall(eref, jref, call->argRet);

				stmgr->unlockAccess("XchgWznmd", "triggerCall");
			};

		};

		if (call->abort) break;
	};

	mon.eventFinalizeCall(eref);
};

bool XchgWznmd::triggerArgToArgCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const Arg& argInv
			, Arg& argRet
		) {
	Call* call;
	ubigint retval;

	call = new Call(ixWznmVCall, jref, argInv);
	triggerCall(dbswznm, call);

	argRet = call->argRet;
	retval = call->abort;

	delete call;
	return retval;
};

bool XchgWznmd::triggerCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
		) {
	Arg argInv;
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerIxCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerRefCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const ubigint refInv
		) {
	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerIntvalCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const int intvalInv
		) {
	Arg argInv(0, 0, {}, "", intvalInv, 0.0, false, "", Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerBoolvalCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const bool boolvalInv
		) {
	Arg argInv(0, 0, {}, "", 0, 0.0, boolvalInv, "", Arg::BOOLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerIxRefCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
		) {
	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerIxSrefCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
		) {
	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerIxSrefToIxCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;
	
	return retval;
};

bool XchgWznmd::triggerIxIntvalCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const int intvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", intvalInv, 0.0, false, "", Arg::IX + Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerIxDblvalCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const double dblvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, dblvalInv, false, "", Arg::IX + Arg::DBLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerIxTxtvalCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const string& txtvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, txtvalInv, Arg::IX + Arg::TXTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerSrefCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const string& srefInv
		) {
	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet));
};

bool XchgWznmd::triggerToBoolvalCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv;
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWznmd::triggerIxToBoolvalCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWznmd::triggerRefToSrefCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const ubigint refInv
			, string& srefRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) srefRet = argRet.sref;

	return(retval);
};

bool XchgWznmd::triggerRefToBoolvalCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWznmd::triggerIxRefToIxCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgWznmd::triggerIxRefToRefCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgWznmd::triggerIxRefSrefCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgWznmd::triggerIxRefSrefIntvalCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgWznmd::triggerIxRefSrefIntvalToRefCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgWznmd::triggerRefToIxCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgWznmd::triggerSrefToRefCall(
			DbsWznm* dbswznm
			, const uint ixWznmVCall
			, const ubigint jref
			, const string& srefInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswznm, ixWznmVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

DcolWznm* XchgWznmd::addDcol(
			const ubigint jref
		) {
	JobWznm* job = NULL;

	DcolWznm* dcol = NULL;

	// create new dcol and append to dcol list
	rwmJobs.rlock("XchgWznmd", "addDcol", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
		dcol = getDcolByJref(jref);

		if (!dcol) {
			rwmDcols.wlock("XchgWznmd", "addDcol", "jref=" + to_string(jref));

			dcol = new DcolWznm(jref, job->ixWznmVLocale);
			dcols[jref] = dcol;

			dcol->lockAccess("XchgWznmd", "addDcol");

			rwmDcols.wunlock("XchgWznmd", "addDcol", "jref=" + to_string(jref));

			mon.eventAddDcol(jref);
		};
	};

	rwmJobs.runlock("XchgWznmd", "addDcol", "jref=" + to_string(jref));

	// make dcol the session's active notify dcol
	triggerIxRefCall(NULL, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMJREFNOTIFY, jref);

	return(dcol);
};

DcolWznm* XchgWznmd::getDcolByJref(
			ubigint jref
			, const bool tree
		) {
	Jobinfo* jobinfo = NULL;

	DcolWznm* dcol = NULL;

	rwmJobs.rlock("XchgWznmd", "getDcolByJref", "jref=" + to_string(jref));
	rwmDcols.rlock("XchgWznmd", "getDcolByJref", "jref=" + to_string(jref));

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo != NULL) {
		auto it = dcols.find(jref);

		if (it != dcols.end()) {
			dcol = it->second;
			dcol->lockAccess("XchgWznmd", "getDcolByJref");

			break;
		};

		if (!tree) break;

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	rwmDcols.runlock("XchgWznmd", "getDcolByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgWznmd", "getDcolByJref", "jref=" + to_string(jref));

	return(dcol);
};

void XchgWznmd::removeDcolByJref(
			const ubigint jref
		) {
	rwmDcols.wlock("XchgWznmd", "removeDcolByJref", "jref=" + to_string(jref));

	auto it = dcols.find(jref);
	if (it != dcols.end()) {
		delete it->second;
		dcols.erase(it);

		mon.eventRemoveDcol(jref);
	};

	rwmDcols.wunlock("XchgWznmd", "removeDcolByJref", "jref=" + to_string(jref));
};

void XchgWznmd::removeDcolsByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	vector<ubigint> jrefs;

	rwmJobs.rlock("XchgWznmd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmDcols.wlock("XchgWznmd", "removeDcolsByJref", "jref=" + to_string(jref));

	jrefs.push_back(jref);

	// sub-tree without recursion
	for (unsigned int i = 0; i < jrefs.size(); i++) {
		jobinfo = getJobinfoByJref(jrefs[i]);

		if (jobinfo) for (auto it = jobinfo->jrefsSub.begin(); it != jobinfo->jrefsSub.end(); it++) jrefs.push_back(*it);
	};

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		auto it = dcols.find(jrefs[i]);
		if (it != dcols.end()) {
			delete it->second;
			dcols.erase(it);

			mon.eventRemoveDcol(jrefs[i]);
		};
	};

	rwmDcols.wunlock("XchgWznmd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgWznmd", "removeDcolsByJref", "jref=" + to_string(jref));
};

void XchgWznmd::submitDpch(
			DpchEngWznm* dpcheng
		) {
	DcolWznm* dcol = NULL;

	Cond* cReady_backup;

	DpchEngWznm* dpchtest;

	// find dcol in charge
	dcol = getDcolByJref(dpcheng->jref);

	if (dcol) {
		mon.eventSubmitDpch(dpcheng->jref, VecWznmVDpch::getSref(dpcheng->ixWznmVDpch), dpcheng->getSrefsMask(), "");

		if (dcol->req != NULL) {
			// a request is waiting
			delete dcol->req->dpcheng;
			dcol->req->dpcheng = dpcheng;

			cReady_backup = &(dcol->req->cReady);

			dcol->req = NULL;
			//cout << "XchgWznmd::submitDpch() waiting request for ixWznmVDpch = " << dpcheng->ixWznmVDpch << ", jref = " << dpcheng->jref << endl;

			cReady_backup->signal("XchgWznmd", "submitDpch", "jref=" + to_string(dcol->jref));

			dcol->unlockAccess("XchgWznmd", "submitDpch");

		} else {
			// merge with similar dispatch if available
			for (auto it = dcol->dpchs.begin(); it != dcol->dpchs.end();) {
				dpchtest = *it;

				if ((dpchtest->ixWznmVDpch == dpcheng->ixWznmVDpch) && (dpchtest->jref == dpcheng->jref)) {
					dpchtest->merge(dpcheng);
					//cout << "XchgWznmd::submitDpch() merge for ixWznmVDpch = " << dpcheng->ixWznmVDpch << ", jref = " << dpcheng->jref << endl;

					delete dpcheng;
					dpcheng = NULL;

					break;

				} else it++;
			};

			// append to list of dispatches
			if (dpcheng) {
				dcol->dpchs.push_back(dpcheng);
				//cout << "XchgWznmd::submitDpch() append for ixWznmVDpch = " << dpcheng->ixWznmVDpch << ", jref = " << dpcheng->jref << endl;
			};

			dcol->unlockAccess("XchgWznmd", "submitDpch");
		};

	} else {
		delete dpcheng;
	};
};

DpchEngWznm* XchgWznmd::pullFirstDpch(
			DcolWznm* dcol
		) {
	DpchEngWznm* dpcheng = NULL;

	// get first element from list ; assume access is locked
	if (!dcol->dpchs.empty()) {
		dpcheng = *(dcol->dpchs.begin());
		dcol->dpchs.pop_front();
	};

	return dpcheng;
};

ubigint XchgWznmd::addJob(
			DbsWznm* dbswznm
			, JobWznm* job
			, const ubigint jrefSup
		) {
	CsjobWznm* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob = getCsjobNotJob(job->ixWznmVJob);
	bool srvNotCli = false;

	// get new jref and append to job list
	rwmJobs.wlock("XchgWznmd", "addJob", "jrefSup=" + to_string(jrefSup));

	job->jref = jrefseq.getNewRef();
	jobs[job->jref] = job;

	if (jobs.size() == 1) {
		// root job
		jrefRoot = job->jref;
		jrefCmd = job->jref;
	};

	ixWznmVJobs[job->jref] = job->ixWznmVJob;
	jobinfos[job->jref] = new Jobinfo(jrefSup);

	if (jrefSup != 0) jobinfos[jrefSup]->jrefsSub.insert(job->jref);

	if (csjobNotJob) {
		rwmCsjobinfos.wlock("XchgWznmd", "addJob", "jref=" + to_string(job->jref));

		csjob = (CsjobWznm*) job;
		csjobinfo = csjobinfos[job->ixWznmVJob];

		if (jrefSup == jrefRoot) {
			csjob->srvNotCli = true;
			srvNotCli = true;
			
			csjobinfo->jrefSrv = job->jref;
			for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) {
				jobs[*it]->ixVSge = job->ixVSge;
				((CsjobWznm*) (jobs[*it]))->srv = csjob;
			};

		} else {
			csjob->srvNotCli = false;
			
			if (csjobinfo->jrefSrv != 0) {
				job->ixVSge = jobs[csjobinfo->jrefSrv]->ixVSge;
				csjob->srv = (CsjobWznm*) jobs[csjobinfo->jrefSrv];
			};
			csjobinfo->jrefsCli.insert(job->jref);
		};

		rwmCsjobinfos.wunlock("XchgWznmd", "addJob", "jref=" + to_string(job->jref));
	};

	rwmJobs.wunlock("XchgWznmd", "addJob", "jref=" + to_string(job->jref));

	mon.eventAddJob(jrefSup, VecWznmVJob::getSref(job->ixWznmVJob), job->jref, csjobNotJob, srvNotCli);

	return(job->jref);
};

JobWznm* XchgWznmd::getJobByJref(
			const ubigint jref
		) {
	JobWznm* job = NULL;

	rwmJobs.rlock("XchgWznmd", "getJobByJref", "jref=" + to_string(jref));

	auto it = jobs.find(jref);
	if (it != jobs.end()) job = it->second;

	rwmJobs.runlock("XchgWznmd", "getJobByJref", "jref=" + to_string(jref));

	return job;
};

Jobinfo* XchgWznmd::getJobinfoByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	rwmJobs.rlock("XchgWznmd", "getJobinfoByJref", "jref=" + to_string(jref));

	auto it = jobinfos.find(jref);
	if (it != jobinfos.end()) jobinfo = it->second;

	rwmJobs.runlock("XchgWznmd", "getJobinfoByJref", "jref=" + to_string(jref));

	return jobinfo;
};

void XchgWznmd::removeJobByJref(
			const ubigint jref
		) {
	JobWznm* job = NULL;
	Jobinfo* jobinfo = NULL;

	CsjobWznm* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob;

	rwmJobs.rlock("XchgWznmd", "removeJobByJref[1]", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
 		csjobNotJob = getCsjobNotJob(job->ixWznmVJob);

		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		if (csjobNotJob) {
			rwmCsjobinfos.rlock("XchgWznmd", "removeJobByJref[1]", "jref=" + to_string(jref));

			csjob = (CsjobWznm*) job;
			csjobinfo = csjobinfos[job->ixWznmVJob];

			removeCsjobClaim(NULL, csjob);

			rwmCsjobinfos.runlock("XchgWznmd", "removeJobByJref[1]", "jref=" + to_string(jref));

			rwmCsjobinfos.wlock("XchgWznmd", "removeJobByJref[2]", "jref=" + to_string(jref));

			if (csjob->srvNotCli) {
				csjobinfo->jrefSrv = 0;
				for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) ((CsjobWznm*) (jobs[*it]))->srv = NULL;

			} else csjobinfo->jrefsCli.erase(jref);

			rwmCsjobinfos.wunlock("XchgWznmd", "removeJobByJref[2]", "jref=" + to_string(jref));
		};

		jobinfo = jobinfos[jref];

		rwmJobs.runlock("XchgWznmd", "removeJobByJref[1]", "jref=" + to_string(jref));

		rwmJobs.wlock("XchgWznmd", "removeJobByJref[2]", "jref=" + to_string(jref));

		if (jobinfo->jrefSup != 0) jobinfos[jobinfo->jrefSup]->jrefsSub.erase(jref);

		rwmJobs.wunlock("XchgWznmd", "removeJobByJref[2]", "jref=" + to_string(jref));

		while (jobinfo->jrefsSub.size() > 0) delete jobs[*(jobinfo->jrefsSub.begin())];

		rwmJobs.wlock("XchgWznmd", "removeJobByJref[3]", "jref=" + to_string(jref));

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);

		delete jobinfo;
		jobinfos.erase(jref);

		ixWznmVJobs.erase(jref);

		if (jobs.empty()) {
			// root job
			jrefRoot = 0;
			jrefCmd = 0;
		};

		rwmJobs.wunlock("XchgWznmd", "removeJobByJref[3]", "jref=" + to_string(jref));

		mon.eventRemoveJob(jref);

	} else rwmJobs.wunlock("XchgWznmd", "removeJobByJref[4]", "jref=" + to_string(jref));
};

bool XchgWznmd::getJobSup(
			const ubigint jrefSup
			, ubigint jref
		) {
	bool retval = false;

	Jobinfo* jobinfo = NULL;

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo) {
		if (jobinfo->jrefSup == jrefSup) {
			retval = true;
			break;
		};

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	return retval;
};

void XchgWznmd::setJobStage(
			DbsWznm* dbswznm
			, JobWznm* job
			, const uint ixVSge
		) {
	set<ubigint> jrefsCli;

	bool csjobNotJob = getCsjobNotJob(job->ixWznmVJob);

	rwmJobs.rlock("XchgWznmd", "setJobStage", "jref=" + to_string(job->jref));
	if (csjobNotJob) rwmCsjobinfos.rlock("XchgWznmd", "setJobStage", "jref=" + to_string(job->jref));

	jobinfos[job->jref]->ixVSge = ixVSge;
	job->ixVSge = ixVSge;
	
	if (csjobNotJob) {
		jrefsCli = getCsjobClisByJref(job->jref);
		
		for (auto it = jrefsCli.begin(); it != jrefsCli.end(); it++) {
			jobinfos[*it]->ixVSge = ixVSge;
			jobs[*it]->ixVSge = ixVSge;
		};
	};

	if (csjobNotJob) rwmCsjobinfos.runlock("XchgWznmd", "setJobStage", "jref=" + to_string(job->jref));
	rwmJobs.runlock("XchgWznmd", "setJobStage", "jref=" + to_string(job->jref));

	triggerIxCall(dbswznm, VecWznmVCall::CALLWZNMSGECHG, job->jref, ixVSge);
};

void XchgWznmd::addCsjobClaim(
			DbsWznm* dbswznm
			, CsjobWznm* csjob
			, Claim* claim
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWznmd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWznmVJob];

		rwmCsjobinfos.runlock("XchgWznmd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgWznmd", "addCsjobClaim");

		csjobinfo->mClaims.wlock("XchgWznmd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) delete it->second;

		csjobinfo->claims[csjob->jref] = claim;

		mod = csjob->srv->handleClaim(dbswznm, csjobinfo->claims, csjob->jref);

		csjobinfo->mClaims.wunlock("XchgWznmd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgWznmd", "addCsjobClaim");

		if (mod) triggerCall(dbswznm, VecWznmVCall::CALLWZNMCLAIMCHG, csjob->jref);
	};
};

bool XchgWznmd::getCsjobClaim(
			CsjobWznm* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
			, bool& run
		) {
	bool retval = false;

	Csjobinfo* csjobinfo = NULL;;

	takenNotAvailable = false;
	fulfilled = false;
	run = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWznmd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWznmVJob];

		csjobinfo->mClaims.rlock("XchgWznmd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		retval = (it != csjobinfo->claims.end());

		if (retval) {
			takenNotAvailable = it->second->takenNotAvailable;
			fulfilled = it->second->fulfilled;
			run = it->second->run;
		};

		csjobinfo->mClaims.runlock("XchgWznmd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		rwmCsjobinfos.runlock("XchgWznmd", "getCsjobClaim", "jref=" + to_string(csjob->jref));
	};

	return retval;
};

bool XchgWznmd::getCsjobClaim(
			CsjobWznm* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
		) {
	bool run;

	return getCsjobClaim(csjob, takenNotAvailable, fulfilled, run);
};

void XchgWznmd::clearCsjobRun(
			DbsWznm* dbswznm
			, const uint ixWznmVJob
		) {
	Csjobinfo* csjobinfo = NULL;
	Claim* claim = NULL;

	bool mod = false;

	rwmCsjobinfos.rlock("XchgWznmd", "clearCsjobRun", "srefIxWznmVJob=" + VecWznmVJob::getSref(ixWznmVJob));

	auto it = csjobinfos.find(ixWznmVJob);
	if (it != csjobinfos.end()) csjobinfo = it->second;

	rwmCsjobinfos.runlock("XchgWznmd", "clearCsjobRun", "srefIxWznmVJob=" + VecWznmVJob::getSref(ixWznmVJob));

	if (csjobinfo) {
		csjobinfo->mClaims.wlock("XchgWznmd", "clearCsjobRun", "srefIxWznmVJob=" + VecWznmVJob::getSref(ixWznmVJob));

		for (auto it2 = csjobinfo->claims.begin(); it2 != csjobinfo->claims.end(); it2++) {
			claim = it2->second;

			if (claim->run) {
				claim->run = false;
				mod = true;
			};
		};

		csjobinfo->mClaims.wunlock("XchgWznmd", "clearCsjobRun", "srefIxWznmVJob=" + VecWznmVJob::getSref(ixWznmVJob));

		if (mod) triggerCall(dbswznm, VecWznmVCall::CALLWZNMCLAIMCHG, csjobinfo->jrefSrv);
	};
};

void XchgWznmd::removeCsjobClaim(
			DbsWznm* dbswznm
			, CsjobWznm* csjob
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWznmd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWznmVJob];

		rwmCsjobinfos.runlock("XchgWznmd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgWznmd", "removeCsjobClaim");

		csjobinfo->mClaims.wlock("XchgWznmd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) {
			delete it->second;
			csjobinfo->claims.erase(it);

			mod = csjob->srv->handleClaim(dbswznm, csjobinfo->claims, 0);
		};

		csjobinfo->mClaims.wunlock("XchgWznmd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgWznmd", "removeCsjobClaim");

		if (mod) triggerCall(dbswznm, VecWznmVCall::CALLWZNMCLAIMCHG, csjobinfo->jrefSrv);
	};
};

bool XchgWznmd::getCsjobNotJob(
			const uint ixWznmVJob
		) {
	bool retval;

	rwmCsjobinfos.rlock("XchgWznmd", "getCsjobNotJob", "srefIxWznmVJob=" + VecWznmVJob::getSref(ixWznmVJob));

	retval = (csjobinfos.find(ixWznmVJob) != csjobinfos.end());

	rwmCsjobinfos.runlock("XchgWznmd", "getCsjobNotJob", "srefIxWznmVJob=" + VecWznmVJob::getSref(ixWznmVJob));

	return retval;
};

set<ubigint> XchgWznmd::getCsjobClisByJref(
			const ubigint jref
		) {
	set<ubigint> retval;

	rwmCsjobinfos.rlock("XchgWznmd", "getCsjobClis", "jref=" + to_string(jref));

	auto it = csjobinfos.find(ixWznmVJobs[jref]);
	
	if (it != csjobinfos.end()) retval = it->second->jrefsCli;

	rwmCsjobinfos.runlock("XchgWznmd", "getCsjobClis", "jref=" + to_string(jref));

	return retval;
};

ubigint XchgWznmd::addWakeup(
			const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) {
	int res;

	ubigint wref;

	pthread_t timer;

	wref = wrefseq.getNewRef();

	if (deltat == 0) {
		// immediate callback: generate request to be treated by job processor
		ReqWznm* req = new ReqWznm(ReqWznm::VecVBasetype::TIMER);
		req->jref = jref;
		req->wref = wref;
		req->sref = sref;
		req->weak = false;

		addReq(req);

	} else {
		// delayed callback: generate dedicated wait thread
		WakeupWznm* wakeup = new WakeupWznm(this, wref, jref, sref, deltat, weak);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&timer, NULL, &runWakeup, (void*) wakeup);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "XchgWznmd::addWakeup() error creating timer thread (" << res << ")" << endl;
		else {
			res = pthread_detach(timer);
			if (res != 0) cout << "XchgWznmd::addWakeup() error detaching timer thread (" << res << ")" << endl;
		};
	};

	return(wref);
};

void* XchgWznmd::runWakeup(
			void* arg
		) {
	WakeupWznm* wakeup = (WakeupWznm*) arg;

	// wait for time specified in microseconds
	timespec deltat;
	deltat.tv_sec = wakeup->deltat / 1000000;
	deltat.tv_nsec = 1000 * (wakeup->deltat%1000000);
#ifdef _WIN32
	usleep(wakeup->deltat);
#else
	nanosleep(&deltat, NULL);
#endif

	// generate request to be treated by job processor
	ReqWznm* req = new ReqWznm(ReqWznm::VecVBasetype::TIMER);
	req->jref = wakeup->jref;
	req->wref = wakeup->wref;
	req->sref = wakeup->sref;
	req->weak = wakeup->weak;

	wakeup->xchg->addReq(req);

	delete wakeup;

	return(NULL);
};

void XchgWznmd::runExtcall(
			void* arg
		) {
	ExtcallWznm* extcall = (ExtcallWznm*) arg;

	// generate request to be treated by job processor
	ReqWznm* req = new ReqWznm(ReqWznm::VecVBasetype::EXTCALL);
	req->call = new Call(*(extcall->call));

	extcall->xchg->addReq(req);
};

NodeWznm* XchgWznmd::addNode(
			const string& ip
			, const uint port
			, const uint opprcn
			, const uint ixWznmVOpengtype
		) {
	NodeWznm* node = NULL;

	rwmNodes.wlock("XchgWznmd", "addNode", "ip:port=" + ip + ":" + to_string(port));

	node = new NodeWznm(nrefseq.getNewRef(), ip, port, opprcn, ixWznmVOpengtype);
	nodes[node->nref] = node;

	rwmNodes.wunlock("XchgWznmd", "addNode", "nref=" + to_string(node->nref));

	mon.eventAddNode(node->nref, ip, port, opprcn);

	setNodeState(node, NodeWznm::VecVState::IDLE);

	triggerCall(NULL, VecWznmVCall::CALLWZNMNODECHG, jrefRoot);

	return(node);
};

NodeWznm* XchgWznmd::getNodeByNref(
			const ubigint nref
		) {
	NodeWznm* node = NULL;

	rwmNodes.rlock("XchgWznmd", "getNodeByNref", "nref=" + to_string(nref));

	auto it = nodes.find(nref);
	if (it != nodes.end()) node = it->second;

	rwmNodes.runlock("XchgWznmd", "getNodeByNref", "nref=" + to_string(nref));

	return(node);
};

void XchgWznmd::terminateNodes() {
	rwmNodes.wlock("XchgWznmd", "terminateNodes");

	for (auto it = nodes.begin(); it != nodes.end(); it++) terminateNodeByNref(it->first);

	rwmNodes.wunlock("XchgWznmd", "terminateNodes");
};

void XchgWznmd::terminateNodeByNref(
			const ubigint nref
		) {
	NodeWznm* node = NULL;

	rwmNodes.wlock("XchgWznmd", "terminateNodeByNref", "nref=" + to_string(nref));

	node = getNodeByNref(nref);
	if (node) setNodeState(node, NodeWznm::VecVState::TERM);

	rwmNodes.wunlock("XchgWznmd", "terminateNodeByNref", "nref=" + to_string(nref));
};

void XchgWznmd::setNodeState(
			NodeWznm* node
			, const uint ixVState
		) {
	cOpengcli.lockMutex("XchgWznmd", "setNodeState", "nref=" + to_string(node->nref));
	rwmNodes.wlock("XchgWznmd", "setNodeState", "nref=" + to_string(node->nref));

	if ( ((ixVState == NodeWznm::VecVState::ERROR) && (node->ixVState == NodeWznm::VecVState::READY)) || (ixVState == NodeWznm::VecVState::TERM)) node->ixVState = ixVState;

	rwmNodes.wunlock("XchgWznmd", "setNodeState", "nref=" + to_string(node->nref));
	cOpengcli.unlockMutex("XchgWznmd", "setNodeState", "nref=" + to_string(node->nref));

	cOpengcli.signal("XchgWznmd", "setNodeState", "nref=" + to_string(node->nref));
};
