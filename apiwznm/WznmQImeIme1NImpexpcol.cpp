/**
	* \file WznmQImeIme1NImpexpcol.cpp
	* API code for table TblWznmQImeIme1NImpexpcol (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQImeIme1NImpexpcol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQImeIme1NImpexpcol
 ******************************************************************************/

WznmQImeIme1NImpexpcol::WznmQImeIme1NImpexpcol(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQImeIme1NImpexpcol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQImeIme1NImpexpcol");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQImeIme1NImpexpcol
 ******************************************************************************/

ListWznmQImeIme1NImpexpcol::ListWznmQImeIme1NImpexpcol() {
};

ListWznmQImeIme1NImpexpcol::ListWznmQImeIme1NImpexpcol(
			const ListWznmQImeIme1NImpexpcol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeIme1NImpexpcol(*(src.nodes[i]));
};

ListWznmQImeIme1NImpexpcol& ListWznmQImeIme1NImpexpcol::operator=(
			const ListWznmQImeIme1NImpexpcol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeIme1NImpexpcol(*(src.nodes[i]));

	return *this;
};

ListWznmQImeIme1NImpexpcol::~ListWznmQImeIme1NImpexpcol() {
	clear();
};

void ListWznmQImeIme1NImpexpcol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQImeIme1NImpexpcol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQImeIme1NImpexpcol* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQImeIme1NImpexpcol");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQImeIme1NImpexpcol", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQImeIme1NImpexpcol(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQImeIme1NImpexpcol[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

