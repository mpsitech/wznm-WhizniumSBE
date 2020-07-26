/**
	* \file WznmQSteList.h
	* API code for table TblWznmQSteList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQSTELIST_H
#define WZNMQSTELIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSteList
	*/
class WznmQSteList {

public:
	WznmQSteList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubSeqRefWznmMSequence = "", const std::string srefEacIxVAction = "", const std::string titEacIxVAction = "", const std::string srefLacIxVAction = "", const std::string titLacIxVAction = "", const std::string yesnoCuststep = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubSeqRefWznmMSequence;
	std::string srefEacIxVAction;
	std::string titEacIxVAction;
	std::string srefLacIxVAction;
	std::string titLacIxVAction;
	std::string yesnoCuststep;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSteList
	*/
class ListWznmQSteList {

public:
	ListWznmQSteList();
	ListWznmQSteList(const ListWznmQSteList& src);
	ListWznmQSteList& operator=(const ListWznmQSteList& src);
	~ListWznmQSteList();

	void clear();

public:
	std::vector<WznmQSteList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

