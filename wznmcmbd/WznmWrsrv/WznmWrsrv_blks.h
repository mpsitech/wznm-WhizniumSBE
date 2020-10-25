/**
	* \file WznmWrsrv_blks.h
	* invocation / return data blocks for operation pack WznmWrsrv (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMWRSRV_BLKS_H
#define WZNMWRSRV_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmWrsrvBase
	*/
class DpchInvWznmWrsrvBase : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvBase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvCmbengbase
	*/
class DpchInvWznmWrsrvCmbengbase : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint ORGNAME = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint FOLDER = 6;

public:
	DpchInvWznmWrsrvCmbengbase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& orgname = "", const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string orgname;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvCrd
	*/
class DpchInvWznmWrsrvCrd : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMJOB = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvCrd(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMJob;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvDds
	*/
class DpchInvWznmWrsrvDds : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMCOMPONENT = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;
	static const Sbecore::uint INIFOLDER = 6;

public:
	DpchInvWznmWrsrvDds(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMComponent = 0, const std::string& Prjshort = "", const std::string& folder = "", const std::string& inifolder = "");

public:
	Sbecore::ubigint refWznmMComponent;
	std::string Prjshort;
	std::string folder;
	std::string inifolder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvDeploy
	*/
class DpchInvWznmWrsrvDeploy : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMRELEASE = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvDeploy(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMRelease = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMRelease;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvDlg
	*/
class DpchInvWznmWrsrvDlg : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMJOB = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvDlg(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMJob;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvEngbase
	*/
class DpchInvWznmWrsrvEngbase : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint ORGNAME = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint FOLDER = 6;

public:
	DpchInvWznmWrsrvEngbase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& orgname = "", const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string orgname;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvIex
	*/
class DpchInvWznmWrsrvIex : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMJOB = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvIex(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMJob;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvInixml
	*/
class DpchInvWznmWrsrvInixml : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvInixml(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvJob
	*/
class DpchInvWznmWrsrvJob : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMJOB = 3;
	static const Sbecore::uint ORGWEB = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint FOLDER = 6;

public:
	DpchInvWznmWrsrvJob(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string& orgweb = "", const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMJob;
	std::string orgweb;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvOp
	*/
class DpchInvWznmWrsrvOp : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMOP = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvOp(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMOp = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMOp;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvOpengbase
	*/
class DpchInvWznmWrsrvOpengbase : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMCOMPONENT = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvOpengbase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMComponent = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMComponent;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvOpk
	*/
class DpchInvWznmWrsrvOpk : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMOPPACK = 3;
	static const Sbecore::uint ORGWEB = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint FOLDER = 6;

public:
	DpchInvWznmWrsrvOpk(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMOppack = 0, const std::string& orgweb = "", const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMOppack;
	std::string orgweb;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvPnl
	*/
class DpchInvWznmWrsrvPnl : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMJOB = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvPnl(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMJob;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvPref
	*/
class DpchInvWznmWrsrvPref : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMRELEASE = 3;
	static const Sbecore::uint INFILE = 4;
	static const Sbecore::uint OUTFILE = 5;

public:
	DpchInvWznmWrsrvPref(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMRelease = 0, const std::string& infile = "", const std::string& outfile = "");

public:
	Sbecore::ubigint refWznmMRelease;
	std::string infile;
	std::string outfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvQry
	*/
class DpchInvWznmWrsrvQry : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMJOB = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvQry(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMJob;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvRootsess
	*/
class DpchInvWznmWrsrvRootsess : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvRootsess(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvUa
	*/
class DpchInvWznmWrsrvUa : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint CMPSREF = 5;
	static const Sbecore::uint FOLDER = 6;

public:
	DpchInvWznmWrsrvUa(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& Cmpsref = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string Cmpsref;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrsrvVec
	*/
class DpchInvWznmWrsrvVec : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVECTOR = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrsrvVec(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVector;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

