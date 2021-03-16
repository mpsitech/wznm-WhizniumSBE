/**
	* \file PnlWznmPnlMNQuery.h
	* job handler for job PnlWznmPnlMNQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMPNLMNQUERY_H
#define PNLWZNMPNLMNQUERY_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWznmPnlMNQuery.h"

#define VecVWznmPnlMNQueryDo PnlWznmPnlMNQuery::VecVDo

#define ContInfWznmPnlMNQuery PnlWznmPnlMNQuery::ContInf
#define StatAppWznmPnlMNQuery PnlWznmPnlMNQuery::StatApp
#define StatShrWznmPnlMNQuery PnlWznmPnlMNQuery::StatShr
#define StgIacWznmPnlMNQuery PnlWznmPnlMNQuery::StgIac
#define TagWznmPnlMNQuery PnlWznmPnlMNQuery::Tag

#define DpchAppWznmPnlMNQueryData PnlWznmPnlMNQuery::DpchAppData
#define DpchAppWznmPnlMNQueryDo PnlWznmPnlMNQuery::DpchAppDo
#define DpchEngWznmPnlMNQueryData PnlWznmPnlMNQuery::DpchEngData

/**
	* PnlWznmPnlMNQuery
	*/
class PnlWznmPnlMNQuery : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmPnlMNQueryDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTVIEWCLICK = 1;
		static const Sbecore::uint BUTADDCLICK = 2;
		static const Sbecore::uint BUTSUBCLICK = 3;
		static const Sbecore::uint BUTREFRESHCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmPnlMNQuery)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmPnlMNQuery)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmPnlMNQuery)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTVIEWAVAIL = 1;
		static const Sbecore::uint BUTVIEWACTIVE = 2;
		static const Sbecore::uint BUTADDAVAIL = 3;
		static const Sbecore::uint BUTSUBAVAIL = 4;
		static const Sbecore::uint BUTSUBACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWznmPnlMNQuery)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOMREFWIDTH = 1;

	public:
		StgIac(const Sbecore::uint TcoMrefWidth = 100);

	public:
		Sbecore::uint TcoMrefWidth;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWznmPnlMNQuery)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmPnlMNQueryData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryWznmPnlMNQuery::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmPnlMNQueryDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmPnlMNQueryData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint STGIAC = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint RST = 8;
		static const Sbecore::uint STATAPPQRY = 9;
		static const Sbecore::uint STATSHRQRY = 10;
		static const Sbecore::uint STGIACQRY = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWznmQPnlMNQuery* rst = NULL, QryWznmPnlMNQuery::StatShr* statshrqry = NULL, QryWznmPnlMNQuery::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListWznmQPnlMNQuery rst;
		QryWznmPnlMNQuery::StatShr statshrqry;
		QryWznmPnlMNQuery::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButViewAvail(DbsWznm* dbswznm);
	bool evalButViewActive(DbsWznm* dbswznm);
	bool evalButAddAvail(DbsWznm* dbswznm);
	bool evalButSubAvail(DbsWznm* dbswznm);
	bool evalButSubActive(DbsWznm* dbswznm);

public:
	PnlWznmPnlMNQuery(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmPnlMNQuery();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFCsiQst;

	QryWznmPnlMNQuery* qry;

	WznmRMPanelMQuery recPnlRqry;

	WznmMQuery recQry;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataStgiac(DbsWznm* dbswznm, StgIac* _stgiac, DpchEngWznm** dpcheng);
	void handleDpchAppDataStgiacqry(DbsWznm* dbswznm, QryWznmPnlMNQuery::StgIac* _stgiacqry, DpchEngWznm** dpcheng);

	void handleDpchAppDoButViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButAddClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSubClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmStatChg(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
