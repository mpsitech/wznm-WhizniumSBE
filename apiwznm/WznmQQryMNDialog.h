/**
	* \file WznmQQryMNDialog.h
	* API code for table TblWznmQQryMNDialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

