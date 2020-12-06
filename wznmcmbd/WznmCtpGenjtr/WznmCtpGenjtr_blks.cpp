/**
	* \file WznmCtpGenjtr_blks.cpp
	* invocation / return data blocks for operation pack WznmCtpGenjtr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WznmCtpGenjtr_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmCtpGenjtr
 ******************************************************************************/

DpchInvWznmCtpGenjtr::DpchInvWznmCtpGenjtr(
			const ubigint oref
			, const string& srefKCustop
			, const ubigint jref
			, const ubigint refWznmMCapability
			, const string& Prjshort
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMCTPGENJTR, oref, jref)
		{
	this->srefKCustop = srefKCustop;
	this->refWznmMCapability = refWznmMCapability;
	this->Prjshort = Prjshort;
};

void DpchInvWznmCtpGenjtr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmCtpGenjtr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "srefKCustop", "", srefKCustop)) add(SREFKCUSTOP);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMCapability", "", refWznmMCapability)) add(REFWZNMMCAPABILITY);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
	};
};

void DpchInvWznmCtpGenjtr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmCtpGenjtr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "srefKCustop", srefKCustop);
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMCapability", refWznmMCapability);
		writeString(wr, "Prjshort", Prjshort);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWznmCtpGenjtr
 ******************************************************************************/

DpchRetWznmCtpGenjtr::DpchRetWznmCtpGenjtr(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const string& logfile
		) :
			DpchRetWznm(VecWznmVDpch::DPCHRETWZNMCTPGENJTR, scrOref, scrJref, ixOpVOpres, pdone)
		{
	this->logfile = logfile;
};

void DpchRetWznmCtpGenjtr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWznmCtpGenjtr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxOpVOpres", "", srefIxOpVOpres)) {
			ixOpVOpres = VecOpVOpres::getIx(srefIxOpVOpres);
			add(IXOPVOPRES);
		};
		if (extractUtinyintUclc(docctx, basexpath, "pdone", "", pdone)) add(PDONE);
		if (extractStringUclc(docctx, basexpath, "logfile", "", logfile)) add(LOGFILE);
	};
};

void DpchRetWznmCtpGenjtr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWznmCtpGenjtr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeString(wr, "logfile", logfile);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
