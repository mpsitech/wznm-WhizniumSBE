/**
	* \file WznmQIelList.cpp
	* API code for table TblWznmQIelList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQIelList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQIelList
 ******************************************************************************/

WznmQIelList::WznmQIelList(
			const uint jnum
			, const string sref
			, const string Short
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubImeRefWznmMImpexp
			, const string stubRefWznmMTablecol
			, const string srefIxVConvtype
			, const string titIxVConvtype
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Short = Short;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubImeRefWznmMImpexp = stubImeRefWznmMImpexp;
	this->stubRefWznmMTablecol = stubRefWznmMTablecol;
	this->srefIxVConvtype = srefIxVConvtype;
	this->titIxVConvtype = titIxVConvtype;
};

bool WznmQIelList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQIelList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubImeRefWznmMImpexp", "ime", stubImeRefWznmMImpexp);
		extractStringUclc(docctx, basexpath, "stubRefWznmMTablecol", "tco", stubRefWznmMTablecol);
		extractStringUclc(docctx, basexpath, "srefIxVConvtype", "cty", srefIxVConvtype);
		extractStringUclc(docctx, basexpath, "titIxVConvtype", "cty2", titIxVConvtype);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQIelList
 ******************************************************************************/

ListWznmQIelList::ListWznmQIelList() {
};

ListWznmQIelList::ListWznmQIelList(
			const ListWznmQIelList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIelList(*(src.nodes[i]));
};

ListWznmQIelList& ListWznmQIelList::operator=(
			const ListWznmQIelList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIelList(*(src.nodes[i]));

	return *this;
};

ListWznmQIelList::~ListWznmQIelList() {
	clear();
};

void ListWznmQIelList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQIelList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQIelList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQIelList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQIelList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQIelList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQIelList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

