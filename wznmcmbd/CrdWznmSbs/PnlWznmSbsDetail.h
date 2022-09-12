/**
	* \file PnlWznmSbsDetail.h
	* job handler for job PnlWznmSbsDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMSBSDETAIL_H
#define PNLWZNMSBSDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmSbsDetailDo PnlWznmSbsDetail::VecVDo

#define ContIacWznmSbsDetail PnlWznmSbsDetail::ContIac
#define ContInfWznmSbsDetail PnlWznmSbsDetail::ContInf
#define StatAppWznmSbsDetail PnlWznmSbsDetail::StatApp
#define StatShrWznmSbsDetail PnlWznmSbsDetail::StatShr
#define TagWznmSbsDetail PnlWznmSbsDetail::Tag

#define DpchAppWznmSbsDetailData PnlWznmSbsDetail::DpchAppData
#define DpchAppWznmSbsDetailDo PnlWznmSbsDetail::DpchAppDo
#define DpchEngWznmSbsDetailData PnlWznmSbsDetail::DpchEngData

/**
	* PnlWznmSbsDetail
	*/
class PnlWznmSbsDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmSbsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCARVIEWCLICK = 2;
		static const Sbecore::uint BUTPSTNEWCLICK = 3;
		static const Sbecore::uint BUTPSTDELETECLICK = 4;
		static const Sbecore::uint BUTPSTJTIEDITCLICK = 5;
		static const Sbecore::uint BUTPSTVERVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmSbsDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint TXFCND = 2;
		static const Sbecore::uint TXFCMT = 3;
		static const Sbecore::uint NUMFPUPPSTJTI = 4;
		static const Sbecore::uint NUMFPUPPSTSCO = 5;
		static const Sbecore::uint NUMFPUPPSTATY = 6;

	public:
		ContIac(const std::string& TxfSho = "", const std::string& TxfCnd = "", const std::string& TxfCmt = "", const Sbecore::uint numFPupPstJti = 1, const Sbecore::uint numFPupPstSco = 1, const Sbecore::uint numFPupPstAty = 1);

	public:
		std::string TxfSho;
		std::string TxfCnd;
		std::string TxfCmt;
		Sbecore::uint numFPupPstJti;
		Sbecore::uint numFPupPstSco;
		Sbecore::uint numFPupPstAty;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmSbsDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTBL = 2;
		static const Sbecore::uint TXTCAR = 3;
		static const Sbecore::uint TXTPSTSRF = 4;
		static const Sbecore::uint TXTPSTTIT = 5;
		static const Sbecore::uint TXTPSTVER = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTbl = "", const std::string& TxtCar = "", const std::string& TxtPstSrf = "", const std::string& TxtPstTit = "", const std::string& TxtPstVer = "");

	public:
		std::string TxtSrf;
		std::string TxtTbl;
		std::string TxtCar;
		std::string TxtPstSrf;
		std::string TxtPstTit;
		std::string TxtPstVer;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmSbsDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmSbsDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFSHOACTIVE = 4;
		static const Sbecore::uint TXTTBLACTIVE = 5;
		static const Sbecore::uint TXTCARACTIVE = 6;
		static const Sbecore::uint BUTCARVIEWAVAIL = 7;
		static const Sbecore::uint BUTCARVIEWACTIVE = 8;
		static const Sbecore::uint TXFCNDACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;
		static const Sbecore::uint BUTPSTNEWAVAIL = 11;
		static const Sbecore::uint BUTPSTDELETEAVAIL = 12;
		static const Sbecore::uint TXTPSTSRFAVAIL = 13;
		static const Sbecore::uint TXTPSTSRFACTIVE = 14;
		static const Sbecore::uint PUPPSTJTIAVAIL = 15;
		static const Sbecore::uint PUPPSTJTIACTIVE = 16;
		static const Sbecore::uint BUTPSTJTIEDITAVAIL = 17;
		static const Sbecore::uint TXTPSTTITAVAIL = 18;
		static const Sbecore::uint TXTPSTTITACTIVE = 19;
		static const Sbecore::uint TXTPSTVERAVAIL = 20;
		static const Sbecore::uint TXTPSTVERACTIVE = 21;
		static const Sbecore::uint BUTPSTVERVIEWAVAIL = 22;
		static const Sbecore::uint BUTPSTVERVIEWACTIVE = 23;
		static const Sbecore::uint PUPPSTSCOAVAIL = 24;
		static const Sbecore::uint PUPPSTSCOACTIVE = 25;
		static const Sbecore::uint PUPPSTATYAVAIL = 26;
		static const Sbecore::uint PUPPSTATYACTIVE = 27;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool TxtTblActive = true, const bool TxtCarActive = true, const bool ButCarViewAvail = true, const bool ButCarViewActive = true, const bool TxfCndActive = true, const bool TxfCmtActive = true, const bool ButPstNewAvail = true, const bool ButPstDeleteAvail = true, const bool TxtPstSrfAvail = true, const bool TxtPstSrfActive = true, const bool PupPstJtiAvail = true, const bool PupPstJtiActive = true, const bool ButPstJtiEditAvail = true, const bool TxtPstTitAvail = true, const bool TxtPstTitActive = true, const bool TxtPstVerAvail = true, const bool TxtPstVerActive = true, const bool ButPstVerViewAvail = true, const bool ButPstVerViewActive = true, const bool PupPstScoAvail = true, const bool PupPstScoActive = true, const bool PupPstAtyAvail = true, const bool PupPstAtyActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool TxtTblActive;
		bool TxtCarActive;
		bool ButCarViewAvail;
		bool ButCarViewActive;
		bool TxfCndActive;
		bool TxfCmtActive;
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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmSbsDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmSbsDetailData)
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
		* DpchAppDo (full: DpchAppWznmSbsDetailDo)
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
		* DpchEngData (full: DpchEngWznmSbsDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPPSTATY = 4;
		static const Sbecore::uint FEEDFPUPPSTJTI = 5;
		static const Sbecore::uint FEEDFPUPPSTSCO = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupPstAty = NULL, Sbecore::Feed* feedFPupPstJti = NULL, Sbecore::Feed* feedFPupPstSco = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupPstAty;
		Sbecore::Feed feedFPupPstJti;
		Sbecore::Feed feedFPupPstSco;
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
	bool evalTxtTblActive(DbsWznm* dbswznm);
	bool evalTxtCarActive(DbsWznm* dbswznm);
	bool evalButCarViewAvail(DbsWznm* dbswznm);
	bool evalButCarViewActive(DbsWznm* dbswznm);
	bool evalTxfCndActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);
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
	PnlWznmSbsDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmSbsDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupPstAty;
	Sbecore::Feed feedFPupPstJti;
	Sbecore::Feed feedFPupPstSco;

	WznmMSubset recSbs;

	WznmMPreset recPst;

	WznmJMPresetTitle recPstJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshPstJti(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecSbs(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
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
	void handleDpchAppDoButCarViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstNewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstDeleteClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstJtiEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstVerViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmPstJtitMod_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSbsUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmPstUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSbs_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSbs_carEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
