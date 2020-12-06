/**
	* \file WznmQPrj1NVersion.h
	* API code for table TblWznmQPrj1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRJ1NVERSION_H
#define WZNMQPRJ1NVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPrj1NVersion
	*/
class WznmQPrj1NVersion {

public:
	WznmQPrj1NVersion(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPrj1NVersion
	*/
class ListWznmQPrj1NVersion {

public:
	ListWznmQPrj1NVersion();
	ListWznmQPrj1NVersion(const ListWznmQPrj1NVersion& src);
	ListWznmQPrj1NVersion& operator=(const ListWznmQPrj1NVersion& src);
	~ListWznmQPrj1NVersion();

	void clear();

public:
	std::vector<WznmQPrj1NVersion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
