/**
	* \file PnlWznmNavDbstr.h
	* job handler for job PnlWznmNavDbstr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVDBSTR_H
#define PNLWZNMNAVDBSTR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavDbstrDo PnlWznmNavDbstr::VecVDo

#define ContIacWznmNavDbstr PnlWznmNavDbstr::ContIac
#define StatAppWznmNavDbstr PnlWznmNavDbstr::StatApp
#define StatShrWznmNavDbstr PnlWznmNavDbstr::StatShr
#define TagWznmNavDbstr PnlWznmNavDbstr::Tag

#define DpchAppWznmNavDbstrData PnlWznmNavDbstr::DpchAppData
#define DpchAppWznmNavDbstrDo PnlWznmNavDbstr::DpchAppDo
#define DpchEngWznmNavDbstrData PnlWznmNavDbstr::DpchEngData

/**
	* PnlWznmNavDbstr
	*/
class PnlWznmNavDbstr : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavDbstrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTTBLVIEWCLICK = 1;
		static const Sbecore::uint BUTTBLNEWCRDCLICK = 2;
		static const Sbecore::uint BUTTCOVIEWCLICK = 3;
		static const Sbecore::uint BUTTCONEWCRDCLICK = 4;
		static const Sbecore::uint BUTSBSVIEWCLICK = 5;
		static const Sbecore::uint BUTSBSNEWCRDCLICK = 6;
		static const Sbecore::uint BUTRELVIEWCLICK = 7;
		static const Sbecore::uint BUTRELNEWCRDCLICK = 8;
		static const Sbecore::uint BUTVECVIEWCLICK = 9;
		static const Sbecore::uint BUTVECNEWCRDCLICK = 10;
		static const Sbecore::uint BUTVITVIEWCLICK = 11;
		static const Sbecore::uint BUTVITNEWCRDCLICK = 12;
		static const Sbecore::uint BUTCHKVIEWCLICK = 13;
		static const Sbecore::uint BUTCHKNEWCRDCLICK = 14;
		static const Sbecore::uint BUTSTBVIEWCLICK = 15;
		static const Sbecore::uint BUTSTBNEWCRDCLICK = 16;
		static const Sbecore::uint BUTIEXVIEWCLICK = 17;
		static const Sbecore::uint BUTIEXNEWCRDCLICK = 18;
		static const Sbecore::uint BUTIMEVIEWCLICK = 19;
		static const Sbecore::uint BUTIMENEWCRDCLICK = 20;
		static const Sbecore::uint BUTIELVIEWCLICK = 21;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavDbstr)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTTBL = 1;
		static const Sbecore::uint NUMFLSTTCO = 2;
		static const Sbecore::uint NUMFLSTSBS = 3;
		static const Sbecore::uint NUMFLSTREL = 4;
		static const Sbecore::uint NUMFLSTVEC = 5;
		static const Sbecore::uint NUMFLSTVIT = 6;
		static const Sbecore::uint NUMFLSTCHK = 7;
		static const Sbecore::uint NUMFLSTSTB = 8;
		static const Sbecore::uint NUMFLSTIEX = 9;
		static const Sbecore::uint NUMFLSTIME = 10;
		static const Sbecore::uint NUMFLSTIEL = 11;

	public:
		ContIac(const Sbecore::uint numFLstTbl = 1, const Sbecore::uint numFLstTco = 1, const Sbecore::uint numFLstSbs = 1, const Sbecore::uint numFLstRel = 1, const Sbecore::uint numFLstVec = 1, const Sbecore::uint numFLstVit = 1, const Sbecore::uint numFLstChk = 1, const Sbecore::uint numFLstStb = 1, const Sbecore::uint numFLstIex = 1, const Sbecore::uint numFLstIme = 1, const Sbecore::uint numFLstIel = 1);

	public:
		Sbecore::uint numFLstTbl;
		Sbecore::uint numFLstTco;
		Sbecore::uint numFLstSbs;
		Sbecore::uint numFLstRel;
		Sbecore::uint numFLstVec;
		Sbecore::uint numFLstVit;
		Sbecore::uint numFLstChk;
		Sbecore::uint numFLstStb;
		Sbecore::uint numFLstIex;
		Sbecore::uint numFLstIme;
		Sbecore::uint numFLstIel;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWznmNavDbstr)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstTblAlt = true, const bool LstTcoAlt = true, const bool LstSbsAlt = true, const bool LstRelAlt = true, const bool LstVecAlt = true, const bool LstVitAlt = true, const bool LstChkAlt = true, const bool LstStbAlt = true, const bool LstIexAlt = true, const bool LstImeAlt = true, const bool LstIelAlt = true, const Sbecore::uint LstTblNumFirstdisp = 1, const Sbecore::uint LstTcoNumFirstdisp = 1, const Sbecore::uint LstSbsNumFirstdisp = 1, const Sbecore::uint LstRelNumFirstdisp = 1, const Sbecore::uint LstVecNumFirstdisp = 1, const Sbecore::uint LstVitNumFirstdisp = 1, const Sbecore::uint LstChkNumFirstdisp = 1, const Sbecore::uint LstStbNumFirstdisp = 1, const Sbecore::uint LstIexNumFirstdisp = 1, const Sbecore::uint LstImeNumFirstdisp = 1, const Sbecore::uint LstIelNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmNavDbstr)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTTBLAVAIL = 1;
		static const Sbecore::uint BUTTBLVIEWACTIVE = 2;
		static const Sbecore::uint BUTTBLNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTTCOAVAIL = 4;
		static const Sbecore::uint BUTTCOVIEWACTIVE = 5;
		static const Sbecore::uint BUTTCONEWCRDACTIVE = 6;
		static const Sbecore::uint LSTSBSAVAIL = 7;
		static const Sbecore::uint BUTSBSVIEWACTIVE = 8;
		static const Sbecore::uint BUTSBSNEWCRDACTIVE = 9;
		static const Sbecore::uint LSTRELAVAIL = 10;
		static const Sbecore::uint BUTRELVIEWACTIVE = 11;
		static const Sbecore::uint BUTRELNEWCRDACTIVE = 12;
		static const Sbecore::uint LSTVECAVAIL = 13;
		static const Sbecore::uint BUTVECVIEWACTIVE = 14;
		static const Sbecore::uint BUTVECNEWCRDACTIVE = 15;
		static const Sbecore::uint LSTVITAVAIL = 16;
		static const Sbecore::uint BUTVITVIEWACTIVE = 17;
		static const Sbecore::uint BUTVITNEWCRDACTIVE = 18;
		static const Sbecore::uint LSTCHKAVAIL = 19;
		static const Sbecore::uint BUTCHKVIEWACTIVE = 20;
		static const Sbecore::uint BUTCHKNEWCRDACTIVE = 21;
		static const Sbecore::uint LSTSTBAVAIL = 22;
		static const Sbecore::uint BUTSTBVIEWACTIVE = 23;
		static const Sbecore::uint BUTSTBNEWCRDACTIVE = 24;
		static const Sbecore::uint LSTIEXAVAIL = 25;
		static const Sbecore::uint BUTIEXVIEWACTIVE = 26;
		static const Sbecore::uint BUTIEXNEWCRDACTIVE = 27;
		static const Sbecore::uint LSTIMEAVAIL = 28;
		static const Sbecore::uint BUTIMEVIEWACTIVE = 29;
		static const Sbecore::uint BUTIMENEWCRDACTIVE = 30;
		static const Sbecore::uint LSTIELAVAIL = 31;
		static const Sbecore::uint BUTIELVIEWACTIVE = 32;

	public:
		StatShr(const bool LstTblAvail = true, const bool ButTblViewActive = true, const bool ButTblNewcrdActive = true, const bool LstTcoAvail = true, const bool ButTcoViewActive = true, const bool ButTcoNewcrdActive = true, const bool LstSbsAvail = true, const bool ButSbsViewActive = true, const bool ButSbsNewcrdActive = true, const bool LstRelAvail = true, const bool ButRelViewActive = true, const bool ButRelNewcrdActive = true, const bool LstVecAvail = true, const bool ButVecViewActive = true, const bool ButVecNewcrdActive = true, const bool LstVitAvail = true, const bool ButVitViewActive = true, const bool ButVitNewcrdActive = true, const bool LstChkAvail = true, const bool ButChkViewActive = true, const bool ButChkNewcrdActive = true, const bool LstStbAvail = true, const bool ButStbViewActive = true, const bool ButStbNewcrdActive = true, const bool LstIexAvail = true, const bool ButIexViewActive = true, const bool ButIexNewcrdActive = true, const bool LstImeAvail = true, const bool ButImeViewActive = true, const bool ButImeNewcrdActive = true, const bool LstIelAvail = true, const bool ButIelViewActive = true);

	public:
		bool LstTblAvail;
		bool ButTblViewActive;
		bool ButTblNewcrdActive;
		bool LstTcoAvail;
		bool ButTcoViewActive;
		bool ButTcoNewcrdActive;
		bool LstSbsAvail;
		bool ButSbsViewActive;
		bool ButSbsNewcrdActive;
		bool LstRelAvail;
		bool ButRelViewActive;
		bool ButRelNewcrdActive;
		bool LstVecAvail;
		bool ButVecViewActive;
		bool ButVecNewcrdActive;
		bool LstVitAvail;
		bool ButVitViewActive;
		bool ButVitNewcrdActive;
		bool LstChkAvail;
		bool ButChkViewActive;
		bool ButChkNewcrdActive;
		bool LstStbAvail;
		bool ButStbViewActive;
		bool ButStbNewcrdActive;
		bool LstIexAvail;
		bool ButIexViewActive;
		bool ButIexNewcrdActive;
		bool LstImeAvail;
		bool ButImeViewActive;
		bool ButImeNewcrdActive;
		bool LstIelAvail;
		bool ButIelViewActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavDbstr)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavDbstrData)
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
		* DpchAppDo (full: DpchAppWznmNavDbstrDo)
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
		* DpchEngData (full: DpchEngWznmNavDbstrData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCHK = 3;
		static const Sbecore::uint FEEDFLSTIEL = 4;
		static const Sbecore::uint FEEDFLSTIEX = 5;
		static const Sbecore::uint FEEDFLSTIME = 6;
		static const Sbecore::uint FEEDFLSTREL = 7;
		static const Sbecore::uint FEEDFLSTSBS = 8;
		static const Sbecore::uint FEEDFLSTSTB = 9;
		static const Sbecore::uint FEEDFLSTTBL = 10;
		static const Sbecore::uint FEEDFLSTTCO = 11;
		static const Sbecore::uint FEEDFLSTVEC = 12;
		static const Sbecore::uint FEEDFLSTVIT = 13;
		static const Sbecore::uint STATAPP = 14;
		static const Sbecore::uint STATSHR = 15;
		static const Sbecore::uint TAG = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstChk = NULL, Sbecore::Xmlio::Feed* feedFLstIel = NULL, Sbecore::Xmlio::Feed* feedFLstIex = NULL, Sbecore::Xmlio::Feed* feedFLstIme = NULL, Sbecore::Xmlio::Feed* feedFLstRel = NULL, Sbecore::Xmlio::Feed* feedFLstSbs = NULL, Sbecore::Xmlio::Feed* feedFLstStb = NULL, Sbecore::Xmlio::Feed* feedFLstTbl = NULL, Sbecore::Xmlio::Feed* feedFLstTco = NULL, Sbecore::Xmlio::Feed* feedFLstVec = NULL, Sbecore::Xmlio::Feed* feedFLstVit = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstChk;
		Sbecore::Xmlio::Feed feedFLstIel;
		Sbecore::Xmlio::Feed feedFLstIex;
		Sbecore::Xmlio::Feed feedFLstIme;
		Sbecore::Xmlio::Feed feedFLstRel;
		Sbecore::Xmlio::Feed feedFLstSbs;
		Sbecore::Xmlio::Feed feedFLstStb;
		Sbecore::Xmlio::Feed feedFLstTbl;
		Sbecore::Xmlio::Feed feedFLstTco;
		Sbecore::Xmlio::Feed feedFLstVec;
		Sbecore::Xmlio::Feed feedFLstVit;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstTblAvail(DbsWznm* dbswznm);
	bool evalButTblViewActive(DbsWznm* dbswznm);
	bool evalButTblNewcrdActive(DbsWznm* dbswznm);
	bool evalLstTcoAvail(DbsWznm* dbswznm);
	bool evalButTcoViewActive(DbsWznm* dbswznm);
	bool evalButTcoNewcrdActive(DbsWznm* dbswznm);
	bool evalLstSbsAvail(DbsWznm* dbswznm);
	bool evalButSbsViewActive(DbsWznm* dbswznm);
	bool evalButSbsNewcrdActive(DbsWznm* dbswznm);
	bool evalLstRelAvail(DbsWznm* dbswznm);
	bool evalButRelViewActive(DbsWznm* dbswznm);
	bool evalButRelNewcrdActive(DbsWznm* dbswznm);
	bool evalLstVecAvail(DbsWznm* dbswznm);
	bool evalButVecViewActive(DbsWznm* dbswznm);
	bool evalButVecNewcrdActive(DbsWznm* dbswznm);
	bool evalLstVitAvail(DbsWznm* dbswznm);
	bool evalButVitViewActive(DbsWznm* dbswznm);
	bool evalButVitNewcrdActive(DbsWznm* dbswznm);
	bool evalLstChkAvail(DbsWznm* dbswznm);
	bool evalButChkViewActive(DbsWznm* dbswznm);
	bool evalButChkNewcrdActive(DbsWznm* dbswznm);
	bool evalLstStbAvail(DbsWznm* dbswznm);
	bool evalButStbViewActive(DbsWznm* dbswznm);
	bool evalButStbNewcrdActive(DbsWznm* dbswznm);
	bool evalLstIexAvail(DbsWznm* dbswznm);
	bool evalButIexViewActive(DbsWznm* dbswznm);
	bool evalButIexNewcrdActive(DbsWznm* dbswznm);
	bool evalLstImeAvail(DbsWznm* dbswznm);
	bool evalButImeViewActive(DbsWznm* dbswznm);
	bool evalButImeNewcrdActive(DbsWznm* dbswznm);
	bool evalLstIelAvail(DbsWznm* dbswznm);
	bool evalButIelViewActive(DbsWznm* dbswznm);

public:
	PnlWznmNavDbstr(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavDbstr();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstChk;
	Sbecore::Xmlio::Feed feedFLstIel;
	Sbecore::Xmlio::Feed feedFLstIex;
	Sbecore::Xmlio::Feed feedFLstIme;
	Sbecore::Xmlio::Feed feedFLstRel;
	Sbecore::Xmlio::Feed feedFLstSbs;
	Sbecore::Xmlio::Feed feedFLstStb;
	Sbecore::Xmlio::Feed feedFLstTbl;
	Sbecore::Xmlio::Feed feedFLstTco;
	Sbecore::Xmlio::Feed feedFLstVec;
	Sbecore::Xmlio::Feed feedFLstVit;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstTbl(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTbl(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstTco(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTco(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstSbs(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshSbs(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstRel(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRel(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstVec(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshVec(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstVit(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshVit(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstChk(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshChk(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstStb(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshStb(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstIex(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshIex(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstIme(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshIme(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstIel(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshIel(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButTblViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButTblNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButTcoViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButTcoNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSbsViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSbsNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRelViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRelNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVecViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVecNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVitViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVitNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButChkViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButChkNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButStbViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButStbNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButIexViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButIexNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButImeViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButImeNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButIelViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif



