/**
	* \file PnlWznmLibDetail.h
	* job handler for job PnlWznmLibDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef PNLWZNMLIBDETAIL_H
#define PNLWZNMLIBDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmLibDetailDo PnlWznmLibDetail::VecVDo

#define ContIacWznmLibDetail PnlWznmLibDetail::ContIac
#define ContInfWznmLibDetail PnlWznmLibDetail::ContInf
#define StatAppWznmLibDetail PnlWznmLibDetail::StatApp
#define StatShrWznmLibDetail PnlWznmLibDetail::StatShr
#define TagWznmLibDetail PnlWznmLibDetail::Tag

#define DpchAppWznmLibDetailData PnlWznmLibDetail::DpchAppData
#define DpchAppWznmLibDetailDo PnlWznmLibDetail::DpchAppDo
#define DpchEngWznmLibDetailData PnlWznmLibDetail::DpchEngData

/**
	* PnlWznmLibDetail
	*/
class PnlWznmLibDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmLibDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTLTYEDITCLICK = 2;
		static const Sbecore::uint BUTDEPVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmLibDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFVER = 2;
		static const Sbecore::uint NUMFPUPLTY = 3;
		static const Sbecore::uint TXFLTY = 4;
		static const Sbecore::uint NUMFLSTDEP = 5;
		static const Sbecore::uint TXFDEP = 6;
		static const Sbecore::uint TXFCMT = 7;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfVer = "", const Sbecore::uint numFPupLty = 1, const std::string& TxfLty = "", const Sbecore::uint numFLstDep = 1, const std::string& TxfDep = "", const std::string& TxfCmt = "");

	public:
		std::string TxfTit;
		std::string TxfVer;
		Sbecore::uint numFPupLty;
		std::string TxfLty;
		Sbecore::uint numFLstDep;
		std::string TxfDep;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmLibDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;

	public:
		ContInf(const std::string& TxtSrf = "");

	public:
		std::string TxtSrf;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmLibDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool PupLtyAlt = false, const bool LstDepAlt = true, const Sbecore::uint LstDepNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmLibDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFLTYVALID = 1;
		static const Sbecore::uint TXFDEPVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint TXFTITACTIVE = 6;
		static const Sbecore::uint TXFVERACTIVE = 7;
		static const Sbecore::uint PUPLTYACTIVE = 8;
		static const Sbecore::uint BUTLTYEDITAVAIL = 9;
		static const Sbecore::uint LSTDEPACTIVE = 10;
		static const Sbecore::uint BUTDEPVIEWAVAIL = 11;
		static const Sbecore::uint BUTDEPVIEWACTIVE = 12;
		static const Sbecore::uint TXFCMTACTIVE = 13;

	public:
		StatShr(const bool TxfLtyValid = false, const bool TxfDepValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool TxfVerActive = true, const bool PupLtyActive = true, const bool ButLtyEditAvail = true, const bool LstDepActive = true, const bool ButDepViewAvail = true, const bool ButDepViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfLtyValid;
		bool TxfDepValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool TxfVerActive;
		bool PupLtyActive;
		bool ButLtyEditAvail;
		bool LstDepActive;
		bool ButDepViewAvail;
		bool ButDepViewActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmLibDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmLibDetailData)
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
		* DpchAppDo (full: DpchAppWznmLibDetailDo)
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
		* DpchEngData (full: DpchEngWznmLibDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDEP = 4;
		static const Sbecore::uint FEEDFPUPLTY = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstDep = NULL, Sbecore::Xmlio::Feed* feedFPupLty = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstDep;
		Sbecore::Xmlio::Feed feedFPupLty;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxtSrfActive(DbsWznm* dbswznm);
	bool evalTxfTitActive(DbsWznm* dbswznm);
	bool evalTxfVerActive(DbsWznm* dbswznm);
	bool evalPupLtyActive(DbsWznm* dbswznm);
	bool evalButLtyEditAvail(DbsWznm* dbswznm);
	bool evalLstDepActive(DbsWznm* dbswznm);
	bool evalButDepViewAvail(DbsWznm* dbswznm);
	bool evalButDepViewActive(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmLibDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmLibDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstDep;
	Sbecore::Xmlio::Feed feedFPupLty;

	WznmMLibrary recLib;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshPupLty(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfLty(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLty(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstDep(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshDep(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecLib(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButLtyEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDepViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmKlsAkeyMod_klsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWznmLibUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif

