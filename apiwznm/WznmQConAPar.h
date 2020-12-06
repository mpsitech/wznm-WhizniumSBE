/**
	* \file WznmQConAPar.h
	* API code for table TblWznmQConAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCONAPAR_H
#define WZNMQCONAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQConAPar
	*/
class WznmQConAPar {

public:
	WznmQConAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string stubX2RefWznmMLocale = "", const std::string osrefKVal = "", const std::string titOsrefKVal = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string stubX2RefWznmMLocale;
	std::string osrefKVal;
	std::string titOsrefKVal;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQConAPar
	*/
class ListWznmQConAPar {

public:
	ListWznmQConAPar();
	ListWznmQConAPar(const ListWznmQConAPar& src);
	ListWznmQConAPar& operator=(const ListWznmQConAPar& src);
	~ListWznmQConAPar();

	void clear();

public:
	std::vector<WznmQConAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
