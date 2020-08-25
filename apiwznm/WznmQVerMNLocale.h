/**
	* \file WznmQVerMNLocale.h
	* API code for table TblWznmQVerMNLocale (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

