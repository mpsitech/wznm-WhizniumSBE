/**
	* \file PnlWznmSteAStep.h
	* API code for job PnlWznmSteAStep (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMSTEASTEP_H
#define PNLWZNMSTEASTEP_H

#include "ApiWznm_blks.h"

#include "WznmQSteAStep.h"

#include "QryWznmSteAStep.h"

#define VecVWznmSteAStepDo PnlWznmSteAStep::VecVDo

#define ContInfWznmSteAStep PnlWznmSteAStep::ContInf
#define StatAppWznmSteAStep PnlWznmSteAStep::StatApp
#define StatShrWznmSteAStep PnlWznmSteAStep::StatShr
#define StgIacWznmSteAStep PnlWznmSteAStep::StgIac
#define TagWznmSteAStep PnlWznmSteAStep::Tag

#define DpchAppWznmSteAStepData PnlWznmSteAStep::DpchAppData
#define DpchAppWznmSteAStepDo PnlWznmSteAStep::DpchAppDo
#define DpchEngWznmSteAStepData PnlWznmSteAStep::DpchEngData

/**
	* PnlWznmSteAStep
	*/
namespace PnlWznmSteAStep {
	/**
		* VecVDo (full: VecVWznmSteAStepDo)
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
	  * ContInf (full: ContInfWznmSteAStep)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmSteAStep)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);

	public:
		Sbecore::uint ixWznmVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmSteAStep)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWznmSteAStep)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOSNXWIDTH = 1;
		static const Sbecore::uint TCOTRGWIDTH = 2;
		static const Sbecore::uint TCORTJWIDTH = 3;
		static const Sbecore::uint TCOVITWIDTH = 4;
		static const Sbecore::uint TCOXSRWIDTH = 5;
		static const Sbecore::uint TCORTDWIDTH = 6;
		static const Sbecore::uint TCOMSKWIDTH = 7;
		static const Sbecore::uint TCOCNDWIDTH = 8;
		static const Sbecore::uint TCOCCDWIDTH = 9;

	public:
		StgIac(const Sbecore::uint TcoSnxWidth = 100, const Sbecore::uint TcoTrgWidth = 100, const Sbecore::uint TcoRtjWidth = 100, const Sbecore::uint TcoVitWidth = 100, const Sbecore::uint TcoXsrWidth = 100, const Sbecore::uint TcoRtdWidth = 100, const Sbecore::uint TcoMskWidth = 100, const Sbecore::uint TcoCndWidth = 100, const Sbecore::uint TcoCcdWidth = 100);

	public:
		Sbecore::uint TcoSnxWidth;
		Sbecore::uint TcoTrgWidth;
		Sbecore::uint TcoRtjWidth;
		Sbecore::uint TcoVitWidth;
		Sbecore::uint TcoXsrWidth;
		Sbecore::uint TcoRtdWidth;
		Sbecore::uint TcoMskWidth;
		Sbecore::uint TcoCndWidth;
		Sbecore::uint TcoCcdWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWznmSteAStep)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOSNX = 7;
		static const Sbecore::uint TCOTRG = 8;
		static const Sbecore::uint TCORTJ = 9;
		static const Sbecore::uint TCOVIT = 10;
		static const Sbecore::uint TCOXSR = 11;
		static const Sbecore::uint TCORTD = 12;
		static const Sbecore::uint TCOMSK = 13;
		static const Sbecore::uint TCOCND = 14;
		static const Sbecore::uint TCOCCD = 15;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoSnx = "", const std::string& TcoTrg = "", const std::string& TcoRtj = "", const std::string& TcoVit = "", const std::string& TcoXsr = "", const std::string& TcoRtd = "", const std::string& TcoMsk = "", const std::string& TcoCnd = "", const std::string& TcoCcd = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoSnx;
		std::string TcoTrg;
		std::string TcoRtj;
		std::string TcoVit;
		std::string TcoXsr;
		std::string TcoRtd;
		std::string TcoMsk;
		std::string TcoCnd;
		std::string TcoCcd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmSteAStepData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWznmSteAStep::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWznmSteAStep::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmSteAStepDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngWznmSteAStepData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
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

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWznmQSteAStep rst;
		QryWznmSteAStep::StatApp statappqry;
		QryWznmSteAStep::StatShr statshrqry;
		QryWznmSteAStep::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

