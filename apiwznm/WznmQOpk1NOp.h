/**
	* \file WznmQOpk1NOp.h
	* API code for table TblWznmQOpk1NOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPK1NOP_H
#define WZNMQOPK1NOP_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpk1NOp
	*/
class WznmQOpk1NOp {

public:
	WznmQOpk1NOp(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpk1NOp
	*/
class ListWznmQOpk1NOp {

public:
	ListWznmQOpk1NOp();
	ListWznmQOpk1NOp(const ListWznmQOpk1NOp& src);
	ListWznmQOpk1NOp& operator=(const ListWznmQOpk1NOp& src);
	~ListWznmQOpk1NOp();

	void clear();

public:
	std::vector<WznmQOpk1NOp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

