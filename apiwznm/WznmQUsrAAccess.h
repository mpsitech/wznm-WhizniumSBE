/**
	* \file WznmQUsrAAccess.h
	* API code for table TblWznmQUsrAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSRAACCESS_H
#define WZNMQUSRAACCESS_H

#include <sbecore/Xmlio.h>

/**
	* WznmQUsrAAccess
	*/
class WznmQUsrAAccess {

public:
	WznmQUsrAAccess(const Sbecore::uint jnum = 0, const std::string srefX1IxWznmVFeatgroup = "", const std::string titX1IxWznmVFeatgroup = "", const std::string x2FeaSrefUix = "", const std::string srefsIxWznmWAccess = "", const std::string titsIxWznmWAccess = "");

public:
	Sbecore::uint jnum;
	std::string srefX1IxWznmVFeatgroup;
	std::string titX1IxWznmVFeatgroup;
	std::string x2FeaSrefUix;
	std::string srefsIxWznmWAccess;
	std::string titsIxWznmWAccess;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQUsrAAccess
	*/
class ListWznmQUsrAAccess {

public:
	ListWznmQUsrAAccess();
	ListWznmQUsrAAccess(const ListWznmQUsrAAccess& src);
	ListWznmQUsrAAccess& operator=(const ListWznmQUsrAAccess& src);
	~ListWznmQUsrAAccess();

	void clear();

public:
	std::vector<WznmQUsrAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
