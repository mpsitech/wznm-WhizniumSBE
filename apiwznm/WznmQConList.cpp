/**
	* \file WznmQConList.cpp
	* API code for table TblWznmQConList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQConList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQConList
 ******************************************************************************/

WznmQConList::WznmQConList(
			const uint jnum
			, const string sref
			, const string Title
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const string stubHkUref
			, const string srefHkIxVSection
			, const string titHkIxVSection
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string stubSupRefWznmMControl
			, const string srefIxVSubtype
			, const string titIxVSubtype
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->stubHkUref = stubHkUref;
	this->srefHkIxVSection = srefHkIxVSection;
	this->titHkIxVSection = titHkIxVSection;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
	this->stubSupRefWznmMControl = stubSupRefWznmMControl;
	this->srefIxVSubtype = srefIxVSubtype;
	this->titIxVSubtype = titIxVSubtype;
};

bool WznmQConList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQConList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "srefHkIxVTbl", "hkt", srefHkIxVTbl);
		extractStringUclc(docctx, basexpath, "titHkIxVTbl", "hkt2", titHkIxVTbl);
		extractStringUclc(docctx, basexpath, "stubHkUref", "hku", stubHkUref);
		extractStringUclc(docctx, basexpath, "srefHkIxVSection", "sct", srefHkIxVSection);
		extractStringUclc(docctx, basexpath, "titHkIxVSection", "sct2", titHkIxVSection);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "stubSupRefWznmMControl", "sup", stubSupRefWznmMControl);
		extractStringUclc(docctx, basexpath, "srefIxVSubtype", "sty", srefIxVSubtype);
		extractStringUclc(docctx, basexpath, "titIxVSubtype", "sty2", titIxVSubtype);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQConList
 ******************************************************************************/

ListWznmQConList::ListWznmQConList() {
};

ListWznmQConList::ListWznmQConList(
			const ListWznmQConList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQConList(*(src.nodes[i]));
};

ListWznmQConList& ListWznmQConList::operator=(
			const ListWznmQConList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQConList(*(src.nodes[i]));

	return *this;
};

ListWznmQConList::~ListWznmQConList() {
	clear();
};

void ListWznmQConList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQConList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQConList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQConList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQConList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQConList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQConList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

