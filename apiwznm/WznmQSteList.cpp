/**
	* \file WznmQSteList.cpp
	* API code for table TblWznmQSteList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQSteList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSteList
 ******************************************************************************/

WznmQSteList::WznmQSteList(
			const uint jnum
			, const string sref
			, const string stubSeqRefWznmMSequence
			, const string srefEacIxVAction
			, const string titEacIxVAction
			, const string srefLacIxVAction
			, const string titLacIxVAction
			, const string yesnoCuststep
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubSeqRefWznmMSequence = stubSeqRefWznmMSequence;
	this->srefEacIxVAction = srefEacIxVAction;
	this->titEacIxVAction = titEacIxVAction;
	this->srefLacIxVAction = srefLacIxVAction;
	this->titLacIxVAction = titLacIxVAction;
	this->yesnoCuststep = yesnoCuststep;
};

bool WznmQSteList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSteList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubSeqRefWznmMSequence", "seq", stubSeqRefWznmMSequence);
		extractStringUclc(docctx, basexpath, "srefEacIxVAction", "eac", srefEacIxVAction);
		extractStringUclc(docctx, basexpath, "titEacIxVAction", "eac2", titEacIxVAction);
		extractStringUclc(docctx, basexpath, "srefLacIxVAction", "lac", srefLacIxVAction);
		extractStringUclc(docctx, basexpath, "titLacIxVAction", "lac2", titLacIxVAction);
		extractStringUclc(docctx, basexpath, "yesnoCuststep", "cst", yesnoCuststep);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSteList
 ******************************************************************************/

ListWznmQSteList::ListWznmQSteList() {
};

ListWznmQSteList::ListWznmQSteList(
			const ListWznmQSteList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteList(*(src.nodes[i]));
};

ListWznmQSteList& ListWznmQSteList::operator=(
			const ListWznmQSteList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteList(*(src.nodes[i]));

	return *this;
};

ListWznmQSteList::~ListWznmQSteList() {
	clear();
};

void ListWznmQSteList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSteList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSteList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSteList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSteList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSteList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSteList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

