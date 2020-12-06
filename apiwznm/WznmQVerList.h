/**
	* \file WznmQVerList.h
	* API code for table TblWznmQVerList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVERLIST_H
#define WZNMQVERLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVerList
	*/
class WznmQVerList {

public:
	WznmQVerList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string stubPrjRefWznmMProject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const std::string stubBvrRefWznmMVersion = "", const std::string stubRefWznmMLocale = "", const std::string srefIxVState = "", const std::string titIxVState = "", const std::string srefsIxWDbmstype = "", const std::string titsIxWDbmstype = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string stubPrjRefWznmMProject;
	Sbecore::usmallint Major;
	Sbecore::usmallint Minor;
	Sbecore::usmallint Sub;
	std::string stubBvrRefWznmMVersion;
	std::string stubRefWznmMLocale;
	std::string srefIxVState;
	std::string titIxVState;
	std::string srefsIxWDbmstype;
	std::string titsIxWDbmstype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVerList
	*/
class ListWznmQVerList {

public:
	ListWznmQVerList();
	ListWznmQVerList(const ListWznmQVerList& src);
	ListWznmQVerList& operator=(const ListWznmQVerList& src);
	~ListWznmQVerList();

	void clear();

public:
	std::vector<WznmQVerList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
