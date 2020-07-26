/**
	* \file WznmQSbsATitle.h
	* API code for table TblWznmQSbsATitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQSBSATITLE_H
#define WZNMQSBSATITLE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSbsATitle
	*/
class WznmQSbsATitle {

public:
	WznmQSbsATitle(const Sbecore::uint jnum = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const std::string stubX2RefWznmMLocale = "", const std::string srefIxWznmVGender = "", const std::string titIxWznmVGender = "", const std::string Title = "");

public:
	Sbecore::uint jnum;
	std::string srefX1IxVType;
	std::string titX1IxVType;
	std::string stubX2RefWznmMLocale;
	std::string srefIxWznmVGender;
	std::string titIxWznmVGender;
	std::string Title;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSbsATitle
	*/
class ListWznmQSbsATitle {

public:
	ListWznmQSbsATitle();
	ListWznmQSbsATitle(const ListWznmQSbsATitle& src);
	ListWznmQSbsATitle& operator=(const ListWznmQSbsATitle& src);
	~ListWznmQSbsATitle();

	void clear();

public:
	std::vector<WznmQSbsATitle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

