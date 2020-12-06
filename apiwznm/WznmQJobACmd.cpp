/**
	* \file WznmQJobACmd.cpp
	* API code for table TblWznmQJobACmd (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQJobACmd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQJobACmd
 ******************************************************************************/

WznmQJobACmd::WznmQJobACmd(
			const uint jnum
			, const string sref
			, const string Comment
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Comment = Comment;
};

bool WznmQJobACmd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQJobACmd");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQJobACmd
 ******************************************************************************/

ListWznmQJobACmd::ListWznmQJobACmd() {
};

ListWznmQJobACmd::ListWznmQJobACmd(
			const ListWznmQJobACmd& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobACmd(*(src.nodes[i]));
};

ListWznmQJobACmd& ListWznmQJobACmd::operator=(
			const ListWznmQJobACmd& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobACmd(*(src.nodes[i]));

	return *this;
};

ListWznmQJobACmd::~ListWznmQJobACmd() {
	clear();
};

void ListWznmQJobACmd::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQJobACmd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQJobACmd* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQJobACmd");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQJobACmd", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQJobACmd(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQJobACmd[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
