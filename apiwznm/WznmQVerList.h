/**
	* \file WznmQVerList.h
	* API code for table TblWznmQVerList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

