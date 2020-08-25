/**
	* \file WznmQStbMNSquawk.h
	* API code for table TblWznmQStbMNSquawk (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQSTBMNSQUAWK_H
#define WZNMQSTBMNSQUAWK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQStbMNSquawk
	*/
class WznmQStbMNSquawk {

public:
	WznmQStbMNSquawk(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQStbMNSquawk
	*/
class ListWznmQStbMNSquawk {

public:
	ListWznmQStbMNSquawk();
	ListWznmQStbMNSquawk(const ListWznmQStbMNSquawk& src);
	ListWznmQStbMNSquawk& operator=(const ListWznmQStbMNSquawk& src);
	~ListWznmQStbMNSquawk();

	void clear();

public:
	std::vector<WznmQStbMNSquawk*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

