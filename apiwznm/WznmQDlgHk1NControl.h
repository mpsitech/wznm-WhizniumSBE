/**
	* \file WznmQDlgHk1NControl.h
	* API code for table TblWznmQDlgHk1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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
