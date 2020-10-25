/**
	* \file WznmQAppList.cpp
	* API code for table TblWznmQAppList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQAppList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQAppList
 ******************************************************************************/

WznmQAppList::WznmQAppList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string Short
			, const string Title
			, const string srefIxWznmVApptarget
			, const string titIxWznmVApptarget
			, const string stubVerRefWznmMVersion
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->Short = Short;
	this->Title = Title;
	this->srefIxWznmVApptarget = srefIxWznmVApptarget;
	this->titIxWznmVApptarget = titIxWznmVApptarget;
	this->stubVerRefWznmMVersion = stubVerRefWznmMVersion;
};

bool WznmQAppList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQAppList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxWznmVApptarget", "trg", srefIxWznmVApptarget);
		extractStringUclc(docctx, basexpath, "titIxWznmVApptarget", "trg2", titIxWznmVApptarget);
		extractStringUclc(docctx, basexpath, "stubVerRefWznmMVersion", "ver", stubVerRefWznmMVersion);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQAppList
 ******************************************************************************/

ListWznmQAppList::ListWznmQAppList() {
};

ListWznmQAppList::ListWznmQAppList(
			const ListWznmQAppList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQAppList(*(src.nodes[i]));
};

ListWznmQAppList& ListWznmQAppList::operator=(
			const ListWznmQAppList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQAppList(*(src.nodes[i]));

	return *this;
};

ListWznmQAppList::~ListWznmQAppList() {
	clear();
};

void ListWznmQAppList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQAppList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQAppList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQAppList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQAppList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQAppList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQAppList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

