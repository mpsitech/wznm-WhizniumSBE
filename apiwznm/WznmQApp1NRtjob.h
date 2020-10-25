/**
	* \file WznmQApp1NRtjob.h
	* API code for table TblWznmQApp1NRtjob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQAPP1NRTJOB_H
#define WZNMQAPP1NRTJOB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQApp1NRtjob
	*/
class WznmQApp1NRtjob {

public:
	WznmQApp1NRtjob(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQApp1NRtjob
	*/
class ListWznmQApp1NRtjob {

public:
	ListWznmQApp1NRtjob();
	ListWznmQApp1NRtjob(const ListWznmQApp1NRtjob& src);
	ListWznmQApp1NRtjob& operator=(const ListWznmQApp1NRtjob& src);
	~ListWznmQApp1NRtjob();

	void clear();

public:
	std::vector<WznmQApp1NRtjob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

