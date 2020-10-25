/**
	* \file Wznmopd.cpp
	* inter-thread exchange object for Wznm operation daemon wznmopd2 (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "Wznmopd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchWznmdReg
 ******************************************************************************/

DpchWznmdReg::DpchWznmdReg() :
			DpchWznm(VecWznmVDpch::DPCHWZNMDREG)
		{
};

bool DpchWznmdReg::all(
			const set<uint>& items
		) {
	if (!find(items, SCRNREF)) return false;

	return true;
};

void DpchWznmdReg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchWznmdReg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrNref", "", scrNref)) add(SCRNREF);
	};
};

/******************************************************************************
 namespace DpchWznmopdAck
 ******************************************************************************/

void DpchWznmopdAck::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchWznmopdAck");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchWznmopdReg
 ******************************************************************************/

void DpchWznmopdReg::writeXML(
			xmlTextWriter* wr
			, const usmallint port
			, const uint ixWznmVOpengtype
			, const usmallint opprcn
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchWznmopdReg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeUsmallint(wr, "port", port);
		writeString(wr, "srefIxWznmVOpengtype", VecWznmVOpengtype::getSref(ixWznmVOpengtype));
		writeUsmallint(wr, "opprcn", opprcn);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchWznmopdUnreg
 ******************************************************************************/

void DpchWznmopdUnreg::writeXML(
			xmlTextWriter* wr
			, const string& scrNref
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchWznmopdUnreg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrNref", scrNref);
	xmlTextWriterEndElement(wr);
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
 class StgWznmopd
 ******************************************************************************/

StgWznmopd::StgWznmopd(
			const string& engip
			, const usmallint engport
			, const usmallint engsrvportbase
			, const usmallint engsrvportofs
			, const usmallint opprcn
		) :
			Block()
		{
	this->engip = engip;
	this->engport = engport;
	this->engsrvportbase = engsrvportbase;
	this->engsrvportofs = engsrvportofs;
	this->opprcn = opprcn;
	mask = {ENGIP, ENGPORT, ENGSRVPORTBASE, ENGSRVPORTOFS, OPPRCN};
};

bool StgWznmopd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWznmopd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWznmopd";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engsrvportbase", engsrvportbase)) add(ENGSRVPORTBASE);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engsrvportofs", engsrvportofs)) add(ENGSRVPORTOFS);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
	};

	return basefound;
};

void StgWznmopd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWznmopd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWznmopd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUsmallintAttr(wr, itemtag, "sref", "engport", engport);
		writeUsmallintAttr(wr, itemtag, "sref", "engsrvportbase", engsrvportbase);
		writeUsmallintAttr(wr, itemtag, "sref", "engsrvportofs", engsrvportofs);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWznmopd::comm(
			const StgWznmopd* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (engsrvportbase == comp->engsrvportbase) insert(items, ENGSRVPORTBASE);
	if (engsrvportofs == comp->engsrvportofs) insert(items, ENGSRVPORTOFS);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);

	return(items);
};

set<uint> StgWznmopd::diff(
			const StgWznmopd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ENGIP, ENGPORT, ENGSRVPORTBASE, ENGSRVPORTOFS, OPPRCN};
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
 class ReqopWznm
 ******************************************************************************/

ReqopWznm::ReqopWznm(
			const uint ixVBasetype
			, const uint ixVState
		) :
			cReady("cReady", "ReqopWznm", "ReqopWznm")
		{
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;

	pdone = 0;

	pp = NULL;

	request = NULL;
	requestlen = 0;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;
};

ReqopWznm::~ReqopWznm() {
	if (pp) MHD_destroy_post_processor(pp);

	if (request) delete[] request;

	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	if (reply) delete[] reply;

	cReady.lockMutex("ReqopWznm", "~ReqopWznm");
	cReady.unlockMutex("ReqopWznm", "~ReqopWznm");
};

void ReqopWznm::setStateReply() {
	cReady.lockMutex("ReqopWznm", "setStateReply", "scrOref=" + dpchinv->scrOref);

	ixVState = VecVState::REPLY;

	pdone = 100;

	if (dpchret) {
		dpchret->scrOref = dpchinv->scrOref;
		dpchret->scrJref = dpchinv->scrJref;
		dpchret->pdone = pdone;
	};

	cReady.unlockMutex("ReqopWznm", "setStateReply", "scrOref=" + dpchinv->scrOref);

	cReady.signal("ReqopWznm", "setStateReply", "scrOref=" + dpchinv->scrOref);
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
		) {
	rwmAccess.rlock(srefObject, srefMember);
};

void ShrdatWznm::runlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.runlock(srefObject, srefMember);
};

void ShrdatWznm::wlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.wlock(srefObject, srefMember);
};

void ShrdatWznm::wunlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.wunlock(srefObject, srefMember);
};

// IP ShrdatOpprc.subs --- INSERT

/******************************************************************************
 class XchgWznmopd::ShrdatOpprc
 ******************************************************************************/

XchgWznmopd::ShrdatOpprc::ShrdatOpprc() :
			ShrdatWznm("XchgWznm", "ShrdatOpprc")
		{
};

void XchgWznmopd::ShrdatOpprc::init(
			XchgWznm* xchg
			, DbsWznm* dbswznm
		) {
	// IP ShrdatOpprc.init --- INSERT
};

void XchgWznmopd::ShrdatOpprc::term(
			XchgWznm* xchg
		) {
	// IP ShrdatOpprc.term --- INSERT
};

/******************************************************************************
 class XchgWznmopd
 ******************************************************************************/

XchgWznmopd::XchgWznmopd() :
			cStable("cStable", "XchgWznmopd", "XchgWznmopd")
			, mLogfile("mLogfile", "XchgWznmopd", "XchgWznmopd")
			, cTerm("cTerm", "XchgWznmopd", "XchgWznmopd")
			, cOpprcs("cOpprcs", "XchgWznmopd", "XchgWznmopd")
			, mReqs("mReqs", "XchgWznmopd", "XchgWznmopd")
		{
	// IP constructor.data --- INSERT
};

XchgWznmopd::~XchgWznmopd() {
	// empty out lists
	for (auto it = reqs.begin(); it != reqs.end(); it++) delete(*it);
	for (auto it = prcreqs.begin(); it != prcreqs.end(); it++) delete(it->second);
};

// IP cust --- INSERT

void XchgWznmopd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	mLogfile.lock("XchgWznmopd", "appendToLogfile");

	time(&rawtime);

	logfile.open(exedir + "/log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	mLogfile.unlock("XchgWznmopd", "appendToLogfile");
};

void XchgWznmopd::addReq(
			ReqopWznm* req
		) {
	mReqs.lock("XchgWznmopd", "addReq");

	req->ixVState = ReqopWznm::VecVState::WAITPRC;
	reqs.push_back(req);

	mReqs.unlock("XchgWznmopd", "addReq");

	cOpprcs.signal("XchgWznmopd", "addReq");
};

ReqopWznm* XchgWznmopd::pullFirstReq() {
	ReqopWznm* req;

	// get first element from list
	mReqs.lock("XchgWznmopd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqopWznm::VecVState::PRC;
		reqs.pop_front();

		prcreqs[req->dpchinv->scrOref] = req;
	};

	mReqs.unlock("XchgWznmopd", "pullFirstReq");

	return req;
};

ReqopWznm* XchgWznmopd::getPrcreqByScrOref(
			const string& scrOref
		) {
	ReqopWznm* req = NULL;

	mReqs.lock("XchgWznmopd", "getPrcreqByScrOref", "scrOref=" + scrOref);

	auto it = prcreqs.find(scrOref);

	if (it != prcreqs.end()) {
		req = it->second;
		req->cReady.lockMutex("XchgWznmopd", "getPrcreqByScrOref", "scrOref=" + scrOref);
	};

	mReqs.unlock("XchgWznmopd", "getPrcreqByScrOref", "scrOref=" + scrOref);

	return req;
};

void XchgWznmopd::pullPrcreq(
			const string& scrOref
		) {
	mReqs.lock("XchgWznmopd", "pullPrcreq", "scrOref=" + scrOref);

	auto it = prcreqs.find(scrOref);
	if (it != prcreqs.end()) prcreqs.erase(it);

	mReqs.unlock("XchgWznmopd", "pullPrcreq", "scrOref=" + scrOref);
};

void XchgWznmopd::setPdone(
			const string& scrOref
			, const utinyint pdone
		) {
	ReqopWznm* req = NULL;

	req = getPrcreqByScrOref(scrOref);

	if (req) {
		req->pdone = pdone;
		req->cReady.unlockMutex("XchgWznmopd", "setPdone", "scrOref=" + scrOref);
	};
};

