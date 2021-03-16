/**
	* \file PnlWznmPrjDetail.h
	* job handler for job PnlWznmPrjDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMPRJDETAIL_H
#define PNLWZNMPRJDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmPrjDetailDo PnlWznmPrjDetail::VecVDo

#define ContIacWznmPrjDetail PnlWznmPrjDetail::ContIac
#define ContInfWznmPrjDetail PnlWznmPrjDetail::ContInf
#define StatAppWznmPrjDetail PnlWznmPrjDetail::StatApp
#define StatShrWznmPrjDetail PnlWznmPrjDetail::StatShr
#define TagWznmPrjDetail PnlWznmPrjDetail::Tag

#define DpchAppWznmPrjDetailData PnlWznmPrjDetail::DpchAppData
#define DpchAppWznmPrjDetailDo PnlWznmPrjDetail::DpchAppDo
#define DpchEngWznmPrjDetailData PnlWznmPrjDetail::DpchEngData

/**
	* PnlWznmPrjDetail
	*/
class PnlWznmPrjDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmPrjDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmPrjDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint TXFTIT = 2;
		static const Sbecore::uint TXFGRL = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const std::string& TxfSho = "", const std::string& TxfTit = "", const std::string& TxfGrl = "", const std::string& TxfCmt = "");

	public:
		std::string TxfSho;
		std::string TxfTit;
		std::string TxfGrl;
		std::string TxfCmt;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmPrjDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTVER = 1;

	public:
		ContInf(const std::string& TxtVer = "");

	public:
		std::string TxtVer;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmPrjDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmPrjDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFSHOACTIVE = 3;
		static const Sbecore::uint TXFTITACTIVE = 4;
		static const Sbecore::uint TXTVERACTIVE = 5;
		static const Sbecore::uint BUTVERVIEWAVAIL = 6;
		static const Sbecore::uint BUTVERVIEWACTIVE = 7;
		static const Sbecore::uint TXFGRLACTIVE = 8;
		static const Sbecore::uint TXFCMTACTIVE = 9;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfShoActive = true, const bool TxfTitActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxfGrlActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfShoActive;
		bool TxfTitActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxfGrlActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmPrjDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmPrjDetailData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmPrjDetailDo)
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
		* DpchEngData (full: DpchEngWznmPrjDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxfShoActive(DbsWznm* dbswznm);
	bool evalTxfTitActive(DbsWznm* dbswznm);
	bool evalTxtVerActive(DbsWznm* dbswznm);
	bool evalButVerViewAvail(DbsWznm* dbswznm);
	bool evalButVerViewActive(DbsWznm* dbswznm);
	bool evalTxfGrlActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmPrjDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmPrjDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	WznmMProject recPrj;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecPrj(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVerViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmPrjUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmPrj_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
