/**
	* \file WznmQVisRowctx.h
	* API code for table TblWznmQVisRowctx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISROWCTX_H
#define WZNMQVISROWCTX_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVisRowctx
	*/
class WznmQVisRowctx {

public:
	WznmQVisRowctx(const Sbecore::uint jnum = 0, const int jnumBox = 0, const std::string Content1 = "", const std::string Content2 = "", const std::string Content3 = "");

public:
	Sbecore::uint jnum;
	int jnumBox;
	std::string Content1;
	std::string Content2;
	std::string Content3;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVisRowctx
	*/
class ListWznmQVisRowctx {

public:
	ListWznmQVisRowctx();
	ListWznmQVisRowctx(const ListWznmQVisRowctx& src);
	ListWznmQVisRowctx& operator=(const ListWznmQVisRowctx& src);
	~ListWznmQVisRowctx();

	void clear();

public:
	std::vector<WznmQVisRowctx*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
