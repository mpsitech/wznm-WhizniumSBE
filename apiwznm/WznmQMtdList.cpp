/**
	* \file WznmQMtdList.cpp
	* API code for table TblWznmQMtdList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQMtdList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMtdList
 ******************************************************************************/

WznmQMtdList::WznmQMtdList(
			const uint jnum
			, const string sref
			, const string stubRefWznmMJob
			, const string yesnoExecsrv
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWznmMJob = stubRefWznmMJob;
	this->yesnoExecsrv = yesnoExecsrv;
};

bool WznmQMtdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMtdList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMJob", "job", stubRefWznmMJob);
		extractStringUclc(docctx, basexpath, "yesnoExecsrv", "exs", yesnoExecsrv);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQMtdList
 ******************************************************************************/

ListWznmQMtdList::ListWznmQMtdList() {
};

ListWznmQMtdList::ListWznmQMtdList(
			const ListWznmQMtdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtdList(*(src.nodes[i]));
};

ListWznmQMtdList& ListWznmQMtdList::operator=(
			const ListWznmQMtdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtdList(*(src.nodes[i]));

	return *this;
};

ListWznmQMtdList::~ListWznmQMtdList() {
	clear();
};

void ListWznmQMtdList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMtdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMtdList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMtdList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMtdList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMtdList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMtdList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

