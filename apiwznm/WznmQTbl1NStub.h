/**
	* \file WznmQTbl1NStub.h
	* API code for table TblWznmQTbl1NStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTBL1NSTUB_H
#define WZNMQTBL1NSTUB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTbl1NStub
	*/
class WznmQTbl1NStub {

public:
	WznmQTbl1NStub(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTbl1NStub
	*/
class ListWznmQTbl1NStub {

public:
	ListWznmQTbl1NStub();
	ListWznmQTbl1NStub(const ListWznmQTbl1NStub& src);
	ListWznmQTbl1NStub& operator=(const ListWznmQTbl1NStub& src);
	~ListWznmQTbl1NStub();

	void clear();

public:
	std::vector<WznmQTbl1NStub*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
