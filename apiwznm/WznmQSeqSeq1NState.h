/**
	* \file WznmQSeqSeq1NState.h
	* API code for table TblWznmQSeqSeq1NState (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSEQSEQ1NSTATE_H
#define WZNMQSEQSEQ1NSTATE_H

#include <sbecore/Xmlio.h>

/**
	* WznmQSeqSeq1NState
	*/
class WznmQSeqSeq1NState {

public:
	WznmQSeqSeq1NState(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWznmQSeqSeq1NState
	*/
class ListWznmQSeqSeq1NState {

public:
	ListWznmQSeqSeq1NState();
	ListWznmQSeqSeq1NState(const ListWznmQSeqSeq1NState& src);
	ListWznmQSeqSeq1NState& operator=(const ListWznmQSeqSeq1NState& src);
	~ListWznmQSeqSeq1NState();

	void clear();

public:
	std::vector<WznmQSeqSeq1NState*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
