/**
	* \file WznmQCal1NSensitivity.h
	* API code for table TblWznmQCal1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCAL1NSENSITIVITY_H
#define WZNMQCAL1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCal1NSensitivity
	*/
class WznmQCal1NSensitivity {

public:
	WznmQCal1NSensitivity(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCal1NSensitivity
	*/
class ListWznmQCal1NSensitivity {

public:
	ListWznmQCal1NSensitivity();
	ListWznmQCal1NSensitivity(const ListWznmQCal1NSensitivity& src);
	ListWznmQCal1NSensitivity& operator=(const ListWznmQCal1NSensitivity& src);
	~ListWznmQCal1NSensitivity();

	void clear();

public:
	std::vector<WznmQCal1NSensitivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
