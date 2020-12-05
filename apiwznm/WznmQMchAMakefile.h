/**
	* \file WznmQMchAMakefile.h
	* API code for table TblWznmQMchAMakefile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMCHAMAKEFILE_H
#define WZNMQMCHAMAKEFILE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMchAMakefile
	*/
class WznmQMchAMakefile {

public:
	WznmQMchAMakefile(const Sbecore::uint jnum = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKTag;
	std::string titX1SrefKTag;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMchAMakefile
	*/
class ListWznmQMchAMakefile {

public:
	ListWznmQMchAMakefile();
	ListWznmQMchAMakefile(const ListWznmQMchAMakefile& src);
	ListWznmQMchAMakefile& operator=(const ListWznmQMchAMakefile& src);
	~ListWznmQMchAMakefile();

	void clear();

public:
	std::vector<WznmQMchAMakefile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

