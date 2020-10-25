/**
	* \file WznmQSbs1NTablecol.h
	* API code for table TblWznmQSbs1NTablecol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSBS1NTABLECOL_H
#define WZNMQSBS1NTABLECOL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSbs1NTablecol
	*/
class WznmQSbs1NTablecol {

public:
	WznmQSbs1NTablecol(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSbs1NTablecol
	*/
class ListWznmQSbs1NTablecol {

public:
	ListWznmQSbs1NTablecol();
	ListWznmQSbs1NTablecol(const ListWznmQSbs1NTablecol& src);
	ListWznmQSbs1NTablecol& operator=(const ListWznmQSbs1NTablecol& src);
	~ListWznmQSbs1NTablecol();

	void clear();

public:
	std::vector<WznmQSbs1NTablecol*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

