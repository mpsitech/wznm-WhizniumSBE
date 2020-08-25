/**
	* \file WznmQSbsAsbMNSubset.cpp
	* API code for table TblWznmQSbsAsbMNSubset (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQSbsAsbMNSubset.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsAsbMNSubset
 ******************************************************************************/

WznmQSbsAsbMNSubset::WznmQSbsAsbMNSubset(
			const uint jnum
			, const string stubMref
			, const string srefIxVReltype
			, const string titIxVReltype
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxVReltype = srefIxVReltype;
	this->titIxVReltype = titIxVReltype;
};

bool WznmQSbsAsbMNSubset::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSbsAsbMNSubset");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxVReltype", "rty", srefIxVReltype);
		extractStringUclc(docctx, basexpath, "titIxVReltype", "rty2", titIxVReltype);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSbsAsbMNSubset
 ******************************************************************************/

ListWznmQSbsAsbMNSubset::ListWznmQSbsAsbMNSubset() {
};

ListWznmQSbsAsbMNSubset::ListWznmQSbsAsbMNSubset(
			const ListWznmQSbsAsbMNSubset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsAsbMNSubset(*(src.nodes[i]));
};

ListWznmQSbsAsbMNSubset& ListWznmQSbsAsbMNSubset::operator=(
			const ListWznmQSbsAsbMNSubset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsAsbMNSubset(*(src.nodes[i]));

	return *this;
};

ListWznmQSbsAsbMNSubset::~ListWznmQSbsAsbMNSubset() {
	clear();
};

void ListWznmQSbsAsbMNSubset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSbsAsbMNSubset::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSbsAsbMNSubset* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSbsAsbMNSubset");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSbsAsbMNSubset", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSbsAsbMNSubset(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSbsAsbMNSubset[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

