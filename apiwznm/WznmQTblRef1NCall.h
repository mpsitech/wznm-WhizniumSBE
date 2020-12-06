/**
	* \file WznmQTblRef1NCall.h
	* API code for table TblWznmQTblRef1NCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLREF1NCALL_H
#define WZNMQTBLREF1NCALL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblRef1NCall
	*/
class WznmQTblRef1NCall {

public:
	WznmQTblRef1NCall(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblRef1NCall
	*/
class ListWznmQTblRef1NCall {

public:
	ListWznmQTblRef1NCall();
	ListWznmQTblRef1NCall(const ListWznmQTblRef1NCall& src);
	ListWznmQTblRef1NCall& operator=(const ListWznmQTblRef1NCall& src);
	~ListWznmQTblRef1NCall();

	void clear();

public:
	std::vector<WznmQTblRef1NCall*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
