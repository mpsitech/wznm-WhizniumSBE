/**
	* \file WznmQSht1NBox.h
	* API code for table TblWznmQSht1NBox (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQSHT1NBOX_H
#define WZNMQSHT1NBOX_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSht1NBox
	*/
class WznmQSht1NBox {

public:
	WznmQSht1NBox(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSht1NBox
	*/
class ListWznmQSht1NBox {

public:
	ListWznmQSht1NBox();
	ListWznmQSht1NBox(const ListWznmQSht1NBox& src);
	ListWznmQSht1NBox& operator=(const ListWznmQSht1NBox& src);
	~ListWznmQSht1NBox();

	void clear();

public:
	std::vector<WznmQSht1NBox*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
