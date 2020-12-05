/**
	* \file WznmQRel1NTablecol.h
	* API code for table TblWznmQRel1NTablecol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQREL1NTABLECOL_H
#define WZNMQREL1NTABLECOL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRel1NTablecol
	*/
class WznmQRel1NTablecol {

public:
	WznmQRel1NTablecol(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRel1NTablecol
	*/
class ListWznmQRel1NTablecol {

public:
	ListWznmQRel1NTablecol();
	ListWznmQRel1NTablecol(const ListWznmQRel1NTablecol& src);
	ListWznmQRel1NTablecol& operator=(const ListWznmQRel1NTablecol& src);
	~ListWznmQRel1NTablecol();

	void clear();

public:
	std::vector<WznmQRel1NTablecol*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

