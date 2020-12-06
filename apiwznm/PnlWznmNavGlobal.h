/**
	* \file PnlWznmNavGlobal.h
	* API code for job PnlWznmNavGlobal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVGLOBAL_H
#define PNLWZNMNAVGLOBAL_H

#include "ApiWznm_blks.h"

#define VecVWznmNavGlobalDo PnlWznmNavGlobal::VecVDo

#define ContIacWznmNavGlobal PnlWznmNavGlobal::ContIac
#define StatAppWznmNavGlobal PnlWznmNavGlobal::StatApp
#define StatShrWznmNavGlobal PnlWznmNavGlobal::StatShr
#define TagWznmNavGlobal PnlWznmNavGlobal::Tag

#define DpchAppWznmNavGlobalData PnlWznmNavGlobal::DpchAppData
#define DpchAppWznmNavGlobalDo PnlWznmNavGlobal::DpchAppDo
#define DpchEngWznmNavGlobalData PnlWznmNavGlobal::DpchEngData

/**
	* PnlWznmNavGlobal
	*/
namespace PnlWznmNavGlobal {
	/**
		* VecVDo (full: VecVWznmNavGlobalDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTLOCVIEWCLICK = 1;
		static const Sbecore::uint BUTLOCNEWCRDCLICK = 2;
		static const Sbecore::uint BUTTAGVIEWCLICK = 3;
		static const Sbecore::uint BUTTAGNEWCRDCLICK = 4;
		static const Sbecore::uint BUTCTPVIEWCLICK = 5;
		static const Sbecore::uint BUTCTPNEWCRDCLICK = 6;
		static const Sbecore::uint BUTMCHVIEWCLICK = 7;
		static const Sbecore::uint BUTMCHNEWCRDCLICK = 8;
		static const Sbecore::uint BUTLIBVIEWCLICK = 9;
		static const Sbecore::uint BUTLIBNEWCRDCLICK = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavGlobal)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTLOC = 1;
		static const Sbecore::uint NUMFLSTTAG = 2;
		static const Sbecore::uint NUMFLSTCTP = 3;
		static const Sbecore::uint NUMFLSTMCH = 4;
		static const Sbecore::uint NUMFLSTLIB = 5;

	public:
		ContIac(const Sbecore::uint numFLstLoc = 1, const Sbecore::uint numFLstTag = 1, const Sbecore::uint numFLstCtp = 1, const Sbecore::uint numFLstMch = 1, const Sbecore::uint numFLstLib = 1);

	public:
		Sbecore::uint numFLstLoc;
		Sbecore::uint numFLstTag;
		Sbecore::uint numFLstCtp;
		Sbecore::uint numFLstMch;
		Sbecore::uint numFLstLib;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNavGlobal)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTLOCALT = 2;
		static const Sbecore::uint LSTTAGALT = 3;
		static const Sbecore::uint LSTCTPALT = 4;
		static const Sbecore::uint LSTMCHALT = 5;
		static const Sbecore::uint LSTLIBALT = 6;
		static const Sbecore::uint LSTLOCNUMFIRSTDISP = 7;
		static const Sbecore::uint LSTTAGNUMFIRSTDISP = 8;
		static const Sbecore::uint LSTCTPNUMFIRSTDISP = 9;
		static const Sbecore::uint LSTMCHNUMFIRSTDISP = 10;
		static const Sbecore::uint LSTLIBNUMFIRSTDISP = 11;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstLocAlt = true, const bool LstTagAlt = true, const bool LstCtpAlt = true, const bool LstMchAlt = true, const bool LstLibAlt = true, const Sbecore::uint LstLocNumFirstdisp = 1, const Sbecore::uint LstTagNumFirstdisp = 1, const Sbecore::uint LstCtpNumFirstdisp = 1, const Sbecore::uint LstMchNumFirstdisp = 1, const Sbecore::uint LstLibNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstLocAlt;
		bool LstTagAlt;
		bool LstCtpAlt;
		bool LstMchAlt;
		bool LstLibAlt;
		Sbecore::uint LstLocNumFirstdisp;
		Sbecore::uint LstTagNumFirstdisp;
		Sbecore::uint LstCtpNumFirstdisp;
		Sbecore::uint LstMchNumFirstdisp;
		Sbecore::uint LstLibNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavGlobal)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTLOCAVAIL = 1;
		static const Sbecore::uint BUTLOCVIEWACTIVE = 2;
		static const Sbecore::uint LSTTAGAVAIL = 3;
		static const Sbecore::uint BUTTAGVIEWACTIVE = 4;
		static const Sbecore::uint LSTCTPAVAIL = 5;
		static const Sbecore::uint BUTCTPVIEWACTIVE = 6;
		static const Sbecore::uint LSTMCHAVAIL = 7;
		static const Sbecore::uint BUTMCHVIEWACTIVE = 8;
		static const Sbecore::uint LSTLIBAVAIL = 9;
		static const Sbecore::uint BUTLIBVIEWACTIVE = 10;

	public:
		StatShr(const bool LstLocAvail = true, const bool ButLocViewActive = true, const bool LstTagAvail = true, const bool ButTagViewActive = true, const bool LstCtpAvail = true, const bool ButCtpViewActive = true, const bool LstMchAvail = true, const bool ButMchViewActive = true, const bool LstLibAvail = true, const bool ButLibViewActive = true);

	public:
		bool LstLocAvail;
		bool ButLocViewActive;
		bool LstTagAvail;
		bool ButTagViewActive;
		bool LstCtpAvail;
		bool ButCtpViewActive;
		bool LstMchAvail;
		bool ButMchViewActive;
		bool LstLibAvail;
		bool ButLibViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavGlobal)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTLOC = 2;
		static const Sbecore::uint CPTTAG = 3;
		static const Sbecore::uint CPTCTP = 4;
		static const Sbecore::uint CPTMCH = 5;
		static const Sbecore::uint CPTLIB = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptLoc = "", const std::string& CptTag = "", const std::string& CptCtp = "", const std::string& CptMch = "", const std::string& CptLib = "");

	public:
		std::string Cpt;
		std::string CptLoc;
		std::string CptTag;
		std::string CptCtp;
		std::string CptMch;
		std::string CptLib;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavGlobalData)
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
		* DpchAppDo (full: DpchAppWznmNavGlobalDo)
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
		* DpchEngData (full: DpchEngWznmNavGlobalData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCTP = 3;
		static const Sbecore::uint FEEDFLSTLIB = 4;
		static const Sbecore::uint FEEDFLSTLOC = 5;
		static const Sbecore::uint FEEDFLSTMCH = 6;
		static const Sbecore::uint FEEDFLSTTAG = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCtp;
		Sbecore::Xmlio::Feed feedFLstLib;
		Sbecore::Xmlio::Feed feedFLstLoc;
		Sbecore::Xmlio::Feed feedFLstMch;
		Sbecore::Xmlio::Feed feedFLstTag;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
