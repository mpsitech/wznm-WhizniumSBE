/**
	* \file WznmQJob1NRtjob.h
	* API code for table TblWznmQJob1NRtjob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

