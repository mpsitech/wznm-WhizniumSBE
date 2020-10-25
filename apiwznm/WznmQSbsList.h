/**
	* \file WznmQSbsList.h
	* API code for table TblWznmQSbsList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSBSLIST_H
#define WZNMQSBSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSbsList
	*/
class WznmQSbsList {

public:
	WznmQSbsList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Short = "", const std::string stubRefWznmMTable = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Short;
	std::string stubRefWznmMTable;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSbsList
	*/
class ListWznmQSbsList {

public:
	ListWznmQSbsList();
	ListWznmQSbsList(const ListWznmQSbsList& src);
	ListWznmQSbsList& operator=(const ListWznmQSbsList& src);
	~ListWznmQSbsList();

	void clear();

public:
	std::vector<WznmQSbsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

