/**
	* \file WznmQSbsBsbMNSubset.h
	* API code for table TblWznmQSbsBsbMNSubset (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSBSBSBMNSUBSET_H
#define WZNMQSBSBSBMNSUBSET_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSbsBsbMNSubset
	*/
class WznmQSbsBsbMNSubset {

public:
	WznmQSbsBsbMNSubset(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxVReltype = "", const std::string titIxVReltype = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxVReltype;
	std::string titIxVReltype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSbsBsbMNSubset
	*/
class ListWznmQSbsBsbMNSubset {

public:
	ListWznmQSbsBsbMNSubset();
	ListWznmQSbsBsbMNSubset(const ListWznmQSbsBsbMNSubset& src);
	ListWznmQSbsBsbMNSubset& operator=(const ListWznmQSbsBsbMNSubset& src);
	~ListWznmQSbsBsbMNSubset();

	void clear();

public:
	std::vector<WznmQSbsBsbMNSubset*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
