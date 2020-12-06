/**
	* \file PnlWznmNavDeploy.h
	* job handler for job PnlWznmNavDeploy (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVDEPLOY_H
#define PNLWZNMNAVDEPLOY_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavDeployDo PnlWznmNavDeploy::VecVDo

#define ContIacWznmNavDeploy PnlWznmNavDeploy::ContIac
#define StatAppWznmNavDeploy PnlWznmNavDeploy::StatApp
#define StatShrWznmNavDeploy PnlWznmNavDeploy::StatShr
#define TagWznmNavDeploy PnlWznmNavDeploy::Tag

#define DpchAppWznmNavDeployData PnlWznmNavDeploy::DpchAppData
#define DpchAppWznmNavDeployDo PnlWznmNavDeploy::DpchAppDo
#define DpchEngWznmNavDeployData PnlWznmNavDeploy::DpchEngData

/**
	* PnlWznmNavDeploy
	*/
class PnlWznmNavDeploy : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavDeployDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCMPVIEWCLICK = 1;
		static const Sbecore::uint BUTCMPNEWCRDCLICK = 2;
		static const Sbecore::uint BUTRLSVIEWCLICK = 3;
		static const Sbecore::uint BUTRLSNEWCRDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavDeploy)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTCMP = 1;
		static const Sbecore::uint NUMFLSTRLS = 2;

	public:
		ContIac(const Sbecore::uint numFLstCmp = 1, const Sbecore::uint numFLstRls = 1);

	public:
		Sbecore::uint numFLstCmp;
		Sbecore::uint numFLstRls;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWznmNavDeploy)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstCmpAlt = true, const bool LstRlsAlt = true, const Sbecore::uint LstCmpNumFirstdisp = 1, const Sbecore::uint LstRlsNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmNavDeploy)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTCMPAVAIL = 1;
		static const Sbecore::uint BUTCMPVIEWACTIVE = 2;
		static const Sbecore::uint LSTRLSAVAIL = 3;
		static const Sbecore::uint BUTRLSVIEWACTIVE = 4;
		static const Sbecore::uint BUTRLSNEWCRDACTIVE = 5;

	public:
		StatShr(const bool LstCmpAvail = true, const bool ButCmpViewActive = true, const bool LstRlsAvail = true, const bool ButRlsViewActive = true, const bool ButRlsNewcrdActive = true);

	public:
		bool LstCmpAvail;
		bool ButCmpViewActive;
		bool LstRlsAvail;
		bool ButRlsViewActive;
		bool ButRlsNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavDeploy)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavDeployData)
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
		* DpchAppDo (full: DpchAppWznmNavDeployDo)
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
		* DpchEngData (full: DpchEngWznmNavDeployData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCMP = 3;
		static const Sbecore::uint FEEDFLSTRLS = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstCmp = NULL, Sbecore::Xmlio::Feed* feedFLstRls = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCmp;
		Sbecore::Xmlio::Feed feedFLstRls;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstCmpAvail(DbsWznm* dbswznm);
	bool evalButCmpViewActive(DbsWznm* dbswznm);
	bool evalLstRlsAvail(DbsWznm* dbswznm);
	bool evalButRlsViewActive(DbsWznm* dbswznm);
	bool evalButRlsNewcrdActive(DbsWznm* dbswznm);

public:
	PnlWznmNavDeploy(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavDeploy();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstCmp;
	Sbecore::Xmlio::Feed feedFLstRls;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstCmp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCmp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstRls(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRls(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButCmpViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCmpNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRlsViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRlsNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
