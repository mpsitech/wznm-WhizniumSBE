/**
	* \file WznmQTblTbl1NTablecol.cpp
	* API code for table TblWznmQTblTbl1NTablecol (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblTbl1NTablecol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblTbl1NTablecol
 ******************************************************************************/

WznmQTblTbl1NTablecol::WznmQTblTbl1NTablecol(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTblTbl1NTablecol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblTbl1NTablecol");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTblTbl1NTablecol
 ******************************************************************************/

ListWznmQTblTbl1NTablecol::ListWznmQTblTbl1NTablecol() {
};

ListWznmQTblTbl1NTablecol::ListWznmQTblTbl1NTablecol(
			const ListWznmQTblTbl1NTablecol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblTbl1NTablecol(*(src.nodes[i]));
};

ListWznmQTblTbl1NTablecol& ListWznmQTblTbl1NTablecol::operator=(
			const ListWznmQTblTbl1NTablecol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblTbl1NTablecol(*(src.nodes[i]));

	return *this;
};

ListWznmQTblTbl1NTablecol::~ListWznmQTblTbl1NTablecol() {
	clear();
};

void ListWznmQTblTbl1NTablecol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblTbl1NTablecol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblTbl1NTablecol* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblTbl1NTablecol");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblTbl1NTablecol", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblTbl1NTablecol(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblTbl1NTablecol[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
