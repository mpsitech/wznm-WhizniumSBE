/**
	* \file WznmQMchSup1NMachine.h
	* API code for table TblWznmQMchSup1NMachine (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMCHSUP1NMACHINE_H
#define WZNMQMCHSUP1NMACHINE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMchSup1NMachine
	*/
class WznmQMchSup1NMachine {

public:
	WznmQMchSup1NMachine(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMchSup1NMachine
	*/
class ListWznmQMchSup1NMachine {

public:
	ListWznmQMchSup1NMachine();
	ListWznmQMchSup1NMachine(const ListWznmQMchSup1NMachine& src);
	ListWznmQMchSup1NMachine& operator=(const ListWznmQMchSup1NMachine& src);
	~ListWznmQMchSup1NMachine();

	void clear();

public:
	std::vector<WznmQMchSup1NMachine*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

