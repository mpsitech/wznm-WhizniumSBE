/**
	* \file WznmQJobJob1NStage.h
	* API code for table TblWznmQJobJob1NStage (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBJOB1NSTAGE_H
#define WZNMQJOBJOB1NSTAGE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobJob1NStage
	*/
class WznmQJobJob1NStage {

public:
	WznmQJobJob1NStage(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJobJob1NStage
	*/
class ListWznmQJobJob1NStage {

public:
	ListWznmQJobJob1NStage();
	ListWznmQJobJob1NStage(const ListWznmQJobJob1NStage& src);
	ListWznmQJobJob1NStage& operator=(const ListWznmQJobJob1NStage& src);
	~ListWznmQJobJob1NStage();

	void clear();

public:
	std::vector<WznmQJobJob1NStage*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
