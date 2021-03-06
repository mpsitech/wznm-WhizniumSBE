/**
	* \file WznmQIelList.h
	* API code for table TblWznmQIelList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIELLIST_H
#define WZNMQIELLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQIelList
	*/
class WznmQIelList {

public:
	WznmQIelList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Short = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubImeRefWznmMImpexp = "", const std::string stubRefWznmMTablecol = "", const std::string srefIxVConvtype = "", const std::string titIxVConvtype = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Short;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubImeRefWznmMImpexp;
	std::string stubRefWznmMTablecol;
	std::string srefIxVConvtype;
	std::string titIxVConvtype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQIelList
	*/
class ListWznmQIelList {

public:
	ListWznmQIelList();
	ListWznmQIelList(const ListWznmQIelList& src);
	ListWznmQIelList& operator=(const ListWznmQIelList& src);
	~ListWznmQIelList();

	void clear();

public:
	std::vector<WznmQIelList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
