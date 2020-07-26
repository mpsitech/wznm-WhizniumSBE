/**
	* \file WznmQVecList.cpp
	* API code for table TblWznmQVecList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQVecList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVecList
 ******************************************************************************/

WznmQVecList::WznmQVecList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefWznmMVersion
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const string stubHkUref
			, const string osrefWznmKTaggrp
			, const string titOsrefWznmKTaggrp
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->stubHkUref = stubHkUref;
	this->osrefWznmKTaggrp = osrefWznmKTaggrp;
	this->titOsrefWznmKTaggrp = titOsrefWznmKTaggrp;
};

bool WznmQVecList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVecList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "srefHkIxVTbl", "hkt", srefHkIxVTbl);
		extractStringUclc(docctx, basexpath, "titHkIxVTbl", "hkt2", titHkIxVTbl);
		extractStringUclc(docctx, basexpath, "stubHkUref", "hku", stubHkUref);
		extractStringUclc(docctx, basexpath, "osrefWznmKTaggrp", "tgr", osrefWznmKTaggrp);
		extractStringUclc(docctx, basexpath, "titOsrefWznmKTaggrp", "tgr2", titOsrefWznmKTaggrp);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVecList
 ******************************************************************************/

ListWznmQVecList::ListWznmQVecList() {
};

ListWznmQVecList::ListWznmQVecList(
			const ListWznmQVecList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecList(*(src.nodes[i]));
};

ListWznmQVecList& ListWznmQVecList::operator=(
			const ListWznmQVecList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecList(*(src.nodes[i]));

	return *this;
};

ListWznmQVecList::~ListWznmQVecList() {
	clear();
};

void ListWznmQVecList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVecList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVecList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVecList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVecList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVecList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVecList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

