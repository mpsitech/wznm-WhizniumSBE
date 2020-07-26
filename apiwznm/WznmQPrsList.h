/**
	* \file WznmQPrsList.h
	* API code for table TblWznmQPrsList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQPRSLIST_H
#define WZNMQPRSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQPrsList
	*/
class WznmQPrsList {

public:
	WznmQPrsList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Title;
	std::string Firstname;
	std::string Lastname;
	std::string srefIxVSex;
	std::string titIxVSex;
	std::string telVal;
	std::string emlVal;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQPrsList
	*/
class ListWznmQPrsList {

public:
	ListWznmQPrsList();
	ListWznmQPrsList(const ListWznmQPrsList& src);
	ListWznmQPrsList& operator=(const ListWznmQPrsList& src);
	~ListWznmQPrsList();

	void clear();

public:
	std::vector<WznmQPrsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

