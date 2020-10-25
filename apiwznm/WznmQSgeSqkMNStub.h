/**
	* \file WznmQSgeSqkMNStub.h
	* API code for table TblWznmQSgeSqkMNStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

