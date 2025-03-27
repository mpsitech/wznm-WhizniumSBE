/**
	* \file DlgWznmVisExpstr.h
	* job handler for job DlgWznmVisExpstr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVISEXPSTR_H
#define DLGWZNMVISEXPSTR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWznmIexVis.h"

#define VecVDlgWznmVisExpstrDit DlgWznmVisExpstr::VecVDit
#define VecVDlgWznmVisExpstrDo DlgWznmVisExpstr::VecVDo
#define VecVDlgWznmVisExpstrDoWri DlgWznmVisExpstr::VecVDoWri
#define VecVDlgWznmVisExpstrSge DlgWznmVisExpstr::VecVSge

#define ContIacDlgWznmVisExpstr DlgWznmVisExpstr::ContIac
#define ContInfDlgWznmVisExpstr DlgWznmVisExpstr::ContInf
#define ContInfDlgWznmVisExpstrMfi DlgWznmVisExpstr::ContInfMfi
#define ContInfDlgWznmVisExpstrWri DlgWznmVisExpstr::ContInfWri
#define StatAppDlgWznmVisExpstr DlgWznmVisExpstr::StatApp
#define StatShrDlgWznmVisExpstr DlgWznmVisExpstr::StatShr
#define StatShrDlgWznmVisExpstrMfi DlgWznmVisExpstr::StatShrMfi
#define StatShrDlgWznmVisExpstrWri DlgWznmVisExpstr::StatShrWri
#define TagDlgWznmVisExpstr DlgWznmVisExpstr::Tag
#define TagDlgWznmVisExpstrMfi DlgWznmVisExpstr::TagMfi
#define TagDlgWznmVisExpstrWri DlgWznmVisExpstr::TagWri

#define DpchAppDlgWznmVisExpstrData DlgWznmVisExpstr::DpchAppData
#define DpchAppDlgWznmVisExpstrDo DlgWznmVisExpstr::DpchAppDo
#define DpchEngDlgWznmVisExpstrData DlgWznmVisExpstr::DpchEngData

/**
	* DlgWznmVisExpstr
	*/
class DlgWznmVisExpstr : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmVisExpstrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint WRI = 1;
		static const Sbecore::uint MFI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmVisExpstrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWri (full: VecVDlgWznmVisExpstrDoWri)
		*/
	class VecVDoWri {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVisExpstrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint EXPORT = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVisExpstr)
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
	  * ContInf (full: ContInfDlgWznmVisExpstr)
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
	  * ContInfMfi (full: ContInfDlgWznmVisExpstrMfi)
	  */
	class ContInfMfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfMfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfMfi* comp);
		std::set<Sbecore::uint> diff(const ContInfMfi* comp);
	};

	/**
	  * ContInfWri (full: ContInfDlgWznmVisExpstrWri)
	  */
	class ContInfWri : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfWri(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfWri* comp);
		std::set<Sbecore::uint> diff(const ContInfWri* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmVisExpstr)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmVisExpstr)
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
		* StatShrMfi (full: StatShrDlgWznmVisExpstrMfi)
		*/
	class StatShrMfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrMfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrMfi* comp);
		std::set<Sbecore::uint> diff(const StatShrMfi* comp);
	};

	/**
		* StatShrWri (full: StatShrDlgWznmVisExpstrWri)
		*/
	class StatShrWri : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrWri(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrWri* comp);
		std::set<Sbecore::uint> diff(const StatShrWri* comp);
	};

	/**
		* Tag (full: TagDlgWznmVisExpstr)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagMfi (full: TagDlgWznmVisExpstrMfi)
		*/
	class TagMfi {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagWri (full: TagDlgWznmVisExpstrWri)
		*/
	class TagWri {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVisExpstrData)
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
		* DpchAppDo (full: DpchAppDlgWznmVisExpstrDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOWRI = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoWri;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVisExpstrData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFMFI = 4;
		static const Sbecore::uint CONTINFWRI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRMFI = 10;
		static const Sbecore::uint STATSHRWRI = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint TAGMFI = 13;
		static const Sbecore::uint TAGWRI = 14;
		static const Sbecore::uint ALL = 15;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfMfi* continfmfi = NULL, ContInfWri* continfwri = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrMfi* statshrmfi = NULL, StatShrWri* statshrwri = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfMfi continfmfi;
		ContInfWri continfwri;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrMfi statshrmfi;
		StatShrWri statshrwri;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalMfiDldActive(DbsWznm* dbswznm);
	bool evalWriButRunActive(DbsWznm* dbswznm);
	bool evalWriButStoActive(DbsWznm* dbswznm);

public:
	DlgWznmVisExpstr(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmVisExpstr();

public:
	ContIac contiac;
	ContInf continf;
	ContInfMfi continfmfi;
	ContInfWri continfwri;
	StatShr statshr;
	StatShrMfi statshrmfi;
	StatShrWri statshrwri;

	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	JobWznmIexVis* iexvis;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string visshort;

	std::string outfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshWri(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshMfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoWriButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoWriButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeExport(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeExport(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
