/**
	* \file WznmQTbl1NCheck.h
	* API code for table TblWznmQTbl1NCheck (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTBL1NCHECK_H
#define WZNMQTBL1NCHECK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTbl1NCheck
	*/
class WznmQTbl1NCheck {

public:
	WznmQTbl1NCheck(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTbl1NCheck
	*/
class ListWznmQTbl1NCheck {

public:
	ListWznmQTbl1NCheck();
	ListWznmQTbl1NCheck(const ListWznmQTbl1NCheck& src);
	ListWznmQTbl1NCheck& operator=(const ListWznmQTbl1NCheck& src);
	~ListWznmQTbl1NCheck();

	void clear();

public:
	std::vector<WznmQTbl1NCheck*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

