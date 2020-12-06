/**
	* \file WznmQOpxARetval.h
	* API code for table TblWznmQOpxARetval (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPXARETVAL_H
#define WZNMQOPXARETVAL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpxARetval
	*/
class WznmQOpxARetval {

public:
	WznmQOpxARetval(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const std::string stubRefWznmMVector = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	std::string stubRefWznmMVector;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpxARetval
	*/
class ListWznmQOpxARetval {

public:
	ListWznmQOpxARetval();
	ListWznmQOpxARetval(const ListWznmQOpxARetval& src);
	ListWznmQOpxARetval& operator=(const ListWznmQOpxARetval& src);
	~ListWznmQOpxARetval();

	void clear();

public:
	std::vector<WznmQOpxARetval*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
