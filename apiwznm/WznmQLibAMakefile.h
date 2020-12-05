/**
	* \file WznmQLibAMakefile.h
	* API code for table TblWznmQLibAMakefile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQLIBAMAKEFILE_H
#define WZNMQLIBAMAKEFILE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLibAMakefile
	*/
class WznmQLibAMakefile {

public:
	WznmQLibAMakefile(const Sbecore::uint jnum = 0, const std::string stubX1RefWznmMMachine = "", const std::string x2SrefKTag = "", const std::string titX2SrefKTag = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string stubX1RefWznmMMachine;
	std::string x2SrefKTag;
	std::string titX2SrefKTag;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQLibAMakefile
	*/
class ListWznmQLibAMakefile {

public:
	ListWznmQLibAMakefile();
	ListWznmQLibAMakefile(const ListWznmQLibAMakefile& src);
	ListWznmQLibAMakefile& operator=(const ListWznmQLibAMakefile& src);
	~ListWznmQLibAMakefile();

	void clear();

public:
	std::vector<WznmQLibAMakefile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

