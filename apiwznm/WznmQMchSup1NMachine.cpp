/**
	* \file WznmQMchSup1NMachine.cpp
	* API code for table TblWznmQMchSup1NMachine (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQMchSup1NMachine.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMchSup1NMachine
 ******************************************************************************/

WznmQMchSup1NMachine::WznmQMchSup1NMachine(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQMchSup1NMachine::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMchSup1NMachine");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQMchSup1NMachine
 ******************************************************************************/

ListWznmQMchSup1NMachine::ListWznmQMchSup1NMachine() {
};

ListWznmQMchSup1NMachine::ListWznmQMchSup1NMachine(
			const ListWznmQMchSup1NMachine& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMchSup1NMachine(*(src.nodes[i]));
};

ListWznmQMchSup1NMachine& ListWznmQMchSup1NMachine::operator=(
			const ListWznmQMchSup1NMachine& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMchSup1NMachine(*(src.nodes[i]));

	return *this;
};

ListWznmQMchSup1NMachine::~ListWznmQMchSup1NMachine() {
	clear();
};

void ListWznmQMchSup1NMachine::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMchSup1NMachine::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMchSup1NMachine* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMchSup1NMachine");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMchSup1NMachine", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMchSup1NMachine(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMchSup1NMachine[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
