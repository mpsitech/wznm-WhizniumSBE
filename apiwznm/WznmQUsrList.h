/**
	* \file WznmQUsrList.h
	* API code for table TblWznmQUsrList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQUSRLIST_H
#define WZNMQUSRLIST_H

#include <sbecore/Xmlio.h>

/**
	* WznmQUsrList
	*/
class WznmQUsrList {

public:
	WznmQUsrList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string stubRefWznmMPerson = "", const std::string sref = "", const std::string stubRefWznmMUsergroup = "", const std::string srefIxVState = "", const std::string titIxVState = "", const std::string srefIxWznmVLocale = "", const std::string titIxWznmVLocale = "", const std::string srefIxWznmVUserlevel = "", const std::string titIxWznmVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string stubRefWznmMPerson;
	std::string sref;
	std::string stubRefWznmMUsergroup;
	std::string srefIxVState;
	std::string titIxVState;
	std::string srefIxWznmVLocale;
	std::string titIxWznmVLocale;
	std::string srefIxWznmVUserlevel;
	std::string titIxWznmVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQUsrList
	*/
class ListWznmQUsrList {

public:
	ListWznmQUsrList();
	ListWznmQUsrList(const ListWznmQUsrList& src);
	ListWznmQUsrList& operator=(const ListWznmQUsrList& src);
	~ListWznmQUsrList();

	void clear();

public:
	std::vector<WznmQUsrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

