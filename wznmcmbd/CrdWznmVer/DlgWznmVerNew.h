/**
	* \file DlgWznmVerNew.h
	* job handler for job DlgWznmVerNew (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef DLGWZNMVERNEW_H
#define DLGWZNMVERNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWznmIexPrj.h"

#define VecVDlgWznmVerNewDo DlgWznmVerNew::VecVDo
#define VecVDlgWznmVerNewSge DlgWznmVerNew::VecVSge
#define VecVDlgWznmVerNewVni DlgWznmVerNew::VecVVni

#define ContIacDlgWznmVerNew DlgWznmVerNew::ContIac
#define ContInfDlgWznmVerNew DlgWznmVerNew::ContInf
#define StatAppDlgWznmVerNew DlgWznmVerNew::StatApp
#define StatShrDlgWznmVerNew DlgWznmVerNew::StatShr
#define TagDlgWznmVerNew DlgWznmVerNew::Tag

#define DpchAppDlgWznmVerNewData DlgWznmVerNew::DpchAppData
#define DpchAppDlgWznmVerNewDo DlgWznmVerNew::DpchAppDo
#define DpchEngDlgWznmVerNewData DlgWznmVerNew::DpchEngData

/**
	* DlgWznmVerNew
	*/
class DlgWznmVerNew : public JobWznm {

public:
	/**
		* VecVDo (full: VecVDlgWznmVerNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVerNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVVni (full: VecVDlgWznmVerNewVni)
		*/
	class VecVVni {

	public:
		static const Sbecore::uint MAJ = 1;
		static const Sbecore::uint MIN = 2;
		static const Sbecore::uint SUB = 3;
		static const Sbecore::uint VOID = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVerNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDETPUPPRJ = 1;
		static const Sbecore::uint NUMFDETPUPBVR = 2;
		static const Sbecore::uint NUMFDETRBUVNI = 3;
		static const Sbecore::uint DETTXFCMT = 4;
		static const Sbecore::uint NUMSFDETLSTLOC = 5;
		static const Sbecore::uint NUMFDETPUPPLC = 6;

	public:
		ContIac(const Sbecore::uint numFDetPupPrj = 1, const Sbecore::uint numFDetPupBvr = 1, const Sbecore::uint numFDetRbuVni = 1, const std::string& DetTxfCmt = "", const std::vector<Sbecore::uint>& numsFDetLstLoc = {}, const Sbecore::uint numFDetPupPlc = 1);

	public:
		Sbecore::uint numFDetPupPrj;
		Sbecore::uint numFDetPupBvr;
		Sbecore::uint numFDetRbuVni;
		std::string DetTxfCmt;
		std::vector<Sbecore::uint> numsFDetLstLoc;
		Sbecore::uint numFDetPupPlc;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmVerNew)
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
		* StatApp (full: StatAppDlgWznmVerNew)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "", const Sbecore::uint DetLstLocNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrDlgWznmVerNew)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCREACTIVE = 1;

	public:
		StatShr(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWznmVerNew)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVerNewData)
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
		* DpchAppDo (full: DpchAppDlgWznmVerNewDo)
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
		* DpchEngData (full: DpchEngDlgWznmVerNewData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETLSTLOC = 4;
		static const Sbecore::uint FEEDFDETPUPBVR = 5;
		static const Sbecore::uint FEEDFDETPUPPLC = 6;
		static const Sbecore::uint FEEDFDETPUPPRJ = 7;
		static const Sbecore::uint FEEDFDETRBUVNI = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint ALL = 13;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFDetLstLoc = NULL, Sbecore::Xmlio::Feed* feedFDetPupBvr = NULL, Sbecore::Xmlio::Feed* feedFDetPupPlc = NULL, Sbecore::Xmlio::Feed* feedFDetPupPrj = NULL, Sbecore::Xmlio::Feed* feedFDetRbuVni = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetLstLoc;
		Sbecore::Xmlio::Feed feedFDetPupBvr;
		Sbecore::Xmlio::Feed feedFDetPupPlc;
		Sbecore::Xmlio::Feed feedFDetPupPrj;
		Sbecore::Xmlio::Feed feedFDetRbuVni;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButCreActive(DbsWznm* dbswznm);

public:
	DlgWznmVerNew(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmVerNew();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFDetLstLoc;
	Sbecore::Xmlio::Feed feedFDetPupBvr;
	Sbecore::Xmlio::Feed feedFDetPupPlc;
	Sbecore::Xmlio::Feed feedFDetPupPrj;
	Sbecore::Xmlio::Feed feedFDetRbuVni;
	Sbecore::Xmlio::Feed feedFSge;

	JobWznmIexPrj* iexprj;

	bool valid;

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	void refreshDetBvr(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshDetLstLoc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshDetPupPlc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshDetPlc(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	// IP cust --- IEND

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButCncClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCreClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCreate(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCreate(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif


