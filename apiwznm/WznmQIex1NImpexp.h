/**
	* \file WznmQIex1NImpexp.h
	* API code for table TblWznmQIex1NImpexp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIEX1NIMPEXP_H
#define WZNMQIEX1NIMPEXP_H

#include <sbecore/Xmlio.h>

/**
	* WznmQIex1NImpexp
	*/
class WznmQIex1NImpexp {

public:
	WznmQIex1NImpexp(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQIex1NImpexp
	*/
class ListWznmQIex1NImpexp {

public:
	ListWznmQIex1NImpexp();
	ListWznmQIex1NImpexp(const ListWznmQIex1NImpexp& src);
	ListWznmQIex1NImpexp& operator=(const ListWznmQIex1NImpexp& src);
	~ListWznmQIex1NImpexp();

	void clear();

public:
	std::vector<WznmQIex1NImpexp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

