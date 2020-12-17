/**
	* \file DlgWznmRlsWrite.h
	* job handler for job DlgWznmRlsWrite (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMRLSWRITE_H
#define DLGWZNMRLSWRITE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWznmLicense.h"

#define VecVDlgWznmRlsWriteDit DlgWznmRlsWrite::VecVDit
#define VecVDlgWznmRlsWriteDo DlgWznmRlsWrite::VecVDo
#define VecVDlgWznmRlsWriteDoWrc DlgWznmRlsWrite::VecVDoWrc
#define VecVDlgWznmRlsWriteSge DlgWznmRlsWrite::VecVSge

#define ContIacDlgWznmRlsWrite DlgWznmRlsWrite::ContIac
#define ContIacDlgWznmRlsWriteDet DlgWznmRlsWrite::ContIacDet
#define ContInfDlgWznmRlsWrite DlgWznmRlsWrite::ContInf
#define ContInfDlgWznmRlsWriteFia DlgWznmRlsWrite::ContInfFia
#define ContInfDlgWznmRlsWriteLfi DlgWznmRlsWrite::ContInfLfi
#define ContInfDlgWznmRlsWriteWrc DlgWznmRlsWrite::ContInfWrc
#define StatAppDlgWznmRlsWrite DlgWznmRlsWrite::StatApp
#define StatShrDlgWznmRlsWrite DlgWznmRlsWrite::StatShr
#define StatShrDlgWznmRlsWriteCuc DlgWznmRlsWrite::StatShrCuc
#define StatShrDlgWznmRlsWriteFia DlgWznmRlsWrite::StatShrFia
#define StatShrDlgWznmRlsWriteLfi DlgWznmRlsWrite::StatShrLfi
#define StatShrDlgWznmRlsWriteWrc DlgWznmRlsWrite::StatShrWrc
#define TagDlgWznmRlsWrite DlgWznmRlsWrite::Tag
#define TagDlgWznmRlsWriteCuc DlgWznmRlsWrite::TagCuc
#define TagDlgWznmRlsWriteDet DlgWznmRlsWrite::TagDet
#define TagDlgWznmRlsWriteFia DlgWznmRlsWrite::TagFia
#define TagDlgWznmRlsWriteLfi DlgWznmRlsWrite::TagLfi
#define TagDlgWznmRlsWriteWrc DlgWznmRlsWrite::TagWrc

#define DpchAppDlgWznmRlsWriteData DlgWznmRlsWrite::DpchAppData
#define DpchAppDlgWznmRlsWriteDo DlgWznmRlsWrite::DpchAppDo
#define DpchEngDlgWznmRlsWriteData DlgWznmRlsWrite::DpchEngData

/**
	* DlgWznmRlsWrite
	*/
class DlgWznmRlsWrite : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmRlsWriteDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint CUC = 2;
		static const Sbecore::uint WRC = 3;
		static const Sbecore::uint LFI = 4;
		static const Sbecore::uint FIA = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmRlsWriteDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWrc (full: VecVDlgWznmRlsWriteDoWrc)
		*/
	class VecVDoWrc {

	public:
		static const Sbecore::uint BUTAUTCLICK = 1;
		static const Sbecore::uint BUTRUNCLICK = 2;
		static const Sbecore::uint BUTSTOCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmRlsWriteSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint ALRMER = 3;
		static const Sbecore::uint UPKIDLE = 4;
		static const Sbecore::uint UNPACK = 5;
		static const Sbecore::uint UPKDONE = 6;
		static const Sbecore::uint AUTH = 7;
		static const Sbecore::uint AUTDONE = 8;
		static const Sbecore::uint CREIDLE = 9;
		static const Sbecore::uint CREATE = 10;
		static const Sbecore::uint WRITE = 11;
		static const Sbecore::uint MRGGNR = 12;
		static const Sbecore::uint MRGSPEC = 13;
		static const Sbecore::uint MRGCTP = 14;
		static const Sbecore::uint MRGCUST = 15;
		static const Sbecore::uint PACK = 16;
		static const Sbecore::uint FAIL = 17;
		static const Sbecore::uint DONE = 18;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmRlsWrite)
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
	  * ContIacDet (full: ContIacDlgWznmRlsWriteDet)
	  */
	class ContIacDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CHKBSO = 1;

	public:
		ContIacDet(const bool ChkBso = false);

	public:
		bool ChkBso;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmRlsWrite)
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
	  * ContInfFia (full: ContInfDlgWznmRlsWriteFia)
	  */
	class ContInfFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfFia(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfFia* comp);
		std::set<Sbecore::uint> diff(const ContInfFia* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmRlsWriteLfi)
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
	  * ContInfWrc (full: ContInfDlgWznmRlsWriteWrc)
	  */
	class ContInfWrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfWrc(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfWrc* comp);
		std::set<Sbecore::uint> diff(const ContInfWrc* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmRlsWrite)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmRlsWrite)
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
		* StatShrCuc (full: StatShrDlgWznmRlsWriteCuc)
		*/
	class StatShrCuc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDAVAIL = 1;
		static const Sbecore::uint ULDACTIVE = 2;

	public:
		StatShrCuc(const bool UldAvail = true, const bool UldActive = true);

	public:
		bool UldAvail;
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrCuc* comp);
		std::set<Sbecore::uint> diff(const StatShrCuc* comp);
	};

	/**
		* StatShrFia (full: StatShrDlgWznmRlsWriteFia)
		*/
	class StatShrFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDAVAIL = 1;
		static const Sbecore::uint DLDACTIVE = 2;

	public:
		StatShrFia(const bool DldAvail = true, const bool DldActive = true);

	public:
		bool DldAvail;
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWznmRlsWriteLfi)
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
		* StatShrWrc (full: StatShrDlgWznmRlsWriteWrc)
		*/
	class StatShrWrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTAUTACTIVE = 1;
		static const Sbecore::uint BUTRUNACTIVE = 2;
		static const Sbecore::uint BUTSTOACTIVE = 3;

	public:
		StatShrWrc(const bool ButAutActive = true, const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButAutActive;
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrWrc* comp);
		std::set<Sbecore::uint> diff(const StatShrWrc* comp);
	};

	/**
		* Tag (full: TagDlgWznmRlsWrite)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagCuc (full: TagDlgWznmRlsWriteCuc)
		*/
	class TagCuc {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgWznmRlsWriteDet)
		*/
	class TagDet {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgWznmRlsWriteFia)
		*/
	class TagFia {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWznmRlsWriteLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagWrc (full: TagDlgWznmRlsWriteWrc)
		*/
	class TagWrc {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmRlsWriteData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmRlsWriteDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOWRC = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoWrc;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmRlsWriteData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFFIA = 5;
		static const Sbecore::uint CONTINFLFI = 6;
		static const Sbecore::uint CONTINFWRC = 7;
		static const Sbecore::uint FEEDFDSE = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint STATSHRCUC = 12;
		static const Sbecore::uint STATSHRFIA = 13;
		static const Sbecore::uint STATSHRLFI = 14;
		static const Sbecore::uint STATSHRWRC = 15;
		static const Sbecore::uint TAG = 16;
		static const Sbecore::uint TAGCUC = 17;
		static const Sbecore::uint TAGDET = 18;
		static const Sbecore::uint TAGFIA = 19;
		static const Sbecore::uint TAGLFI = 20;
		static const Sbecore::uint TAGWRC = 21;
		static const Sbecore::uint ALL = 22;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfFia* continffia = NULL, ContInfLfi* continflfi = NULL, ContInfWrc* continfwrc = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrCuc* statshrcuc = NULL, StatShrFia* statshrfia = NULL, StatShrLfi* statshrlfi = NULL, StatShrWrc* statshrwrc = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfFia continffia;
		ContInfLfi continflfi;
		ContInfWrc continfwrc;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrCuc statshrcuc;
		StatShrFia statshrfia;
		StatShrLfi statshrlfi;
		StatShrWrc statshrwrc;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLfiDldActive(DbsWznm* dbswznm);
	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalFiaDldAvail(DbsWznm* dbswznm);
	bool evalFiaDldActive(DbsWznm* dbswznm);
	bool evalWrcButAutActive(DbsWznm* dbswznm);
	bool evalWrcButRunActive(DbsWznm* dbswznm);
	bool evalWrcButStoActive(DbsWznm* dbswznm);
	bool evalCucUldAvail(DbsWznm* dbswznm);
	bool evalCucUldActive(DbsWznm* dbswznm);

public:
	DlgWznmRlsWrite(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmRlsWrite();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfFia continffia;
	ContInfLfi continflfi;
	ContInfWrc continfwrc;
	StatShr statshr;
	StatShrCuc statshrcuc;
	StatShrFia statshrfia;
	StatShrLfi statshrlfi;
	StatShrWrc statshrwrc;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	JobWznmLicense* license;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	Sbecore::ubigint refWznmMRelease;
	std::string rlssref;

	std::string author;

	std::string PRJSHORT;
	std::string Prjshort;
	std::string prjshort;

	std::string Prjtit;

	Sbecore::uint ixCmptype;

	std::string CMPSREF;
	std::string Cmpsref;
	std::string cmpsref;

	std::string cchost;
	std::string ncore;
	std::string sysroot;
	std::string inclibeq;

	std::string infilename;
	std::string outfolder; // working directory
	std::string ipfolder; // IP's
	std::string specfolder; // job-type specific IP's
	std::string custfolder; // custom IP's

	std::string logaspect;
	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void untgz(const std::string& tgzpath, const std::string& outfoder, const bool verbose = false);

	void createIpoutSubfolder(const bool spec, const std::string& sub1, const std::string& sub2 = "");
	void copyAcvtmp(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMFile, const std::string& tmpfile);

	void createEng(DbsWznm* dbswznm, const bool dplonly);
	void createOpeng(DbsWznm* dbswznm, const bool dplonly);
	void createCmbeng(DbsWznm* dbswznm, const bool dplonly);
	void createDbs(DbsWznm* dbswznm, const bool dplonly);
	void createWebapp(DbsWznm* dbswznm, const bool dplonly);
	void createApi(DbsWznm* dbswznm, const bool dplonly);
	void createJapi(DbsWznm* dbswznm, const bool dplonly);
	// IP cust --- IEND

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCuc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshWrc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshFia(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiacdet(DbsWznm* dbswznm, ContIacDet* _contiacdet, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoWrcButAutClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoWrcButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoWrcButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	void handleUploadInSgeIdle(DbsWznm* dbswznm, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);
	std::string handleDownloadInSgeFail(DbsWznm* dbswznm);

	void handleDpchRetWznm(DbsWznm* dbswznm, DpchRetWznm* dpchret);
	void handleDpchRetWznmPrctreeMerge(DbsWznm* dbswznm, DpchRetWznmPrctreeMerge* dpchret);

	void handleTimerInSgeUpkidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerWithSrefMonInSgeCreate(DbsWznm* dbswznm);
	void handleTimerInSgeCreidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerWithSrefMonInSgeWrite(DbsWznm* dbswznm);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlraer(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlraer(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrmer(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrmer(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUnpack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUnpack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAuth(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAuth(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAutdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAutdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCreidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCreidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCreate(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCreate(DbsWznm* dbswznm);
	Sbecore::uint enterSgeWrite(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeWrite(DbsWznm* dbswznm);
	Sbecore::uint enterSgeMrggnr(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeMrggnr(DbsWznm* dbswznm);
	Sbecore::uint enterSgeMrgspec(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeMrgspec(DbsWznm* dbswznm);
	Sbecore::uint enterSgeMrgctp(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeMrgctp(DbsWznm* dbswznm);
	Sbecore::uint enterSgeMrgcust(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeMrgcust(DbsWznm* dbswznm);
	Sbecore::uint enterSgePack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeFail(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeFail(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
