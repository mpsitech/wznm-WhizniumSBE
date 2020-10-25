/**
	* \file WznmQUsgMNUser.cpp
	* API code for table TblWznmQUsgMNUser (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQUsgMNUser.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQUsgMNUser
 ******************************************************************************/

WznmQUsgMNUser::WznmQUsgMNUser(
			const uint jnum
			, const string stubMref
			, const string srefIxWznmVUserlevel
			, const string titIxWznmVUserlevel
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxWznmVUserlevel = srefIxWznmVUserlevel;
	this->titIxWznmVUserlevel = titIxWznmVUserlevel;
};

bool WznmQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQUsgMNUser");
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
 class ListWznmQUsgMNUser
 ******************************************************************************/

ListWznmQUsgMNUser::ListWznmQUsgMNUser() {
};

ListWznmQUsgMNUser::ListWznmQUsgMNUser(
			const ListWznmQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsgMNUser(*(src.nodes[i]));
};

ListWznmQUsgMNUser& ListWznmQUsgMNUser::operator=(
			const ListWznmQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsgMNUser(*(src.nodes[i]));

	return *this;
};

ListWznmQUsgMNUser::~ListWznmQUsgMNUser() {
	clear();
};

void ListWznmQUsgMNUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQUsgMNUser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQUsgMNUser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQUsgMNUser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQUsgMNUser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQUsgMNUser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

