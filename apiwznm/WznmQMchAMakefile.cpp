/**
	* \file WznmQMchAMakefile.cpp
	* API code for table TblWznmQMchAMakefile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQMchAMakefile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMchAMakefile
 ******************************************************************************/

WznmQMchAMakefile::WznmQMchAMakefile(
			const uint jnum
			, const string x1SrefKTag
			, const string titX1SrefKTag
			, const string Val
		) :
			jnum(jnum)
			, x1SrefKTag(x1SrefKTag)
			, titX1SrefKTag(titX1SrefKTag)
			, Val(Val)
		{
};

bool WznmQMchAMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMchAMakefile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1SrefKTag", "tag", x1SrefKTag);
		extractStringUclc(docctx, basexpath, "titX1SrefKTag", "tag2", titX1SrefKTag);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQMchAMakefile
 ******************************************************************************/

ListWznmQMchAMakefile::ListWznmQMchAMakefile() {
};

ListWznmQMchAMakefile::ListWznmQMchAMakefile(
			const ListWznmQMchAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMchAMakefile(*(src.nodes[i]));
};

ListWznmQMchAMakefile& ListWznmQMchAMakefile::operator=(
			const ListWznmQMchAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMchAMakefile(*(src.nodes[i]));

	return *this;
};

ListWznmQMchAMakefile::~ListWznmQMchAMakefile() {
	clear();
};

void ListWznmQMchAMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMchAMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMchAMakefile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMchAMakefile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMchAMakefile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMchAMakefile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMchAMakefile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
