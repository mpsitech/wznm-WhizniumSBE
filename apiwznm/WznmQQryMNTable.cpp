/**
	* \file WznmQQryMNTable.cpp
	* API code for table TblWznmQQryMNTable (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQryMNTable.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryMNTable
 ******************************************************************************/

WznmQQryMNTable::WznmQQryMNTable(
			const uint jnum
			, const string stubMref
			, const string stubsTrefWznmMQuerymod
			, const string yesnoSource
			, const string Prefix
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubsTrefWznmMQuerymod = stubsTrefWznmMQuerymod;
	this->yesnoSource = yesnoSource;
	this->Prefix = Prefix;
};

bool WznmQQryMNTable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQQryMNTable");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubsTrefWznmMQuerymod", "tqmd", stubsTrefWznmMQuerymod);
		extractStringUclc(docctx, basexpath, "yesnoSource", "src", yesnoSource);
		extractStringUclc(docctx, basexpath, "Prefix", "pfx", Prefix);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQQryMNTable
 ******************************************************************************/

ListWznmQQryMNTable::ListWznmQQryMNTable() {
};

ListWznmQQryMNTable::ListWznmQQryMNTable(
			const ListWznmQQryMNTable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryMNTable(*(src.nodes[i]));
};

ListWznmQQryMNTable& ListWznmQQryMNTable::operator=(
			const ListWznmQQryMNTable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryMNTable(*(src.nodes[i]));

	return *this;
};

ListWznmQQryMNTable::~ListWznmQQryMNTable() {
	clear();
};

void ListWznmQQryMNTable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQQryMNTable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQQryMNTable* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQQryMNTable");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQQryMNTable", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQQryMNTable(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQQryMNTable[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
