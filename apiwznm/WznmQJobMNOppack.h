/**
	* \file WznmQJobMNOppack.h
	* API code for table TblWznmQJobMNOppack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQJOBMNOPPACK_H
#define WZNMQJOBMNOPPACK_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobMNOppack
	*/
class WznmQJobMNOppack {

public:
	WznmQJobMNOppack(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJobMNOppack
	*/
class ListWznmQJobMNOppack {

public:
	ListWznmQJobMNOppack();
	ListWznmQJobMNOppack(const ListWznmQJobMNOppack& src);
	ListWznmQJobMNOppack& operator=(const ListWznmQJobMNOppack& src);
	~ListWznmQJobMNOppack();

	void clear();

public:
	std::vector<WznmQJobMNOppack*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

