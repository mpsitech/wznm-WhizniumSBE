/**
	* \file WznmQIexRef1NDialog.h
	* API code for table TblWznmQIexRef1NDialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIEXREF1NDIALOG_H
#define WZNMQIEXREF1NDIALOG_H

#include <sbecore/Xmlio.h>

/**
	* WznmQIexRef1NDialog
	*/
class WznmQIexRef1NDialog {

public:
	WznmQIexRef1NDialog(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQIexRef1NDialog
	*/
class ListWznmQIexRef1NDialog {

public:
	ListWznmQIexRef1NDialog();
	ListWznmQIexRef1NDialog(const ListWznmQIexRef1NDialog& src);
	ListWznmQIexRef1NDialog& operator=(const ListWznmQIexRef1NDialog& src);
	~ListWznmQIexRef1NDialog();

	void clear();

public:
	std::vector<WznmQIexRef1NDialog*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

