/**
	* \file PnlWznmNavVisual.h
	* API code for job PnlWznmNavVisual (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVVISUAL_H
#define PNLWZNMNAVVISUAL_H

#include "ApiWznm_blks.h"

#define VecVWznmNavVisualDo PnlWznmNavVisual::VecVDo

#define ContIacWznmNavVisual PnlWznmNavVisual::ContIac
#define StatAppWznmNavVisual PnlWznmNavVisual::StatApp
#define StatShrWznmNavVisual PnlWznmNavVisual::StatShr
#define TagWznmNavVisual PnlWznmNavVisual::Tag

#define DpchAppWznmNavVisualData PnlWznmNavVisual::DpchAppData
#define DpchAppWznmNavVisualDo PnlWznmNavVisual::DpchAppDo
#define DpchEngWznmNavVisualData PnlWznmNavVisual::DpchEngData

/**
	* PnlWznmNavVisual
	*/
namespace PnlWznmNavVisual {
	/**
		* VecVDo (full: VecVWznmNavVisualDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTVISVIEWCLICK = 1;
		static const Sbecore::uint BUTVISNEWCRDCLICK = 2;
		static const Sbecore::uint BUTSHTVIEWCLICK = 3;
		static const Sbecore::uint BUTSHTNEWCRDCLICK = 4;
		static const Sbecore::uint BUTBOXVIEWCLICK = 5;
		static const Sbecore::uint BUTBOXNEWCRDCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavVisual)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTVIS = 1;
		static const Sbecore::uint NUMFLSTSHT = 2;
		static const Sbecore::uint NUMFLSTBOX = 3;

	public:
		ContIac(const Sbecore::uint numFLstVis = 1, const Sbecore::uint numFLstSht = 1, const Sbecore::uint numFLstBox = 1);

	public:
		Sbecore::uint numFLstVis;
		Sbecore::uint numFLstSht;
		Sbecore::uint numFLstBox;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNavVisual)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTVISALT = 2;
		static const Sbecore::uint LSTSHTALT = 3;
		static const Sbecore::uint LSTBOXALT = 4;
		static const Sbecore::uint LSTVISNUMFIRSTDISP = 5;
		static const Sbecore::uint LSTSHTNUMFIRSTDISP = 6;
		static const Sbecore::uint LSTBOXNUMFIRSTDISP = 7;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstVisAlt = true, const bool LstShtAlt = true, const bool LstBoxAlt = true, const Sbecore::uint LstVisNumFirstdisp = 1, const Sbecore::uint LstShtNumFirstdisp = 1, const Sbecore::uint LstBoxNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstVisAlt;
		bool LstShtAlt;
		bool LstBoxAlt;
		Sbecore::uint LstVisNumFirstdisp;
		Sbecore::uint LstShtNumFirstdisp;
		Sbecore::uint LstBoxNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavVisual)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTVISAVAIL = 1;
		static const Sbecore::uint BUTVISVIEWACTIVE = 2;
		static const Sbecore::uint LSTSHTAVAIL = 3;
		static const Sbecore::uint BUTSHTVIEWACTIVE = 4;
		static const Sbecore::uint BUTSHTNEWCRDACTIVE = 5;
		static const Sbecore::uint LSTBOXAVAIL = 6;
		static const Sbecore::uint BUTBOXVIEWACTIVE = 7;
		static const Sbecore::uint BUTBOXNEWCRDACTIVE = 8;

	public:
		StatShr(const bool LstVisAvail = true, const bool ButVisViewActive = true, const bool LstShtAvail = true, const bool ButShtViewActive = true, const bool ButShtNewcrdActive = true, const bool LstBoxAvail = true, const bool ButBoxViewActive = true, const bool ButBoxNewcrdActive = true);

	public:
		bool LstVisAvail;
		bool ButVisViewActive;
		bool LstShtAvail;
		bool ButShtViewActive;
		bool ButShtNewcrdActive;
		bool LstBoxAvail;
		bool ButBoxViewActive;
		bool ButBoxNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavVisual)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTVIS = 2;
		static const Sbecore::uint CPTSHT = 3;
		static const Sbecore::uint CPTBOX = 4;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptVis = "", const std::string& CptSht = "", const std::string& CptBox = "");

	public:
		std::string Cpt;
		std::string CptVis;
		std::string CptSht;
		std::string CptBox;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavVisualData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavVisualDo)
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
		* DpchEngData (full: DpchEngWznmNavVisualData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTBOX = 3;
		static const Sbecore::uint FEEDFLSTSHT = 4;
		static const Sbecore::uint FEEDFLSTVIS = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstBox;
		Sbecore::Feed feedFLstSht;
		Sbecore::Feed feedFLstVis;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
