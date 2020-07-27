/**
	* \file DlgWznmVerGenjtr.h
	* job handler for job DlgWznmVerGenjtr (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef DLGWZNMVERGENJTR_H
#define DLGWZNMVERGENJTR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWznmVerGenjtrDit DlgWznmVerGenjtr::VecVDit
#define VecVDlgWznmVerGenjtrDo DlgWznmVerGenjtr::VecVDo
#define VecVDlgWznmVerGenjtrSge DlgWznmVerGenjtr::VecVSge

#define ContIacDlgWznmVerGenjtr DlgWznmVerGenjtr::ContIac
#define ContInfDlgWznmVerGenjtr DlgWznmVerGenjtr::ContInf
#define ContInfDlgWznmVerGenjtrLfi DlgWznmVerGenjtr::ContInfLfi
#define StatAppDlgWznmVerGenjtr DlgWznmVerGenjtr::StatApp
#define StatShrDlgWznmVerGenjtr DlgWznmVerGenjtr::StatShr
#define StatShrDlgWznmVerGenjtrLfi DlgWznmVerGenjtr::StatShrLfi
#define TagDlgWznmVerGenjtr DlgWznmVerGenjtr::Tag
#define TagDlgWznmVerGenjtrGjt DlgWznmVerGenjtr::TagGjt
#define TagDlgWznmVerGenjtrLfi DlgWznmVerGenjtr::TagLfi

#define DpchAppDlgWznmVerGenjtrData DlgWznmVerGenjtr::DpchAppData
#define DpchAppDlgWznmVerGenjtrDo DlgWznmVerGenjtr::DpchAppDo
#define DpchEngDlgWznmVerGenjtrData DlgWznmVerGenjtr::DpchEngData

/**
	* DlgWznmVerGenjtr
	*/
class DlgWznmVerGenjtr : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmVerGenjtrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint GJT = 1;
		static const Sbecore::uint LFI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmVerGenjtrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint GJTBUTRUNCLICK = 1;
		static const Sbecore::uint GJTBUTSTOCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVerGenjtrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRGER = 2;
		static const Sbecore::uint GENQTB = 3;
		static const Sbecore::uint GENJOB = 4;
		static const Sbecore::uint GENCALL = 5;
		static const Sbecore::uint GENCTP = 6;
		static const Sbecore::uint ASMLFI = 7;
		static const Sbecore::uint FAIL = 8;
		static const Sbecore::uint DONE = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVerGenjtr)
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
	  * ContInf (full: ContInfDlgWznmVerGenjtr)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint GJTTXTPRG = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& GjtTxtPrg = "");

	public:
		Sbecore::uint numFSge;
		std::string GjtTxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmVerGenjtrLfi)
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
		* StatApp (full: StatAppDlgWznmVerGenjtr)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmVerGenjtr)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint GJTBUTRUNACTIVE = 1;
		static const Sbecore::uint GJTBUTSTOACTIVE = 2;
		static const Sbecore::uint BUTDNEACTIVE = 3;

	public:
		StatShr(const bool GjtButRunActive = true, const bool GjtButStoActive = true, const bool ButDneActive = true);

	public:
		bool GjtButRunActive;
		bool GjtButStoActive;
		bool ButDneActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWznmVerGenjtrLfi)
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
		* Tag (full: TagDlgWznmVerGenjtr)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagGjt (full: TagDlgWznmVerGenjtrGjt)
		*/
	class TagGjt {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWznmVerGenjtrLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVerGenjtrData)
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
		* DpchAppDo (full: DpchAppDlgWznmVerGenjtrDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVerGenjtrData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFLFI = 4;
		static const Sbecore::uint FEEDFDSE = 5;
		static const Sbecore::uint FEEDFSGE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint STATSHRLFI = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint TAGGJT = 11;
		static const Sbecore::uint TAGLFI = 12;
		static const Sbecore::uint ALL = 13;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfLfi* continflfi = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrLfi* statshrlfi = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfLfi continflfi;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrLfi statshrlfi;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLfiDldActive(DbsWznm* dbswznm);
	bool evalGjtButRunActive(DbsWznm* dbswznm);
	bool evalGjtButStoActive(DbsWznm* dbswznm);
	bool evalButDneActive(DbsWznm* dbswznm);

public:
	DlgWznmVerGenjtr(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmVerGenjtr();

public:
	ContIac contiac;
	ContInf continf;
	ContInfLfi continflfi;
	StatShr statshr;
	StatShrLfi statshrlfi;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::map<Sbecore::ubigint,Sbecore::ubigint> orefsToRefs;

	std::vector<std::string> logfiles;
	std::vector<std::string> logheaders;

	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshGjt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoGjtButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoGjtButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	std::string handleDownloadInSgeFail(DbsWznm* dbswznm);

	void handleDpchRetWznm(DbsWznm* dbswznm, DpchRetWznm* dpchret);
	void handleDpchRetWznmCtpGenjtr(DbsWznm* dbswznm, DpchRetWznmCtpGenjtr* dpchret);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrger(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrger(DbsWznm* dbswznm);
	Sbecore::uint enterSgeGenqtb(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeGenqtb(DbsWznm* dbswznm);
	Sbecore::uint enterSgeGenjob(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeGenjob(DbsWznm* dbswznm);
	Sbecore::uint enterSgeGencall(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeGencall(DbsWznm* dbswznm);
	Sbecore::uint enterSgeGenctp(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeGenctp(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAsmlfi(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAsmlfi(DbsWznm* dbswznm);
	Sbecore::uint enterSgeFail(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeFail(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif

