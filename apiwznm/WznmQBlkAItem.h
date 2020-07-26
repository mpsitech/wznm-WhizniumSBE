/**
	* \file WznmQBlkAItem.h
	* API code for table TblWznmQBlkAItem (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQBLKAITEM_H
#define WZNMQBLKAITEM_H

#include <sbecore/Xmlio.h>

/**
	* WznmQBlkAItem
	*/
class WznmQBlkAItem {

public:
	WznmQBlkAItem(const Sbecore::uint jnum = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string sref = "", const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const std::string stubRefWznmMControl = "", const std::string stubRefWznmMVector = "", const std::string stubRefWznmMFeed = "", const std::string stubRefWznmMTable = "", const std::string stubRefWznmMBlock = "", const std::string Defval = "", const std::string stubRefWznmMVectoritem = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string sref;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	std::string stubRefWznmMControl;
	std::string stubRefWznmMVector;
	std::string stubRefWznmMFeed;
	std::string stubRefWznmMTable;
	std::string stubRefWznmMBlock;
	std::string Defval;
	std::string stubRefWznmMVectoritem;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQBlkAItem
	*/
class ListWznmQBlkAItem {

public:
	ListWznmQBlkAItem();
	ListWznmQBlkAItem(const ListWznmQBlkAItem& src);
	ListWznmQBlkAItem& operator=(const ListWznmQBlkAItem& src);
	~ListWznmQBlkAItem();

	void clear();

public:
	std::vector<WznmQBlkAItem*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

