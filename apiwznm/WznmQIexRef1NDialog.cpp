/**
	* \file WznmQIexRef1NDialog.cpp
	* API code for table TblWznmQIexRef1NDialog (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQIexRef1NDialog.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQIexRef1NDialog
 ******************************************************************************/

WznmQIexRef1NDialog::WznmQIexRef1NDialog(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQIexRef1NDialog::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQIexRef1NDialog");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQIexRef1NDialog
 ******************************************************************************/

ListWznmQIexRef1NDialog::ListWznmQIexRef1NDialog() {
};

ListWznmQIexRef1NDialog::ListWznmQIexRef1NDialog(
			const ListWznmQIexRef1NDialog& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIexRef1NDialog(*(src.nodes[i]));
};

ListWznmQIexRef1NDialog& ListWznmQIexRef1NDialog::operator=(
			const ListWznmQIexRef1NDialog& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIexRef1NDialog(*(src.nodes[i]));

	return *this;
};

ListWznmQIexRef1NDialog::~ListWznmQIexRef1NDialog() {
	clear();
};

void ListWznmQIexRef1NDialog::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQIexRef1NDialog::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQIexRef1NDialog* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQIexRef1NDialog");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQIexRef1NDialog", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQIexRef1NDialog(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQIexRef1NDialog[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

