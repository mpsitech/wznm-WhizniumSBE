/**
	* \file WznmQTblALoadfct.h
	* API code for table TblWznmQTblALoadfct (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTBLALOADFCT_H
#define WZNMQTBLALOADFCT_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblALoadfct
	*/
class WznmQTblALoadfct {

public:
	WznmQTblALoadfct(const Sbecore::uint jnum = 0, const std::string srefIxVLoadtype = "", const std::string titIxVLoadtype = "", const std::string Fctname = "", const std::string ldSrefWznmMTablecol = "", const std::string lbySrefsWznmMTablecol = "", const std::string ordSrefsWznmMTablecol = "", const std::string srefIxVLimtype = "", const std::string titIxVLimtype = "");

public:
	Sbecore::uint jnum;
	std::string srefIxVLoadtype;
	std::string titIxVLoadtype;
	std::string Fctname;
	std::string ldSrefWznmMTablecol;
	std::string lbySrefsWznmMTablecol;
	std::string ordSrefsWznmMTablecol;
	std::string srefIxVLimtype;
	std::string titIxVLimtype;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblALoadfct
	*/
class ListWznmQTblALoadfct {

public:
	ListWznmQTblALoadfct();
	ListWznmQTblALoadfct(const ListWznmQTblALoadfct& src);
	ListWznmQTblALoadfct& operator=(const ListWznmQTblALoadfct& src);
	~ListWznmQTblALoadfct();

	void clear();

public:
	std::vector<WznmQTblALoadfct*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

