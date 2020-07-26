/**
	* \file WznmQOpxRef1NBlock.cpp
	* API code for table TblWznmQOpxRef1NBlock (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQOpxRef1NBlock.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpxRef1NBlock
 ******************************************************************************/

WznmQOpxRef1NBlock::WznmQOpxRef1NBlock(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQOpxRef1NBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQOpxRef1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQOpxRef1NBlock
 ******************************************************************************/

ListWznmQOpxRef1NBlock::ListWznmQOpxRef1NBlock() {
};

ListWznmQOpxRef1NBlock::ListWznmQOpxRef1NBlock(
			const ListWznmQOpxRef1NBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpxRef1NBlock(*(src.nodes[i]));
};

ListWznmQOpxRef1NBlock& ListWznmQOpxRef1NBlock::operator=(
			const ListWznmQOpxRef1NBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpxRef1NBlock(*(src.nodes[i]));

	return *this;
};

ListWznmQOpxRef1NBlock::~ListWznmQOpxRef1NBlock() {
	clear();
};

void ListWznmQOpxRef1NBlock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQOpxRef1NBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQOpxRef1NBlock* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQOpxRef1NBlock");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQOpxRef1NBlock", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQOpxRef1NBlock(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQOpxRef1NBlock[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

