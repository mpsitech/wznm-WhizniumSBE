/**
	* \file WznmQDlgRef1NControl.cpp
	* API code for table TblWznmQDlgRef1NControl (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQDlgRef1NControl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQDlgRef1NControl
 ******************************************************************************/

WznmQDlgRef1NControl::WznmQDlgRef1NControl(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQDlgRef1NControl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQDlgRef1NControl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQDlgRef1NControl
 ******************************************************************************/

ListWznmQDlgRef1NControl::ListWznmQDlgRef1NControl() {
};

ListWznmQDlgRef1NControl::ListWznmQDlgRef1NControl(
			const ListWznmQDlgRef1NControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQDlgRef1NControl(*(src.nodes[i]));
};

ListWznmQDlgRef1NControl& ListWznmQDlgRef1NControl::operator=(
			const ListWznmQDlgRef1NControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQDlgRef1NControl(*(src.nodes[i]));

	return *this;
};

ListWznmQDlgRef1NControl::~ListWznmQDlgRef1NControl() {
	clear();
};

void ListWznmQDlgRef1NControl::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQDlgRef1NControl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQDlgRef1NControl* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQDlgRef1NControl");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQDlgRef1NControl", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQDlgRef1NControl(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQDlgRef1NControl[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

