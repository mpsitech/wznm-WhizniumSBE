/**
	* \file WznmQRel1NTablecol.cpp
	* API code for table TblWznmQRel1NTablecol (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRel1NTablecol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRel1NTablecol
 ******************************************************************************/

WznmQRel1NTablecol::WznmQRel1NTablecol(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQRel1NTablecol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQRel1NTablecol");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQRel1NTablecol
 ******************************************************************************/

ListWznmQRel1NTablecol::ListWznmQRel1NTablecol() {
};

ListWznmQRel1NTablecol::ListWznmQRel1NTablecol(
			const ListWznmQRel1NTablecol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRel1NTablecol(*(src.nodes[i]));
};

ListWznmQRel1NTablecol& ListWznmQRel1NTablecol::operator=(
			const ListWznmQRel1NTablecol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRel1NTablecol(*(src.nodes[i]));

	return *this;
};

ListWznmQRel1NTablecol::~ListWznmQRel1NTablecol() {
	clear();
};

void ListWznmQRel1NTablecol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQRel1NTablecol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQRel1NTablecol* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQRel1NTablecol");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQRel1NTablecol", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQRel1NTablecol(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQRel1NTablecol[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
