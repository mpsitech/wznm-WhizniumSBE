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
 class DpchInvWznmWrappBase
 ******************************************************************************/

DpchInvWznmWrappBase::DpchInvWznmWrappBase(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMApp
			, const string& folder
			, const bool ipAllNotSpec
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRAPPBASE, oref, jref)
		{
	this->refWznmMApp = refWznmMApp;
	this->folder = folder;
	this->ipAllNotSpec = ipAllNotSpec;
};

void DpchInvWznmWrappBase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrappBase");
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

void DpchInvWznmWrappBase::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrappBase");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMApp", refWznmMApp);
		writeString(wr, "folder", folder);
		writeBool(wr, "ipAllNotSpec", ipAllNotSpec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrappJbase
 ******************************************************************************/

DpchInvWznmWrappJbase::DpchInvWznmWrappJbase(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMApp
			, const string& folder
			, const bool ipAllNotSpec
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRAPPJBASE, oref, jref)
		{
	this->refWznmMApp = refWznmMApp;
	this->folder = folder;
	this->ipAllNotSpec = ipAllNotSpec;
};

void DpchInvWznmWrappJbase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrappJbase");
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

void DpchInvWznmWrappJbase::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrappJbase");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMApp", refWznmMApp);
		writeString(wr, "folder", folder);
		writeBool(wr, "ipAllNotSpec", ipAllNotSpec);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT



