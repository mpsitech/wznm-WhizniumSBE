/**
	* \file WznmQTblPst1NQuerymod.h
	* API code for table TblWznmQTblPst1NQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLPST1NQUERYMOD_H
#define WZNMQTBLPST1NQUERYMOD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblPst1NQuerymod
	*/
class WznmQTblPst1NQuerymod {

public:
	WznmQTblPst1NQuerymod(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblPst1NQuerymod
	*/
class ListWznmQTblPst1NQuerymod {

public:
	ListWznmQTblPst1NQuerymod();
	ListWznmQTblPst1NQuerymod(const ListWznmQTblPst1NQuerymod& src);
	ListWznmQTblPst1NQuerymod& operator=(const ListWznmQTblPst1NQuerymod& src);
	~ListWznmQTblPst1NQuerymod();

	void clear();

public:
	std::vector<WznmQTblPst1NQuerymod*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
