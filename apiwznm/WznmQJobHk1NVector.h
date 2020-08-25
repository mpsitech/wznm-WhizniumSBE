/**
	* \file WznmQJobHk1NVector.h
	* API code for table TblWznmQJobHk1NVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQJOBHK1NVECTOR_H
#define WZNMQJOBHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobHk1NVector
	*/
class WznmQJobHk1NVector {

public:
	WznmQJobHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJobHk1NVector
	*/
class ListWznmQJobHk1NVector {

public:
	ListWznmQJobHk1NVector();
	ListWznmQJobHk1NVector(const ListWznmQJobHk1NVector& src);
	ListWznmQJobHk1NVector& operator=(const ListWznmQJobHk1NVector& src);
	~ListWznmQJobHk1NVector();

	void clear();

public:
	std::vector<WznmQJobHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

