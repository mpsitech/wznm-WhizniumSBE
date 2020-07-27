/**
	* \file WznmQPrsMNProject.cpp
	* API code for table TblWznmQPrsMNProject (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQPrsMNProject.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPrsMNProject
 ******************************************************************************/

WznmQPrsMNProject::WznmQPrsMNProject(
			const uint jnum
			, const string stubMref
			, const string ftmX1Startd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->ftmX1Startd = ftmX1Startd;
	this->ftmX1Stopd = ftmX1Stopd;
	this->srefKFunction = srefKFunction;
	this->titSrefKFunction = titSrefKFunction;
};

bool WznmQPrsMNProject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQPrsMNProject");
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
 class ListWznmQPrsMNProject
 ******************************************************************************/

ListWznmQPrsMNProject::ListWznmQPrsMNProject() {
};

ListWznmQPrsMNProject::ListWznmQPrsMNProject(
			const ListWznmQPrsMNProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrsMNProject(*(src.nodes[i]));
};

ListWznmQPrsMNProject& ListWznmQPrsMNProject::operator=(
			const ListWznmQPrsMNProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrsMNProject(*(src.nodes[i]));

	return *this;
};

ListWznmQPrsMNProject::~ListWznmQPrsMNProject() {
	clear();
};

void ListWznmQPrsMNProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQPrsMNProject::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQPrsMNProject* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQPrsMNProject");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQPrsMNProject", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQPrsMNProject(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQPrsMNProject[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
