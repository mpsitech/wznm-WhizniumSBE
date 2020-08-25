/**
	* \file WznmQCalList.cpp
	* API code for table TblWznmQCalList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQCalList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCalList
 ******************************************************************************/

WznmQCalList::WznmQCalList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefWznmMVersion
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string srefsInvIxWznmWArgtype
			, const string titsInvIxWznmWArgtype
			, const string srefsRetIxWznmWArgtype
			, const string titsRetIxWznmWArgtype
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
	this->srefsInvIxWznmWArgtype = srefsInvIxWznmWArgtype;
	this->titsInvIxWznmWArgtype = titsInvIxWznmWArgtype;
	this->srefsRetIxWznmWArgtype = srefsRetIxWznmWArgtype;
	this->titsRetIxWznmWArgtype = titsRetIxWznmWArgtype;
};

bool WznmQCalList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCalList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "srefsInvIxWznmWArgtype", "iat", srefsInvIxWznmWArgtype);
		extractStringUclc(docctx, basexpath, "titsInvIxWznmWArgtype", "iat2", titsInvIxWznmWArgtype);
		extractStringUclc(docctx, basexpath, "srefsRetIxWznmWArgtype", "rat", srefsRetIxWznmWArgtype);
		extractStringUclc(docctx, basexpath, "titsRetIxWznmWArgtype", "rat2", titsRetIxWznmWArgtype);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCalList
 ******************************************************************************/

ListWznmQCalList::ListWznmQCalList() {
};

ListWznmQCalList::ListWznmQCalList(
			const ListWznmQCalList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCalList(*(src.nodes[i]));
};

ListWznmQCalList& ListWznmQCalList::operator=(
			const ListWznmQCalList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCalList(*(src.nodes[i]));

	return *this;
};

ListWznmQCalList::~ListWznmQCalList() {
	clear();
};

void ListWznmQCalList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCalList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCalList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCalList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCalList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCalList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCalList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

