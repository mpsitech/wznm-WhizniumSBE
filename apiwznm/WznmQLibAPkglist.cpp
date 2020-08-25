/**
	* \file WznmQLibAPkglist.cpp
	* API code for table TblWznmQLibAPkglist (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQLibAPkglist.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQLibAPkglist
 ******************************************************************************/

WznmQLibAPkglist::WznmQLibAPkglist(
			const uint jnum
			, const string srefX1RefIxVTbl
			, const string titX1RefIxVTbl
			, const string stubX1RefUref
			, const string Pkglist
		) {
	this->jnum = jnum;
	this->srefX1RefIxVTbl = srefX1RefIxVTbl;
	this->titX1RefIxVTbl = titX1RefIxVTbl;
	this->stubX1RefUref = stubX1RefUref;
	this->Pkglist = Pkglist;
};

bool WznmQLibAPkglist::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQLibAPkglist");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1RefIxVTbl", "ret", srefX1RefIxVTbl);
		extractStringUclc(docctx, basexpath, "titX1RefIxVTbl", "ret2", titX1RefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubX1RefUref", "reu", stubX1RefUref);
		extractStringUclc(docctx, basexpath, "Pkglist", "pkl", Pkglist);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQLibAPkglist
 ******************************************************************************/

ListWznmQLibAPkglist::ListWznmQLibAPkglist() {
};

ListWznmQLibAPkglist::ListWznmQLibAPkglist(
			const ListWznmQLibAPkglist& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibAPkglist(*(src.nodes[i]));
};

ListWznmQLibAPkglist& ListWznmQLibAPkglist::operator=(
			const ListWznmQLibAPkglist& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibAPkglist(*(src.nodes[i]));

	return *this;
};

ListWznmQLibAPkglist::~ListWznmQLibAPkglist() {
	clear();
};

void ListWznmQLibAPkglist::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQLibAPkglist::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQLibAPkglist* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQLibAPkglist");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQLibAPkglist", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQLibAPkglist(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQLibAPkglist[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

