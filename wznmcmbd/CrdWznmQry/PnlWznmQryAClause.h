/**
	* \file PnlWznmQryAClause.h
	* job handler for job PnlWznmQryAClause (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMQRYACLAUSE_H
#define PNLWZNMQRYACLAUSE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWznmQryAClause.h"

#define VecVWznmQryAClauseDo PnlWznmQryAClause::VecVDo

#define ContInfWznmQryAClause PnlWznmQryAClause::ContInf
#define StatAppWznmQryAClause PnlWznmQryAClause::StatApp
#define StatShrWznmQryAClause PnlWznmQryAClause::StatShr
#define StgIacWznmQryAClause PnlWznmQryAClause::StgIac
#define TagWznmQryAClause PnlWznmQryAClause::Tag

#define DpchAppWznmQryAClauseData PnlWznmQryAClause::DpchAppData
#define DpchAppWznmQryAClauseDo PnlWznmQryAClause::DpchAppDo
#define DpchEngWznmQryAClauseData PnlWznmQryAClause::DpchEngData

/**
	* PnlWznmQryAClause
	*/
class PnlWznmQryAClause : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmQryAClauseDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUPCLICK = 1;
		static const Sbecore::uint BUTDOWNCLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDUPLICATECLICK = 4;
		static const Sbecore::uint BUTDELETECLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmQryAClause)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmQryAClause)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmQryAClause)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTUPAVAIL = 1;
		static const Sbecore::uint BUTUPACTIVE = 2;
		static const Sbecore::uint BUTDOWNAVAIL = 3;
		static const Sbecore::uint BUTDOWNACTIVE = 4;
		static const Sbecore::uint BUTNEWAVAIL = 5;
		static const Sbecore::uint BUTDUPLICATEAVAIL = 6;
		static const Sbecore::uint BUTDUPLICATEACTIVE = 7;
		static const Sbecore::uint BUTDELETEAVAIL = 8;
		static const Sbecore::uint BUTDELETEACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWznmQryAClause)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOQMDWIDTH = 1;
		static const Sbecore::uint TCOTYPWIDTH = 2;
		static const Sbecore::uint TCOCSEWIDTH = 3;
		static const Sbecore::uint TCOPSTWIDTH = 4;
		static const Sbecore::uint TCOVECWIDTH = 5;
		static const Sbecore::uint TCOVITWIDTH = 6;

	public:
		StgIac(const Sbecore::uint TcoQmdWidth = 100, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoCseWidth = 100, const Sbecore::uint TcoPstWidth = 100, const Sbecore::uint TcoVecWidth = 100, const Sbecore::uint TcoVitWidth = 100);

	public:
		Sbecore::uint TcoQmdWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoCseWidth;
		Sbecore::uint TcoPstWidth;
		Sbecore::uint TcoVecWidth;
		Sbecore::uint TcoVitWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWznmQryAClause)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmQryAClauseData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryWznmQryAClause::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmQryAClauseDo)
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
		* DpchEngData (full: DpchEngWznmQryAClauseData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint STGIAC = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint RST = 8;
		static const Sbecore::uint STATAPPQRY = 9;
		static const Sbecore::uint STATSHRQRY = 10;
		static const Sbecore::uint STGIACQRY = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWznmQQryAClause* rst = NULL, QryWznmQryAClause::StatShr* statshrqry = NULL, QryWznmQryAClause::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListWznmQQryAClause rst;
		QryWznmQryAClause::StatShr statshrqry;
		QryWznmQryAClause::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButUpAvail(DbsWznm* dbswznm);
	bool evalButUpActive(DbsWznm* dbswznm);
	bool evalButDownAvail(DbsWznm* dbswznm);
	bool evalButDownActive(DbsWznm* dbswznm);
	bool evalButNewAvail(DbsWznm* dbswznm);
	bool evalButDuplicateAvail(DbsWznm* dbswznm);
	bool evalButDuplicateActive(DbsWznm* dbswznm);
	bool evalButDeleteAvail(DbsWznm* dbswznm);
	bool evalButDeleteActive(DbsWznm* dbswznm);

public:
	PnlWznmQryAClause(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmQryAClause();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Xmlio::Feed feedFCsiQst;

	QryWznmQryAClause* qry;

	WznmAMQueryClause recQryAcse;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataStgiac(DbsWznm* dbswznm, StgIac* _stgiac, DpchEngWznm** dpcheng);
	void handleDpchAppDataStgiacqry(DbsWznm* dbswznm, QryWznmQryAClause::StgIac* _stgiacqry, DpchEngWznm** dpcheng);

	void handleDpchAppDoButUpClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDownClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButNewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDuplicateClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmStatChg(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
