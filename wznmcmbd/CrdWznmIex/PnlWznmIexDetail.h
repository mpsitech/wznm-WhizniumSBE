/**
	* \file PnlWznmIexDetail.h
	* job handler for job PnlWznmIexDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMIEXDETAIL_H
#define PNLWZNMIEXDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmIexDetailDo PnlWznmIexDetail::VecVDo

#define ContIacWznmIexDetail PnlWznmIexDetail::ContIac
#define ContInfWznmIexDetail PnlWznmIexDetail::ContInf
#define StatAppWznmIexDetail PnlWznmIexDetail::StatApp
#define StatShrWznmIexDetail PnlWznmIexDetail::StatShr
#define TagWznmIexDetail PnlWznmIexDetail::Tag

#define DpchAppWznmIexDetailData PnlWznmIexDetail::DpchAppData
#define DpchAppWznmIexDetailDo PnlWznmIexDetail::DpchAppDo
#define DpchEngWznmIexDetailData PnlWznmIexDetail::DpchEngData

/**
	* PnlWznmIexDetail
	*/
class PnlWznmIexDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmIexDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJTIEDITCLICK = 2;
		static const Sbecore::uint BUTVERVIEWCLICK = 3;
		static const Sbecore::uint BUTJOBVIEWCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmIexDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPJTI = 2;
		static const Sbecore::uint TXFMIV = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupJti = 1, const std::string& TxfMiv = "", const std::string& TxfCmt = "");

	public:
		std::string TxfSho;
		Sbecore::uint numFPupJti;
		std::string TxfMiv;
		std::string TxfCmt;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmIexDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTVER = 3;
		static const Sbecore::uint TXTJOB = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtVer = "", const std::string& TxtJob = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtVer;
		std::string TxtJob;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmIexDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmIexDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFSHOACTIVE = 4;
		static const Sbecore::uint PUPJTIACTIVE = 5;
		static const Sbecore::uint BUTJTIEDITAVAIL = 6;
		static const Sbecore::uint TXTTITACTIVE = 7;
		static const Sbecore::uint TXTVERACTIVE = 8;
		static const Sbecore::uint BUTVERVIEWAVAIL = 9;
		static const Sbecore::uint BUTVERVIEWACTIVE = 10;
		static const Sbecore::uint TXTJOBACTIVE = 11;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 12;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 13;
		static const Sbecore::uint TXFMIVACTIVE = 14;
		static const Sbecore::uint TXFCMTACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfMivActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfMivActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmIexDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmIexDetailData)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmIexDetailDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmIexDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJTI = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupJti = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupJti;
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
	bool evalTxfShoActive(DbsWznm* dbswznm);
	bool evalPupJtiActive(DbsWznm* dbswznm);
	bool evalButJtiEditAvail(DbsWznm* dbswznm);
	bool evalTxtTitActive(DbsWznm* dbswznm);
	bool evalTxtVerActive(DbsWznm* dbswznm);
	bool evalButVerViewAvail(DbsWznm* dbswznm);
	bool evalButVerViewActive(DbsWznm* dbswznm);
	bool evalTxtJobActive(DbsWznm* dbswznm);
	bool evalButJobViewAvail(DbsWznm* dbswznm);
	bool evalButJobViewActive(DbsWznm* dbswznm);
	bool evalTxfMivActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmIexDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmIexDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupJti;

	WznmMImpexpcplx recIex;

	WznmJMImpexpcplxTitle recIexJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJti(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecIex(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecIexJtit(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJtiEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVerViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJobViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmIexJtitMod_iexEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmIexUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmIex_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmIex_jobEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
