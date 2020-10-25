/**
	* \file WznmQQryAOrder.cpp
	* API code for table TblWznmQQryAOrder (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQQryAOrder.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryAOrder
 ******************************************************************************/

WznmQQryAOrder::WznmQQryAOrder(
			const uint jnum
			, const string Short
			, const string srefsWznmMTablecol
		) {
	this->jnum = jnum;
	this->Short = Short;
	this->srefsWznmMTablecol = srefsWznmMTablecol;
};

bool WznmQQryAOrder::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQQryAOrder");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "srefsWznmMTablecol", "tco", srefsWznmMTablecol);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQQryAOrder
 ******************************************************************************/

ListWznmQQryAOrder::ListWznmQQryAOrder() {
};

ListWznmQQryAOrder::ListWznmQQryAOrder(
			const ListWznmQQryAOrder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryAOrder(*(src.nodes[i]));
};

ListWznmQQryAOrder& ListWznmQQryAOrder::operator=(
			const ListWznmQQryAOrder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryAOrder(*(src.nodes[i]));

	return *this;
};

ListWznmQQryAOrder::~ListWznmQQryAOrder() {
	clear();
};

void ListWznmQQryAOrder::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQQryAOrder::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQQryAOrder* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQQryAOrder");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQQryAOrder", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQQryAOrder(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQQryAOrder[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

