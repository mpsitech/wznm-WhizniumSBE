/**
	* \file WznmQOpkMNJob.h
	* API code for table TblWznmQOpkMNJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPKMNJOB_H
#define WZNMQOPKMNJOB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQOpkMNJob
	*/
class WznmQOpkMNJob {

public:
	WznmQOpkMNJob(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQOpkMNJob
	*/
class ListWznmQOpkMNJob {

public:
	ListWznmQOpkMNJob();
	ListWznmQOpkMNJob(const ListWznmQOpkMNJob& src);
	ListWznmQOpkMNJob& operator=(const ListWznmQOpkMNJob& src);
	~ListWznmQOpkMNJob();

	void clear();

public:
	std::vector<WznmQOpkMNJob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

