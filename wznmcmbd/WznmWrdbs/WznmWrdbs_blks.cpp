/**
	* \file WznmWrdbs_blks.cpp
	* invocation / return data blocks for operation pack WznmWrdbs (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WznmWrdbs_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmWrdbsDbs
 ******************************************************************************/

DpchInvWznmWrdbsDbs::DpchInvWznmWrdbsDbs(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRDBSDBS, oref, jref)
		{
	this->refWznmMVersion = refWznmMVersion;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrdbsDbs::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrdbsDbs");
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

void DpchInvWznmWrdbsDbs::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrdbsDbs");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVersion", refWznmMVersion);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrdbsDeploy
 ******************************************************************************/

DpchInvWznmWrdbsDeploy::DpchInvWznmWrdbsDeploy(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMRelease
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRDBSDEPLOY, oref, jref)
		{
	this->refWznmMRelease = refWznmMRelease;
	this->folder = folder;
};

void DpchInvWznmWrdbsDeploy::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrdbsDeploy");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMRelease", "", refWznmMRelease)) add(REFWZNMMRELEASE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrdbsDeploy::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrdbsDeploy");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMRelease", refWznmMRelease);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrdbsDiffsql
 ******************************************************************************/

DpchInvWznmWrdbsDiffsql::DpchInvWznmWrdbsDiffsql(
			const ubigint oref
			, const ubigint jref
			, const ubigint frRefWznmMVersion
			, const ubigint toRefWznmMVersion
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRDBSDIFFSQL, oref, jref)
		{
	this->frRefWznmMVersion = frRefWznmMVersion;
	this->toRefWznmMVersion = toRefWznmMVersion;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrdbsDiffsql::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrdbsDiffsql");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "frRefWznmMVersion", "", frRefWznmMVersion)) add(FRREFWZNMMVERSION);
		if (extractUbigintUclc(docctx, basexpath, "toRefWznmMVersion", "", toRefWznmMVersion)) add(TOREFWZNMMVERSION);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrdbsDiffsql::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrdbsDiffsql");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "frRefWznmMVersion", frRefWznmMVersion);
		writeUbigint(wr, "toRefWznmMVersion", toRefWznmMVersion);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrdbsSql
 ******************************************************************************/

DpchInvWznmWrdbsSql::DpchInvWznmWrdbsSql(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMRelease
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRDBSSQL, oref, jref)
		{
	this->refWznmMRelease = refWznmMRelease;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmWrdbsSql::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrdbsSql");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMRelease", "", refWznmMRelease)) add(REFWZNMMRELEASE);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrdbsSql::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrdbsSql");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMRelease", refWznmMRelease);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrdbsTbl
 ******************************************************************************/

DpchInvWznmWrdbsTbl::DpchInvWznmWrdbsTbl(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMTable
			, const string& Prjshort
			, const bool dbsmy
			, const bool dbspg
			, const bool dbslite
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRDBSTBL, oref, jref)
		{
	this->refWznmMTable = refWznmMTable;
	this->Prjshort = Prjshort;
	this->dbsmy = dbsmy;
	this->dbspg = dbspg;
	this->dbslite = dbslite;
	this->folder = folder;
};

void DpchInvWznmWrdbsTbl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrdbsTbl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMTable", "", refWznmMTable)) add(REFWZNMMTABLE);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractBoolUclc(docctx, basexpath, "dbsmy", "", dbsmy)) add(DBSMY);
		if (extractBoolUclc(docctx, basexpath, "dbspg", "", dbspg)) add(DBSPG);
		if (extractBoolUclc(docctx, basexpath, "dbslite", "", dbslite)) add(DBSLITE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrdbsTbl::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrdbsTbl");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMTable", refWznmMTable);
		writeString(wr, "Prjshort", Prjshort);
		writeBool(wr, "dbsmy", dbsmy);
		writeBool(wr, "dbspg", dbspg);
		writeBool(wr, "dbslite", dbslite);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
