/**
	* \file WznmQOpkSqkMNStub.h
	* API code for table TblWznmQOpkSqkMNStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQOPKSQKMNSTUB_H
#define WZNMQOPKSQKMNSTUB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpkSqkMNStub
	*/
class WznmQOpkSqkMNStub {

public:
	WznmQOpkSqkMNStub(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpkSqkMNStub
	*/
class ListWznmQOpkSqkMNStub {

public:
	ListWznmQOpkSqkMNStub();
	ListWznmQOpkSqkMNStub(const ListWznmQOpkSqkMNStub& src);
	ListWznmQOpkSqkMNStub& operator=(const ListWznmQOpkSqkMNStub& src);
	~ListWznmQOpkSqkMNStub();

	void clear();

public:
	std::vector<WznmQOpkSqkMNStub*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

