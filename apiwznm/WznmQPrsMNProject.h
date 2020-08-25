/**
	* \file WznmQPrsMNProject.h
	* API code for table TblWznmQPrsMNProject (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQPRSMNPROJECT_H
#define WZNMQPRSMNPROJECT_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPrsMNProject
	*/
class WznmQPrsMNProject {

public:
	WznmQPrsMNProject(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string ftmX1Startd = "", const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

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
	* ListWznmQPrsMNProject
	*/
class ListWznmQPrsMNProject {

public:
	ListWznmQPrsMNProject();
	ListWznmQPrsMNProject(const ListWznmQPrsMNProject& src);
	ListWznmQPrsMNProject& operator=(const ListWznmQPrsMNProject& src);
	~ListWznmQPrsMNProject();

	void clear();

public:
	std::vector<WznmQPrsMNProject*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

