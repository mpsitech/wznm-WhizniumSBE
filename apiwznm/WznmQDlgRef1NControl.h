/**
	* \file WznmQDlgRef1NControl.h
	* API code for table TblWznmQDlgRef1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQDLGREF1NCONTROL_H
#define WZNMQDLGREF1NCONTROL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQDlgRef1NControl
	*/
class WznmQDlgRef1NControl {

public:
	WznmQDlgRef1NControl(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQDlgRef1NControl
	*/
class ListWznmQDlgRef1NControl {

public:
	ListWznmQDlgRef1NControl();
	ListWznmQDlgRef1NControl(const ListWznmQDlgRef1NControl& src);
	ListWznmQDlgRef1NControl& operator=(const ListWznmQDlgRef1NControl& src);
	~ListWznmQDlgRef1NControl();

	void clear();

public:
	std::vector<WznmQDlgRef1NControl*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
