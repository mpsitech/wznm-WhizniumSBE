/**
	* \file DlgWznmPrjImpex.h
	* job handler for job DlgWznmPrjImpex (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef DLGWZNMPRJIMPEX_H
#define DLGWZNMPRJIMPEX_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWznmLicense.h"
#include "JobWznmIexPrj.h"

#define VecVDlgWznmPrjImpexDit DlgWznmPrjImpex::VecVDit
#define VecVDlgWznmPrjImpexDo DlgWznmPrjImpex::VecVDo
#define VecVDlgWznmPrjImpexDoImp DlgWznmPrjImpex::VecVDoImp
#define VecVDlgWznmPrjImpexSge DlgWznmPrjImpex::VecVSge

#define ContIacDlgWznmPrjImpex DlgWznmPrjImpex::ContIac
#define ContInfDlgWznmPrjImpex DlgWznmPrjImpex::ContInf
#define ContInfDlgWznmPrjImpexImp DlgWznmPrjImpex::ContInfImp
#define ContInfDlgWznmPrjImpexLfi DlgWznmPrjImpex::ContInfLfi
#define StatAppDlgWznmPrjImpex DlgWznmPrjImpex::StatApp
#define StatShrDlgWznmPrjImpex DlgWznmPrjImpex::StatShr
#define StatShrDlgWznmPrjImpexIfi DlgWznmPrjImpex::StatShrIfi
#define StatShrDlgWznmPrjImpexImp DlgWznmPrjImpex::StatShrImp
#define StatShrDlgWznmPrjImpexLfi DlgWznmPrjImpex::StatShrLfi
#define TagDlgWznmPrjImpex DlgWznmPrjImpex::Tag
#define TagDlgWznmPrjImpexIfi DlgWznmPrjImpex::TagIfi
#define TagDlgWznmPrjImpexImp DlgWznmPrjImpex::TagImp
#define TagDlgWznmPrjImpexLfi DlgWznmPrjImpex::TagLfi

#define DpchAppDlgWznmPrjImpexData DlgWznmPrjImpex::DpchAppData
#define DpchAppDlgWznmPrjImpexDo DlgWznmPrjImpex::DpchAppDo
#define DpchEngDlgWznmPrjImpexData DlgWznmPrjImpex::DpchEngData

/**
	* DlgWznmPrjImpex
	*/
class DlgWznmPrjImpex : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmPrjImpexDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint IFI = 1;
		static const Sbecore::uint IMP = 2;
		static const Sbecore::uint LFI = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmPrjImpexDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgWznmPrjImpexDoImp)
		*/
	class VecVDoImp {

	public:
		static const Sbecore::uint BUTAUTCLICK = 1;
		static const Sbecore::uint BUTRUNCLICK = 2;
		static const Sbecore::uint BUTSTOCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmPrjImpexSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint PRSIDLE = 3;
		static const Sbecore::uint PARSE = 4;
		static const Sbecore::uint ALRWZNMPER = 5;
		static const Sbecore::uint PRSDONE = 6;
		static const Sbecore::uint AUTH = 7;
		static const Sbecore::uint AUTDONE = 8;
		static const Sbecore::uint IMPIDLE = 9;
		static const Sbecore::uint IMPORT = 10;
		static const Sbecore::uint ALRWZNMIER = 11;
		static const Sbecore::uint SYNC = 12;
		static const Sbecore::uint DONE = 13;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmPrjImpex)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmPrjImpex)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfImp (full: ContInfDlgWznmPrjImpexImp)
	  */
	class ContInfImp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfImp(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfImp* comp);
		std::set<Sbecore::uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmPrjImpexLfi)
	  */
	class ContInfLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfLfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfLfi* comp);
		std::set<Sbecore::uint> diff(const ContInfLfi* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmPrjImpex)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmPrjImpex)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StatShrIfi (full: StatShrDlgWznmPrjImpexIfi)
		*/
	class StatShrIfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrIfi* comp);
		std::set<Sbecore::uint> diff(const StatShrIfi* comp);
	};

	/**
		* StatShrImp (full: StatShrDlgWznmPrjImpexImp)
		*/
	class StatShrImp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTAUTACTIVE = 1;
		static const Sbecore::uint BUTRUNACTIVE = 2;
		static const Sbecore::uint BUTSTOACTIVE = 3;

	public:
		StatShrImp(const bool ButAutActive = true, const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButAutActive;
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrImp* comp);
		std::set<Sbecore::uint> diff(const StatShrImp* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWznmPrjImpexLfi)
		*/
	class StatShrLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrLfi* comp);
		std::set<Sbecore::uint> diff(const StatShrLfi* comp);
	};

	/**
		* Tag (full: TagDlgWznmPrjImpex)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgWznmPrjImpexIfi)
		*/
	class TagIfi {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgWznmPrjImpexImp)
		*/
	class TagImp {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWznmPrjImpexLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmPrjImpexData)
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
		* DpchAppDo (full: DpchAppDlgWznmPrjImpexDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOIMP = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoImp;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmPrjImpexData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFIMP = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRIFI = 10;
		static const Sbecore::uint STATSHRIMP = 11;
		static const Sbecore::uint STATSHRLFI = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGIFI = 14;
		static const Sbecore::uint TAGIMP = 15;
		static const Sbecore::uint TAGLFI = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, ContInfLfi* continflfi = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalLfiDldActive(DbsWznm* dbswznm);
	bool evalImpButAutActive(DbsWznm* dbswznm);
	bool evalImpButRunActive(DbsWznm* dbswznm);
	bool evalImpButStoActive(DbsWznm* dbswznm);
	bool evalIfiUldActive(DbsWznm* dbswznm);

public:
	DlgWznmPrjImpex(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmPrjImpex();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	ContInfLfi continflfi;
	StatShr statshr;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	JobWznmLicense* license;
	JobWznmIexPrj* iex;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;

	bool ifitxt;
	bool ifixml;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshIfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshImp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoImpButAutClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoImpButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoImpButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	void handleUploadInSgeIdle(DbsWznm* dbswznm, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);

	void handleTimerWithSrefMonInSgeImport(DbsWznm* dbswznm);
	void handleTimerInSgeImpidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerInSgePrsidle(DbsWznm* dbswznm, const std::string& sref);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlraer(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlraer(DbsWznm* dbswznm);
	Sbecore::uint enterSgePrsidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePrsidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeParse(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeParse(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrwznmper(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrwznmper(DbsWznm* dbswznm);
	Sbecore::uint enterSgePrsdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePrsdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAuth(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAuth(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAutdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAutdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeImpidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeImpidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeImport(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeImport(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrwznmier(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrwznmier(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSync(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSync(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif


