/**
	* \file WznmQSbsATitle.cpp
	* API code for table TblWznmQSbsATitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSbsATitle.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsATitle
 ******************************************************************************/

WznmQSbsATitle::WznmQSbsATitle(
			const uint jnum
			, const string srefX1IxVType
			, const string titX1IxVType
			, const string stubX2RefWznmMLocale
			, const string srefIxWznmVGender
			, const string titIxWznmVGender
			, const string Title
		) {
	this->jnum = jnum;
	this->srefX1IxVType = srefX1IxVType;
	this->titX1IxVType = titX1IxVType;
	this->stubX2RefWznmMLocale = stubX2RefWznmMLocale;
	this->srefIxWznmVGender = srefIxWznmVGender;
	this->titIxWznmVGender = titIxWznmVGender;
	this->Title = Title;
};

bool WznmQSbsATitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSbsATitle");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxVType", "typ", srefX1IxVType);
		extractStringUclc(docctx, basexpath, "titX1IxVType", "typ2", titX1IxVType);
		extractStringUclc(docctx, basexpath, "stubX2RefWznmMLocale", "loc", stubX2RefWznmMLocale);
		extractStringUclc(docctx, basexpath, "srefIxWznmVGender", "gnd", srefIxWznmVGender);
		extractStringUclc(docctx, basexpath, "titIxWznmVGender", "gnd2", titIxWznmVGender);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSbsATitle
 ******************************************************************************/

ListWznmQSbsATitle::ListWznmQSbsATitle() {
};

ListWznmQSbsATitle::ListWznmQSbsATitle(
			const ListWznmQSbsATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsATitle(*(src.nodes[i]));
};

ListWznmQSbsATitle& ListWznmQSbsATitle::operator=(
			const ListWznmQSbsATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsATitle(*(src.nodes[i]));

	return *this;
};

ListWznmQSbsATitle::~ListWznmQSbsATitle() {
	clear();
};

void ListWznmQSbsATitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSbsATitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSbsATitle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSbsATitle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSbsATitle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSbsATitle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSbsATitle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
