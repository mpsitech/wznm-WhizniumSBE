/**
	* \file PnlWznmTblRef1NRtblock.h
	* job handler for job PnlWznmTblRef1NRtblock (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMTBLREF1NRTBLOCK_H
#define PNLWZNMTBLREF1NRTBLOCK_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWznmTblRef1NRtblock.h"

#define VecVWznmTblRef1NRtblockDo PnlWznmTblRef1NRtblock::VecVDo

#define ContInfWznmTblRef1NRtblock PnlWznmTblRef1NRtblock::ContInf
#define StatAppWznmTblRef1NRtblock PnlWznmTblRef1NRtblock::StatApp
#define StgIacWznmTblRef1NRtblock PnlWznmTblRef1NRtblock::StgIac
#define TagWznmTblRef1NRtblock PnlWznmTblRef1NRtblock::Tag

#define DpchAppWznmTblRef1NRtblockData PnlWznmTblRef1NRtblock::DpchAppData
#define DpchAppWznmTblRef1NRtblockDo PnlWznmTblRef1NRtblock::DpchAppDo
#define DpchEngWznmTblRef1NRtblockData PnlWznmTblRef1NRtblock::DpchEngData

/**
	* PnlWznmTblRef1NRtblock
	*/
class PnlWznmTblRef1NRtblock : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmTblRef1NRtblockDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREFRESHCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmTblRef1NRtblock)
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
		* StatApp (full: StatAppWznmTblRef1NRtblock)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StgIac (full: StgIacWznmTblRef1NRtblock)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOREFWIDTH = 1;

	public:
		StgIac(const Sbecore::uint TcoRefWidth = 100);

	public:
		Sbecore::uint TcoRefWidth;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWznmTblRef1NRtblock)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmTblRef1NRtblockData)
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
		QryWznmTblRef1NRtblock::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmTblRef1NRtblockDo)
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
		* DpchEngData (full: DpchEngWznmTblRef1NRtblockData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STGIAC = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint RST = 7;
		static const Sbecore::uint STATAPPQRY = 8;
		static const Sbecore::uint STATSHRQRY = 9;
		static const Sbecore::uint STGIACQRY = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFCsiQst = NULL, StgIac* stgiac = NULL, ListWznmQTblRef1NRtblock* rst = NULL, QryWznmTblRef1NRtblock::StatShr* statshrqry = NULL, QryWznmTblRef1NRtblock::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StgIac stgiac;
		ListWznmQTblRef1NRtblock rst;
		QryWznmTblRef1NRtblock::StatShr statshrqry;
		QryWznmTblRef1NRtblock::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

public:
	PnlWznmTblRef1NRtblock(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmTblRef1NRtblock();

public:
	ContInf continf;
	StgIac stgiac;

	Sbecore::Feed feedFCsiQst;

	QryWznmTblRef1NRtblock* qry;

	WznmMRtblock recRtb;

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
	void handleDpchAppDataStgiacqry(DbsWznm* dbswznm, QryWznmTblRef1NRtblock::StgIac* _stgiacqry, DpchEngWznm** dpcheng);

	void handleDpchAppDoButRefreshClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmStatChg(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
