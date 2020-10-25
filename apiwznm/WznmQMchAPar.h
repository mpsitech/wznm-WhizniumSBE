/**
	* \file WznmQMchAPar.h
	* API code for table TblWznmQMchAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQMCHAPAR_H
#define WZNMQMCHAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMchAPar
	*/
class WznmQMchAPar {

public:
	WznmQMchAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMchAPar
	*/
class ListWznmQMchAPar {

public:
	ListWznmQMchAPar();
	ListWznmQMchAPar(const ListWznmQMchAPar& src);
	ListWznmQMchAPar& operator=(const ListWznmQMchAPar& src);
	~ListWznmQMchAPar();

	void clear();

public:
	std::vector<WznmQMchAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

