/**
	* \file WznmQVerRef1NFile.h
	* API code for table TblWznmQVerRef1NFile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

