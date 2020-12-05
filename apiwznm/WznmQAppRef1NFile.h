/**
	* \file WznmQAppRef1NFile.h
	* API code for table TblWznmQAppRef1NFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQAPPREF1NFILE_H
#define WZNMQAPPREF1NFILE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQAppRef1NFile
	*/
class WznmQAppRef1NFile {

public:
	WznmQAppRef1NFile(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQAppRef1NFile
	*/
class ListWznmQAppRef1NFile {

public:
	ListWznmQAppRef1NFile();
	ListWznmQAppRef1NFile(const ListWznmQAppRef1NFile& src);
	ListWznmQAppRef1NFile& operator=(const ListWznmQAppRef1NFile& src);
	~ListWznmQAppRef1NFile();

	void clear();

public:
	std::vector<WznmQAppRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

