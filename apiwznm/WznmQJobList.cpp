/**
	* \file WznmQJobList.cpp
	* API code for table TblWznmQJobList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQJobList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQJobList
 ******************************************************************************/

WznmQJobList::WznmQJobList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefWznmMVersion
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string yesnoGlobal
			, const string yesnoClisrv
			, const string yesnoShrdat
		) :
			jnum(jnum)
			, sref(sref)
			, srefIxVBasetype(srefIxVBasetype)
			, titIxVBasetype(titIxVBasetype)
			, stubRefWznmMVersion(stubRefWznmMVersion)
			, srefRefIxVTbl(srefRefIxVTbl)
			, titRefIxVTbl(titRefIxVTbl)
			, stubRefUref(stubRefUref)
			, yesnoGlobal(yesnoGlobal)
			, yesnoClisrv(yesnoClisrv)
			, yesnoShrdat(yesnoShrdat)
		{
};

bool WznmQJobList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQJobList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "yesnoGlobal", "gbl", yesnoGlobal);
		extractStringUclc(docctx, basexpath, "yesnoClisrv", "cls", yesnoClisrv);
		extractStringUclc(docctx, basexpath, "yesnoShrdat", "shd", yesnoShrdat);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQJobList
 ******************************************************************************/

ListWznmQJobList::ListWznmQJobList() {
};

ListWznmQJobList::ListWznmQJobList(
			const ListWznmQJobList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobList(*(src.nodes[i]));
};

ListWznmQJobList& ListWznmQJobList::operator=(
			const ListWznmQJobList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobList(*(src.nodes[i]));

	return *this;
};

ListWznmQJobList::~ListWznmQJobList() {
	clear();
};

void ListWznmQJobList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQJobList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQJobList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQJobList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQJobList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQJobList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQJobList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
