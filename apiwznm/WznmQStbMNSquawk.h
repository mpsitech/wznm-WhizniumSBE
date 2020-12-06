/**
	* \file WznmQStbMNSquawk.h
	* API code for table TblWznmQStbMNSquawk (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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
