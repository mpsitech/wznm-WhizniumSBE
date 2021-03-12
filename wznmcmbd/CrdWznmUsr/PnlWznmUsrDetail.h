/**
	* \file PnlWznmUsrDetail.h
	* job handler for job PnlWznmUsrDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMUSRDETAIL_H
#define PNLWZNMUSRDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmUsrDetailDo PnlWznmUsrDetail::VecVDo

#define ContIacWznmUsrDetail PnlWznmUsrDetail::ContIac
#define ContInfWznmUsrDetail PnlWznmUsrDetail::ContInf
#define StatAppWznmUsrDetail PnlWznmUsrDetail::StatApp
#define StatShrWznmUsrDetail PnlWznmUsrDetail::StatShr
#define TagWznmUsrDetail PnlWznmUsrDetail::Tag

#define DpchAppWznmUsrDetailData PnlWznmUsrDetail::DpchAppData
#define DpchAppWznmUsrDetailDo PnlWznmUsrDetail::DpchAppDo
#define DpchEngWznmUsrDetailData PnlWznmUsrDetail::DpchEngData

/**
	* PnlWznmUsrDetail
	*/
class PnlWznmUsrDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRSVIEWCLICK = 2;
		static const Sbecore::uint BUTUSGVIEWCLICK = 3;
		static const Sbecore::uint BUTJSTEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmUsrDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPJST = 1;
		static const Sbecore::uint NUMFPUPSTE = 2;
		static const Sbecore::uint NUMFPUPLCL = 3;
		static const Sbecore::uint NUMFPUPULV = 4;
		static const Sbecore::uint TXFPWD = 5;
		static const Sbecore::uint TXFFKY = 6;
		static const Sbecore::uint TXFCMT = 7;

	public:
		ContIac(const Sbecore::uint numFPupJst = 1, const Sbecore::uint numFPupSte = 1, const Sbecore::uint numFPupLcl = 1, const Sbecore::uint numFPupUlv = 1, const std::string& TxfPwd = "", const std::string& TxfFky = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupJst;
		Sbecore::uint numFPupSte;
		Sbecore::uint numFPupLcl;
		Sbecore::uint numFPupUlv;
		std::string TxfPwd;
		std::string TxfFky;
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
	  * ContInf (full: ContInfWznmUsrDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRS = 1;
		static const Sbecore::uint TXTSRF = 2;
		static const Sbecore::uint TXTUSG = 3;

	public:
		ContInf(const std::string& TxtPrs = "", const std::string& TxtSrf = "", const std::string& TxtUsg = "");

	public:
		std::string TxtPrs;
		std::string TxtSrf;
		std::string TxtUsg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmUsrDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmUsrDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRSACTIVE = 3;
		static const Sbecore::uint BUTPRSVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 5;
		static const Sbecore::uint TXTSRFACTIVE = 6;
		static const Sbecore::uint TXTUSGACTIVE = 7;
		static const Sbecore::uint BUTUSGVIEWAVAIL = 8;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 9;
		static const Sbecore::uint PUPJSTACTIVE = 10;
		static const Sbecore::uint BUTJSTEDITAVAIL = 11;
		static const Sbecore::uint PUPSTEACTIVE = 12;
		static const Sbecore::uint PUPLCLACTIVE = 13;
		static const Sbecore::uint PUPULVACTIVE = 14;
		static const Sbecore::uint TXFPWDACTIVE = 15;
		static const Sbecore::uint TXFFKYACTIVE = 16;
		static const Sbecore::uint TXFCMTACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrsActive = true, const bool ButPrsViewAvail = true, const bool ButPrsViewActive = true, const bool TxtSrfActive = true, const bool TxtUsgActive = true, const bool ButUsgViewAvail = true, const bool ButUsgViewActive = true, const bool PupJstActive = true, const bool ButJstEditAvail = true, const bool PupSteActive = true, const bool PupLclActive = true, const bool PupUlvActive = true, const bool TxfPwdActive = true, const bool TxfFkyActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrsActive;
		bool ButPrsViewAvail;
		bool ButPrsViewActive;
		bool TxtSrfActive;
		bool TxtUsgActive;
		bool ButUsgViewAvail;
		bool ButUsgViewActive;
		bool PupJstActive;
		bool ButJstEditAvail;
		bool PupSteActive;
		bool PupLclActive;
		bool PupUlvActive;
		bool TxfPwdActive;
		bool TxfFkyActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmUsrDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmUsrDetailData)
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
		* DpchAppDo (full: DpchAppWznmUsrDetailDo)
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
		* DpchEngData (full: DpchEngWznmUsrDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJST = 4;
		static const Sbecore::uint FEEDFPUPLCL = 5;
		static const Sbecore::uint FEEDFPUPSTE = 6;
		static const Sbecore::uint FEEDFPUPULV = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupJst = NULL, Sbecore::Feed* feedFPupLcl = NULL, Sbecore::Feed* feedFPupSte = NULL, Sbecore::Feed* feedFPupUlv = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupJst;
		Sbecore::Feed feedFPupLcl;
		Sbecore::Feed feedFPupSte;
		Sbecore::Feed feedFPupUlv;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxtPrsActive(DbsWznm* dbswznm);
	bool evalButPrsViewAvail(DbsWznm* dbswznm);
	bool evalButPrsViewActive(DbsWznm* dbswznm);
	bool evalTxtSrfActive(DbsWznm* dbswznm);
	bool evalTxtUsgActive(DbsWznm* dbswznm);
	bool evalButUsgViewAvail(DbsWznm* dbswznm);
	bool evalButUsgViewActive(DbsWznm* dbswznm);
	bool evalPupJstActive(DbsWznm* dbswznm);
	bool evalButJstEditAvail(DbsWznm* dbswznm);
	bool evalPupSteActive(DbsWznm* dbswznm);
	bool evalPupLclActive(DbsWznm* dbswznm);
	bool evalPupUlvActive(DbsWznm* dbswznm);
	bool evalTxfPwdActive(DbsWznm* dbswznm);
	bool evalTxfFkyActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmUsrDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmUsrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupJst;
	Sbecore::Feed feedFPupLcl;
	Sbecore::Feed feedFPupSte;
	Sbecore::Feed feedFPupUlv;

	WznmMUser recUsr;

	WznmJMUserState recUsrJste;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJst(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecUsr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecUsrJste(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButUsgViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJstEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmUsrJsteMod_usrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmUsrUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmUsr_usgEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmUsr_prsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
