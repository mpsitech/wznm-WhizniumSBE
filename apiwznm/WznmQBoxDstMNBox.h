/**
	* \file WznmQBoxDstMNBox.h
	* API code for table TblWznmQBoxDstMNBox (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMQBOXDSTMNBOX_H
#define WZNMQBOXDSTMNBOX_H

#include <sbecore/Xmlio.h>

/**
	* WznmQBoxDstMNBox
	*/
class WznmQBoxDstMNBox {

public:
	WznmQBoxDstMNBox(const Sbecore::uint jnum = 0, const std::string stubMref = "", const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);

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
	* ListWznmQBoxDstMNBox
	*/
class ListWznmQBoxDstMNBox {

public:
	ListWznmQBoxDstMNBox();
	ListWznmQBoxDstMNBox(const ListWznmQBoxDstMNBox& src);
	ListWznmQBoxDstMNBox& operator=(const ListWznmQBoxDstMNBox& src);
	~ListWznmQBoxDstMNBox();

	void clear();

public:
	std::vector<WznmQBoxDstMNBox*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
