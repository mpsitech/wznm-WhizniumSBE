/**
	* \file DlgWznmRlsFinreptr.h
	* job handler for job DlgWznmRlsFinreptr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMRLSFINREPTR_H
#define DLGWZNMRLSFINREPTR_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include "git2.h"
// IP include.cust --- IEND

#define VecVDlgWznmRlsFinreptrDit DlgWznmRlsFinreptr::VecVDit
#define VecVDlgWznmRlsFinreptrDo DlgWznmRlsFinreptr::VecVDo
#define VecVDlgWznmRlsFinreptrDoFin DlgWznmRlsFinreptr::VecVDoFin
#define VecVDlgWznmRlsFinreptrDoRes DlgWznmRlsFinreptr::VecVDoRes
#define VecVDlgWznmRlsFinreptrSge DlgWznmRlsFinreptr::VecVSge

#define ContIacDlgWznmRlsFinreptr DlgWznmRlsFinreptr::ContIac
#define ContInfDlgWznmRlsFinreptr DlgWznmRlsFinreptr::ContInf
#define ContInfDlgWznmRlsFinreptrFin DlgWznmRlsFinreptr::ContInfFin
#define ContInfDlgWznmRlsFinreptrRes DlgWznmRlsFinreptr::ContInfRes
#define StatAppDlgWznmRlsFinreptr DlgWznmRlsFinreptr::StatApp
#define StatShrDlgWznmRlsFinreptr DlgWznmRlsFinreptr::StatShr
#define StatShrDlgWznmRlsFinreptrFin DlgWznmRlsFinreptr::StatShrFin
#define StatShrDlgWznmRlsFinreptrRes DlgWznmRlsFinreptr::StatShrRes
#define TagDlgWznmRlsFinreptr DlgWznmRlsFinreptr::Tag
#define TagDlgWznmRlsFinreptrFin DlgWznmRlsFinreptr::TagFin
#define TagDlgWznmRlsFinreptrRes DlgWznmRlsFinreptr::TagRes

#define DpchAppDlgWznmRlsFinreptrData DlgWznmRlsFinreptr::DpchAppData
#define DpchAppDlgWznmRlsFinreptrDo DlgWznmRlsFinreptr::DpchAppDo
#define DpchEngDlgWznmRlsFinreptrData DlgWznmRlsFinreptr::DpchEngData

/**
	* DlgWznmRlsFinreptr
	*/
class DlgWznmRlsFinreptr : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmRlsFinreptrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint FIN = 1;
		static const Sbecore::uint RES = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmRlsFinreptrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoFin (full: VecVDlgWznmRlsFinreptrDoFin)
		*/
	class VecVDoFin {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoRes (full: VecVDlgWznmRlsFinreptrDoRes)
		*/
	class VecVDoRes {

	public:
		static const Sbecore::uint BUTPSGCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmRlsFinreptrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRGNF = 2;
		static const Sbecore::uint ALRGAD = 3;
		static const Sbecore::uint FINIDLE = 4;
		static const Sbecore::uint PACK = 5;
		static const Sbecore::uint COMMIT = 6;
		static const Sbecore::uint FINDONE = 7;
		static const Sbecore::uint PSGIDLE = 8;
		static const Sbecore::uint PUSHGIT = 9;
		static const Sbecore::uint DONE = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmRlsFinreptr)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmRlsFinreptr)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfFin (full: ContInfDlgWznmRlsFinreptrFin)
	  */
	class ContInfFin : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfFin(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfFin* comp);
		std::set<Sbecore::uint> diff(const ContInfFin* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWznmRlsFinreptrRes)
	  */
	class ContInfRes : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;
		static const Sbecore::uint TXTPRG = 2;

	public:
		ContInfRes(const std::string& Dld = "file", const std::string& TxtPrg = "");

	public:
		std::string Dld;
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfRes* comp);
		std::set<Sbecore::uint> diff(const ContInfRes* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmRlsFinreptr)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmRlsFinreptr)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StatShrFin (full: StatShrDlgWznmRlsFinreptrFin)
		*/
	class StatShrFin : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrFin(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFin* comp);
		std::set<Sbecore::uint> diff(const StatShrFin* comp);
	};

	/**
		* StatShrRes (full: StatShrDlgWznmRlsFinreptrRes)
		*/
	class StatShrRes : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDAVAIL = 1;
		static const Sbecore::uint DLDACTIVE = 2;
		static const Sbecore::uint TXTPRGAVAIL = 3;
		static const Sbecore::uint SEP1AVAIL = 4;
		static const Sbecore::uint BUTPSGAVAIL = 5;
		static const Sbecore::uint BUTPSGACTIVE = 6;

	public:
		StatShrRes(const bool DldAvail = true, const bool DldActive = true, const bool TxtPrgAvail = true, const bool Sep1Avail = true, const bool ButPsgAvail = true, const bool ButPsgActive = true);

	public:
		bool DldAvail;
		bool DldActive;
		bool TxtPrgAvail;
		bool Sep1Avail;
		bool ButPsgAvail;
		bool ButPsgActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrRes* comp);
		std::set<Sbecore::uint> diff(const StatShrRes* comp);
	};

	/**
		* Tag (full: TagDlgWznmRlsFinreptr)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFin (full: TagDlgWznmRlsFinreptrFin)
		*/
	class TagFin {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagRes (full: TagDlgWznmRlsFinreptrRes)
		*/
	class TagRes {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmRlsFinreptrData)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmRlsFinreptrDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOFIN = 3;
		static const Sbecore::uint IXVDORES = 4;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoFin;
		Sbecore::uint ixVDoRes;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmRlsFinreptrData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFFIN = 4;
		static const Sbecore::uint CONTINFRES = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRFIN = 10;
		static const Sbecore::uint STATSHRRES = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint TAGFIN = 13;
		static const Sbecore::uint TAGRES = 14;
		static const Sbecore::uint ALL = 15;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfFin* continffin = NULL, ContInfRes* continfres = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrFin* statshrfin = NULL, StatShrRes* statshrres = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfFin continffin;
		ContInfRes continfres;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrFin statshrfin;
		StatShrRes statshrres;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalResDldAvail(DbsWznm* dbswznm);
	bool evalResDldActive(DbsWznm* dbswznm);
	bool evalResTxtPrgAvail(DbsWznm* dbswznm);
	bool evalResSep1Avail(DbsWznm* dbswznm);
	bool evalResButPsgAvail(DbsWznm* dbswznm);
	bool evalResButPsgActive(DbsWznm* dbswznm);
	bool evalFinButRunActive(DbsWznm* dbswznm);
	bool evalFinButStoActive(DbsWznm* dbswznm);

public:
	DlgWznmRlsFinreptr(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmRlsFinreptr();

public:
	ContIac contiac;
	ContInf continf;
	ContInfFin continffin;
	ContInfRes continfres;
	StatShr statshr;
	StatShrFin statshrfin;
	StatShrRes statshrres;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string usrsref;

	std::string vertag;

	Sbecore::Mutex mGitprg;
	std::string gitprg;

	std::string tgzfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	static int gitCredCallback(git_cred** cred, const char* url, const char* username_from_url, unsigned int allowed_types, void* payload);

	static int gitIndexUpdateCallback(const char* path, const char* matched_pathspec, void* payload);
	static int gitIndexAddCallback(const char* path, const char* matched_pathspec, void* payload);

	static int gitPackCallback(int stage, unsigned int current, unsigned int total, void* payload);
	static int gitPushCallback(unsigned int current, unsigned int total, size_t bytes, void *payload);
	// IP cust --- IEND

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshFin(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRes(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoFinButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoFinButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoResButPsgClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);

	void handleTimerInSgeFinidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerInSgePsgidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerWithSrefMonInSgePushgit(DbsWznm* dbswznm);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrgnf(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrgnf(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrgad(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrgad(DbsWznm* dbswznm);
	Sbecore::uint enterSgeFinidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeFinidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgePack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCommit(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCommit(DbsWznm* dbswznm);
	Sbecore::uint enterSgeFindone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeFindone(DbsWznm* dbswznm);
	Sbecore::uint enterSgePsgidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePsgidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgePushgit(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePushgit(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
