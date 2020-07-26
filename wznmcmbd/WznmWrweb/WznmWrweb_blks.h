/**
	* \file WznmWrweb_blks.h
	* invocation / return data blocks for operation pack WznmWrweb (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRWEB_BLKS_H
#define WZNMWRWEB_BLKS_H

#include "Wznm.h"

/**
	* DpchInvWznmWrwebBase
	*/
class DpchInvWznmWrwebBase : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrwebBase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrwebCrd
	*/
class DpchInvWznmWrwebCrd : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMCARD = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrwebCrd(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMCard = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMCard;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrwebDeploy
	*/
class DpchInvWznmWrwebDeploy : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMVERSION = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrwebDeploy(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMVersion;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrwebDlg
	*/
class DpchInvWznmWrwebDlg : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMDIALOG = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrwebDlg(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMDialog = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMDialog;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWznmWrwebPnl
	*/
class DpchInvWznmWrwebPnl : public DpchInvWznm {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWZNMMPANEL = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint FOLDER = 5;

public:
	DpchInvWznmWrwebPnl(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWznmMPanel = 0, const std::string& Prjshort = "", const std::string& folder = "");

public:
	Sbecore::ubigint refWznmMPanel;
	std::string Prjshort;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

