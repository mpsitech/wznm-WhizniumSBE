/**
	* \file WznmQQryAOrder.h
	* API code for table TblWznmQQryAOrder (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQQRYAORDER_H
#define WZNMQQRYAORDER_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQryAOrder
	*/
class WznmQQryAOrder {

public:
	WznmQQryAOrder(const Sbecore::uint jnum = 0, const std::string Short = "", const std::string srefsWznmMTablecol = "");

public:
	Sbecore::uint jnum;
	std::string Short;
	std::string srefsWznmMTablecol;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQryAOrder
	*/
class ListWznmQQryAOrder {

public:
	ListWznmQQryAOrder();
	ListWznmQQryAOrder(const ListWznmQQryAOrder& src);
	ListWznmQQryAOrder& operator=(const ListWznmQQryAOrder& src);
	~ListWznmQQryAOrder();

	void clear();

public:
	std::vector<WznmQQryAOrder*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

