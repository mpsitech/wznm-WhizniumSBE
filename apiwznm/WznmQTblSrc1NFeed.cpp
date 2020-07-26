/**
	* \file WznmQTblSrc1NFeed.cpp
	* API code for table TblWznmQTblSrc1NFeed (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQTblSrc1NFeed.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblSrc1NFeed
 ******************************************************************************/

WznmQTblSrc1NFeed::WznmQTblSrc1NFeed(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTblSrc1NFeed::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblSrc1NFeed");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTblSrc1NFeed
 ******************************************************************************/

ListWznmQTblSrc1NFeed::ListWznmQTblSrc1NFeed() {
};

ListWznmQTblSrc1NFeed::ListWznmQTblSrc1NFeed(
			const ListWznmQTblSrc1NFeed& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblSrc1NFeed(*(src.nodes[i]));
};

ListWznmQTblSrc1NFeed& ListWznmQTblSrc1NFeed::operator=(
			const ListWznmQTblSrc1NFeed& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblSrc1NFeed(*(src.nodes[i]));

	return *this;
};

ListWznmQTblSrc1NFeed::~ListWznmQTblSrc1NFeed() {
	clear();
};

void ListWznmQTblSrc1NFeed::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblSrc1NFeed::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblSrc1NFeed* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblSrc1NFeed");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblSrc1NFeed", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblSrc1NFeed(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblSrc1NFeed[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

