/**
	* \file DlgWznmVerBscui.h
	* job handler for job DlgWznmVerBscui (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVERBSCUI_H
#define DLGWZNMVERBSCUI_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWznmIexBui.h"

#define VecVDlgWznmVerBscuiDit DlgWznmVerBscui::VecVDit
#define VecVDlgWznmVerBscuiDo DlgWznmVerBscui::VecVDo
#define VecVDlgWznmVerBscuiDoImp DlgWznmVerBscui::VecVDoImp
#define VecVDlgWznmVerBscuiDoPpr DlgWznmVerBscui::VecVDoPpr
#define VecVDlgWznmVerBscuiSge DlgWznmVerBscui::VecVSge

#define ContIacDlgWznmVerBscui DlgWznmVerBscui::ContIac
#define ContInfDlgWznmVerBscui DlgWznmVerBscui::ContInf
#define ContInfDlgWznmVerBscuiImp DlgWznmVerBscui::ContInfImp
#define ContInfDlgWznmVerBscuiLfi DlgWznmVerBscui::ContInfLfi
#define ContInfDlgWznmVerBscuiPpr DlgWznmVerBscui::ContInfPpr
#define StatAppDlgWznmVerBscui DlgWznmVerBscui::StatApp
#define StatShrDlgWznmVerBscui DlgWznmVerBscui::StatShr
#define StatShrDlgWznmVerBscuiIfi DlgWznmVerBscui::StatShrIfi
#define StatShrDlgWznmVerBscuiImp DlgWznmVerBscui::StatShrImp
#define StatShrDlgWznmVerBscuiLfi DlgWznmVerBscui::StatShrLfi
#define StatShrDlgWznmVerBscuiPpr DlgWznmVerBscui::StatShrPpr
#define TagDlgWznmVerBscui DlgWznmVerBscui::Tag
#define TagDlgWznmVerBscuiIfi DlgWznmVerBscui::TagIfi
#define TagDlgWznmVerBscuiImp DlgWznmVerBscui::TagImp
#define TagDlgWznmVerBscuiLfi DlgWznmVerBscui::TagLfi
#define TagDlgWznmVerBscuiPpr DlgWznmVerBscui::TagPpr

#define DpchAppDlgWznmVerBscuiData DlgWznmVerBscui::DpchAppData
#define DpchAppDlgWznmVerBscuiDo DlgWznmVerBscui::DpchAppDo
#define DpchEngDlgWznmVerBscuiData DlgWznmVerBscui::DpchEngData

/**
	* DlgWznmVerBscui
	*/
class DlgWznmVerBscui : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmVerBscuiDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint IFI = 1;
		static const Sbecore::uint IMP = 2;
		static const Sbecore::uint PPR = 3;
		static const Sbecore::uint LFI = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmVerBscuiDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgWznmVerBscuiDoImp)
		*/
	class VecVDoImp {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoPpr (full: VecVDlgWznmVerBscuiDoPpr)
		*/
	class VecVDoPpr {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVerBscuiSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PRSIDLE = 2;
		static const Sbecore::uint PARSE = 3;
		static const Sbecore::uint ALRWZNMPER = 4;
		static const Sbecore::uint PRSDONE = 5;
		static const Sbecore::uint IMPIDLE = 6;
		static const Sbecore::uint IMPORT = 7;
		static const Sbecore::uint ALRWZNMIER = 8;
		static const Sbecore::uint IMPDONE = 9;
		static const Sbecore::uint POSTPRC = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVerBscui)
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
	  * ContInf (full: ContInfDlgWznmVerBscui)
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
	  * ContInfImp (full: ContInfDlgWznmVerBscuiImp)
	  */
	class ContInfImp : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfImp(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfImp* comp);
		std::set<Sbecore::uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmVerBscuiLfi)
	  */
	class ContInfLfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfLfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfLfi* comp);
		std::set<Sbecore::uint> diff(const ContInfLfi* comp);
	};

	/**
	  * ContInfPpr (full: ContInfDlgWznmVerBscuiPpr)
	  */
	class ContInfPpr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfPpr(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfPpr* comp);
		std::set<Sbecore::uint> diff(const ContInfPpr* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmVerBscui)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmVerBscui)
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
		* StatShrIfi (full: StatShrDlgWznmVerBscuiIfi)
		*/
	class StatShrIfi : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrIfi* comp);
		std::set<Sbecore::uint> diff(const StatShrIfi* comp);
	};

	/**
		* StatShrImp (full: StatShrDlgWznmVerBscuiImp)
		*/
	class StatShrImp : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrImp* comp);
		std::set<Sbecore::uint> diff(const StatShrImp* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWznmVerBscuiLfi)
		*/
	class StatShrLfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrLfi* comp);
		std::set<Sbecore::uint> diff(const StatShrLfi* comp);
	};

	/**
		* StatShrPpr (full: StatShrDlgWznmVerBscuiPpr)
		*/
	class StatShrPpr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrPpr(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrPpr* comp);
		std::set<Sbecore::uint> diff(const StatShrPpr* comp);
	};

	/**
		* Tag (full: TagDlgWznmVerBscui)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgWznmVerBscuiIfi)
		*/
	class TagIfi {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgWznmVerBscuiImp)
		*/
	class TagImp {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWznmVerBscuiLfi)
		*/
	class TagLfi {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagPpr (full: TagDlgWznmVerBscuiPpr)
		*/
	class TagPpr {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVerBscuiData)
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
		* DpchAppDo (full: DpchAppDlgWznmVerBscuiDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOIMP = 3;
		static const Sbecore::uint IXVDOPPR = 4;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoImp;
		Sbecore::uint ixVDoPpr;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVerBscuiData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFIMP = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint CONTINFPPR = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHRIFI = 11;
		static const Sbecore::uint STATSHRIMP = 12;
		static const Sbecore::uint STATSHRLFI = 13;
		static const Sbecore::uint STATSHRPPR = 14;
		static const Sbecore::uint TAG = 15;
		static const Sbecore::uint TAGIFI = 16;
		static const Sbecore::uint TAGIMP = 17;
		static const Sbecore::uint TAGLFI = 18;
		static const Sbecore::uint TAGPPR = 19;
		static const Sbecore::uint ALL = 20;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, ContInfLfi* continflfi = NULL, ContInfPpr* continfppr = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, StatShrPpr* statshrppr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		ContInfPpr continfppr;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;
		StatShrPpr statshrppr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalLfiDldActive(DbsWznm* dbswznm);
	bool evalPprButRunActive(DbsWznm* dbswznm);
	bool evalPprButStoActive(DbsWznm* dbswznm);
	bool evalImpButRunActive(DbsWznm* dbswznm);
	bool evalImpButStoActive(DbsWznm* dbswznm);
	bool evalIfiUldActive(DbsWznm* dbswznm);

public:
	DlgWznmVerBscui(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmVerBscui();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	ContInfLfi continflfi;
	ContInfPpr continfppr;
	StatShr statshr;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;
	StatShrPpr statshrppr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	JobWznmIexBui* iex;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;
	std::string rectpath;

	bool ifitxt;
	bool ifixml;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshIfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshImp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPpr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoImpButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoImpButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoPprButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoPprButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	void handleUploadInSgeIdle(DbsWznm* dbswznm, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);

	void handleDpchRetWznm(DbsWznm* dbswznm, DpchRetWznm* dpchret);

	void handleTimerInSgeImpidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerWithSrefMonInSgeImport(DbsWznm* dbswznm);
	void handleTimerInSgePrsidle(DbsWznm* dbswznm, const std::string& sref);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgePrsidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePrsidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeParse(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeParse(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrwznmper(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrwznmper(DbsWznm* dbswznm);
	Sbecore::uint enterSgePrsdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePrsdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeImpidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeImpidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeImport(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeImport(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrwznmier(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrwznmier(DbsWznm* dbswznm);
	Sbecore::uint enterSgeImpdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeImpdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgePostprc(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePostprc(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
