/**
	* \file WznmQOpxList.cpp
	* API code for table TblWznmQOpxList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQOpxList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpxList
 ******************************************************************************/

WznmQOpxList::WznmQOpxList(
			const uint jnum
			, const string sref
			, const string stubRefWznmMOppack
			, const string yesnoShrdat
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWznmMOppack = stubRefWznmMOppack;
	this->yesnoShrdat = yesnoShrdat;
};

bool WznmQOpxList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQOpxList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMOppack", "opk", stubRefWznmMOppack);
		extractStringUclc(docctx, basexpath, "yesnoShrdat", "shd", yesnoShrdat);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQOpxList
 ******************************************************************************/

ListWznmQOpxList::ListWznmQOpxList() {
};

ListWznmQOpxList::ListWznmQOpxList(
			const ListWznmQOpxList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpxList(*(src.nodes[i]));
};

ListWznmQOpxList& ListWznmQOpxList::operator=(
			const ListWznmQOpxList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpxList(*(src.nodes[i]));

	return *this;
};

ListWznmQOpxList::~ListWznmQOpxList() {
	clear();
};

void ListWznmQOpxList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQOpxList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQOpxList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQOpxList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQOpxList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQOpxList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQOpxList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

