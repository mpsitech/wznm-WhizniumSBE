/**
	* \file PnlWznmRel1NTablecol.h
	* job handler for job PnlWznmRel1NTablecol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMREL1NTABLECOL_H
#define PNLWZNMREL1NTABLECOL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWznmRel1NTablecol.h"

#define VecVWznmRel1NTablecolDo PnlWznmRel1NTablecol::VecVDo

#define ContInfWznmRel1NTablecol PnlWznmRel1NTablecol::ContInf
#define StatAppWznmRel1NTablecol PnlWznmRel1NTablecol::StatApp
#define StgIacWznmRel1NTablecol PnlWznmRel1NTablecol::StgIac
#define TagWznmRel1NTablecol PnlWznmRel1NTablecol::Tag

#define DpchAppWznmRel1NTablecolData PnlWznmRel1NTablecol::DpchAppData
#define DpchAppWznmRel1NTablecolDo PnlWznmRel1NTablecol::DpchAppDo
#define DpchEngWznmRel1NTablecolData PnlWznmRel1NTablecol::DpchEngData

/**
	* PnlWznmRel1NTablecol
	*/
class PnlWznmRel1NTablecol : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmRel1NTablecolDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREFRESHCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmRel1NTablecol)
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
		* StatApp (full: StatAppWznmRel1NTablecol)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StgIac (full: StgIacWznmRel1NTablecol)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOREFWIDTH = 1;

	public:
		StgIac(const Sbecore::uint TcoRefWidth = 100);

	public:
		Sbecore::uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWznmRel1NTablecol)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmRel1NTablecolData)
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
		QryWznmRel1NTablecol::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmRel1NTablecolDo)
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
		* DpchEngData (full: DpchEngWznmRel1NTablecolData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STGIAC = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint RST = 7;
		static const Sbecore::uint STATAPPQRY = 8;
		static const Sbecore::uint STATSHRQRY = 9;
		static const Sbecore::uint STGIACQRY = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFCsiQst = NULL, StgIac* stgiac = NULL, ListWznmQRel1NTablecol* rst = NULL, QryWznmRel1NTablecol::StatShr* statshrqry = NULL, QryWznmRel1NTablecol::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		StgIac stgiac;
		ListWznmQRel1NTablecol rst;
		QryWznmRel1NTablecol::StatShr statshrqry;
		QryWznmRel1NTablecol::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

public:
	PnlWznmRel1NTablecol(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmRel1NTablecol();

public:
	ContInf continf;
	StgIac stgiac;

	Sbecore::Xmlio::Feed feedFCsiQst;

	QryWznmRel1NTablecol* qry;

	WznmMTablecol recTco;
	Sbecore::uint ixWSubsetTco;

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
	void handleDpchAppDataStgiacqry(DbsWznm* dbswznm, QryWznmRel1NTablecol::StgIac* _stgiacqry, DpchEngWznm** dpcheng);

	void handleDpchAppDoButRefreshClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmStatChg(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
