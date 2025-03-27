/**
	* \file WznmQVer1NImpexpcplx.cpp
	* API code for table TblWznmQVer1NImpexpcplx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVer1NImpexpcplx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVer1NImpexpcplx
 ******************************************************************************/

WznmQVer1NImpexpcplx::WznmQVer1NImpexpcplx(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQVer1NImpexpcplx::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVer1NImpexpcplx");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVer1NImpexpcplx
 ******************************************************************************/

ListWznmQVer1NImpexpcplx::ListWznmQVer1NImpexpcplx() {
};

ListWznmQVer1NImpexpcplx::ListWznmQVer1NImpexpcplx(
			const ListWznmQVer1NImpexpcplx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVer1NImpexpcplx(*(src.nodes[i]));
};

ListWznmQVer1NImpexpcplx& ListWznmQVer1NImpexpcplx::operator=(
			const ListWznmQVer1NImpexpcplx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVer1NImpexpcplx(*(src.nodes[i]));

	return *this;
};

ListWznmQVer1NImpexpcplx::~ListWznmQVer1NImpexpcplx() {
	clear();
};

void ListWznmQVer1NImpexpcplx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVer1NImpexpcplx::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVer1NImpexpcplx* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVer1NImpexpcplx");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVer1NImpexpcplx", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVer1NImpexpcplx(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVer1NImpexpcplx[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
