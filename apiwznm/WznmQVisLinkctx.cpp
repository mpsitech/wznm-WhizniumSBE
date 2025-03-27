/**
	* \file WznmQVisLinkctx.cpp
	* API code for table TblWznmQVisLinkctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQVisLinkctx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVisLinkctx
 ******************************************************************************/

WznmQVisLinkctx::WznmQVisLinkctx(
			const uint jnum
			, const utinyint orgClk
			, const utinyint dstClk
			, const utinyint Weight
			, const int jnumBoxOrg
			, const int jnumBoxDst
			, const string Title
			, const string Content1
			, const string Content2
		) :
			jnum(jnum)
			, orgClk(orgClk)
			, dstClk(dstClk)
			, Weight(Weight)
			, jnumBoxOrg(jnumBoxOrg)
			, jnumBoxDst(jnumBoxDst)
			, Title(Title)
			, Content1(Content1)
			, Content2(Content2)
		{
};

bool WznmQVisLinkctx::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVisLinkctx");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractUtinyintUclc(docctx, basexpath, "orgClk", "ocl", orgClk);
		extractUtinyintUclc(docctx, basexpath, "dstClk", "dcl", dstClk);
		extractUtinyintUclc(docctx, basexpath, "Weight", "wgt", Weight);
		extractIntUclc(docctx, basexpath, "jnumBoxOrg", "", jnumBoxOrg);
		extractIntUclc(docctx, basexpath, "jnumBoxDst", "", jnumBoxDst);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Content1", "cnt1", Content1);
		extractStringUclc(docctx, basexpath, "Content2", "cnt2", Content2);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVisLinkctx
 ******************************************************************************/

ListWznmQVisLinkctx::ListWznmQVisLinkctx() {
};

ListWznmQVisLinkctx::ListWznmQVisLinkctx(
			const ListWznmQVisLinkctx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisLinkctx(*(src.nodes[i]));
};

ListWznmQVisLinkctx& ListWznmQVisLinkctx::operator=(
			const ListWznmQVisLinkctx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisLinkctx(*(src.nodes[i]));

	return *this;
};

ListWznmQVisLinkctx::~ListWznmQVisLinkctx() {
	clear();
};

void ListWznmQVisLinkctx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVisLinkctx::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVisLinkctx* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVisLinkctx");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVisLinkctx", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVisLinkctx(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVisLinkctx[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
