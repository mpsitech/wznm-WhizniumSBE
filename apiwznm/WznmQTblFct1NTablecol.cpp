/**
	* \file WznmQTblFct1NTablecol.cpp
	* API code for table TblWznmQTblFct1NTablecol (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblFct1NTablecol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblFct1NTablecol
 ******************************************************************************/

WznmQTblFct1NTablecol::WznmQTblFct1NTablecol(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTblFct1NTablecol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblFct1NTablecol");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTblFct1NTablecol
 ******************************************************************************/

ListWznmQTblFct1NTablecol::ListWznmQTblFct1NTablecol() {
};

ListWznmQTblFct1NTablecol::ListWznmQTblFct1NTablecol(
			const ListWznmQTblFct1NTablecol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblFct1NTablecol(*(src.nodes[i]));
};

ListWznmQTblFct1NTablecol& ListWznmQTblFct1NTablecol::operator=(
			const ListWznmQTblFct1NTablecol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblFct1NTablecol(*(src.nodes[i]));

	return *this;
};

ListWznmQTblFct1NTablecol::~ListWznmQTblFct1NTablecol() {
	clear();
};

void ListWznmQTblFct1NTablecol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblFct1NTablecol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblFct1NTablecol* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblFct1NTablecol");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblFct1NTablecol", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblFct1NTablecol(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblFct1NTablecol[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
