/**
	* \file WznmQSbsBsbMNSubset.cpp
	* API code for table TblWznmQSbsBsbMNSubset (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQSbsBsbMNSubset.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsBsbMNSubset
 ******************************************************************************/

WznmQSbsBsbMNSubset::WznmQSbsBsbMNSubset(
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

bool WznmQSbsBsbMNSubset::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSbsBsbMNSubset");
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
 class ListWznmQSbsBsbMNSubset
 ******************************************************************************/

ListWznmQSbsBsbMNSubset::ListWznmQSbsBsbMNSubset() {
};

ListWznmQSbsBsbMNSubset::ListWznmQSbsBsbMNSubset(
			const ListWznmQSbsBsbMNSubset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsBsbMNSubset(*(src.nodes[i]));
};

ListWznmQSbsBsbMNSubset& ListWznmQSbsBsbMNSubset::operator=(
			const ListWznmQSbsBsbMNSubset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsBsbMNSubset(*(src.nodes[i]));

	return *this;
};

ListWznmQSbsBsbMNSubset::~ListWznmQSbsBsbMNSubset() {
	clear();
};

void ListWznmQSbsBsbMNSubset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSbsBsbMNSubset::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSbsBsbMNSubset* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSbsBsbMNSubset");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSbsBsbMNSubset", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSbsBsbMNSubset(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSbsBsbMNSubset[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

