/**
	* \file WznmQOpxSqkMNStub.h
	* API code for table TblWznmQOpxSqkMNStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

