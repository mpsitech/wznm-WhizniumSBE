/**
	* \file WznmPrcfile_blks.h
	* invocation / return data blocks for operation pack WznmPrcfile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMPRCFILE_BLKS_H
#define WZNMPRCFILE_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmPrcfileConcat
	*/
class DpchInvWznmPrcfileConcat : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint INFILES = 3;
	static const Sbecore::uint HEADERS = 4;
	static const Sbecore::uint OUTFILE = 5;

public:
	DpchInvWznmPrcfileConcat(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::vector<std::string>& infiles = {}, const std::vector<std::string>& headers = {}, const std::string& outfile = "");

public:
	std::vector<std::string> infiles;
	std::vector<std::string> headers;
	std::string outfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmPrcfileIexconv
	*/
class DpchInvWznmPrcfileIexconv : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint INFILE = 3;
	static const Sbecore::uint OUTFILE = 4;

public:
	DpchInvWznmPrcfileIexconv(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::string& infile = "", const std::string& outfile = "");

public:
	std::string infile;
	std::string outfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmPrcfilePlhrpl
	*/
class DpchInvWznmPrcfilePlhrpl : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint INREFWZNMMFILE = 3;
	static const Sbecore::uint INFILE = 4;
	static const Sbecore::uint OUTFILE = 5;
	static const Sbecore::uint KEYS = 6;
	static const Sbecore::uint VALS = 7;

public:
	DpchInvWznmPrcfilePlhrpl(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint inRefWznmMFile = 0, const std::string& infile = "", const std::string& outfile = "", const std::vector<std::string>& keys = {}, const std::vector<std::string>& vals = {});

public:
	Sbecore::ubigint inRefWznmMFile;
	std::string infile;
	std::string outfile;
	std::vector<std::string> keys;
	std::vector<std::string> vals;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

