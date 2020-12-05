/**
	* \file WznmQTblRef1NDialog.h
	* API code for table TblWznmQTblRef1NDialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLREF1NDIALOG_H
#define WZNMQTBLREF1NDIALOG_H

#include <sbecore/Xmlio.h>

/**
	* WznmQTblRef1NDialog
	*/
class WznmQTblRef1NDialog {

public:
	WznmQTblRef1NDialog(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQTblRef1NDialog
	*/
class ListWznmQTblRef1NDialog {

public:
	ListWznmQTblRef1NDialog();
	ListWznmQTblRef1NDialog(const ListWznmQTblRef1NDialog& src);
	ListWznmQTblRef1NDialog& operator=(const ListWznmQTblRef1NDialog& src);
	~ListWznmQTblRef1NDialog();

	void clear();

public:
	std::vector<WznmQTblRef1NDialog*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

