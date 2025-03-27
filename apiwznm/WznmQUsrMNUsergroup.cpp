/**
	* \file WznmQUsrMNUsergroup.cpp
	* API code for table TblWznmQUsrMNUsergroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQUsrMNUsergroup.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQUsrMNUsergroup
 ******************************************************************************/

WznmQUsrMNUsergroup::WznmQUsrMNUsergroup(
			const uint jnum
			, const string stubMref
			, const string srefIxWznmVUserlevel
			, const string titIxWznmVUserlevel
		) :
			jnum(jnum)
			, stubMref(stubMref)
			, srefIxWznmVUserlevel(srefIxWznmVUserlevel)
			, titIxWznmVUserlevel(titIxWznmVUserlevel)
		{
};

bool WznmQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxWznmVUserlevel", "ulv", srefIxWznmVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxWznmVUserlevel", "ulv2", titIxWznmVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQUsrMNUsergroup
 ******************************************************************************/

ListWznmQUsrMNUsergroup::ListWznmQUsrMNUsergroup() {
};

ListWznmQUsrMNUsergroup::ListWznmQUsrMNUsergroup(
			const ListWznmQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsrMNUsergroup(*(src.nodes[i]));
};

ListWznmQUsrMNUsergroup& ListWznmQUsrMNUsergroup::operator=(
			const ListWznmQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsrMNUsergroup(*(src.nodes[i]));

	return *this;
};

ListWznmQUsrMNUsergroup::~ListWznmQUsrMNUsergroup() {
	clear();
};

void ListWznmQUsrMNUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQUsrMNUsergroup* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQUsrMNUsergroup", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQUsrMNUsergroup(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQUsrMNUsergroup[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
