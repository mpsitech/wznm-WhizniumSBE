/**
	* \file PnlWznmTblDetail.h
	* job handler for job PnlWznmTblDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMTBLDETAIL_H
#define PNLWZNMTBLDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmTblDetailDo PnlWznmTblDetail::VecVDo

#define ContIacWznmTblDetail PnlWznmTblDetail::ContIac
#define ContInfWznmTblDetail PnlWznmTblDetail::ContInf
#define StatAppWznmTblDetail PnlWznmTblDetail::StatApp
#define StatShrWznmTblDetail PnlWznmTblDetail::StatShr
#define TagWznmTblDetail PnlWznmTblDetail::Tag

#define DpchAppWznmTblDetailData PnlWznmTblDetail::DpchAppData
#define DpchAppWznmTblDetailDo PnlWznmTblDetail::DpchAppDo
#define DpchEngWznmTblDetailData PnlWznmTblDetail::DpchEngData

/**
	* PnlWznmTblDetail
	*/
class PnlWznmTblDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmTblDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTREUVIEWCLICK = 3;
		static const Sbecore::uint BUTCARVIEWCLICK = 4;
		static const Sbecore::uint BUTUNQVIEWCLICK = 5;
		static const Sbecore::uint BUTPSTNEWCLICK = 6;
		static const Sbecore::uint BUTPSTDELETECLICK = 7;
		static const Sbecore::uint BUTPSTJTIEDITCLICK = 8;
		static const Sbecore::uint BUTPSTVERVIEWCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmTblDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint NUMFPUPRET = 3;
		static const Sbecore::uint NUMFLSTUNQ = 4;
		static const Sbecore::uint TXFUNQ = 5;
		static const Sbecore::uint TXFCMT = 6;
		static const Sbecore::uint NUMFPUPPSTJTI = 7;
		static const Sbecore::uint NUMFPUPPSTSCO = 8;
		static const Sbecore::uint NUMFPUPPSTATY = 9;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFLstUnq = 1, const std::string& TxfUnq = "", const std::string& TxfCmt = "", const Sbecore::uint numFPupPstJti = 1, const Sbecore::uint numFPupPstSco = 1, const Sbecore::uint numFPupPstAty = 1);

	public:
		std::string TxfSho;
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFLstUnq;
		std::string TxfUnq;
		std::string TxfCmt;
		Sbecore::uint numFPupPstJti;
		Sbecore::uint numFPupPstSco;
		Sbecore::uint numFPupPstAty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmTblDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTREU = 3;
		static const Sbecore::uint TXTCAR = 4;
		static const Sbecore::uint TXTPSTSRF = 5;
		static const Sbecore::uint TXTPSTTIT = 6;
		static const Sbecore::uint TXTPSTVER = 7;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtReu = "", const std::string& TxtCar = "", const std::string& TxtPstSrf = "", const std::string& TxtPstTit = "", const std::string& TxtPstVer = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtReu;
		std::string TxtCar;
		std::string TxtPstSrf;
		std::string TxtPstTit;
		std::string TxtPstVer;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmTblDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstUnqAlt = true, const Sbecore::uint LstUnqNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmTblDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFUNQVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXFSHOACTIVE = 5;
		static const Sbecore::uint PUPTYPACTIVE = 6;
		static const Sbecore::uint TXTVERACTIVE = 7;
		static const Sbecore::uint BUTVERVIEWAVAIL = 8;
		static const Sbecore::uint BUTVERVIEWACTIVE = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint TXTCARAVAIL = 13;
		static const Sbecore::uint TXTCARACTIVE = 14;
		static const Sbecore::uint BUTCARVIEWAVAIL = 15;
		static const Sbecore::uint BUTCARVIEWACTIVE = 16;
		static const Sbecore::uint LSTUNQAVAIL = 17;
		static const Sbecore::uint LSTUNQACTIVE = 18;
		static const Sbecore::uint BUTUNQVIEWAVAIL = 19;
		static const Sbecore::uint BUTUNQVIEWACTIVE = 20;
		static const Sbecore::uint TXFCMTACTIVE = 21;
		static const Sbecore::uint SEPPSTAVAIL = 22;
		static const Sbecore::uint HDGPSTAVAIL = 23;
		static const Sbecore::uint BUTPSTNEWAVAIL = 24;
		static const Sbecore::uint BUTPSTDELETEAVAIL = 25;
		static const Sbecore::uint TXTPSTSRFAVAIL = 26;
		static const Sbecore::uint TXTPSTSRFACTIVE = 27;
		static const Sbecore::uint PUPPSTJTIAVAIL = 28;
		static const Sbecore::uint PUPPSTJTIACTIVE = 29;
		static const Sbecore::uint BUTPSTJTIEDITAVAIL = 30;
		static const Sbecore::uint TXTPSTTITAVAIL = 31;
		static const Sbecore::uint TXTPSTTITACTIVE = 32;
		static const Sbecore::uint TXTPSTVERAVAIL = 33;
		static const Sbecore::uint TXTPSTVERACTIVE = 34;
		static const Sbecore::uint BUTPSTVERVIEWAVAIL = 35;
		static const Sbecore::uint BUTPSTVERVIEWACTIVE = 36;
		static const Sbecore::uint PUPPSTSCOAVAIL = 37;
		static const Sbecore::uint PUPPSTSCOACTIVE = 38;
		static const Sbecore::uint PUPPSTATYAVAIL = 39;
		static const Sbecore::uint PUPPSTATYACTIVE = 40;

	public:
		StatShr(const bool TxfUnqValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxtCarAvail = true, const bool TxtCarActive = true, const bool ButCarViewAvail = true, const bool ButCarViewActive = true, const bool LstUnqAvail = true, const bool LstUnqActive = true, const bool ButUnqViewAvail = true, const bool ButUnqViewActive = true, const bool TxfCmtActive = true, const bool SepPstAvail = true, const bool HdgPstAvail = true, const bool ButPstNewAvail = true, const bool ButPstDeleteAvail = true, const bool TxtPstSrfAvail = true, const bool TxtPstSrfActive = true, const bool PupPstJtiAvail = true, const bool PupPstJtiActive = true, const bool ButPstJtiEditAvail = true, const bool TxtPstTitAvail = true, const bool TxtPstTitActive = true, const bool TxtPstVerAvail = true, const bool TxtPstVerActive = true, const bool ButPstVerViewAvail = true, const bool ButPstVerViewActive = true, const bool PupPstScoAvail = true, const bool PupPstScoActive = true, const bool PupPstAtyAvail = true, const bool PupPstAtyActive = true);

	public:
		bool TxfUnqValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxtCarAvail;
		bool TxtCarActive;
		bool ButCarViewAvail;
		bool ButCarViewActive;
		bool LstUnqAvail;
		bool LstUnqActive;
		bool ButUnqViewAvail;
		bool ButUnqViewActive;
		bool TxfCmtActive;
		bool SepPstAvail;
		bool HdgPstAvail;
		bool ButPstNewAvail;
		bool ButPstDeleteAvail;
		bool TxtPstSrfAvail;
		bool TxtPstSrfActive;
		bool PupPstJtiAvail;
		bool PupPstJtiActive;
		bool ButPstJtiEditAvail;
		bool TxtPstTitAvail;
		bool TxtPstTitActive;
		bool TxtPstVerAvail;
		bool TxtPstVerActive;
		bool ButPstVerViewAvail;
		bool ButPstVerViewActive;
		bool PupPstScoAvail;
		bool PupPstScoActive;
		bool PupPstAtyAvail;
		bool PupPstAtyActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmTblDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmTblDetailData)
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
		* DpchAppDo (full: DpchAppWznmTblDetailDo)
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
		* DpchEngData (full: DpchEngWznmTblDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTUNQ = 4;
		static const Sbecore::uint FEEDFPUPPSTATY = 5;
		static const Sbecore::uint FEEDFPUPPSTJTI = 6;
		static const Sbecore::uint FEEDFPUPPSTSCO = 7;
		static const Sbecore::uint FEEDFPUPRET = 8;
		static const Sbecore::uint FEEDFPUPTYP = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint ALL = 13;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstUnq = NULL, Sbecore::Xmlio::Feed* feedFPupPstAty = NULL, Sbecore::Xmlio::Feed* feedFPupPstJti = NULL, Sbecore::Xmlio::Feed* feedFPupPstSco = NULL, Sbecore::Xmlio::Feed* feedFPupRet = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstUnq;
		Sbecore::Xmlio::Feed feedFPupPstAty;
		Sbecore::Xmlio::Feed feedFPupPstJti;
		Sbecore::Xmlio::Feed feedFPupPstSco;
		Sbecore::Xmlio::Feed feedFPupRet;
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
	bool evalTxtVerActive(DbsWznm* dbswznm);
	bool evalButVerViewAvail(DbsWznm* dbswznm);
	bool evalButVerViewActive(DbsWznm* dbswznm);
	bool evalTxtReuActive(DbsWznm* dbswznm);
	bool evalButReuViewAvail(DbsWznm* dbswznm);
	bool evalButReuViewActive(DbsWznm* dbswznm);
	bool evalTxtCarAvail(DbsWznm* dbswznm);
	bool evalTxtCarActive(DbsWznm* dbswznm);
	bool evalButCarViewAvail(DbsWznm* dbswznm);
	bool evalButCarViewActive(DbsWznm* dbswznm);
	bool evalLstUnqAvail(DbsWznm* dbswznm);
	bool evalLstUnqActive(DbsWznm* dbswznm);
	bool evalButUnqViewAvail(DbsWznm* dbswznm);
	bool evalButUnqViewActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);
	bool evalSepPstAvail(DbsWznm* dbswznm);
	bool evalHdgPstAvail(DbsWznm* dbswznm);
	bool evalButPstNewAvail(DbsWznm* dbswznm);
	bool evalButPstDeleteAvail(DbsWznm* dbswznm);
	bool evalTxtPstSrfAvail(DbsWznm* dbswznm);
	bool evalTxtPstSrfActive(DbsWznm* dbswznm);
	bool evalPupPstJtiAvail(DbsWznm* dbswznm);
	bool evalPupPstJtiActive(DbsWznm* dbswznm);
	bool evalButPstJtiEditAvail(DbsWznm* dbswznm);
	bool evalTxtPstTitAvail(DbsWznm* dbswznm);
	bool evalTxtPstTitActive(DbsWznm* dbswznm);
	bool evalTxtPstVerAvail(DbsWznm* dbswznm);
	bool evalTxtPstVerActive(DbsWznm* dbswznm);
	bool evalButPstVerViewAvail(DbsWznm* dbswznm);
	bool evalButPstVerViewActive(DbsWznm* dbswznm);
	bool evalPupPstScoAvail(DbsWznm* dbswznm);
	bool evalPupPstScoActive(DbsWznm* dbswznm);
	bool evalPupPstAtyAvail(DbsWznm* dbswznm);
	bool evalPupPstAtyActive(DbsWznm* dbswznm);

public:
	PnlWznmTblDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmTblDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstUnq;
	Sbecore::Xmlio::Feed feedFPupPstAty;
	Sbecore::Xmlio::Feed feedFPupPstJti;
	Sbecore::Xmlio::Feed feedFPupPstSco;
	Sbecore::Xmlio::Feed feedFPupRet;
	Sbecore::Xmlio::Feed feedFPupTyp;

	WznmMTable recTbl;
	Sbecore::uint ixWSubsetTbl;

	WznmMPreset recPst;

	WznmJMPresetTitle recPstJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstUnq(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshUnq(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPstJti(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecTbl(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecPst(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecPstJtit(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDoButReuViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCarViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButUnqViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstNewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstDeleteClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstJtiEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstVerViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmTbl_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTbl_typEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTbl_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTbl_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTbl_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTbl_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTbl_carEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmPstUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmTblUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmPstJtitMod_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
