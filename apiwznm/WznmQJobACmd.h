/**
	* \file WznmQJobACmd.h
	* API code for table TblWznmQJobACmd (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBACMD_H
#define WZNMQJOBACMD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobACmd
	*/
class WznmQJobACmd {

public:
	WznmQJobACmd(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJobACmd
	*/
class ListWznmQJobACmd {

public:
	ListWznmQJobACmd();
	ListWznmQJobACmd(const ListWznmQJobACmd& src);
	ListWznmQJobACmd& operator=(const ListWznmQJobACmd& src);
	~ListWznmQJobACmd();

	void clear();

public:
	std::vector<WznmQJobACmd*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

