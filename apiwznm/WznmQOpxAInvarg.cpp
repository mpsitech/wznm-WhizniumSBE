/**
	* \file WznmQOpxAInvarg.cpp
	* API code for table TblWznmQOpxAInvarg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQOpxAInvarg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpxAInvarg
 ******************************************************************************/

WznmQOpxAInvarg::WznmQOpxAInvarg(
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

bool WznmQOpxAInvarg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQOpxAInvarg");
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
 class ListWznmQOpxAInvarg
 ******************************************************************************/

ListWznmQOpxAInvarg::ListWznmQOpxAInvarg() {
};

ListWznmQOpxAInvarg::ListWznmQOpxAInvarg(
			const ListWznmQOpxAInvarg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpxAInvarg(*(src.nodes[i]));
};

ListWznmQOpxAInvarg& ListWznmQOpxAInvarg::operator=(
			const ListWznmQOpxAInvarg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpxAInvarg(*(src.nodes[i]));

	return *this;
};

ListWznmQOpxAInvarg::~ListWznmQOpxAInvarg() {
	clear();
};

void ListWznmQOpxAInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQOpxAInvarg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQOpxAInvarg* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQOpxAInvarg");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQOpxAInvarg", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQOpxAInvarg(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQOpxAInvarg[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

