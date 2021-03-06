/**
	* \file WznmQJobSupMNJob.h
	* API code for table TblWznmQJobSupMNJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBSUPMNJOB_H
#define WZNMQJOBSUPMNJOB_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobSupMNJob
	*/
class WznmQJobSupMNJob {

public:
	WznmQJobSupMNJob(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string Short = "", const std::string yesnoMulti = "", const std::string srefIxVConstract = "", const std::string titIxVConstract = "");

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
	* ListWznmQJobSupMNJob
	*/
class ListWznmQJobSupMNJob {

public:
	ListWznmQJobSupMNJob();
	ListWznmQJobSupMNJob(const ListWznmQJobSupMNJob& src);
	ListWznmQJobSupMNJob& operator=(const ListWznmQJobSupMNJob& src);
	~ListWznmQJobSupMNJob();

	void clear();

public:
	std::vector<WznmQJobSupMNJob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
