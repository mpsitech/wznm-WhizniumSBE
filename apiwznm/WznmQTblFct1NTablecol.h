/**
	* \file WznmQTblFct1NTablecol.h
	* API code for table TblWznmQTblFct1NTablecol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLFCT1NTABLECOL_H
#define WZNMQTBLFCT1NTABLECOL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblFct1NTablecol
	*/
class WznmQTblFct1NTablecol {

public:
	WznmQTblFct1NTablecol(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblFct1NTablecol
	*/
class ListWznmQTblFct1NTablecol {

public:
	ListWznmQTblFct1NTablecol();
	ListWznmQTblFct1NTablecol(const ListWznmQTblFct1NTablecol& src);
	ListWznmQTblFct1NTablecol& operator=(const ListWznmQTblFct1NTablecol& src);
	~ListWznmQTblFct1NTablecol();

	void clear();

public:
	std::vector<WznmQTblFct1NTablecol*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

