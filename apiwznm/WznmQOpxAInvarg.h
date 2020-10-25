/**
	* \file WznmQOpxAInvarg.h
	* API code for table TblWznmQOpxAInvarg (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQOPXAINVARG_H
#define WZNMQOPXAINVARG_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpxAInvarg
	*/
class WznmQOpxAInvarg {

public:
	WznmQOpxAInvarg(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const std::string stubRefWznmMVector = "", const std::string Defval = "", const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");

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
	* ListWznmQOpxAInvarg
	*/
class ListWznmQOpxAInvarg {

public:
	ListWznmQOpxAInvarg();
	ListWznmQOpxAInvarg(const ListWznmQOpxAInvarg& src);
	ListWznmQOpxAInvarg& operator=(const ListWznmQOpxAInvarg& src);
	~ListWznmQOpxAInvarg();

	void clear();

public:
	std::vector<WznmQOpxAInvarg*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

