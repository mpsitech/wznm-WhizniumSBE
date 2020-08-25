/**
	* \file WznmQTblMNVector.cpp
	* API code for table TblWznmQTblMNVector (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQTblMNVector.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblMNVector
 ******************************************************************************/

WznmQTblMNVector::WznmQTblMNVector(
			const uint jnum
			, const string stubMref
			, const string stubRefWznmMSubset
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubRefWznmMSubset = stubRefWznmMSubset;
};

bool WznmQTblMNVector::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblMNVector");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMSubset", "sbs", stubRefWznmMSubset);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTblMNVector
 ******************************************************************************/

ListWznmQTblMNVector::ListWznmQTblMNVector() {
};

ListWznmQTblMNVector::ListWznmQTblMNVector(
			const ListWznmQTblMNVector& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblMNVector(*(src.nodes[i]));
};

ListWznmQTblMNVector& ListWznmQTblMNVector::operator=(
			const ListWznmQTblMNVector& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblMNVector(*(src.nodes[i]));

	return *this;
};

ListWznmQTblMNVector::~ListWznmQTblMNVector() {
	clear();
};

void ListWznmQTblMNVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblMNVector::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblMNVector* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblMNVector");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblMNVector", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblMNVector(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblMNVector[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

