/**
	* \file WznmQCapList.h
	* API code for table TblWznmQCapList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQCAPLIST_H
#define WZNMQCAPLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCapList
	*/
class WznmQCapList {

public:
	WznmQCapList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubRefWznmMVersion = "", const std::string stubTplRefWznmMCapability = "", const std::string srefsIxWArtefact = "", const std::string titsIxWArtefact = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubRefWznmMVersion;
	std::string stubTplRefWznmMCapability;
	std::string srefsIxWArtefact;
	std::string titsIxWArtefact;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCapList
	*/
class ListWznmQCapList {

public:
	ListWznmQCapList();
	ListWznmQCapList(const ListWznmQCapList& src);
	ListWznmQCapList& operator=(const ListWznmQCapList& src);
	~ListWznmQCapList();

	void clear();

public:
	std::vector<WznmQCapList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

