/**
	* \file WznmQTblList.cpp
	* API code for table TblWznmQTblList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblList
 ******************************************************************************/

WznmQTblList::WznmQTblList(
			const uint jnum
			, const string sref
			, const string Short
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefWznmMVersion
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Short = Short;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
};

bool WznmQTblList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTblList
 ******************************************************************************/

ListWznmQTblList::ListWznmQTblList() {
};

ListWznmQTblList::ListWznmQTblList(
			const ListWznmQTblList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblList(*(src.nodes[i]));
};

ListWznmQTblList& ListWznmQTblList::operator=(
			const ListWznmQTblList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblList(*(src.nodes[i]));

	return *this;
};

ListWznmQTblList::~ListWznmQTblList() {
	clear();
};

void ListWznmQTblList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
