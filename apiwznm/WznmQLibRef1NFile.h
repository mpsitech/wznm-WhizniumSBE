/**
	* \file WznmQLibRef1NFile.h
	* API code for table TblWznmQLibRef1NFile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQLIBREF1NFILE_H
#define WZNMQLIBREF1NFILE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQLibRef1NFile
	*/
class WznmQLibRef1NFile {

public:
	WznmQLibRef1NFile(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQLibRef1NFile
	*/
class ListWznmQLibRef1NFile {

public:
	ListWznmQLibRef1NFile();
	ListWznmQLibRef1NFile(const ListWznmQLibRef1NFile& src);
	ListWznmQLibRef1NFile& operator=(const ListWznmQLibRef1NFile& src);
	~ListWznmQLibRef1NFile();

	void clear();

public:
	std::vector<WznmQLibRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

