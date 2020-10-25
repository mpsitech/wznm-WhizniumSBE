/**
	* \file WznmQTblRef1NDialog.h
	* API code for table TblWznmQTblRef1NDialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

