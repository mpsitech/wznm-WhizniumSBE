/**
	* \file WznmQVerList.cpp
	* API code for table TblWznmQVerList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVerList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVerList
 ******************************************************************************/

WznmQVerList::WznmQVerList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string stubPrjRefWznmMProject
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const string stubBvrRefWznmMVersion
			, const string stubRefWznmMLocale
			, const string srefIxVState
			, const string titIxVState
			, const string srefsIxWDbmstype
			, const string titsIxWDbmstype
		) :
			jnum(jnum)
			, stubGrp(stubGrp)
			, stubOwn(stubOwn)
			, stubPrjRefWznmMProject(stubPrjRefWznmMProject)
			, Major(Major)
			, Minor(Minor)
			, Sub(Sub)
			, stubBvrRefWznmMVersion(stubBvrRefWznmMVersion)
			, stubRefWznmMLocale(stubRefWznmMLocale)
			, srefIxVState(srefIxVState)
			, titIxVState(titIxVState)
			, srefsIxWDbmstype(srefsIxWDbmstype)
			, titsIxWDbmstype(titsIxWDbmstype)
		{
};

bool WznmQVerList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVerList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "stubPrjRefWznmMProject", "prj", stubPrjRefWznmMProject);
		extractUsmallintUclc(docctx, basexpath, "Major", "maj", Major);
		extractUsmallintUclc(docctx, basexpath, "Minor", "min", Minor);
		extractUsmallintUclc(docctx, basexpath, "Sub", "sub", Sub);
		extractStringUclc(docctx, basexpath, "stubBvrRefWznmMVersion", "bvr", stubBvrRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "stubRefWznmMLocale", "loc", stubRefWznmMLocale);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "srefsIxWDbmstype", "dty", srefsIxWDbmstype);
		extractStringUclc(docctx, basexpath, "titsIxWDbmstype", "dty2", titsIxWDbmstype);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVerList
 ******************************************************************************/

ListWznmQVerList::ListWznmQVerList() {
};

ListWznmQVerList::ListWznmQVerList(
			const ListWznmQVerList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVerList(*(src.nodes[i]));
};

ListWznmQVerList& ListWznmQVerList::operator=(
			const ListWznmQVerList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVerList(*(src.nodes[i]));

	return *this;
};

ListWznmQVerList::~ListWznmQVerList() {
	clear();
};

void ListWznmQVerList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVerList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVerList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVerList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVerList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVerList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVerList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
