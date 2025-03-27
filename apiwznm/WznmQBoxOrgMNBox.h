/**
	* \file WznmQBoxOrgMNBox.h
	* API code for table TblWznmQBoxOrgMNBox (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQBOXORGMNBOX_H
#define WZNMQBOXORGMNBOX_H

#include <sbecore/Xmlio.h>

/**
	* WznmQBoxOrgMNBox
	*/
class WznmQBoxOrgMNBox {

public:
	WznmQBoxOrgMNBox(const Sbecore::uint jnum = 0, const std::string stubMref = "", const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);

public:
	Sbecore::uint jnum;
	std::string stubMref;
	Sbecore::utinyint orgClk;
	Sbecore::utinyint dstClk;
	Sbecore::utinyint Weight;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQBoxOrgMNBox
	*/
class ListWznmQBoxOrgMNBox {

public:
	ListWznmQBoxOrgMNBox();
	ListWznmQBoxOrgMNBox(const ListWznmQBoxOrgMNBox& src);
	ListWznmQBoxOrgMNBox& operator=(const ListWznmQBoxOrgMNBox& src);
	~ListWznmQBoxOrgMNBox();

	void clear();

public:
	std::vector<WznmQBoxOrgMNBox*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
