/**
	* \file WznmQQryAOrder.h
	* API code for table TblWznmQQryAOrder (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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
