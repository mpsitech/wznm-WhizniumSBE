/**
	* \file WznmQSeqList.h
	* API code for table TblWznmQSeqList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSEQLIST_H
#define WZNMQSEQLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSeqList
	*/
class WznmQSeqList {

public:
	WznmQSeqList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubAppRefWznmMApp = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubAppRefWznmMApp;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSeqList
	*/
class ListWznmQSeqList {

public:
	ListWznmQSeqList();
	ListWznmQSeqList(const ListWznmQSeqList& src);
	ListWznmQSeqList& operator=(const ListWznmQSeqList& src);
	~ListWznmQSeqList();

	void clear();

public:
	std::vector<WznmQSeqList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

