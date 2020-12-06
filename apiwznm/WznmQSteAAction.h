/**
	* \file WznmQSteAAction.h
	* API code for table TblWznmQSteAAction (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSTEAACTION_H
#define WZNMQSTEAACTION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSteAAction
	*/
class WznmQSteAAction {

public:
	WznmQSteAAction(const Sbecore::uint jnum = 0, const std::string srefIxVSection = "", const std::string titIxVSection = "", const std::string srefIxVType = "", const std::string titIxVType = "", const std::string stubRefWznmMRtjob = "", const std::string stubRefWznmMVector = "", const std::string stubRefWznmMVectoritem = "", const std::string stubSnxRefWznmMState = "", const std::string stubRefWznmMSequence = "", const std::string tr1SrefATrig = "", const std::string Ip1 = "", const std::string tr2SrefATrig = "", const std::string Ip2 = "", const std::string tr3SrefATrig = "", const std::string Ip3 = "", const std::string tr4SrefATrig = "", const std::string Ip4 = "");

public:
	Sbecore::uint jnum;
	std::string srefIxVSection;
	std::string titIxVSection;
	std::string srefIxVType;
	std::string titIxVType;
	std::string stubRefWznmMRtjob;
	std::string stubRefWznmMVector;
	std::string stubRefWznmMVectoritem;
	std::string stubSnxRefWznmMState;
	std::string stubRefWznmMSequence;
	std::string tr1SrefATrig;
	std::string Ip1;
	std::string tr2SrefATrig;
	std::string Ip2;
	std::string tr3SrefATrig;
	std::string Ip3;
	std::string tr4SrefATrig;
	std::string Ip4;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSteAAction
	*/
class ListWznmQSteAAction {

public:
	ListWznmQSteAAction();
	ListWznmQSteAAction(const ListWznmQSteAAction& src);
	ListWznmQSteAAction& operator=(const ListWznmQSteAAction& src);
	~ListWznmQSteAAction();

	void clear();

public:
	std::vector<WznmQSteAAction*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
