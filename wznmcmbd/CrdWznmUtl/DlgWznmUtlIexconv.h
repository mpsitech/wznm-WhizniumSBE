/**
	* \file DlgWznmUtlIexconv.h
	* job handler for job DlgWznmUtlIexconv (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef DLGWZNMUTLIEXCONV_H
#define DLGWZNMUTLIEXCONV_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include <sys/types.h>
#include <dirent.h>
// IP include.cust --- IEND

#define VecVDlgWznmUtlIexconvDit DlgWznmUtlIexconv::VecVDit
#define VecVDlgWznmUtlIexconvDo DlgWznmUtlIexconv::VecVDo
#define VecVDlgWznmUtlIexconvDoCnv DlgWznmUtlIexconv::VecVDoCnv
#define VecVDlgWznmUtlIexconvSge DlgWznmUtlIexconv::VecVSge

#define ContIacDlgWznmUtlIexconv DlgWznmUtlIexconv::ContIac
#define ContInfDlgWznmUtlIexconv DlgWznmUtlIexconv::ContInf
#define ContInfDlgWznmUtlIexconvCnv DlgWznmUtlIexconv::ContInfCnv
#define ContInfDlgWznmUtlIexconvRes DlgWznmUtlIexconv::ContInfRes
#define StatAppDlgWznmUtlIexconv DlgWznmUtlIexconv::StatApp
#define StatShrDlgWznmUtlIexconv DlgWznmUtlIexconv::StatShr
#define StatShrDlgWznmUtlIexconvCnv DlgWznmUtlIexconv::StatShrCnv
#define StatShrDlgWznmUtlIexconvRes DlgWznmUtlIexconv::StatShrRes
#define StatShrDlgWznmUtlIexconvSrc DlgWznmUtlIexconv::StatShrSrc
#define TagDlgWznmUtlIexconv DlgWznmUtlIexconv::Tag
#define TagDlgWznmUtlIexconvCnv DlgWznmUtlIexconv::TagCnv
#define TagDlgWznmUtlIexconvRes DlgWznmUtlIexconv::TagRes
#define TagDlgWznmUtlIexconvSrc DlgWznmUtlIexconv::TagSrc

#define DpchAppDlgWznmUtlIexconvData DlgWznmUtlIexconv::DpchAppData
#define DpchAppDlgWznmUtlIexconvDo DlgWznmUtlIexconv::DpchAppDo
#define DpchEngDlgWznmUtlIexconvData DlgWznmUtlIexconv::DpchEngData

/**
	* DlgWznmUtlIexconv
	*/
class DlgWznmUtlIexconv : public JobWznm {

public:
	/**
		* VecVDit (full: VecVDlgWznmUtlIexconvDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint SRC = 1;
		static const Sbecore::uint CNV = 2;
		static const Sbecore::uint RES = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWznmUtlIexconvDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoCnv (full: VecVDlgWznmUtlIexconvDoCnv)
		*/
	class VecVDoCnv {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmUtlIexconvSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint UPKIDLE = 2;
		static const Sbecore::uint UNPACK = 3;
		static const Sbecore::uint UPKDONE = 4;
		static const Sbecore::uint ULDDONE = 5;
		static const Sbecore::uint CONV = 6;
		static const Sbecore::uint PACK = 7;
		static const Sbecore::uint DONE = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmUtlIexconv)
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
	  * ContInf (full: ContInfDlgWznmUtlIexconv)
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
	  * ContInfCnv (full: ContInfDlgWznmUtlIexconvCnv)
	  */
	class ContInfCnv : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfCnv(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfCnv* comp);
		std::set<Sbecore::uint> diff(const ContInfCnv* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWznmUtlIexconvRes)
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
		* StatApp (full: StatAppDlgWznmUtlIexconv)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmUtlIexconv)
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
		* StatShrCnv (full: StatShrDlgWznmUtlIexconvCnv)
		*/
	class StatShrCnv : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrCnv(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrCnv* comp);
		std::set<Sbecore::uint> diff(const StatShrCnv* comp);
	};

	/**
		* StatShrRes (full: StatShrDlgWznmUtlIexconvRes)
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
		* StatShrSrc (full: StatShrDlgWznmUtlIexconvSrc)
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
		* Tag (full: TagDlgWznmUtlIexconv)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagCnv (full: TagDlgWznmUtlIexconvCnv)
		*/
	class TagCnv {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagRes (full: TagDlgWznmUtlIexconvRes)
		*/
	class TagRes {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagSrc (full: TagDlgWznmUtlIexconvSrc)
		*/
	class TagSrc {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmUtlIexconvData)
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
		* DpchAppDo (full: DpchAppDlgWznmUtlIexconvDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOCNV = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoCnv;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmUtlIexconvData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFCNV = 4;
		static const Sbecore::uint CONTINFRES = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRCNV = 10;
		static const Sbecore::uint STATSHRRES = 11;
		static const Sbecore::uint STATSHRSRC = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGCNV = 14;
		static const Sbecore::uint TAGRES = 15;
		static const Sbecore::uint TAGSRC = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfCnv* continfcnv = NULL, ContInfRes* continfres = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrCnv* statshrcnv = NULL, StatShrRes* statshrres = NULL, StatShrSrc* statshrsrc = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfCnv continfcnv;
		ContInfRes continfres;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrCnv statshrcnv;
		StatShrRes statshrres;
		StatShrSrc statshrsrc;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWznm* dbswznm);
	bool evalResDldActive(DbsWznm* dbswznm);
	bool evalCnvButRunActive(DbsWznm* dbswznm);
	bool evalCnvButStoActive(DbsWznm* dbswznm);
	bool evalSrcUldActive(DbsWznm* dbswznm);

public:
	DlgWznmUtlIexconv(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmUtlIexconv();

public:
	ContIac contiac;
	ContInf continf;
	ContInfCnv continfcnv;
	ContInfRes continfres;
	StatShr statshr;
	StatShrCnv statshrcnv;
	StatShrRes statshrres;
	StatShrSrc statshrsrc;

	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;

	std::string infolder;
	std::string infile;
	std::string outfolder;
	std::string outfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshSrc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCnv(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRes(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleDpchAppDoCnvButRunClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoCnvButStoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

	void handleUploadInSgeIdle(DbsWznm* dbswznm, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWznm* dbswznm);

	void handleTimerInSgeUpkidle(DbsWznm* dbswznm, const std::string& sref);
	void handleTimerWithSrefMonInSgeConv(DbsWznm* dbswznm);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkidle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkidle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUnpack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUnpack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUpkdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUpkdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeUlddone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeUlddone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeConv(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeConv(DbsWznm* dbswznm);
	Sbecore::uint enterSgePack(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePack(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif


