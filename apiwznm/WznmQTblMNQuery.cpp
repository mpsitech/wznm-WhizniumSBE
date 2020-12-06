/**
	* \file WznmQTblMNQuery.cpp
	* API code for table TblWznmQTblMNQuery (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblMNQuery.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblMNQuery
 ******************************************************************************/

WznmQTblMNQuery::WznmQTblMNQuery(
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

bool WznmQTblMNQuery::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblMNQuery");
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
 class ListWznmQTblMNQuery
 ******************************************************************************/

ListWznmQTblMNQuery::ListWznmQTblMNQuery() {
};

ListWznmQTblMNQuery::ListWznmQTblMNQuery(
			const ListWznmQTblMNQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblMNQuery(*(src.nodes[i]));
};

ListWznmQTblMNQuery& ListWznmQTblMNQuery::operator=(
			const ListWznmQTblMNQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblMNQuery(*(src.nodes[i]));

	return *this;
};

ListWznmQTblMNQuery::~ListWznmQTblMNQuery() {
	clear();
};

void ListWznmQTblMNQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblMNQuery::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblMNQuery* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblMNQuery");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblMNQuery", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblMNQuery(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblMNQuery[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
