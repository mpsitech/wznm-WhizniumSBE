/**
	* \file WznmQMty1NMachine.h
	* API code for table TblWznmQMty1NMachine (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQMTY1NMACHINE_H
#define WZNMQMTY1NMACHINE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMty1NMachine
	*/
class WznmQMty1NMachine {

public:
	WznmQMty1NMachine(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMty1NMachine
	*/
class ListWznmQMty1NMachine {

public:
	ListWznmQMty1NMachine();
	ListWznmQMty1NMachine(const ListWznmQMty1NMachine& src);
	ListWznmQMty1NMachine& operator=(const ListWznmQMty1NMachine& src);
	~ListWznmQMty1NMachine();

	void clear();

public:
	std::vector<WznmQMty1NMachine*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

