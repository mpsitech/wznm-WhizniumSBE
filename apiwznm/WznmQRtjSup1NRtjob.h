/**
	* \file WznmQRtjSup1NRtjob.h
	* API code for table TblWznmQRtjSup1NRtjob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQRTJSUP1NRTJOB_H
#define WZNMQRTJSUP1NRTJOB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRtjSup1NRtjob
	*/
class WznmQRtjSup1NRtjob {

public:
	WznmQRtjSup1NRtjob(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRtjSup1NRtjob
	*/
class ListWznmQRtjSup1NRtjob {

public:
	ListWznmQRtjSup1NRtjob();
	ListWznmQRtjSup1NRtjob(const ListWznmQRtjSup1NRtjob& src);
	ListWznmQRtjSup1NRtjob& operator=(const ListWznmQRtjSup1NRtjob& src);
	~ListWznmQRtjSup1NRtjob();

	void clear();

public:
	std::vector<WznmQRtjSup1NRtjob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

