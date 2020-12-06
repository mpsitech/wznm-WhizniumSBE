/**
	* \file WznmPrctree_blks.cpp
	* invocation / return data blocks for operation pack WznmPrctree (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WznmPrctree_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmPrctreeExtract
 ******************************************************************************/

DpchInvWznmPrctreeExtract::DpchInvWznmPrctreeExtract(
			const ubigint oref
			, const ubigint jref
			, const string& infile
			, const string& infolder
			, const string& extfile
			, const string& extfolder
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMPRCTREEEXTRACT, oref, jref)
		{
	this->infile = infile;
	this->infolder = infolder;
	this->extfile = extfile;
	this->extfolder = extfolder;
};

void DpchInvWznmPrctreeExtract::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmPrctreeExtract");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "infile", "", infile)) add(INFILE);
		if (extractStringUclc(docctx, basexpath, "infolder", "", infolder)) add(INFOLDER);
		if (extractStringUclc(docctx, basexpath, "extfile", "", extfile)) add(EXTFILE);
		if (extractStringUclc(docctx, basexpath, "extfolder", "", extfolder)) add(EXTFOLDER);
	};
};

void DpchInvWznmPrctreeExtract::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmPrctreeExtract");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeString(wr, "infile", infile);
		writeString(wr, "infolder", infolder);
		writeString(wr, "extfile", extfile);
		writeString(wr, "extfolder", extfolder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWznmPrctreeExtract
 ******************************************************************************/

DpchRetWznmPrctreeExtract::DpchRetWznmPrctreeExtract(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const string& logfile
		) :
			DpchRetWznm(VecWznmVDpch::DPCHRETWZNMPRCTREEEXTRACT, scrOref, scrJref, ixOpVOpres, pdone)
		{
	this->logfile = logfile;
};

void DpchRetWznmPrctreeExtract::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWznmPrctreeExtract");
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

void DpchRetWznmPrctreeExtract::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWznmPrctreeExtract");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeString(wr, "logfile", logfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmPrctreeMerge
 ******************************************************************************/

DpchInvWznmPrctreeMerge::DpchInvWznmPrctreeMerge(
			const ubigint oref
			, const ubigint jref
			, const string& extfile
			, const string& extfolder
			, const string& tplfile
			, const string& tplfolder
			, const bool notrace
			, const bool skipmultvoid
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMPRCTREEMERGE, oref, jref)
		{
	this->extfile = extfile;
	this->extfolder = extfolder;
	this->tplfile = tplfile;
	this->tplfolder = tplfolder;
	this->notrace = notrace;
	this->skipmultvoid = skipmultvoid;
};

void DpchInvWznmPrctreeMerge::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmPrctreeMerge");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "extfile", "", extfile)) add(EXTFILE);
		if (extractStringUclc(docctx, basexpath, "extfolder", "", extfolder)) add(EXTFOLDER);
		if (extractStringUclc(docctx, basexpath, "tplfile", "", tplfile)) add(TPLFILE);
		if (extractStringUclc(docctx, basexpath, "tplfolder", "", tplfolder)) add(TPLFOLDER);
		if (extractBoolUclc(docctx, basexpath, "notrace", "", notrace)) add(NOTRACE);
		if (extractBoolUclc(docctx, basexpath, "skipmultvoid", "", skipmultvoid)) add(SKIPMULTVOID);
	};
};

void DpchInvWznmPrctreeMerge::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmPrctreeMerge");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeString(wr, "extfile", extfile);
		writeString(wr, "extfolder", extfolder);
		writeString(wr, "tplfile", tplfile);
		writeString(wr, "tplfolder", tplfolder);
		writeBool(wr, "notrace", notrace);
		writeBool(wr, "skipmultvoid", skipmultvoid);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWznmPrctreeMerge
 ******************************************************************************/

DpchRetWznmPrctreeMerge::DpchRetWznmPrctreeMerge(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const string& logfile
		) :
			DpchRetWznm(VecWznmVDpch::DPCHRETWZNMPRCTREEMERGE, scrOref, scrJref, ixOpVOpres, pdone)
		{
	this->logfile = logfile;
};

void DpchRetWznmPrctreeMerge::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWznmPrctreeMerge");
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

void DpchRetWznmPrctreeMerge::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWznmPrctreeMerge");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeString(wr, "logfile", logfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmPrctreeValidate
 ******************************************************************************/

DpchInvWznmPrctreeValidate::DpchInvWznmPrctreeValidate(
			const ubigint oref
			, const ubigint jref
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMPRCTREEVALIDATE, oref, jref)
		{
};

void DpchInvWznmPrctreeValidate::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmPrctreeValidate");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvWznmPrctreeValidate::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmPrctreeValidate");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
