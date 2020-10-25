/**
	* \file WznmPrctree_blks.h
	* invocation / return data blocks for operation pack WznmPrctree (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMPRCTREE_BLKS_H
#define WZNMPRCTREE_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmPrctreeExtract
	*/
class DpchInvWznmPrctreeExtract : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint INFILE = 3;
	static const Sbecore::uint INFOLDER = 4;
	static const Sbecore::uint EXTFILE = 5;
	static const Sbecore::uint EXTFOLDER = 6;

public:
	DpchInvWznmPrctreeExtract(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::string& infile = "", const std::string& infolder = "", const std::string& extfile = "", const std::string& extfolder = "");

public:
	std::string infile;
	std::string infolder;
	std::string extfile;
	std::string extfolder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWznmPrctreeExtract
	*/
class DpchRetWznmPrctreeExtract : public DpchRetWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint LOGFILE = 5;

public:
	DpchRetWznmPrctreeExtract(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& logfile = "");

public:
	std::string logfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmPrctreeMerge
	*/
class DpchInvWznmPrctreeMerge : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint EXTFILE = 3;
	static const Sbecore::uint EXTFOLDER = 4;
	static const Sbecore::uint TPLFILE = 5;
	static const Sbecore::uint TPLFOLDER = 6;
	static const Sbecore::uint NOTRACE = 7;
	static const Sbecore::uint SKIPMULTVOID = 8;

public:
	DpchInvWznmPrctreeMerge(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::string& extfile = "", const std::string& extfolder = "", const std::string& tplfile = "", const std::string& tplfolder = "", const bool notrace = false, const bool skipmultvoid = false);

public:
	std::string extfile;
	std::string extfolder;
	std::string tplfile;
	std::string tplfolder;
	bool notrace;
	bool skipmultvoid;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWznmPrctreeMerge
	*/
class DpchRetWznmPrctreeMerge : public DpchRetWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint LOGFILE = 5;

public:
	DpchRetWznmPrctreeMerge(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& logfile = "");

public:
	std::string logfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmPrctreeValidate
	*/
class DpchInvWznmPrctreeValidate : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;

public:
	DpchInvWznmPrctreeValidate(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0);

public:

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

