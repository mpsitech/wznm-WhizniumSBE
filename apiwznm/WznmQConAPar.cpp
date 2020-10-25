/**
	* \file WznmQConAPar.cpp
	* API code for table TblWznmQConAPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQConAPar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQConAPar
 ******************************************************************************/

WznmQConAPar::WznmQConAPar(
			const uint jnum
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string stubX2RefWznmMLocale
			, const string osrefKVal
			, const string titOsrefKVal
		) {
	this->jnum = jnum;
	this->x1SrefKKey = x1SrefKKey;
	this->titX1SrefKKey = titX1SrefKKey;
	this->stubX2RefWznmMLocale = stubX2RefWznmMLocale;
	this->osrefKVal = osrefKVal;
	this->titOsrefKVal = titOsrefKVal;
};

bool WznmQConAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQConAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey);
		extractStringUclc(docctx, basexpath, "titX1SrefKKey", "key2", titX1SrefKKey);
		extractStringUclc(docctx, basexpath, "stubX2RefWznmMLocale", "loc", stubX2RefWznmMLocale);
		extractStringUclc(docctx, basexpath, "osrefKVal", "val", osrefKVal);
		extractStringUclc(docctx, basexpath, "titOsrefKVal", "val2", titOsrefKVal);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQConAPar
 ******************************************************************************/

ListWznmQConAPar::ListWznmQConAPar() {
};

ListWznmQConAPar::ListWznmQConAPar(
			const ListWznmQConAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQConAPar(*(src.nodes[i]));
};

ListWznmQConAPar& ListWznmQConAPar::operator=(
			const ListWznmQConAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQConAPar(*(src.nodes[i]));

	return *this;
};

ListWznmQConAPar::~ListWznmQConAPar() {
	clear();
};

void ListWznmQConAPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQConAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQConAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQConAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQConAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQConAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQConAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

