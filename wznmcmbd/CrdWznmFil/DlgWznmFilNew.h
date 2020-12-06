/**
	* \file DlgWznmFilNew.h
	* job handler for job DlgWznmFilNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMFILNEW_H
#define DLGWZNMFILNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWznmFilNewDit DlgWznmFilNew::VecVDit
#define VecVDlgWznmFilNewDo DlgWznmFilNew::VecVDo
#define VecVDlgWznmFilNewDoDet DlgWznmFilNew::VecVDoDet
#define VecVDlgWznmFilNewSge DlgWznmFilNew::VecVSge

#define ContIacDlgWznmFilNew DlgWznmFilNew::ContIac
#define ContIacDlgWznmFilNewDet DlgWznmFilNew::ContIacDet
#define ContInfDlgWznmFilNew DlgWznmFilNew::ContInf
#define StatAppDlgWznmFilNew DlgWznmFilNew::StatApp
#define StatShrDlgWznmFilNew DlgWznmFilNew::StatShr
#define StatShrDlgWznmFilNewDet DlgWznmFilNew::StatShrDet
#define StatShrDlgWznmFilNewFil DlgWznmFilNew::StatShrFil
#define TagDlgWznmFilNew DlgWznmFilNew::Tag
#define TagDlgWznmFilNewDet DlgWznmFilNew::TagDet
#define TagDlgWznmFilNewFil DlgWznmFilNew::TagFil

#define DpchAppDlgWznmFilNewData DlgWznmFilNew::DpchAppData
#define DpchAppDlgWznmFilNewDo DlgWznmFilNew::DpchAppDo
#define DpchEngDlgWznmFilNewData DlgWznmFilNew::DpchEngData

/**
	* DlgWznmFilNew
	*/
class DlgWznmFilNew : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmFilNewDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint FIL = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmFilNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgWznmFilNewDoDet)
		*/
	class VecVDoDet {

	public:
		static const Sbecore::uint BUTCRECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmFilNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint CREDONE = 3;
		static const Sbecore::uint DONE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmFilNew)
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
	  * ContIacDet (full: ContIacDlgWznmFilNewDet)
	  */
	class ContIacDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFFNM = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint TXFREU = 3;
		static const Sbecore::uint NUMFPUPCNT = 4;
		static const Sbecore::uint NUMFPUPMIM = 5;
		static const Sbecore::uint TXFCMT = 6;

	public:
		ContIacDet(const std::string& TxfFnm = "", const Sbecore::uint numFPupRet = 1, const std::string& TxfReu = "", const Sbecore::uint numFPupCnt = 1, const Sbecore::uint numFPupMim = 1, const std::string& TxfCmt = "");

	public:
		std::string TxfFnm;
		Sbecore::uint numFPupRet;
		std::string TxfReu;
		Sbecore::uint numFPupCnt;
		Sbecore::uint numFPupMim;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmFilNew)
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
		* StatApp (full: StatAppDlgWznmFilNew)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmFilNew)
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
		* StatShrDet (full: StatShrDlgWznmFilNewDet)
		*/
	class StatShrDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCREACTIVE = 1;

	public:
		StatShrDet(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrDet* comp);
		std::set<Sbecore::uint> diff(const StatShrDet* comp);
	};

	/**
		* StatShrFil (full: StatShrDlgWznmFilNewFil)
		*/
	class StatShrFil : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrFil(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFil* comp);
		std::set<Sbecore::uint> diff(const StatShrFil* comp);
	};

	/**
		* Tag (full: TagDlgWznmFilNew)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgWznmFilNewDet)
		*/
	class TagDet {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFil (full: TagDlgWznmFilNewFil)
		*/
	class TagFil {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmFilNewData)
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
		* DpchAppDo (full: DpchAppDlgWznmFilNewDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDODET = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoDet;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmFilNewData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint FEEDFDETPUPCNT = 5;
		static const Sbecore::uint FEEDFDETPUPMIM = 6;
		static const Sbecore::uint FEEDFDETPUPRET = 7;
		static const Sbecore::uint FEEDFDSE = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint STATSHRDET = 12;
		static const Sbecore::uint STATSHRFIL = 13;
		static const Sbecore::uint TAG = 14;
		static const Sbecore::uint TAGDET = 15;
		static const Sbecore::uint TAGFIL = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFDetPupCnt = NULL, Sbecore::Xmlio::Feed* feedFDetPupMim = NULL, Sbecore::Xmlio::Feed* feedFDetPupRet = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrDet* statshrdet = NULL, StatShrFil* statshrfil = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetPupCnt;
		Sbecore::Xmlio::Feed feedFDetPupMim;
		Sbecore::Xmlio::Feed feedFDetPupRet;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrDet statshrdet;
		StatShrFil statshrfil;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalDetButCreActive(DbsWznm* dbswznm);
	bool evalFilUldActive(DbsWznm* dbswznm);

public:
	DlgWznmFilNew(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmFilNew();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	StatShr statshr;
	StatShrDet statshrdet;
	StatShrFil statshrfil;

	Sbecore::Xmlio::Feed feedFDetPupCnt;
	Sbecore::Xmlio::Feed feedFDetPupMim;
	Sbecore::Xmlio::Feed feedFDetPupRet;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	bool valid;

	// IP vars.cust --- IBEGIN
	std::string infilename;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	Sbecore::ubigint getRefApp(DbsWznm* dbswznm, const std::string& s);
	Sbecore::ubigint getRefVer(DbsWznm* dbswznm, const std::string& s);
	// IP cust --- IEND

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshFil(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiacdet(DbsWznm* dbswznm, ContIacDet* _contiacdet, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoDetButCreClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleUploadInSgeCredone(DbsWznm* dbswznm, const std::string& filename);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCreate(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCreate(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCredone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCredone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
