/**
	* \file WznmQChkRef1NCall.h
	* API code for table TblWznmQChkRef1NCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCHKREF1NCALL_H
#define WZNMQCHKREF1NCALL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQChkRef1NCall
	*/
class WznmQChkRef1NCall {

public:
	WznmQChkRef1NCall(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQChkRef1NCall
	*/
class ListWznmQChkRef1NCall {

public:
	ListWznmQChkRef1NCall();
	ListWznmQChkRef1NCall(const ListWznmQChkRef1NCall& src);
	ListWznmQChkRef1NCall& operator=(const ListWznmQChkRef1NCall& src);
	~ListWznmQChkRef1NCall();

	void clear();

public:
	std::vector<WznmQChkRef1NCall*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

