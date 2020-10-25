/**
	* \file WznmQVecPst1NQuerymod.h
	* API code for table TblWznmQVecPst1NQuerymod (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

