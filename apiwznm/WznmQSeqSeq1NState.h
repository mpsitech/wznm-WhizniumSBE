/**
	* \file WznmQSeqSeq1NState.h
	* API code for table TblWznmQSeqSeq1NState (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

