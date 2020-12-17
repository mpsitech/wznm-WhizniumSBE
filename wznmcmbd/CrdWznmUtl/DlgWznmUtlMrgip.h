/**
	* \file DlgWznmUtlMrgip.h
	* job handler for job DlgWznmUtlMrgip (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMUTLMRGIP_H
#define DLGWZNMUTLMRGIP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWznmUtlMrgipDit DlgWznmUtlMrgip::VecVDit
#define VecVDlgWznmUtlMrgipDo DlgWznmUtlMrgip::VecVDo
#define VecVDlgWznmUtlMrgipDoMrg DlgWznmUtlMrgip::VecVDoMrg
#define VecVDlgWznmUtlMrgipSge DlgWznmUtlMrgip::VecVSge

#define ContIacDlgWznmUtlMrgip DlgWznmUtlMrgip::ContIac
#define ContInfDlgWznmUtlMrgip DlgWznmUtlMrgip::ContInf
#define ContInfDlgWznmUtlMrgipLfi DlgWznmUtlMrgip::ContInfLfi
#define ContInfDlgWznmUtlMrgipMrg DlgWznmUtlMrgip::ContInfMrg
#define ContInfDlgWznmUtlMrgipRes DlgWznmUtlMrgip::ContInfRes
#define StatAppDlgWznmUtlMrgip DlgWznmUtlMrgip::StatApp
#define StatShrDlgWznmUtlMrgip DlgWznmUtlMrgip::StatShr
#define StatShrDlgWznmUtlMrgipLfi DlgWznmUtlMrgip::StatShrLfi
#define StatShrDlgWznmUtlMrgipMrg DlgWznmUtlMrgip::StatShrMrg
#define StatShrDlgWznmUtlMrgipRes DlgWznmUtlMrgip::StatShrRes
#define StatShrDlgWznmUtlMrgipSrc DlgWznmUtlMrgip::StatShrSrc
#define StatShrDlgWznmUtlMrgipTrg DlgWznmUtlMrgip::StatShrTrg
#define TagDlgWznmUtlMrgip DlgWznmUtlMrgip::Tag
#define TagDlgWznmUtlMrgipLfi DlgWznmUtlMrgip::TagLfi
#define TagDlgWznmUtlMrgipMrg DlgWznmUtlMrgip::TagMrg
#define TagDlgWznmUtlMrgipRes DlgWznmUtlMrgip::TagRes
#define TagDlgWznmUtlMrgipSrc DlgWznmUtlMrgip::TagSrc
#define TagDlgWznmUtlMrgipTrg DlgWznmUtlMrgip::TagTrg

#define DpchAppDlgWznmUtlMrgipData DlgWznmUtlMrgip::DpchAppData
#define DpchAppDlgWznmUtlMrgipDo DlgWznmUtlMrgip::DpchAppDo
#define DpchEngDlgWznmUtlMrgipData DlgWznmUtlMrgip::DpchEngData

/**
	* DlgWznmUtlMrgip
	*/
class DlgWznmUtlMrgip : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmUtlMrgipDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint SRC = 1;
		static const Sbecore::uint TRG = 2;
		static const Sbecore::uint MRG = 3;
		static const Sbecore::uint LFI = 4;
		static const Sbecore::uint RES = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmUtlMrgipDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoMrg (full: VecVDlgWznmUtlMrgipDoMrg)
		*/
	class VecVDoMrg {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmUtlMrgipSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRMER = 2;
		static const Sbecore::uint SUPIDLE = 3;
		static const Sbecore::uint SRCUNPACK = 4;
		static const Sbecore::uint SUPDONE = 5;
		static const Sbecore::uint SULDONE = 6;
		static const Sbecore::uint TUPIDLE = 7;
		static const Sbecore::uint TRGUNPACK = 8;
		static const Sbecore::uint TUPDONE = 9;
		static const Sbecore::uint TULDONE = 10;
		static const Sbecore::uint MERGE = 11;
		static const Sbecore::uint PACK = 12;
		static const Sbecore::uint FAIL = 13;
		static const Sbecore::uint DONE = 14;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmUtlMrgip)
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
	  * ContInf (full: ContInfDlgWznmUtlMrgip)
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
	  * ContInfLfi (full: ContInfDlgWznmUtlMrgipLfi)
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
	  * ContInfMrg (full: ContInfDlgWznmUtlMrgipMrg)
	  */
	class ContInfMrg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfMrg(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfMrg* comp);
		std::set<Sbecore::uint> diff(const ContInfMrg* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWznmUtlMrgipRes)
	  */
	class ContInfRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfRes(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfRes* comp);
		std::set<Sbecore::uint> diff(const ContInfRes* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmUtlMrgip)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmUtlMrgip)
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
		* StatShrLfi (full: StatShrDlgWznmUtlMrgipLfi)
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
		* StatShrMrg (full: StatShrDlgWznmUtlMrgipMrg)
		*/
	class StatShrMrg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrMrg(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrMrg* comp);
		std::set<Sbecore::uint> diff(const StatShrMrg* comp);
	};

	/**
		* StatShrRes (full: StatShrDlgWznmUtlMrgipRes)
		*/
	class StatShrRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrRes(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrRes* comp);
		std::set<Sbecore::uint> diff(const StatShrRes* comp);
	};

	/**
		* StatShrSrc (full: StatShrDlgWznmUtlMrgipSrc)
		*/
	class StatShrSrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrSrc(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrSrc* comp);
		std::set<Sbecore::uint> diff(const StatShrSrc* comp);
	};

	/**
		* StatShrTrg (full: StatShrDlgWznmUtlMrgipTrg)
		*/
	class StatShrTrg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrTrg(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrTrg* comp);
		std::set<Sbecore::uint> diff(const StatShrTrg* comp);
	};

	/**
		* Tag (full: TagDlgWznmUtlMrgip)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWznmUtlMrgipLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagMrg (full: TagDlgWznmUtlMrgipMrg)
		*/
	class TagMrg {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagRes (full: TagDlgWznmUtlMrgipRes)
		*/
	class TagRes {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagSrc (full: TagDlgWznmUtlMrgipSrc)
		*/
	class TagSrc {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagTrg (full: TagDlgWznmUtlMrgipTrg)
		*/
	class TagTrg {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmUtlMrgipData)
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
		* DpchAppDo (full: DpchAppDlgWznmUtlMrgipDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOMRG = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoMrg;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmUtlMrgipData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFLFI = 4;
		static const Sbecore::uint CONTINFMRG = 5;
		static const Sbecore::uint CONTINFRES = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHRLFI = 11;
		static const Sbecore::uint STATSHRMRG = 12;
		static const Sbecore::uint STATSHRRES = 13;
		static const Sbecore::uint STATSHRSRC = 14;
		static const Sbecore::uint STATSHRTRG = 15;
		static const Sbecore::uint TAG = 16;
		static const Sbecore::uint TAGLFI = 17;
		static const Sbecore::uint TAGMRG = 18;
		static const Sbecore::uint TAGRES = 19;
		static const Sbecore::uint TAGSRC = 20;
		static const Sbecore::uint TAGTRG = 21;
		static const Sbecore::uint ALL = 22;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfLfi* continflfi = NULL, ContInfMrg* continfmrg = NULL, ContInfRes* continfres = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrLfi* statshrlfi = NULL, StatShrMrg* statshrmrg = NULL, StatShrRes* statshrres = NULL, StatShrSrc* statshrsrc = NULL, StatShrTrg* statshrtrg = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfLfi continflfi;
		ContInfMrg continfmrg;
		ContInfRes continfres;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrLfi statshrlfi;
		StatShrMrg statshrmrg;
		StatShrRes statshrres;
		StatShrSrc statshrsrc;
		StatShrTrg statshrtrg;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalResDldActive(DbsWznm* dbswznm);
	bool evalLfiDldActive(DbsWznm* dbswznm);
	bool evalMrgButRunActive(DbsWznm* dbswznm);
	bool evalMrgButStoActive(DbsWznm* dbswznm);
	bool evalTrgUldActive(DbsWznm* dbswznm);
	bool evalSrcUldActive(DbsWznm* dbswznm);

public:
	DlgWznmUtlMrgip(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmUtlMrgip();

public:
	ContIac contiac;
	ContInf continf;
	ContInfLfi continflfi;
	ContInfMrg continfmrg;
	ContInfRes continfres;
	StatShr statshr;
	StatShrLfi statshrlfi;
	StatShrMrg statshrmrg;
	StatShrRes statshrres;
	StatShrSrc statshrsrc;
	StatShrTrg statshrtrg;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;
	std::string outfilename;

	std::string infolder;
	std::string infile;
	std::string outfolder;
	std::string outfile;

	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshSrc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTrg(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshMrg(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRes(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoMrgButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMrgButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	void handleUploadInSgeSuldone(DbsWznm* dbswznm, const std::string& filename);
	void handleUploadInSgeSupdone(DbsWznm* dbswznm, const std::string& filename);
	void handleUploadInSgeIdle(DbsWznm* dbswznm, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);
	std::string handleDownloadInSgeFail(DbsWznm* dbswznm);

	void handleDpchRetWznm(DbsWznm* dbswznm, DpchRetWznm* dpchret);
	void handleDpchRetWznmPrctreeMerge(DbsWznm* dbswznm, DpchRetWznmPrctreeMerge* dpchret);

	void handleTimerInSgeSupidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerInSgeTupidle(DbsWznm* dbswznm, const std::string& sref);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrmer(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrmer(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSupidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSupidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSrcunpack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSrcunpack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSupdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSupdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSuldone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSuldone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeTupidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeTupidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeTrgunpack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeTrgunpack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeTupdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeTupdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeTuldone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeTuldone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeMerge(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeMerge(DbsWznm* dbswznm);
	Sbecore::uint enterSgePack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeFail(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeFail(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
