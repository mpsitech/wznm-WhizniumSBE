/**
	* \file WznmQMtyAMakefile.h
	* API code for table TblWznmQMtyAMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQMTYAMAKEFILE_H
#define WZNMQMTYAMAKEFILE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQMtyAMakefile
	*/
class WznmQMtyAMakefile {

public:
	WznmQMtyAMakefile(const Sbecore::uint jnum = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKTag;
	std::string titX1SrefKTag;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQMtyAMakefile
	*/
class ListWznmQMtyAMakefile {

public:
	ListWznmQMtyAMakefile();
	ListWznmQMtyAMakefile(const ListWznmQMtyAMakefile& src);
	ListWznmQMtyAMakefile& operator=(const ListWznmQMtyAMakefile& src);
	~ListWznmQMtyAMakefile();

	void clear();

public:
	std::vector<WznmQMtyAMakefile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

