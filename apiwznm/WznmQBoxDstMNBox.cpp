/**
	* \file WznmQBoxDstMNBox.cpp
	* API code for table TblWznmQBoxDstMNBox (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQBoxDstMNBox.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBoxDstMNBox
 ******************************************************************************/

WznmQBoxDstMNBox::WznmQBoxDstMNBox(
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

bool WznmQBoxDstMNBox::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQBoxDstMNBox");
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
 class ListWznmQBoxDstMNBox
 ******************************************************************************/

ListWznmQBoxDstMNBox::ListWznmQBoxDstMNBox() {
};

ListWznmQBoxDstMNBox::ListWznmQBoxDstMNBox(
			const ListWznmQBoxDstMNBox& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBoxDstMNBox(*(src.nodes[i]));
};

ListWznmQBoxDstMNBox& ListWznmQBoxDstMNBox::operator=(
			const ListWznmQBoxDstMNBox& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBoxDstMNBox(*(src.nodes[i]));

	return *this;
};

ListWznmQBoxDstMNBox::~ListWznmQBoxDstMNBox() {
	clear();
};

void ListWznmQBoxDstMNBox::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQBoxDstMNBox::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQBoxDstMNBox* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQBoxDstMNBox");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQBoxDstMNBox", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQBoxDstMNBox(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQBoxDstMNBox[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
