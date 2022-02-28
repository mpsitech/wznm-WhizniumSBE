/**
	* \file PnlWznmFilDetail.h
	* job handler for job PnlWznmFilDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMFILDETAIL_H
#define PNLWZNMFILDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmFilDetailDo PnlWznmFilDetail::VecVDo

#define ContIacWznmFilDetail PnlWznmFilDetail::ContIac
#define ContInfWznmFilDetail PnlWznmFilDetail::ContInf
#define StatAppWznmFilDetail PnlWznmFilDetail::StatApp
#define StatShrWznmFilDetail PnlWznmFilDetail::StatShr
#define TagWznmFilDetail PnlWznmFilDetail::Tag

#define DpchAppWznmFilDetailData PnlWznmFilDetail::DpchAppData
#define DpchAppWznmFilDetailDo PnlWznmFilDetail::DpchAppDo
#define DpchEngWznmFilDetailData PnlWznmFilDetail::DpchEngData

/**
	* PnlWznmFilDetail
	*/
class PnlWznmFilDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmFilDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTREUVIEWCLICK = 5;
		static const Sbecore::uint BUTCNTEDITCLICK = 6;
		static const Sbecore::uint BUTMIMEDITCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmFilDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFFNM = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint NUMFPUPRET = 3;
		static const Sbecore::uint NUMFPUPCNT = 4;
		static const Sbecore::uint TXFCNT = 5;
		static const Sbecore::uint TXFACV = 6;
		static const Sbecore::uint TXFANM = 7;
		static const Sbecore::uint NUMFPUPMIM = 8;
		static const Sbecore::uint TXFMIM = 9;
		static const Sbecore::uint TXFSIZ = 10;
		static const Sbecore::uint TXFCMT = 11;

	public:
		ContIac(const std::string& TxfFnm = "", const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupCnt = 1, const std::string& TxfCnt = "", const std::string& TxfAcv = "", const std::string& TxfAnm = "", const Sbecore::uint numFPupMim = 1, const std::string& TxfMim = "", const std::string& TxfSiz = "", const std::string& TxfCmt = "");

	public:
		std::string TxfFnm;
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupCnt;
		std::string TxfCnt;
		std::string TxfAcv;
		std::string TxfAnm;
		Sbecore::uint numFPupMim;
		std::string TxfMim;
		std::string TxfSiz;
		std::string TxfCmt;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmFilDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTCLU = 1;
		static const Sbecore::uint TXTREU = 2;

	public:
		ContInf(const std::string& TxtClu = "", const std::string& TxtReu = "");

	public:
		std::string TxtClu;
		std::string TxtReu;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmFilDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmFilDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCNTVALID = 1;
		static const Sbecore::uint TXFMIMVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXFFNMACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint PUPCNTACTIVE = 13;
		static const Sbecore::uint BUTCNTEDITAVAIL = 14;
		static const Sbecore::uint TXFACVACTIVE = 15;
		static const Sbecore::uint TXFANMACTIVE = 16;
		static const Sbecore::uint PUPMIMACTIVE = 17;
		static const Sbecore::uint BUTMIMEDITAVAIL = 18;
		static const Sbecore::uint TXFSIZACTIVE = 19;
		static const Sbecore::uint TXFCMTACTIVE = 20;

	public:
		StatShr(const bool TxfCntValid = false, const bool TxfMimValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfFnmActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupCntActive = true, const bool ButCntEditAvail = true, const bool TxfAcvActive = true, const bool TxfAnmActive = true, const bool PupMimActive = true, const bool ButMimEditAvail = true, const bool TxfSizActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfCntValid;
		bool TxfMimValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfFnmActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool PupCntActive;
		bool ButCntEditAvail;
		bool TxfAcvActive;
		bool TxfAnmActive;
		bool PupMimActive;
		bool ButMimEditAvail;
		bool TxfSizActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmFilDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmFilDetailData)
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
		* DpchAppDo (full: DpchAppWznmFilDetailDo)
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
		* DpchEngData (full: DpchEngWznmFilDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPCNT = 5;
		static const Sbecore::uint FEEDFPUPMIM = 6;
		static const Sbecore::uint FEEDFPUPRET = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstClu = NULL, Sbecore::Feed* feedFPupCnt = NULL, Sbecore::Feed* feedFPupMim = NULL, Sbecore::Feed* feedFPupRet = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFPupCnt;
		Sbecore::Feed feedFPupMim;
		Sbecore::Feed feedFPupRet;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxfFnmActive(DbsWznm* dbswznm);
	bool evalLstCluActive(DbsWznm* dbswznm);
	bool evalButCluViewActive(DbsWznm* dbswznm);
	bool evalButCluClusterAvail(DbsWznm* dbswznm);
	bool evalButCluUnclusterAvail(DbsWznm* dbswznm);
	bool evalTxtReuActive(DbsWznm* dbswznm);
	bool evalButReuViewAvail(DbsWznm* dbswznm);
	bool evalButReuViewActive(DbsWznm* dbswznm);
	bool evalPupCntActive(DbsWznm* dbswznm);
	bool evalButCntEditAvail(DbsWznm* dbswznm);
	bool evalTxfAcvActive(DbsWznm* dbswznm);
	bool evalTxfAnmActive(DbsWznm* dbswznm);
	bool evalPupMimActive(DbsWznm* dbswznm);
	bool evalButMimEditAvail(DbsWznm* dbswznm);
	bool evalTxfSizActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmFilDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmFilDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstClu;
	Sbecore::Feed feedFPupCnt;
	Sbecore::Feed feedFPupMim;
	Sbecore::Feed feedFPupRet;

	WznmMFile recFil;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstClu(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshClu(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPupCnt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfCnt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCnt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPupMim(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfMim(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshMim(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecFil(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCntEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMimEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmFil_cluEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmFil_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmFil_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmFilUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmKlsAkeyMod_klsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWznmFilMod_cluEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
