/**
	* \file WznmQTblTbl1NTablecol.h
	* API code for table TblWznmQTblTbl1NTablecol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLTBL1NTABLECOL_H
#define WZNMQTBLTBL1NTABLECOL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblTbl1NTablecol
	*/
class WznmQTblTbl1NTablecol {

public:
	WznmQTblTbl1NTablecol(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblTbl1NTablecol
	*/
class ListWznmQTblTbl1NTablecol {

public:
	ListWznmQTblTbl1NTablecol();
	ListWznmQTblTbl1NTablecol(const ListWznmQTblTbl1NTablecol& src);
	ListWznmQTblTbl1NTablecol& operator=(const ListWznmQTblTbl1NTablecol& src);
	~ListWznmQTblTbl1NTablecol();

	void clear();

public:
	std::vector<WznmQTblTbl1NTablecol*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
