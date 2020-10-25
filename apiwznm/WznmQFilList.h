/**
	* \file WznmQFilList.h
	* API code for table TblWznmQFilList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQFILLIST_H
#define WZNMQFILLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQFilList
	*/
class WznmQFilList {

public:
	WznmQFilList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Filename = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::uint Size = 0);

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Filename;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string osrefKContent;
	std::string titOsrefKContent;
	std::string srefKMimetype;
	std::string titSrefKMimetype;
	Sbecore::uint Size;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQFilList
	*/
class ListWznmQFilList {

public:
	ListWznmQFilList();
	ListWznmQFilList(const ListWznmQFilList& src);
	ListWznmQFilList& operator=(const ListWznmQFilList& src);
	~ListWznmQFilList();

	void clear();

public:
	std::vector<WznmQFilList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

