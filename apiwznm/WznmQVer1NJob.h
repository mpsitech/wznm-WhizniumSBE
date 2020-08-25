/**
	* \file WznmQVer1NJob.h
	* API code for table TblWznmQVer1NJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQVER1NJOB_H
#define WZNMQVER1NJOB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVer1NJob
	*/
class WznmQVer1NJob {

public:
	WznmQVer1NJob(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVer1NJob
	*/
class ListWznmQVer1NJob {

public:
	ListWznmQVer1NJob();
	ListWznmQVer1NJob(const ListWznmQVer1NJob& src);
	ListWznmQVer1NJob& operator=(const ListWznmQVer1NJob& src);
	~ListWznmQVer1NJob();

	void clear();

public:
	std::vector<WznmQVer1NJob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

