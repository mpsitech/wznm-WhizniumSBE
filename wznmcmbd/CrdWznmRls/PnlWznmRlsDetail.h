/**
	* \file PnlWznmRlsDetail.h
	* job handler for job PnlWznmRlsDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMRLSDETAIL_H
#define PNLWZNMRLSDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmRlsDetailDo PnlWznmRlsDetail::VecVDo

#define ContIacWznmRlsDetail PnlWznmRlsDetail::ContIac
#define ContInfWznmRlsDetail PnlWznmRlsDetail::ContInf
#define StatAppWznmRlsDetail PnlWznmRlsDetail::StatApp
#define StatShrWznmRlsDetail PnlWznmRlsDetail::StatShr
#define TagWznmRlsDetail PnlWznmRlsDetail::Tag

#define DpchAppWznmRlsDetailData PnlWznmRlsDetail::DpchAppData
#define DpchAppWznmRlsDetailDo PnlWznmRlsDetail::DpchAppDo
#define DpchEngWznmRlsDetailData PnlWznmRlsDetail::DpchEngData

/**
	* PnlWznmRlsDetail
	*/
class PnlWznmRlsDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmRlsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCMPVIEWCLICK = 2;
		static const Sbecore::uint BUTMCHVIEWCLICK = 3;
		static const Sbecore::uint BUTOPTEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmRlsDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMSFLSTOPT = 1;
		static const Sbecore::uint TXFOPT = 2;
		static const Sbecore::uint TXFCMT = 3;

	public:
		ContIac(const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "", const std::string& TxfCmt = "");

	public:
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;
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
	  * ContInf (full: ContInfWznmRlsDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCMP = 2;
		static const Sbecore::uint TXTMCH = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtCmp = "", const std::string& TxtMch = "");

	public:
		std::string TxtSrf;
		std::string TxtCmp;
		std::string TxtMch;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmRlsDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOptAlt = true, const Sbecore::uint LstOptNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOptAlt = true, const Sbecore::uint LstOptNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmRlsDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFOPTVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXTCMPACTIVE = 5;
		static const Sbecore::uint BUTCMPVIEWAVAIL = 6;
		static const Sbecore::uint BUTCMPVIEWACTIVE = 7;
		static const Sbecore::uint TXTMCHACTIVE = 8;
		static const Sbecore::uint BUTMCHVIEWAVAIL = 9;
		static const Sbecore::uint BUTMCHVIEWACTIVE = 10;
		static const Sbecore::uint LSTOPTACTIVE = 11;
		static const Sbecore::uint BUTOPTEDITAVAIL = 12;
		static const Sbecore::uint TXFCMTACTIVE = 13;

	public:
		StatShr(const bool TxfOptValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtCmpActive = true, const bool ButCmpViewAvail = true, const bool ButCmpViewActive = true, const bool TxtMchActive = true, const bool ButMchViewAvail = true, const bool ButMchViewActive = true, const bool LstOptActive = true, const bool ButOptEditAvail = true, const bool TxfCmtActive = true);

	public:
		bool TxfOptValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtCmpActive;
		bool ButCmpViewAvail;
		bool ButCmpViewActive;
		bool TxtMchActive;
		bool ButMchViewAvail;
		bool ButMchViewActive;
		bool LstOptActive;
		bool ButOptEditAvail;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmRlsDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmRlsDetailData)
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
		* DpchAppDo (full: DpchAppWznmRlsDetailDo)
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
		* DpchEngData (full: DpchEngWznmRlsDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOPT = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstOpt = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstOpt;
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
	bool evalTxtCmpActive(DbsWznm* dbswznm);
	bool evalButCmpViewAvail(DbsWznm* dbswznm);
	bool evalButCmpViewActive(DbsWznm* dbswznm);
	bool evalTxtMchActive(DbsWznm* dbswznm);
	bool evalButMchViewAvail(DbsWznm* dbswznm);
	bool evalButMchViewActive(DbsWznm* dbswznm);
	bool evalLstOptActive(DbsWznm* dbswznm);
	bool evalButOptEditAvail(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmRlsDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmRlsDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstOpt;

	WznmMRelease recRls;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecRls(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCmpViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMchViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButOptEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmKlsAkeyMod_klsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWznmRlsUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmRls_mchEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmRls_cmpEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
