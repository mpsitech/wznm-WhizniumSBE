/**
	* \file DlgWznmUsrMngkeypair.h
	* job handler for job DlgWznmUsrMngkeypair (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMUSRMNGKEYPAIR_H
#define DLGWZNMUSRMNGKEYPAIR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWznmUsrMngkeypairDo DlgWznmUsrMngkeypair::VecVDo
#define VecVDlgWznmUsrMngkeypairSge DlgWznmUsrMngkeypair::VecVSge

#define ContInfDlgWznmUsrMngkeypair DlgWznmUsrMngkeypair::ContInf
#define StatAppDlgWznmUsrMngkeypair DlgWznmUsrMngkeypair::StatApp
#define StatShrDlgWznmUsrMngkeypair DlgWznmUsrMngkeypair::StatShr
#define TagDlgWznmUsrMngkeypair DlgWznmUsrMngkeypair::Tag

#define DpchAppDlgWznmUsrMngkeypairDo DlgWznmUsrMngkeypair::DpchAppDo
#define DpchEngDlgWznmUsrMngkeypairData DlgWznmUsrMngkeypair::DpchEngData

/**
	* DlgWznmUsrMngkeypair
	*/
class DlgWznmUsrMngkeypair : public JobWznm {

public:
	/**
		* VecVDo (full: VecVDlgWznmUsrMngkeypairDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTDELCLICK = 1;
		static const Sbecore::uint DETBUTGENCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmUsrMngkeypairSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint NF = 1;
		static const Sbecore::uint FOUND = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfDlgWznmUsrMngkeypair)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint DETTXTSTE = 2;
		static const Sbecore::uint DETDLD = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& DetTxtSte = "", const std::string& DetDld = "file");

	public:
		Sbecore::uint numFSge;
		std::string DetTxtSte;
		std::string DetDld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmUsrMngkeypair)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmUsrMngkeypair)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint DETBUTDELAVAIL = 1;
		static const Sbecore::uint DETBUTGENAVAIL = 2;
		static const Sbecore::uint DETDLDACTIVE = 3;

	public:
		StatShr(const bool DetButDelAvail = true, const bool DetButGenAvail = true, const bool DetDldActive = true);

	public:
		bool DetButDelAvail;
		bool DetButGenAvail;
		bool DetDldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWznmUsrMngkeypair)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmUsrMngkeypairDo)
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
		* DpchEngData (full: DpchEngDlgWznmUsrMngkeypairData)
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

	bool evalDetButDelAvail(DbsWznm* dbswznm);
	bool evalDetButGenAvail(DbsWznm* dbswznm);
	bool evalDetDldActive(DbsWznm* dbswznm);

public:
	DlgWznmUsrMngkeypair(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmUsrMngkeypair();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFSge;

	// IP vars.cust --- IBEGIN
	std::string usrsref;
	// IP vars.cust --- IEND

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

	void handleDpchAppDoDetButDelClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoDetButGenClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	std::string handleDownloadInSgeFound(DbsWznm* dbswznm);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeNf(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeNf(DbsWznm* dbswznm);
	Sbecore::uint enterSgeFound(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeFound(DbsWznm* dbswznm);

};

#endif
