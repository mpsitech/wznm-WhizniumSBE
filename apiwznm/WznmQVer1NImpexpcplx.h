/**
	* \file WznmQVer1NImpexpcplx.h
	* API code for table TblWznmQVer1NImpexpcplx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NIMPEXPCPLX_H
#define WZNMQVER1NIMPEXPCPLX_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NImpexpcplx
	*/
class WznmQVer1NImpexpcplx {

public:
	WznmQVer1NImpexpcplx(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NImpexpcplx
	*/
class ListWznmQVer1NImpexpcplx {

public:
	ListWznmQVer1NImpexpcplx();
	ListWznmQVer1NImpexpcplx(const ListWznmQVer1NImpexpcplx& src);
	ListWznmQVer1NImpexpcplx& operator=(const ListWznmQVer1NImpexpcplx& src);
	~ListWznmQVer1NImpexpcplx();

	void clear();

public:
	std::vector<WznmQVer1NImpexpcplx*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
