/**
	* \file PnlWznmVecDetail.h
	* job handler for job PnlWznmVecDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMVECDETAIL_H
#define PNLWZNMVECDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmVecDetailDo PnlWznmVecDetail::VecVDo

#define ContIacWznmVecDetail PnlWznmVecDetail::ContIac
#define ContInfWznmVecDetail PnlWznmVecDetail::ContInf
#define StatAppWznmVecDetail PnlWznmVecDetail::StatApp
#define StatShrWznmVecDetail PnlWznmVecDetail::StatShr
#define TagWznmVecDetail PnlWznmVecDetail::Tag

#define DpchAppWznmVecDetailData PnlWznmVecDetail::DpchAppData
#define DpchAppWznmVecDetailDo PnlWznmVecDetail::DpchAppDo
#define DpchEngWznmVecDetailData PnlWznmVecDetail::DpchEngData

/**
	* PnlWznmVecDetail
	*/
class PnlWznmVecDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmVecDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTHKUVIEWCLICK = 3;
		static const Sbecore::uint BUTTGREDITCLICK = 4;
		static const Sbecore::uint BUTOPTEDITCLICK = 5;
		static const Sbecore::uint BUTPSTNEWCLICK = 6;
		static const Sbecore::uint BUTPSTDELETECLICK = 7;
		static const Sbecore::uint BUTPSTJTIEDITCLICK = 8;
		static const Sbecore::uint BUTPSTVERVIEWCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmVecDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFPUPHKT = 2;
		static const Sbecore::uint NUMFPUPTGR = 3;
		static const Sbecore::uint TXFTGR = 4;
		static const Sbecore::uint NUMSFLSTOPT = 5;
		static const Sbecore::uint TXFOPT = 6;
		static const Sbecore::uint NUMFPUPPSTJTI = 7;
		static const Sbecore::uint NUMFPUPPSTSCO = 8;
		static const Sbecore::uint NUMFPUPPSTATY = 9;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupHkt = 1, const Sbecore::uint numFPupTgr = 1, const std::string& TxfTgr = "", const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "", const Sbecore::uint numFPupPstJti = 1, const Sbecore::uint numFPupPstSco = 1, const Sbecore::uint numFPupPstAty = 1);

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupHkt;
		Sbecore::uint numFPupTgr;
		std::string TxfTgr;
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;
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
	  * ContInf (full: ContInfWznmVecDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTHKU = 3;
		static const Sbecore::uint TXTPSTSRF = 4;
		static const Sbecore::uint TXTPSTTIT = 5;
		static const Sbecore::uint TXTPSTVER = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtHku = "", const std::string& TxtPstSrf = "", const std::string& TxtPstTit = "", const std::string& TxtPstVer = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtHku;
		std::string TxtPstSrf;
		std::string TxtPstTit;
		std::string TxtPstVer;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmVecDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool PupTgrAlt = false, const bool LstOptAlt = true, const Sbecore::uint LstOptNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmVecDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTGRVALID = 1;
		static const Sbecore::uint TXFOPTVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint PUPTYPACTIVE = 6;
		static const Sbecore::uint TXTVERACTIVE = 7;
		static const Sbecore::uint BUTVERVIEWAVAIL = 8;
		static const Sbecore::uint BUTVERVIEWACTIVE = 9;
		static const Sbecore::uint TXTHKUACTIVE = 10;
		static const Sbecore::uint BUTHKUVIEWAVAIL = 11;
		static const Sbecore::uint BUTHKUVIEWACTIVE = 12;
		static const Sbecore::uint PUPTGRACTIVE = 13;
		static const Sbecore::uint BUTTGREDITAVAIL = 14;
		static const Sbecore::uint LSTOPTACTIVE = 15;
		static const Sbecore::uint BUTOPTEDITAVAIL = 16;
		static const Sbecore::uint BUTPSTNEWAVAIL = 17;
		static const Sbecore::uint BUTPSTDELETEAVAIL = 18;
		static const Sbecore::uint TXTPSTSRFAVAIL = 19;
		static const Sbecore::uint TXTPSTSRFACTIVE = 20;
		static const Sbecore::uint PUPPSTJTIAVAIL = 21;
		static const Sbecore::uint PUPPSTJTIACTIVE = 22;
		static const Sbecore::uint BUTPSTJTIEDITAVAIL = 23;
		static const Sbecore::uint TXTPSTTITAVAIL = 24;
		static const Sbecore::uint TXTPSTTITACTIVE = 25;
		static const Sbecore::uint TXTPSTVERAVAIL = 26;
		static const Sbecore::uint TXTPSTVERACTIVE = 27;
		static const Sbecore::uint BUTPSTVERVIEWAVAIL = 28;
		static const Sbecore::uint BUTPSTVERVIEWACTIVE = 29;
		static const Sbecore::uint PUPPSTSCOAVAIL = 30;
		static const Sbecore::uint PUPPSTSCOACTIVE = 31;
		static const Sbecore::uint PUPPSTATYAVAIL = 32;
		static const Sbecore::uint PUPPSTATYACTIVE = 33;

	public:
		StatShr(const bool TxfTgrValid = false, const bool TxfOptValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtHkuActive = true, const bool ButHkuViewAvail = true, const bool ButHkuViewActive = true, const bool PupTgrActive = true, const bool ButTgrEditAvail = true, const bool LstOptActive = true, const bool ButOptEditAvail = true, const bool ButPstNewAvail = true, const bool ButPstDeleteAvail = true, const bool TxtPstSrfAvail = true, const bool TxtPstSrfActive = true, const bool PupPstJtiAvail = true, const bool PupPstJtiActive = true, const bool ButPstJtiEditAvail = true, const bool TxtPstTitAvail = true, const bool TxtPstTitActive = true, const bool TxtPstVerAvail = true, const bool TxtPstVerActive = true, const bool ButPstVerViewAvail = true, const bool ButPstVerViewActive = true, const bool PupPstScoAvail = true, const bool PupPstScoActive = true, const bool PupPstAtyAvail = true, const bool PupPstAtyActive = true);

	public:
		bool TxfTgrValid;
		bool TxfOptValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtHkuActive;
		bool ButHkuViewAvail;
		bool ButHkuViewActive;
		bool PupTgrActive;
		bool ButTgrEditAvail;
		bool LstOptActive;
		bool ButOptEditAvail;
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
		* Tag (full: TagWznmVecDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmVecDetailData)
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
		* DpchAppDo (full: DpchAppWznmVecDetailDo)
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
		* DpchEngData (full: DpchEngWznmVecDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOPT = 4;
		static const Sbecore::uint FEEDFPUPHKT = 5;
		static const Sbecore::uint FEEDFPUPPSTATY = 6;
		static const Sbecore::uint FEEDFPUPPSTJTI = 7;
		static const Sbecore::uint FEEDFPUPPSTSCO = 8;
		static const Sbecore::uint FEEDFPUPTGR = 9;
		static const Sbecore::uint FEEDFPUPTYP = 10;
		static const Sbecore::uint STATAPP = 11;
		static const Sbecore::uint STATSHR = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint ALL = 14;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstOpt = NULL, Sbecore::Xmlio::Feed* feedFPupHkt = NULL, Sbecore::Xmlio::Feed* feedFPupPstAty = NULL, Sbecore::Xmlio::Feed* feedFPupPstJti = NULL, Sbecore::Xmlio::Feed* feedFPupPstSco = NULL, Sbecore::Xmlio::Feed* feedFPupTgr = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstOpt;
		Sbecore::Xmlio::Feed feedFPupHkt;
		Sbecore::Xmlio::Feed feedFPupPstAty;
		Sbecore::Xmlio::Feed feedFPupPstJti;
		Sbecore::Xmlio::Feed feedFPupPstSco;
		Sbecore::Xmlio::Feed feedFPupTgr;
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
	bool evalPupTypActive(DbsWznm* dbswznm);
	bool evalTxtVerActive(DbsWznm* dbswznm);
	bool evalButVerViewAvail(DbsWznm* dbswznm);
	bool evalButVerViewActive(DbsWznm* dbswznm);
	bool evalTxtHkuActive(DbsWznm* dbswznm);
	bool evalButHkuViewAvail(DbsWznm* dbswznm);
	bool evalButHkuViewActive(DbsWznm* dbswznm);
	bool evalPupTgrActive(DbsWznm* dbswznm);
	bool evalButTgrEditAvail(DbsWznm* dbswznm);
	bool evalLstOptActive(DbsWznm* dbswznm);
	bool evalButOptEditAvail(DbsWznm* dbswznm);
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
	PnlWznmVecDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmVecDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstOpt;
	Sbecore::Xmlio::Feed feedFPupHkt;
	Sbecore::Xmlio::Feed feedFPupPstAty;
	Sbecore::Xmlio::Feed feedFPupPstJti;
	Sbecore::Xmlio::Feed feedFPupPstSco;
	Sbecore::Xmlio::Feed feedFPupTgr;
	Sbecore::Xmlio::Feed feedFPupTyp;

	WznmMVector recVec;
	Sbecore::uint ixWSubsetVec;

	WznmMPreset recPst;

	WznmJMPresetTitle recPstJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshPupTgr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfTgr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTgr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPstJti(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecVec(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecPst(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecPstJtit(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVerViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButHkuViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButTgrEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButOptEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstNewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstDeleteClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstJtiEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstVerViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmPstJtitMod_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmKlsAkeyMod_klsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWznmVecUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmPstUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVec_hktEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmVec_hkuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVec_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmVec_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVec_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVec_typEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmPst_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif

