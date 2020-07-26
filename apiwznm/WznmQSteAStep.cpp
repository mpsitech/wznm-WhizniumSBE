/**
	* \file WznmQSteAStep.cpp
	* API code for table TblWznmQSteAStep (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQSteAStep.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSteAStep
 ******************************************************************************/

WznmQSteAStep::WznmQSteAStep(
			const uint jnum
			, const string stubSnxRefWznmMState
			, const string srefIxVTrigger
			, const string titIxVTrigger
			, const string stubRefWznmMRtjob
			, const string stubRefWznmMVectoritem
			, const string xsref
			, const string stubRefWznmMRtdpch
			, const string srefsMask
			, const string Cond
			, const string yesnoCustcode
		) {
	this->jnum = jnum;
	this->stubSnxRefWznmMState = stubSnxRefWznmMState;
	this->srefIxVTrigger = srefIxVTrigger;
	this->titIxVTrigger = titIxVTrigger;
	this->stubRefWznmMRtjob = stubRefWznmMRtjob;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->xsref = xsref;
	this->stubRefWznmMRtdpch = stubRefWznmMRtdpch;
	this->srefsMask = srefsMask;
	this->Cond = Cond;
	this->yesnoCustcode = yesnoCustcode;
};

bool WznmQSteAStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSteAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubSnxRefWznmMState", "snx", stubSnxRefWznmMState);
		extractStringUclc(docctx, basexpath, "srefIxVTrigger", "trg", srefIxVTrigger);
		extractStringUclc(docctx, basexpath, "titIxVTrigger", "trg2", titIxVTrigger);
		extractStringUclc(docctx, basexpath, "stubRefWznmMRtjob", "rtj", stubRefWznmMRtjob);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVectoritem", "vit", stubRefWznmMVectoritem);
		extractStringUclc(docctx, basexpath, "xsref", "xsr", xsref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMRtdpch", "rtd", stubRefWznmMRtdpch);
		extractStringUclc(docctx, basexpath, "srefsMask", "msk", srefsMask);
		extractStringUclc(docctx, basexpath, "Cond", "cnd", Cond);
		extractStringUclc(docctx, basexpath, "yesnoCustcode", "ccd", yesnoCustcode);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSteAStep
 ******************************************************************************/

ListWznmQSteAStep::ListWznmQSteAStep() {
};

ListWznmQSteAStep::ListWznmQSteAStep(
			const ListWznmQSteAStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteAStep(*(src.nodes[i]));
};

ListWznmQSteAStep& ListWznmQSteAStep::operator=(
			const ListWznmQSteAStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteAStep(*(src.nodes[i]));

	return *this;
};

ListWznmQSteAStep::~ListWznmQSteAStep() {
	clear();
};

void ListWznmQSteAStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSteAStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSteAStep* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSteAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSteAStep", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSteAStep(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSteAStep[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

