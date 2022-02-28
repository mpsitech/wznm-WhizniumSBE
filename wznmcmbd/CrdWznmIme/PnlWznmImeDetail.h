/**
	* \file PnlWznmImeDetail.h
	* job handler for job PnlWznmImeDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMIMEDETAIL_H
#define PNLWZNMIMEDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmImeDetailDo PnlWznmImeDetail::VecVDo

#define ContIacWznmImeDetail PnlWznmImeDetail::ContIac
#define ContInfWznmImeDetail PnlWznmImeDetail::ContInf
#define StatAppWznmImeDetail PnlWznmImeDetail::StatApp
#define StatShrWznmImeDetail PnlWznmImeDetail::StatShr
#define TagWznmImeDetail PnlWznmImeDetail::Tag

#define DpchAppWznmImeDetailData PnlWznmImeDetail::DpchAppData
#define DpchAppWznmImeDetailDo PnlWznmImeDetail::DpchAppDo
#define DpchEngWznmImeDetailData PnlWznmImeDetail::DpchEngData

/**
	* PnlWznmImeDetail
	*/
class PnlWznmImeDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmImeDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTIEXVIEWCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;
		static const Sbecore::uint BUTRTRVIEWCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmImeDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMSFLSTIOP = 1;
		static const Sbecore::uint NUMFLSTRTR = 2;
		static const Sbecore::uint TXFRTR = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const std::vector<Sbecore::uint>& numsFLstIop = {}, const Sbecore::uint numFLstRtr = 1, const std::string& TxfRtr = "", const std::string& TxfCmt = "");

	public:
		std::vector<Sbecore::uint> numsFLstIop;
		Sbecore::uint numFLstRtr;
		std::string TxfRtr;
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
	  * ContInf (full: ContInfWznmImeDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTIEX = 2;
		static const Sbecore::uint TXTSUP = 3;
		static const Sbecore::uint TXTTBL = 4;
		static const Sbecore::uint TXTIOP = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtIex = "", const std::string& TxtSup = "", const std::string& TxtTbl = "", const std::string& TxtIop = "");

	public:
		std::string TxtSrf;
		std::string TxtIex;
		std::string TxtSup;
		std::string TxtTbl;
		std::string TxtIop;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmImeDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstIopAlt = true, const bool LstRtrAlt = true, const Sbecore::uint LstIopNumFirstdisp = 1, const Sbecore::uint LstRtrNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstIopAlt = true, const bool LstRtrAlt = true, const Sbecore::uint LstIopNumFirstdisp = 1, const Sbecore::uint LstRtrNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmImeDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFRTRVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXTIEXACTIVE = 5;
		static const Sbecore::uint BUTIEXVIEWAVAIL = 6;
		static const Sbecore::uint BUTIEXVIEWACTIVE = 7;
		static const Sbecore::uint TXTSUPACTIVE = 8;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 9;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 10;
		static const Sbecore::uint TXTTBLACTIVE = 11;
		static const Sbecore::uint LSTIOPACTIVE = 12;
		static const Sbecore::uint LSTRTRACTIVE = 13;
		static const Sbecore::uint BUTRTRVIEWAVAIL = 14;
		static const Sbecore::uint BUTRTRVIEWACTIVE = 15;
		static const Sbecore::uint TXFCMTACTIVE = 16;

	public:
		StatShr(const bool TxfRtrValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtIexActive = true, const bool ButIexViewAvail = true, const bool ButIexViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTblActive = true, const bool LstIopActive = true, const bool LstRtrActive = true, const bool ButRtrViewAvail = true, const bool ButRtrViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfRtrValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtIexActive;
		bool ButIexViewAvail;
		bool ButIexViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtTblActive;
		bool LstIopActive;
		bool LstRtrActive;
		bool ButRtrViewAvail;
		bool ButRtrViewActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmImeDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmImeDetailData)
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
		* DpchAppDo (full: DpchAppWznmImeDetailDo)
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
		* DpchEngData (full: DpchEngWznmImeDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTIOP = 4;
		static const Sbecore::uint FEEDFLSTRTR = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstIop = NULL, Sbecore::Feed* feedFLstRtr = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstIop;
		Sbecore::Feed feedFLstRtr;
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
	bool evalTxtIexActive(DbsWznm* dbswznm);
	bool evalButIexViewAvail(DbsWznm* dbswznm);
	bool evalButIexViewActive(DbsWznm* dbswznm);
	bool evalTxtSupActive(DbsWznm* dbswznm);
	bool evalButSupViewAvail(DbsWznm* dbswznm);
	bool evalButSupViewActive(DbsWznm* dbswznm);
	bool evalTxtTblActive(DbsWznm* dbswznm);
	bool evalLstIopActive(DbsWznm* dbswznm);
	bool evalLstRtrActive(DbsWznm* dbswznm);
	bool evalButRtrViewAvail(DbsWznm* dbswznm);
	bool evalButRtrViewActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmImeDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmImeDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstIop;
	Sbecore::Feed feedFLstRtr;

	WznmMImpexp recIme;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshTxtIop(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstRtr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRtr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecIme(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButIexViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRtrViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmIme_iexEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmIme_supEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmImeUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
