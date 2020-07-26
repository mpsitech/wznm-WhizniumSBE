/**
	* \file PnlWznmNavGlobal.h
	* job handler for job PnlWznmNavGlobal (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMNAVGLOBAL_H
#define PNLWZNMNAVGLOBAL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavGlobalDo PnlWznmNavGlobal::VecVDo

#define ContIacWznmNavGlobal PnlWznmNavGlobal::ContIac
#define StatAppWznmNavGlobal PnlWznmNavGlobal::StatApp
#define StatShrWznmNavGlobal PnlWznmNavGlobal::StatShr
#define TagWznmNavGlobal PnlWznmNavGlobal::Tag

#define DpchAppWznmNavGlobalData PnlWznmNavGlobal::DpchAppData
#define DpchAppWznmNavGlobalDo PnlWznmNavGlobal::DpchAppDo
#define DpchEngWznmNavGlobalData PnlWznmNavGlobal::DpchEngData

/**
	* PnlWznmNavGlobal
	*/
class PnlWznmNavGlobal : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavGlobalDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTLOCVIEWCLICK = 1;
		static const Sbecore::uint BUTLOCNEWCRDCLICK = 2;
		static const Sbecore::uint BUTTAGVIEWCLICK = 3;
		static const Sbecore::uint BUTTAGNEWCRDCLICK = 4;
		static const Sbecore::uint BUTCTPVIEWCLICK = 5;
		static const Sbecore::uint BUTCTPNEWCRDCLICK = 6;
		static const Sbecore::uint BUTMTYVIEWCLICK = 7;
		static const Sbecore::uint BUTMTYNEWCRDCLICK = 8;
		static const Sbecore::uint BUTMCHVIEWCLICK = 9;
		static const Sbecore::uint BUTMCHNEWCRDCLICK = 10;
		static const Sbecore::uint BUTLIBVIEWCLICK = 11;
		static const Sbecore::uint BUTLIBNEWCRDCLICK = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavGlobal)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTLOC = 1;
		static const Sbecore::uint NUMFLSTTAG = 2;
		static const Sbecore::uint NUMFLSTCTP = 3;
		static const Sbecore::uint NUMFLSTMTY = 4;
		static const Sbecore::uint NUMFLSTMCH = 5;
		static const Sbecore::uint NUMFLSTLIB = 6;

	public:
		ContIac(const Sbecore::uint numFLstLoc = 1, const Sbecore::uint numFLstTag = 1, const Sbecore::uint numFLstCtp = 1, const Sbecore::uint numFLstMty = 1, const Sbecore::uint numFLstMch = 1, const Sbecore::uint numFLstLib = 1);

	public:
		Sbecore::uint numFLstLoc;
		Sbecore::uint numFLstTag;
		Sbecore::uint numFLstCtp;
		Sbecore::uint numFLstMty;
		Sbecore::uint numFLstMch;
		Sbecore::uint numFLstLib;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWznmNavGlobal)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstLocAlt = true, const bool LstTagAlt = true, const bool LstCtpAlt = true, const bool LstMtyAlt = true, const bool LstMchAlt = true, const bool LstLibAlt = true, const Sbecore::uint LstLocNumFirstdisp = 1, const Sbecore::uint LstTagNumFirstdisp = 1, const Sbecore::uint LstCtpNumFirstdisp = 1, const Sbecore::uint LstMtyNumFirstdisp = 1, const Sbecore::uint LstMchNumFirstdisp = 1, const Sbecore::uint LstLibNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmNavGlobal)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTLOCAVAIL = 1;
		static const Sbecore::uint BUTLOCVIEWACTIVE = 2;
		static const Sbecore::uint LSTTAGAVAIL = 3;
		static const Sbecore::uint BUTTAGVIEWACTIVE = 4;
		static const Sbecore::uint LSTCTPAVAIL = 5;
		static const Sbecore::uint BUTCTPVIEWACTIVE = 6;
		static const Sbecore::uint LSTMTYAVAIL = 7;
		static const Sbecore::uint BUTMTYVIEWACTIVE = 8;
		static const Sbecore::uint LSTMCHAVAIL = 9;
		static const Sbecore::uint BUTMCHVIEWACTIVE = 10;
		static const Sbecore::uint LSTLIBAVAIL = 11;
		static const Sbecore::uint BUTLIBVIEWACTIVE = 12;

	public:
		StatShr(const bool LstLocAvail = true, const bool ButLocViewActive = true, const bool LstTagAvail = true, const bool ButTagViewActive = true, const bool LstCtpAvail = true, const bool ButCtpViewActive = true, const bool LstMtyAvail = true, const bool ButMtyViewActive = true, const bool LstMchAvail = true, const bool ButMchViewActive = true, const bool LstLibAvail = true, const bool ButLibViewActive = true);

	public:
		bool LstLocAvail;
		bool ButLocViewActive;
		bool LstTagAvail;
		bool ButTagViewActive;
		bool LstCtpAvail;
		bool ButCtpViewActive;
		bool LstMtyAvail;
		bool ButMtyViewActive;
		bool LstMchAvail;
		bool ButMchViewActive;
		bool LstLibAvail;
		bool ButLibViewActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavGlobal)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavGlobalData)
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
		* DpchAppDo (full: DpchAppWznmNavGlobalDo)
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
		* DpchEngData (full: DpchEngWznmNavGlobalData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCTP = 3;
		static const Sbecore::uint FEEDFLSTLIB = 4;
		static const Sbecore::uint FEEDFLSTLOC = 5;
		static const Sbecore::uint FEEDFLSTMCH = 6;
		static const Sbecore::uint FEEDFLSTMTY = 7;
		static const Sbecore::uint FEEDFLSTTAG = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstCtp = NULL, Sbecore::Xmlio::Feed* feedFLstLib = NULL, Sbecore::Xmlio::Feed* feedFLstLoc = NULL, Sbecore::Xmlio::Feed* feedFLstMch = NULL, Sbecore::Xmlio::Feed* feedFLstMty = NULL, Sbecore::Xmlio::Feed* feedFLstTag = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCtp;
		Sbecore::Xmlio::Feed feedFLstLib;
		Sbecore::Xmlio::Feed feedFLstLoc;
		Sbecore::Xmlio::Feed feedFLstMch;
		Sbecore::Xmlio::Feed feedFLstMty;
		Sbecore::Xmlio::Feed feedFLstTag;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstLocAvail(DbsWznm* dbswznm);
	bool evalButLocViewActive(DbsWznm* dbswznm);
	bool evalLstTagAvail(DbsWznm* dbswznm);
	bool evalButTagViewActive(DbsWznm* dbswznm);
	bool evalLstCtpAvail(DbsWznm* dbswznm);
	bool evalButCtpViewActive(DbsWznm* dbswznm);
	bool evalLstMtyAvail(DbsWznm* dbswznm);
	bool evalButMtyViewActive(DbsWznm* dbswznm);
	bool evalLstMchAvail(DbsWznm* dbswznm);
	bool evalButMchViewActive(DbsWznm* dbswznm);
	bool evalLstLibAvail(DbsWznm* dbswznm);
	bool evalButLibViewActive(DbsWznm* dbswznm);

public:
	PnlWznmNavGlobal(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavGlobal();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstCtp;
	Sbecore::Xmlio::Feed feedFLstLib;
	Sbecore::Xmlio::Feed feedFLstLoc;
	Sbecore::Xmlio::Feed feedFLstMch;
	Sbecore::Xmlio::Feed feedFLstMty;
	Sbecore::Xmlio::Feed feedFLstTag;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstLoc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLoc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstTag(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTag(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstCtp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCtp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstMty(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshMty(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstMch(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshMch(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstLib(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLib(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButLocViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButLocNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButTagViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButTagNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCtpViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCtpNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMtyViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMtyNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMchViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMchNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButLibViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButLibNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif

