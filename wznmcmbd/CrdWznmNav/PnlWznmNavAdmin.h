/**
	* \file PnlWznmNavAdmin.h
	* job handler for job PnlWznmNavAdmin (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVADMIN_H
#define PNLWZNMNAVADMIN_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavAdminDo PnlWznmNavAdmin::VecVDo

#define ContIacWznmNavAdmin PnlWznmNavAdmin::ContIac
#define StatAppWznmNavAdmin PnlWznmNavAdmin::StatApp
#define StatShrWznmNavAdmin PnlWznmNavAdmin::StatShr
#define TagWznmNavAdmin PnlWznmNavAdmin::Tag

#define DpchAppWznmNavAdminData PnlWznmNavAdmin::DpchAppData
#define DpchAppWznmNavAdminDo PnlWznmNavAdmin::DpchAppDo
#define DpchEngWznmNavAdminData PnlWznmNavAdmin::DpchEngData

/**
	* PnlWznmNavAdmin
	*/
class PnlWznmNavAdmin : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavAdminDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUSGVIEWCLICK = 1;
		static const Sbecore::uint BUTUSGNEWCRDCLICK = 2;
		static const Sbecore::uint BUTUSRVIEWCLICK = 3;
		static const Sbecore::uint BUTUSRNEWCRDCLICK = 4;
		static const Sbecore::uint BUTPRSVIEWCLICK = 5;
		static const Sbecore::uint BUTPRSNEWCRDCLICK = 6;
		static const Sbecore::uint BUTFILVIEWCLICK = 7;
		static const Sbecore::uint BUTFILNEWCRDCLICK = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavAdmin)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTUSG = 1;
		static const Sbecore::uint NUMFLSTUSR = 2;
		static const Sbecore::uint NUMFLSTPRS = 3;
		static const Sbecore::uint NUMFLSTFIL = 4;

	public:
		ContIac(const Sbecore::uint numFLstUsg = 1, const Sbecore::uint numFLstUsr = 1, const Sbecore::uint numFLstPrs = 1, const Sbecore::uint numFLstFil = 1);

	public:
		Sbecore::uint numFLstUsg;
		Sbecore::uint numFLstUsr;
		Sbecore::uint numFLstPrs;
		Sbecore::uint numFLstFil;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWznmNavAdmin)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const bool LstFilAlt = true, const Sbecore::uint LstUsgNumFirstdisp = 1, const Sbecore::uint LstUsrNumFirstdisp = 1, const Sbecore::uint LstPrsNumFirstdisp = 1, const Sbecore::uint LstFilNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const bool LstFilAlt = true, const Sbecore::uint LstUsgNumFirstdisp = 1, const Sbecore::uint LstUsrNumFirstdisp = 1, const Sbecore::uint LstPrsNumFirstdisp = 1, const Sbecore::uint LstFilNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmNavAdmin)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTUSGAVAIL = 1;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 2;
		static const Sbecore::uint LSTUSRAVAIL = 3;
		static const Sbecore::uint BUTUSRVIEWACTIVE = 4;
		static const Sbecore::uint LSTPRSAVAIL = 5;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 6;
		static const Sbecore::uint LSTFILAVAIL = 7;
		static const Sbecore::uint BUTFILVIEWACTIVE = 8;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavAdmin)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavAdminData)
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
		* DpchAppDo (full: DpchAppWznmNavAdminDo)
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
		* DpchEngData (full: DpchEngWznmNavAdminData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFIL = 3;
		static const Sbecore::uint FEEDFLSTPRS = 4;
		static const Sbecore::uint FEEDFLSTUSG = 5;
		static const Sbecore::uint FEEDFLSTUSR = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstFil = NULL, Sbecore::Feed* feedFLstPrs = NULL, Sbecore::Feed* feedFLstUsg = NULL, Sbecore::Feed* feedFLstUsr = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstFil;
		Sbecore::Feed feedFLstPrs;
		Sbecore::Feed feedFLstUsg;
		Sbecore::Feed feedFLstUsr;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstUsgAvail(DbsWznm* dbswznm);
	bool evalButUsgViewActive(DbsWznm* dbswznm);
	bool evalLstUsrAvail(DbsWznm* dbswznm);
	bool evalButUsrViewActive(DbsWznm* dbswznm);
	bool evalLstPrsAvail(DbsWznm* dbswznm);
	bool evalButPrsViewActive(DbsWznm* dbswznm);
	bool evalLstFilAvail(DbsWznm* dbswznm);
	bool evalButFilViewActive(DbsWznm* dbswznm);

public:
	PnlWznmNavAdmin(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavAdmin();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstFil;
	Sbecore::Feed feedFLstPrs;
	Sbecore::Feed feedFLstUsg;
	Sbecore::Feed feedFLstUsr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstUsg(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshUsg(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstUsr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshUsr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstPrs(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPrs(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstFil(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshFil(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButUsgViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButUsgNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButUsrViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButUsrNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPrsNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButFilNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
