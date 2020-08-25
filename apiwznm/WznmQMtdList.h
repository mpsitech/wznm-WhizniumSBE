/**
	* \file WznmQMtdList.h
	* API code for table TblWznmQMtdList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQMTDLIST_H
#define WZNMQMTDLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMtdList
	*/
class WznmQMtdList {

public:
	WznmQMtdList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWznmMJob = "", const std::string yesnoExecsrv = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWznmMJob;
	std::string yesnoExecsrv;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMtdList
	*/
class ListWznmQMtdList {

public:
	ListWznmQMtdList();
	ListWznmQMtdList(const ListWznmQMtdList& src);
	ListWznmQMtdList& operator=(const ListWznmQMtdList& src);
	~ListWznmQMtdList();

	void clear();

public:
	std::vector<WznmQMtdList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

