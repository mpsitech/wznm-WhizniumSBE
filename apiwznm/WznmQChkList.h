/**
	* \file WznmQChkList.h
	* API code for table TblWznmQChkList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQCHKLIST_H
#define WZNMQCHKLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQChkList
	*/
class WznmQChkList {

public:
	WznmQChkList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMTable = "", const std::string stubRefWznmMTablecol = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMTable;
	std::string stubRefWznmMTablecol;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQChkList
	*/
class ListWznmQChkList {

public:
	ListWznmQChkList();
	ListWznmQChkList(const ListWznmQChkList& src);
	ListWznmQChkList& operator=(const ListWznmQChkList& src);
	~ListWznmQChkList();

	void clear();

public:
	std::vector<WznmQChkList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

