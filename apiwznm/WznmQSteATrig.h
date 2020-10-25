/**
	* \file WznmQSteATrig.h
	* API code for table TblWznmQSteATrig (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSTEATRIG_H
#define WZNMQSTEATRIG_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSteATrig
	*/
class WznmQSteATrig {

public:
	WznmQSteATrig(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVType = "", const std::string titIxVType = "", const std::string stubRefWznmMEvent = "", const std::string stubRefWznmMRtjob = "", const std::string stubRefWznmMVectoritem = "", const std::string xsref = "", const std::string stubRefWznmMRtdpch = "", const std::string srefsMask = "", const std::string Cond = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVType;
	std::string titIxVType;
	std::string stubRefWznmMEvent;
	std::string stubRefWznmMRtjob;
	std::string stubRefWznmMVectoritem;
	std::string xsref;
	std::string stubRefWznmMRtdpch;
	std::string srefsMask;
	std::string Cond;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSteATrig
	*/
class ListWznmQSteATrig {

public:
	ListWznmQSteATrig();
	ListWznmQSteATrig(const ListWznmQSteATrig& src);
	ListWznmQSteATrig& operator=(const ListWznmQSteATrig& src);
	~ListWznmQSteATrig();

	void clear();

public:
	std::vector<WznmQSteATrig*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

