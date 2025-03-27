/**
	* \file WznmQCtpList.cpp
	* API code for table TblWznmQCtpList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQCtpList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCtpList
 ******************************************************************************/

WznmQCtpList::WznmQCtpList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubRefWznmMVersion
			, const string srefsIxWArtefact
			, const string titsIxWArtefact
		) :
			jnum(jnum)
			, sref(sref)
			, Title(Title)
			, stubRefWznmMVersion(stubRefWznmMVersion)
			, srefsIxWArtefact(srefsIxWArtefact)
			, titsIxWArtefact(titsIxWArtefact)
		{
};

bool WznmQCtpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "srefsIxWArtefact", "atf", srefsIxWArtefact);
		extractStringUclc(docctx, basexpath, "titsIxWArtefact", "atf2", titsIxWArtefact);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCtpList
 ******************************************************************************/

ListWznmQCtpList::ListWznmQCtpList() {
};

ListWznmQCtpList::ListWznmQCtpList(
			const ListWznmQCtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpList(*(src.nodes[i]));
};

ListWznmQCtpList& ListWznmQCtpList::operator=(
			const ListWznmQCtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpList(*(src.nodes[i]));

	return *this;
};

ListWznmQCtpList::~ListWznmQCtpList() {
	clear();
};

void ListWznmQCtpList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCtpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCtpList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCtpList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCtpList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCtpList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
