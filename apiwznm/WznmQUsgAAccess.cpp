/**
	* \file WznmQUsgAAccess.cpp
	* API code for table TblWznmQUsgAAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQUsgAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQUsgAAccess
 ******************************************************************************/

WznmQUsgAAccess::WznmQUsgAAccess(
			const uint jnum
			, const string srefX1IxWznmVFeatgroup
			, const string titX1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const string srefsIxWznmWAccess
			, const string titsIxWznmWAccess
		) :
			jnum(jnum)
			, srefX1IxWznmVFeatgroup(srefX1IxWznmVFeatgroup)
			, titX1IxWznmVFeatgroup(titX1IxWznmVFeatgroup)
			, x2FeaSrefUix(x2FeaSrefUix)
			, srefsIxWznmWAccess(srefsIxWznmWAccess)
			, titsIxWznmWAccess(titsIxWznmWAccess)
		{
};

bool WznmQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxWznmVFeatgroup", "feg", srefX1IxWznmVFeatgroup);
		extractStringUclc(docctx, basexpath, "titX1IxWznmVFeatgroup", "feg2", titX1IxWznmVFeatgroup);
		extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix);
		extractStringUclc(docctx, basexpath, "srefsIxWznmWAccess", "acc", srefsIxWznmWAccess);
		extractStringUclc(docctx, basexpath, "titsIxWznmWAccess", "acc2", titsIxWznmWAccess);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQUsgAAccess
 ******************************************************************************/

ListWznmQUsgAAccess::ListWznmQUsgAAccess() {
};

ListWznmQUsgAAccess::ListWznmQUsgAAccess(
			const ListWznmQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsgAAccess(*(src.nodes[i]));
};

ListWznmQUsgAAccess& ListWznmQUsgAAccess::operator=(
			const ListWznmQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsgAAccess(*(src.nodes[i]));

	return *this;
};

ListWznmQUsgAAccess::~ListWznmQUsgAAccess() {
	clear();
};

void ListWznmQUsgAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQUsgAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQUsgAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQUsgAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQUsgAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
