/**
	* \file WznmWrvis_blks.cpp
	* invocation / return data blocks for operation pack WznmWrvis (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmWrvis_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmWrvisDbstr
 ******************************************************************************/

DpchInvWznmWrvisDbstr::DpchInvWznmWrvisDbstr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMSheet
			, const string& Prjshort
			, const string& folder
			, const string& Shtshort
			, const ubigint jrefBoxctx
			, const ubigint jrefLinkctx
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRVISDBSTR, oref, jref)
			, refWznmMSheet(refWznmMSheet)
			, Prjshort(Prjshort)
			, folder(folder)
			, Shtshort(Shtshort)
			, jrefBoxctx(jrefBoxctx)
			, jrefLinkctx(jrefLinkctx)
		{
};

void DpchInvWznmWrvisDbstr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrvisDbstr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMSheet", "", refWznmMSheet)) add(REFWZNMMSHEET);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractStringUclc(docctx, basexpath, "Shtshort", "", Shtshort)) add(SHTSHORT);
		if (extractUbigintUclc(docctx, basexpath, "jrefBoxctx", "", jrefBoxctx)) add(JREFBOXCTX);
		if (extractUbigintUclc(docctx, basexpath, "jrefLinkctx", "", jrefLinkctx)) add(JREFLINKCTX);
	};
};

void DpchInvWznmWrvisDbstr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrvisDbstr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMSheet", refWznmMSheet);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
		writeString(wr, "Shtshort", Shtshort);
		writeUbigint(wr, "jrefBoxctx", jrefBoxctx);
		writeUbigint(wr, "jrefLinkctx", jrefLinkctx);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmWrvisImpexp
 ******************************************************************************/

DpchInvWznmWrvisImpexp::DpchInvWznmWrvisImpexp(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMSheet
			, const string& Prjshort
			, const string& folder
			, const string& Shtshort
			, const ubigint jrefBoxctx
			, const ubigint jrefLinkctx
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMWRVISIMPEXP, oref, jref)
			, refWznmMSheet(refWznmMSheet)
			, Prjshort(Prjshort)
			, folder(folder)
			, Shtshort(Shtshort)
			, jrefBoxctx(jrefBoxctx)
			, jrefLinkctx(jrefLinkctx)
		{
};

void DpchInvWznmWrvisImpexp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmWrvisImpexp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMSheet", "", refWznmMSheet)) add(REFWZNMMSHEET);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractStringUclc(docctx, basexpath, "Shtshort", "", Shtshort)) add(SHTSHORT);
		if (extractUbigintUclc(docctx, basexpath, "jrefBoxctx", "", jrefBoxctx)) add(JREFBOXCTX);
		if (extractUbigintUclc(docctx, basexpath, "jrefLinkctx", "", jrefLinkctx)) add(JREFLINKCTX);
	};
};

void DpchInvWznmWrvisImpexp::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmWrvisImpexp");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMSheet", refWznmMSheet);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
		writeString(wr, "Shtshort", Shtshort);
		writeUbigint(wr, "jrefBoxctx", jrefBoxctx);
		writeUbigint(wr, "jrefLinkctx", jrefLinkctx);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
