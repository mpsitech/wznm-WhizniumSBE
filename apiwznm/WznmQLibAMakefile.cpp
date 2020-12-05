/**
	* \file WznmQLibAMakefile.cpp
	* API code for table TblWznmQLibAMakefile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQLibAMakefile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQLibAMakefile
 ******************************************************************************/

WznmQLibAMakefile::WznmQLibAMakefile(
			const uint jnum
			, const string stubX1RefWznmMMachine
			, const string x2SrefKTag
			, const string titX2SrefKTag
			, const string Val
		) {
	this->jnum = jnum;
	this->stubX1RefWznmMMachine = stubX1RefWznmMMachine;
	this->x2SrefKTag = x2SrefKTag;
	this->titX2SrefKTag = titX2SrefKTag;
	this->Val = Val;
};

bool WznmQLibAMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQLibAMakefile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubX1RefWznmMMachine", "mch", stubX1RefWznmMMachine);
		extractStringUclc(docctx, basexpath, "x2SrefKTag", "tag", x2SrefKTag);
		extractStringUclc(docctx, basexpath, "titX2SrefKTag", "tag2", titX2SrefKTag);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQLibAMakefile
 ******************************************************************************/

ListWznmQLibAMakefile::ListWznmQLibAMakefile() {
};

ListWznmQLibAMakefile::ListWznmQLibAMakefile(
			const ListWznmQLibAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibAMakefile(*(src.nodes[i]));
};

ListWznmQLibAMakefile& ListWznmQLibAMakefile::operator=(
			const ListWznmQLibAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibAMakefile(*(src.nodes[i]));

	return *this;
};

ListWznmQLibAMakefile::~ListWznmQLibAMakefile() {
	clear();
};

void ListWznmQLibAMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQLibAMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQLibAMakefile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQLibAMakefile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQLibAMakefile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQLibAMakefile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQLibAMakefile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

