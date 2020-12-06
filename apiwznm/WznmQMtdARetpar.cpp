/**
	* \file WznmQMtdARetpar.cpp
	* API code for table TblWznmQMtdARetpar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQMtdARetpar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMtdARetpar
 ******************************************************************************/

WznmQMtdARetpar::WznmQMtdARetpar(
			const uint jnum
			, const string sref
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const string stubRefWznmMVector
			, const uint Length
			, const string Comment
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxWznmVVartype = srefIxWznmVVartype;
	this->titIxWznmVVartype = titIxWznmVVartype;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->Length = Length;
	this->Comment = Comment;
};

bool WznmQMtdARetpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMtdARetpar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "titIxWznmVVartype", "vty2", titIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVector", "vec", stubRefWznmMVector);
		extractUintUclc(docctx, basexpath, "Length", "len", Length);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQMtdARetpar
 ******************************************************************************/

ListWznmQMtdARetpar::ListWznmQMtdARetpar() {
};

ListWznmQMtdARetpar::ListWznmQMtdARetpar(
			const ListWznmQMtdARetpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtdARetpar(*(src.nodes[i]));
};

ListWznmQMtdARetpar& ListWznmQMtdARetpar::operator=(
			const ListWznmQMtdARetpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtdARetpar(*(src.nodes[i]));

	return *this;
};

ListWznmQMtdARetpar::~ListWznmQMtdARetpar() {
	clear();
};

void ListWznmQMtdARetpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMtdARetpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMtdARetpar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMtdARetpar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMtdARetpar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMtdARetpar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMtdARetpar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
