/**
	* \file PnlWznmNavUix.h
	* job handler for job PnlWznmNavUix (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVUIX_H
#define PNLWZNMNAVUIX_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavUixDo PnlWznmNavUix::VecVDo

#define ContIacWznmNavUix PnlWznmNavUix::ContIac
#define StatAppWznmNavUix PnlWznmNavUix::StatApp
#define StatShrWznmNavUix PnlWznmNavUix::StatShr
#define TagWznmNavUix PnlWznmNavUix::Tag

#define DpchAppWznmNavUixData PnlWznmNavUix::DpchAppData
#define DpchAppWznmNavUixDo PnlWznmNavUix::DpchAppDo
#define DpchEngWznmNavUixData PnlWznmNavUix::DpchEngData

/**
	* PnlWznmNavUix
	*/
class PnlWznmNavUix : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavUixDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPSTVIEWCLICK = 1;
		static const Sbecore::uint BUTPSTNEWCRDCLICK = 2;
		static const Sbecore::uint BUTMDLVIEWCLICK = 3;
		static const Sbecore::uint BUTMDLNEWCRDCLICK = 4;
		static const Sbecore::uint BUTCARVIEWCLICK = 5;
		static const Sbecore::uint BUTCARNEWCRDCLICK = 6;
		static const Sbecore::uint BUTDLGVIEWCLICK = 7;
		static const Sbecore::uint BUTDLGNEWCRDCLICK = 8;
		static const Sbecore::uint BUTPNLVIEWCLICK = 9;
		static const Sbecore::uint BUTPNLNEWCRDCLICK = 10;
		static const Sbecore::uint BUTQRYVIEWCLICK = 11;
		static const Sbecore::uint BUTQRYNEWCRDCLICK = 12;
		static const Sbecore::uint BUTQCOVIEWCLICK = 13;
		static const Sbecore::uint BUTQCONEWCRDCLICK = 14;
		static const Sbecore::uint BUTQMDVIEWCLICK = 15;
		static const Sbecore::uint BUTQMDNEWCRDCLICK = 16;
		static const Sbecore::uint BUTCONVIEWCLICK = 17;
		static const Sbecore::uint BUTCONNEWCRDCLICK = 18;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavUix)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTPST = 1;
		static const Sbecore::uint NUMFLSTMDL = 2;
		static const Sbecore::uint NUMFLSTCAR = 3;
		static const Sbecore::uint NUMFLSTDLG = 4;
		static const Sbecore::uint NUMFLSTPNL = 5;
		static const Sbecore::uint NUMFLSTQRY = 6;
		static const Sbecore::uint NUMFLSTQCO = 7;
		static const Sbecore::uint NUMFLSTQMD = 8;
		static const Sbecore::uint NUMFLSTCON = 9;

	public:
		ContIac(const Sbecore::uint numFLstPst = 1, const Sbecore::uint numFLstMdl = 1, const Sbecore::uint numFLstCar = 1, const Sbecore::uint numFLstDlg = 1, const Sbecore::uint numFLstPnl = 1, const Sbecore::uint numFLstQry = 1, const Sbecore::uint numFLstQco = 1, const Sbecore::uint numFLstQmd = 1, const Sbecore::uint numFLstCon = 1);

	public:
		Sbecore::uint numFLstPst;
		Sbecore::uint numFLstMdl;
		Sbecore::uint numFLstCar;
		Sbecore::uint numFLstDlg;
		Sbecore::uint numFLstPnl;
		Sbecore::uint numFLstQry;
		Sbecore::uint numFLstQco;
		Sbecore::uint numFLstQmd;
		Sbecore::uint numFLstCon;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWznmNavUix)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstPstAlt = true, const bool LstMdlAlt = true, const bool LstCarAlt = true, const bool LstDlgAlt = true, const bool LstPnlAlt = true, const bool LstQryAlt = true, const bool LstQcoAlt = true, const bool LstQmdAlt = true, const bool LstConAlt = true, const Sbecore::uint LstPstNumFirstdisp = 1, const Sbecore::uint LstMdlNumFirstdisp = 1, const Sbecore::uint LstCarNumFirstdisp = 1, const Sbecore::uint LstDlgNumFirstdisp = 1, const Sbecore::uint LstPnlNumFirstdisp = 1, const Sbecore::uint LstQryNumFirstdisp = 1, const Sbecore::uint LstQcoNumFirstdisp = 1, const Sbecore::uint LstQmdNumFirstdisp = 1, const Sbecore::uint LstConNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmNavUix)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTPSTAVAIL = 1;
		static const Sbecore::uint BUTPSTVIEWACTIVE = 2;
		static const Sbecore::uint BUTPSTNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTMDLAVAIL = 4;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 5;
		static const Sbecore::uint BUTMDLNEWCRDACTIVE = 6;
		static const Sbecore::uint LSTCARAVAIL = 7;
		static const Sbecore::uint BUTCARVIEWACTIVE = 8;
		static const Sbecore::uint BUTCARNEWCRDACTIVE = 9;
		static const Sbecore::uint LSTDLGAVAIL = 10;
		static const Sbecore::uint BUTDLGVIEWACTIVE = 11;
		static const Sbecore::uint BUTDLGNEWCRDACTIVE = 12;
		static const Sbecore::uint LSTPNLAVAIL = 13;
		static const Sbecore::uint BUTPNLVIEWACTIVE = 14;
		static const Sbecore::uint BUTPNLNEWCRDACTIVE = 15;
		static const Sbecore::uint LSTQRYAVAIL = 16;
		static const Sbecore::uint BUTQRYVIEWACTIVE = 17;
		static const Sbecore::uint BUTQRYNEWCRDACTIVE = 18;
		static const Sbecore::uint LSTQCOAVAIL = 19;
		static const Sbecore::uint BUTQCOVIEWACTIVE = 20;
		static const Sbecore::uint BUTQCONEWCRDACTIVE = 21;
		static const Sbecore::uint LSTQMDAVAIL = 22;
		static const Sbecore::uint BUTQMDVIEWACTIVE = 23;
		static const Sbecore::uint BUTQMDNEWCRDACTIVE = 24;
		static const Sbecore::uint LSTCONAVAIL = 25;
		static const Sbecore::uint BUTCONVIEWACTIVE = 26;
		static const Sbecore::uint BUTCONNEWCRDACTIVE = 27;

	public:
		StatShr(const bool LstPstAvail = true, const bool ButPstViewActive = true, const bool ButPstNewcrdActive = true, const bool LstMdlAvail = true, const bool ButMdlViewActive = true, const bool ButMdlNewcrdActive = true, const bool LstCarAvail = true, const bool ButCarViewActive = true, const bool ButCarNewcrdActive = true, const bool LstDlgAvail = true, const bool ButDlgViewActive = true, const bool ButDlgNewcrdActive = true, const bool LstPnlAvail = true, const bool ButPnlViewActive = true, const bool ButPnlNewcrdActive = true, const bool LstQryAvail = true, const bool ButQryViewActive = true, const bool ButQryNewcrdActive = true, const bool LstQcoAvail = true, const bool ButQcoViewActive = true, const bool ButQcoNewcrdActive = true, const bool LstQmdAvail = true, const bool ButQmdViewActive = true, const bool ButQmdNewcrdActive = true, const bool LstConAvail = true, const bool ButConViewActive = true, const bool ButConNewcrdActive = true);

	public:
		bool LstPstAvail;
		bool ButPstViewActive;
		bool ButPstNewcrdActive;
		bool LstMdlAvail;
		bool ButMdlViewActive;
		bool ButMdlNewcrdActive;
		bool LstCarAvail;
		bool ButCarViewActive;
		bool ButCarNewcrdActive;
		bool LstDlgAvail;
		bool ButDlgViewActive;
		bool ButDlgNewcrdActive;
		bool LstPnlAvail;
		bool ButPnlViewActive;
		bool ButPnlNewcrdActive;
		bool LstQryAvail;
		bool ButQryViewActive;
		bool ButQryNewcrdActive;
		bool LstQcoAvail;
		bool ButQcoViewActive;
		bool ButQcoNewcrdActive;
		bool LstQmdAvail;
		bool ButQmdViewActive;
		bool ButQmdNewcrdActive;
		bool LstConAvail;
		bool ButConViewActive;
		bool ButConNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavUix)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavUixData)
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
		* DpchAppDo (full: DpchAppWznmNavUixDo)
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
		* DpchEngData (full: DpchEngWznmNavUixData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCAR = 3;
		static const Sbecore::uint FEEDFLSTCON = 4;
		static const Sbecore::uint FEEDFLSTDLG = 5;
		static const Sbecore::uint FEEDFLSTMDL = 6;
		static const Sbecore::uint FEEDFLSTPNL = 7;
		static const Sbecore::uint FEEDFLSTPST = 8;
		static const Sbecore::uint FEEDFLSTQCO = 9;
		static const Sbecore::uint FEEDFLSTQMD = 10;
		static const Sbecore::uint FEEDFLSTQRY = 11;
		static const Sbecore::uint STATAPP = 12;
		static const Sbecore::uint STATSHR = 13;
		static const Sbecore::uint TAG = 14;
		static const Sbecore::uint ALL = 15;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstCar = NULL, Sbecore::Xmlio::Feed* feedFLstCon = NULL, Sbecore::Xmlio::Feed* feedFLstDlg = NULL, Sbecore::Xmlio::Feed* feedFLstMdl = NULL, Sbecore::Xmlio::Feed* feedFLstPnl = NULL, Sbecore::Xmlio::Feed* feedFLstPst = NULL, Sbecore::Xmlio::Feed* feedFLstQco = NULL, Sbecore::Xmlio::Feed* feedFLstQmd = NULL, Sbecore::Xmlio::Feed* feedFLstQry = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCar;
		Sbecore::Xmlio::Feed feedFLstCon;
		Sbecore::Xmlio::Feed feedFLstDlg;
		Sbecore::Xmlio::Feed feedFLstMdl;
		Sbecore::Xmlio::Feed feedFLstPnl;
		Sbecore::Xmlio::Feed feedFLstPst;
		Sbecore::Xmlio::Feed feedFLstQco;
		Sbecore::Xmlio::Feed feedFLstQmd;
		Sbecore::Xmlio::Feed feedFLstQry;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstPstAvail(DbsWznm* dbswznm);
	bool evalButPstViewActive(DbsWznm* dbswznm);
	bool evalButPstNewcrdActive(DbsWznm* dbswznm);
	bool evalLstMdlAvail(DbsWznm* dbswznm);
	bool evalButMdlViewActive(DbsWznm* dbswznm);
	bool evalButMdlNewcrdActive(DbsWznm* dbswznm);
	bool evalLstCarAvail(DbsWznm* dbswznm);
	bool evalButCarViewActive(DbsWznm* dbswznm);
	bool evalButCarNewcrdActive(DbsWznm* dbswznm);
	bool evalLstDlgAvail(DbsWznm* dbswznm);
	bool evalButDlgViewActive(DbsWznm* dbswznm);
	bool evalButDlgNewcrdActive(DbsWznm* dbswznm);
	bool evalLstPnlAvail(DbsWznm* dbswznm);
	bool evalButPnlViewActive(DbsWznm* dbswznm);
	bool evalButPnlNewcrdActive(DbsWznm* dbswznm);
	bool evalLstQryAvail(DbsWznm* dbswznm);
	bool evalButQryViewActive(DbsWznm* dbswznm);
	bool evalButQryNewcrdActive(DbsWznm* dbswznm);
	bool evalLstQcoAvail(DbsWznm* dbswznm);
	bool evalButQcoViewActive(DbsWznm* dbswznm);
	bool evalButQcoNewcrdActive(DbsWznm* dbswznm);
	bool evalLstQmdAvail(DbsWznm* dbswznm);
	bool evalButQmdViewActive(DbsWznm* dbswznm);
	bool evalButQmdNewcrdActive(DbsWznm* dbswznm);
	bool evalLstConAvail(DbsWznm* dbswznm);
	bool evalButConViewActive(DbsWznm* dbswznm);
	bool evalButConNewcrdActive(DbsWznm* dbswznm);

public:
	PnlWznmNavUix(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavUix();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstCar;
	Sbecore::Xmlio::Feed feedFLstCon;
	Sbecore::Xmlio::Feed feedFLstDlg;
	Sbecore::Xmlio::Feed feedFLstMdl;
	Sbecore::Xmlio::Feed feedFLstPnl;
	Sbecore::Xmlio::Feed feedFLstPst;
	Sbecore::Xmlio::Feed feedFLstQco;
	Sbecore::Xmlio::Feed feedFLstQmd;
	Sbecore::Xmlio::Feed feedFLstQry;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstPst(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPst(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstMdl(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshMdl(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstCar(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCar(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstDlg(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshDlg(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstPnl(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPnl(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstQry(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshQry(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstQco(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshQco(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstQmd(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshQmd(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstCon(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCon(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButPstViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPstNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMdlViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMdlNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCarViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCarNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDlgViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDlgNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPnlViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPnlNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButQryViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButQryNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButQcoViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButQcoNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButQmdViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButQmdNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButConViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButConNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
