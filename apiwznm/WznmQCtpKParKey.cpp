/**
	* \file WznmQCtpKParKey.cpp
	* API code for table TblWznmQCtpKParKey (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQCtpKParKey.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCtpKParKey
 ******************************************************************************/

WznmQCtpKParKey::WznmQCtpKParKey(
			const uint jnum
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const string Title
			, const string Comment
		) :
			jnum(jnum)
			, yesnoFixed(yesnoFixed)
			, sref(sref)
			, Avail(Avail)
			, Implied(Implied)
			, Title(Title)
			, Comment(Comment)
		{
};

bool WznmQCtpKParKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCtpKParKey");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "yesnoFixed", "fix", yesnoFixed);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Avail", "avl", Avail);
		extractStringUclc(docctx, basexpath, "Implied", "imp", Implied);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCtpKParKey
 ******************************************************************************/

ListWznmQCtpKParKey::ListWznmQCtpKParKey() {
};

ListWznmQCtpKParKey::ListWznmQCtpKParKey(
			const ListWznmQCtpKParKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpKParKey(*(src.nodes[i]));
};

ListWznmQCtpKParKey& ListWznmQCtpKParKey::operator=(
			const ListWznmQCtpKParKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpKParKey(*(src.nodes[i]));

	return *this;
};

ListWznmQCtpKParKey::~ListWznmQCtpKParKey() {
	clear();
};

void ListWznmQCtpKParKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCtpKParKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCtpKParKey* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCtpKParKey");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCtpKParKey", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCtpKParKey(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCtpKParKey[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
