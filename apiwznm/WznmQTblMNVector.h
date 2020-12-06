/**
	* \file WznmQTblMNVector.h
	* API code for table TblWznmQTblMNVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLMNVECTOR_H
#define WZNMQTBLMNVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblMNVector
	*/
class WznmQTblMNVector {

public:
	WznmQTblMNVector(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string stubRefWznmMSubset = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string stubRefWznmMSubset;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblMNVector
	*/
class ListWznmQTblMNVector {

public:
	ListWznmQTblMNVector();
	ListWznmQTblMNVector(const ListWznmQTblMNVector& src);
	ListWznmQTblMNVector& operator=(const ListWznmQTblMNVector& src);
	~ListWznmQTblMNVector();

	void clear();

public:
	std::vector<WznmQTblMNVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
