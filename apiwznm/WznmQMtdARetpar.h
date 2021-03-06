/**
	* \file WznmQMtdARetpar.h
	* API code for table TblWznmQMtdARetpar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMTDARETPAR_H
#define WZNMQMTDARETPAR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMtdARetpar
	*/
class WznmQMtdARetpar {

public:
	WznmQMtdARetpar(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	std::string stubRefWznmMVector;
	Sbecore::uint Length;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMtdARetpar
	*/
class ListWznmQMtdARetpar {

public:
	ListWznmQMtdARetpar();
	ListWznmQMtdARetpar(const ListWznmQMtdARetpar& src);
	ListWznmQMtdARetpar& operator=(const ListWznmQMtdARetpar& src);
	~ListWznmQMtdARetpar();

	void clear();

public:
	std::vector<WznmQMtdARetpar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
