/**
	* \file WznmQPrsADetail.h
	* API code for table TblWznmQPrsADetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRSADETAIL_H
#define WZNMQPRSADETAIL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPrsADetail
	*/
class WznmQPrsADetail {

public:
	WznmQPrsADetail(const Sbecore::uint jnum = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKType;
	std::string titX1SrefKType;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPrsADetail
	*/
class ListWznmQPrsADetail {

public:
	ListWznmQPrsADetail();
	ListWznmQPrsADetail(const ListWznmQPrsADetail& src);
	ListWznmQPrsADetail& operator=(const ListWznmQPrsADetail& src);
	~ListWznmQPrsADetail();

	void clear();

public:
	std::vector<WznmQPrsADetail*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
