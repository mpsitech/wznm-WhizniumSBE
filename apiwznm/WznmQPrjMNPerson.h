/**
	* \file WznmQPrjMNPerson.h
	* API code for table TblWznmQPrjMNPerson (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRJMNPERSON_H
#define WZNMQPRJMNPERSON_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPrjMNPerson
	*/
class WznmQPrjMNPerson {

public:
	WznmQPrjMNPerson(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string ftmX1Startd = "", const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string ftmX1Startd;
	std::string ftmX1Stopd;
	std::string srefKFunction;
	std::string titSrefKFunction;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPrjMNPerson
	*/
class ListWznmQPrjMNPerson {

public:
	ListWznmQPrjMNPerson();
	ListWznmQPrjMNPerson(const ListWznmQPrjMNPerson& src);
	ListWznmQPrjMNPerson& operator=(const ListWznmQPrjMNPerson& src);
	~ListWznmQPrjMNPerson();

	void clear();

public:
	std::vector<WznmQPrjMNPerson*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
