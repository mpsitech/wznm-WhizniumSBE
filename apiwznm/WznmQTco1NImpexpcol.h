/**
	* \file WznmQTco1NImpexpcol.h
	* API code for table TblWznmQTco1NImpexpcol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTCO1NIMPEXPCOL_H
#define WZNMQTCO1NIMPEXPCOL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTco1NImpexpcol
	*/
class WznmQTco1NImpexpcol {

public:
	WznmQTco1NImpexpcol(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTco1NImpexpcol
	*/
class ListWznmQTco1NImpexpcol {

public:
	ListWznmQTco1NImpexpcol();
	ListWznmQTco1NImpexpcol(const ListWznmQTco1NImpexpcol& src);
	ListWznmQTco1NImpexpcol& operator=(const ListWznmQTco1NImpexpcol& src);
	~ListWznmQTco1NImpexpcol();

	void clear();

public:
	std::vector<WznmQTco1NImpexpcol*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

