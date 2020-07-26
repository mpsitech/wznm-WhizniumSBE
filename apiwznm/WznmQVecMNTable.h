/**
	* \file WznmQVecMNTable.h
	* API code for table TblWznmQVecMNTable (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

