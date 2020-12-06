/**
	* \file WznmQCalList.h
	* API code for table TblWznmQCalList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCALLIST_H
#define WZNMQCALLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCalList
	*/
class WznmQCalList {

public:
	WznmQCalList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMVersion = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string srefsInvIxWznmWArgtype = "", const std::string titsInvIxWznmWArgtype = "", const std::string srefsRetIxWznmWArgtype = "", const std::string titsRetIxWznmWArgtype = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMVersion;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string srefsInvIxWznmWArgtype;
	std::string titsInvIxWznmWArgtype;
	std::string srefsRetIxWznmWArgtype;
	std::string titsRetIxWznmWArgtype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCalList
	*/
class ListWznmQCalList {

public:
	ListWznmQCalList();
	ListWznmQCalList(const ListWznmQCalList& src);
	ListWznmQCalList& operator=(const ListWznmQCalList& src);
	~ListWznmQCalList();

	void clear();

public:
	std::vector<WznmQCalList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
