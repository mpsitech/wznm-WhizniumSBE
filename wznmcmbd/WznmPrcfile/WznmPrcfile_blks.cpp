/**
	* \file WznmPrcfile_blks.cpp
	* invocation / return data blocks for operation pack WznmPrcfile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WznmPrcfile_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWznmPrcfileConcat
 ******************************************************************************/

DpchInvWznmPrcfileConcat::DpchInvWznmPrcfileConcat(
			const ubigint oref
			, const ubigint jref
			, const vector<string>& infiles
			, const vector<string>& headers
			, const string& outfile
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMPRCFILECONCAT, oref, jref)
			, infiles(infiles)
			, headers(headers)
			, outfile(outfile)
		{
};

void DpchInvWznmPrcfileConcat::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmPrcfileConcat");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringvecUclc(docctx, basexpath, "infiles", "", infiles)) add(INFILES);
		if (extractStringvecUclc(docctx, basexpath, "headers", "", headers)) add(HEADERS);
		if (extractStringUclc(docctx, basexpath, "outfile", "", outfile)) add(OUTFILE);
	};
};

void DpchInvWznmPrcfileConcat::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmPrcfileConcat");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeStringvec(wr, "infiles", infiles);
		writeStringvec(wr, "headers", headers);
		writeString(wr, "outfile", outfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWznmPrcfilePlhrpl
 ******************************************************************************/

DpchInvWznmPrcfilePlhrpl::DpchInvWznmPrcfilePlhrpl(
			const ubigint oref
			, const ubigint jref
			, const ubigint inRefWznmMFile
			, const string& infile
			, const string& outfile
			, const vector<string>& keys
			, const vector<string>& vals
		) :
			DpchInvWznm(VecWznmVDpch::DPCHINVWZNMPRCFILEPLHRPL, oref, jref)
			, inRefWznmMFile(inRefWznmMFile)
			, infile(infile)
			, outfile(outfile)
			, keys(keys)
			, vals(vals)
		{
};

void DpchInvWznmPrcfilePlhrpl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWznmPrcfilePlhrpl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "inRefWznmMFile", "", inRefWznmMFile)) add(INREFWZNMMFILE);
		if (extractStringUclc(docctx, basexpath, "infile", "", infile)) add(INFILE);
		if (extractStringUclc(docctx, basexpath, "outfile", "", outfile)) add(OUTFILE);
		if (extractStringvecUclc(docctx, basexpath, "keys", "", keys)) add(KEYS);
		if (extractStringvecUclc(docctx, basexpath, "vals", "", vals)) add(VALS);
	};
};

void DpchInvWznmPrcfilePlhrpl::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWznmPrcfilePlhrpl");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "inRefWznmMFile", inRefWznmMFile);
		writeString(wr, "infile", infile);
		writeString(wr, "outfile", outfile);
		writeStringvec(wr, "keys", keys);
		writeStringvec(wr, "vals", vals);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
