/**
	* \file DlgWznmVerFinmod.h
	* job handler for job DlgWznmVerFinmod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVERFINMOD_H
#define DLGWZNMVERFINMOD_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWznmLicense.h"

#define VecVDlgWznmVerFinmodDo DlgWznmVerFinmod::VecVDo
#define VecVDlgWznmVerFinmodSge DlgWznmVerFinmod::VecVSge

#define ContInfDlgWznmVerFinmod DlgWznmVerFinmod::ContInf
#define StatAppDlgWznmVerFinmod DlgWznmVerFinmod::StatApp
#define StatShrDlgWznmVerFinmod DlgWznmVerFinmod::StatShr
#define TagDlgWznmVerFinmod DlgWznmVerFinmod::Tag

#define DpchAppDlgWznmVerFinmodDo DlgWznmVerFinmod::DpchAppDo
#define DpchEngDlgWznmVerFinmodData DlgWznmVerFinmod::DpchEngData

/**
	* DlgWznmVerFinmod
	*/
class DlgWznmVerFinmod : public JobWznm {

public:
	/**
		* VecVDo (full: VecVDlgWznmVerFinmodDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint FNMBUTRUNCLICK = 1;
		static const Sbecore::uint FNMBUTSTOCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVerFinmodSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint FINMOD = 2;
		static const Sbecore::uint SYNC = 3;
		static const Sbecore::uint DONE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfDlgWznmVerFinmod)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint FNMTXTPRG = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& FnmTxtPrg = "");

	public:
		Sbecore::uint numFSge;
		std::string FnmTxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmVerFinmod)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmVerFinmod)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint FNMBUTRUNACTIVE = 1;
		static const Sbecore::uint FNMBUTSTOACTIVE = 2;
		static const Sbecore::uint BUTDNEACTIVE = 3;

	public:
		StatShr(const bool FnmButRunActive = true, const bool FnmButStoActive = true, const bool ButDneActive = true);

	public:
		bool FnmButRunActive;
		bool FnmButStoActive;
		bool ButDneActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWznmVerFinmod)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVerFinmodDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVerFinmodData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalFnmButRunActive(DbsWznm* dbswznm);
	bool evalFnmButStoActive(DbsWznm* dbswznm);
	bool evalButDneActive(DbsWznm* dbswznm);

public:
	DlgWznmVerFinmod(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmVerFinmod();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFSge;

	JobWznmLicense* license;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

	void handleDpchAppDoFnmButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoFnmButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchRetWznm(DbsWznm* dbswznm, DpchRetWznm* dpchret);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeFinmod(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeFinmod(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSync(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSync(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
