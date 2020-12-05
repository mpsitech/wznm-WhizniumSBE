/**
	* \file WznmQRelRef1NDialog.h
	* API code for table TblWznmQRelRef1NDialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRELREF1NDIALOG_H
#define WZNMQRELREF1NDIALOG_H

#include <sbecore/Xmlio.h>

/**
	* WznmQRelRef1NDialog
	*/
class WznmQRelRef1NDialog {

public:
	WznmQRelRef1NDialog(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQRelRef1NDialog
	*/
class ListWznmQRelRef1NDialog {

public:
	ListWznmQRelRef1NDialog();
	ListWznmQRelRef1NDialog(const ListWznmQRelRef1NDialog& src);
	ListWznmQRelRef1NDialog& operator=(const ListWznmQRelRef1NDialog& src);
	~ListWznmQRelRef1NDialog();

	void clear();

public:
	std::vector<WznmQRelRef1NDialog*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

