/**
	* \file WznmQOpkMNJob.h
	* API code for table TblWznmQOpkMNJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

