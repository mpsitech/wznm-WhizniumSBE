/**
	* \file WznmQTblRef1NCall.h
	* API code for table TblWznmQTblRef1NCall (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

