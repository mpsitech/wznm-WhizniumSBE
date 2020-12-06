/**
	* \file WznmQJobList.h
	* API code for table TblWznmQJobList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBLIST_H
#define WZNMQJOBLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobList
	*/
class WznmQJobList {

public:
	WznmQJobList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWznmMVersion = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string yesnoGlobal = "", const std::string yesnoClisrv = "", const std::string yesnoShrdat = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWznmMVersion;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string yesnoGlobal;
	std::string yesnoClisrv;
	std::string yesnoShrdat;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJobList
	*/
class ListWznmQJobList {

public:
	ListWznmQJobList();
	ListWznmQJobList(const ListWznmQJobList& src);
	ListWznmQJobList& operator=(const ListWznmQJobList& src);
	~ListWznmQJobList();

	void clear();

public:
	std::vector<WznmQJobList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
