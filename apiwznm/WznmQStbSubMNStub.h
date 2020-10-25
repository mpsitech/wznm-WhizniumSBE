/**
	* \file WznmQStbSubMNStub.h
	* API code for table TblWznmQStbSubMNStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSTBSUBMNSTUB_H
#define WZNMQSTBSUBMNSTUB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQStbSubMNStub
	*/
class WznmQStbSubMNStub {

public:
	WznmQStbSubMNStub(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQStbSubMNStub
	*/
class ListWznmQStbSubMNStub {

public:
	ListWznmQStbSubMNStub();
	ListWznmQStbSubMNStub(const ListWznmQStbSubMNStub& src);
	ListWznmQStbSubMNStub& operator=(const ListWznmQStbSubMNStub& src);
	~ListWznmQStbSubMNStub();

	void clear();

public:
	std::vector<WznmQStbSubMNStub*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

