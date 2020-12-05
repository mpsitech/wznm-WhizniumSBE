/**
	* \file PnlWznmOpkMNComponent.h
	* job handler for job PnlWznmOpkMNComponent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMOPKMNCOMPONENT_H
#define PNLWZNMOPKMNCOMPONENT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWznmOpkMNComponent.h"

#define VecVWznmOpkMNComponentDo PnlWznmOpkMNComponent::VecVDo

#define ContInfWznmOpkMNComponent PnlWznmOpkMNComponent::ContInf
#define StatAppWznmOpkMNComponent PnlWznmOpkMNComponent::StatApp
#define StatShrWznmOpkMNComponent PnlWznmOpkMNComponent::StatShr
#define StgIacWznmOpkMNComponent PnlWznmOpkMNComponent::StgIac
#define TagWznmOpkMNComponent PnlWznmOpkMNComponent::Tag

#define DpchAppWznmOpkMNComponentData PnlWznmOpkMNComponent::DpchAppData
#define DpchAppWznmOpkMNComponentDo PnlWznmOpkMNComponent::DpchAppDo
#define DpchEngWznmOpkMNComponentData PnlWznmOpkMNComponent::DpchEngData

/**
	* PnlWznmOpkMNComponent
	*/
class PnlWznmOpkMNComponent : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmOpkMNComponentDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTADDCLICK = 1;
		static const Sbecore::uint BUTSUBCLICK = 2;
		static const Sbecore::uint BUTREFRESHCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmOpkMNComponent)
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
		* StatApp (full: StatAppWznmOpkMNComponent)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmOpkMNComponent)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTADDAVAIL = 1;
		static const Sbecore::uint BUTSUBAVAIL = 2;
		static const Sbecore::uint BUTSUBACTIVE = 3;

	public:
		StatShr(const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWznmOpkMNComponent)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOMREFWIDTH = 1;

	public:
		StgIac(const Sbecore::uint TcoMrefWidth = 100);

	public:
		Sbecore::uint TcoMrefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWznmOpkMNComponent)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmOpkMNComponentData)
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
		QryWznmOpkMNComponent::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmOpkMNComponentDo)
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
		* DpchEngData (full: DpchEngWznmOpkMNComponentData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWznmQOpkMNComponent* rst = NULL, QryWznmOpkMNComponent::StatShr* statshrqry = NULL, QryWznmOpkMNComponent::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListWznmQOpkMNComponent rst;
		QryWznmOpkMNComponent::StatShr statshrqry;
		QryWznmOpkMNComponent::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButAddAvail(DbsWznm* dbswznm);
	bool evalButSubAvail(DbsWznm* dbswznm);
	bool evalButSubActive(DbsWznm* dbswznm);

public:
	PnlWznmOpkMNComponent(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmOpkMNComponent();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Xmlio::Feed feedFCsiQst;

	QryWznmOpkMNComponent* qry;

	WznmRMComponentMOppack recCmpRopk;

	WznmMComponent recCmp;
	Sbecore::uint ixWSubsetCmp;

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
	void handleDpchAppDataStgiacqry(DbsWznm* dbswznm, QryWznmOpkMNComponent::StgIac* _stgiacqry, DpchEngWznm** dpcheng);

	void handleDpchAppDoButAddClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSubClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmStatChg(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif



