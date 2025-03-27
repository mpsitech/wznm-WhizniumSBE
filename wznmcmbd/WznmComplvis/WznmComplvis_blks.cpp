/**
	* \file WznmComplvis_blks.cpp
	* invocation / return data blocks for operation pack WznmComplvis (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmComplvis_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmComplvisDbstr
 ******************************************************************************/

DpchInvWznmComplvisDbstr::DpchInvWznmComplvisDbstr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVisual
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMCOMPLVISDBSTR, oref, jref)
			, refWznmMVisual(refWznmMVisual)
		{
};

void DpchInvWznmComplvisDbstr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmComplvisDbstr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMVisual", "", refWznmMVisual)) add(REFWZNMMVISUAL);
	};
};

void DpchInvWznmComplvisDbstr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmComplvisDbstr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVisual", refWznmMVisual);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmComplvisImpexp
 ******************************************************************************/

DpchInvWznmComplvisImpexp::DpchInvWznmComplvisImpexp(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWznmMVisual
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMCOMPLVISIMPEXP, oref, jref)
			, refWznmMVisual(refWznmMVisual)
		{
};

void DpchInvWznmComplvisImpexp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmComplvisImpexp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMVisual", "", refWznmMVisual)) add(REFWZNMMVISUAL);
	};
};

void DpchInvWznmComplvisImpexp::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmComplvisImpexp");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMVisual", refWznmMVisual);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
