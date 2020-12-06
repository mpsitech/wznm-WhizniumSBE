/**
	* \file WznmQQryMNDialog.h
	* API code for table TblWznmQQryMNDialog (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRYMNDIALOG_H
#define WZNMQQRYMNDIALOG_H

#include <sbecore/Xmlio.h>

/**
	* WznmQQryMNDialog
	*/
class WznmQQryMNDialog {

public:
	WznmQQryMNDialog(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQQryMNDialog
	*/
class ListWznmQQryMNDialog {

public:
	ListWznmQQryMNDialog();
	ListWznmQQryMNDialog(const ListWznmQQryMNDialog& src);
	ListWznmQQryMNDialog& operator=(const ListWznmQQryMNDialog& src);
	~ListWznmQQryMNDialog();

	void clear();

public:
	std::vector<WznmQQryMNDialog*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
