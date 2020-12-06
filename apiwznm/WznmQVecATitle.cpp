/**
	* \file WznmQVecATitle.cpp
	* API code for table TblWznmQVecATitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVecATitle.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVecATitle
 ******************************************************************************/

WznmQVecATitle::WznmQVecATitle(
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

bool WznmQVecATitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVecATitle");
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
 class ListWznmQVecATitle
 ******************************************************************************/

ListWznmQVecATitle::ListWznmQVecATitle() {
};

ListWznmQVecATitle::ListWznmQVecATitle(
			const ListWznmQVecATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecATitle(*(src.nodes[i]));
};

ListWznmQVecATitle& ListWznmQVecATitle::operator=(
			const ListWznmQVecATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecATitle(*(src.nodes[i]));

	return *this;
};

ListWznmQVecATitle::~ListWznmQVecATitle() {
	clear();
};

void ListWznmQVecATitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVecATitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVecATitle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVecATitle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVecATitle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVecATitle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVecATitle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
