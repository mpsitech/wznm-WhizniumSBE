/**
	* \file WznmQTblATitle.cpp
	* API code for table TblWznmQTblATitle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblATitle.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblATitle
 ******************************************************************************/

WznmQTblATitle::WznmQTblATitle(
			const uint jnum
			, const string srefX1IxVType
			, const string titX1IxVType
			, const string stubX2RefWznmMLocale
			, const string srefIxWznmVGender
			, const string titIxWznmVGender
			, const string Title
		) :
			jnum(jnum)
			, srefX1IxVType(srefX1IxVType)
			, titX1IxVType(titX1IxVType)
			, stubX2RefWznmMLocale(stubX2RefWznmMLocale)
			, srefIxWznmVGender(srefIxWznmVGender)
			, titIxWznmVGender(titIxWznmVGender)
			, Title(Title)
		{
};

bool WznmQTblATitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblATitle");
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
 class ListWznmQTblATitle
 ******************************************************************************/

ListWznmQTblATitle::ListWznmQTblATitle() {
};

ListWznmQTblATitle::ListWznmQTblATitle(
			const ListWznmQTblATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblATitle(*(src.nodes[i]));
};

ListWznmQTblATitle& ListWznmQTblATitle::operator=(
			const ListWznmQTblATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblATitle(*(src.nodes[i]));

	return *this;
};

ListWznmQTblATitle::~ListWznmQTblATitle() {
	clear();
};

void ListWznmQTblATitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblATitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblATitle* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblATitle");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblATitle", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblATitle(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblATitle[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
