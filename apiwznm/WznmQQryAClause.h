/**
	* \file WznmQQryAClause.h
	* API code for table TblWznmQQryAClause (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRYACLAUSE_H
#define WZNMQQRYACLAUSE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQryAClause
	*/
class WznmQQryAClause {

public:
	WznmQQryAClause(const Sbecore::uint jnum = 0, const std::string stubX1RefWznmMQuerymod = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string Clause = "", const std::string stubRefWznmMPreset = "", const std::string stubRefWznmMVector = "", const std::string stubRefWznmMVectoritem = "");

public:
	Sbecore::uint jnum;
	std::string stubX1RefWznmMQuerymod;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string Clause;
	std::string stubRefWznmMPreset;
	std::string stubRefWznmMVector;
	std::string stubRefWznmMVectoritem;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQryAClause
	*/
class ListWznmQQryAClause {

public:
	ListWznmQQryAClause();
	ListWznmQQryAClause(const ListWznmQQryAClause& src);
	ListWznmQQryAClause& operator=(const ListWznmQQryAClause& src);
	~ListWznmQQryAClause();

	void clear();

public:
	std::vector<WznmQQryAClause*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
