/**
	* \file WznmQTbl1NImpexp.h
	* API code for table TblWznmQTbl1NImpexp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTBL1NIMPEXP_H
#define WZNMQTBL1NIMPEXP_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTbl1NImpexp
	*/
class WznmQTbl1NImpexp {

public:
	WznmQTbl1NImpexp(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTbl1NImpexp
	*/
class ListWznmQTbl1NImpexp {

public:
	ListWznmQTbl1NImpexp();
	ListWznmQTbl1NImpexp(const ListWznmQTbl1NImpexp& src);
	ListWznmQTbl1NImpexp& operator=(const ListWznmQTbl1NImpexp& src);
	~ListWznmQTbl1NImpexp();

	void clear();

public:
	std::vector<WznmQTbl1NImpexp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

