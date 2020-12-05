/**
	* \file WznmQJobSubMNJob.h
	* API code for table TblWznmQJobSubMNJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBSUBMNJOB_H
#define WZNMQJOBSUBMNJOB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobSubMNJob
	*/
class WznmQJobSubMNJob {

public:
	WznmQJobSubMNJob(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string Short = "", const std::string yesnoMulti = "", const std::string srefIxVConstract = "", const std::string titIxVConstract = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string Short;
	std::string yesnoMulti;
	std::string srefIxVConstract;
	std::string titIxVConstract;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJobSubMNJob
	*/
class ListWznmQJobSubMNJob {

public:
	ListWznmQJobSubMNJob();
	ListWznmQJobSubMNJob(const ListWznmQJobSubMNJob& src);
	ListWznmQJobSubMNJob& operator=(const ListWznmQJobSubMNJob& src);
	~ListWznmQJobSubMNJob();

	void clear();

public:
	std::vector<WznmQJobSubMNJob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

