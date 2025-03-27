/**
	* \file WznmQVisVis1NSheet.cpp
	* API code for table TblWznmQVisVis1NSheet (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQVisVis1NSheet.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVisVis1NSheet
 ******************************************************************************/

WznmQVisVis1NSheet::WznmQVisVis1NSheet(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQVisVis1NSheet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVisVis1NSheet");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVisVis1NSheet
 ******************************************************************************/

ListWznmQVisVis1NSheet::ListWznmQVisVis1NSheet() {
};

ListWznmQVisVis1NSheet::ListWznmQVisVis1NSheet(
			const ListWznmQVisVis1NSheet& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisVis1NSheet(*(src.nodes[i]));
};

ListWznmQVisVis1NSheet& ListWznmQVisVis1NSheet::operator=(
			const ListWznmQVisVis1NSheet& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisVis1NSheet(*(src.nodes[i]));

	return *this;
};

ListWznmQVisVis1NSheet::~ListWznmQVisVis1NSheet() {
	clear();
};

void ListWznmQVisVis1NSheet::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVisVis1NSheet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVisVis1NSheet* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVisVis1NSheet");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVisVis1NSheet", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVisVis1NSheet(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVisVis1NSheet[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
