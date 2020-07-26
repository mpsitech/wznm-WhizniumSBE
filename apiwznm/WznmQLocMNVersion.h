/**
	* \file WznmQLocMNVersion.h
	* API code for table TblWznmQLocMNVersion (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQLOCMNVERSION_H
#define WZNMQLOCMNVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLocMNVersion
	*/
class WznmQLocMNVersion {

public:
	WznmQLocMNVersion(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQLocMNVersion
	*/
class ListWznmQLocMNVersion {

public:
	ListWznmQLocMNVersion();
	ListWznmQLocMNVersion(const ListWznmQLocMNVersion& src);
	ListWznmQLocMNVersion& operator=(const ListWznmQLocMNVersion& src);
	~ListWznmQLocMNVersion();

	void clear();

public:
	std::vector<WznmQLocMNVersion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

