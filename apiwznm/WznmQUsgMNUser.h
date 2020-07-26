/**
	* \file WznmQUsgMNUser.h
	* API code for table TblWznmQUsgMNUser (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQUSGMNUSER_H
#define WZNMQUSGMNUSER_H

#include <sbecore/Xmlio.h>

/**
	* WznmQUsgMNUser
	*/
class WznmQUsgMNUser {

public:
	WznmQUsgMNUser(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxWznmVUserlevel;
	std::string titIxWznmVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQUsgMNUser
	*/
class ListWznmQUsgMNUser {

public:
	ListWznmQUsgMNUser();
	ListWznmQUsgMNUser(const ListWznmQUsgMNUser& src);
	ListWznmQUsgMNUser& operator=(const ListWznmQUsgMNUser& src);
	~ListWznmQUsgMNUser();

	void clear();

public:
	std::vector<WznmQUsgMNUser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

