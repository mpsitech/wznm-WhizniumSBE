/**
	* \file WznmWrsapi_blks.cpp
	* invocation / return data blocks for operation pack WznmWrsapi (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#include "WznmWrsapi_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmWrsapiBase
 ******************************************************************************/

DpchInvWznmWrsapiBase::DpchInvWznmWrsapiBase(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRSAPIBASE, oref, jref)
		{
	this->refWznmMVersion = refWznmMVersion;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrsapiBase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrsapiBase");
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

void DpchInvWznmWrsapiBase::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrsapiBase");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVersion", refWznmMVersion);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrsapiJob
 ******************************************************************************/

DpchInvWznmWrsapiJob::DpchInvWznmWrsapiJob(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMComponent
			, const ubigint refWznmMJob
			, const string& orgweb
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRSAPIJOB, oref, jref)
		{
	this->refWznmMComponent = refWznmMComponent;
	this->refWznmMJob = refWznmMJob;
	this->orgweb = orgweb;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrsapiJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrsapiJob");
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

void DpchInvWznmWrsapiJob::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrsapiJob");
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
 class DpchInvWznmWrsapiQtb
 ******************************************************************************/

DpchInvWznmWrsapiQtb::DpchInvWznmWrsapiQtb(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMTable
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRSAPIQTB, oref, jref)
		{
	this->refWznmMTable = refWznmMTable;
	this->folder = folder;
};

void DpchInvWznmWrsapiQtb::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrsapiQtb");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMTable", "", refWznmMTable)) add(REFWZNMMTABLE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrsapiQtb::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrsapiQtb");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMTable", refWznmMTable);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrsapiVec
 ******************************************************************************/

DpchInvWznmWrsapiVec::DpchInvWznmWrsapiVec(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVector
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRSAPIVEC, oref, jref)
		{
	this->refWznmMVector = refWznmMVector;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrsapiVec::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrsapiVec");
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

void DpchInvWznmWrsapiVec::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrsapiVec");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVector", refWznmMVector);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
