/**
	* \file PnlWznmMtyDetail.h
	* job handler for job PnlWznmMtyDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef PNLWZNMMTYDETAIL_H
#define PNLWZNMMTYDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmMtyDetailDo PnlWznmMtyDetail::VecVDo

#define ContIacWznmMtyDetail PnlWznmMtyDetail::ContIac
#define ContInfWznmMtyDetail PnlWznmMtyDetail::ContInf
#define StatAppWznmMtyDetail PnlWznmMtyDetail::StatApp
#define StatShrWznmMtyDetail PnlWznmMtyDetail::StatShr
#define TagWznmMtyDetail PnlWznmMtyDetail::Tag

#define DpchAppWznmMtyDetailData PnlWznmMtyDetail::DpchAppData
#define DpchAppWznmMtyDetailDo PnlWznmMtyDetail::DpchAppDo
#define DpchEngWznmMtyDetailData PnlWznmMtyDetail::DpchEngData

/**
	* PnlWznmMtyDetail
	*/
class PnlWznmMtyDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmMtyDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTOSEDITCLICK = 2;
		static const Sbecore::uint BUTCCHVIEWCLICK = 3;
		static const Sbecore::uint BUTPKMEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmMtyDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPACH = 1;
		static const Sbecore::uint NUMFPUPOS = 2;
		static const Sbecore::uint TXFOS = 3;
		static const Sbecore::uint NUMFPUPPKM = 4;
		static const Sbecore::uint TXFPKM = 5;
		static const Sbecore::uint TXFCMT = 6;

	public:
		ContIac(const Sbecore::uint numFPupAch = 1, const Sbecore::uint numFPupOs = 1, const std::string& TxfOs = "", const Sbecore::uint numFPupPkm = 1, const std::string& TxfPkm = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupAch;
		Sbecore::uint numFPupOs;
		std::string TxfOs;
		Sbecore::uint numFPupPkm;
		std::string TxfPkm;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmMtyDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCCH = 2;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtCch = "");

	public:
		std::string TxtSrf;
		std::string TxtCch;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmMtyDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool PupOsAlt = false, const bool PupPkmAlt = false);
	};

	/**
		* StatShr (full: StatShrWznmMtyDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFOSVALID = 1;
		static const Sbecore::uint TXFPKMVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint PUPACHACTIVE = 6;
		static const Sbecore::uint PUPOSACTIVE = 7;
		static const Sbecore::uint BUTOSEDITAVAIL = 8;
		static const Sbecore::uint TXTCCHACTIVE = 9;
		static const Sbecore::uint BUTCCHVIEWAVAIL = 10;
		static const Sbecore::uint BUTCCHVIEWACTIVE = 11;
		static const Sbecore::uint PUPPKMACTIVE = 12;
		static const Sbecore::uint BUTPKMEDITAVAIL = 13;
		static const Sbecore::uint TXFCMTACTIVE = 14;

	public:
		StatShr(const bool TxfOsValid = false, const bool TxfPkmValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupAchActive = true, const bool PupOsActive = true, const bool ButOsEditAvail = true, const bool TxtCchActive = true, const bool ButCchViewAvail = true, const bool ButCchViewActive = true, const bool PupPkmActive = true, const bool ButPkmEditAvail = true, const bool TxfCmtActive = true);

	public:
		bool TxfOsValid;
		bool TxfPkmValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupAchActive;
		bool PupOsActive;
		bool ButOsEditAvail;
		bool TxtCchActive;
		bool ButCchViewAvail;
		bool ButCchViewActive;
		bool PupPkmActive;
		bool ButPkmEditAvail;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmMtyDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmMtyDetailData)
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
		* DpchAppDo (full: DpchAppWznmMtyDetailDo)
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
		* DpchEngData (full: DpchEngWznmMtyDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPACH = 4;
		static const Sbecore::uint FEEDFPUPOS = 5;
		static const Sbecore::uint FEEDFPUPPKM = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupAch = NULL, Sbecore::Xmlio::Feed* feedFPupOs = NULL, Sbecore::Xmlio::Feed* feedFPupPkm = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupAch;
		Sbecore::Xmlio::Feed feedFPupOs;
		Sbecore::Xmlio::Feed feedFPupPkm;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxtSrfActive(DbsWznm* dbswznm);
	bool evalPupAchActive(DbsWznm* dbswznm);
	bool evalPupOsActive(DbsWznm* dbswznm);
	bool evalButOsEditAvail(DbsWznm* dbswznm);
	bool evalTxtCchActive(DbsWznm* dbswznm);
	bool evalButCchViewAvail(DbsWznm* dbswznm);
	bool evalButCchViewActive(DbsWznm* dbswznm);
	bool evalPupPkmActive(DbsWznm* dbswznm);
	bool evalButPkmEditAvail(DbsWznm* dbswznm);
	bool evalTxfCmtActive(DbsWznm* dbswznm);

public:
	PnlWznmMtyDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmMtyDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupAch;
	Sbecore::Xmlio::Feed feedFPupOs;
	Sbecore::Xmlio::Feed feedFPupPkm;

	WznmMMachtype recMty;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshPupOs(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfOs(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshOs(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPupPkm(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfPkm(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPkm(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecMty(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButOsEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCchViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPkmEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmKlsAkeyMod_klsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWznmMtyUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmMty_cchEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

