/**
	* \file WznmQOpkSqkMNStub.h
	* API code for table TblWznmQOpkSqkMNStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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
