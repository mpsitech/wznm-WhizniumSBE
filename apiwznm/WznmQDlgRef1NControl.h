/**
	* \file WznmQDlgRef1NControl.h
	* API code for table TblWznmQDlgRef1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

