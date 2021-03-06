/**
	* \file WznmQVecMNTable.h
	* API code for table TblWznmQVecMNTable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECMNTABLE_H
#define WZNMQVECMNTABLE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVecMNTable
	*/
class WznmQVecMNTable {

public:
	WznmQVecMNTable(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string stubRefWznmMSubset = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string stubRefWznmMSubset;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVecMNTable
	*/
class ListWznmQVecMNTable {

public:
	ListWznmQVecMNTable();
	ListWznmQVecMNTable(const ListWznmQVecMNTable& src);
	ListWznmQVecMNTable& operator=(const ListWznmQVecMNTable& src);
	~ListWznmQVecMNTable();

	void clear();

public:
	std::vector<WznmQVecMNTable*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
