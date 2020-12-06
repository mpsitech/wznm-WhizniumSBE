/**
	* \file WznmQCapAPar.h
	* API code for table TblWznmQCapAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCAPAPAR_H
#define WZNMQCAPAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCapAPar
	*/
class WznmQCapAPar {

public:
	WznmQCapAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCapAPar
	*/
class ListWznmQCapAPar {

public:
	ListWznmQCapAPar();
	ListWznmQCapAPar(const ListWznmQCapAPar& src);
	ListWznmQCapAPar& operator=(const ListWznmQCapAPar& src);
	~ListWznmQCapAPar();

	void clear();

public:
	std::vector<WznmQCapAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
