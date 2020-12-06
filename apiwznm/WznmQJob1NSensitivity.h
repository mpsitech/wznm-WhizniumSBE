/**
	* \file WznmQJob1NSensitivity.h
	* API code for table TblWznmQJob1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOB1NSENSITIVITY_H
#define WZNMQJOB1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJob1NSensitivity
	*/
class WznmQJob1NSensitivity {

public:
	WznmQJob1NSensitivity(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJob1NSensitivity
	*/
class ListWznmQJob1NSensitivity {

public:
	ListWznmQJob1NSensitivity();
	ListWznmQJob1NSensitivity(const ListWznmQJob1NSensitivity& src);
	ListWznmQJob1NSensitivity& operator=(const ListWznmQJob1NSensitivity& src);
	~ListWznmQJob1NSensitivity();

	void clear();

public:
	std::vector<WznmQJob1NSensitivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
