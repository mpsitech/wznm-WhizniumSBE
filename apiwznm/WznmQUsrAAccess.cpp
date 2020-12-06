/**
	* \file WznmQUsrAAccess.cpp
	* API code for table TblWznmQUsrAAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQUsrAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQUsrAAccess
 ******************************************************************************/

WznmQUsrAAccess::WznmQUsrAAccess(
			const uint jnum
			, const string srefX1IxWznmVFeatgroup
			, const string titX1IxWznmVFeatgroup
			, const string x2FeaSrefUix
			, const string srefsIxWznmWAccess
			, const string titsIxWznmWAccess
		) {
	this->jnum = jnum;
	this->srefX1IxWznmVFeatgroup = srefX1IxWznmVFeatgroup;
	this->titX1IxWznmVFeatgroup = titX1IxWznmVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->srefsIxWznmWAccess = srefsIxWznmWAccess;
	this->titsIxWznmWAccess = titsIxWznmWAccess;
};

bool WznmQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQUsrAAccess");
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
 class ListWznmQUsrAAccess
 ******************************************************************************/

ListWznmQUsrAAccess::ListWznmQUsrAAccess() {
};

ListWznmQUsrAAccess::ListWznmQUsrAAccess(
			const ListWznmQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsrAAccess(*(src.nodes[i]));
};

ListWznmQUsrAAccess& ListWznmQUsrAAccess::operator=(
			const ListWznmQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsrAAccess(*(src.nodes[i]));

	return *this;
};

ListWznmQUsrAAccess::~ListWznmQUsrAAccess() {
	clear();
};

void ListWznmQUsrAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQUsrAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQUsrAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQUsrAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQUsrAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
