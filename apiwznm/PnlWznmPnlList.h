/**
	* \file PnlWznmPnlList.h
	* API code for job PnlWznmPnlList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMPNLLIST_H
#define PNLWZNMPNLLIST_H

#include "ApiWznm_blks.h"

#include "WznmQPnlList.h"

#include "QryWznmPnlList.h"

#define VecVWznmPnlListDo PnlWznmPnlList::VecVDo

#define ContIacWznmPnlList PnlWznmPnlList::ContIac
#define ContInfWznmPnlList PnlWznmPnlList::ContInf
#define StatShrWznmPnlList PnlWznmPnlList::StatShr
#define StgIacWznmPnlList PnlWznmPnlList::StgIac
#define TagWznmPnlList PnlWznmPnlList::Tag

#define DpchAppWznmPnlListData PnlWznmPnlList::DpchAppData
#define DpchAppWznmPnlListDo PnlWznmPnlList::DpchAppDo
#define DpchEngWznmPnlListData PnlWznmPnlList::DpchEngData

/**
	* PnlWznmPnlList
	*/
namespace PnlWznmPnlList {
	/**
		* VecVDo (full: VecVWznmPnlListDo)
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
	  * ContIac (full: ContIacWznmPnlList)
	  */
	class ContIac : public Sbecore::Block {

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
	  * ContInf (full: ContInfWznmPnlList)
	  */
	class ContInf : public Sbecore::Block {

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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWznmPnlList)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWznmPnlList)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOSRFWIDTH = 1;
		static const Sbecore::uint TCOTYPWIDTH = 2;
		static const Sbecore::uint TCOCARWIDTH = 3;
		static const Sbecore::uint TCORETWIDTH = 4;
		static const Sbecore::uint TCOREUWIDTH = 5;

	public:
		StgIac(const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoCarWidth = 100, const Sbecore::uint TcoRetWidth = 100, const Sbecore::uint TcoReuWidth = 100);

	public:
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoCarWidth;
		Sbecore::uint TcoRetWidth;
		Sbecore::uint TcoReuWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWznmPnlList)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTFOR = 2;
		static const Sbecore::uint TXTRECORD1 = 3;
		static const Sbecore::uint TXTRECORD2 = 4;
		static const Sbecore::uint TRS = 5;
		static const Sbecore::uint TXTSHOWING1 = 6;
		static const Sbecore::uint TXTSHOWING2 = 7;
		static const Sbecore::uint TCOSRF = 8;
		static const Sbecore::uint TCOTYP = 9;
		static const Sbecore::uint TCOCAR = 10;
		static const Sbecore::uint TCORET = 11;
		static const Sbecore::uint TCOREU = 12;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtFor = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoSrf = "", const std::string& TcoTyp = "", const std::string& TcoCar = "", const std::string& TcoRet = "", const std::string& TcoReu = "");

	public:
		std::string Cpt;
		std::string TxtFor;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoSrf;
		std::string TcoTyp;
		std::string TcoCar;
		std::string TcoRet;
		std::string TcoReu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmPnlListData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWznmPnlList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWznmPnlList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmPnlListDo)
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
		* DpchEngData (full: DpchEngWznmPnlListData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
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

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		Sbecore::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWznmQPnlList rst;
		QryWznmPnlList::StatApp statappqry;
		QryWznmPnlList::StatShr statshrqry;
		QryWznmPnlList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
