/**
	* \file WznmQCtpTpl1NCapability.h
	* API code for table TblWznmQCtpTpl1NCapability (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQCTPTPL1NCAPABILITY_H
#define WZNMQCTPTPL1NCAPABILITY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCtpTpl1NCapability
	*/
class WznmQCtpTpl1NCapability {

public:
	WznmQCtpTpl1NCapability(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCtpTpl1NCapability
	*/
class ListWznmQCtpTpl1NCapability {

public:
	ListWznmQCtpTpl1NCapability();
	ListWznmQCtpTpl1NCapability(const ListWznmQCtpTpl1NCapability& src);
	ListWznmQCtpTpl1NCapability& operator=(const ListWznmQCtpTpl1NCapability& src);
	~ListWznmQCtpTpl1NCapability();

	void clear();

public:
	std::vector<WznmQCtpTpl1NCapability*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

