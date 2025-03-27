/**
	* \file PnlWznmSgeDetail.h
	* job handler for job PnlWznmSgeDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMSGEDETAIL_H
#define PNLWZNMSGEDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmSgeDetailDo PnlWznmSgeDetail::VecVDo

#define ContIacWznmSgeDetail PnlWznmSgeDetail::ContIac
#define ContInfWznmSgeDetail PnlWznmSgeDetail::ContInf
#define StatAppWznmSgeDetail PnlWznmSgeDetail::StatApp
#define StatShrWznmSgeDetail PnlWznmSgeDetail::StatShr
#define TagWznmSgeDetail PnlWznmSgeDetail::Tag

#define DpchAppWznmSgeDetailData PnlWznmSgeDetail::DpchAppData
#define DpchAppWznmSgeDetailDo PnlWznmSgeDetail::DpchAppDo
#define DpchEngWznmSgeDetailData PnlWznmSgeDetail::DpchEngData

/**
	* PnlWznmSgeDetail
	*/
class PnlWznmSgeDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmSgeDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJOBVIEWCLICK = 2;
		static const Sbecore::uint BUTSNXVIEWCLICK = 3;
		static const Sbecore::uint BUTFNXVIEWCLICK = 4;
		static const Sbecore::uint BUTSQKNEWCLICK = 5;
		static const Sbecore::uint BUTSQKDELETECLICK = 6;
		static const Sbecore::uint BUTSQKJTIEDITCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmSgeDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint TXFMON = 2;
		static const Sbecore::uint TXFCMT = 3;
		static const Sbecore::uint NUMFPUPSQKJTI = 4;
		static const Sbecore::uint TXFSQKEXA = 5;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const std::string& TxfMon = "", const std::string& TxfCmt = "", const Sbecore::uint numFPupSqkJti = 1, const std::string& TxfSqkExa = "");

	public:
		Sbecore::uint numFPupTyp;
		std::string TxfMon;
		std::string TxfCmt;
		Sbecore::uint numFPupSqkJti;
		std::string TxfSqkExa;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmSgeDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTJOB = 2;
		static const Sbecore::uint TXTSNX = 3;
		static const Sbecore::uint TXTFNX = 4;
		static const Sbecore::uint TXTSQKTIT = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtJob = "", const std::string& TxtSnx = "", const std::string& TxtFnx = "", const std::string& TxtSqkTit = "");

	public:
		std::string TxtSrf;
		std::string TxtJob;
		std::string TxtSnx;
		std::string TxtFnx;
		std::string TxtSqkTit;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmSgeDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmSgeDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPTYPACTIVE = 4;
		static const Sbecore::uint TXTJOBACTIVE = 5;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 6;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 7;
		static const Sbecore::uint TXFMONACTIVE = 8;
		static const Sbecore::uint TXTSNXACTIVE = 9;
		static const Sbecore::uint BUTSNXVIEWAVAIL = 10;
		static const Sbecore::uint BUTSNXVIEWACTIVE = 11;
		static const Sbecore::uint TXTFNXACTIVE = 12;
		static const Sbecore::uint BUTFNXVIEWAVAIL = 13;
		static const Sbecore::uint BUTFNXVIEWACTIVE = 14;
		static const Sbecore::uint TXFCMTACTIVE = 15;
		static const Sbecore::uint BUTSQKNEWAVAIL = 16;
		static const Sbecore::uint BUTSQKDELETEAVAIL = 17;
		static const Sbecore::uint PUPSQKJTIAVAIL = 18;
		static const Sbecore::uint PUPSQKJTIACTIVE = 19;
		static const Sbecore::uint BUTSQKJTIEDITAVAIL = 20;
		static const Sbecore::uint TXTSQKTITAVAIL = 21;
		static const Sbecore::uint TXTSQKTITACTIVE = 22;
		static const Sbecore::uint TXFSQKEXAAVAIL = 23;
		static const Sbecore::uint TXFSQKEXAACTIVE = 24;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfMonActive = true, const bool TxtSnxActive = true, const bool ButSnxViewAvail = true, const bool ButSnxViewActive = true, const bool TxtFnxActive = true, const bool ButFnxViewAvail = true, const bool ButFnxViewActive = true, const bool TxfCmtActive = true, const bool ButSqkNewAvail = true, const bool ButSqkDeleteAvail = true, const bool PupSqkJtiAvail = true, const bool PupSqkJtiActive = true, const bool ButSqkJtiEditAvail = true, const bool TxtSqkTitAvail = true, const bool TxtSqkTitActive = true, const bool TxfSqkExaAvail = true, const bool TxfSqkExaActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfMonActive;
		bool TxtSnxActive;
		bool ButSnxViewAvail;
		bool ButSnxViewActive;
		bool TxtFnxActive;
		bool ButFnxViewAvail;
		bool ButFnxViewActive;
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
		* Tag (full: TagWznmSgeDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmSgeDetailData)
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
		* DpchAppDo (full: DpchAppWznmSgeDetailDo)
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
		* DpchEngData (full: DpchEngWznmSgeDetailData)
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
	bool evalPupTypActive(DbsWznm* dbswznm);
	bool evalTxtJobActive(DbsWznm* dbswznm);
	bool evalButJobViewAvail(DbsWznm* dbswznm);
	bool evalButJobViewActive(DbsWznm* dbswznm);
	bool evalTxfMonActive(DbsWznm* dbswznm);
	bool evalTxtSnxActive(DbsWznm* dbswznm);
	bool evalButSnxViewAvail(DbsWznm* dbswznm);
	bool evalButSnxViewActive(DbsWznm* dbswznm);
	bool evalTxtFnxActive(DbsWznm* dbswznm);
	bool evalButFnxViewAvail(DbsWznm* dbswznm);
	bool evalButFnxViewActive(DbsWznm* dbswznm);
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
	PnlWznmSgeDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmSgeDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupSqkJti;
	Sbecore::Feed feedFPupTyp;

	WznmMStage recSge;

	WznmMSquawk recSqk;

	WznmJMSquawkTitle recSqkJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshSqkJti(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecSge(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
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
	void handleDpchAppDoButJobViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSnxViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButFnxViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSqkNewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSqkDeleteClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSqkJtiEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmSqkJtitMod_sqkEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSgeUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSqkUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSge_snxEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSge_sqkEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSge_jobEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSge_fnxEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
