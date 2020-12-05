/**
	* \file WznmQTcoList.cpp
	* API code for table TblWznmQTcoList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTcoList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTcoList
 ******************************************************************************/

WznmQTcoList::WznmQTcoList(
			const uint jnum
			, const string sref
			, const string Short
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubTblRefWznmMTable
			, const string srefFctIxVTbl
			, const string titFctIxVTbl
			, const string srefIxVSubtype
			, const string titIxVSubtype
			, const string srefIxVAxisfct
			, const string titIxVAxisfct
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Short = Short;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubTblRefWznmMTable = stubTblRefWznmMTable;
	this->srefFctIxVTbl = srefFctIxVTbl;
	this->titFctIxVTbl = titFctIxVTbl;
	this->srefIxVSubtype = srefIxVSubtype;
	this->titIxVSubtype = titIxVSubtype;
	this->srefIxVAxisfct = srefIxVAxisfct;
	this->titIxVAxisfct = titIxVAxisfct;
};

bool WznmQTcoList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTcoList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubTblRefWznmMTable", "tbl", stubTblRefWznmMTable);
		extractStringUclc(docctx, basexpath, "srefFctIxVTbl", "fct", srefFctIxVTbl);
		extractStringUclc(docctx, basexpath, "titFctIxVTbl", "fct2", titFctIxVTbl);
		extractStringUclc(docctx, basexpath, "srefIxVSubtype", "sty", srefIxVSubtype);
		extractStringUclc(docctx, basexpath, "titIxVSubtype", "sty2", titIxVSubtype);
		extractStringUclc(docctx, basexpath, "srefIxVAxisfct", "axf", srefIxVAxisfct);
		extractStringUclc(docctx, basexpath, "titIxVAxisfct", "axf2", titIxVAxisfct);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTcoList
 ******************************************************************************/

ListWznmQTcoList::ListWznmQTcoList() {
};

ListWznmQTcoList::ListWznmQTcoList(
			const ListWznmQTcoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoList(*(src.nodes[i]));
};

ListWznmQTcoList& ListWznmQTcoList::operator=(
			const ListWznmQTcoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoList(*(src.nodes[i]));

	return *this;
};

ListWznmQTcoList::~ListWznmQTcoList() {
	clear();
};

void ListWznmQTcoList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTcoList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTcoList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTcoList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTcoList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTcoList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTcoList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

