/**
	* \file WznmQTblALoadfct.cpp
	* API code for table TblWznmQTblALoadfct (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblALoadfct.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblALoadfct
 ******************************************************************************/

WznmQTblALoadfct::WznmQTblALoadfct(
			const uint jnum
			, const string srefIxVLoadtype
			, const string titIxVLoadtype
			, const string Fctname
			, const string ldSrefWznmMTablecol
			, const string lbySrefsWznmMTablecol
			, const string ordSrefsWznmMTablecol
			, const string srefIxVLimtype
			, const string titIxVLimtype
		) :
			jnum(jnum)
			, srefIxVLoadtype(srefIxVLoadtype)
			, titIxVLoadtype(titIxVLoadtype)
			, Fctname(Fctname)
			, ldSrefWznmMTablecol(ldSrefWznmMTablecol)
			, lbySrefsWznmMTablecol(lbySrefsWznmMTablecol)
			, ordSrefsWznmMTablecol(ordSrefsWznmMTablecol)
			, srefIxVLimtype(srefIxVLimtype)
			, titIxVLimtype(titIxVLimtype)
		{
};

bool WznmQTblALoadfct::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblALoadfct");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefIxVLoadtype", "lot", srefIxVLoadtype);
		extractStringUclc(docctx, basexpath, "titIxVLoadtype", "lot2", titIxVLoadtype);
		extractStringUclc(docctx, basexpath, "Fctname", "fna", Fctname);
		extractStringUclc(docctx, basexpath, "ldSrefWznmMTablecol", "ldx", ldSrefWznmMTablecol);
		extractStringUclc(docctx, basexpath, "lbySrefsWznmMTablecol", "lby", lbySrefsWznmMTablecol);
		extractStringUclc(docctx, basexpath, "ordSrefsWznmMTablecol", "ord", ordSrefsWznmMTablecol);
		extractStringUclc(docctx, basexpath, "srefIxVLimtype", "lit", srefIxVLimtype);
		extractStringUclc(docctx, basexpath, "titIxVLimtype", "lit2", titIxVLimtype);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTblALoadfct
 ******************************************************************************/

ListWznmQTblALoadfct::ListWznmQTblALoadfct() {
};

ListWznmQTblALoadfct::ListWznmQTblALoadfct(
			const ListWznmQTblALoadfct& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblALoadfct(*(src.nodes[i]));
};

ListWznmQTblALoadfct& ListWznmQTblALoadfct::operator=(
			const ListWznmQTblALoadfct& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblALoadfct(*(src.nodes[i]));

	return *this;
};

ListWznmQTblALoadfct::~ListWznmQTblALoadfct() {
	clear();
};

void ListWznmQTblALoadfct::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblALoadfct::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblALoadfct* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblALoadfct");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblALoadfct", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblALoadfct(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblALoadfct[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
