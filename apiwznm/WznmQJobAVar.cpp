/**
	* \file WznmQJobAVar.cpp
	* API code for table TblWznmQJobAVar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQJobAVar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQJobAVar
 ******************************************************************************/

WznmQJobAVar::WznmQJobAVar(
			const uint jnum
			, const string sref
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const string stubRefWznmMVector
			, const uint Length
			, const string yesnoShr
			, const string Comment
		) :
			jnum(jnum)
			, sref(sref)
			, srefIxWznmVVartype(srefIxWznmVVartype)
			, titIxWznmVVartype(titIxWznmVVartype)
			, stubRefWznmMVector(stubRefWznmMVector)
			, Length(Length)
			, yesnoShr(yesnoShr)
			, Comment(Comment)
		{
};

bool WznmQJobAVar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQJobAVar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "titIxWznmVVartype", "vty2", titIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVector", "vec", stubRefWznmMVector);
		extractUintUclc(docctx, basexpath, "Length", "len", Length);
		extractStringUclc(docctx, basexpath, "yesnoShr", "shr", yesnoShr);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQJobAVar
 ******************************************************************************/

ListWznmQJobAVar::ListWznmQJobAVar() {
};

ListWznmQJobAVar::ListWznmQJobAVar(
			const ListWznmQJobAVar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobAVar(*(src.nodes[i]));
};

ListWznmQJobAVar& ListWznmQJobAVar::operator=(
			const ListWznmQJobAVar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobAVar(*(src.nodes[i]));

	return *this;
};

ListWznmQJobAVar::~ListWznmQJobAVar() {
	clear();
};

void ListWznmQJobAVar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQJobAVar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQJobAVar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQJobAVar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQJobAVar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQJobAVar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQJobAVar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
