/**
	* \file WznmQPrjPrj1NVersion.h
	* API code for table TblWznmQPrjPrj1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRJPRJ1NVERSION_H
#define WZNMQPRJPRJ1NVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPrjPrj1NVersion
	*/
class WznmQPrjPrj1NVersion {

public:
	WznmQPrjPrj1NVersion(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPrjPrj1NVersion
	*/
class ListWznmQPrjPrj1NVersion {

public:
	ListWznmQPrjPrj1NVersion();
	ListWznmQPrjPrj1NVersion(const ListWznmQPrjPrj1NVersion& src);
	ListWznmQPrjPrj1NVersion& operator=(const ListWznmQPrjPrj1NVersion& src);
	~ListWznmQPrjPrj1NVersion();

	void clear();

public:
	std::vector<WznmQPrjPrj1NVersion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
