/**
	* \file WznmQRtjList.h
	* API code for table TblWznmQRtjList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQRTJLIST_H
#define WZNMQRTJLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRtjList
	*/
class WznmQRtjList {

public:
	WznmQRtjList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWznmMApp = "", const std::string stubSupRefWznmMRtjob = "", const std::string stubRefWznmMJob = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWznmMApp;
	std::string stubSupRefWznmMRtjob;
	std::string stubRefWznmMJob;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRtjList
	*/
class ListWznmQRtjList {

public:
	ListWznmQRtjList();
	ListWznmQRtjList(const ListWznmQRtjList& src);
	ListWznmQRtjList& operator=(const ListWznmQRtjList& src);
	~ListWznmQRtjList();

	void clear();

public:
	std::vector<WznmQRtjList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

