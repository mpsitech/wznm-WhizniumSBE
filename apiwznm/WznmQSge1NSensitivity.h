/**
	* \file WznmQSge1NSensitivity.h
	* API code for table TblWznmQSge1NSensitivity (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQSGE1NSENSITIVITY_H
#define WZNMQSGE1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSge1NSensitivity
	*/
class WznmQSge1NSensitivity {

public:
	WznmQSge1NSensitivity(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSge1NSensitivity
	*/
class ListWznmQSge1NSensitivity {

public:
	ListWznmQSge1NSensitivity();
	ListWznmQSge1NSensitivity(const ListWznmQSge1NSensitivity& src);
	ListWznmQSge1NSensitivity& operator=(const ListWznmQSge1NSensitivity& src);
	~ListWznmQSge1NSensitivity();

	void clear();

public:
	std::vector<WznmQSge1NSensitivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

