/**
	* \file DlgWznmMchWriniscr.h
	* job handler for job DlgWznmMchWriniscr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMMCHWRINISCR_H
#define DLGWZNMMCHWRINISCR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWznmMchWriniscrDit DlgWznmMchWriniscr::VecVDit
#define VecVDlgWznmMchWriniscrDo DlgWznmMchWriniscr::VecVDo
#define VecVDlgWznmMchWriniscrDoWri DlgWznmMchWriniscr::VecVDoWri
#define VecVDlgWznmMchWriniscrSge DlgWznmMchWriniscr::VecVSge

#define ContIacDlgWznmMchWriniscr DlgWznmMchWriniscr::ContIac
#define ContInfDlgWznmMchWriniscr DlgWznmMchWriniscr::ContInf
#define ContInfDlgWznmMchWriniscrFia DlgWznmMchWriniscr::ContInfFia
#define ContInfDlgWznmMchWriniscrWri DlgWznmMchWriniscr::ContInfWri
#define StatAppDlgWznmMchWriniscr DlgWznmMchWriniscr::StatApp
#define StatShrDlgWznmMchWriniscr DlgWznmMchWriniscr::StatShr
#define StatShrDlgWznmMchWriniscrFia DlgWznmMchWriniscr::StatShrFia
#define StatShrDlgWznmMchWriniscrWri DlgWznmMchWriniscr::StatShrWri
#define TagDlgWznmMchWriniscr DlgWznmMchWriniscr::Tag
#define TagDlgWznmMchWriniscrFia DlgWznmMchWriniscr::TagFia
#define TagDlgWznmMchWriniscrWri DlgWznmMchWriniscr::TagWri

#define DpchAppDlgWznmMchWriniscrData DlgWznmMchWriniscr::DpchAppData
#define DpchAppDlgWznmMchWriniscrDo DlgWznmMchWriniscr::DpchAppDo
#define DpchEngDlgWznmMchWriniscrData DlgWznmMchWriniscr::DpchEngData

/**
	* DlgWznmMchWriniscr
	*/
class DlgWznmMchWriniscr : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmMchWriniscrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint WRI = 1;
		static const Sbecore::uint FIA = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmMchWriniscrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWri (full: VecVDlgWznmMchWriniscrDoWri)
		*/
	class VecVDoWri {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmMchWriniscrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint WRITE = 2;
		static const Sbecore::uint PACK = 3;
		static const Sbecore::uint DONE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmMchWriniscr)
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
	  * ContInf (full: ContInfDlgWznmMchWriniscr)
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
	  * ContInfFia (full: ContInfDlgWznmMchWriniscrFia)
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
	  * ContInfWri (full: ContInfDlgWznmMchWriniscrWri)
	  */
	class ContInfWri : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfWri(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfWri* comp);
		std::set<Sbecore::uint> diff(const ContInfWri* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmMchWriniscr)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmMchWriniscr)
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
		* StatShrFia (full: StatShrDlgWznmMchWriniscrFia)
		*/
	class StatShrFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrFia(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
		* StatShrWri (full: StatShrDlgWznmMchWriniscrWri)
		*/
	class StatShrWri : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrWri(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrWri* comp);
		std::set<Sbecore::uint> diff(const StatShrWri* comp);
	};

	/**
		* Tag (full: TagDlgWznmMchWriniscr)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgWznmMchWriniscrFia)
		*/
	class TagFia {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagWri (full: TagDlgWznmMchWriniscrWri)
		*/
	class TagWri {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmMchWriniscrData)
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
		* DpchAppDo (full: DpchAppDlgWznmMchWriniscrDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmMchWriniscrData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFFIA = 4;
		static const Sbecore::uint CONTINFWRI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRFIA = 10;
		static const Sbecore::uint STATSHRWRI = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint TAGFIA = 13;
		static const Sbecore::uint TAGWRI = 14;
		static const Sbecore::uint ALL = 15;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfFia* continffia = NULL, ContInfWri* continfwri = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrFia* statshrfia = NULL, StatShrWri* statshrwri = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfFia continffia;
		ContInfWri continfwri;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrFia statshrfia;
		StatShrWri statshrwri;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalFiaDldActive(DbsWznm* dbswznm);
	bool evalWriButRunActive(DbsWznm* dbswznm);
	bool evalWriButStoActive(DbsWznm* dbswznm);

public:
	DlgWznmMchWriniscr(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmMchWriniscr();

public:
	ContIac contiac;
	ContInf continf;
	ContInfFia continffia;
	ContInfWri continfwri;
	StatShr statshr;
	StatShrFia statshrfia;
	StatShrWri statshrwri;

	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string outfolder; // working directory
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshWri(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshFia(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

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

	void handleTimerWithSrefMonInSgeWrite(DbsWznm* dbswznm);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeWrite(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeWrite(DbsWznm* dbswznm);
	Sbecore::uint enterSgePack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif



