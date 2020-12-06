/**
	* \file WznmQOpkMNComponent.cpp
	* API code for table TblWznmQOpkMNComponent (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQOpkMNComponent.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpkMNComponent
 ******************************************************************************/

WznmQOpkMNComponent::WznmQOpkMNComponent(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool WznmQOpkMNComponent::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQOpkMNComponent");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQOpkMNComponent
 ******************************************************************************/

ListWznmQOpkMNComponent::ListWznmQOpkMNComponent() {
};

ListWznmQOpkMNComponent::ListWznmQOpkMNComponent(
			const ListWznmQOpkMNComponent& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkMNComponent(*(src.nodes[i]));
};

ListWznmQOpkMNComponent& ListWznmQOpkMNComponent::operator=(
			const ListWznmQOpkMNComponent& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkMNComponent(*(src.nodes[i]));

	return *this;
};

ListWznmQOpkMNComponent::~ListWznmQOpkMNComponent() {
	clear();
};

void ListWznmQOpkMNComponent::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQOpkMNComponent::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQOpkMNComponent* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQOpkMNComponent");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQOpkMNComponent", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQOpkMNComponent(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQOpkMNComponent[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
