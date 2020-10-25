/**
	* \file WznmQTblATitle.h
	* API code for table TblWznmQTblATitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTBLATITLE_H
#define WZNMQTBLATITLE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblATitle
	*/
class WznmQTblATitle {

public:
	WznmQTblATitle(const Sbecore::uint jnum = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const std::string stubX2RefWznmMLocale = "", const std::string srefIxWznmVGender = "", const std::string titIxWznmVGender = "", const std::string Title = "");

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
	* ListWznmQTblATitle
	*/
class ListWznmQTblATitle {

public:
	ListWznmQTblATitle();
	ListWznmQTblATitle(const ListWznmQTblATitle& src);
	ListWznmQTblATitle& operator=(const ListWznmQTblATitle& src);
	~ListWznmQTblATitle();

	void clear();

public:
	std::vector<WznmQTblATitle*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

