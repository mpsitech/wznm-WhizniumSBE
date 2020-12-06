/**
	* \file PnlWznmIelDetail.h
	* job handler for job PnlWznmIelDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMIELDETAIL_H
#define PNLWZNMIELDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmIelDetailDo PnlWznmIelDetail::VecVDo

#define ContIacWznmIelDetail PnlWznmIelDetail::ContIac
#define ContInfWznmIelDetail PnlWznmIelDetail::ContInf
#define StatAppWznmIelDetail PnlWznmIelDetail::StatApp
#define StatShrWznmIelDetail PnlWznmIelDetail::StatShr
#define TagWznmIelDetail PnlWznmIelDetail::Tag

#define DpchAppWznmIelDetailData PnlWznmIelDetail::DpchAppData
#define DpchAppWznmIelDetailDo PnlWznmIelDetail::DpchAppDo
#define DpchEngWznmIelDetailData PnlWznmIelDetail::DpchEngData

/**
	* PnlWznmIelDetail
	*/
class PnlWznmIelDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmIelDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTIMEVIEWCLICK = 2;
		static const Sbecore::uint BUTIM2VIEWCLICK = 3;
		static const Sbecore::uint BUTPSTVIEWCLICK = 4;
		static const Sbecore::uint BUTSTBVIEWCLICK = 5;
		static const Sbecore::uint BUTVITVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmIelDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint NUMSFLSTOCC = 3;
		static const Sbecore::uint NUMFPUPCTY = 4;
		static const Sbecore::uint TXFDFV = 5;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupTyp = 1, const std::vector<Sbecore::uint>& numsFLstOcc = {}, const Sbecore::uint numFPupCty = 1, const std::string& TxfDfv = "");

	public:
		std::string TxfSho;
		Sbecore::uint numFPupTyp;
		std::vector<Sbecore::uint> numsFLstOcc;
		Sbecore::uint numFPupCty;
		std::string TxfDfv;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmIelDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTOCC = 2;
		static const Sbecore::uint TXTIME = 3;
		static const Sbecore::uint TXTTCO = 4;
		static const Sbecore::uint TXTIM2 = 5;
		static const Sbecore::uint TXTPST = 6;
		static const Sbecore::uint TXTSTB = 7;
		static const Sbecore::uint TXTVIT = 8;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtOcc = "", const std::string& TxtIme = "", const std::string& TxtTco = "", const std::string& TxtIm2 = "", const std::string& TxtPst = "", const std::string& TxtStb = "", const std::string& TxtVit = "");

	public:
		std::string TxtSrf;
		std::string TxtOcc;
		std::string TxtIme;
		std::string TxtTco;
		std::string TxtIm2;
		std::string TxtPst;
		std::string TxtStb;
		std::string TxtVit;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmIelDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOccAlt = true, const Sbecore::uint LstOccNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmIelDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFSHOACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint LSTOCCACTIVE = 6;
		static const Sbecore::uint TXTIMEACTIVE = 7;
		static const Sbecore::uint BUTIMEVIEWAVAIL = 8;
		static const Sbecore::uint BUTIMEVIEWACTIVE = 9;
		static const Sbecore::uint TXTTCOACTIVE = 10;
		static const Sbecore::uint TXTIM2ACTIVE = 11;
		static const Sbecore::uint BUTIM2VIEWAVAIL = 12;
		static const Sbecore::uint BUTIM2VIEWACTIVE = 13;
		static const Sbecore::uint PUPCTYACTIVE = 14;
		static const Sbecore::uint TXFDFVACTIVE = 15;
		static const Sbecore::uint TXTPSTACTIVE = 16;
		static const Sbecore::uint BUTPSTVIEWAVAIL = 17;
		static const Sbecore::uint BUTPSTVIEWACTIVE = 18;
		static const Sbecore::uint TXTSTBACTIVE = 19;
		static const Sbecore::uint BUTSTBVIEWAVAIL = 20;
		static const Sbecore::uint BUTSTBVIEWACTIVE = 21;
		static const Sbecore::uint TXTVITACTIVE = 22;
		static const Sbecore::uint BUTVITVIEWAVAIL = 23;
		static const Sbecore::uint BUTVITVIEWACTIVE = 24;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupTypActive = true, const bool LstOccActive = true, const bool TxtImeActive = true, const bool ButImeViewAvail = true, const bool ButImeViewActive = true, const bool TxtTcoActive = true, const bool TxtIm2Active = true, const bool ButIm2ViewAvail = true, const bool ButIm2ViewActive = true, const bool PupCtyActive = true, const bool TxfDfvActive = true, const bool TxtPstActive = true, const bool ButPstViewAvail = true, const bool ButPstViewActive = true, const bool TxtStbActive = true, const bool ButStbViewAvail = true, const bool ButStbViewActive = true, const bool TxtVitActive = true, const bool ButVitViewAvail = true, const bool ButVitViewActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupTypActive;
		bool LstOccActive;
		bool TxtImeActive;
		bool ButImeViewAvail;
		bool ButImeViewActive;
		bool TxtTcoActive;
		bool TxtIm2Active;
		bool ButIm2ViewAvail;
		bool ButIm2ViewActive;
		bool PupCtyActive;
		bool TxfDfvActive;
		bool TxtPstActive;
		bool ButPstViewAvail;
		bool ButPstViewActive;
		bool TxtStbActive;
		bool ButStbViewAvail;
		bool ButStbViewActive;
		bool TxtVitActive;
		bool ButVitViewAvail;
		bool ButVitViewActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmIelDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmIelDetailData)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmIelDetailDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmIelDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOCC = 4;
		static const Sbecore::uint FEEDFPUPCTY = 5;
		static const Sbecore::uint FEEDFPUPTYP = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstOcc = NULL, Sbecore::Xmlio::Feed* feedFPupCty = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstOcc;
		Sbecore::Xmlio::Feed feedFPupCty;
		Sbecore::Xmlio::Feed feedFPupTyp;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxtSrfActive(DbsWznm* dbswznm);
	bool evalTxfShoActive(DbsWznm* dbswznm);
	bool evalPupTypActive(DbsWznm* dbswznm);
	bool evalLstOccActive(DbsWznm* dbswznm);
	bool evalTxtImeActive(DbsWznm* dbswznm);
	bool evalButImeViewAvail(DbsWznm* dbswznm);
	bool evalButImeViewActive(DbsWznm* dbswznm);
	bool evalTxtTcoActive(DbsWznm* dbswznm);
	bool evalTxtIm2Active(DbsWznm* dbswznm);
	bool evalButIm2ViewAvail(DbsWznm* dbswznm);
	bool evalButIm2ViewActive(DbsWznm* dbswznm);
	bool evalPupCtyActive(DbsWznm* dbswznm);
	bool evalTxfDfvActive(DbsWznm* dbswznm);
	bool evalTxtPstActive(DbsWznm* dbswznm);
	bool evalButPstViewAvail(DbsWznm* dbswznm);
	bool evalButPstViewActive(DbsWznm* dbswznm);
	bool evalTxtStbActive(DbsWznm* dbswznm);
	bool evalButStbViewAvail(DbsWznm* dbswznm);
	bool evalButStbViewActive(DbsWznm* dbswznm);
	bool evalTxtVitActive(DbsWznm* dbswznm);
	bool evalButVitViewAvail(DbsWznm* dbswznm);
	bool evalButVitViewActive(DbsWznm* dbswznm);

public:
	PnlWznmIelDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmIelDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstOcc;
	Sbecore::Xmlio::Feed feedFPupCty;
	Sbecore::Xmlio::Feed feedFPupTyp;

	WznmMImpexpcol recIel;

	WznmJMImpexpcolStub recIelJstb;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshTxtOcc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecIel(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecIelJstb(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButImeViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButIm2ViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButStbViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVitViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmIel_vitEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmIel_stbEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmIel_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmIel_imeEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmIel_im2Eq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmIelUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmIelJstbMod_ielEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
