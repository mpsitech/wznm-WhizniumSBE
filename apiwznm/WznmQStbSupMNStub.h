/**
	* \file WznmQStbSupMNStub.h
	* API code for table TblWznmQStbSupMNStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSTBSUPMNSTUB_H
#define WZNMQSTBSUPMNSTUB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQStbSupMNStub
	*/
class WznmQStbSupMNStub {

public:
	WznmQStbSupMNStub(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQStbSupMNStub
	*/
class ListWznmQStbSupMNStub {

public:
	ListWznmQStbSupMNStub();
	ListWznmQStbSupMNStub(const ListWznmQStbSupMNStub& src);
	ListWznmQStbSupMNStub& operator=(const ListWznmQStbSupMNStub& src);
	~ListWznmQStbSupMNStub();

	void clear();

public:
	std::vector<WznmQStbSupMNStub*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
