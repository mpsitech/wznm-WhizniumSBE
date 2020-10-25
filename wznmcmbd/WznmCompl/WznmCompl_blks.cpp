/**
	* \file WznmCompl_blks.cpp
	* invocation / return data blocks for operation pack WznmCompl (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmCompl_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmComplBscui
 ******************************************************************************/

DpchInvWznmComplBscui::DpchInvWznmComplBscui(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMCOMPLBSCUI, oref, jref)
		{
	this->refWznmMVersion = refWznmMVersion;
	this->Prjshort = Prjshort;
};

void DpchInvWznmComplBscui::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmComplBscui");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMVersion", "", refWznmMVersion)) add(REFWZNMMVERSION);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
	};
};

void DpchInvWznmComplBscui::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmComplBscui");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVersion", refWznmMVersion);
		writeString(wr, "Prjshort", Prjshort);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmComplDbs
 ******************************************************************************/

DpchInvWznmComplDbs::DpchInvWznmComplDbs(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMCOMPLDBS, oref, jref)
		{
	this->refWznmMVersion = refWznmMVersion;
	this->Prjshort = Prjshort;
};

void DpchInvWznmComplDbs::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmComplDbs");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMVersion", "", refWznmMVersion)) add(REFWZNMMVERSION);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
	};
};

void DpchInvWznmComplDbs::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmComplDbs");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVersion", refWznmMVersion);
		writeString(wr, "Prjshort", Prjshort);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmComplIex
 ******************************************************************************/

DpchInvWznmComplIex::DpchInvWznmComplIex(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVersion
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMCOMPLIEX, oref, jref)
		{
	this->refWznmMVersion = refWznmMVersion;
};

void DpchInvWznmComplIex::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmComplIex");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMVersion", "", refWznmMVersion)) add(REFWZNMMVERSION);
	};
};

void DpchInvWznmComplIex::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmComplIex");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVersion", refWznmMVersion);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmComplJtr
 ******************************************************************************/

DpchInvWznmComplJtr::DpchInvWznmComplJtr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMCOMPLJTR, oref, jref)
		{
	this->refWznmMVersion = refWznmMVersion;
	this->Prjshort = Prjshort;
};

void DpchInvWznmComplJtr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmComplJtr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMVersion", "", refWznmMVersion)) add(REFWZNMMVERSION);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
	};
};

void DpchInvWznmComplJtr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmComplJtr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVersion", refWznmMVersion);
		writeString(wr, "Prjshort", Prjshort);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT

