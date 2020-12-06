/**
	* \file PnlWznmQcoList.h
	* job handler for job PnlWznmQcoList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMQCOLIST_H
#define PNLWZNMQCOLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWznmQcoList.h"

#define VecVWznmQcoListDo PnlWznmQcoList::VecVDo

#define ContIacWznmQcoList PnlWznmQcoList::ContIac
#define ContInfWznmQcoList PnlWznmQcoList::ContInf
#define StatShrWznmQcoList PnlWznmQcoList::StatShr
#define StgIacWznmQcoList PnlWznmQcoList::StgIac
#define TagWznmQcoList PnlWznmQcoList::Tag

#define DpchAppWznmQcoListData PnlWznmQcoList::DpchAppData
#define DpchAppWznmQcoListDo PnlWznmQcoList::DpchAppDo
#define DpchEngWznmQcoListData PnlWznmQcoList::DpchEngData

/**
	* PnlWznmQcoList
	*/
class PnlWznmQcoList : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmQcoListDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDELETECLICK = 4;
		static const Sbecore::uint BUTFILTERCLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmQcoList)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFTOS = 1;

	public:
		ContIac(const Sbecore::uint numFTos = 1);

	public:
		Sbecore::uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmQcoList)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTFOR = 1;
		static const Sbecore::uint TXTPRE = 2;
		static const Sbecore::uint BUTFILTERON = 3;
		static const Sbecore::uint NUMFCSIQST = 4;

	public:
		ContInf(const std::string& TxtFor = "", const std::string& TxtPre = "", const bool ButFilterOn = false, const Sbecore::uint numFCsiQst = 1);

	public:
		std::string TxtFor;
		std::string TxtPre;
		bool ButFilterOn;
		Sbecore::uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWznmQcoList)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWznmQcoList)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOSRFWIDTH = 1;
		static const Sbecore::uint TCOSHOWIDTH = 2;
		static const Sbecore::uint TCOTYPWIDTH = 3;
		static const Sbecore::uint TCOQRYWIDTH = 4;
		static const Sbecore::uint TCOTCOWIDTH = 5;

	public:
		StgIac(const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoShoWidth = 100, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoQryWidth = 100, const Sbecore::uint TcoTcoWidth = 100);

	public:
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoShoWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoQryWidth;
		Sbecore::uint TcoTcoWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWznmQcoList)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmQcoListData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWznmQcoList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmQcoListDo)
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
		* DpchEngData (full: DpchEngWznmQcoListData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFCSIQST = 4;
		static const Sbecore::uint FEEDFTOS = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint STGIAC = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint RST = 9;
		static const Sbecore::uint STATAPPQRY = 10;
		static const Sbecore::uint STATSHRQRY = 11;
		static const Sbecore::uint STGIACQRY = 12;
		static const Sbecore::uint ALL = 13;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFCsiQst = NULL, Sbecore::Xmlio::Feed* feedFTos = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWznmQQcoList* rst = NULL, QryWznmQcoList::StatShr* statshrqry = NULL, QryWznmQcoList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		Sbecore::Xmlio::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		ListWznmQQcoList rst;
		QryWznmQcoList::StatShr statshrqry;
		QryWznmQcoList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButDeleteActive(DbsWznm* dbswznm);

public:
	PnlWznmQcoList(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmQcoList();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Xmlio::Feed feedFCsiQst;
	Sbecore::Xmlio::Feed feedFTos;

	QryWznmQcoList* qry;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void minimize(DbsWznm* dbswznm, const bool notif = false, DpchEngWznm** dpcheng = NULL);
	void regularize(DbsWznm* dbswznm, const bool notif = false, DpchEngWznm** dpcheng = NULL);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);
	void handleDpchAppDataStgiac(DbsWznm* dbswznm, StgIac* _stgiac, DpchEngWznm** dpcheng);
	void handleDpchAppDataStgiacqry(DbsWznm* dbswznm, QryWznmQcoList::StgIac* _stgiacqry, DpchEngWznm** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButNewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButFilterClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmStatChg(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
