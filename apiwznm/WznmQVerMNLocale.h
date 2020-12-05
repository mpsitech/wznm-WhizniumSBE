/**
	* \file WznmQVerMNLocale.h
	* API code for table TblWznmQVerMNLocale (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVERMNLOCALE_H
#define WZNMQVERMNLOCALE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVerMNLocale
	*/
class WznmQVerMNLocale {

public:
	WznmQVerMNLocale(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVerMNLocale
	*/
class ListWznmQVerMNLocale {

public:
	ListWznmQVerMNLocale();
	ListWznmQVerMNLocale(const ListWznmQVerMNLocale& src);
	ListWznmQVerMNLocale& operator=(const ListWznmQVerMNLocale& src);
	~ListWznmQVerMNLocale();

	void clear();

public:
	std::vector<WznmQVerMNLocale*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

