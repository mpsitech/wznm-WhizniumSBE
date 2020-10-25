/**
	* \file WznmQSbsAsbMNSubset.h
	* API code for table TblWznmQSbsAsbMNSubset (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

