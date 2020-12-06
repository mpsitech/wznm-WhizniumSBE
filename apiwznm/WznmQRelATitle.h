/**
	* \file WznmQRelATitle.h
	* API code for table TblWznmQRelATitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRELATITLE_H
#define WZNMQRELATITLE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRelATitle
	*/
class WznmQRelATitle {

public:
	WznmQRelATitle(const Sbecore::uint jnum = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const std::string stubX2RefWznmMLocale = "", const std::string Title = "");

public:
	Sbecore::uint jnum;
	std::string srefX1IxVType;
	std::string titX1IxVType;
	std::string stubX2RefWznmMLocale;
	std::string Title;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRelATitle
	*/
class ListWznmQRelATitle {

public:
	ListWznmQRelATitle();
	ListWznmQRelATitle(const ListWznmQRelATitle& src);
	ListWznmQRelATitle& operator=(const ListWznmQRelATitle& src);
	~ListWznmQRelATitle();

	void clear();

public:
	std::vector<WznmQRelATitle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
