/**
	* \file WznmQOpkAInvarg.cpp
	* API code for table TblWznmQOpkAInvarg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQOpkAInvarg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpkAInvarg
 ******************************************************************************/

WznmQOpkAInvarg::WznmQOpkAInvarg(
			const uint jnum
			, const string sref
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const string stubRefWznmMVector
			, const string Defval
			, const string stubRefWznmMVectoritem
			, const string Comment
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxWznmVVartype = srefIxWznmVVartype;
	this->titIxWznmVVartype = titIxWznmVVartype;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->Defval = Defval;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->Comment = Comment;
};

bool WznmQOpkAInvarg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQOpkAInvarg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "titIxWznmVVartype", "vty2", titIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVector", "vec", stubRefWznmMVector);
		extractStringUclc(docctx, basexpath, "Defval", "dvl", Defval);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVectoritem", "vit", stubRefWznmMVectoritem);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQOpkAInvarg
 ******************************************************************************/

ListWznmQOpkAInvarg::ListWznmQOpkAInvarg() {
};

ListWznmQOpkAInvarg::ListWznmQOpkAInvarg(
			const ListWznmQOpkAInvarg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkAInvarg(*(src.nodes[i]));
};

ListWznmQOpkAInvarg& ListWznmQOpkAInvarg::operator=(
			const ListWznmQOpkAInvarg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkAInvarg(*(src.nodes[i]));

	return *this;
};

ListWznmQOpkAInvarg::~ListWznmQOpkAInvarg() {
	clear();
};

void ListWznmQOpkAInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQOpkAInvarg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQOpkAInvarg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQOpkAInvarg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQOpkAInvarg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQOpkAInvarg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQOpkAInvarg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
