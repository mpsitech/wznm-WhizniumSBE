/**
	* \file PnlWznmSteDetail.h
	* job handler for job PnlWznmSteDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMSTEDETAIL_H
#define PNLWZNMSTEDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmSteDetailDo PnlWznmSteDetail::VecVDo

#define ContIacWznmSteDetail PnlWznmSteDetail::ContIac
#define ContInfWznmSteDetail PnlWznmSteDetail::ContInf
#define StatAppWznmSteDetail PnlWznmSteDetail::StatApp
#define StatShrWznmSteDetail PnlWznmSteDetail::StatShr
#define TagWznmSteDetail PnlWznmSteDetail::Tag

#define DpchAppWznmSteDetailData PnlWznmSteDetail::DpchAppData
#define DpchAppWznmSteDetailDo PnlWznmSteDetail::DpchAppDo
#define DpchEngWznmSteDetailData PnlWznmSteDetail::DpchEngData

/**
	* PnlWznmSteDetail
	*/
class PnlWznmSteDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmSteDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTSEQVIEWCLICK = 2;
		static const Sbecore::uint BUTERJVIEWCLICK = 3;
		static const Sbecore::uint BUTEVEVIEWCLICK = 4;
		static const Sbecore::uint BUTEVIVIEWCLICK = 5;
		static const Sbecore::uint BUTESNVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmSteDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPEAC = 1;
		static const Sbecore::uint NUMFPUPLAC = 2;
		static const Sbecore::uint CHKCST = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const Sbecore::uint numFPupEac = 1, const Sbecore::uint numFPupLac = 1, const bool ChkCst = false, const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupEac;
		Sbecore::uint numFPupLac;
		bool ChkCst;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmSteDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTSEQ = 2;
		static const Sbecore::uint TXTERJ = 3;
		static const Sbecore::uint TXTEVE = 4;
		static const Sbecore::uint TXTEVI = 5;
		static const Sbecore::uint TXTESN = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtSeq = "", const std::string& TxtErj = "", const std::string& TxtEve = "", const std::string& TxtEvi = "", const std::string& TxtEsn = "");

	public:
		std::string TxtSrf;
		std::string TxtSeq;
		std::string TxtErj;
		std::string TxtEve;
		std::string TxtEvi;
		std::string TxtEsn;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmSteDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmSteDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXTSEQACTIVE = 4;
		static const Sbecore::uint BUTSEQVIEWAVAIL = 5;
		static const Sbecore::uint BUTSEQVIEWACTIVE = 6;
		static const Sbecore::uint PUPEACACTIVE = 7;
		static const Sbecore::uint TXTERJACTIVE = 8;
		static const Sbecore::uint BUTERJVIEWAVAIL = 9;
		static const Sbecore::uint BUTERJVIEWACTIVE = 10;
		static const Sbecore::uint TXTEVEACTIVE = 11;
		static const Sbecore::uint BUTEVEVIEWAVAIL = 12;
		static const Sbecore::uint BUTEVEVIEWACTIVE = 13;
		static const Sbecore::uint TXTEVIACTIVE = 14;
		static const Sbecore::uint BUTEVIVIEWAVAIL = 15;
		static const Sbecore::uint BUTEVIVIEWACTIVE = 16;
		static const Sbecore::uint TXTESNACTIVE = 17;
		static const Sbecore::uint BUTESNVIEWAVAIL = 18;
		static const Sbecore::uint BUTESNVIEWACTIVE = 19;
		static const Sbecore::uint PUPLACACTIVE = 20;
		static const Sbecore::uint CHKCSTACTIVE = 21;
		static const Sbecore::uint TXFCMTACTIVE = 22;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtSeqActive = true, const bool ButSeqViewAvail = true, const bool ButSeqViewActive = true, const bool PupEacActive = true, const bool TxtErjActive = true, const bool ButErjViewAvail = true, const bool ButErjViewActive = true, const bool TxtEveActive = true, const bool ButEveViewAvail = true, const bool ButEveViewActive = true, const bool TxtEviActive = true, const bool ButEviViewAvail = true, const bool ButEviViewActive = true, const bool TxtEsnActive = true, const bool ButEsnViewAvail = true, const bool ButEsnViewActive = true, const bool PupLacActive = true, const bool ChkCstActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtSeqActive;
		bool ButSeqViewAvail;
		bool ButSeqViewActive;
		bool PupEacActive;
		bool TxtErjActive;
		bool ButErjViewAvail;
		bool ButErjViewActive;
		bool TxtEveActive;
		bool ButEveViewAvail;
		bool ButEveViewActive;
		bool TxtEviActive;
		bool ButEviViewAvail;
		bool ButEviViewActive;
		bool TxtEsnActive;
		bool ButEsnViewAvail;
		bool ButEsnViewActive;
		bool PupLacActive;
		bool ChkCstActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmSteDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmSteDetailData)
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
		* DpchAppDo (full: DpchAppWznmSteDetailDo)
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
		* DpchEngData (full: DpchEngWznmSteDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPEAC = 4;
		static const Sbecore::uint FEEDFPUPLAC = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupEac = NULL, Sbecore::Xmlio::Feed* feedFPupLac = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupEac;
		Sbecore::Xmlio::Feed feedFPupLac;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxtSrfActive(DbsWznm* dbswznm);
	bool evalTxtSeqActive(DbsWznm* dbswznm);
	bool evalButSeqViewAvail(DbsWznm* dbswznm);
	bool evalButSeqViewActive(DbsWznm* dbswznm);
	bool evalPupEacActive(DbsWznm* dbswznm);
	bool evalTxtErjActive(DbsWznm* dbswznm);
	bool evalButErjViewAvail(DbsWznm* dbswznm);
	bool evalButErjViewActive(DbsWznm* dbswznm);
	bool evalTxtEveActive(DbsWznm* dbswznm);
	bool evalButEveViewAvail(DbsWznm* dbswznm);
	bool evalButEveViewActive(DbsWznm* dbswznm);
	bool evalTxtEviActive(DbsWznm* dbswznm);
	bool evalButEviViewAvail(DbsWznm* dbswznm);
	bool evalButEviViewActive(DbsWznm* dbswznm);
	bool evalTxtEsnActive(DbsWznm* dbswznm);
	bool evalButEsnViewAvail(DbsWznm* dbswznm);
	bool evalButEsnViewActive(DbsWznm* dbswznm);
	bool evalPupLacActive(DbsWznm* dbswznm);
	bool evalChkCstActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmSteDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmSteDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupEac;
	Sbecore::Xmlio::Feed feedFPupLac;

	WznmMState recSte;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecSte(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSeqViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButErjViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButEveViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButEviViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButEsnViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmSteUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSte_erjEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSte_esnEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSte_eveEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSte_eviEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSte_seqEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

