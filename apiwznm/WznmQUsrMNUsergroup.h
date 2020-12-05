/**
	* \file WznmQUsrMNUsergroup.h
	* API code for table TblWznmQUsrMNUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSRMNUSERGROUP_H
#define WZNMQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

/**
	* WznmQUsrMNUsergroup
	*/
class WznmQUsrMNUsergroup {

public:
	WznmQUsrMNUsergroup(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxWznmVUserlevel;
	std::string titIxWznmVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQUsrMNUsergroup
	*/
class ListWznmQUsrMNUsergroup {

public:
	ListWznmQUsrMNUsergroup();
	ListWznmQUsrMNUsergroup(const ListWznmQUsrMNUsergroup& src);
	ListWznmQUsrMNUsergroup& operator=(const ListWznmQUsrMNUsergroup& src);
	~ListWznmQUsrMNUsergroup();

	void clear();

public:
	std::vector<WznmQUsrMNUsergroup*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

