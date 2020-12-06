/**
	* \file WznmQMdlRef1NPanel.cpp
	* API code for table TblWznmQMdlRef1NPanel (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQMdlRef1NPanel.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMdlRef1NPanel
 ******************************************************************************/

WznmQMdlRef1NPanel::WznmQMdlRef1NPanel(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQMdlRef1NPanel::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMdlRef1NPanel");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQMdlRef1NPanel
 ******************************************************************************/

ListWznmQMdlRef1NPanel::ListWznmQMdlRef1NPanel() {
};

ListWznmQMdlRef1NPanel::ListWznmQMdlRef1NPanel(
			const ListWznmQMdlRef1NPanel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMdlRef1NPanel(*(src.nodes[i]));
};

ListWznmQMdlRef1NPanel& ListWznmQMdlRef1NPanel::operator=(
			const ListWznmQMdlRef1NPanel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMdlRef1NPanel(*(src.nodes[i]));

	return *this;
};

ListWznmQMdlRef1NPanel::~ListWznmQMdlRef1NPanel() {
	clear();
};

void ListWznmQMdlRef1NPanel::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMdlRef1NPanel::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMdlRef1NPanel* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMdlRef1NPanel");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMdlRef1NPanel", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMdlRef1NPanel(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMdlRef1NPanel[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
