/**
	* \file WznmQJob1NMethod.h
	* API code for table TblWznmQJob1NMethod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOB1NMETHOD_H
#define WZNMQJOB1NMETHOD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJob1NMethod
	*/
class WznmQJob1NMethod {

public:
	WznmQJob1NMethod(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJob1NMethod
	*/
class ListWznmQJob1NMethod {

public:
	ListWznmQJob1NMethod();
	ListWznmQJob1NMethod(const ListWznmQJob1NMethod& src);
	ListWznmQJob1NMethod& operator=(const ListWznmQJob1NMethod& src);
	~ListWznmQJob1NMethod();

	void clear();

public:
	std::vector<WznmQJob1NMethod*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

