/**
	* \file WznmQSbs1NStub.h
	* API code for table TblWznmQSbs1NStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSBS1NSTUB_H
#define WZNMQSBS1NSTUB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSbs1NStub
	*/
class WznmQSbs1NStub {

public:
	WznmQSbs1NStub(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSbs1NStub
	*/
class ListWznmQSbs1NStub {

public:
	ListWznmQSbs1NStub();
	ListWznmQSbs1NStub(const ListWznmQSbs1NStub& src);
	ListWznmQSbs1NStub& operator=(const ListWznmQSbs1NStub& src);
	~ListWznmQSbs1NStub();

	void clear();

public:
	std::vector<WznmQSbs1NStub*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
