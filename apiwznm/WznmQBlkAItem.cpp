/**
	* \file WznmQBlkAItem.cpp
	* API code for table TblWznmQBlkAItem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQBlkAItem.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBlkAItem
 ******************************************************************************/

WznmQBlkAItem::WznmQBlkAItem(
			const uint jnum
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string sref
			, const string srefIxWznmVVartype
			, const string titIxWznmVVartype
			, const string stubRefWznmMControl
			, const string stubRefWznmMVector
			, const string stubRefWznmMFeed
			, const string stubRefWznmMTable
			, const string stubRefWznmMBlock
			, const string Defval
			, const string stubRefWznmMVectoritem
			, const string Comment
		) {
	this->jnum = jnum;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->sref = sref;
	this->srefIxWznmVVartype = srefIxWznmVVartype;
	this->titIxWznmVVartype = titIxWznmVVartype;
	this->stubRefWznmMControl = stubRefWznmMControl;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->stubRefWznmMFeed = stubRefWznmMFeed;
	this->stubRefWznmMTable = stubRefWznmMTable;
	this->stubRefWznmMBlock = stubRefWznmMBlock;
	this->Defval = Defval;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->Comment = Comment;
};

bool WznmQBlkAItem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQBlkAItem");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "titIxWznmVVartype", "vty2", titIxWznmVVartype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMControl", "con", stubRefWznmMControl);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVector", "vec", stubRefWznmMVector);
		extractStringUclc(docctx, basexpath, "stubRefWznmMFeed", "fed", stubRefWznmMFeed);
		extractStringUclc(docctx, basexpath, "stubRefWznmMTable", "tbl", stubRefWznmMTable);
		extractStringUclc(docctx, basexpath, "stubRefWznmMBlock", "bl2", stubRefWznmMBlock);
		extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVectoritem", "vit", stubRefWznmMVectoritem);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQBlkAItem
 ******************************************************************************/

ListWznmQBlkAItem::ListWznmQBlkAItem() {
};

ListWznmQBlkAItem::ListWznmQBlkAItem(
			const ListWznmQBlkAItem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBlkAItem(*(src.nodes[i]));
};

ListWznmQBlkAItem& ListWznmQBlkAItem::operator=(
			const ListWznmQBlkAItem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBlkAItem(*(src.nodes[i]));

	return *this;
};

ListWznmQBlkAItem::~ListWznmQBlkAItem() {
	clear();
};

void ListWznmQBlkAItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQBlkAItem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQBlkAItem* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQBlkAItem");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQBlkAItem", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQBlkAItem(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQBlkAItem[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
