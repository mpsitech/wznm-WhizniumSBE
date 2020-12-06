/**
	* \file WznmQCtpKParKey.h
	* API code for table TblWznmQCtpKParKey (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCTPKPARKEY_H
#define WZNMQCTPKPARKEY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCtpKParKey
	*/
class WznmQCtpKParKey {

public:
	WznmQCtpKParKey(const Sbecore::uint jnum = 0, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string yesnoFixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	std::string Title;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCtpKParKey
	*/
class ListWznmQCtpKParKey {

public:
	ListWznmQCtpKParKey();
	ListWznmQCtpKParKey(const ListWznmQCtpKParKey& src);
	ListWznmQCtpKParKey& operator=(const ListWznmQCtpKParKey& src);
	~ListWznmQCtpKParKey();

	void clear();

public:
	std::vector<WznmQCtpKParKey*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
