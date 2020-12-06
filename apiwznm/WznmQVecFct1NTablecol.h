/**
	* \file WznmQVecFct1NTablecol.h
	* API code for table TblWznmQVecFct1NTablecol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECFCT1NTABLECOL_H
#define WZNMQVECFCT1NTABLECOL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVecFct1NTablecol
	*/
class WznmQVecFct1NTablecol {

public:
	WznmQVecFct1NTablecol(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVecFct1NTablecol
	*/
class ListWznmQVecFct1NTablecol {

public:
	ListWznmQVecFct1NTablecol();
	ListWznmQVecFct1NTablecol(const ListWznmQVecFct1NTablecol& src);
	ListWznmQVecFct1NTablecol& operator=(const ListWznmQVecFct1NTablecol& src);
	~ListWznmQVecFct1NTablecol();

	void clear();

public:
	std::vector<WznmQVecFct1NTablecol*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
