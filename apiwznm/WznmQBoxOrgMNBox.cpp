/**
	* \file WznmQBoxOrgMNBox.cpp
	* API code for table TblWznmQBoxOrgMNBox (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQBoxOrgMNBox.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBoxOrgMNBox
 ******************************************************************************/

WznmQBoxOrgMNBox::WznmQBoxOrgMNBox(
			const uint jnum
			, const string stubMref
			, const utinyint orgClk
			, const utinyint dstClk
			, const utinyint Weight
		) :
			jnum(jnum)
			, stubMref(stubMref)
			, orgClk(orgClk)
			, dstClk(dstClk)
			, Weight(Weight)
		{
};

bool WznmQBoxOrgMNBox::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQBoxOrgMNBox");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractUtinyintUclc(docctx, basexpath, "orgClk", "ocl", orgClk);
		extractUtinyintUclc(docctx, basexpath, "dstClk", "dcl", dstClk);
		extractUtinyintUclc(docctx, basexpath, "Weight", "wgt", Weight);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQBoxOrgMNBox
 ******************************************************************************/

ListWznmQBoxOrgMNBox::ListWznmQBoxOrgMNBox() {
};

ListWznmQBoxOrgMNBox::ListWznmQBoxOrgMNBox(
			const ListWznmQBoxOrgMNBox& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBoxOrgMNBox(*(src.nodes[i]));
};

ListWznmQBoxOrgMNBox& ListWznmQBoxOrgMNBox::operator=(
			const ListWznmQBoxOrgMNBox& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBoxOrgMNBox(*(src.nodes[i]));

	return *this;
};

ListWznmQBoxOrgMNBox::~ListWznmQBoxOrgMNBox() {
	clear();
};

void ListWznmQBoxOrgMNBox::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQBoxOrgMNBox::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQBoxOrgMNBox* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQBoxOrgMNBox");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQBoxOrgMNBox", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQBoxOrgMNBox(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQBoxOrgMNBox[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
