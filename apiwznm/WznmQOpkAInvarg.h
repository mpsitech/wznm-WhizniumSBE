/**
	* \file WznmQOpkAInvarg.h
	* API code for table TblWznmQOpkAInvarg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPKAINVARG_H
#define WZNMQOPKAINVARG_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpkAInvarg
	*/
class WznmQOpkAInvarg {

public:
	WznmQOpkAInvarg(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const std::string stubRefWznmMVector = "", const std::string Defval = "", const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	std::string stubRefWznmMVector;
	std::string Defval;
	std::string stubRefWznmMVectoritem;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpkAInvarg
	*/
class ListWznmQOpkAInvarg {

public:
	ListWznmQOpkAInvarg();
	ListWznmQOpkAInvarg(const ListWznmQOpkAInvarg& src);
	ListWznmQOpkAInvarg& operator=(const ListWznmQOpkAInvarg& src);
	~ListWznmQOpkAInvarg();

	void clear();

public:
	std::vector<WznmQOpkAInvarg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

