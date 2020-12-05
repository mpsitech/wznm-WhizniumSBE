/**
	* \file WznmQRlsList.h
	* API code for table TblWznmQRlsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRLSLIST_H
#define WZNMQRLSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRlsList
	*/
class WznmQRlsList {

public:
	WznmQRlsList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWznmMComponent = "", const std::string stubRefWznmMMachine = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWznmMComponent;
	std::string stubRefWznmMMachine;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRlsList
	*/
class ListWznmQRlsList {

public:
	ListWznmQRlsList();
	ListWznmQRlsList(const ListWznmQRlsList& src);
	ListWznmQRlsList& operator=(const ListWznmQRlsList& src);
	~ListWznmQRlsList();

	void clear();

public:
	std::vector<WznmQRlsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

