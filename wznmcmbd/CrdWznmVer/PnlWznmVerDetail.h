/**
	* \file PnlWznmVerDetail.h
	* job handler for job PnlWznmVerDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMVERDETAIL_H
#define PNLWZNMVERDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmVerDetailDo PnlWznmVerDetail::VecVDo

#define ContIacWznmVerDetail PnlWznmVerDetail::ContIac
#define ContInfWznmVerDetail PnlWznmVerDetail::ContInf
#define StatAppWznmVerDetail PnlWznmVerDetail::StatApp
#define StatShrWznmVerDetail PnlWznmVerDetail::StatShr
#define TagWznmVerDetail PnlWznmVerDetail::Tag

#define DpchAppWznmVerDetailData PnlWznmVerDetail::DpchAppData
#define DpchAppWznmVerDetailDo PnlWznmVerDetail::DpchAppDo
#define DpchEngWznmVerDetailData PnlWznmVerDetail::DpchEngData

/**
	* PnlWznmVerDetail
	*/
class PnlWznmVerDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmVerDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRJVIEWCLICK = 2;
		static const Sbecore::uint BUTBVRVIEWCLICK = 3;
		static const Sbecore::uint BUTLOCVIEWCLICK = 4;
		static const Sbecore::uint BUTJSTEDITCLICK = 5;
		static const Sbecore::uint BUTJEDITCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmVerDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFMAJ = 1;
		static const Sbecore::uint TXFMIN = 2;
		static const Sbecore::uint TXFSUB = 3;
		static const Sbecore::uint NUMFPUPJST = 4;
		static const Sbecore::uint NUMFPUPSTE = 5;
		static const Sbecore::uint NUMSFLSTDTY = 6;
		static const Sbecore::uint NUMSFLSTOPT = 7;
		static const Sbecore::uint NUMFPUPJ = 8;
		static const Sbecore::uint TXFCMT = 9;

	public:
		ContIac(const std::string& TxfMaj = "", const std::string& TxfMin = "", const std::string& TxfSub = "", const Sbecore::uint numFPupJst = 1, const Sbecore::uint numFPupSte = 1, const std::vector<Sbecore::uint>& numsFLstDty = {}, const std::vector<Sbecore::uint>& numsFLstOpt = {}, const Sbecore::uint numFPupJ = 1, const std::string& TxfCmt = "");

	public:
		std::string TxfMaj;
		std::string TxfMin;
		std::string TxfSub;
		Sbecore::uint numFPupJst;
		Sbecore::uint numFPupSte;
		std::vector<Sbecore::uint> numsFLstDty;
		std::vector<Sbecore::uint> numsFLstOpt;
		Sbecore::uint numFPupJ;
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
	  * ContInf (full: ContInfWznmVerDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRJ = 1;
		static const Sbecore::uint TXTBVR = 2;
		static const Sbecore::uint TXTLOC = 3;
		static const Sbecore::uint TXTDTY = 4;
		static const Sbecore::uint TXTOPT = 5;
		static const Sbecore::uint TXTAB1 = 6;
		static const Sbecore::uint TXTAB2 = 7;
		static const Sbecore::uint TXTAB3 = 8;

	public:
		ContInf(const std::string& TxtPrj = "", const std::string& TxtBvr = "", const std::string& TxtLoc = "", const std::string& TxtDty = "", const std::string& TxtOpt = "", const std::string& TxtAb1 = "", const std::string& TxtAb2 = "", const std::string& TxtAb3 = "");

	public:
		std::string TxtPrj;
		std::string TxtBvr;
		std::string TxtLoc;
		std::string TxtDty;
		std::string TxtOpt;
		std::string TxtAb1;
		std::string TxtAb2;
		std::string TxtAb3;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmVerDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstDtyAlt = true, const bool LstOptAlt = true, const Sbecore::uint LstDtyNumFirstdisp = 1, const Sbecore::uint LstOptNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstDtyAlt = true, const bool LstOptAlt = true, const Sbecore::uint LstDtyNumFirstdisp = 1, const Sbecore::uint LstOptNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmVerDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRJACTIVE = 3;
		static const Sbecore::uint BUTPRJVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRJVIEWACTIVE = 5;
		static const Sbecore::uint TXFMAJACTIVE = 6;
		static const Sbecore::uint TXFMINACTIVE = 7;
		static const Sbecore::uint TXFSUBACTIVE = 8;
		static const Sbecore::uint TXTBVRACTIVE = 9;
		static const Sbecore::uint BUTBVRVIEWAVAIL = 10;
		static const Sbecore::uint BUTBVRVIEWACTIVE = 11;
		static const Sbecore::uint TXTLOCACTIVE = 12;
		static const Sbecore::uint BUTLOCVIEWAVAIL = 13;
		static const Sbecore::uint BUTLOCVIEWACTIVE = 14;
		static const Sbecore::uint PUPJSTACTIVE = 15;
		static const Sbecore::uint BUTJSTEDITAVAIL = 16;
		static const Sbecore::uint PUPSTEACTIVE = 17;
		static const Sbecore::uint LSTDTYACTIVE = 18;
		static const Sbecore::uint LSTOPTACTIVE = 19;
		static const Sbecore::uint PUPJACTIVE = 20;
		static const Sbecore::uint BUTJEDITAVAIL = 21;
		static const Sbecore::uint TXTAB1ACTIVE = 22;
		static const Sbecore::uint TXTAB2ACTIVE = 23;
		static const Sbecore::uint TXTAB3ACTIVE = 24;
		static const Sbecore::uint TXFCMTACTIVE = 25;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrjActive = true, const bool ButPrjViewAvail = true, const bool ButPrjViewActive = true, const bool TxfMajActive = true, const bool TxfMinActive = true, const bool TxfSubActive = true, const bool TxtBvrActive = true, const bool ButBvrViewAvail = true, const bool ButBvrViewActive = true, const bool TxtLocActive = true, const bool ButLocViewAvail = true, const bool ButLocViewActive = true, const bool PupJstActive = true, const bool ButJstEditAvail = true, const bool PupSteActive = true, const bool LstDtyActive = true, const bool LstOptActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtAb1Active = true, const bool TxtAb2Active = true, const bool TxtAb3Active = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrjActive;
		bool ButPrjViewAvail;
		bool ButPrjViewActive;
		bool TxfMajActive;
		bool TxfMinActive;
		bool TxfSubActive;
		bool TxtBvrActive;
		bool ButBvrViewAvail;
		bool ButBvrViewActive;
		bool TxtLocActive;
		bool ButLocViewAvail;
		bool ButLocViewActive;
		bool PupJstActive;
		bool ButJstEditAvail;
		bool PupSteActive;
		bool LstDtyActive;
		bool LstOptActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtAb1Active;
		bool TxtAb2Active;
		bool TxtAb3Active;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmVerDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmVerDetailData)
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
		* DpchAppDo (full: DpchAppWznmVerDetailDo)
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
		* DpchEngData (full: DpchEngWznmVerDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDTY = 4;
		static const Sbecore::uint FEEDFLSTOPT = 5;
		static const Sbecore::uint FEEDFPUPJ = 6;
		static const Sbecore::uint FEEDFPUPJST = 7;
		static const Sbecore::uint FEEDFPUPSTE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstDty = NULL, Sbecore::Feed* feedFLstOpt = NULL, Sbecore::Feed* feedFPupJ = NULL, Sbecore::Feed* feedFPupJst = NULL, Sbecore::Feed* feedFPupSte = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstDty;
		Sbecore::Feed feedFLstOpt;
		Sbecore::Feed feedFPupJ;
		Sbecore::Feed feedFPupJst;
		Sbecore::Feed feedFPupSte;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxtPrjActive(DbsWznm* dbswznm);
	bool evalButPrjViewAvail(DbsWznm* dbswznm);
	bool evalButPrjViewActive(DbsWznm* dbswznm);
	bool evalTxfMajActive(DbsWznm* dbswznm);
	bool evalTxfMinActive(DbsWznm* dbswznm);
	bool evalTxfSubActive(DbsWznm* dbswznm);
	bool evalTxtBvrActive(DbsWznm* dbswznm);
	bool evalButBvrViewAvail(DbsWznm* dbswznm);
	bool evalButBvrViewActive(DbsWznm* dbswznm);
	bool evalTxtLocActive(DbsWznm* dbswznm);
	bool evalButLocViewAvail(DbsWznm* dbswznm);
	bool evalButLocViewActive(DbsWznm* dbswznm);
	bool evalPupJstActive(DbsWznm* dbswznm);
	bool evalButJstEditAvail(DbsWznm* dbswznm);
	bool evalPupSteActive(DbsWznm* dbswznm);
	bool evalLstDtyActive(DbsWznm* dbswznm);
	bool evalLstOptActive(DbsWznm* dbswznm);
	bool evalPupJActive(DbsWznm* dbswznm);
	bool evalButJEditAvail(DbsWznm* dbswznm);
	bool evalTxtAb1Active(DbsWznm* dbswznm);
	bool evalTxtAb2Active(DbsWznm* dbswznm);
	bool evalTxtAb3Active(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmVerDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmVerDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstDty;
	Sbecore::Feed feedFLstOpt;
	Sbecore::Feed feedFPupJ;
	Sbecore::Feed feedFPupJst;
	Sbecore::Feed feedFPupSte;

	WznmMVersion recVer;

	WznmJMVersion recVerJ;

	WznmJMVersionState recVerJste;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJst(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxtDty(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxtOpt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshJ(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecVer(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecVerJ(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecVerJste(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPrjViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButBvrViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButLocViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJstEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmVerJsteMod_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVerUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVerJMod_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVer_steEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmVer_prjEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVer_locEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVer_bvrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
