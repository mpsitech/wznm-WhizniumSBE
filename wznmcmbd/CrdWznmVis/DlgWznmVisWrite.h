/**
	* \file DlgWznmVisWrite.h
	* job handler for job DlgWznmVisWrite (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVISWRITE_H
#define DLGWZNMVISWRITE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWznmVisBoxctx.h"
#include "QryWznmVisLinkctx.h"
#include "QryWznmVisRowctx.h"

#define VecVDlgWznmVisWriteDit DlgWznmVisWrite::VecVDit
#define VecVDlgWznmVisWriteDo DlgWznmVisWrite::VecVDo
#define VecVDlgWznmVisWriteDoWrc DlgWznmVisWrite::VecVDoWrc
#define VecVDlgWznmVisWriteSge DlgWznmVisWrite::VecVSge

#define ContIacDlgWznmVisWrite DlgWznmVisWrite::ContIac
#define ContInfDlgWznmVisWrite DlgWznmVisWrite::ContInf
#define ContInfDlgWznmVisWriteFia DlgWznmVisWrite::ContInfFia
#define ContInfDlgWznmVisWriteLfi DlgWznmVisWrite::ContInfLfi
#define ContInfDlgWznmVisWriteWrc DlgWznmVisWrite::ContInfWrc
#define StatAppDlgWznmVisWrite DlgWznmVisWrite::StatApp
#define StatShrDlgWznmVisWrite DlgWznmVisWrite::StatShr
#define StatShrDlgWznmVisWriteFia DlgWznmVisWrite::StatShrFia
#define StatShrDlgWznmVisWriteLfi DlgWznmVisWrite::StatShrLfi
#define StatShrDlgWznmVisWriteWrc DlgWznmVisWrite::StatShrWrc
#define TagDlgWznmVisWrite DlgWznmVisWrite::Tag
#define TagDlgWznmVisWriteFia DlgWznmVisWrite::TagFia
#define TagDlgWznmVisWriteLfi DlgWznmVisWrite::TagLfi
#define TagDlgWznmVisWriteWrc DlgWznmVisWrite::TagWrc

#define DpchAppDlgWznmVisWriteData DlgWznmVisWrite::DpchAppData
#define DpchAppDlgWznmVisWriteDo DlgWznmVisWrite::DpchAppDo
#define DpchEngDlgWznmVisWriteData DlgWznmVisWrite::DpchEngData

/**
	* DlgWznmVisWrite
	*/
class DlgWznmVisWrite : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmVisWriteDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint WRC = 1;
		static const Sbecore::uint LFI = 2;
		static const Sbecore::uint FIA = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmVisWriteDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWrc (full: VecVDlgWznmVisWriteDoWrc)
		*/
	class VecVDoWrc {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVisWriteSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRMER = 2;
		static const Sbecore::uint WRITE = 3;
		static const Sbecore::uint MRGGNR = 4;
		static const Sbecore::uint PACK = 5;
		static const Sbecore::uint FAIL = 6;
		static const Sbecore::uint DONE = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVisWrite)
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
	  * ContInf (full: ContInfDlgWznmVisWrite)
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
	  * ContInfFia (full: ContInfDlgWznmVisWriteFia)
	  */
	class ContInfFia : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfFia(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfFia* comp);
		std::set<Sbecore::uint> diff(const ContInfFia* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmVisWriteLfi)
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
	  * ContInfWrc (full: ContInfDlgWznmVisWriteWrc)
	  */
	class ContInfWrc : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfWrc(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfWrc* comp);
		std::set<Sbecore::uint> diff(const ContInfWrc* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmVisWrite)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmVisWrite)
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
		* StatShrFia (full: StatShrDlgWznmVisWriteFia)
		*/
	class StatShrFia : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrFia(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWznmVisWriteLfi)
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
		* StatShrWrc (full: StatShrDlgWznmVisWriteWrc)
		*/
	class StatShrWrc : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrWrc(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrWrc* comp);
		std::set<Sbecore::uint> diff(const StatShrWrc* comp);
	};

	/**
		* Tag (full: TagDlgWznmVisWrite)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgWznmVisWriteFia)
		*/
	class TagFia {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWznmVisWriteLfi)
		*/
	class TagLfi {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagWrc (full: TagDlgWznmVisWriteWrc)
		*/
	class TagWrc {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVisWriteData)
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
		* DpchAppDo (full: DpchAppDlgWznmVisWriteDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVisWriteData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFFIA = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint CONTINFWRC = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHRFIA = 11;
		static const Sbecore::uint STATSHRLFI = 12;
		static const Sbecore::uint STATSHRWRC = 13;
		static const Sbecore::uint TAG = 14;
		static const Sbecore::uint TAGFIA = 15;
		static const Sbecore::uint TAGLFI = 16;
		static const Sbecore::uint TAGWRC = 17;
		static const Sbecore::uint ALL = 18;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfFia* continffia = NULL, ContInfLfi* continflfi = NULL, ContInfWrc* continfwrc = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrFia* statshrfia = NULL, StatShrLfi* statshrlfi = NULL, StatShrWrc* statshrwrc = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfFia continffia;
		ContInfLfi continflfi;
		ContInfWrc continfwrc;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrFia statshrfia;
		StatShrLfi statshrlfi;
		StatShrWrc statshrwrc;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalFiaDldActive(DbsWznm* dbswznm);
	bool evalLfiDldActive(DbsWznm* dbswznm);
	bool evalWrcButRunActive(DbsWznm* dbswznm);
	bool evalWrcButStoActive(DbsWznm* dbswznm);

public:
	DlgWznmVisWrite(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmVisWrite();

public:
	ContIac contiac;
	ContInf continf;
	ContInfFia continffia;
	ContInfLfi continflfi;
	ContInfWrc continfwrc;
	StatShr statshr;
	StatShrFia statshrfia;
	StatShrLfi statshrlfi;
	StatShrWrc statshrwrc;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	QryWznmVisBoxctx* qryboxctx;
	QryWznmVisLinkctx* qrylinkctx;
	QryWznmVisRowctx* qryrowctx;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string Prjshort;

	Sbecore::uint ixVistype;

	std::string outfolder; // working directory
	std::string ipfolder; // IP's

	std::string logaspect;
	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void create(DbsWznm* dbswznm);
	// IP cust --- IEND

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

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

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoWrcButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoWrcButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);
	std::string handleDownloadInSgeFail(DbsWznm* dbswznm);

	void handleDpchRetWznm(DbsWznm* dbswznm, DpchRetWznm* dpchret);
	void handleDpchRetWznmPrctreeMerge(DbsWznm* dbswznm, DpchRetWznmPrctreeMerge* dpchret);

	void handleTimerWithSrefMonInSgeWrite(DbsWznm* dbswznm);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrmer(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrmer(DbsWznm* dbswznm);
	Sbecore::uint enterSgeWrite(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeWrite(DbsWznm* dbswznm);
	Sbecore::uint enterSgeMrggnr(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeMrggnr(DbsWznm* dbswznm);
	Sbecore::uint enterSgePack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeFail(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeFail(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
