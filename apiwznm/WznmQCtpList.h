/**
	* \file WznmQCtpList.h
	* API code for table TblWznmQCtpList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCTPLIST_H
#define WZNMQCTPLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCtpList
	*/
class WznmQCtpList {

public:
	WznmQCtpList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubRefWznmMVersion = "", const std::string srefsIxWArtefact = "", const std::string titsIxWArtefact = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubRefWznmMVersion;
	std::string srefsIxWArtefact;
	std::string titsIxWArtefact;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCtpList
	*/
class ListWznmQCtpList {

public:
	ListWznmQCtpList();
	ListWznmQCtpList(const ListWznmQCtpList& src);
	ListWznmQCtpList& operator=(const ListWznmQCtpList& src);
	~ListWznmQCtpList();

	void clear();

public:
	std::vector<WznmQCtpList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

