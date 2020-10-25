/**
	* \file DlgWznmPrjNew.h
	* job handler for job DlgWznmPrjNew (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef DLGWZNMPRJNEW_H
#define DLGWZNMPRJNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWznmLicense.h"

#define VecVDlgWznmPrjNewDo DlgWznmPrjNew::VecVDo
#define VecVDlgWznmPrjNewSge DlgWznmPrjNew::VecVSge

#define ContIacDlgWznmPrjNew DlgWznmPrjNew::ContIac
#define ContInfDlgWznmPrjNew DlgWznmPrjNew::ContInf
#define StatAppDlgWznmPrjNew DlgWznmPrjNew::StatApp
#define StatShrDlgWznmPrjNew DlgWznmPrjNew::StatShr
#define TagDlgWznmPrjNew DlgWznmPrjNew::Tag

#define DpchAppDlgWznmPrjNewData DlgWznmPrjNew::DpchAppData
#define DpchAppDlgWznmPrjNewDo DlgWznmPrjNew::DpchAppDo
#define DpchEngDlgWznmPrjNewData DlgWznmPrjNew::DpchEngData

/**
	* DlgWznmPrjNew
	*/
class DlgWznmPrjNew : public JobWznm {

public:
	/**
		* VecVDo (full: VecVDlgWznmPrjNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTAUTCLICK = 1;
		static const Sbecore::uint BUTCNCCLICK = 2;
		static const Sbecore::uint BUTCRECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmPrjNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint AUTH = 3;
		static const Sbecore::uint AUTDONE = 4;
		static const Sbecore::uint CREATE = 5;
		static const Sbecore::uint SYNC = 6;
		static const Sbecore::uint DONE = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmPrjNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DETTXFSHO = 1;
		static const Sbecore::uint DETTXFTIT = 2;

	public:
		ContIac(const std::string& DetTxfSho = "", const std::string& DetTxfTit = "");

	public:
		std::string DetTxfSho;
		std::string DetTxfTit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmPrjNew)
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
		* StatApp (full: StatAppDlgWznmPrjNew)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWznmPrjNew)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DETBUTAUTACTIVE = 1;
		static const Sbecore::uint BUTCNCACTIVE = 2;
		static const Sbecore::uint BUTCREACTIVE = 3;

	public:
		StatShr(const bool DetButAutActive = true, const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool DetButAutActive;
		bool ButCncActive;
		bool ButCreActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWznmPrjNew)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmPrjNewData)
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
		* DpchAppDo (full: DpchAppDlgWznmPrjNewDo)
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
		* DpchEngData (full: DpchEngDlgWznmPrjNewData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFSGE = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalDetButAutActive(DbsWznm* dbswznm);
	bool evalButCncActive(DbsWznm* dbswznm);
	bool evalButCreActive(DbsWznm* dbswznm);

public:
	DlgWznmPrjNew(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmPrjNew();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	JobWznmLicense* license;

	bool valid;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoDetButAutClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCncClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCreClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlraer(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlraer(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAuth(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAuth(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAutdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAutdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCreate(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCreate(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSync(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSync(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif

