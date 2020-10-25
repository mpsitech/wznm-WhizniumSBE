/**
	* \file WznmQQryMNPanel.h
	* API code for table TblWznmQQryMNPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQQRYMNPANEL_H
#define WZNMQQRYMNPANEL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQryMNPanel
	*/
class WznmQQryMNPanel {

public:
	WznmQQryMNPanel(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQryMNPanel
	*/
class ListWznmQQryMNPanel {

public:
	ListWznmQQryMNPanel();
	ListWznmQQryMNPanel(const ListWznmQQryMNPanel& src);
	ListWznmQQryMNPanel& operator=(const ListWznmQQryMNPanel& src);
	~ListWznmQQryMNPanel();

	void clear();

public:
	std::vector<WznmQQryMNPanel*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

