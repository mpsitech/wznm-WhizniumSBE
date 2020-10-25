/**
	* \file DlgWznmUtlExtrip.h
	* job handler for job DlgWznmUtlExtrip (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef DLGWZNMUTLEXTRIP_H
#define DLGWZNMUTLEXTRIP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWznmUtlExtripDit DlgWznmUtlExtrip::VecVDit
#define VecVDlgWznmUtlExtripDo DlgWznmUtlExtrip::VecVDo
#define VecVDlgWznmUtlExtripDoExt DlgWznmUtlExtrip::VecVDoExt
#define VecVDlgWznmUtlExtripSge DlgWznmUtlExtrip::VecVSge

#define ContIacDlgWznmUtlExtrip DlgWznmUtlExtrip::ContIac
#define ContInfDlgWznmUtlExtrip DlgWznmUtlExtrip::ContInf
#define ContInfDlgWznmUtlExtripExt DlgWznmUtlExtrip::ContInfExt
#define ContInfDlgWznmUtlExtripLfi DlgWznmUtlExtrip::ContInfLfi
#define ContInfDlgWznmUtlExtripRes DlgWznmUtlExtrip::ContInfRes
#define StatAppDlgWznmUtlExtrip DlgWznmUtlExtrip::StatApp
#define StatShrDlgWznmUtlExtrip DlgWznmUtlExtrip::StatShr
#define StatShrDlgWznmUtlExtripExt DlgWznmUtlExtrip::StatShrExt
#define StatShrDlgWznmUtlExtripLfi DlgWznmUtlExtrip::StatShrLfi
#define StatShrDlgWznmUtlExtripRes DlgWznmUtlExtrip::StatShrRes
#define StatShrDlgWznmUtlExtripSrc DlgWznmUtlExtrip::StatShrSrc
#define TagDlgWznmUtlExtrip DlgWznmUtlExtrip::Tag
#define TagDlgWznmUtlExtripExt DlgWznmUtlExtrip::TagExt
#define TagDlgWznmUtlExtripLfi DlgWznmUtlExtrip::TagLfi
#define TagDlgWznmUtlExtripRes DlgWznmUtlExtrip::TagRes
#define TagDlgWznmUtlExtripSrc DlgWznmUtlExtrip::TagSrc

#define DpchAppDlgWznmUtlExtripData DlgWznmUtlExtrip::DpchAppData
#define DpchAppDlgWznmUtlExtripDo DlgWznmUtlExtrip::DpchAppDo
#define DpchEngDlgWznmUtlExtripData DlgWznmUtlExtrip::DpchEngData

/**
	* DlgWznmUtlExtrip
	*/
class DlgWznmUtlExtrip : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmUtlExtripDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint SRC = 1;
		static const Sbecore::uint EXT = 2;
		static const Sbecore::uint LFI = 3;
		static const Sbecore::uint RES = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmUtlExtripDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoExt (full: VecVDlgWznmUtlExtripDoExt)
		*/
	class VecVDoExt {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmUtlExtripSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRXER = 2;
		static const Sbecore::uint UPKIDLE = 3;
		static const Sbecore::uint UNPACK = 4;
		static const Sbecore::uint UPKDONE = 5;
		static const Sbecore::uint ULDDONE = 6;
		static const Sbecore::uint SRCVLD = 7;
		static const Sbecore::uint ALRVER = 8;
		static const Sbecore::uint VLDDONE = 9;
		static const Sbecore::uint EXTRACT = 10;
		static const Sbecore::uint PACK = 11;
		static const Sbecore::uint FAIL = 12;
		static const Sbecore::uint DONE = 13;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmUtlExtrip)
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
	  * ContInf (full: ContInfDlgWznmUtlExtrip)
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
	  * ContInfExt (full: ContInfDlgWznmUtlExtripExt)
	  */
	class ContInfExt : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfExt(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfExt* comp);
		std::set<Sbecore::uint> diff(const ContInfExt* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmUtlExtripLfi)
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
	  * ContInfRes (full: ContInfDlgWznmUtlExtripRes)
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
		* StatApp (full: StatAppDlgWznmUtlExtrip)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmUtlExtrip)
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
		* StatShrExt (full: StatShrDlgWznmUtlExtripExt)
		*/
	class StatShrExt : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrExt(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrExt* comp);
		std::set<Sbecore::uint> diff(const StatShrExt* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWznmUtlExtripLfi)
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
		* StatShrRes (full: StatShrDlgWznmUtlExtripRes)
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
		* StatShrSrc (full: StatShrDlgWznmUtlExtripSrc)
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
		* Tag (full: TagDlgWznmUtlExtrip)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagExt (full: TagDlgWznmUtlExtripExt)
		*/
	class TagExt {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWznmUtlExtripLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagRes (full: TagDlgWznmUtlExtripRes)
		*/
	class TagRes {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagSrc (full: TagDlgWznmUtlExtripSrc)
		*/
	class TagSrc {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmUtlExtripData)
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
		* DpchAppDo (full: DpchAppDlgWznmUtlExtripDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOEXT = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoExt;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmUtlExtripData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFEXT = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint CONTINFRES = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHREXT = 11;
		static const Sbecore::uint STATSHRLFI = 12;
		static const Sbecore::uint STATSHRRES = 13;
		static const Sbecore::uint STATSHRSRC = 14;
		static const Sbecore::uint TAG = 15;
		static const Sbecore::uint TAGEXT = 16;
		static const Sbecore::uint TAGLFI = 17;
		static const Sbecore::uint TAGRES = 18;
		static const Sbecore::uint TAGSRC = 19;
		static const Sbecore::uint ALL = 20;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfExt* continfext = NULL, ContInfLfi* continflfi = NULL, ContInfRes* continfres = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrExt* statshrext = NULL, StatShrLfi* statshrlfi = NULL, StatShrRes* statshrres = NULL, StatShrSrc* statshrsrc = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfExt continfext;
		ContInfLfi continflfi;
		ContInfRes continfres;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrExt statshrext;
		StatShrLfi statshrlfi;
		StatShrRes statshrres;
		StatShrSrc statshrsrc;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalResDldActive(DbsWznm* dbswznm);
	bool evalLfiDldActive(DbsWznm* dbswznm);
	bool evalExtButRunActive(DbsWznm* dbswznm);
	bool evalExtButStoActive(DbsWznm* dbswznm);
	bool evalSrcUldActive(DbsWznm* dbswznm);

public:
	DlgWznmUtlExtrip(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmUtlExtrip();

public:
	ContIac contiac;
	ContInf continf;
	ContInfExt continfext;
	ContInfLfi continflfi;
	ContInfRes continfres;
	StatShr statshr;
	StatShrExt statshrext;
	StatShrLfi statshrlfi;
	StatShrRes statshrres;
	StatShrSrc statshrsrc;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;

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
	void refreshExt(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRes(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoExtButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoExtButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	void handleUploadInSgeIdle(DbsWznm* dbswznm, const std::string& filename);

	std::string handleDownloadInSgeFail(DbsWznm* dbswznm);
	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);

	void handleDpchRetWznm(DbsWznm* dbswznm, DpchRetWznm* dpchret);
	void handleDpchRetWznmPrctreeExtract(DbsWznm* dbswznm, DpchRetWznmPrctreeExtract* dpchret);

	void handleTimerInSgeUpkidle(DbsWznm* dbswznm, const std::string& sref);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrxer(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrxer(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUnpack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUnpack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUlddone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUlddone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSrcvld(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSrcvld(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrver(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrver(DbsWznm* dbswznm);
	Sbecore::uint enterSgeVlddone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeVlddone(DbsWznm* dbswznm);
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


