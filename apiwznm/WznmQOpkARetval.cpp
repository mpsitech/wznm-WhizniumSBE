/**
	* \file WznmQOpkARetval.cpp
	* API code for table TblWznmQOpkARetval (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQOpkARetval.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpkARetval
 ******************************************************************************/

WznmQOpkARetval::WznmQOpkARetval(
			const uint jnum
			, const string sref
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const string stubRefWznmMVector
			, const string Comment
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxWznmVVartype = srefIxWznmVVartype;
	this->titIxWznmVVartype = titIxWznmVVartype;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->Comment = Comment;
};

bool WznmQOpkARetval::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQOpkARetval");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "titIxWznmVVartype", "vty2", titIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVector", "vec", stubRefWznmMVector);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQOpkARetval
 ******************************************************************************/

ListWznmQOpkARetval::ListWznmQOpkARetval() {
};

ListWznmQOpkARetval::ListWznmQOpkARetval(
			const ListWznmQOpkARetval& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkARetval(*(src.nodes[i]));
};

ListWznmQOpkARetval& ListWznmQOpkARetval::operator=(
			const ListWznmQOpkARetval& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkARetval(*(src.nodes[i]));

	return *this;
};

ListWznmQOpkARetval::~ListWznmQOpkARetval() {
	clear();
};

void ListWznmQOpkARetval::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQOpkARetval::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQOpkARetval* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQOpkARetval");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQOpkARetval", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQOpkARetval(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQOpkARetval[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
