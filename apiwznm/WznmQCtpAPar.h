/**
	* \file WznmQCtpAPar.h
	* API code for table TblWznmQCtpAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQCTPAPAR_H
#define WZNMQCTPAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCtpAPar
	*/
class WznmQCtpAPar {

public:
	WznmQCtpAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCtpAPar
	*/
class ListWznmQCtpAPar {

public:
	ListWznmQCtpAPar();
	ListWznmQCtpAPar(const ListWznmQCtpAPar& src);
	ListWznmQCtpAPar& operator=(const ListWznmQCtpAPar& src);
	~ListWznmQCtpAPar();

	void clear();

public:
	std::vector<WznmQCtpAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

