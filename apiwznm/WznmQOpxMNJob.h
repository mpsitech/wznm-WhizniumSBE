/**
	* \file WznmQOpxMNJob.h
	* API code for table TblWznmQOpxMNJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPXMNJOB_H
#define WZNMQOPXMNJOB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpxMNJob
	*/
class WznmQOpxMNJob {

public:
	WznmQOpxMNJob(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpxMNJob
	*/
class ListWznmQOpxMNJob {

public:
	ListWznmQOpxMNJob();
	ListWznmQOpxMNJob(const ListWznmQOpxMNJob& src);
	ListWznmQOpxMNJob& operator=(const ListWznmQOpxMNJob& src);
	~ListWznmQOpxMNJob();

	void clear();

public:
	std::vector<WznmQOpxMNJob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

