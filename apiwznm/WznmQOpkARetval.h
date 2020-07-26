/**
	* \file WznmQOpkARetval.h
	* API code for table TblWznmQOpkARetval (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQOPKARETVAL_H
#define WZNMQOPKARETVAL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpkARetval
	*/
class WznmQOpkARetval {

public:
	WznmQOpkARetval(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const std::string stubRefWznmMVector = "", const std::string Comment = "");

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
	* ListWznmQOpkARetval
	*/
class ListWznmQOpkARetval {

public:
	ListWznmQOpkARetval();
	ListWznmQOpkARetval(const ListWznmQOpkARetval& src);
	ListWznmQOpkARetval& operator=(const ListWznmQOpkARetval& src);
	~ListWznmQOpkARetval();

	void clear();

public:
	std::vector<WznmQOpkARetval*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

