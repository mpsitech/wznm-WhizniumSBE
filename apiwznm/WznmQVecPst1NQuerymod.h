/**
	* \file WznmQVecPst1NQuerymod.h
	* API code for table TblWznmQVecPst1NQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECPST1NQUERYMOD_H
#define WZNMQVECPST1NQUERYMOD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVecPst1NQuerymod
	*/
class WznmQVecPst1NQuerymod {

public:
	WznmQVecPst1NQuerymod(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVecPst1NQuerymod
	*/
class ListWznmQVecPst1NQuerymod {

public:
	ListWznmQVecPst1NQuerymod();
	ListWznmQVecPst1NQuerymod(const ListWznmQVecPst1NQuerymod& src);
	ListWznmQVecPst1NQuerymod& operator=(const ListWznmQVecPst1NQuerymod& src);
	~ListWznmQVecPst1NQuerymod();

	void clear();

public:
	std::vector<WznmQVecPst1NQuerymod*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
