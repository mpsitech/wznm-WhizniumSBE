/**
	* \file WznmQRelRef1NDialog.cpp
	* API code for table TblWznmQRelRef1NDialog (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRelRef1NDialog.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRelRef1NDialog
 ******************************************************************************/

WznmQRelRef1NDialog::WznmQRelRef1NDialog(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQRelRef1NDialog::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQRelRef1NDialog");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQRelRef1NDialog
 ******************************************************************************/

ListWznmQRelRef1NDialog::ListWznmQRelRef1NDialog() {
};

ListWznmQRelRef1NDialog::ListWznmQRelRef1NDialog(
			const ListWznmQRelRef1NDialog& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRelRef1NDialog(*(src.nodes[i]));
};

ListWznmQRelRef1NDialog& ListWznmQRelRef1NDialog::operator=(
			const ListWznmQRelRef1NDialog& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRelRef1NDialog(*(src.nodes[i]));

	return *this;
};

ListWznmQRelRef1NDialog::~ListWznmQRelRef1NDialog() {
	clear();
};

void ListWznmQRelRef1NDialog::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQRelRef1NDialog::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQRelRef1NDialog* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQRelRef1NDialog");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQRelRef1NDialog", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQRelRef1NDialog(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQRelRef1NDialog[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
