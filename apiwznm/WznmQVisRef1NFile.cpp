/**
	* \file WznmQVisRef1NFile.cpp
	* API code for table TblWznmQVisRef1NFile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 29 Dec 2024
  */
// IP header --- ABOVE

#include "WznmQVisRef1NFile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVisRef1NFile
 ******************************************************************************/

WznmQVisRef1NFile::WznmQVisRef1NFile(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQVisRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVisRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVisRef1NFile
 ******************************************************************************/

ListWznmQVisRef1NFile::ListWznmQVisRef1NFile() {
};

ListWznmQVisRef1NFile::ListWznmQVisRef1NFile(
			const ListWznmQVisRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisRef1NFile(*(src.nodes[i]));
};

ListWznmQVisRef1NFile& ListWznmQVisRef1NFile::operator=(
			const ListWznmQVisRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisRef1NFile(*(src.nodes[i]));

	return *this;
};

ListWznmQVisRef1NFile::~ListWznmQVisRef1NFile() {
	clear();
};

void ListWznmQVisRef1NFile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVisRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVisRef1NFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVisRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVisRef1NFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVisRef1NFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVisRef1NFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
