/**
	* \file WznmQOpkList.h
	* API code for table TblWznmQOpkList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPKLIST_H
#define WZNMQOPKLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpkList
	*/
class WznmQOpkList {

public:
	WznmQOpkList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMVersion = "", const std::string yesnoShrdat = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMVersion;
	std::string yesnoShrdat;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpkList
	*/
class ListWznmQOpkList {

public:
	ListWznmQOpkList();
	ListWznmQOpkList(const ListWznmQOpkList& src);
	ListWznmQOpkList& operator=(const ListWznmQOpkList& src);
	~ListWznmQOpkList();

	void clear();

public:
	std::vector<WznmQOpkList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
