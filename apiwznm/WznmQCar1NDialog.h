/**
	* \file WznmQCar1NDialog.h
	* API code for table TblWznmQCar1NDialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQCAR1NDIALOG_H
#define WZNMQCAR1NDIALOG_H

#include <sbecore/Xmlio.h>

/**
	* WznmQCar1NDialog
	*/
class WznmQCar1NDialog {

public:
	WznmQCar1NDialog(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQCar1NDialog
	*/
class ListWznmQCar1NDialog {

public:
	ListWznmQCar1NDialog();
	ListWznmQCar1NDialog(const ListWznmQCar1NDialog& src);
	ListWznmQCar1NDialog& operator=(const ListWznmQCar1NDialog& src);
	~ListWznmQCar1NDialog();

	void clear();

public:
	std::vector<WznmQCar1NDialog*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

