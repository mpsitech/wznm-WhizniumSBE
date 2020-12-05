/**
	* \file PnlWznmVitDetail.h
	* job handler for job PnlWznmVitDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMVITDETAIL_H
#define PNLWZNMVITDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmVitDetailDo PnlWznmVitDetail::VecVDo

#define ContIacWznmVitDetail PnlWznmVitDetail::ContIac
#define ContInfWznmVitDetail PnlWznmVitDetail::ContInf
#define StatAppWznmVitDetail PnlWznmVitDetail::StatApp
#define StatShrWznmVitDetail PnlWznmVitDetail::StatShr
#define TagWznmVitDetail PnlWznmVitDetail::Tag

#define DpchAppWznmVitDetailData PnlWznmVitDetail::DpchAppData
#define DpchAppWznmVitDetailDo PnlWznmVitDetail::DpchAppDo
#define DpchEngWznmVitDetailData PnlWznmVitDetail::DpchEngData

/**
	* PnlWznmVitDetail
	*/
class PnlWznmVitDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmVitDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJEDITCLICK = 2;
		static const Sbecore::uint BUTVECVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmVitDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJ = 1;
		static const Sbecore::uint TXFAVL = 2;
		static const Sbecore::uint TXFIMP = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const Sbecore::uint numFPupJ = 1, const std::string& TxfAvl = "", const std::string& TxfImp = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupJ;
		std::string TxfAvl;
		std::string TxfImp;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmVitDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTVEC = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtVec = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtVec;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmVitDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmVitDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPJACTIVE = 4;
		static const Sbecore::uint BUTJEDITAVAIL = 5;
		static const Sbecore::uint TXTTITACTIVE = 6;
		static const Sbecore::uint TXTVECACTIVE = 7;
		static const Sbecore::uint BUTVECVIEWAVAIL = 8;
		static const Sbecore::uint BUTVECVIEWACTIVE = 9;
		static const Sbecore::uint TXFAVLACTIVE = 10;
		static const Sbecore::uint TXFIMPACTIVE = 11;
		static const Sbecore::uint TXFCMTACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtTitActive = true, const bool TxtVecActive = true, const bool ButVecViewAvail = true, const bool ButVecViewActive = true, const bool TxfAvlActive = true, const bool TxfImpActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtTitActive;
		bool TxtVecActive;
		bool ButVecViewAvail;
		bool ButVecViewActive;
		bool TxfAvlActive;
		bool TxfImpActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmVitDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmVitDetailData)
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
		* DpchAppDo (full: DpchAppWznmVitDetailDo)
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
		* DpchEngData (full: DpchEngWznmVitDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJ = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupJ = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupJ;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxtSrfActive(DbsWznm* dbswznm);
	bool evalPupJActive(DbsWznm* dbswznm);
	bool evalButJEditAvail(DbsWznm* dbswznm);
	bool evalTxtTitActive(DbsWznm* dbswznm);
	bool evalTxtVecActive(DbsWznm* dbswznm);
	bool evalButVecViewAvail(DbsWznm* dbswznm);
	bool evalButVecViewActive(DbsWznm* dbswznm);
	bool evalTxfAvlActive(DbsWznm* dbswznm);
	bool evalTxfImpActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmVitDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmVitDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupJ;

	WznmMVectoritem recVit;

	WznmJMVectoritem recVitJ;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJ(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecVit(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecVitJ(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVecViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmVitJMod_vitEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVitUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVit_vecEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif



