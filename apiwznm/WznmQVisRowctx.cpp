/**
	* \file WznmQVisRowctx.cpp
	* API code for table TblWznmQVisRowctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQVisRowctx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVisRowctx
 ******************************************************************************/

WznmQVisRowctx::WznmQVisRowctx(
			const uint jnum
			, const int jnumBox
			, const string Content1
			, const string Content2
			, const string Content3
		) :
			jnum(jnum)
			, jnumBox(jnumBox)
			, Content1(Content1)
			, Content2(Content2)
			, Content3(Content3)
		{
};

bool WznmQVisRowctx::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVisRowctx");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractIntUclc(docctx, basexpath, "jnumBox", "", jnumBox);
		extractStringUclc(docctx, basexpath, "Content1", "cnt1", Content1);
		extractStringUclc(docctx, basexpath, "Content2", "cnt2", Content2);
		extractStringUclc(docctx, basexpath, "Content3", "cnt3", Content3);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVisRowctx
 ******************************************************************************/

ListWznmQVisRowctx::ListWznmQVisRowctx() {
};

ListWznmQVisRowctx::ListWznmQVisRowctx(
			const ListWznmQVisRowctx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisRowctx(*(src.nodes[i]));
};

ListWznmQVisRowctx& ListWznmQVisRowctx::operator=(
			const ListWznmQVisRowctx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisRowctx(*(src.nodes[i]));

	return *this;
};

ListWznmQVisRowctx::~ListWznmQVisRowctx() {
	clear();
};

void ListWznmQVisRowctx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVisRowctx::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVisRowctx* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVisRowctx");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVisRowctx", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVisRowctx(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVisRowctx[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
