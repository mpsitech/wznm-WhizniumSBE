/**
	* \file WznmQMtdAInvpar.h
	* API code for table TblWznmQMtdAInvpar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMTDAINVPAR_H
#define WZNMQMTDAINVPAR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMtdAInvpar
	*/
class WznmQMtdAInvpar {

public:
	WznmQMtdAInvpar(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string Comment = "");

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
	* ListWznmQMtdAInvpar
	*/
class ListWznmQMtdAInvpar {

public:
	ListWznmQMtdAInvpar();
	ListWznmQMtdAInvpar(const ListWznmQMtdAInvpar& src);
	ListWznmQMtdAInvpar& operator=(const ListWznmQMtdAInvpar& src);
	~ListWznmQMtdAInvpar();

	void clear();

public:
	std::vector<WznmQMtdAInvpar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
