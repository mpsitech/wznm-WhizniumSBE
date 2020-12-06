/**
	* \file WznmQUsgAAccess.h
	* API code for table TblWznmQUsgAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSGAACCESS_H
#define WZNMQUSGAACCESS_H

#include <sbecore/Xmlio.h>

/**
	* WznmQUsgAAccess
	*/
class WznmQUsgAAccess {

public:
	WznmQUsgAAccess(const Sbecore::uint jnum = 0, const std::string srefX1IxWznmVFeatgroup = "", const std::string titX1IxWznmVFeatgroup = "", const std::string x2FeaSrefUix = "", const std::string srefsIxWznmWAccess = "", const std::string titsIxWznmWAccess = "");

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
	* ListWznmQUsgAAccess
	*/
class ListWznmQUsgAAccess {

public:
	ListWznmQUsgAAccess();
	ListWznmQUsgAAccess(const ListWznmQUsgAAccess& src);
	ListWznmQUsgAAccess& operator=(const ListWznmQUsgAAccess& src);
	~ListWznmQUsgAAccess();

	void clear();

public:
	std::vector<WznmQUsgAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
