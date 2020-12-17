/**
	* \file PnlWznmTcoDetail.h
	* job handler for job PnlWznmTcoDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMTCODETAIL_H
#define PNLWZNMTCODETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmTcoDetailDo PnlWznmTcoDetail::VecVDo

#define ContIacWznmTcoDetail PnlWznmTcoDetail::ContIac
#define ContInfWznmTcoDetail PnlWznmTcoDetail::ContInf
#define StatAppWznmTcoDetail PnlWznmTcoDetail::StatApp
#define StatShrWznmTcoDetail PnlWznmTcoDetail::StatShr
#define TagWznmTcoDetail PnlWznmTcoDetail::Tag

#define DpchAppWznmTcoDetailData PnlWznmTcoDetail::DpchAppData
#define DpchAppWznmTcoDetailDo PnlWznmTcoDetail::DpchAppDo
#define DpchEngWznmTcoDetailData PnlWznmTcoDetail::DpchEngData

/**
	* PnlWznmTcoDetail
	*/
class PnlWznmTcoDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmTcoDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTTBLVIEWCLICK = 2;
		static const Sbecore::uint BUTSBSVIEWCLICK = 3;
		static const Sbecore::uint BUTRELVIEWCLICK = 4;
		static const Sbecore::uint BUTFCUVIEWCLICK = 5;
		static const Sbecore::uint BUTOPTEDITCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmTcoDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint NUMFPUPFCT = 3;
		static const Sbecore::uint NUMFPUPSTY = 4;
		static const Sbecore::uint NUMFPUPAXF = 5;
		static const Sbecore::uint NUMSFLSTOPT = 6;
		static const Sbecore::uint TXFOPT = 7;
		static const Sbecore::uint CHKPNC = 8;
		static const Sbecore::uint CHKEPO = 9;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupFct = 1, const Sbecore::uint numFPupSty = 1, const Sbecore::uint numFPupAxf = 1, const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "", const bool ChkPnc = false, const bool ChkEpo = false);

	public:
		std::string TxfSho;
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupFct;
		Sbecore::uint numFPupSty;
		Sbecore::uint numFPupAxf;
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;
		bool ChkPnc;
		bool ChkEpo;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmTcoDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTBL = 2;
		static const Sbecore::uint TXTSBS = 3;
		static const Sbecore::uint TXTREL = 4;
		static const Sbecore::uint TXTFCU = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTbl = "", const std::string& TxtSbs = "", const std::string& TxtRel = "", const std::string& TxtFcu = "");

	public:
		std::string TxtSrf;
		std::string TxtTbl;
		std::string TxtSbs;
		std::string TxtRel;
		std::string TxtFcu;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmTcoDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOptAlt = true, const Sbecore::uint LstOptNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmTcoDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFOPTVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXFSHOACTIVE = 5;
		static const Sbecore::uint PUPTYPACTIVE = 6;
		static const Sbecore::uint TXTTBLACTIVE = 7;
		static const Sbecore::uint BUTTBLVIEWAVAIL = 8;
		static const Sbecore::uint BUTTBLVIEWACTIVE = 9;
		static const Sbecore::uint TXTSBSAVAIL = 10;
		static const Sbecore::uint TXTSBSACTIVE = 11;
		static const Sbecore::uint BUTSBSVIEWAVAIL = 12;
		static const Sbecore::uint BUTSBSVIEWACTIVE = 13;
		static const Sbecore::uint TXTRELAVAIL = 14;
		static const Sbecore::uint TXTRELACTIVE = 15;
		static const Sbecore::uint BUTRELVIEWAVAIL = 16;
		static const Sbecore::uint BUTRELVIEWACTIVE = 17;
		static const Sbecore::uint TXTFCUAVAIL = 18;
		static const Sbecore::uint TXTFCUACTIVE = 19;
		static const Sbecore::uint BUTFCUVIEWAVAIL = 20;
		static const Sbecore::uint BUTFCUVIEWACTIVE = 21;
		static const Sbecore::uint PUPSTYACTIVE = 22;
		static const Sbecore::uint PUPAXFACTIVE = 23;
		static const Sbecore::uint LSTOPTACTIVE = 24;
		static const Sbecore::uint BUTOPTEDITAVAIL = 25;
		static const Sbecore::uint CHKPNCACTIVE = 26;
		static const Sbecore::uint CHKEPOACTIVE = 27;

	public:
		StatShr(const bool TxfOptValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupTypActive = true, const bool TxtTblActive = true, const bool ButTblViewAvail = true, const bool ButTblViewActive = true, const bool TxtSbsAvail = true, const bool TxtSbsActive = true, const bool ButSbsViewAvail = true, const bool ButSbsViewActive = true, const bool TxtRelAvail = true, const bool TxtRelActive = true, const bool ButRelViewAvail = true, const bool ButRelViewActive = true, const bool TxtFcuAvail = true, const bool TxtFcuActive = true, const bool ButFcuViewAvail = true, const bool ButFcuViewActive = true, const bool PupStyActive = true, const bool PupAxfActive = true, const bool LstOptActive = true, const bool ButOptEditAvail = true, const bool ChkPncActive = true, const bool ChkEpoActive = true);

	public:
		bool TxfOptValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupTypActive;
		bool TxtTblActive;
		bool ButTblViewAvail;
		bool ButTblViewActive;
		bool TxtSbsAvail;
		bool TxtSbsActive;
		bool ButSbsViewAvail;
		bool ButSbsViewActive;
		bool TxtRelAvail;
		bool TxtRelActive;
		bool ButRelViewAvail;
		bool ButRelViewActive;
		bool TxtFcuAvail;
		bool TxtFcuActive;
		bool ButFcuViewAvail;
		bool ButFcuViewActive;
		bool PupStyActive;
		bool PupAxfActive;
		bool LstOptActive;
		bool ButOptEditAvail;
		bool ChkPncActive;
		bool ChkEpoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmTcoDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmTcoDetailData)
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
		* DpchAppDo (full: DpchAppWznmTcoDetailDo)
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
		* DpchEngData (full: DpchEngWznmTcoDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOPT = 4;
		static const Sbecore::uint FEEDFPUPAXF = 5;
		static const Sbecore::uint FEEDFPUPFCT = 6;
		static const Sbecore::uint FEEDFPUPSTY = 7;
		static const Sbecore::uint FEEDFPUPTYP = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstOpt = NULL, Sbecore::Xmlio::Feed* feedFPupAxf = NULL, Sbecore::Xmlio::Feed* feedFPupFct = NULL, Sbecore::Xmlio::Feed* feedFPupSty = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstOpt;
		Sbecore::Xmlio::Feed feedFPupAxf;
		Sbecore::Xmlio::Feed feedFPupFct;
		Sbecore::Xmlio::Feed feedFPupSty;
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
	bool evalTxtTblActive(DbsWznm* dbswznm);
	bool evalButTblViewAvail(DbsWznm* dbswznm);
	bool evalButTblViewActive(DbsWznm* dbswznm);
	bool evalTxtSbsAvail(DbsWznm* dbswznm);
	bool evalTxtSbsActive(DbsWznm* dbswznm);
	bool evalButSbsViewAvail(DbsWznm* dbswznm);
	bool evalButSbsViewActive(DbsWznm* dbswznm);
	bool evalTxtRelAvail(DbsWznm* dbswznm);
	bool evalTxtRelActive(DbsWznm* dbswznm);
	bool evalButRelViewAvail(DbsWznm* dbswznm);
	bool evalButRelViewActive(DbsWznm* dbswznm);
	bool evalTxtFcuAvail(DbsWznm* dbswznm);
	bool evalTxtFcuActive(DbsWznm* dbswznm);
	bool evalButFcuViewAvail(DbsWznm* dbswznm);
	bool evalButFcuViewActive(DbsWznm* dbswznm);
	bool evalPupStyActive(DbsWznm* dbswznm);
	bool evalPupAxfActive(DbsWznm* dbswznm);
	bool evalLstOptActive(DbsWznm* dbswznm);
	bool evalButOptEditAvail(DbsWznm* dbswznm);
	bool evalChkPncActive(DbsWznm* dbswznm);
	bool evalChkEpoActive(DbsWznm* dbswznm);

public:
	PnlWznmTcoDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmTcoDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstOpt;
	Sbecore::Xmlio::Feed feedFPupAxf;
	Sbecore::Xmlio::Feed feedFPupFct;
	Sbecore::Xmlio::Feed feedFPupSty;
	Sbecore::Xmlio::Feed feedFPupTyp;

	WznmMTablecol recTco;
	Sbecore::uint ixWSubsetTco;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecTco(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButTblViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSbsViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRelViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButFcuViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButOptEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmKlsAkeyMod_klsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWznmTcoUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmTco_tblEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTco_tbl_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTco_sbsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTco_relEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTco_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTco_fcuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTco_fctEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
