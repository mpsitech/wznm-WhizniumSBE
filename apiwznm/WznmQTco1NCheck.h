/**
	* \file WznmQTco1NCheck.h
	* API code for table TblWznmQTco1NCheck (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTCO1NCHECK_H
#define WZNMQTCO1NCHECK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTco1NCheck
	*/
class WznmQTco1NCheck {

public:
	WznmQTco1NCheck(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTco1NCheck
	*/
class ListWznmQTco1NCheck {

public:
	ListWznmQTco1NCheck();
	ListWznmQTco1NCheck(const ListWznmQTco1NCheck& src);
	ListWznmQTco1NCheck& operator=(const ListWznmQTco1NCheck& src);
	~ListWznmQTco1NCheck();

	void clear();

public:
	std::vector<WznmQTco1NCheck*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
