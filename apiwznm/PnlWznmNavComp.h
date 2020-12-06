/**
	* \file PnlWznmNavComp.h
	* API code for job PnlWznmNavComp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVCOMP_H
#define PNLWZNMNAVCOMP_H

#include "ApiWznm_blks.h"

#define VecVWznmNavCompDo PnlWznmNavComp::VecVDo

#define ContIacWznmNavComp PnlWznmNavComp::ContIac
#define StatAppWznmNavComp PnlWznmNavComp::StatApp
#define StatShrWznmNavComp PnlWznmNavComp::StatShr
#define TagWznmNavComp PnlWznmNavComp::Tag

#define DpchAppWznmNavCompData PnlWznmNavComp::DpchAppData
#define DpchAppWznmNavCompDo PnlWznmNavComp::DpchAppDo
#define DpchEngWznmNavCompData PnlWznmNavComp::DpchEngData

/**
	* PnlWznmNavComp
	*/
namespace PnlWznmNavComp {
	/**
		* VecVDo (full: VecVWznmNavCompDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTOPKVIEWCLICK = 1;
		static const Sbecore::uint BUTOPKNEWCRDCLICK = 2;
		static const Sbecore::uint BUTOPXVIEWCLICK = 3;
		static const Sbecore::uint BUTOPXNEWCRDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavComp)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTOPK = 1;
		static const Sbecore::uint NUMFLSTOPX = 2;

	public:
		ContIac(const Sbecore::uint numFLstOpk = 1, const Sbecore::uint numFLstOpx = 1);

	public:
		Sbecore::uint numFLstOpk;
		Sbecore::uint numFLstOpx;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNavComp)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTOPKALT = 2;
		static const Sbecore::uint LSTOPXALT = 3;
		static const Sbecore::uint LSTOPKNUMFIRSTDISP = 4;
		static const Sbecore::uint LSTOPXNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOpkAlt = true, const bool LstOpxAlt = true, const Sbecore::uint LstOpkNumFirstdisp = 1, const Sbecore::uint LstOpxNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstOpkAlt;
		bool LstOpxAlt;
		Sbecore::uint LstOpkNumFirstdisp;
		Sbecore::uint LstOpxNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavComp)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTOPKAVAIL = 1;
		static const Sbecore::uint BUTOPKVIEWACTIVE = 2;
		static const Sbecore::uint BUTOPKNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTOPXAVAIL = 4;
		static const Sbecore::uint BUTOPXVIEWACTIVE = 5;
		static const Sbecore::uint BUTOPXNEWCRDACTIVE = 6;

	public:
		StatShr(const bool LstOpkAvail = true, const bool ButOpkViewActive = true, const bool ButOpkNewcrdActive = true, const bool LstOpxAvail = true, const bool ButOpxViewActive = true, const bool ButOpxNewcrdActive = true);

	public:
		bool LstOpkAvail;
		bool ButOpkViewActive;
		bool ButOpkNewcrdActive;
		bool LstOpxAvail;
		bool ButOpxViewActive;
		bool ButOpxNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavComp)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTOPK = 2;
		static const Sbecore::uint CPTOPX = 3;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptOpk = "", const std::string& CptOpx = "");

	public:
		std::string Cpt;
		std::string CptOpk;
		std::string CptOpx;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavCompData)
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
		* DpchAppDo (full: DpchAppWznmNavCompDo)
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
		* DpchEngData (full: DpchEngWznmNavCompData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTOPK = 3;
		static const Sbecore::uint FEEDFLSTOPX = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstOpk;
		Sbecore::Xmlio::Feed feedFLstOpx;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
