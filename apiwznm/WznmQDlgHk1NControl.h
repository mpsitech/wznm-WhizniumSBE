/**
	* \file WznmQDlgHk1NControl.h
	* API code for table TblWznmQDlgHk1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQDLGHK1NCONTROL_H
#define WZNMQDLGHK1NCONTROL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQDlgHk1NControl
	*/
class WznmQDlgHk1NControl {

public:
	WznmQDlgHk1NControl(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQDlgHk1NControl
	*/
class ListWznmQDlgHk1NControl {

public:
	ListWznmQDlgHk1NControl();
	ListWznmQDlgHk1NControl(const ListWznmQDlgHk1NControl& src);
	ListWznmQDlgHk1NControl& operator=(const ListWznmQDlgHk1NControl& src);
	~ListWznmQDlgHk1NControl();

	void clear();

public:
	std::vector<WznmQDlgHk1NControl*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

