/**
	* \file WznmQJobSubMNJob.cpp
	* API code for table TblWznmQJobSubMNJob (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQJobSubMNJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQJobSubMNJob
 ******************************************************************************/

WznmQJobSubMNJob::WznmQJobSubMNJob(
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

bool WznmQJobSubMNJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQJobSubMNJob");
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
 class ListWznmQJobSubMNJob
 ******************************************************************************/

ListWznmQJobSubMNJob::ListWznmQJobSubMNJob() {
};

ListWznmQJobSubMNJob::ListWznmQJobSubMNJob(
			const ListWznmQJobSubMNJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobSubMNJob(*(src.nodes[i]));
};

ListWznmQJobSubMNJob& ListWznmQJobSubMNJob::operator=(
			const ListWznmQJobSubMNJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQJobSubMNJob(*(src.nodes[i]));

	return *this;
};

ListWznmQJobSubMNJob::~ListWznmQJobSubMNJob() {
	clear();
};

void ListWznmQJobSubMNJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQJobSubMNJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQJobSubMNJob* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQJobSubMNJob");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQJobSubMNJob", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQJobSubMNJob(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQJobSubMNJob[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

