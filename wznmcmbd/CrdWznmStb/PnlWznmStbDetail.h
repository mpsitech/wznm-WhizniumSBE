/**
	* \file PnlWznmStbDetail.h
	* job handler for job PnlWznmStbDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMSTBDETAIL_H
#define PNLWZNMSTBDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmStbDetailDo PnlWznmStbDetail::VecVDo

#define ContIacWznmStbDetail PnlWznmStbDetail::ContIac
#define ContInfWznmStbDetail PnlWznmStbDetail::ContInf
#define StatAppWznmStbDetail PnlWznmStbDetail::StatApp
#define StatShrWznmStbDetail PnlWznmStbDetail::StatShr
#define TagWznmStbDetail PnlWznmStbDetail::Tag

#define DpchAppWznmStbDetailData PnlWznmStbDetail::DpchAppData
#define DpchAppWznmStbDetailDo PnlWznmStbDetail::DpchAppDo
#define DpchEngWznmStbDetailData PnlWznmStbDetail::DpchEngData

/**
	* PnlWznmStbDetail
	*/
class PnlWznmStbDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmStbDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTSBSVIEWCLICK = 2;
		static const Sbecore::uint BUTTCOVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmStbDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint CHKHRC = 2;
		static const Sbecore::uint CHKLCL = 3;
		static const Sbecore::uint TXFEXA = 4;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const bool ChkHrc = false, const bool ChkLcl = false, const std::string& TxfExa = "");

	public:
		Sbecore::uint numFPupTyp;
		bool ChkHrc;
		bool ChkLcl;
		std::string TxfExa;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmStbDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTBL = 2;
		static const Sbecore::uint TXTSBS = 3;
		static const Sbecore::uint TXTTCO = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTbl = "", const std::string& TxtSbs = "", const std::string& TxtTco = "");

	public:
		std::string TxtSrf;
		std::string TxtTbl;
		std::string TxtSbs;
		std::string TxtTco;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmStbDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmStbDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPTYPACTIVE = 4;
		static const Sbecore::uint TXTTBLACTIVE = 5;
		static const Sbecore::uint TXTSBSACTIVE = 6;
		static const Sbecore::uint BUTSBSVIEWAVAIL = 7;
		static const Sbecore::uint BUTSBSVIEWACTIVE = 8;
		static const Sbecore::uint CHKHRCACTIVE = 9;
		static const Sbecore::uint TXTTCOACTIVE = 10;
		static const Sbecore::uint BUTTCOVIEWAVAIL = 11;
		static const Sbecore::uint BUTTCOVIEWACTIVE = 12;
		static const Sbecore::uint CHKLCLACTIVE = 13;
		static const Sbecore::uint TXFEXAACTIVE = 14;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtTblActive = true, const bool TxtSbsActive = true, const bool ButSbsViewAvail = true, const bool ButSbsViewActive = true, const bool ChkHrcActive = true, const bool TxtTcoActive = true, const bool ButTcoViewAvail = true, const bool ButTcoViewActive = true, const bool ChkLclActive = true, const bool TxfExaActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtTblActive;
		bool TxtSbsActive;
		bool ButSbsViewAvail;
		bool ButSbsViewActive;
		bool ChkHrcActive;
		bool TxtTcoActive;
		bool ButTcoViewAvail;
		bool ButTcoViewActive;
		bool ChkLclActive;
		bool TxfExaActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmStbDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmStbDetailData)
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
		* DpchAppDo (full: DpchAppWznmStbDetailDo)
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
		* DpchEngData (full: DpchEngWznmStbDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPTYP = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
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
	bool evalTxtTblActive(DbsWznm* dbswznm);
	bool evalTxtSbsActive(DbsWznm* dbswznm);
	bool evalButSbsViewAvail(DbsWznm* dbswznm);
	bool evalButSbsViewActive(DbsWznm* dbswznm);
	bool evalChkHrcActive(DbsWznm* dbswznm);
	bool evalTxtTcoActive(DbsWznm* dbswznm);
	bool evalButTcoViewAvail(DbsWznm* dbswznm);
	bool evalButTcoViewActive(DbsWznm* dbswznm);
	bool evalChkLclActive(DbsWznm* dbswznm);
	bool evalTxfExaActive(DbsWznm* dbswznm);

public:
	PnlWznmStbDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmStbDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupTyp;

	WznmMStub recStb;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecStb(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSbsViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButTcoViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmStbUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmStb_tcoEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmStb_sbsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
