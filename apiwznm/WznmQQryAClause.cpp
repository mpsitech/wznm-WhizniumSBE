/**
	* \file WznmQQryAClause.cpp
	* API code for table TblWznmQQryAClause (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQryAClause.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryAClause
 ******************************************************************************/

WznmQQryAClause::WznmQQryAClause(
			const uint jnum
			, const string stubX1RefWznmMQuerymod
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string Clause
			, const string stubRefWznmMPreset
			, const string stubRefWznmMVector
			, const string stubRefWznmMVectoritem
		) :
			jnum(jnum)
			, stubX1RefWznmMQuerymod(stubX1RefWznmMQuerymod)
			, srefIxVBasetype(srefIxVBasetype)
			, titIxVBasetype(titIxVBasetype)
			, Clause(Clause)
			, stubRefWznmMPreset(stubRefWznmMPreset)
			, stubRefWznmMVector(stubRefWznmMVector)
			, stubRefWznmMVectoritem(stubRefWznmMVectoritem)
		{
};

bool WznmQQryAClause::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQQryAClause");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubX1RefWznmMQuerymod", "qmd", stubX1RefWznmMQuerymod);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "Clause", "cse", Clause);
		extractStringUclc(docctx, basexpath, "stubRefWznmMPreset", "pst", stubRefWznmMPreset);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVector", "vec", stubRefWznmMVector);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVectoritem", "vit", stubRefWznmMVectoritem);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQQryAClause
 ******************************************************************************/

ListWznmQQryAClause::ListWznmQQryAClause() {
};

ListWznmQQryAClause::ListWznmQQryAClause(
			const ListWznmQQryAClause& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryAClause(*(src.nodes[i]));
};

ListWznmQQryAClause& ListWznmQQryAClause::operator=(
			const ListWznmQQryAClause& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryAClause(*(src.nodes[i]));

	return *this;
};

ListWznmQQryAClause::~ListWznmQQryAClause() {
	clear();
};

void ListWznmQQryAClause::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQQryAClause::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQQryAClause* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQQryAClause");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQQryAClause", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQQryAClause(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQQryAClause[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
