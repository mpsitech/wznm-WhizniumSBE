/**
	* \file WznmQStbMNCall.h
	* API code for table TblWznmQStbMNCall (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQSTBMNCALL_H
#define WZNMQSTBMNCALL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQStbMNCall
	*/
class WznmQStbMNCall {

public:
	WznmQStbMNCall(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQStbMNCall
	*/
class ListWznmQStbMNCall {

public:
	ListWznmQStbMNCall();
	ListWznmQStbMNCall(const ListWznmQStbMNCall& src);
	ListWznmQStbMNCall& operator=(const ListWznmQStbMNCall& src);
	~ListWznmQStbMNCall();

	void clear();

public:
	std::vector<WznmQStbMNCall*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

