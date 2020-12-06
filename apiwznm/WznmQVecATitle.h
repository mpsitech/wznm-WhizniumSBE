/**
	* \file WznmQVecATitle.h
	* API code for table TblWznmQVecATitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECATITLE_H
#define WZNMQVECATITLE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVecATitle
	*/
class WznmQVecATitle {

public:
	WznmQVecATitle(const Sbecore::uint jnum = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const std::string stubX2RefWznmMLocale = "", const std::string Title = "");

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
	* ListWznmQVecATitle
	*/
class ListWznmQVecATitle {

public:
	ListWznmQVecATitle();
	ListWznmQVecATitle(const ListWznmQVecATitle& src);
	ListWznmQVecATitle& operator=(const ListWznmQVecATitle& src);
	~ListWznmQVecATitle();

	void clear();

public:
	std::vector<WznmQVecATitle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
