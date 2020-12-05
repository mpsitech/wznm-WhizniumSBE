/**
	* \file PnlWznmNavProject.h
	* job handler for job PnlWznmNavProject (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVPROJECT_H
#define PNLWZNMNAVPROJECT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavProjectDo PnlWznmNavProject::VecVDo

#define ContIacWznmNavProject PnlWznmNavProject::ContIac
#define StatAppWznmNavProject PnlWznmNavProject::StatApp
#define StatShrWznmNavProject PnlWznmNavProject::StatShr
#define TagWznmNavProject PnlWznmNavProject::Tag

#define DpchAppWznmNavProjectData PnlWznmNavProject::DpchAppData
#define DpchAppWznmNavProjectDo PnlWznmNavProject::DpchAppDo
#define DpchEngWznmNavProjectData PnlWznmNavProject::DpchEngData

/**
	* PnlWznmNavProject
	*/
class PnlWznmNavProject : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavProjectDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPRJVIEWCLICK = 1;
		static const Sbecore::uint BUTPRJNEWCRDCLICK = 2;
		static const Sbecore::uint BUTVERVIEWCLICK = 3;
		static const Sbecore::uint BUTVERNEWCRDCLICK = 4;
		static const Sbecore::uint BUTCAPVIEWCLICK = 5;
		static const Sbecore::uint BUTCAPNEWCRDCLICK = 6;
		static const Sbecore::uint BUTERRVIEWCLICK = 7;
		static const Sbecore::uint BUTERRNEWCRDCLICK = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavProject)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTPRJ = 1;
		static const Sbecore::uint NUMFLSTVER = 2;
		static const Sbecore::uint NUMFLSTCAP = 3;
		static const Sbecore::uint NUMFLSTERR = 4;

	public:
		ContIac(const Sbecore::uint numFLstPrj = 1, const Sbecore::uint numFLstVer = 1, const Sbecore::uint numFLstCap = 1, const Sbecore::uint numFLstErr = 1);

	public:
		Sbecore::uint numFLstPrj;
		Sbecore::uint numFLstVer;
		Sbecore::uint numFLstCap;
		Sbecore::uint numFLstErr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWznmNavProject)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstPrjAlt = true, const bool LstVerAlt = true, const bool LstCapAlt = true, const bool LstErrAlt = true, const Sbecore::uint LstPrjNumFirstdisp = 1, const Sbecore::uint LstVerNumFirstdisp = 1, const Sbecore::uint LstCapNumFirstdisp = 1, const Sbecore::uint LstErrNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmNavProject)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTPRJAVAIL = 1;
		static const Sbecore::uint BUTPRJVIEWACTIVE = 2;
		static const Sbecore::uint LSTVERAVAIL = 3;
		static const Sbecore::uint BUTVERVIEWACTIVE = 4;
		static const Sbecore::uint LSTCAPAVAIL = 5;
		static const Sbecore::uint BUTCAPVIEWACTIVE = 6;
		static const Sbecore::uint BUTCAPNEWCRDACTIVE = 7;
		static const Sbecore::uint LSTERRAVAIL = 8;
		static const Sbecore::uint BUTERRVIEWACTIVE = 9;
		static const Sbecore::uint BUTERRNEWCRDACTIVE = 10;

	public:
		StatShr(const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstVerAvail = true, const bool ButVerViewActive = true, const bool LstCapAvail = true, const bool ButCapViewActive = true, const bool ButCapNewcrdActive = true, const bool LstErrAvail = true, const bool ButErrViewActive = true, const bool ButErrNewcrdActive = true);

	public:
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstVerAvail;
		bool ButVerViewActive;
		bool LstCapAvail;
		bool ButCapViewActive;
		bool ButCapNewcrdActive;
		bool LstErrAvail;
		bool ButErrViewActive;
		bool ButErrNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavProject)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavProjectData)
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
		* DpchAppDo (full: DpchAppWznmNavProjectDo)
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
		* DpchEngData (full: DpchEngWznmNavProjectData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCAP = 3;
		static const Sbecore::uint FEEDFLSTERR = 4;
		static const Sbecore::uint FEEDFLSTPRJ = 5;
		static const Sbecore::uint FEEDFLSTVER = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstCap = NULL, Sbecore::Xmlio::Feed* feedFLstErr = NULL, Sbecore::Xmlio::Feed* feedFLstPrj = NULL, Sbecore::Xmlio::Feed* feedFLstVer = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCap;
		Sbecore::Xmlio::Feed feedFLstErr;
		Sbecore::Xmlio::Feed feedFLstPrj;
		Sbecore::Xmlio::Feed feedFLstVer;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstPrjAvail(DbsWznm* dbswznm);
	bool evalButPrjViewActive(DbsWznm* dbswznm);
	bool evalLstVerAvail(DbsWznm* dbswznm);
	bool evalButVerViewActive(DbsWznm* dbswznm);
	bool evalLstCapAvail(DbsWznm* dbswznm);
	bool evalButCapViewActive(DbsWznm* dbswznm);
	bool evalButCapNewcrdActive(DbsWznm* dbswznm);
	bool evalLstErrAvail(DbsWznm* dbswznm);
	bool evalButErrViewActive(DbsWznm* dbswznm);
	bool evalButErrNewcrdActive(DbsWznm* dbswznm);

public:
	PnlWznmNavProject(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavProject();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstCap;
	Sbecore::Xmlio::Feed feedFLstErr;
	Sbecore::Xmlio::Feed feedFLstPrj;
	Sbecore::Xmlio::Feed feedFLstVer;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstPrj(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPrj(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstVer(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshVer(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstCap(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCap(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstErr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshErr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButPrjViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButPrjNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVerViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVerNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCapViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCapNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButErrViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButErrNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif



