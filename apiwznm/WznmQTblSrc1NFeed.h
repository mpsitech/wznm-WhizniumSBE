/**
	* \file WznmQTblSrc1NFeed.h
	* API code for table TblWznmQTblSrc1NFeed (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLSRC1NFEED_H
#define WZNMQTBLSRC1NFEED_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblSrc1NFeed
	*/
class WznmQTblSrc1NFeed {

public:
	WznmQTblSrc1NFeed(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblSrc1NFeed
	*/
class ListWznmQTblSrc1NFeed {

public:
	ListWznmQTblSrc1NFeed();
	ListWznmQTblSrc1NFeed(const ListWznmQTblSrc1NFeed& src);
	ListWznmQTblSrc1NFeed& operator=(const ListWznmQTblSrc1NFeed& src);
	~ListWznmQTblSrc1NFeed();

	void clear();

public:
	std::vector<WznmQTblSrc1NFeed*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

