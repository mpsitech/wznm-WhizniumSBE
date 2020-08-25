/**
	* \file WznmQMtyAMakefile.cpp
	* API code for table TblWznmQMtyAMakefile (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQMtyAMakefile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMtyAMakefile
 ******************************************************************************/

WznmQMtyAMakefile::WznmQMtyAMakefile(
			const uint jnum
			, const string x1SrefKTag
			, const string titX1SrefKTag
			, const string Val
		) {
	this->jnum = jnum;
	this->x1SrefKTag = x1SrefKTag;
	this->titX1SrefKTag = titX1SrefKTag;
	this->Val = Val;
};

bool WznmQMtyAMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMtyAMakefile");
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
 class ListWznmQMtyAMakefile
 ******************************************************************************/

ListWznmQMtyAMakefile::ListWznmQMtyAMakefile() {
};

ListWznmQMtyAMakefile::ListWznmQMtyAMakefile(
			const ListWznmQMtyAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtyAMakefile(*(src.nodes[i]));
};

ListWznmQMtyAMakefile& ListWznmQMtyAMakefile::operator=(
			const ListWznmQMtyAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtyAMakefile(*(src.nodes[i]));

	return *this;
};

ListWznmQMtyAMakefile::~ListWznmQMtyAMakefile() {
	clear();
};

void ListWznmQMtyAMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMtyAMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMtyAMakefile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMtyAMakefile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMtyAMakefile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMtyAMakefile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMtyAMakefile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

