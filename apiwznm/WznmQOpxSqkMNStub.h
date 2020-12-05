/**
	* \file WznmQOpxSqkMNStub.h
	* API code for table TblWznmQOpxSqkMNStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPXSQKMNSTUB_H
#define WZNMQOPXSQKMNSTUB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpxSqkMNStub
	*/
class WznmQOpxSqkMNStub {

public:
	WznmQOpxSqkMNStub(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpxSqkMNStub
	*/
class ListWznmQOpxSqkMNStub {

public:
	ListWznmQOpxSqkMNStub();
	ListWznmQOpxSqkMNStub(const ListWznmQOpxSqkMNStub& src);
	ListWznmQOpxSqkMNStub& operator=(const ListWznmQOpxSqkMNStub& src);
	~ListWznmQOpxSqkMNStub();

	void clear();

public:
	std::vector<WznmQOpxSqkMNStub*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

