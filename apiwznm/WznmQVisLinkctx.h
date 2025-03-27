/**
	* \file WznmQVisLinkctx.h
	* API code for table TblWznmQVisLinkctx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISLINKCTX_H
#define WZNMQVISLINKCTX_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVisLinkctx
	*/
class WznmQVisLinkctx {

public:
	WznmQVisLinkctx(const Sbecore::uint jnum = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0, const int jnumBoxOrg = 0, const int jnumBoxDst = 0, const std::string Title = "", const std::string Content1 = "", const std::string Content2 = "");

public:
	Sbecore::uint jnum;
	Sbecore::utinyint orgClk;
	Sbecore::utinyint dstClk;
	Sbecore::utinyint Weight;
	int jnumBoxOrg;
	int jnumBoxDst;
	std::string Title;
	std::string Content1;
	std::string Content2;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVisLinkctx
	*/
class ListWznmQVisLinkctx {

public:
	ListWznmQVisLinkctx();
	ListWznmQVisLinkctx(const ListWznmQVisLinkctx& src);
	ListWznmQVisLinkctx& operator=(const ListWznmQVisLinkctx& src);
	~ListWznmQVisLinkctx();

	void clear();

public:
	std::vector<WznmQVisLinkctx*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
