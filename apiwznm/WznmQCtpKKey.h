/**
	* \file WznmQCtpKKey.h
	* API code for table TblWznmQCtpKKey (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQCTPKKEY_H
#define WZNMQCTPKKEY_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCtpKKey
	*/
class WznmQCtpKKey {

public:
	WznmQCtpKKey(const Sbecore::uint jnum = 0, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string yesnoFixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	std::string Title;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCtpKKey
	*/
class ListWznmQCtpKKey {

public:
	ListWznmQCtpKKey();
	ListWznmQCtpKKey(const ListWznmQCtpKKey& src);
	ListWznmQCtpKKey& operator=(const ListWznmQCtpKKey& src);
	~ListWznmQCtpKKey();

	void clear();

public:
	std::vector<WznmQCtpKKey*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

