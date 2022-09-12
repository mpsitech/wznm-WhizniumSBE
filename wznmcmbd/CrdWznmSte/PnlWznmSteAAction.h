/**
	* \file PnlWznmSteAAction.h
	* job handler for job PnlWznmSteAAction (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMSTEAACTION_H
#define PNLWZNMSTEAACTION_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWznmSteAAction.h"

#define VecVWznmSteAActionDo PnlWznmSteAAction::VecVDo

#define ContInfWznmSteAAction PnlWznmSteAAction::ContInf
#define StatAppWznmSteAAction PnlWznmSteAAction::StatApp
#define StatShrWznmSteAAction PnlWznmSteAAction::StatShr
#define StgIacWznmSteAAction PnlWznmSteAAction::StgIac
#define TagWznmSteAAction PnlWznmSteAAction::Tag

#define DpchAppWznmSteAActionData PnlWznmSteAAction::DpchAppData
#define DpchAppWznmSteAActionDo PnlWznmSteAAction::DpchAppDo
#define DpchEngWznmSteAActionData PnlWznmSteAAction::DpchEngData

/**
	* PnlWznmSteAAction
	*/
class PnlWznmSteAAction : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmSteAActionDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTNEWCLICK = 1;
		static const Sbecore::uint BUTDUPLICATECLICK = 2;
		static const Sbecore::uint BUTDELETECLICK = 3;
		static const Sbecore::uint BUTREFRESHCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmSteAAction)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmSteAAction)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmSteAAction)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTNEWAVAIL = 1;
		static const Sbecore::uint BUTDUPLICATEAVAIL = 2;
		static const Sbecore::uint BUTDUPLICATEACTIVE = 3;
		static const Sbecore::uint BUTDELETEAVAIL = 4;
		static const Sbecore::uint BUTDELETEACTIVE = 5;

	public:
		StatShr(const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWznmSteAAction)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOSCTWIDTH = 1;
		static const Sbecore::uint TCOTYPWIDTH = 2;
		static const Sbecore::uint TCOTRJWIDTH = 3;
		static const Sbecore::uint TCOVECWIDTH = 4;
		static const Sbecore::uint TCOVITWIDTH = 5;
		static const Sbecore::uint TCOSNXWIDTH = 6;
		static const Sbecore::uint TCOSEQWIDTH = 7;
		static const Sbecore::uint TCOTR1WIDTH = 8;
		static const Sbecore::uint TCOIP1WIDTH = 9;
		static const Sbecore::uint TCOTR2WIDTH = 10;
		static const Sbecore::uint TCOIP2WIDTH = 11;
		static const Sbecore::uint TCOTR3WIDTH = 12;
		static const Sbecore::uint TCOIP3WIDTH = 13;
		static const Sbecore::uint TCOTR4WIDTH = 14;
		static const Sbecore::uint TCOIP4WIDTH = 15;

	public:
		StgIac(const Sbecore::uint TcoSctWidth = 100, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoTrjWidth = 100, const Sbecore::uint TcoVecWidth = 100, const Sbecore::uint TcoVitWidth = 100, const Sbecore::uint TcoSnxWidth = 100, const Sbecore::uint TcoSeqWidth = 100, const Sbecore::uint TcoTr1Width = 100, const Sbecore::uint TcoIp1Width = 100, const Sbecore::uint TcoTr2Width = 100, const Sbecore::uint TcoIp2Width = 100, const Sbecore::uint TcoTr3Width = 100, const Sbecore::uint TcoIp3Width = 100, const Sbecore::uint TcoTr4Width = 100, const Sbecore::uint TcoIp4Width = 100);

	public:
		Sbecore::uint TcoSctWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoTrjWidth;
		Sbecore::uint TcoVecWidth;
		Sbecore::uint TcoVitWidth;
		Sbecore::uint TcoSnxWidth;
		Sbecore::uint TcoSeqWidth;
		Sbecore::uint TcoTr1Width;
		Sbecore::uint TcoIp1Width;
		Sbecore::uint TcoTr2Width;
		Sbecore::uint TcoIp2Width;
		Sbecore::uint TcoTr3Width;
		Sbecore::uint TcoIp3Width;
		Sbecore::uint TcoTr4Width;
		Sbecore::uint TcoIp4Width;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWznmSteAAction)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmSteAActionData)
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
		QryWznmSteAAction::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmSteAActionDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmSteAActionData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWznmQSteAAction* rst = NULL, QryWznmSteAAction::StatShr* statshrqry = NULL, QryWznmSteAAction::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListWznmQSteAAction rst;
		QryWznmSteAAction::StatShr statshrqry;
		QryWznmSteAAction::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButNewAvail(DbsWznm* dbswznm);
	bool evalButDuplicateAvail(DbsWznm* dbswznm);
	bool evalButDuplicateActive(DbsWznm* dbswznm);
	bool evalButDeleteAvail(DbsWznm* dbswznm);
	bool evalButDeleteActive(DbsWznm* dbswznm);

public:
	PnlWznmSteAAction(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmSteAAction();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFCsiQst;

	QryWznmSteAAction* qry;

	WznmAMStateAction recSteAact;

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
	void handleDpchAppDataStgiacqry(DbsWznm* dbswznm, QryWznmSteAAction::StgIac* _stgiacqry, DpchEngWznm** dpcheng);

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
