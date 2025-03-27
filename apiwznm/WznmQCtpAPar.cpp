/**
	* \file WznmQCtpAPar.cpp
	* API code for table TblWznmQCtpAPar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQCtpAPar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCtpAPar
 ******************************************************************************/

WznmQCtpAPar::WznmQCtpAPar(
			const uint jnum
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string Val
		) :
			jnum(jnum)
			, x1SrefKKey(x1SrefKKey)
			, titX1SrefKKey(titX1SrefKKey)
			, Val(Val)
		{
};

bool WznmQCtpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCtpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey);
		extractStringUclc(docctx, basexpath, "titX1SrefKKey", "key2", titX1SrefKKey);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCtpAPar
 ******************************************************************************/

ListWznmQCtpAPar::ListWznmQCtpAPar() {
};

ListWznmQCtpAPar::ListWznmQCtpAPar(
			const ListWznmQCtpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpAPar(*(src.nodes[i]));
};

ListWznmQCtpAPar& ListWznmQCtpAPar::operator=(
			const ListWznmQCtpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpAPar(*(src.nodes[i]));

	return *this;
};

ListWznmQCtpAPar::~ListWznmQCtpAPar() {
	clear();
};

void ListWznmQCtpAPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCtpAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCtpAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCtpAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCtpAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCtpAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCtpAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
