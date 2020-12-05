/**
	* \file WznmQJobSupMNJob.cpp
	* API code for table TblWznmQJobSupMNJob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQJobSupMNJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQJobSupMNJob
 ******************************************************************************/

WznmQJobSupMNJob::WznmQJobSupMNJob(
			const uint jnum
			, const string stubMref
			, const string Short
			, const string yesnoMulti
			, const string srefIxVConstract
			, const string titIxVConstract
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->Short = Short;
	this->yesnoMulti = yesnoMulti;
	this->srefIxVConstract = srefIxVConstract;
	this->titIxVConstract = titIxVConstract;
};

bool WznmQJobSupMNJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQJobSupMNJob");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "yesnoMulti", "mlt", yesnoMulti);
		extractStringUclc(docctx, basexpath, "srefIxVConstract", "csa", srefIxVConstract);
		extractStringUclc(docctx, basexpath, "titIxVConstract", "csa2", titIxVConstract);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQJobSupMNJob
 ******************************************************************************/

ListWznmQJobSupMNJob::ListWznmQJobSupMNJob() {
};

ListWznmQJobSupMNJob::ListWznmQJobSupMNJob(
			const ListWznmQJobSupMNJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobSupMNJob(*(src.nodes[i]));
};

ListWznmQJobSupMNJob& ListWznmQJobSupMNJob::operator=(
			const ListWznmQJobSupMNJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobSupMNJob(*(src.nodes[i]));

	return *this;
};

ListWznmQJobSupMNJob::~ListWznmQJobSupMNJob() {
	clear();
};

void ListWznmQJobSupMNJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQJobSupMNJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQJobSupMNJob* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQJobSupMNJob");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQJobSupMNJob", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQJobSupMNJob(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQJobSupMNJob[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

