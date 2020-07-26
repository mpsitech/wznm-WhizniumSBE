/**
	* \file WznmQDlgList.h
	* API code for table TblWznmQDlgList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQDLGLIST_H
#define WZNMQDLGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQDlgList
	*/
class WznmQDlgList {

public:
	WznmQDlgList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMCard = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMCard;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQDlgList
	*/
class ListWznmQDlgList {

public:
	ListWznmQDlgList();
	ListWznmQDlgList(const ListWznmQDlgList& src);
	ListWznmQDlgList& operator=(const ListWznmQDlgList& src);
	~ListWznmQDlgList();

	void clear();

public:
	std::vector<WznmQDlgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

