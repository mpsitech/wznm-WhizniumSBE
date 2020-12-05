/**
	* \file PnlWznmTblALoadfct.h
	* API code for job PnlWznmTblALoadfct (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMTBLALOADFCT_H
#define PNLWZNMTBLALOADFCT_H

#include "ApiWznm_blks.h"

#include "WznmQTblALoadfct.h"

#include "QryWznmTblALoadfct.h"

#define VecVWznmTblALoadfctDo PnlWznmTblALoadfct::VecVDo

#define ContInfWznmTblALoadfct PnlWznmTblALoadfct::ContInf
#define StatAppWznmTblALoadfct PnlWznmTblALoadfct::StatApp
#define StatShrWznmTblALoadfct PnlWznmTblALoadfct::StatShr
#define StgIacWznmTblALoadfct PnlWznmTblALoadfct::StgIac
#define TagWznmTblALoadfct PnlWznmTblALoadfct::Tag

#define DpchAppWznmTblALoadfctData PnlWznmTblALoadfct::DpchAppData
#define DpchAppWznmTblALoadfctDo PnlWznmTblALoadfct::DpchAppDo
#define DpchEngWznmTblALoadfctData PnlWznmTblALoadfct::DpchEngData

/**
	* PnlWznmTblALoadfct
	*/
namespace PnlWznmTblALoadfct {
	/**
		* VecVDo (full: VecVWznmTblALoadfctDo)
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
	  * ContInf (full: ContInfWznmTblALoadfct)
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
	  * StatApp (full: StatAppWznmTblALoadfct)
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
	  * StatShr (full: StatShrWznmTblALoadfct)
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
	  * StgIac (full: StgIacWznmTblALoadfct)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOLOTWIDTH = 1;
		static const Sbecore::uint TCOFNAWIDTH = 2;
		static const Sbecore::uint TCOLDXWIDTH = 3;
		static const Sbecore::uint TCOLBYWIDTH = 4;
		static const Sbecore::uint TCOORDWIDTH = 5;
		static const Sbecore::uint TCOLITWIDTH = 6;

	public:
		StgIac(const Sbecore::uint TcoLotWidth = 100, const Sbecore::uint TcoFnaWidth = 100, const Sbecore::uint TcoLdxWidth = 100, const Sbecore::uint TcoLbyWidth = 100, const Sbecore::uint TcoOrdWidth = 100, const Sbecore::uint TcoLitWidth = 100);

	public:
		Sbecore::uint TcoLotWidth;
		Sbecore::uint TcoFnaWidth;
		Sbecore::uint TcoLdxWidth;
		Sbecore::uint TcoLbyWidth;
		Sbecore::uint TcoOrdWidth;
		Sbecore::uint TcoLitWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWznmTblALoadfct)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOLOT = 7;
		static const Sbecore::uint TCOFNA = 8;
		static const Sbecore::uint TCOLDX = 9;
		static const Sbecore::uint TCOLBY = 10;
		static const Sbecore::uint TCOORD = 11;
		static const Sbecore::uint TCOLIT = 12;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoLot = "", const std::string& TcoFna = "", const std::string& TcoLdx = "", const std::string& TcoLby = "", const std::string& TcoOrd = "", const std::string& TcoLit = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoLot;
		std::string TcoFna;
		std::string TcoLdx;
		std::string TcoLby;
		std::string TcoOrd;
		std::string TcoLit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmTblALoadfctData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWznmTblALoadfct::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWznmTblALoadfct::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmTblALoadfctDo)
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
		* DpchEngData (full: DpchEngWznmTblALoadfctData)
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
		ListWznmQTblALoadfct rst;
		QryWznmTblALoadfct::StatApp statappqry;
		QryWznmTblALoadfct::StatShr statshrqry;
		QryWznmTblALoadfct::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

