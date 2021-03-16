/**
	* \file DlgWznmRlsStareptr.h
	* job handler for job DlgWznmRlsStareptr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMRLSSTAREPTR_H
#define DLGWZNMRLSSTAREPTR_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include "git2.h"
// IP include.cust --- IEND

#define VecVDlgWznmRlsStareptrDit DlgWznmRlsStareptr::VecVDit
#define VecVDlgWznmRlsStareptrDo DlgWznmRlsStareptr::VecVDo
#define VecVDlgWznmRlsStareptrDoDet DlgWznmRlsStareptr::VecVDoDet
#define VecVDlgWznmRlsStareptrDoExt DlgWznmRlsStareptr::VecVDoExt
#define VecVDlgWznmRlsStareptrDoIni DlgWznmRlsStareptr::VecVDoIni
#define VecVDlgWznmRlsStareptrSge DlgWznmRlsStareptr::VecVSge

#define ContIacDlgWznmRlsStareptr DlgWznmRlsStareptr::ContIac
#define ContIacDlgWznmRlsStareptrDet DlgWznmRlsStareptr::ContIacDet
#define ContInfDlgWznmRlsStareptr DlgWznmRlsStareptr::ContInf
#define ContInfDlgWznmRlsStareptrExt DlgWznmRlsStareptr::ContInfExt
#define ContInfDlgWznmRlsStareptrIni DlgWznmRlsStareptr::ContInfIni
#define ContInfDlgWznmRlsStareptrLfi DlgWznmRlsStareptr::ContInfLfi
#define StatAppDlgWznmRlsStareptr DlgWznmRlsStareptr::StatApp
#define StatShrDlgWznmRlsStareptr DlgWznmRlsStareptr::StatShr
#define StatShrDlgWznmRlsStareptrDet DlgWznmRlsStareptr::StatShrDet
#define StatShrDlgWznmRlsStareptrExt DlgWznmRlsStareptr::StatShrExt
#define StatShrDlgWznmRlsStareptrIni DlgWznmRlsStareptr::StatShrIni
#define StatShrDlgWznmRlsStareptrLfi DlgWznmRlsStareptr::StatShrLfi
#define TagDlgWznmRlsStareptr DlgWznmRlsStareptr::Tag
#define TagDlgWznmRlsStareptrDet DlgWznmRlsStareptr::TagDet
#define TagDlgWznmRlsStareptrExt DlgWznmRlsStareptr::TagExt
#define TagDlgWznmRlsStareptrIni DlgWznmRlsStareptr::TagIni
#define TagDlgWznmRlsStareptrLfi DlgWznmRlsStareptr::TagLfi

#define DpchAppDlgWznmRlsStareptrData DlgWznmRlsStareptr::DpchAppData
#define DpchAppDlgWznmRlsStareptrDo DlgWznmRlsStareptr::DpchAppDo
#define DpchEngDlgWznmRlsStareptrData DlgWznmRlsStareptr::DpchEngData

/**
	* DlgWznmRlsStareptr
	*/
class DlgWznmRlsStareptr : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmRlsStareptrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint INI = 2;
		static const Sbecore::uint EXT = 3;
		static const Sbecore::uint LFI = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmRlsStareptrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgWznmRlsStareptrDoDet)
		*/
	class VecVDoDet {

	public:
		static const Sbecore::uint BUTSTACLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoExt (full: VecVDlgWznmRlsStareptrDoExt)
		*/
	class VecVDoExt {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoIni (full: VecVDlgWznmRlsStareptrDoIni)
		*/
	class VecVDoIni {

	public:
		static const Sbecore::uint BUTCLGCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmRlsStareptrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRGNF = 2;
		static const Sbecore::uint ALRGAD = 3;
		static const Sbecore::uint ALRGVE = 4;
		static const Sbecore::uint ALRXER = 5;
		static const Sbecore::uint STADONE = 6;
		static const Sbecore::uint UPKIDLE = 7;
		static const Sbecore::uint UNPACK = 8;
		static const Sbecore::uint UPKDONE = 9;
		static const Sbecore::uint CLGIDLE = 10;
		static const Sbecore::uint CLONEGIT = 11;
		static const Sbecore::uint CLGDONE = 12;
		static const Sbecore::uint EXTRACT = 13;
		static const Sbecore::uint PACK = 14;
		static const Sbecore::uint FAIL = 15;
		static const Sbecore::uint DONE = 16;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmRlsStareptr)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacDet (full: ContIacDlgWznmRlsStareptrDet)
	  */
	class ContIacDet : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFRBUBRT = 1;
		static const Sbecore::uint TXFGRL = 2;

	public:
		ContIacDet(const Sbecore::uint numFRbuBrt = 1, const std::string& TxfGrl = "");

	public:
		Sbecore::uint numFRbuBrt;
		std::string TxfGrl;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmRlsStareptr)
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
	  * ContInfExt (full: ContInfDlgWznmRlsStareptrExt)
	  */
	class ContInfExt : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfExt(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfExt* comp);
		std::set<Sbecore::uint> diff(const ContInfExt* comp);
	};

	/**
	  * ContInfIni (full: ContInfDlgWznmRlsStareptrIni)
	  */
	class ContInfIni : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfIni(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfIni* comp);
		std::set<Sbecore::uint> diff(const ContInfIni* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmRlsStareptrLfi)
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
		* StatApp (full: StatAppDlgWznmRlsStareptr)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmRlsStareptr)
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
		* StatShrDet (full: StatShrDlgWznmRlsStareptrDet)
		*/
	class StatShrDet : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFGRLAVAIL = 1;
		static const Sbecore::uint BUTSTAACTIVE = 2;

	public:
		StatShrDet(const bool TxfGrlAvail = true, const bool ButStaActive = true);

	public:
		bool TxfGrlAvail;
		bool ButStaActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrDet* comp);
		std::set<Sbecore::uint> diff(const StatShrDet* comp);
	};

	/**
		* StatShrExt (full: StatShrDlgWznmRlsStareptrExt)
		*/
	class StatShrExt : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrExt(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrExt* comp);
		std::set<Sbecore::uint> diff(const StatShrExt* comp);
	};

	/**
		* StatShrIni (full: StatShrDlgWznmRlsStareptrIni)
		*/
	class StatShrIni : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDAVAIL = 1;
		static const Sbecore::uint ULDACTIVE = 2;
		static const Sbecore::uint TXTPRGAVAIL = 3;
		static const Sbecore::uint SEP1AVAIL = 4;
		static const Sbecore::uint BUTCLGAVAIL = 5;
		static const Sbecore::uint BUTCLGACTIVE = 6;

	public:
		StatShrIni(const bool UldAvail = true, const bool UldActive = true, const bool TxtPrgAvail = true, const bool Sep1Avail = true, const bool ButClgAvail = true, const bool ButClgActive = true);

	public:
		bool UldAvail;
		bool UldActive;
		bool TxtPrgAvail;
		bool Sep1Avail;
		bool ButClgAvail;
		bool ButClgActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrIni* comp);
		std::set<Sbecore::uint> diff(const StatShrIni* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWznmRlsStareptrLfi)
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
		* Tag (full: TagDlgWznmRlsStareptr)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgWznmRlsStareptrDet)
		*/
	class TagDet {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagExt (full: TagDlgWznmRlsStareptrExt)
		*/
	class TagExt {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagIni (full: TagDlgWznmRlsStareptrIni)
		*/
	class TagIni {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWznmRlsStareptrLfi)
		*/
	class TagLfi {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmRlsStareptrData)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmRlsStareptrDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDODET = 3;
		static const Sbecore::uint IXVDOEXT = 4;
		static const Sbecore::uint IXVDOINI = 5;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoDet;
		Sbecore::uint ixVDoExt;
		Sbecore::uint ixVDoIni;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmRlsStareptrData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFEXT = 5;
		static const Sbecore::uint CONTINFINI = 6;
		static const Sbecore::uint CONTINFLFI = 7;
		static const Sbecore::uint FEEDFDETRBUBRT = 8;
		static const Sbecore::uint FEEDFDSE = 9;
		static const Sbecore::uint FEEDFSGE = 10;
		static const Sbecore::uint STATAPP = 11;
		static const Sbecore::uint STATSHR = 12;
		static const Sbecore::uint STATSHRDET = 13;
		static const Sbecore::uint STATSHREXT = 14;
		static const Sbecore::uint STATSHRINI = 15;
		static const Sbecore::uint STATSHRLFI = 16;
		static const Sbecore::uint TAG = 17;
		static const Sbecore::uint TAGDET = 18;
		static const Sbecore::uint TAGEXT = 19;
		static const Sbecore::uint TAGINI = 20;
		static const Sbecore::uint TAGLFI = 21;
		static const Sbecore::uint ALL = 22;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfExt* continfext = NULL, ContInfIni* continfini = NULL, ContInfLfi* continflfi = NULL, Sbecore::Feed* feedFDetRbuBrt = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrDet* statshrdet = NULL, StatShrExt* statshrext = NULL, StatShrIni* statshrini = NULL, StatShrLfi* statshrlfi = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfExt continfext;
		ContInfIni continfini;
		ContInfLfi continflfi;
		Sbecore::Feed feedFDetRbuBrt;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrDet statshrdet;
		StatShrExt statshrext;
		StatShrIni statshrini;
		StatShrLfi statshrlfi;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalLfiDldActive(DbsWznm* dbswznm);
	bool evalExtButRunActive(DbsWznm* dbswznm);
	bool evalExtButStoActive(DbsWznm* dbswznm);
	bool evalIniUldAvail(DbsWznm* dbswznm);
	bool evalIniUldActive(DbsWznm* dbswznm);
	bool evalIniTxtPrgAvail(DbsWznm* dbswznm);
	bool evalIniSep1Avail(DbsWznm* dbswznm);
	bool evalIniButClgAvail(DbsWznm* dbswznm);
	bool evalIniButClgActive(DbsWznm* dbswznm);
	bool evalDetTxfGrlAvail(DbsWznm* dbswznm);
	bool evalDetButStaActive(DbsWznm* dbswznm);

public:
	DlgWznmRlsStareptr(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmRlsStareptr();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfExt continfext;
	ContInfIni continfini;
	ContInfLfi continflfi;
	StatShr statshr;
	StatShrDet statshrdet;
	StatShrExt statshrext;
	StatShrIni statshrini;
	StatShrLfi statshrlfi;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDetRbuBrt;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string usrsref;

	std::string infilename;

	std::string acttag;
	std::string exptag;

	Sbecore::Mutex mGitprg;
	std::string gitprg;

	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	static int gitCredCallback(git_cred** cred, const char* url, const char* username_from_url, unsigned int allowed_types, void* payload);

	static int gitFetchCallback(const git_transfer_progress* _stats, void* payload);
	static void gitCheckoutCallback(const char* path, size_t _cur, size_t _tot, void* payload);
	// IP cust --- IEND

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshIni(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshExt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiacdet(DbsWznm* dbswznm, ContIacDet* _contiacdet, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoDetButStaClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoExtButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoExtButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoIniButClgClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	void handleUploadInSgeStadone(DbsWznm* dbswznm, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);
	std::string handleDownloadInSgeFail(DbsWznm* dbswznm);

	void handleDpchRetWznmPrctreeExtract(DbsWznm* dbswznm, DpchRetWznmPrctreeExtract* dpchret);

	void handleTimerInSgeUpkidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerInSgeClgidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerWithSrefMonInSgeClonegit(DbsWznm* dbswznm);

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
	Sbecore::uint enterSgeAlrgve(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrgve(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrxer(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrxer(DbsWznm* dbswznm);
	Sbecore::uint enterSgeStadone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeStadone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUnpack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUnpack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeClgidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeClgidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeClonegit(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeClonegit(DbsWznm* dbswznm);
	Sbecore::uint enterSgeClgdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeClgdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeExtract(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeExtract(DbsWznm* dbswznm);
	Sbecore::uint enterSgePack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeFail(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeFail(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
