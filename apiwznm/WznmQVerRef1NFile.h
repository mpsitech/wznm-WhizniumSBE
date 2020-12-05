/**
	* \file WznmQVerRef1NFile.h
	* API code for table TblWznmQVerRef1NFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVERREF1NFILE_H
#define WZNMQVERREF1NFILE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQVerRef1NFile
	*/
class WznmQVerRef1NFile {

public:
	WznmQVerRef1NFile(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQVerRef1NFile
	*/
class ListWznmQVerRef1NFile {

public:
	ListWznmQVerRef1NFile();
	ListWznmQVerRef1NFile(const ListWznmQVerRef1NFile& src);
	ListWznmQVerRef1NFile& operator=(const ListWznmQVerRef1NFile& src);
	~ListWznmQVerRef1NFile();

	void clear();

public:
	std::vector<WznmQVerRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

