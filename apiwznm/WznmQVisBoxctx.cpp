/**
	* \file WznmQVisBoxctx.cpp
	* API code for table TblWznmQVisBoxctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQVisBoxctx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVisBoxctx
 ******************************************************************************/

WznmQVisBoxctx::WznmQVisBoxctx(
			const uint jnum
			, const string stubUnvUref
			, const smallint x
			, const smallint y
			, const string jnumsSub
			, const string jnumsLink
			, const int w
			, const int h
			, const string Content1
			, const string Content2
		) :
			jnum(jnum)
			, stubUnvUref(stubUnvUref)
			, x(x)
			, y(y)
			, jnumsSub(jnumsSub)
			, jnumsLink(jnumsLink)
			, w(w)
			, h(h)
			, Content1(Content1)
			, Content2(Content2)
		{
};

bool WznmQVisBoxctx::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVisBoxctx");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubUnvUref", "stubUnv", stubUnvUref);
		extractSmallintUclc(docctx, basexpath, "x", "x", x);
		extractSmallintUclc(docctx, basexpath, "y", "y", y);
		extractStringUclc(docctx, basexpath, "jnumsSub", "sub", jnumsSub);
		extractStringUclc(docctx, basexpath, "jnumsLink", "lnk", jnumsLink);
		extractIntUclc(docctx, basexpath, "w", "w", w);
		extractIntUclc(docctx, basexpath, "h", "h", h);
		extractStringUclc(docctx, basexpath, "Content1", "cnt1", Content1);
		extractStringUclc(docctx, basexpath, "Content2", "cnt2", Content2);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVisBoxctx
 ******************************************************************************/

ListWznmQVisBoxctx::ListWznmQVisBoxctx() {
};

ListWznmQVisBoxctx::ListWznmQVisBoxctx(
			const ListWznmQVisBoxctx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisBoxctx(*(src.nodes[i]));
};

ListWznmQVisBoxctx& ListWznmQVisBoxctx::operator=(
			const ListWznmQVisBoxctx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisBoxctx(*(src.nodes[i]));

	return *this;
};

ListWznmQVisBoxctx::~ListWznmQVisBoxctx() {
	clear();
};

void ListWznmQVisBoxctx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVisBoxctx::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVisBoxctx* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVisBoxctx");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVisBoxctx", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVisBoxctx(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVisBoxctx[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
