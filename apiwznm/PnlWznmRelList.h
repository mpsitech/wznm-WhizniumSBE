/**
	* \file PnlWznmRelList.h
	* API code for job PnlWznmRelList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMRELLIST_H
#define PNLWZNMRELLIST_H

#include "ApiWznm_blks.h"

#include "WznmQRelList.h"

#include "QryWznmRelList.h"

#define VecVWznmRelListDo PnlWznmRelList::VecVDo

#define ContIacWznmRelList PnlWznmRelList::ContIac
#define ContInfWznmRelList PnlWznmRelList::ContInf
#define StatShrWznmRelList PnlWznmRelList::StatShr
#define StgIacWznmRelList PnlWznmRelList::StgIac
#define TagWznmRelList PnlWznmRelList::Tag

#define DpchAppWznmRelListData PnlWznmRelList::DpchAppData
#define DpchAppWznmRelListDo PnlWznmRelList::DpchAppDo
#define DpchEngWznmRelListData PnlWznmRelList::DpchEngData

/**
	* PnlWznmRelList
	*/
namespace PnlWznmRelList {
	/**
		* VecVDo (full: VecVWznmRelListDo)
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
	  * ContIac (full: ContIacWznmRelList)
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
	  * ContInf (full: ContInfWznmRelList)
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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWznmRelList)
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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWznmRelList)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOFRTWIDTH = 1;
		static const Sbecore::uint TCOFRSWIDTH = 2;
		static const Sbecore::uint TCOTOTWIDTH = 3;
		static const Sbecore::uint TCOTOSWIDTH = 4;
		static const Sbecore::uint TCOTYPWIDTH = 5;
		static const Sbecore::uint TCOVERWIDTH = 6;
		static const Sbecore::uint TCOSUPWIDTH = 7;
		static const Sbecore::uint TCOSRLWIDTH = 8;
		static const Sbecore::uint TCOTBLWIDTH = 9;
		static const Sbecore::uint TCOPFXWIDTH = 10;

	public:
		StgIac(const Sbecore::uint TcoFrtWidth = 100, const Sbecore::uint TcoFrsWidth = 100, const Sbecore::uint TcoTotWidth = 100, const Sbecore::uint TcoTosWidth = 100, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoVerWidth = 100, const Sbecore::uint TcoSupWidth = 100, const Sbecore::uint TcoSrlWidth = 100, const Sbecore::uint TcoTblWidth = 100, const Sbecore::uint TcoPfxWidth = 100);

	public:
		Sbecore::uint TcoFrtWidth;
		Sbecore::uint TcoFrsWidth;
		Sbecore::uint TcoTotWidth;
		Sbecore::uint TcoTosWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoVerWidth;
		Sbecore::uint TcoSupWidth;
		Sbecore::uint TcoSrlWidth;
		Sbecore::uint TcoTblWidth;
		Sbecore::uint TcoPfxWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWznmRelList)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTFOR = 2;
		static const Sbecore::uint TXTRECORD1 = 3;
		static const Sbecore::uint TXTRECORD2 = 4;
		static const Sbecore::uint TRS = 5;
		static const Sbecore::uint TXTSHOWING1 = 6;
		static const Sbecore::uint TXTSHOWING2 = 7;
		static const Sbecore::uint TCOFRT = 8;
		static const Sbecore::uint TCOFRS = 9;
		static const Sbecore::uint TCOTOT = 10;
		static const Sbecore::uint TCOTOS = 11;
		static const Sbecore::uint TCOTYP = 12;
		static const Sbecore::uint TCOVER = 13;
		static const Sbecore::uint TCOSUP = 14;
		static const Sbecore::uint TCOSRL = 15;
		static const Sbecore::uint TCOTBL = 16;
		static const Sbecore::uint TCOPFX = 17;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtFor = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoFrt = "", const std::string& TcoFrs = "", const std::string& TcoTot = "", const std::string& TcoTos = "", const std::string& TcoTyp = "", const std::string& TcoVer = "", const std::string& TcoSup = "", const std::string& TcoSrl = "", const std::string& TcoTbl = "", const std::string& TcoPfx = "");

	public:
		std::string Cpt;
		std::string TxtFor;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoFrt;
		std::string TcoFrs;
		std::string TcoTot;
		std::string TcoTos;
		std::string TcoTyp;
		std::string TcoVer;
		std::string TcoSup;
		std::string TcoSrl;
		std::string TcoTbl;
		std::string TcoPfx;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmRelListData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWznmRelList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWznmRelList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmRelListDo)
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
		* DpchEngData (full: DpchEngWznmRelListData)
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
		Sbecore::Xmlio::Feed feedFCsiQst;
		Sbecore::Xmlio::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWznmQRelList rst;
		QryWznmRelList::StatApp statappqry;
		QryWznmRelList::StatShr statshrqry;
		QryWznmRelList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

