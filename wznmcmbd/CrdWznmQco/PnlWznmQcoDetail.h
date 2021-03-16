/**
	* \file PnlWznmQcoDetail.h
	* job handler for job PnlWznmQcoDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMQCODETAIL_H
#define PNLWZNMQCODETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmQcoDetailDo PnlWznmQcoDetail::VecVDo

#define ContIacWznmQcoDetail PnlWznmQcoDetail::ContIac
#define ContInfWznmQcoDetail PnlWznmQcoDetail::ContInf
#define StatAppWznmQcoDetail PnlWznmQcoDetail::StatApp
#define StatShrWznmQcoDetail PnlWznmQcoDetail::StatShr
#define TagWznmQcoDetail PnlWznmQcoDetail::Tag

#define DpchAppWznmQcoDetailData PnlWznmQcoDetail::DpchAppData
#define DpchAppWznmQcoDetailDo PnlWznmQcoDetail::DpchAppDo
#define DpchEngWznmQcoDetailData PnlWznmQcoDetail::DpchEngData

/**
	* PnlWznmQcoDetail
	*/
class PnlWznmQcoDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmQcoDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTQRYVIEWCLICK = 2;
		static const Sbecore::uint BUTSTBVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmQcoDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint NUMSFLSTOCC = 3;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupTyp = 1, const std::vector<Sbecore::uint>& numsFLstOcc = {});

	public:
		std::string TxfSho;
		Sbecore::uint numFPupTyp;
		std::vector<Sbecore::uint> numsFLstOcc;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmQcoDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTOCC = 2;
		static const Sbecore::uint TXTQRY = 3;
		static const Sbecore::uint TXTTCO = 4;
		static const Sbecore::uint TXTSTB = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtOcc = "", const std::string& TxtQry = "", const std::string& TxtTco = "", const std::string& TxtStb = "");

	public:
		std::string TxtSrf;
		std::string TxtOcc;
		std::string TxtQry;
		std::string TxtTco;
		std::string TxtStb;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmQcoDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOccAlt = true, const Sbecore::uint LstOccNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOccAlt = true, const Sbecore::uint LstOccNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmQcoDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFSHOACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint LSTOCCACTIVE = 6;
		static const Sbecore::uint TXTQRYACTIVE = 7;
		static const Sbecore::uint BUTQRYVIEWAVAIL = 8;
		static const Sbecore::uint BUTQRYVIEWACTIVE = 9;
		static const Sbecore::uint TXTTCOACTIVE = 10;
		static const Sbecore::uint TXTSTBACTIVE = 11;
		static const Sbecore::uint BUTSTBVIEWAVAIL = 12;
		static const Sbecore::uint BUTSTBVIEWACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupTypActive = true, const bool LstOccActive = true, const bool TxtQryActive = true, const bool ButQryViewAvail = true, const bool ButQryViewActive = true, const bool TxtTcoActive = true, const bool TxtStbActive = true, const bool ButStbViewAvail = true, const bool ButStbViewActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupTypActive;
		bool LstOccActive;
		bool TxtQryActive;
		bool ButQryViewAvail;
		bool ButQryViewActive;
		bool TxtTcoActive;
		bool TxtStbActive;
		bool ButStbViewAvail;
		bool ButStbViewActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmQcoDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmQcoDetailData)
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
		* DpchAppDo (full: DpchAppWznmQcoDetailDo)
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
		* DpchEngData (full: DpchEngWznmQcoDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOCC = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstOcc = NULL, Sbecore::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstOcc;
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
	bool evalTxtSrfActive(DbsWznm* dbswznm);
	bool evalTxfShoActive(DbsWznm* dbswznm);
	bool evalPupTypActive(DbsWznm* dbswznm);
	bool evalLstOccActive(DbsWznm* dbswznm);
	bool evalTxtQryActive(DbsWznm* dbswznm);
	bool evalButQryViewAvail(DbsWznm* dbswznm);
	bool evalButQryViewActive(DbsWznm* dbswznm);
	bool evalTxtTcoActive(DbsWznm* dbswznm);
	bool evalTxtStbActive(DbsWznm* dbswznm);
	bool evalButStbViewAvail(DbsWznm* dbswznm);
	bool evalButStbViewActive(DbsWznm* dbswznm);

public:
	PnlWznmQcoDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmQcoDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstOcc;
	Sbecore::Feed feedFPupTyp;

	WznmMQuerycol recQco;

	WznmJMQuerycolStub recQcoJstb;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshTxtOcc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecQco(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecQcoJstb(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButQryViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButStbViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmQcoJstbMod_qcoEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmQcoUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmQco_stbEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmQco_qryEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
