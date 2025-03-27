/**
	* \file WznmQPrjMNPerson.cpp
	* API code for table TblWznmQPrjMNPerson (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPrjMNPerson.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPrjMNPerson
 ******************************************************************************/

WznmQPrjMNPerson::WznmQPrjMNPerson(
			const uint jnum
			, const string stubMref
			, const string ftmX1Startd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) :
			jnum(jnum)
			, stubMref(stubMref)
			, ftmX1Startd(ftmX1Startd)
			, ftmX1Stopd(ftmX1Stopd)
			, srefKFunction(srefKFunction)
			, titSrefKFunction(titSrefKFunction)
		{
};

bool WznmQPrjMNPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQPrjMNPerson");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "ftmX1Startd", "sta", ftmX1Startd);
		extractStringUclc(docctx, basexpath, "ftmX1Stopd", "sto", ftmX1Stopd);
		extractStringUclc(docctx, basexpath, "srefKFunction", "fct", srefKFunction);
		extractStringUclc(docctx, basexpath, "titSrefKFunction", "fct2", titSrefKFunction);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQPrjMNPerson
 ******************************************************************************/

ListWznmQPrjMNPerson::ListWznmQPrjMNPerson() {
};

ListWznmQPrjMNPerson::ListWznmQPrjMNPerson(
			const ListWznmQPrjMNPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrjMNPerson(*(src.nodes[i]));
};

ListWznmQPrjMNPerson& ListWznmQPrjMNPerson::operator=(
			const ListWznmQPrjMNPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrjMNPerson(*(src.nodes[i]));

	return *this;
};

ListWznmQPrjMNPerson::~ListWznmQPrjMNPerson() {
	clear();
};

void ListWznmQPrjMNPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQPrjMNPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQPrjMNPerson* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQPrjMNPerson");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQPrjMNPerson", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQPrjMNPerson(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQPrjMNPerson[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
