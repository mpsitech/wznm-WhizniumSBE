/**
	* \file DlgWznmAppWrite.h
	* job handler for job DlgWznmAppWrite (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef DLGWZNMAPPWRITE_H
#define DLGWZNMAPPWRITE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWznmAppWriteDit DlgWznmAppWrite::VecVDit
#define VecVDlgWznmAppWriteDo DlgWznmAppWrite::VecVDo
#define VecVDlgWznmAppWriteDoWrc DlgWznmAppWrite::VecVDoWrc
#define VecVDlgWznmAppWriteSge DlgWznmAppWrite::VecVSge

#define ContIacDlgWznmAppWrite DlgWznmAppWrite::ContIac
#define ContIacDlgWznmAppWriteDet DlgWznmAppWrite::ContIacDet
#define ContInfDlgWznmAppWrite DlgWznmAppWrite::ContInf
#define ContInfDlgWznmAppWriteFia DlgWznmAppWrite::ContInfFia
#define ContInfDlgWznmAppWriteLfi DlgWznmAppWrite::ContInfLfi
#define ContInfDlgWznmAppWriteWrc DlgWznmAppWrite::ContInfWrc
#define StatAppDlgWznmAppWrite DlgWznmAppWrite::StatApp
#define StatShrDlgWznmAppWrite DlgWznmAppWrite::StatShr
#define StatShrDlgWznmAppWriteCuc DlgWznmAppWrite::StatShrCuc
#define StatShrDlgWznmAppWriteFia DlgWznmAppWrite::StatShrFia
#define StatShrDlgWznmAppWriteLfi DlgWznmAppWrite::StatShrLfi
#define StatShrDlgWznmAppWriteWrc DlgWznmAppWrite::StatShrWrc
#define TagDlgWznmAppWrite DlgWznmAppWrite::Tag
#define TagDlgWznmAppWriteCuc DlgWznmAppWrite::TagCuc
#define TagDlgWznmAppWriteDet DlgWznmAppWrite::TagDet
#define TagDlgWznmAppWriteFia DlgWznmAppWrite::TagFia
#define TagDlgWznmAppWriteLfi DlgWznmAppWrite::TagLfi
#define TagDlgWznmAppWriteWrc DlgWznmAppWrite::TagWrc

#define DpchAppDlgWznmAppWriteData DlgWznmAppWrite::DpchAppData
#define DpchAppDlgWznmAppWriteDo DlgWznmAppWrite::DpchAppDo
#define DpchEngDlgWznmAppWriteData DlgWznmAppWrite::DpchEngData

/**
	* DlgWznmAppWrite
	*/
class DlgWznmAppWrite : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmAppWriteDit)
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
		* VecVDo (full: VecVDlgWznmAppWriteDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWrc (full: VecVDlgWznmAppWriteDoWrc)
		*/
	class VecVDoWrc {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmAppWriteSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRMER = 2;
		static const Sbecore::uint UPKIDLE = 3;
		static const Sbecore::uint UNPACK = 4;
		static const Sbecore::uint UPKDONE = 5;
		static const Sbecore::uint WRITE = 6;
		static const Sbecore::uint MRGGNR = 7;
		static const Sbecore::uint MRGCUST = 8;
		static const Sbecore::uint PACK = 9;
		static const Sbecore::uint FAIL = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmAppWrite)
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
	  * ContIacDet (full: ContIacDlgWznmAppWriteDet)
	  */
	class ContIacDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CHKUSF = 1;

	public:
		ContIacDet(const bool ChkUsf = false);

	public:
		bool ChkUsf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmAppWrite)
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
	  * ContInfFia (full: ContInfDlgWznmAppWriteFia)
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
	  * ContInfLfi (full: ContInfDlgWznmAppWriteLfi)
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
	  * ContInfWrc (full: ContInfDlgWznmAppWriteWrc)
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
		* StatApp (full: StatAppDlgWznmAppWrite)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmAppWrite)
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
		* StatShrCuc (full: StatShrDlgWznmAppWriteCuc)
		*/
	class StatShrCuc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrCuc(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrCuc* comp);
		std::set<Sbecore::uint> diff(const StatShrCuc* comp);
	};

	/**
		* StatShrFia (full: StatShrDlgWznmAppWriteFia)
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
		* StatShrLfi (full: StatShrDlgWznmAppWriteLfi)
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
		* StatShrWrc (full: StatShrDlgWznmAppWriteWrc)
		*/
	class StatShrWrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrWrc(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrWrc* comp);
		std::set<Sbecore::uint> diff(const StatShrWrc* comp);
	};

	/**
		* Tag (full: TagDlgWznmAppWrite)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagCuc (full: TagDlgWznmAppWriteCuc)
		*/
	class TagCuc {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgWznmAppWriteDet)
		*/
	class TagDet {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgWznmAppWriteFia)
		*/
	class TagFia {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWznmAppWriteLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagWrc (full: TagDlgWznmAppWriteWrc)
		*/
	class TagWrc {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmAppWriteData)
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
		* DpchAppDo (full: DpchAppDlgWznmAppWriteDo)
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
		* DpchEngData (full: DpchEngDlgWznmAppWriteData)
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

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalFiaDldActive(DbsWznm* dbswznm);
	bool evalLfiDldActive(DbsWznm* dbswznm);
	bool evalWrcButRunActive(DbsWznm* dbswznm);
	bool evalWrcButStoActive(DbsWznm* dbswznm);
	bool evalCucUldActive(DbsWznm* dbswznm);

public:
	DlgWznmAppWrite(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmAppWrite();

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

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string PRJSHORT;
	std::string Prjshort;
	std::string prjshort;

	Sbecore::uint ixApptarget;

	std::string APPSHORT;
	std::string Appshort;
	std::string appshort;

	std::string infilename;
	std::string outfolder; // working directory
	std::string ipfolder; // IP's
	std::string custfolder; // custom IP's

	std::string logaspect;
	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void createCxx(DbsWznm* dbswznm);
	void createJava(DbsWznm* dbswznm);
	// IP cust --- IEND

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCuc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshWrc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshFia(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiacdet(DbsWznm* dbswznm, ContIacDet* _contiacdet, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoWrcButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoWrcButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

	void handleUploadInSgeIdle(DbsWznm* dbswznm, const std::string& filename);

	std::string handleDownloadInSgeFail(DbsWznm* dbswznm);
	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);

	void handleDpchRetWznmPrctreeMerge(DbsWznm* dbswznm, DpchRetWznmPrctreeMerge* dpchret);

	void handleTimerWithSrefMonInSgeWrite(DbsWznm* dbswznm);
	void handleTimerInSgeUpkidle(DbsWznm* dbswznm, const std::string& sref);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrmer(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrmer(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUnpack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUnpack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeWrite(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeWrite(DbsWznm* dbswznm);
	Sbecore::uint enterSgeMrggnr(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeMrggnr(DbsWznm* dbswznm);
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


