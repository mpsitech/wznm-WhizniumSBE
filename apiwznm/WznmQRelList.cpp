/**
	* \file WznmQRelList.cpp
	* API code for table TblWznmQRelList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQRelList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRelList
 ******************************************************************************/

WznmQRelList::WznmQRelList(
			const uint jnum
			, const string stubFrRefWznmMTable
			, const string stubFrsRefWznmMSubset
			, const string stubToRefWznmMTable
			, const string stubTosRefWznmMSubset
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefWznmMVersion
			, const string stubSupRefWznmMRelation
			, const string srefSupIxVSubrole
			, const string titSupIxVSubrole
			, const string stubRefWznmMTable
			, const string Prefix
		) {
	this->jnum = jnum;
	this->stubFrRefWznmMTable = stubFrRefWznmMTable;
	this->stubFrsRefWznmMSubset = stubFrsRefWznmMSubset;
	this->stubToRefWznmMTable = stubToRefWznmMTable;
	this->stubTosRefWznmMSubset = stubTosRefWznmMSubset;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->stubSupRefWznmMRelation = stubSupRefWznmMRelation;
	this->srefSupIxVSubrole = srefSupIxVSubrole;
	this->titSupIxVSubrole = titSupIxVSubrole;
	this->stubRefWznmMTable = stubRefWznmMTable;
	this->Prefix = Prefix;
};

bool WznmQRelList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQRelList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubFrRefWznmMTable", "frt", stubFrRefWznmMTable);
		extractStringUclc(docctx, basexpath, "stubFrsRefWznmMSubset", "frs", stubFrsRefWznmMSubset);
		extractStringUclc(docctx, basexpath, "stubToRefWznmMTable", "tot", stubToRefWznmMTable);
		extractStringUclc(docctx, basexpath, "stubTosRefWznmMSubset", "tos", stubTosRefWznmMSubset);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "stubSupRefWznmMRelation", "sup", stubSupRefWznmMRelation);
		extractStringUclc(docctx, basexpath, "srefSupIxVSubrole", "srl", srefSupIxVSubrole);
		extractStringUclc(docctx, basexpath, "titSupIxVSubrole", "srl2", titSupIxVSubrole);
		extractStringUclc(docctx, basexpath, "stubRefWznmMTable", "tbl", stubRefWznmMTable);
		extractStringUclc(docctx, basexpath, "Prefix", "pfx", Prefix);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQRelList
 ******************************************************************************/

ListWznmQRelList::ListWznmQRelList() {
};

ListWznmQRelList::ListWznmQRelList(
			const ListWznmQRelList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRelList(*(src.nodes[i]));
};

ListWznmQRelList& ListWznmQRelList::operator=(
			const ListWznmQRelList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRelList(*(src.nodes[i]));

	return *this;
};

ListWznmQRelList::~ListWznmQRelList() {
	clear();
};

void ListWznmQRelList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQRelList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQRelList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQRelList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQRelList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQRelList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQRelList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

