/**
	* \file WznmQImeSup1NImpexp.h
	* API code for table TblWznmQImeSup1NImpexp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQIMESUP1NIMPEXP_H
#define WZNMQIMESUP1NIMPEXP_H

#include <sbecore/Xmlio.h>

/**
	* WznmQImeSup1NImpexp
	*/
class WznmQImeSup1NImpexp {

public:
	WznmQImeSup1NImpexp(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQImeSup1NImpexp
	*/
class ListWznmQImeSup1NImpexp {

public:
	ListWznmQImeSup1NImpexp();
	ListWznmQImeSup1NImpexp(const ListWznmQImeSup1NImpexp& src);
	ListWznmQImeSup1NImpexp& operator=(const ListWznmQImeSup1NImpexp& src);
	~ListWznmQImeSup1NImpexp();

	void clear();

public:
	std::vector<WznmQImeSup1NImpexp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

