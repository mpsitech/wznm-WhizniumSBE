/**
	* \file PnlWznmNavUix.h
	* API code for job PnlWznmNavUix (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVUIX_H
#define PNLWZNMNAVUIX_H

#include "ApiWznm_blks.h"

#define VecVWznmNavUixDo PnlWznmNavUix::VecVDo

#define ContIacWznmNavUix PnlWznmNavUix::ContIac
#define StatAppWznmNavUix PnlWznmNavUix::StatApp
#define StatShrWznmNavUix PnlWznmNavUix::StatShr
#define TagWznmNavUix PnlWznmNavUix::Tag

#define DpchAppWznmNavUixData PnlWznmNavUix::DpchAppData
#define DpchAppWznmNavUixDo PnlWznmNavUix::DpchAppDo
#define DpchEngWznmNavUixData PnlWznmNavUix::DpchEngData

/**
	* PnlWznmNavUix
	*/
namespace PnlWznmNavUix {
	/**
		* VecVDo (full: VecVWznmNavUixDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPSTVIEWCLICK = 1;
		static const Sbecore::uint BUTPSTNEWCRDCLICK = 2;
		static const Sbecore::uint BUTMDLVIEWCLICK = 3;
		static const Sbecore::uint BUTMDLNEWCRDCLICK = 4;
		static const Sbecore::uint BUTCARVIEWCLICK = 5;
		static const Sbecore::uint BUTCARNEWCRDCLICK = 6;
		static const Sbecore::uint BUTDLGVIEWCLICK = 7;
		static const Sbecore::uint BUTDLGNEWCRDCLICK = 8;
		static const Sbecore::uint BUTPNLVIEWCLICK = 9;
		static const Sbecore::uint BUTPNLNEWCRDCLICK = 10;
		static const Sbecore::uint BUTQRYVIEWCLICK = 11;
		static const Sbecore::uint BUTQRYNEWCRDCLICK = 12;
		static const Sbecore::uint BUTQCOVIEWCLICK = 13;
		static const Sbecore::uint BUTQCONEWCRDCLICK = 14;
		static const Sbecore::uint BUTQMDVIEWCLICK = 15;
		static const Sbecore::uint BUTQMDNEWCRDCLICK = 16;
		static const Sbecore::uint BUTCONVIEWCLICK = 17;
		static const Sbecore::uint BUTCONNEWCRDCLICK = 18;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavUix)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTPST = 1;
		static const Sbecore::uint NUMFLSTMDL = 2;
		static const Sbecore::uint NUMFLSTCAR = 3;
		static const Sbecore::uint NUMFLSTDLG = 4;
		static const Sbecore::uint NUMFLSTPNL = 5;
		static const Sbecore::uint NUMFLSTQRY = 6;
		static const Sbecore::uint NUMFLSTQCO = 7;
		static const Sbecore::uint NUMFLSTQMD = 8;
		static const Sbecore::uint NUMFLSTCON = 9;

	public:
		ContIac(const Sbecore::uint numFLstPst = 1, const Sbecore::uint numFLstMdl = 1, const Sbecore::uint numFLstCar = 1, const Sbecore::uint numFLstDlg = 1, const Sbecore::uint numFLstPnl = 1, const Sbecore::uint numFLstQry = 1, const Sbecore::uint numFLstQco = 1, const Sbecore::uint numFLstQmd = 1, const Sbecore::uint numFLstCon = 1);

	public:
		Sbecore::uint numFLstPst;
		Sbecore::uint numFLstMdl;
		Sbecore::uint numFLstCar;
		Sbecore::uint numFLstDlg;
		Sbecore::uint numFLstPnl;
		Sbecore::uint numFLstQry;
		Sbecore::uint numFLstQco;
		Sbecore::uint numFLstQmd;
		Sbecore::uint numFLstCon;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNavUix)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTPSTALT = 2;
		static const Sbecore::uint LSTMDLALT = 3;
		static const Sbecore::uint LSTCARALT = 4;
		static const Sbecore::uint LSTDLGALT = 5;
		static const Sbecore::uint LSTPNLALT = 6;
		static const Sbecore::uint LSTQRYALT = 7;
		static const Sbecore::uint LSTQCOALT = 8;
		static const Sbecore::uint LSTQMDALT = 9;
		static const Sbecore::uint LSTCONALT = 10;
		static const Sbecore::uint LSTPSTNUMFIRSTDISP = 11;
		static const Sbecore::uint LSTMDLNUMFIRSTDISP = 12;
		static const Sbecore::uint LSTCARNUMFIRSTDISP = 13;
		static const Sbecore::uint LSTDLGNUMFIRSTDISP = 14;
		static const Sbecore::uint LSTPNLNUMFIRSTDISP = 15;
		static const Sbecore::uint LSTQRYNUMFIRSTDISP = 16;
		static const Sbecore::uint LSTQCONUMFIRSTDISP = 17;
		static const Sbecore::uint LSTQMDNUMFIRSTDISP = 18;
		static const Sbecore::uint LSTCONNUMFIRSTDISP = 19;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstPstAlt = true, const bool LstMdlAlt = true, const bool LstCarAlt = true, const bool LstDlgAlt = true, const bool LstPnlAlt = true, const bool LstQryAlt = true, const bool LstQcoAlt = true, const bool LstQmdAlt = true, const bool LstConAlt = true, const Sbecore::uint LstPstNumFirstdisp = 1, const Sbecore::uint LstMdlNumFirstdisp = 1, const Sbecore::uint LstCarNumFirstdisp = 1, const Sbecore::uint LstDlgNumFirstdisp = 1, const Sbecore::uint LstPnlNumFirstdisp = 1, const Sbecore::uint LstQryNumFirstdisp = 1, const Sbecore::uint LstQcoNumFirstdisp = 1, const Sbecore::uint LstQmdNumFirstdisp = 1, const Sbecore::uint LstConNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstPstAlt;
		bool LstMdlAlt;
		bool LstCarAlt;
		bool LstDlgAlt;
		bool LstPnlAlt;
		bool LstQryAlt;
		bool LstQcoAlt;
		bool LstQmdAlt;
		bool LstConAlt;
		Sbecore::uint LstPstNumFirstdisp;
		Sbecore::uint LstMdlNumFirstdisp;
		Sbecore::uint LstCarNumFirstdisp;
		Sbecore::uint LstDlgNumFirstdisp;
		Sbecore::uint LstPnlNumFirstdisp;
		Sbecore::uint LstQryNumFirstdisp;
		Sbecore::uint LstQcoNumFirstdisp;
		Sbecore::uint LstQmdNumFirstdisp;
		Sbecore::uint LstConNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavUix)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTPSTAVAIL = 1;
		static const Sbecore::uint BUTPSTVIEWACTIVE = 2;
		static const Sbecore::uint BUTPSTNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTMDLAVAIL = 4;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 5;
		static const Sbecore::uint BUTMDLNEWCRDACTIVE = 6;
		static const Sbecore::uint LSTCARAVAIL = 7;
		static const Sbecore::uint BUTCARVIEWACTIVE = 8;
		static const Sbecore::uint BUTCARNEWCRDACTIVE = 9;
		static const Sbecore::uint LSTDLGAVAIL = 10;
		static const Sbecore::uint BUTDLGVIEWACTIVE = 11;
		static const Sbecore::uint BUTDLGNEWCRDACTIVE = 12;
		static const Sbecore::uint LSTPNLAVAIL = 13;
		static const Sbecore::uint BUTPNLVIEWACTIVE = 14;
		static const Sbecore::uint BUTPNLNEWCRDACTIVE = 15;
		static const Sbecore::uint LSTQRYAVAIL = 16;
		static const Sbecore::uint BUTQRYVIEWACTIVE = 17;
		static const Sbecore::uint BUTQRYNEWCRDACTIVE = 18;
		static const Sbecore::uint LSTQCOAVAIL = 19;
		static const Sbecore::uint BUTQCOVIEWACTIVE = 20;
		static const Sbecore::uint BUTQCONEWCRDACTIVE = 21;
		static const Sbecore::uint LSTQMDAVAIL = 22;
		static const Sbecore::uint BUTQMDVIEWACTIVE = 23;
		static const Sbecore::uint BUTQMDNEWCRDACTIVE = 24;
		static const Sbecore::uint LSTCONAVAIL = 25;
		static const Sbecore::uint BUTCONVIEWACTIVE = 26;
		static const Sbecore::uint BUTCONNEWCRDACTIVE = 27;

	public:
		StatShr(const bool LstPstAvail = true, const bool ButPstViewActive = true, const bool ButPstNewcrdActive = true, const bool LstMdlAvail = true, const bool ButMdlViewActive = true, const bool ButMdlNewcrdActive = true, const bool LstCarAvail = true, const bool ButCarViewActive = true, const bool ButCarNewcrdActive = true, const bool LstDlgAvail = true, const bool ButDlgViewActive = true, const bool ButDlgNewcrdActive = true, const bool LstPnlAvail = true, const bool ButPnlViewActive = true, const bool ButPnlNewcrdActive = true, const bool LstQryAvail = true, const bool ButQryViewActive = true, const bool ButQryNewcrdActive = true, const bool LstQcoAvail = true, const bool ButQcoViewActive = true, const bool ButQcoNewcrdActive = true, const bool LstQmdAvail = true, const bool ButQmdViewActive = true, const bool ButQmdNewcrdActive = true, const bool LstConAvail = true, const bool ButConViewActive = true, const bool ButConNewcrdActive = true);

	public:
		bool LstPstAvail;
		bool ButPstViewActive;
		bool ButPstNewcrdActive;
		bool LstMdlAvail;
		bool ButMdlViewActive;
		bool ButMdlNewcrdActive;
		bool LstCarAvail;
		bool ButCarViewActive;
		bool ButCarNewcrdActive;
		bool LstDlgAvail;
		bool ButDlgViewActive;
		bool ButDlgNewcrdActive;
		bool LstPnlAvail;
		bool ButPnlViewActive;
		bool ButPnlNewcrdActive;
		bool LstQryAvail;
		bool ButQryViewActive;
		bool ButQryNewcrdActive;
		bool LstQcoAvail;
		bool ButQcoViewActive;
		bool ButQcoNewcrdActive;
		bool LstQmdAvail;
		bool ButQmdViewActive;
		bool ButQmdNewcrdActive;
		bool LstConAvail;
		bool ButConViewActive;
		bool ButConNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavUix)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPST = 2;
		static const Sbecore::uint CPTMDL = 3;
		static const Sbecore::uint CPTCAR = 4;
		static const Sbecore::uint CPTDLG = 5;
		static const Sbecore::uint CPTPNL = 6;
		static const Sbecore::uint CPTQRY = 7;
		static const Sbecore::uint CPTQCO = 8;
		static const Sbecore::uint CPTQMD = 9;
		static const Sbecore::uint CPTCON = 10;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPst = "", const std::string& CptMdl = "", const std::string& CptCar = "", const std::string& CptDlg = "", const std::string& CptPnl = "", const std::string& CptQry = "", const std::string& CptQco = "", const std::string& CptQmd = "", const std::string& CptCon = "");

	public:
		std::string Cpt;
		std::string CptPst;
		std::string CptMdl;
		std::string CptCar;
		std::string CptDlg;
		std::string CptPnl;
		std::string CptQry;
		std::string CptQco;
		std::string CptQmd;
		std::string CptCon;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavUixData)
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
		* DpchAppDo (full: DpchAppWznmNavUixDo)
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
		* DpchEngData (full: DpchEngWznmNavUixData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCAR = 3;
		static const Sbecore::uint FEEDFLSTCON = 4;
		static const Sbecore::uint FEEDFLSTDLG = 5;
		static const Sbecore::uint FEEDFLSTMDL = 6;
		static const Sbecore::uint FEEDFLSTPNL = 7;
		static const Sbecore::uint FEEDFLSTPST = 8;
		static const Sbecore::uint FEEDFLSTQCO = 9;
		static const Sbecore::uint FEEDFLSTQMD = 10;
		static const Sbecore::uint FEEDFLSTQRY = 11;
		static const Sbecore::uint STATAPP = 12;
		static const Sbecore::uint STATSHR = 13;
		static const Sbecore::uint TAG = 14;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCar;
		Sbecore::Xmlio::Feed feedFLstCon;
		Sbecore::Xmlio::Feed feedFLstDlg;
		Sbecore::Xmlio::Feed feedFLstMdl;
		Sbecore::Xmlio::Feed feedFLstPnl;
		Sbecore::Xmlio::Feed feedFLstPst;
		Sbecore::Xmlio::Feed feedFLstQco;
		Sbecore::Xmlio::Feed feedFLstQmd;
		Sbecore::Xmlio::Feed feedFLstQry;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

