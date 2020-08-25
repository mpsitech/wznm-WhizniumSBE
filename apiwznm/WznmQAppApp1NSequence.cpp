/**
	* \file WznmQAppApp1NSequence.cpp
	* API code for table TblWznmQAppApp1NSequence (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQAppApp1NSequence.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQAppApp1NSequence
 ******************************************************************************/

WznmQAppApp1NSequence::WznmQAppApp1NSequence(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQAppApp1NSequence::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQAppApp1NSequence");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQAppApp1NSequence
 ******************************************************************************/

ListWznmQAppApp1NSequence::ListWznmQAppApp1NSequence() {
};

ListWznmQAppApp1NSequence::ListWznmQAppApp1NSequence(
			const ListWznmQAppApp1NSequence& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQAppApp1NSequence(*(src.nodes[i]));
};

ListWznmQAppApp1NSequence& ListWznmQAppApp1NSequence::operator=(
			const ListWznmQAppApp1NSequence& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQAppApp1NSequence(*(src.nodes[i]));

	return *this;
};

ListWznmQAppApp1NSequence::~ListWznmQAppApp1NSequence() {
	clear();
};

void ListWznmQAppApp1NSequence::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQAppApp1NSequence::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQAppApp1NSequence* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQAppApp1NSequence");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQAppApp1NSequence", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQAppApp1NSequence(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQAppApp1NSequence[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

