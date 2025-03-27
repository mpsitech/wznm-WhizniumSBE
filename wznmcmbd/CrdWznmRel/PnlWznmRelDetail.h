/**
	* \file PnlWznmRelDetail.h
	* job handler for job PnlWznmRelDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMRELDETAIL_H
#define PNLWZNMRELDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmRelDetailDo PnlWznmRelDetail::VecVDo

#define ContIacWznmRelDetail PnlWznmRelDetail::ContIac
#define ContInfWznmRelDetail PnlWznmRelDetail::ContInf
#define StatAppWznmRelDetail PnlWznmRelDetail::StatApp
#define StatShrWznmRelDetail PnlWznmRelDetail::StatShr
#define TagWznmRelDetail PnlWznmRelDetail::Tag

#define DpchAppWznmRelDetailData PnlWznmRelDetail::DpchAppData
#define DpchAppWznmRelDetailDo PnlWznmRelDetail::DpchAppDo
#define DpchEngWznmRelDetailData PnlWznmRelDetail::DpchEngData

/**
	* PnlWznmRelDetail
	*/
class PnlWznmRelDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmRelDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTFRSVIEWCLICK = 2;
		static const Sbecore::uint BUTTOSVIEWCLICK = 3;
		static const Sbecore::uint BUTCLUVIEWCLICK = 4;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 5;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 6;
		static const Sbecore::uint BUTVERVIEWCLICK = 7;
		static const Sbecore::uint BUTSUPVIEWCLICK = 8;
		static const Sbecore::uint BUTOPTEDITCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmRelDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint TXFPFX = 3;
		static const Sbecore::uint NUMSFLSTOPT = 4;
		static const Sbecore::uint TXFOPT = 5;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFLstClu = 1, const std::string& TxfPfx = "", const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFLstClu;
		std::string TxfPfx;
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmRelDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTFRT = 1;
		static const Sbecore::uint TXTFRS = 2;
		static const Sbecore::uint TXTTOT = 3;
		static const Sbecore::uint TXTTOS = 4;
		static const Sbecore::uint TXTCLU = 5;
		static const Sbecore::uint TXTVER = 6;
		static const Sbecore::uint TXTSUP = 7;
		static const Sbecore::uint TXTTBL = 8;

	public:
		ContInf(const std::string& TxtFrt = "", const std::string& TxtFrs = "", const std::string& TxtTot = "", const std::string& TxtTos = "", const std::string& TxtClu = "", const std::string& TxtVer = "", const std::string& TxtSup = "", const std::string& TxtTbl = "");

	public:
		std::string TxtFrt;
		std::string TxtFrs;
		std::string TxtTot;
		std::string TxtTos;
		std::string TxtClu;
		std::string TxtVer;
		std::string TxtSup;
		std::string TxtTbl;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmRelDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstCluAlt = true, const bool LstOptAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1, const Sbecore::uint LstOptNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstCluAlt = true, const bool LstOptAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1, const Sbecore::uint LstOptNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmRelDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTFRTACTIVE = 3;
		static const Sbecore::uint TXTFRSACTIVE = 4;
		static const Sbecore::uint BUTFRSVIEWAVAIL = 5;
		static const Sbecore::uint BUTFRSVIEWACTIVE = 6;
		static const Sbecore::uint TXTTOTACTIVE = 7;
		static const Sbecore::uint TXTTOSACTIVE = 8;
		static const Sbecore::uint BUTTOSVIEWAVAIL = 9;
		static const Sbecore::uint BUTTOSVIEWACTIVE = 10;
		static const Sbecore::uint PUPTYPACTIVE = 11;
		static const Sbecore::uint LSTCLUACTIVE = 12;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 13;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 14;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 15;
		static const Sbecore::uint TXTVERACTIVE = 16;
		static const Sbecore::uint BUTVERVIEWAVAIL = 17;
		static const Sbecore::uint BUTVERVIEWACTIVE = 18;
		static const Sbecore::uint TXTSUPACTIVE = 19;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 20;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 21;
		static const Sbecore::uint TXTTBLACTIVE = 22;
		static const Sbecore::uint TXFPFXACTIVE = 23;
		static const Sbecore::uint LSTOPTACTIVE = 24;
		static const Sbecore::uint TXFOPTVALID = 25;
		static const Sbecore::uint BUTOPTEDITAVAIL = 26;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtFrtActive = true, const bool TxtFrsActive = true, const bool ButFrsViewAvail = true, const bool ButFrsViewActive = true, const bool TxtTotActive = true, const bool TxtTosActive = true, const bool ButTosViewAvail = true, const bool ButTosViewActive = true, const bool PupTypActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTblActive = true, const bool TxfPfxActive = true, const bool LstOptActive = true, const bool TxfOptValid = false, const bool ButOptEditAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtFrtActive;
		bool TxtFrsActive;
		bool ButFrsViewAvail;
		bool ButFrsViewActive;
		bool TxtTotActive;
		bool TxtTosActive;
		bool ButTosViewAvail;
		bool ButTosViewActive;
		bool PupTypActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtTblActive;
		bool TxfPfxActive;
		bool LstOptActive;
		bool TxfOptValid;
		bool ButOptEditAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmRelDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmRelDetailData)
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
		* DpchAppDo (full: DpchAppWznmRelDetailDo)
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
		* DpchEngData (full: DpchEngWznmRelDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFLSTOPT = 5;
		static const Sbecore::uint FEEDFPUPTYP = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstClu = NULL, Sbecore::Feed* feedFLstOpt = NULL, Sbecore::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFLstOpt;
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
	bool evalTxtFrtActive(DbsWznm* dbswznm);
	bool evalTxtFrsActive(DbsWznm* dbswznm);
	bool evalButFrsViewAvail(DbsWznm* dbswznm);
	bool evalButFrsViewActive(DbsWznm* dbswznm);
	bool evalTxtTotActive(DbsWznm* dbswznm);
	bool evalTxtTosActive(DbsWznm* dbswznm);
	bool evalButTosViewAvail(DbsWznm* dbswznm);
	bool evalButTosViewActive(DbsWznm* dbswznm);
	bool evalPupTypActive(DbsWznm* dbswznm);
	bool evalLstCluActive(DbsWznm* dbswznm);
	bool evalButCluViewActive(DbsWznm* dbswznm);
	bool evalButCluClusterAvail(DbsWznm* dbswznm);
	bool evalButCluUnclusterAvail(DbsWznm* dbswznm);
	bool evalTxtVerActive(DbsWznm* dbswznm);
	bool evalButVerViewAvail(DbsWznm* dbswznm);
	bool evalButVerViewActive(DbsWznm* dbswznm);
	bool evalTxtSupActive(DbsWznm* dbswznm);
	bool evalButSupViewAvail(DbsWznm* dbswznm);
	bool evalButSupViewActive(DbsWznm* dbswznm);
	bool evalTxtTblActive(DbsWznm* dbswznm);
	bool evalTxfPfxActive(DbsWznm* dbswznm);
	bool evalLstOptActive(DbsWznm* dbswznm);
	bool evalButOptEditAvail(DbsWznm* dbswznm);

public:
	PnlWznmRelDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmRelDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstClu;
	Sbecore::Feed feedFLstOpt;
	Sbecore::Feed feedFPupTyp;

	WznmMRelation recRel;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstClu(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshClu(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecRel(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButFrsViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButTosViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVerViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButOptEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmRelMod_cluEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmKlsAkeyMod_klsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWznmRelUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmRel_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmRel_tosEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmRel_supEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmRel_frsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmRel_cluEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
