/**
	* \file WznmWrcsapi_blks.cpp
	* invocation / return data blocks for operation pack WznmWrcsapi (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#include "WznmWrcsapi_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmWrcsapiBase
 ******************************************************************************/

DpchInvWznmWrcsapiBase::DpchInvWznmWrcsapiBase(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRCSAPIBASE, oref, jref)
		{
	this->refWznmMVersion = refWznmMVersion;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrcsapiBase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrcsapiBase");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMVersion", "", refWznmMVersion)) add(REFWZNMMVERSION);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrcsapiBase::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrcsapiBase");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVersion", refWznmMVersion);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrcsapiJob
 ******************************************************************************/

DpchInvWznmWrcsapiJob::DpchInvWznmWrcsapiJob(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMComponent
			, const ubigint refWznmMJob
			, const string& orgweb
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRCSAPIJOB, oref, jref)
		{
	this->refWznmMComponent = refWznmMComponent;
	this->refWznmMJob = refWznmMJob;
	this->orgweb = orgweb;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrcsapiJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrcsapiJob");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMComponent", "", refWznmMComponent)) add(REFWZNMMCOMPONENT);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMJob", "", refWznmMJob)) add(REFWZNMMJOB);
		if (extractStringUclc(docctx, basexpath, "orgweb", "", orgweb)) add(ORGWEB);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrcsapiJob::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrcsapiJob");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMComponent", refWznmMComponent);
		writeUbigint(wr, "refWznmMJob", refWznmMJob);
		writeString(wr, "orgweb", orgweb);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrcsapiQtb
 ******************************************************************************/

DpchInvWznmWrcsapiQtb::DpchInvWznmWrcsapiQtb(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMTable
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRCSAPIQTB, oref, jref)
		{
	this->refWznmMTable = refWznmMTable;
	this->folder = folder;
};

void DpchInvWznmWrcsapiQtb::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrcsapiQtb");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMTable", "", refWznmMTable)) add(REFWZNMMTABLE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrcsapiQtb::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrcsapiQtb");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMTable", refWznmMTable);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrcsapiVec
 ******************************************************************************/

DpchInvWznmWrcsapiVec::DpchInvWznmWrcsapiVec(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVector
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRCSAPIVEC, oref, jref)
		{
	this->refWznmMVector = refWznmMVector;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrcsapiVec::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrcsapiVec");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMVector", "", refWznmMVector)) add(REFWZNMMVECTOR);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrcsapiVec::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrcsapiVec");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVector", refWznmMVector);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
