/**
	* \file WznmQMdlMdl1NCard.h
	* API code for table TblWznmQMdlMdl1NCard (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMDLMDL1NCARD_H
#define WZNMQMDLMDL1NCARD_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMdlMdl1NCard
	*/
class WznmQMdlMdl1NCard {

public:
	WznmQMdlMdl1NCard(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMdlMdl1NCard
	*/
class ListWznmQMdlMdl1NCard {

public:
	ListWznmQMdlMdl1NCard();
	ListWznmQMdlMdl1NCard(const ListWznmQMdlMdl1NCard& src);
	ListWznmQMdlMdl1NCard& operator=(const ListWznmQMdlMdl1NCard& src);
	~ListWznmQMdlMdl1NCard();

	void clear();

public:
	std::vector<WznmQMdlMdl1NCard*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

