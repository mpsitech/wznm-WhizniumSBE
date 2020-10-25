/**
	* \file PnlWznmQmdDetail.h
	* job handler for job PnlWznmQmdDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMQMDDETAIL_H
#define PNLWZNMQMDDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmQmdDetailDo PnlWznmQmdDetail::VecVDo

#define ContIacWznmQmdDetail PnlWznmQmdDetail::ContIac
#define ContInfWznmQmdDetail PnlWznmQmdDetail::ContInf
#define StatAppWznmQmdDetail PnlWznmQmdDetail::StatApp
#define StatShrWznmQmdDetail PnlWznmQmdDetail::StatShr
#define TagWznmQmdDetail PnlWznmQmdDetail::Tag

#define DpchAppWznmQmdDetailData PnlWznmQmdDetail::DpchAppData
#define DpchAppWznmQmdDetailDo PnlWznmQmdDetail::DpchAppDo
#define DpchEngWznmQmdDetailData PnlWznmQmdDetail::DpchEngData

/**
	* PnlWznmQmdDetail
	*/
class PnlWznmQmdDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmQmdDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTQRYVIEWCLICK = 2;
		static const Sbecore::uint BUTPSTVIEWCLICK = 3;
		static const Sbecore::uint BUTREUVIEWCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmQmdDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint TXFAVL = 3;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupRet = 1, const std::string& TxfAvl = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupRet;
		std::string TxfAvl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmQmdDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTQRY = 1;
		static const Sbecore::uint TXTPST = 2;
		static const Sbecore::uint TXTREU = 3;

	public:
		ContInf(const std::string& TxtQry = "", const std::string& TxtPst = "", const std::string& TxtReu = "");

	public:
		std::string TxtQry;
		std::string TxtPst;
		std::string TxtReu;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmQmdDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmQmdDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint PUPTYPACTIVE = 3;
		static const Sbecore::uint TXTQRYACTIVE = 4;
		static const Sbecore::uint BUTQRYVIEWAVAIL = 5;
		static const Sbecore::uint BUTQRYVIEWACTIVE = 6;
		static const Sbecore::uint TXTPSTACTIVE = 7;
		static const Sbecore::uint BUTPSTVIEWAVAIL = 8;
		static const Sbecore::uint BUTPSTVIEWACTIVE = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint TXFAVLACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool PupTypActive = true, const bool TxtQryActive = true, const bool ButQryViewAvail = true, const bool ButQryViewActive = true, const bool TxtPstActive = true, const bool ButPstViewAvail = true, const bool ButPstViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxfAvlActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool PupTypActive;
		bool TxtQryActive;
		bool ButQryViewAvail;
		bool ButQryViewActive;
		bool TxtPstActive;
		bool ButPstViewAvail;
		bool ButPstViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxfAvlActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmQmdDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmQmdDetailData)
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
		* DpchAppDo (full: DpchAppWznmQmdDetailDo)
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
		* DpchEngData (full: DpchEngWznmQmdDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPRET = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupRet = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupRet;
		Sbecore::Xmlio::Feed feedFPupTyp;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalPupTypActive(DbsWznm* dbswznm);
	bool evalTxtQryActive(DbsWznm* dbswznm);
	bool evalButQryViewAvail(DbsWznm* dbswznm);
	bool evalButQryViewActive(DbsWznm* dbswznm);
	bool evalTxtPstActive(DbsWznm* dbswznm);
	bool evalButPstViewAvail(DbsWznm* dbswznm);
	bool evalButPstViewActive(DbsWznm* dbswznm);
	bool evalTxtReuActive(DbsWznm* dbswznm);
	bool evalButReuViewAvail(DbsWznm* dbswznm);
	bool evalButReuViewActive(DbsWznm* dbswznm);
	bool evalTxfAvlActive(DbsWznm* dbswznm);

public:
	PnlWznmQmdDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmQmdDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupRet;
	Sbecore::Xmlio::Feed feedFPupTyp;

	WznmMQuerymod recQmd;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecQmd(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButQryViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmQmdUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmQmd_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmQmd_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmQmd_qryEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmQmd_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

