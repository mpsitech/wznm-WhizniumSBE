/**
	* \file WznmCtpWrweb_blks.cpp
	* invocation / return data blocks for operation pack WznmCtpWrweb (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmCtpWrweb_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmCtpWrweb
 ******************************************************************************/

DpchInvWznmCtpWrweb::DpchInvWznmCtpWrweb(
			const ubigint oref
			, const string& srefKCustop
			, const ubigint jref
			, const ubigint refWznmMCapability
			, const string& Prjshort
			, const string& folder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMCTPWRWEB, oref, jref)
		{
	this->srefKCustop = srefKCustop;
	this->refWznmMCapability = refWznmMCapability;
	this->Prjshort = Prjshort;
	this->folder = folder;
};

void DpchInvWznmCtpWrweb::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmCtpWrweb");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "srefKCustop", "", srefKCustop)) add(SREFKCUSTOP);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWznmMCapability", "", refWznmMCapability)) add(REFWZNMMCAPABILITY);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWznmCtpWrweb::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmCtpWrweb");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "srefKCustop", srefKCustop);
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWznmMCapability", refWznmMCapability);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT

