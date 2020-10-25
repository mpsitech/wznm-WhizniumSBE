/**
	* \file WznmQMdlMdl1NCard.cpp
	* API code for table TblWznmQMdlMdl1NCard (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQMdlMdl1NCard.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMdlMdl1NCard
 ******************************************************************************/

WznmQMdlMdl1NCard::WznmQMdlMdl1NCard(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQMdlMdl1NCard::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMdlMdl1NCard");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQMdlMdl1NCard
 ******************************************************************************/

ListWznmQMdlMdl1NCard::ListWznmQMdlMdl1NCard() {
};

ListWznmQMdlMdl1NCard::ListWznmQMdlMdl1NCard(
			const ListWznmQMdlMdl1NCard& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMdlMdl1NCard(*(src.nodes[i]));
};

ListWznmQMdlMdl1NCard& ListWznmQMdlMdl1NCard::operator=(
			const ListWznmQMdlMdl1NCard& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMdlMdl1NCard(*(src.nodes[i]));

	return *this;
};

ListWznmQMdlMdl1NCard::~ListWznmQMdlMdl1NCard() {
	clear();
};

void ListWznmQMdlMdl1NCard::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMdlMdl1NCard::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMdlMdl1NCard* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMdlMdl1NCard");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMdlMdl1NCard", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMdlMdl1NCard(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMdlMdl1NCard[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

