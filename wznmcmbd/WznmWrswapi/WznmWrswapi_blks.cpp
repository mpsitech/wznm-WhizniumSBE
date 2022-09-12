/**
	* \file WznmWrswapi_blks.cpp
	* invocation / return data blocks for operation pack WznmWrswapi (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#include "WznmWrswapi_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmWrswapiBase
 ******************************************************************************/

DpchInvWznmWrswapiBase::DpchInvWznmWrswapiBase(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRSWAPIBASE, oref, jref)
		{
	this->refWznmMVersion = refWznmMVersion;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrswapiBase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrswapiBase");
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

void DpchInvWznmWrswapiBase::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrswapiBase");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVersion", refWznmMVersion);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrswapiJob
 ******************************************************************************/

DpchInvWznmWrswapiJob::DpchInvWznmWrswapiJob(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMComponent
			, const ubigint refWznmMJob
			, const string& orgweb
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRSWAPIJOB, oref, jref)
		{
	this->refWznmMComponent = refWznmMComponent;
	this->refWznmMJob = refWznmMJob;
	this->orgweb = orgweb;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrswapiJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrswapiJob");
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

void DpchInvWznmWrswapiJob::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrswapiJob");
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
 class DpchInvWznmWrswapiQtb
 ******************************************************************************/

DpchInvWznmWrswapiQtb::DpchInvWznmWrswapiQtb(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMTable
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRSWAPIQTB, oref, jref)
		{
	this->refWznmMTable = refWznmMTable;
	this->folder = folder;
};

void DpchInvWznmWrswapiQtb::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrswapiQtb");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMTable", "", refWznmMTable)) add(REFWZNMMTABLE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrswapiQtb::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrswapiQtb");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMTable", refWznmMTable);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrswapiVec
 ******************************************************************************/

DpchInvWznmWrswapiVec::DpchInvWznmWrswapiVec(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVector
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRSWAPIVEC, oref, jref)
		{
	this->refWznmMVector = refWznmMVector;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrswapiVec::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrswapiVec");
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

void DpchInvWznmWrswapiVec::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrswapiVec");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVector", refWznmMVector);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
