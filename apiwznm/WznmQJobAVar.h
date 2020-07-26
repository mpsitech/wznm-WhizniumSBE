/**
	* \file WznmQJobAVar.h
	* API code for table TblWznmQJobAVar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQJOBAVAR_H
#define WZNMQJOBAVAR_H

#include <sbecore/Xmlio.h>

/**
	* WznmQJobAVar
	*/
class WznmQJobAVar {

public:
	WznmQJobAVar(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string yesnoShr = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	std::string stubRefWznmMVector;
	Sbecore::uint Length;
	std::string yesnoShr;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQJobAVar
	*/
class ListWznmQJobAVar {

public:
	ListWznmQJobAVar();
	ListWznmQJobAVar(const ListWznmQJobAVar& src);
	ListWznmQJobAVar& operator=(const ListWznmQJobAVar& src);
	~ListWznmQJobAVar();

	void clear();

public:
	std::vector<WznmQJobAVar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

