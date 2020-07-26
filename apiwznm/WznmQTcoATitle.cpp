/**
	* \file WznmQTcoATitle.cpp
	* API code for table TblWznmQTcoATitle (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQTcoATitle.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTcoATitle
 ******************************************************************************/

WznmQTcoATitle::WznmQTcoATitle(
			const uint jnum
			, const string srefX1IxVType
			, const string titX1IxVType
			, const string stubX2RefWznmMLocale
			, const string Title
		) {
	this->jnum = jnum;
	this->srefX1IxVType = srefX1IxVType;
	this->titX1IxVType = titX1IxVType;
	this->stubX2RefWznmMLocale = stubX2RefWznmMLocale;
	this->Title = Title;
};

bool WznmQTcoATitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTcoATitle");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxVType", "typ", srefX1IxVType);
		extractStringUclc(docctx, basexpath, "titX1IxVType", "typ2", titX1IxVType);
		extractStringUclc(docctx, basexpath, "stubX2RefWznmMLocale", "loc", stubX2RefWznmMLocale);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTcoATitle
 ******************************************************************************/

ListWznmQTcoATitle::ListWznmQTcoATitle() {
};

ListWznmQTcoATitle::ListWznmQTcoATitle(
			const ListWznmQTcoATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoATitle(*(src.nodes[i]));
};

ListWznmQTcoATitle& ListWznmQTcoATitle::operator=(
			const ListWznmQTcoATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoATitle(*(src.nodes[i]));

	return *this;
};

ListWznmQTcoATitle::~ListWznmQTcoATitle() {
	clear();
};

void ListWznmQTcoATitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTcoATitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTcoATitle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTcoATitle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTcoATitle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTcoATitle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTcoATitle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

