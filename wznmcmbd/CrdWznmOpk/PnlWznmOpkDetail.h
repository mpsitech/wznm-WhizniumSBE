/**
	* \file PnlWznmOpkDetail.h
	* job handler for job PnlWznmOpkDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMOPKDETAIL_H
#define PNLWZNMOPKDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmOpkDetailDo PnlWznmOpkDetail::VecVDo

#define ContIacWznmOpkDetail PnlWznmOpkDetail::ContIac
#define ContInfWznmOpkDetail PnlWznmOpkDetail::ContInf
#define StatAppWznmOpkDetail PnlWznmOpkDetail::StatApp
#define StatShrWznmOpkDetail PnlWznmOpkDetail::StatShr
#define TagWznmOpkDetail PnlWznmOpkDetail::Tag

#define DpchAppWznmOpkDetailData PnlWznmOpkDetail::DpchAppData
#define DpchAppWznmOpkDetailDo PnlWznmOpkDetail::DpchAppDo
#define DpchEngWznmOpkDetailData PnlWznmOpkDetail::DpchEngData

/**
	* PnlWznmOpkDetail
	*/
class PnlWznmOpkDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmOpkDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTSQKNEWCLICK = 3;
		static const Sbecore::uint BUTSQKDELETECLICK = 4;
		static const Sbecore::uint BUTSQKJTIEDITCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmOpkDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint CHKSHD = 3;
		static const Sbecore::uint TXFCMT = 4;
		static const Sbecore::uint NUMFPUPSQKJTI = 5;
		static const Sbecore::uint TXFSQKEXA = 6;

	public:
		ContIac(const std::string& TxfTit = "", const Sbecore::uint numFPupTyp = 1, const bool ChkShd = false, const std::string& TxfCmt = "", const Sbecore::uint numFPupSqkJti = 1, const std::string& TxfSqkExa = "");

	public:
		std::string TxfTit;
		Sbecore::uint numFPupTyp;
		bool ChkShd;
		std::string TxfCmt;
		Sbecore::uint numFPupSqkJti;
		std::string TxfSqkExa;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmOpkDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTSQKTIT = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtSqkTit = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtSqkTit;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmOpkDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmOpkDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFTITACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint TXTVERACTIVE = 6;
		static const Sbecore::uint BUTVERVIEWAVAIL = 7;
		static const Sbecore::uint BUTVERVIEWACTIVE = 8;
		static const Sbecore::uint CHKSHDACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;
		static const Sbecore::uint BUTSQKNEWAVAIL = 11;
		static const Sbecore::uint BUTSQKDELETEAVAIL = 12;
		static const Sbecore::uint PUPSQKJTIAVAIL = 13;
		static const Sbecore::uint PUPSQKJTIACTIVE = 14;
		static const Sbecore::uint BUTSQKJTIEDITAVAIL = 15;
		static const Sbecore::uint TXTSQKTITAVAIL = 16;
		static const Sbecore::uint TXTSQKTITACTIVE = 17;
		static const Sbecore::uint TXFSQKEXAAVAIL = 18;
		static const Sbecore::uint TXFSQKEXAACTIVE = 19;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool ChkShdActive = true, const bool TxfCmtActive = true, const bool ButSqkNewAvail = true, const bool ButSqkDeleteAvail = true, const bool PupSqkJtiAvail = true, const bool PupSqkJtiActive = true, const bool ButSqkJtiEditAvail = true, const bool TxtSqkTitAvail = true, const bool TxtSqkTitActive = true, const bool TxfSqkExaAvail = true, const bool TxfSqkExaActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool ChkShdActive;
		bool TxfCmtActive;
		bool ButSqkNewAvail;
		bool ButSqkDeleteAvail;
		bool PupSqkJtiAvail;
		bool PupSqkJtiActive;
		bool ButSqkJtiEditAvail;
		bool TxtSqkTitAvail;
		bool TxtSqkTitActive;
		bool TxfSqkExaAvail;
		bool TxfSqkExaActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmOpkDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmOpkDetailData)
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
		* DpchAppDo (full: DpchAppWznmOpkDetailDo)
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
		* DpchEngData (full: DpchEngWznmOpkDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPSQKJTI = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupSqkJti = NULL, Sbecore::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupSqkJti;
		Sbecore::Feed feedFPupTyp;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxtSrfActive(DbsWznm* dbswznm);
	bool evalTxfTitActive(DbsWznm* dbswznm);
	bool evalPupTypActive(DbsWznm* dbswznm);
	bool evalTxtVerActive(DbsWznm* dbswznm);
	bool evalButVerViewAvail(DbsWznm* dbswznm);
	bool evalButVerViewActive(DbsWznm* dbswznm);
	bool evalChkShdActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);
	bool evalButSqkNewAvail(DbsWznm* dbswznm);
	bool evalButSqkDeleteAvail(DbsWznm* dbswznm);
	bool evalPupSqkJtiAvail(DbsWznm* dbswznm);
	bool evalPupSqkJtiActive(DbsWznm* dbswznm);
	bool evalButSqkJtiEditAvail(DbsWznm* dbswznm);
	bool evalTxtSqkTitAvail(DbsWznm* dbswznm);
	bool evalTxtSqkTitActive(DbsWznm* dbswznm);
	bool evalTxfSqkExaAvail(DbsWznm* dbswznm);
	bool evalTxfSqkExaActive(DbsWznm* dbswznm);

public:
	PnlWznmOpkDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmOpkDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupSqkJti;
	Sbecore::Feed feedFPupTyp;

	WznmMOppack recOpk;

	WznmMSquawk recSqk;

	WznmJMSquawkTitle recSqkJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshSqkJti(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecOpk(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecSqk(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecSqkJtit(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDoButSqkNewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSqkDeleteClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSqkJtiEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmSqkJtitMod_sqkEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSqkUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmOpkUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmOpk_sqkEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmOpk_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
