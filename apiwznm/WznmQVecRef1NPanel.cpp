/**
	* \file WznmQVecRef1NPanel.cpp
	* API code for table TblWznmQVecRef1NPanel (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVecRef1NPanel.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVecRef1NPanel
 ******************************************************************************/

WznmQVecRef1NPanel::WznmQVecRef1NPanel(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQVecRef1NPanel::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVecRef1NPanel");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVecRef1NPanel
 ******************************************************************************/

ListWznmQVecRef1NPanel::ListWznmQVecRef1NPanel() {
};

ListWznmQVecRef1NPanel::ListWznmQVecRef1NPanel(
			const ListWznmQVecRef1NPanel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecRef1NPanel(*(src.nodes[i]));
};

ListWznmQVecRef1NPanel& ListWznmQVecRef1NPanel::operator=(
			const ListWznmQVecRef1NPanel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecRef1NPanel(*(src.nodes[i]));

	return *this;
};

ListWznmQVecRef1NPanel::~ListWznmQVecRef1NPanel() {
	clear();
};

void ListWznmQVecRef1NPanel::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVecRef1NPanel::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVecRef1NPanel* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVecRef1NPanel");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVecRef1NPanel", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVecRef1NPanel(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVecRef1NPanel[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
