/**
	* \file WznmQSbsAsbMNSubset.h
	* API code for table TblWznmQSbsAsbMNSubset (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSBSASBMNSUBSET_H
#define WZNMQSBSASBMNSUBSET_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSbsAsbMNSubset
	*/
class WznmQSbsAsbMNSubset {

public:
	WznmQSbsAsbMNSubset(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxVReltype = "", const std::string titIxVReltype = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxVReltype;
	std::string titIxVReltype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSbsAsbMNSubset
	*/
class ListWznmQSbsAsbMNSubset {

public:
	ListWznmQSbsAsbMNSubset();
	ListWznmQSbsAsbMNSubset(const ListWznmQSbsAsbMNSubset& src);
	ListWznmQSbsAsbMNSubset& operator=(const ListWznmQSbsAsbMNSubset& src);
	~ListWznmQSbsAsbMNSubset();

	void clear();

public:
	std::vector<WznmQSbsAsbMNSubset*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
