/**
	* \file WznmQLibAMakefile.h
	* API code for table TblWznmQLibAMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQLIBAMAKEFILE_H
#define WZNMQLIBAMAKEFILE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLibAMakefile
	*/
class WznmQLibAMakefile {

public:
	WznmQLibAMakefile(const Sbecore::uint jnum = 0, const std::string srefX1RefIxVTbl = "", const std::string titX1RefIxVTbl = "", const std::string stubX1RefUref = "", const std::string x2SrefKTag = "", const std::string titX2SrefKTag = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string srefX1RefIxVTbl;
	std::string titX1RefIxVTbl;
	std::string stubX1RefUref;
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

