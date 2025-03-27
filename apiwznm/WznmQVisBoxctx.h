/**
	* \file WznmQVisBoxctx.h
	* API code for table TblWznmQVisBoxctx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISBOXCTX_H
#define WZNMQVISBOXCTX_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVisBoxctx
	*/
class WznmQVisBoxctx {

public:
	WznmQVisBoxctx(const Sbecore::uint jnum = 0, const std::string stubUnvUref = "", const Sbecore::smallint x = 0, const Sbecore::smallint y = 0, const std::string jnumsSub = "", const std::string jnumsLink = "", const int w = 0, const int h = 0, const std::string Content1 = "", const std::string Content2 = "");

public:
	Sbecore::uint jnum;
	std::string stubUnvUref;
	Sbecore::smallint x;
	Sbecore::smallint y;
	std::string jnumsSub;
	std::string jnumsLink;
	int w;
	int h;
	std::string Content1;
	std::string Content2;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVisBoxctx
	*/
class ListWznmQVisBoxctx {

public:
	ListWznmQVisBoxctx();
	ListWznmQVisBoxctx(const ListWznmQVisBoxctx& src);
	ListWznmQVisBoxctx& operator=(const ListWznmQVisBoxctx& src);
	~ListWznmQVisBoxctx();

	void clear();

public:
	std::vector<WznmQVisBoxctx*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
