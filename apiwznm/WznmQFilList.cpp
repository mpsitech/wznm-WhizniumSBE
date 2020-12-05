/**
	* \file WznmQFilList.cpp
	* API code for table TblWznmQFilList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQFilList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQFilList
 ******************************************************************************/

WznmQFilList::WznmQFilList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string Filename
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const uint Size
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->Filename = Filename;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
	this->osrefKContent = osrefKContent;
	this->titOsrefKContent = titOsrefKContent;
	this->srefKMimetype = srefKMimetype;
	this->titSrefKMimetype = titSrefKMimetype;
	this->Size = Size;
};

bool WznmQFilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQFilList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent);
		extractStringUclc(docctx, basexpath, "titOsrefKContent", "cnt2", titOsrefKContent);
		extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype);
		extractStringUclc(docctx, basexpath, "titSrefKMimetype", "mim2", titSrefKMimetype);
		extractUintUclc(docctx, basexpath, "Size", "siz", Size);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQFilList
 ******************************************************************************/

ListWznmQFilList::ListWznmQFilList() {
};

ListWznmQFilList::ListWznmQFilList(
			const ListWznmQFilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQFilList(*(src.nodes[i]));
};

ListWznmQFilList& ListWznmQFilList::operator=(
			const ListWznmQFilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQFilList(*(src.nodes[i]));

	return *this;
};

ListWznmQFilList::~ListWznmQFilList() {
	clear();
};

void ListWznmQFilList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQFilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQFilList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQFilList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQFilList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQFilList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQFilList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

