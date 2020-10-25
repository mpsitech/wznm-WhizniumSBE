/**
	* \file WznmQTcoATitle.h
	* API code for table TblWznmQTcoATitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTCOATITLE_H
#define WZNMQTCOATITLE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTcoATitle
	*/
class WznmQTcoATitle {

public:
	WznmQTcoATitle(const Sbecore::uint jnum = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const std::string stubX2RefWznmMLocale = "", const std::string Title = "");

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
	* ListWznmQTcoATitle
	*/
class ListWznmQTcoATitle {

public:
	ListWznmQTcoATitle();
	ListWznmQTcoATitle(const ListWznmQTcoATitle& src);
	ListWznmQTcoATitle& operator=(const ListWznmQTcoATitle& src);
	~ListWznmQTcoATitle();

	void clear();

public:
	std::vector<WznmQTcoATitle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

