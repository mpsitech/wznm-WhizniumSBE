/**
	* \file WznmQVecSrc1NFeed.h
	* API code for table TblWznmQVecSrc1NFeed (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECSRC1NFEED_H
#define WZNMQVECSRC1NFEED_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVecSrc1NFeed
	*/
class WznmQVecSrc1NFeed {

public:
	WznmQVecSrc1NFeed(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVecSrc1NFeed
	*/
class ListWznmQVecSrc1NFeed {

public:
	ListWznmQVecSrc1NFeed();
	ListWznmQVecSrc1NFeed(const ListWznmQVecSrc1NFeed& src);
	ListWznmQVecSrc1NFeed& operator=(const ListWznmQVecSrc1NFeed& src);
	~ListWznmQVecSrc1NFeed();

	void clear();

public:
	std::vector<WznmQVecSrc1NFeed*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
