/**
	* \file PnlWznmNavComp.h
	* job handler for job PnlWznmNavComp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMNAVCOMP_H
#define PNLWZNMNAVCOMP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavCompDo PnlWznmNavComp::VecVDo

#define ContIacWznmNavComp PnlWznmNavComp::ContIac
#define StatAppWznmNavComp PnlWznmNavComp::StatApp
#define StatShrWznmNavComp PnlWznmNavComp::StatShr
#define TagWznmNavComp PnlWznmNavComp::Tag

#define DpchAppWznmNavCompData PnlWznmNavComp::DpchAppData
#define DpchAppWznmNavCompDo PnlWznmNavComp::DpchAppDo
#define DpchEngWznmNavCompData PnlWznmNavComp::DpchEngData

/**
	* PnlWznmNavComp
	*/
class PnlWznmNavComp : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavCompDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTOPKVIEWCLICK = 1;
		static const Sbecore::uint BUTOPKNEWCRDCLICK = 2;
		static const Sbecore::uint BUTOPXVIEWCLICK = 3;
		static const Sbecore::uint BUTOPXNEWCRDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavComp)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTOPK = 1;
		static const Sbecore::uint NUMFLSTOPX = 2;

	public:
		ContIac(const Sbecore::uint numFLstOpk = 1, const Sbecore::uint numFLstOpx = 1);

	public:
		Sbecore::uint numFLstOpk;
		Sbecore::uint numFLstOpx;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWznmNavComp)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOpkAlt = true, const bool LstOpxAlt = true, const Sbecore::uint LstOpkNumFirstdisp = 1, const Sbecore::uint LstOpxNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmNavComp)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTOPKAVAIL = 1;
		static const Sbecore::uint BUTOPKVIEWACTIVE = 2;
		static const Sbecore::uint BUTOPKNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTOPXAVAIL = 4;
		static const Sbecore::uint BUTOPXVIEWACTIVE = 5;
		static const Sbecore::uint BUTOPXNEWCRDACTIVE = 6;

	public:
		StatShr(const bool LstOpkAvail = true, const bool ButOpkViewActive = true, const bool ButOpkNewcrdActive = true, const bool LstOpxAvail = true, const bool ButOpxViewActive = true, const bool ButOpxNewcrdActive = true);

	public:
		bool LstOpkAvail;
		bool ButOpkViewActive;
		bool ButOpkNewcrdActive;
		bool LstOpxAvail;
		bool ButOpxViewActive;
		bool ButOpxNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavComp)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavCompData)
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
		* DpchAppDo (full: DpchAppWznmNavCompDo)
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
		* DpchEngData (full: DpchEngWznmNavCompData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTOPK = 3;
		static const Sbecore::uint FEEDFLSTOPX = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstOpk = NULL, Sbecore::Xmlio::Feed* feedFLstOpx = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstOpk;
		Sbecore::Xmlio::Feed feedFLstOpx;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstOpkAvail(DbsWznm* dbswznm);
	bool evalButOpkViewActive(DbsWznm* dbswznm);
	bool evalButOpkNewcrdActive(DbsWznm* dbswznm);
	bool evalLstOpxAvail(DbsWznm* dbswznm);
	bool evalButOpxViewActive(DbsWznm* dbswznm);
	bool evalButOpxNewcrdActive(DbsWznm* dbswznm);

public:
	PnlWznmNavComp(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavComp();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstOpk;
	Sbecore::Xmlio::Feed feedFLstOpx;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstOpk(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshOpk(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstOpx(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshOpx(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButOpkViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButOpkNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButOpxViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButOpxNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif

