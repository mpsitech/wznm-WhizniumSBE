/**
	* \file WznmQSgeSqkMNStub.h
	* API code for table TblWznmQSgeSqkMNStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSGESQKMNSTUB_H
#define WZNMQSGESQKMNSTUB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSgeSqkMNStub
	*/
class WznmQSgeSqkMNStub {

public:
	WznmQSgeSqkMNStub(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSgeSqkMNStub
	*/
class ListWznmQSgeSqkMNStub {

public:
	ListWznmQSgeSqkMNStub();
	ListWznmQSgeSqkMNStub(const ListWznmQSgeSqkMNStub& src);
	ListWznmQSgeSqkMNStub& operator=(const ListWznmQSgeSqkMNStub& src);
	~ListWznmQSgeSqkMNStub();

	void clear();

public:
	std::vector<WznmQSgeSqkMNStub*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

