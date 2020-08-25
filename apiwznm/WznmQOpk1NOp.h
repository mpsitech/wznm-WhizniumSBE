/**
	* \file WznmQOpk1NOp.h
	* API code for table TblWznmQOpk1NOp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

