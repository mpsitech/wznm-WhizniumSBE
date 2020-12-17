/**
	* \file PnlWznmQryDetail.h
	* job handler for job PnlWznmQryDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMQRYDETAIL_H
#define PNLWZNMQRYDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmQryDetailDo PnlWznmQryDetail::VecVDo

#define ContIacWznmQryDetail PnlWznmQryDetail::ContIac
#define ContInfWznmQryDetail PnlWznmQryDetail::ContInf
#define StatAppWznmQryDetail PnlWznmQryDetail::StatApp
#define StatShrWznmQryDetail PnlWznmQryDetail::StatShr
#define TagWznmQryDetail PnlWznmQryDetail::Tag

#define DpchAppWznmQryDetailData PnlWznmQryDetail::DpchAppData
#define DpchAppWznmQryDetailDo PnlWznmQryDetail::DpchAppDo
#define DpchEngWznmQryDetailData PnlWznmQryDetail::DpchEngData

/**
	* PnlWznmQryDetail
	*/
class PnlWznmQryDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmQryDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;
		static const Sbecore::uint BUTJOBVIEWCLICK = 4;
		static const Sbecore::uint BUTINOVIEWCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmQryDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint CHKLOF = 2;
		static const Sbecore::uint NUMFLSTINO = 3;
		static const Sbecore::uint TXFINO = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const bool ChkLof = false, const Sbecore::uint numFLstIno = 1, const std::string& TxfIno = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupTyp;
		bool ChkLof;
		Sbecore::uint numFLstIno;
		std::string TxfIno;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmQryDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTSUP = 3;
		static const Sbecore::uint TXTTBL = 4;
		static const Sbecore::uint TXTQTB = 5;
		static const Sbecore::uint TXTJOB = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtSup = "", const std::string& TxtTbl = "", const std::string& TxtQtb = "", const std::string& TxtJob = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtSup;
		std::string TxtTbl;
		std::string TxtQtb;
		std::string TxtJob;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmQryDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstInoAlt = true, const Sbecore::uint LstInoNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmQryDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFINOVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint TXTVERACTIVE = 6;
		static const Sbecore::uint BUTVERVIEWAVAIL = 7;
		static const Sbecore::uint BUTVERVIEWACTIVE = 8;
		static const Sbecore::uint TXTSUPACTIVE = 9;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 10;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 11;
		static const Sbecore::uint TXTTBLACTIVE = 12;
		static const Sbecore::uint TXTQTBACTIVE = 13;
		static const Sbecore::uint TXTJOBACTIVE = 14;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 15;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 16;
		static const Sbecore::uint CHKLOFACTIVE = 17;
		static const Sbecore::uint LSTINOACTIVE = 18;
		static const Sbecore::uint BUTINOVIEWAVAIL = 19;
		static const Sbecore::uint BUTINOVIEWACTIVE = 20;
		static const Sbecore::uint TXFCMTACTIVE = 21;

	public:
		StatShr(const bool TxfInoValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTblActive = true, const bool TxtQtbActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool ChkLofActive = true, const bool LstInoActive = true, const bool ButInoViewAvail = true, const bool ButInoViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfInoValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtTblActive;
		bool TxtQtbActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool ChkLofActive;
		bool LstInoActive;
		bool ButInoViewAvail;
		bool ButInoViewActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmQryDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmQryDetailData)
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
		* DpchAppDo (full: DpchAppWznmQryDetailDo)
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
		* DpchEngData (full: DpchEngWznmQryDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTINO = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstIno = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstIno;
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
	bool evalTxtSupActive(DbsWznm* dbswznm);
	bool evalButSupViewAvail(DbsWznm* dbswznm);
	bool evalButSupViewActive(DbsWznm* dbswznm);
	bool evalTxtTblActive(DbsWznm* dbswznm);
	bool evalTxtQtbActive(DbsWznm* dbswznm);
	bool evalTxtJobActive(DbsWznm* dbswznm);
	bool evalButJobViewAvail(DbsWznm* dbswznm);
	bool evalButJobViewActive(DbsWznm* dbswznm);
	bool evalChkLofActive(DbsWznm* dbswznm);
	bool evalLstInoActive(DbsWznm* dbswznm);
	bool evalButInoViewAvail(DbsWznm* dbswznm);
	bool evalButInoViewActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmQryDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmQryDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstIno;
	Sbecore::Xmlio::Feed feedFPupTyp;

	WznmMQuery recQry;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstIno(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshIno(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecQry(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVerViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJobViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButInoViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmQryUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmQry_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmQry_supEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmQry_jobEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
