/**
	* \file WznmQAppApp1NSequence.h
	* API code for table TblWznmQAppApp1NSequence (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQAPPAPP1NSEQUENCE_H
#define WZNMQAPPAPP1NSEQUENCE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQAppApp1NSequence
	*/
class WznmQAppApp1NSequence {

public:
	WznmQAppApp1NSequence(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQAppApp1NSequence
	*/
class ListWznmQAppApp1NSequence {

public:
	ListWznmQAppApp1NSequence();
	ListWznmQAppApp1NSequence(const ListWznmQAppApp1NSequence& src);
	ListWznmQAppApp1NSequence& operator=(const ListWznmQAppApp1NSequence& src);
	~ListWznmQAppApp1NSequence();

	void clear();

public:
	std::vector<WznmQAppApp1NSequence*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

