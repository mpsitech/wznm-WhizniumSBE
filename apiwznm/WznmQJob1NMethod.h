/**
	* \file WznmQJob1NMethod.h
	* API code for table TblWznmQJob1NMethod (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

