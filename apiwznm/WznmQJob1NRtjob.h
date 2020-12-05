/**
	* \file WznmQJob1NRtjob.h
	* API code for table TblWznmQJob1NRtjob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOB1NRTJOB_H
#define WZNMQJOB1NRTJOB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJob1NRtjob
	*/
class WznmQJob1NRtjob {

public:
	WznmQJob1NRtjob(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJob1NRtjob
	*/
class ListWznmQJob1NRtjob {

public:
	ListWznmQJob1NRtjob();
	ListWznmQJob1NRtjob(const ListWznmQJob1NRtjob& src);
	ListWznmQJob1NRtjob& operator=(const ListWznmQJob1NRtjob& src);
	~ListWznmQJob1NRtjob();

	void clear();

public:
	std::vector<WznmQJob1NRtjob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

