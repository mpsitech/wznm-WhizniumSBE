/**
	* \file WznmQSteAStep.h
	* API code for table TblWznmQSteAStep (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQSTEASTEP_H
#define WZNMQSTEASTEP_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSteAStep
	*/
class WznmQSteAStep {

public:
	WznmQSteAStep(const Sbecore::uint jnum = 0, const std::string stubSnxRefWznmMState = "", const std::string srefIxVTrigger = "", const std::string titIxVTrigger = "", const std::string stubRefWznmMRtjob = "", const std::string stubRefWznmMVectoritem = "", const std::string xsref = "", const std::string stubRefWznmMRtdpch = "", const std::string srefsMask = "", const std::string Cond = "", const std::string yesnoCustcode = "");

public:
	Sbecore::uint jnum;
	std::string stubSnxRefWznmMState;
	std::string srefIxVTrigger;
	std::string titIxVTrigger;
	std::string stubRefWznmMRtjob;
	std::string stubRefWznmMVectoritem;
	std::string xsref;
	std::string stubRefWznmMRtdpch;
	std::string srefsMask;
	std::string Cond;
	std::string yesnoCustcode;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSteAStep
	*/
class ListWznmQSteAStep {

public:
	ListWznmQSteAStep();
	ListWznmQSteAStep(const ListWznmQSteAStep& src);
	ListWznmQSteAStep& operator=(const ListWznmQSteAStep& src);
	~ListWznmQSteAStep();

	void clear();

public:
	std::vector<WznmQSteAStep*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

