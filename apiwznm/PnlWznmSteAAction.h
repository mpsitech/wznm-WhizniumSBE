/**
	* \file PnlWznmSteAAction.h
	* API code for job PnlWznmSteAAction (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMSTEAACTION_H
#define PNLWZNMSTEAACTION_H

#include "ApiWznm_blks.h"

#include "WznmQSteAAction.h"

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
namespace PnlWznmSteAAction {
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
	  * StatApp (full: StatAppWznmSteAAction)
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
	  * StatShr (full: StatShrWznmSteAAction)
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
	  * StgIac (full: StgIacWznmSteAAction)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWznmSteAAction)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOSCT = 7;
		static const Sbecore::uint TCOTYP = 8;
		static const Sbecore::uint TCOTRJ = 9;
		static const Sbecore::uint TCOVEC = 10;
		static const Sbecore::uint TCOVIT = 11;
		static const Sbecore::uint TCOSNX = 12;
		static const Sbecore::uint TCOSEQ = 13;
		static const Sbecore::uint TCOTR1 = 14;
		static const Sbecore::uint TCOIP1 = 15;
		static const Sbecore::uint TCOTR2 = 16;
		static const Sbecore::uint TCOIP2 = 17;
		static const Sbecore::uint TCOTR3 = 18;
		static const Sbecore::uint TCOIP3 = 19;
		static const Sbecore::uint TCOTR4 = 20;
		static const Sbecore::uint TCOIP4 = 21;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoSct = "", const std::string& TcoTyp = "", const std::string& TcoTrj = "", const std::string& TcoVec = "", const std::string& TcoVit = "", const std::string& TcoSnx = "", const std::string& TcoSeq = "", const std::string& TcoTr1 = "", const std::string& TcoIp1 = "", const std::string& TcoTr2 = "", const std::string& TcoIp2 = "", const std::string& TcoTr3 = "", const std::string& TcoIp3 = "", const std::string& TcoTr4 = "", const std::string& TcoIp4 = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoSct;
		std::string TcoTyp;
		std::string TcoTrj;
		std::string TcoVec;
		std::string TcoVit;
		std::string TcoSnx;
		std::string TcoSeq;
		std::string TcoTr1;
		std::string TcoIp1;
		std::string TcoTr2;
		std::string TcoIp2;
		std::string TcoTr3;
		std::string TcoIp3;
		std::string TcoTr4;
		std::string TcoIp4;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmSteAActionData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWznmSteAAction::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWznmSteAAction::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmSteAActionDo)
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
		* DpchEngData (full: DpchEngWznmSteAActionData)
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
		ListWznmQSteAAction rst;
		QryWznmSteAAction::StatApp statappqry;
		QryWznmSteAAction::StatShr statshrqry;
		QryWznmSteAAction::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
