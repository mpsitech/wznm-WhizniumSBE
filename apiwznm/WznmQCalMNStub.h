/**
	* \file WznmQCalMNStub.h
	* API code for table TblWznmQCalMNStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCALMNSTUB_H
#define WZNMQCALMNSTUB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCalMNStub
	*/
class WznmQCalMNStub {

public:
	WznmQCalMNStub(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCalMNStub
	*/
class ListWznmQCalMNStub {

public:
	ListWznmQCalMNStub();
	ListWznmQCalMNStub(const ListWznmQCalMNStub& src);
	ListWznmQCalMNStub& operator=(const ListWznmQCalMNStub& src);
	~ListWznmQCalMNStub();

	void clear();

public:
	std::vector<WznmQCalMNStub*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

