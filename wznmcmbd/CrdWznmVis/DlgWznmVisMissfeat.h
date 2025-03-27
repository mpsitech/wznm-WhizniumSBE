/**
	* \file DlgWznmVisMissfeat.h
	* job handler for job DlgWznmVisMissfeat (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVISMISSFEAT_H
#define DLGWZNMVISMISSFEAT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWznmVisMissfeatDo DlgWznmVisMissfeat::VecVDo
#define VecVDlgWznmVisMissfeatSge DlgWznmVisMissfeat::VecVSge

#define ContInfDlgWznmVisMissfeat DlgWznmVisMissfeat::ContInf
#define StatAppDlgWznmVisMissfeat DlgWznmVisMissfeat::StatApp
#define StatShrDlgWznmVisMissfeat DlgWznmVisMissfeat::StatShr
#define TagDlgWznmVisMissfeat DlgWznmVisMissfeat::Tag

#define DpchAppDlgWznmVisMissfeatDo DlgWznmVisMissfeat::DpchAppDo
#define DpchEngDlgWznmVisMissfeatData DlgWznmVisMissfeat::DpchEngData

/**
	* DlgWznmVisMissfeat
	*/
class DlgWznmVisMissfeat : public JobWznm {

public:
	/**
		* VecVDo (full: VecVDlgWznmVisMissfeatDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CMFBUTRUNCLICK = 1;
		static const Sbecore::uint CMFBUTSTOCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVisMissfeatSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint COMPL = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfDlgWznmVisMissfeat)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint CMFTXTPRG = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& CmfTxtPrg = "");

	public:
		Sbecore::uint numFSge;
		std::string CmfTxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmVisMissfeat)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmVisMissfeat)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint CMFBUTRUNACTIVE = 1;
		static const Sbecore::uint CMFBUTSTOACTIVE = 2;
		static const Sbecore::uint BUTDNEACTIVE = 3;

	public:
		StatShr(const bool CmfButRunActive = true, const bool CmfButStoActive = true, const bool ButDneActive = true);

	public:
		bool CmfButRunActive;
		bool CmfButStoActive;
		bool ButDneActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWznmVisMissfeat)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVisMissfeatDo)
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
		* DpchEngData (full: DpchEngDlgWznmVisMissfeatData)
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

	bool evalCmfButRunActive(DbsWznm* dbswznm);
	bool evalCmfButStoActive(DbsWznm* dbswznm);
	bool evalButDneActive(DbsWznm* dbswznm);

public:
	DlgWznmVisMissfeat(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmVisMissfeat();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFSge;

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

	void handleDpchAppDoCmfButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoCmfButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchRetWznm(DbsWznm* dbswznm, DpchRetWznm* dpchret);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCompl(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCompl(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
