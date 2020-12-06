/**
	* \file WznmQSteAAction.cpp
	* API code for table TblWznmQSteAAction (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSteAAction.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSteAAction
 ******************************************************************************/

WznmQSteAAction::WznmQSteAAction(
			const uint jnum
			, const string srefIxVSection
			, const string titIxVSection
			, const string srefIxVType
			, const string titIxVType
			, const string stubRefWznmMRtjob
			, const string stubRefWznmMVector
			, const string stubRefWznmMVectoritem
			, const string stubSnxRefWznmMState
			, const string stubRefWznmMSequence
			, const string tr1SrefATrig
			, const string Ip1
			, const string tr2SrefATrig
			, const string Ip2
			, const string tr3SrefATrig
			, const string Ip3
			, const string tr4SrefATrig
			, const string Ip4
		) {
	this->jnum = jnum;
	this->srefIxVSection = srefIxVSection;
	this->titIxVSection = titIxVSection;
	this->srefIxVType = srefIxVType;
	this->titIxVType = titIxVType;
	this->stubRefWznmMRtjob = stubRefWznmMRtjob;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->stubSnxRefWznmMState = stubSnxRefWznmMState;
	this->stubRefWznmMSequence = stubRefWznmMSequence;
	this->tr1SrefATrig = tr1SrefATrig;
	this->Ip1 = Ip1;
	this->tr2SrefATrig = tr2SrefATrig;
	this->Ip2 = Ip2;
	this->tr3SrefATrig = tr3SrefATrig;
	this->Ip3 = Ip3;
	this->tr4SrefATrig = tr4SrefATrig;
	this->Ip4 = Ip4;
};

bool WznmQSteAAction::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSteAAction");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefIxVSection", "sct", srefIxVSection);
		extractStringUclc(docctx, basexpath, "titIxVSection", "sct2", titIxVSection);
		extractStringUclc(docctx, basexpath, "srefIxVType", "typ", srefIxVType);
		extractStringUclc(docctx, basexpath, "titIxVType", "typ2", titIxVType);
		extractStringUclc(docctx, basexpath, "stubRefWznmMRtjob", "trj", stubRefWznmMRtjob);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVector", "vec", stubRefWznmMVector);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVectoritem", "vit", stubRefWznmMVectoritem);
		extractStringUclc(docctx, basexpath, "stubSnxRefWznmMState", "snx", stubSnxRefWznmMState);
		extractStringUclc(docctx, basexpath, "stubRefWznmMSequence", "seq", stubRefWznmMSequence);
		extractStringUclc(docctx, basexpath, "tr1SrefATrig", "tr1", tr1SrefATrig);
		extractStringUclc(docctx, basexpath, "Ip1", "ip1", Ip1);
		extractStringUclc(docctx, basexpath, "tr2SrefATrig", "tr2", tr2SrefATrig);
		extractStringUclc(docctx, basexpath, "Ip2", "ip2", Ip2);
		extractStringUclc(docctx, basexpath, "tr3SrefATrig", "tr3", tr3SrefATrig);
		extractStringUclc(docctx, basexpath, "Ip3", "ip3", Ip3);
		extractStringUclc(docctx, basexpath, "tr4SrefATrig", "tr4", tr4SrefATrig);
		extractStringUclc(docctx, basexpath, "Ip4", "ip4", Ip4);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSteAAction
 ******************************************************************************/

ListWznmQSteAAction::ListWznmQSteAAction() {
};

ListWznmQSteAAction::ListWznmQSteAAction(
			const ListWznmQSteAAction& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteAAction(*(src.nodes[i]));
};

ListWznmQSteAAction& ListWznmQSteAAction::operator=(
			const ListWznmQSteAAction& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteAAction(*(src.nodes[i]));

	return *this;
};

ListWznmQSteAAction::~ListWznmQSteAAction() {
	clear();
};

void ListWznmQSteAAction::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSteAAction::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSteAAction* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSteAAction");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSteAAction", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSteAAction(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSteAAction[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
