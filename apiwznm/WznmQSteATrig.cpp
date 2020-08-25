/**
	* \file WznmQSteATrig.cpp
	* API code for table TblWznmQSteATrig (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQSteATrig.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSteATrig
 ******************************************************************************/

WznmQSteATrig::WznmQSteATrig(
			const uint jnum
			, const string sref
			, const string srefIxVType
			, const string titIxVType
			, const string stubRefWznmMEvent
			, const string stubRefWznmMRtjob
			, const string stubRefWznmMVectoritem
			, const string xsref
			, const string stubRefWznmMRtdpch
			, const string srefsMask
			, const string Cond
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVType = srefIxVType;
	this->titIxVType = titIxVType;
	this->stubRefWznmMEvent = stubRefWznmMEvent;
	this->stubRefWznmMRtjob = stubRefWznmMRtjob;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	this->xsref = xsref;
	this->stubRefWznmMRtdpch = stubRefWznmMRtdpch;
	this->srefsMask = srefsMask;
	this->Cond = Cond;
};

bool WznmQSteATrig::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSteATrig");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVType", "typ", srefIxVType);
		extractStringUclc(docctx, basexpath, "titIxVType", "typ2", titIxVType);
		extractStringUclc(docctx, basexpath, "stubRefWznmMEvent", "evt", stubRefWznmMEvent);
		extractStringUclc(docctx, basexpath, "stubRefWznmMRtjob", "rtj", stubRefWznmMRtjob);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVectoritem", "vit", stubRefWznmMVectoritem);
		extractStringUclc(docctx, basexpath, "xsref", "xsr", xsref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMRtdpch", "rtd", stubRefWznmMRtdpch);
		extractStringUclc(docctx, basexpath, "srefsMask", "msk", srefsMask);
		extractStringUclc(docctx, basexpath, "Cond", "cnd", Cond);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSteATrig
 ******************************************************************************/

ListWznmQSteATrig::ListWznmQSteATrig() {
};

ListWznmQSteATrig::ListWznmQSteATrig(
			const ListWznmQSteATrig& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteATrig(*(src.nodes[i]));
};

ListWznmQSteATrig& ListWznmQSteATrig::operator=(
			const ListWznmQSteATrig& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteATrig(*(src.nodes[i]));

	return *this;
};

ListWznmQSteATrig::~ListWznmQSteATrig() {
	clear();
};

void ListWznmQSteATrig::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSteATrig::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSteATrig* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSteATrig");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSteATrig", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSteATrig(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSteATrig[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

