/**
	* \file WznmQVisRef1NFile.h
	* API code for table TblWznmQVisRef1NFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 29 Dec 2024
  */
// IP header --- ABOVE

#ifndef WZNMQVISREF1NFILE_H
#define WZNMQVISREF1NFILE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVisRef1NFile
	*/
class WznmQVisRef1NFile {

public:
	WznmQVisRef1NFile(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVisRef1NFile
	*/
class ListWznmQVisRef1NFile {

public:
	ListWznmQVisRef1NFile();
	ListWznmQVisRef1NFile(const ListWznmQVisRef1NFile& src);
	ListWznmQVisRef1NFile& operator=(const ListWznmQVisRef1NFile& src);
	~ListWznmQVisRef1NFile();

	void clear();

public:
	std::vector<WznmQVisRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
