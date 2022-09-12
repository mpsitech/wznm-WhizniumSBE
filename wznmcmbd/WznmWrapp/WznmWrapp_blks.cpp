/**
	* \file WznmWrapp_blks.cpp
	* invocation / return data blocks for operation pack WznmWrapp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WznmWrapp_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmWrappDom
 ******************************************************************************/

DpchInvWznmWrappDom::DpchInvWznmWrappDom(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMApp
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRAPPDOM, oref, jref)
		{
	this->refWznmMApp = refWznmMApp;
	this->folder = folder;
};

void DpchInvWznmWrappDom::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrappDom");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMApp", "", refWznmMApp)) add(REFWZNMMAPP);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrappDom::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrappDom");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMApp", refWznmMApp);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrappMain
 ******************************************************************************/

DpchInvWznmWrappMain::DpchInvWznmWrappMain(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMApp
			, const string& folder
			, const bool ipAllNotSpec
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRAPPMAIN, oref, jref)
		{
	this->refWznmMApp = refWznmMApp;
	this->folder = folder;
	this->ipAllNotSpec = ipAllNotSpec;
};

void DpchInvWznmWrappMain::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrappMain");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMApp", "", refWznmMApp)) add(REFWZNMMAPP);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractBoolUclc(docctx, basexpath, "ipAllNotSpec", "", ipAllNotSpec)) add(IPALLNOTSPEC);
	};
};

void DpchInvWznmWrappMain::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrappMain");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMApp", refWznmMApp);
		writeString(wr, "folder", folder);
		writeBool(wr, "ipAllNotSpec", ipAllNotSpec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrappStdvec
 ******************************************************************************/

DpchInvWznmWrappStdvec::DpchInvWznmWrappStdvec(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMApp
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRAPPSTDVEC, oref, jref)
		{
	this->refWznmMApp = refWznmMApp;
	this->folder = folder;
};

void DpchInvWznmWrappStdvec::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrappStdvec");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMApp", "", refWznmMApp)) add(REFWZNMMAPP);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmWrappStdvec::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrappStdvec");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMApp", refWznmMApp);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
