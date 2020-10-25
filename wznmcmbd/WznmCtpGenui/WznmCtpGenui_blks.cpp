/**
	* \file WznmCtpGenui_blks.cpp
	* invocation / return data blocks for operation pack WznmCtpGenui (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmCtpGenui_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmCtpGenui
 ******************************************************************************/

DpchInvWznmCtpGenui::DpchInvWznmCtpGenui(
			const ubigint oref
			, const string& srefKCustop
			, const ubigint jref
			, const ubigint refWznmMCapability
			, const string& Prjshort
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMCTPGENUI, oref, jref)
		{
	this->srefKCustop = srefKCustop;
	this->refWznmMCapability = refWznmMCapability;
	this->Prjshort = Prjshort;
};

void DpchInvWznmCtpGenui::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmCtpGenui");
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

void DpchInvWznmCtpGenui::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmCtpGenui");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "srefKCustop", srefKCustop);
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMCapability", refWznmMCapability);
		writeString(wr, "Prjshort", Prjshort);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWznmCtpGenui
 ******************************************************************************/

DpchRetWznmCtpGenui::DpchRetWznmCtpGenui(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const string& logfile
		) :
			DpchRetWznm(VecWznmVDpch::DPCHRETWZNMCTPGENUI, scrOref, scrJref, ixOpVOpres, pdone)
		{
	this->logfile = logfile;
};

void DpchRetWznmCtpGenui::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWznmCtpGenui");
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

void DpchRetWznmCtpGenui::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWznmCtpGenui");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeString(wr, "logfile", logfile);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT

