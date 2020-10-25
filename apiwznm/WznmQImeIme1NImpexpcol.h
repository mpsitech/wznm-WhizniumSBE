/**
	* \file WznmQImeIme1NImpexpcol.h
	* API code for table TblWznmQImeIme1NImpexpcol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQIMEIME1NIMPEXPCOL_H
#define WZNMQIMEIME1NIMPEXPCOL_H

#include <sbecore/Xmlio.h>

/**
	* WznmQImeIme1NImpexpcol
	*/
class WznmQImeIme1NImpexpcol {

public:
	WznmQImeIme1NImpexpcol(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQImeIme1NImpexpcol
	*/
class ListWznmQImeIme1NImpexpcol {

public:
	ListWznmQImeIme1NImpexpcol();
	ListWznmQImeIme1NImpexpcol(const ListWznmQImeIme1NImpexpcol& src);
	ListWznmQImeIme1NImpexpcol& operator=(const ListWznmQImeIme1NImpexpcol& src);
	~ListWznmQImeIme1NImpexpcol();

	void clear();

public:
	std::vector<WznmQImeIme1NImpexpcol*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

