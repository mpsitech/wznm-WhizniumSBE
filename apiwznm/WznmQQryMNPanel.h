/**
	* \file WznmQQryMNPanel.h
	* API code for table TblWznmQQryMNPanel (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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
