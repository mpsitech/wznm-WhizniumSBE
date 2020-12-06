/**
	* \file PnlWznmBlkAItem.h
	* API code for job PnlWznmBlkAItem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMBLKAITEM_H
#define PNLWZNMBLKAITEM_H

#include "ApiWznm_blks.h"

#include "WznmQBlkAItem.h"

#include "QryWznmBlkAItem.h"

#define VecVWznmBlkAItemDo PnlWznmBlkAItem::VecVDo

#define ContInfWznmBlkAItem PnlWznmBlkAItem::ContInf
#define StatAppWznmBlkAItem PnlWznmBlkAItem::StatApp
#define StatShrWznmBlkAItem PnlWznmBlkAItem::StatShr
#define StgIacWznmBlkAItem PnlWznmBlkAItem::StgIac
#define TagWznmBlkAItem PnlWznmBlkAItem::Tag

#define DpchAppWznmBlkAItemData PnlWznmBlkAItem::DpchAppData
#define DpchAppWznmBlkAItemDo PnlWznmBlkAItem::DpchAppDo
#define DpchEngWznmBlkAItemData PnlWznmBlkAItem::DpchEngData

/**
	* PnlWznmBlkAItem
	*/
namespace PnlWznmBlkAItem {
	/**
		* VecVDo (full: VecVWznmBlkAItemDo)
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
	  * ContInf (full: ContInfWznmBlkAItem)
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
	  * StatApp (full: StatAppWznmBlkAItem)
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
	  * StatShr (full: StatShrWznmBlkAItem)
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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWznmBlkAItem)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOTYPWIDTH = 1;
		static const Sbecore::uint TCOSRFWIDTH = 2;
		static const Sbecore::uint TCOVTYWIDTH = 3;
		static const Sbecore::uint TCOCONWIDTH = 4;
		static const Sbecore::uint TCOVECWIDTH = 5;
		static const Sbecore::uint TCOFEDWIDTH = 6;
		static const Sbecore::uint TCOTBLWIDTH = 7;
		static const Sbecore::uint TCOBL2WIDTH = 8;
		static const Sbecore::uint TCODFVWIDTH = 9;
		static const Sbecore::uint TCOVITWIDTH = 10;
		static const Sbecore::uint TCOCMTWIDTH = 11;

	public:
		StgIac(const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoVtyWidth = 100, const Sbecore::uint TcoConWidth = 100, const Sbecore::uint TcoVecWidth = 100, const Sbecore::uint TcoFedWidth = 100, const Sbecore::uint TcoTblWidth = 100, const Sbecore::uint TcoBl2Width = 100, const Sbecore::uint TcoDfvWidth = 100, const Sbecore::uint TcoVitWidth = 100, const Sbecore::uint TcoCmtWidth = 100);

	public:
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoVtyWidth;
		Sbecore::uint TcoConWidth;
		Sbecore::uint TcoVecWidth;
		Sbecore::uint TcoFedWidth;
		Sbecore::uint TcoTblWidth;
		Sbecore::uint TcoBl2Width;
		Sbecore::uint TcoDfvWidth;
		Sbecore::uint TcoVitWidth;
		Sbecore::uint TcoCmtWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWznmBlkAItem)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOTYP = 7;
		static const Sbecore::uint TCOSRF = 8;
		static const Sbecore::uint TCOVTY = 9;
		static const Sbecore::uint TCOCON = 10;
		static const Sbecore::uint TCOVEC = 11;
		static const Sbecore::uint TCOFED = 12;
		static const Sbecore::uint TCOTBL = 13;
		static const Sbecore::uint TCOBL2 = 14;
		static const Sbecore::uint TCODFV = 15;
		static const Sbecore::uint TCOVIT = 16;
		static const Sbecore::uint TCOCMT = 17;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoTyp = "", const std::string& TcoSrf = "", const std::string& TcoVty = "", const std::string& TcoCon = "", const std::string& TcoVec = "", const std::string& TcoFed = "", const std::string& TcoTbl = "", const std::string& TcoBl2 = "", const std::string& TcoDfv = "", const std::string& TcoVit = "", const std::string& TcoCmt = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoTyp;
		std::string TcoSrf;
		std::string TcoVty;
		std::string TcoCon;
		std::string TcoVec;
		std::string TcoFed;
		std::string TcoTbl;
		std::string TcoBl2;
		std::string TcoDfv;
		std::string TcoVit;
		std::string TcoCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmBlkAItemData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWznmBlkAItem::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWznmBlkAItem::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmBlkAItemDo)
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
		* DpchEngData (full: DpchEngWznmBlkAItemData)
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
		ListWznmQBlkAItem rst;
		QryWznmBlkAItem::StatApp statappqry;
		QryWznmBlkAItem::StatShr statshrqry;
		QryWznmBlkAItem::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
