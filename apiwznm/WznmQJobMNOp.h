/**
	* \file WznmQJobMNOp.h
	* API code for table TblWznmQJobMNOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBMNOP_H
#define WZNMQJOBMNOP_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobMNOp
	*/
class WznmQJobMNOp {

public:
	WznmQJobMNOp(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJobMNOp
	*/
class ListWznmQJobMNOp {

public:
	ListWznmQJobMNOp();
	ListWznmQJobMNOp(const ListWznmQJobMNOp& src);
	ListWznmQJobMNOp& operator=(const ListWznmQJobMNOp& src);
	~ListWznmQJobMNOp();

	void clear();

public:
	std::vector<WznmQJobMNOp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
