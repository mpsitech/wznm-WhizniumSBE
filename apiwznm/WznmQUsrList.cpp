/**
	* \file WznmQUsrList.cpp
	* API code for table TblWznmQUsrList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQUsrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQUsrList
 ******************************************************************************/

WznmQUsrList::WznmQUsrList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string stubRefWznmMPerson
			, const string sref
			, const string stubRefWznmMUsergroup
			, const string srefIxVState
			, const string titIxVState
			, const string srefIxWznmVLocale
			, const string titIxWznmVLocale
			, const string srefIxWznmVUserlevel
			, const string titIxWznmVUserlevel
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->stubRefWznmMPerson = stubRefWznmMPerson;
	this->sref = sref;
	this->stubRefWznmMUsergroup = stubRefWznmMUsergroup;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->srefIxWznmVLocale = srefIxWznmVLocale;
	this->titIxWznmVLocale = titIxWznmVLocale;
	this->srefIxWznmVUserlevel = srefIxWznmVUserlevel;
	this->titIxWznmVUserlevel = titIxWznmVUserlevel;
};

bool WznmQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "stubRefWznmMPerson", "prs", stubRefWznmMPerson);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMUsergroup", "usg", stubRefWznmMUsergroup);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "srefIxWznmVLocale", "lcl", srefIxWznmVLocale);
		extractStringUclc(docctx, basexpath, "titIxWznmVLocale", "lcl2", titIxWznmVLocale);
		extractStringUclc(docctx, basexpath, "srefIxWznmVUserlevel", "ulv", srefIxWznmVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxWznmVUserlevel", "ulv2", titIxWznmVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQUsrList
 ******************************************************************************/

ListWznmQUsrList::ListWznmQUsrList() {
};

ListWznmQUsrList::ListWznmQUsrList(
			const ListWznmQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsrList(*(src.nodes[i]));
};

ListWznmQUsrList& ListWznmQUsrList::operator=(
			const ListWznmQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsrList(*(src.nodes[i]));

	return *this;
};

ListWznmQUsrList::~ListWznmQUsrList() {
	clear();
};

void ListWznmQUsrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQUsrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQUsrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQUsrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQUsrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

