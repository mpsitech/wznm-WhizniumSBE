/**
	* \file CrdWznmNav.h
	* API code for job CrdWznmNav (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZNMNAV_H
#define CRDWZNMNAV_H

#include "ApiWznm_blks.h"

#define VecVWznmNavDo CrdWznmNav::VecVDo
#define VecVWznmNavSge CrdWznmNav::VecVSge

#define ContInfWznmNav CrdWznmNav::ContInf
#define StatAppWznmNav CrdWznmNav::StatApp
#define StatShrWznmNav CrdWznmNav::StatShr
#define TagWznmNav CrdWznmNav::Tag

#define DpchAppWznmNavDo CrdWznmNav::DpchAppDo
#define DpchEngWznmNavData CrdWznmNav::DpchEngData

/**
	* CrdWznmNav
	*/
namespace CrdWznmNav {
	/**
		* VecVDo (full: VecVWznmNavDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITSESSPSCLICK = 3;
		static const Sbecore::uint MITSESTRMCLICK = 4;
		static const Sbecore::uint MITCRDUSGCLICK = 5;
		static const Sbecore::uint MITCRDUSRCLICK = 6;
		static const Sbecore::uint MITCRDPRSCLICK = 7;
		static const Sbecore::uint MITCRDFILCLICK = 8;
		static const Sbecore::uint MITCRDLOCCLICK = 9;
		static const Sbecore::uint MITCRDTAGCLICK = 10;
		static const Sbecore::uint MITCRDCTPCLICK = 11;
		static const Sbecore::uint MITCRDMCHCLICK = 12;
		static const Sbecore::uint MITCRDLIBCLICK = 13;
		static const Sbecore::uint MITCRDPRJCLICK = 14;
		static const Sbecore::uint MITCRDVERCLICK = 15;
		static const Sbecore::uint MITCRDCAPCLICK = 16;
		static const Sbecore::uint MITCRDERRCLICK = 17;
		static const Sbecore::uint MITCRDTBLCLICK = 18;
		static const Sbecore::uint MITCRDTCOCLICK = 19;
		static const Sbecore::uint MITCRDSBSCLICK = 20;
		static const Sbecore::uint MITCRDRELCLICK = 21;
		static const Sbecore::uint MITCRDVECCLICK = 22;
		static const Sbecore::uint MITCRDVITCLICK = 23;
		static const Sbecore::uint MITCRDCHKCLICK = 24;
		static const Sbecore::uint MITCRDSTBCLICK = 25;
		static const Sbecore::uint MITCRDIEXCLICK = 26;
		static const Sbecore::uint MITCRDIMECLICK = 27;
		static const Sbecore::uint MITCRDPSTCLICK = 28;
		static const Sbecore::uint MITCRDMDLCLICK = 29;
		static const Sbecore::uint MITCRDCARCLICK = 30;
		static const Sbecore::uint MITCRDDLGCLICK = 31;
		static const Sbecore::uint MITCRDPNLCLICK = 32;
		static const Sbecore::uint MITCRDQRYCLICK = 33;
		static const Sbecore::uint MITCRDQCOCLICK = 34;
		static const Sbecore::uint MITCRDQMDCLICK = 35;
		static const Sbecore::uint MITCRDCONCLICK = 36;
		static const Sbecore::uint MITCRDOPKCLICK = 37;
		static const Sbecore::uint MITCRDOPXCLICK = 38;
		static const Sbecore::uint MITCRDJOBCLICK = 39;
		static const Sbecore::uint MITCRDSGECLICK = 40;
		static const Sbecore::uint MITCRDMTDCLICK = 41;
		static const Sbecore::uint MITCRDBLKCLICK = 42;
		static const Sbecore::uint MITCRDCALCLICK = 43;
		static const Sbecore::uint MITCRDCMPCLICK = 44;
		static const Sbecore::uint MITCRDRLSCLICK = 45;
		static const Sbecore::uint MITCRDVISCLICK = 46;
		static const Sbecore::uint MITCRDSHTCLICK = 47;
		static const Sbecore::uint MITCRDBOXCLICK = 48;
		static const Sbecore::uint MITCRDAPPCLICK = 49;
		static const Sbecore::uint MITCRDRTJCLICK = 50;
		static const Sbecore::uint MITCRDEVTCLICK = 51;
		static const Sbecore::uint MITCRDSEQCLICK = 52;
		static const Sbecore::uint MITCRDSTECLICK = 53;
		static const Sbecore::uint MITCRDUTLCLICK = 54;
		static const Sbecore::uint MITAPPMLCCLICK = 55;
		static const Sbecore::uint MITAPPLOICLICK = 56;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWznmNavSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZNMABT = 2;
		static const Sbecore::uint ALRWZNMTRM = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmNav)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXSESSES1 = 3;
		static const Sbecore::uint MTXSESSES2 = 4;
		static const Sbecore::uint MTXSESSES3 = 5;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxSesSes1 = "", const std::string& MtxSesSes2 = "", const std::string& MtxSesSes3 = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxSesSes1;
		std::string MtxSesSes2;
		std::string MtxSesSes3;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNav)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONEHEADBAR = 5;
		static const Sbecore::uint INITDONEPRE = 6;
		static const Sbecore::uint INITDONEADMIN = 7;
		static const Sbecore::uint INITDONEGLOBAL = 8;
		static const Sbecore::uint INITDONEPROJECT = 9;
		static const Sbecore::uint INITDONEDBSTR = 10;
		static const Sbecore::uint INITDONEUIX = 11;
		static const Sbecore::uint INITDONECOMP = 12;
		static const Sbecore::uint INITDONEJOB = 13;
		static const Sbecore::uint INITDONEDEPLOY = 14;
		static const Sbecore::uint INITDONEVISUAL = 15;
		static const Sbecore::uint INITDONEAPPDEV = 16;
		static const Sbecore::uint INITDONEAUXFCT = 17;

	public:
		StatApp(const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneGlobal = false, const bool initdoneProject = false, const bool initdoneDbstr = false, const bool initdoneUix = false, const bool initdoneComp = false, const bool initdoneJob = false, const bool initdoneDeploy = false, const bool initdoneVisual = false, const bool initdoneAppdev = false, const bool initdoneAuxfct = false);

	public:
		Sbecore::uint ixWznmVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneHeadbar;
		bool initdonePre;
		bool initdoneAdmin;
		bool initdoneGlobal;
		bool initdoneProject;
		bool initdoneDbstr;
		bool initdoneUix;
		bool initdoneComp;
		bool initdoneJob;
		bool initdoneDeploy;
		bool initdoneVisual;
		bool initdoneAppdev;
		bool initdoneAuxfct;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNav)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint SCRJREFDLGLOAINI = 1;
		static const Sbecore::uint SCRJREFDLGMNGLIC = 2;
		static const Sbecore::uint SCRJREFHEADBAR = 3;
		static const Sbecore::uint SCRJREFPRE = 4;
		static const Sbecore::uint PNLPREAVAIL = 5;
		static const Sbecore::uint SCRJREFADMIN = 6;
		static const Sbecore::uint PNLADMINAVAIL = 7;
		static const Sbecore::uint SCRJREFGLOBAL = 8;
		static const Sbecore::uint PNLGLOBALAVAIL = 9;
		static const Sbecore::uint SCRJREFPROJECT = 10;
		static const Sbecore::uint PNLPROJECTAVAIL = 11;
		static const Sbecore::uint SCRJREFDBSTR = 12;
		static const Sbecore::uint PNLDBSTRAVAIL = 13;
		static const Sbecore::uint SCRJREFUIX = 14;
		static const Sbecore::uint PNLUIXAVAIL = 15;
		static const Sbecore::uint SCRJREFCOMP = 16;
		static const Sbecore::uint PNLCOMPAVAIL = 17;
		static const Sbecore::uint SCRJREFJOB = 18;
		static const Sbecore::uint PNLJOBAVAIL = 19;
		static const Sbecore::uint SCRJREFDEPLOY = 20;
		static const Sbecore::uint PNLDEPLOYAVAIL = 21;
		static const Sbecore::uint SCRJREFVISUAL = 22;
		static const Sbecore::uint PNLVISUALAVAIL = 23;
		static const Sbecore::uint SCRJREFAPPDEV = 24;
		static const Sbecore::uint PNLAPPDEVAVAIL = 25;
		static const Sbecore::uint SCRJREFAUXFCT = 26;
		static const Sbecore::uint PNLAUXFCTAVAIL = 27;
		static const Sbecore::uint MITSESSPSAVAIL = 28;
		static const Sbecore::uint MSPCRD1AVAIL = 29;
		static const Sbecore::uint MITCRDUSGAVAIL = 30;
		static const Sbecore::uint MITCRDUSRAVAIL = 31;
		static const Sbecore::uint MITCRDPRSAVAIL = 32;
		static const Sbecore::uint MITCRDFILAVAIL = 33;
		static const Sbecore::uint MSPCRD2AVAIL = 34;
		static const Sbecore::uint MITCRDLOCAVAIL = 35;
		static const Sbecore::uint MITCRDTAGAVAIL = 36;
		static const Sbecore::uint MITCRDCTPAVAIL = 37;
		static const Sbecore::uint MITCRDMCHAVAIL = 38;
		static const Sbecore::uint MITCRDLIBAVAIL = 39;
		static const Sbecore::uint MSPCRD3AVAIL = 40;
		static const Sbecore::uint MITCRDPRJAVAIL = 41;
		static const Sbecore::uint MITCRDVERAVAIL = 42;
		static const Sbecore::uint MITCRDCAPAVAIL = 43;
		static const Sbecore::uint MITCRDCAPACTIVE = 44;
		static const Sbecore::uint MITCRDERRAVAIL = 45;
		static const Sbecore::uint MITCRDERRACTIVE = 46;
		static const Sbecore::uint MSPCRD4AVAIL = 47;
		static const Sbecore::uint MITCRDTBLAVAIL = 48;
		static const Sbecore::uint MITCRDTBLACTIVE = 49;
		static const Sbecore::uint MITCRDTCOAVAIL = 50;
		static const Sbecore::uint MITCRDTCOACTIVE = 51;
		static const Sbecore::uint MITCRDSBSAVAIL = 52;
		static const Sbecore::uint MITCRDSBSACTIVE = 53;
		static const Sbecore::uint MITCRDRELAVAIL = 54;
		static const Sbecore::uint MITCRDRELACTIVE = 55;
		static const Sbecore::uint MITCRDVECAVAIL = 56;
		static const Sbecore::uint MITCRDVECACTIVE = 57;
		static const Sbecore::uint MITCRDVITAVAIL = 58;
		static const Sbecore::uint MITCRDVITACTIVE = 59;
		static const Sbecore::uint MITCRDCHKAVAIL = 60;
		static const Sbecore::uint MITCRDCHKACTIVE = 61;
		static const Sbecore::uint MITCRDSTBAVAIL = 62;
		static const Sbecore::uint MITCRDSTBACTIVE = 63;
		static const Sbecore::uint MITCRDIEXAVAIL = 64;
		static const Sbecore::uint MITCRDIEXACTIVE = 65;
		static const Sbecore::uint MITCRDIMEAVAIL = 66;
		static const Sbecore::uint MITCRDIMEACTIVE = 67;
		static const Sbecore::uint MSPCRD5AVAIL = 68;
		static const Sbecore::uint MITCRDPSTAVAIL = 69;
		static const Sbecore::uint MITCRDPSTACTIVE = 70;
		static const Sbecore::uint MITCRDMDLAVAIL = 71;
		static const Sbecore::uint MITCRDMDLACTIVE = 72;
		static const Sbecore::uint MITCRDCARAVAIL = 73;
		static const Sbecore::uint MITCRDCARACTIVE = 74;
		static const Sbecore::uint MITCRDDLGAVAIL = 75;
		static const Sbecore::uint MITCRDDLGACTIVE = 76;
		static const Sbecore::uint MITCRDPNLAVAIL = 77;
		static const Sbecore::uint MITCRDPNLACTIVE = 78;
		static const Sbecore::uint MITCRDQRYAVAIL = 79;
		static const Sbecore::uint MITCRDQRYACTIVE = 80;
		static const Sbecore::uint MITCRDQCOAVAIL = 81;
		static const Sbecore::uint MITCRDQCOACTIVE = 82;
		static const Sbecore::uint MITCRDQMDAVAIL = 83;
		static const Sbecore::uint MITCRDQMDACTIVE = 84;
		static const Sbecore::uint MITCRDCONAVAIL = 85;
		static const Sbecore::uint MITCRDCONACTIVE = 86;
		static const Sbecore::uint MSPCRD6AVAIL = 87;
		static const Sbecore::uint MITCRDOPKAVAIL = 88;
		static const Sbecore::uint MITCRDOPKACTIVE = 89;
		static const Sbecore::uint MITCRDOPXAVAIL = 90;
		static const Sbecore::uint MITCRDOPXACTIVE = 91;
		static const Sbecore::uint MSPCRD7AVAIL = 92;
		static const Sbecore::uint MITCRDJOBAVAIL = 93;
		static const Sbecore::uint MITCRDJOBACTIVE = 94;
		static const Sbecore::uint MITCRDSGEAVAIL = 95;
		static const Sbecore::uint MITCRDSGEACTIVE = 96;
		static const Sbecore::uint MITCRDMTDAVAIL = 97;
		static const Sbecore::uint MITCRDMTDACTIVE = 98;
		static const Sbecore::uint MITCRDBLKAVAIL = 99;
		static const Sbecore::uint MITCRDBLKACTIVE = 100;
		static const Sbecore::uint MITCRDCALAVAIL = 101;
		static const Sbecore::uint MITCRDCALACTIVE = 102;
		static const Sbecore::uint MSPCRD8AVAIL = 103;
		static const Sbecore::uint MITCRDCMPAVAIL = 104;
		static const Sbecore::uint MITCRDRLSAVAIL = 105;
		static const Sbecore::uint MITCRDRLSACTIVE = 106;
		static const Sbecore::uint MSPCRD9AVAIL = 107;
		static const Sbecore::uint MITCRDVISAVAIL = 108;
		static const Sbecore::uint MITCRDSHTAVAIL = 109;
		static const Sbecore::uint MITCRDSHTACTIVE = 110;
		static const Sbecore::uint MITCRDBOXAVAIL = 111;
		static const Sbecore::uint MITCRDBOXACTIVE = 112;
		static const Sbecore::uint MSPCRD10AVAIL = 113;
		static const Sbecore::uint MITCRDAPPAVAIL = 114;
		static const Sbecore::uint MITCRDRTJAVAIL = 115;
		static const Sbecore::uint MITCRDRTJACTIVE = 116;
		static const Sbecore::uint MITCRDEVTAVAIL = 117;
		static const Sbecore::uint MITCRDEVTACTIVE = 118;
		static const Sbecore::uint MITCRDSEQAVAIL = 119;
		static const Sbecore::uint MITCRDSEQACTIVE = 120;
		static const Sbecore::uint MITCRDSTEAVAIL = 121;
		static const Sbecore::uint MITCRDSTEACTIVE = 122;
		static const Sbecore::uint MSPCRD11AVAIL = 123;
		static const Sbecore::uint MITCRDUTLAVAIL = 124;
		static const Sbecore::uint MSPAPP2AVAIL = 125;
		static const Sbecore::uint MITAPPMLCAVAIL = 126;
		static const Sbecore::uint MITAPPLOIAVAIL = 127;

	public:
		StatShr(const std::string& scrJrefDlgloaini = "", const std::string& scrJrefDlgmnglic = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefPre = "", const bool pnlpreAvail = false, const std::string& scrJrefAdmin = "", const bool pnladminAvail = false, const std::string& scrJrefGlobal = "", const bool pnlglobalAvail = false, const std::string& scrJrefProject = "", const bool pnlprojectAvail = false, const std::string& scrJrefDbstr = "", const bool pnldbstrAvail = false, const std::string& scrJrefUix = "", const bool pnluixAvail = false, const std::string& scrJrefComp = "", const bool pnlcompAvail = false, const std::string& scrJrefJob = "", const bool pnljobAvail = false, const std::string& scrJrefDeploy = "", const bool pnldeployAvail = false, const std::string& scrJrefVisual = "", const bool pnlvisualAvail = false, const std::string& scrJrefAppdev = "", const bool pnlappdevAvail = false, const std::string& scrJrefAuxfct = "", const bool pnlauxfctAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MspCrd2Avail = true, const bool MitCrdLocAvail = true, const bool MitCrdTagAvail = true, const bool MitCrdCtpAvail = true, const bool MitCrdMchAvail = true, const bool MitCrdLibAvail = true, const bool MspCrd3Avail = true, const bool MitCrdPrjAvail = true, const bool MitCrdVerAvail = true, const bool MitCrdCapAvail = true, const bool MitCrdCapActive = true, const bool MitCrdErrAvail = true, const bool MitCrdErrActive = true, const bool MspCrd4Avail = true, const bool MitCrdTblAvail = true, const bool MitCrdTblActive = true, const bool MitCrdTcoAvail = true, const bool MitCrdTcoActive = true, const bool MitCrdSbsAvail = true, const bool MitCrdSbsActive = true, const bool MitCrdRelAvail = true, const bool MitCrdRelActive = true, const bool MitCrdVecAvail = true, const bool MitCrdVecActive = true, const bool MitCrdVitAvail = true, const bool MitCrdVitActive = true, const bool MitCrdChkAvail = true, const bool MitCrdChkActive = true, const bool MitCrdStbAvail = true, const bool MitCrdStbActive = true, const bool MitCrdIexAvail = true, const bool MitCrdIexActive = true, const bool MitCrdImeAvail = true, const bool MitCrdImeActive = true, const bool MspCrd5Avail = true, const bool MitCrdPstAvail = true, const bool MitCrdPstActive = true, const bool MitCrdMdlAvail = true, const bool MitCrdMdlActive = true, const bool MitCrdCarAvail = true, const bool MitCrdCarActive = true, const bool MitCrdDlgAvail = true, const bool MitCrdDlgActive = true, const bool MitCrdPnlAvail = true, const bool MitCrdPnlActive = true, const bool MitCrdQryAvail = true, const bool MitCrdQryActive = true, const bool MitCrdQcoAvail = true, const bool MitCrdQcoActive = true, const bool MitCrdQmdAvail = true, const bool MitCrdQmdActive = true, const bool MitCrdConAvail = true, const bool MitCrdConActive = true, const bool MspCrd6Avail = true, const bool MitCrdOpkAvail = true, const bool MitCrdOpkActive = true, const bool MitCrdOpxAvail = true, const bool MitCrdOpxActive = true, const bool MspCrd7Avail = true, const bool MitCrdJobAvail = true, const bool MitCrdJobActive = true, const bool MitCrdSgeAvail = true, const bool MitCrdSgeActive = true, const bool MitCrdMtdAvail = true, const bool MitCrdMtdActive = true, const bool MitCrdBlkAvail = true, const bool MitCrdBlkActive = true, const bool MitCrdCalAvail = true, const bool MitCrdCalActive = true, const bool MspCrd8Avail = true, const bool MitCrdCmpAvail = true, const bool MitCrdRlsAvail = true, const bool MitCrdRlsActive = true, const bool MspCrd9Avail = true, const bool MitCrdVisAvail = true, const bool MitCrdShtAvail = true, const bool MitCrdShtActive = true, const bool MitCrdBoxAvail = true, const bool MitCrdBoxActive = true, const bool MspCrd10Avail = true, const bool MitCrdAppAvail = true, const bool MitCrdRtjAvail = true, const bool MitCrdRtjActive = true, const bool MitCrdEvtAvail = true, const bool MitCrdEvtActive = true, const bool MitCrdSeqAvail = true, const bool MitCrdSeqActive = true, const bool MitCrdSteAvail = true, const bool MitCrdSteActive = true, const bool MspCrd11Avail = true, const bool MitCrdUtlAvail = true, const bool MspApp2Avail = true, const bool MitAppMlcAvail = true, const bool MitAppLoiAvail = true);

	public:
		std::string scrJrefDlgloaini;
		std::string scrJrefDlgmnglic;
		std::string scrJrefHeadbar;
		std::string scrJrefPre;
		bool pnlpreAvail;
		std::string scrJrefAdmin;
		bool pnladminAvail;
		std::string scrJrefGlobal;
		bool pnlglobalAvail;
		std::string scrJrefProject;
		bool pnlprojectAvail;
		std::string scrJrefDbstr;
		bool pnldbstrAvail;
		std::string scrJrefUix;
		bool pnluixAvail;
		std::string scrJrefComp;
		bool pnlcompAvail;
		std::string scrJrefJob;
		bool pnljobAvail;
		std::string scrJrefDeploy;
		bool pnldeployAvail;
		std::string scrJrefVisual;
		bool pnlvisualAvail;
		std::string scrJrefAppdev;
		bool pnlappdevAvail;
		std::string scrJrefAuxfct;
		bool pnlauxfctAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdFilAvail;
		bool MspCrd2Avail;
		bool MitCrdLocAvail;
		bool MitCrdTagAvail;
		bool MitCrdCtpAvail;
		bool MitCrdMchAvail;
		bool MitCrdLibAvail;
		bool MspCrd3Avail;
		bool MitCrdPrjAvail;
		bool MitCrdVerAvail;
		bool MitCrdCapAvail;
		bool MitCrdCapActive;
		bool MitCrdErrAvail;
		bool MitCrdErrActive;
		bool MspCrd4Avail;
		bool MitCrdTblAvail;
		bool MitCrdTblActive;
		bool MitCrdTcoAvail;
		bool MitCrdTcoActive;
		bool MitCrdSbsAvail;
		bool MitCrdSbsActive;
		bool MitCrdRelAvail;
		bool MitCrdRelActive;
		bool MitCrdVecAvail;
		bool MitCrdVecActive;
		bool MitCrdVitAvail;
		bool MitCrdVitActive;
		bool MitCrdChkAvail;
		bool MitCrdChkActive;
		bool MitCrdStbAvail;
		bool MitCrdStbActive;
		bool MitCrdIexAvail;
		bool MitCrdIexActive;
		bool MitCrdImeAvail;
		bool MitCrdImeActive;
		bool MspCrd5Avail;
		bool MitCrdPstAvail;
		bool MitCrdPstActive;
		bool MitCrdMdlAvail;
		bool MitCrdMdlActive;
		bool MitCrdCarAvail;
		bool MitCrdCarActive;
		bool MitCrdDlgAvail;
		bool MitCrdDlgActive;
		bool MitCrdPnlAvail;
		bool MitCrdPnlActive;
		bool MitCrdQryAvail;
		bool MitCrdQryActive;
		bool MitCrdQcoAvail;
		bool MitCrdQcoActive;
		bool MitCrdQmdAvail;
		bool MitCrdQmdActive;
		bool MitCrdConAvail;
		bool MitCrdConActive;
		bool MspCrd6Avail;
		bool MitCrdOpkAvail;
		bool MitCrdOpkActive;
		bool MitCrdOpxAvail;
		bool MitCrdOpxActive;
		bool MspCrd7Avail;
		bool MitCrdJobAvail;
		bool MitCrdJobActive;
		bool MitCrdSgeAvail;
		bool MitCrdSgeActive;
		bool MitCrdMtdAvail;
		bool MitCrdMtdActive;
		bool MitCrdBlkAvail;
		bool MitCrdBlkActive;
		bool MitCrdCalAvail;
		bool MitCrdCalActive;
		bool MspCrd8Avail;
		bool MitCrdCmpAvail;
		bool MitCrdRlsAvail;
		bool MitCrdRlsActive;
		bool MspCrd9Avail;
		bool MitCrdVisAvail;
		bool MitCrdShtAvail;
		bool MitCrdShtActive;
		bool MitCrdBoxAvail;
		bool MitCrdBoxActive;
		bool MspCrd10Avail;
		bool MitCrdAppAvail;
		bool MitCrdRtjAvail;
		bool MitCrdRtjActive;
		bool MitCrdEvtAvail;
		bool MitCrdEvtActive;
		bool MitCrdSeqAvail;
		bool MitCrdSeqActive;
		bool MitCrdSteAvail;
		bool MitCrdSteActive;
		bool MspCrd11Avail;
		bool MitCrdUtlAvail;
		bool MspApp2Avail;
		bool MitAppMlcAvail;
		bool MitAppLoiAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNav)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITSESSPS = 3;
		static const Sbecore::uint MITSESTRM = 4;
		static const Sbecore::uint MITCRDUSG = 5;
		static const Sbecore::uint MITCRDUSR = 6;
		static const Sbecore::uint MITCRDPRS = 7;
		static const Sbecore::uint MITCRDFIL = 8;
		static const Sbecore::uint MITCRDLOC = 9;
		static const Sbecore::uint MITCRDTAG = 10;
		static const Sbecore::uint MITCRDCTP = 11;
		static const Sbecore::uint MITCRDMCH = 12;
		static const Sbecore::uint MITCRDLIB = 13;
		static const Sbecore::uint MITCRDPRJ = 14;
		static const Sbecore::uint MITCRDVER = 15;
		static const Sbecore::uint MITCRDCAP = 16;
		static const Sbecore::uint MITCRDERR = 17;
		static const Sbecore::uint MITCRDTBL = 18;
		static const Sbecore::uint MITCRDTCO = 19;
		static const Sbecore::uint MITCRDSBS = 20;
		static const Sbecore::uint MITCRDREL = 21;
		static const Sbecore::uint MITCRDVEC = 22;
		static const Sbecore::uint MITCRDVIT = 23;
		static const Sbecore::uint MITCRDCHK = 24;
		static const Sbecore::uint MITCRDSTB = 25;
		static const Sbecore::uint MITCRDIEX = 26;
		static const Sbecore::uint MITCRDIME = 27;
		static const Sbecore::uint MITCRDPST = 28;
		static const Sbecore::uint MITCRDMDL = 29;
		static const Sbecore::uint MITCRDCAR = 30;
		static const Sbecore::uint MITCRDDLG = 31;
		static const Sbecore::uint MITCRDPNL = 32;
		static const Sbecore::uint MITCRDQRY = 33;
		static const Sbecore::uint MITCRDQCO = 34;
		static const Sbecore::uint MITCRDQMD = 35;
		static const Sbecore::uint MITCRDCON = 36;
		static const Sbecore::uint MITCRDOPK = 37;
		static const Sbecore::uint MITCRDOPX = 38;
		static const Sbecore::uint MITCRDJOB = 39;
		static const Sbecore::uint MITCRDSGE = 40;
		static const Sbecore::uint MITCRDMTD = 41;
		static const Sbecore::uint MITCRDBLK = 42;
		static const Sbecore::uint MITCRDCAL = 43;
		static const Sbecore::uint MITCRDCMP = 44;
		static const Sbecore::uint MITCRDRLS = 45;
		static const Sbecore::uint MITCRDVIS = 46;
		static const Sbecore::uint MITCRDSHT = 47;
		static const Sbecore::uint MITCRDBOX = 48;
		static const Sbecore::uint MITCRDAPP = 49;
		static const Sbecore::uint MITCRDRTJ = 50;
		static const Sbecore::uint MITCRDEVT = 51;
		static const Sbecore::uint MITCRDSEQ = 52;
		static const Sbecore::uint MITCRDSTE = 53;
		static const Sbecore::uint MITCRDUTL = 54;
		static const Sbecore::uint MITAPPMLC = 55;
		static const Sbecore::uint MITAPPLOI = 56;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitSesSps = "", const std::string& MitSesTrm = "", const std::string& MitCrdUsg = "", const std::string& MitCrdUsr = "", const std::string& MitCrdPrs = "", const std::string& MitCrdFil = "", const std::string& MitCrdLoc = "", const std::string& MitCrdTag = "", const std::string& MitCrdCtp = "", const std::string& MitCrdMch = "", const std::string& MitCrdLib = "", const std::string& MitCrdPrj = "", const std::string& MitCrdVer = "", const std::string& MitCrdCap = "", const std::string& MitCrdErr = "", const std::string& MitCrdTbl = "", const std::string& MitCrdTco = "", const std::string& MitCrdSbs = "", const std::string& MitCrdRel = "", const std::string& MitCrdVec = "", const std::string& MitCrdVit = "", const std::string& MitCrdChk = "", const std::string& MitCrdStb = "", const std::string& MitCrdIex = "", const std::string& MitCrdIme = "", const std::string& MitCrdPst = "", const std::string& MitCrdMdl = "", const std::string& MitCrdCar = "", const std::string& MitCrdDlg = "", const std::string& MitCrdPnl = "", const std::string& MitCrdQry = "", const std::string& MitCrdQco = "", const std::string& MitCrdQmd = "", const std::string& MitCrdCon = "", const std::string& MitCrdOpk = "", const std::string& MitCrdOpx = "", const std::string& MitCrdJob = "", const std::string& MitCrdSge = "", const std::string& MitCrdMtd = "", const std::string& MitCrdBlk = "", const std::string& MitCrdCal = "", const std::string& MitCrdCmp = "", const std::string& MitCrdRls = "", const std::string& MitCrdVis = "", const std::string& MitCrdSht = "", const std::string& MitCrdBox = "", const std::string& MitCrdApp = "", const std::string& MitCrdRtj = "", const std::string& MitCrdEvt = "", const std::string& MitCrdSeq = "", const std::string& MitCrdSte = "", const std::string& MitCrdUtl = "", const std::string& MitAppMlc = "", const std::string& MitAppLoi = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitSesSps;
		std::string MitSesTrm;
		std::string MitCrdUsg;
		std::string MitCrdUsr;
		std::string MitCrdPrs;
		std::string MitCrdFil;
		std::string MitCrdLoc;
		std::string MitCrdTag;
		std::string MitCrdCtp;
		std::string MitCrdMch;
		std::string MitCrdLib;
		std::string MitCrdPrj;
		std::string MitCrdVer;
		std::string MitCrdCap;
		std::string MitCrdErr;
		std::string MitCrdTbl;
		std::string MitCrdTco;
		std::string MitCrdSbs;
		std::string MitCrdRel;
		std::string MitCrdVec;
		std::string MitCrdVit;
		std::string MitCrdChk;
		std::string MitCrdStb;
		std::string MitCrdIex;
		std::string MitCrdIme;
		std::string MitCrdPst;
		std::string MitCrdMdl;
		std::string MitCrdCar;
		std::string MitCrdDlg;
		std::string MitCrdPnl;
		std::string MitCrdQry;
		std::string MitCrdQco;
		std::string MitCrdQmd;
		std::string MitCrdCon;
		std::string MitCrdOpk;
		std::string MitCrdOpx;
		std::string MitCrdJob;
		std::string MitCrdSge;
		std::string MitCrdMtd;
		std::string MitCrdBlk;
		std::string MitCrdCal;
		std::string MitCrdCmp;
		std::string MitCrdRls;
		std::string MitCrdVis;
		std::string MitCrdSht;
		std::string MitCrdBox;
		std::string MitCrdApp;
		std::string MitCrdRtj;
		std::string MitCrdEvt;
		std::string MitCrdSeq;
		std::string MitCrdSte;
		std::string MitCrdUtl;
		std::string MitAppMlc;
		std::string MitAppLoi;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavDo)
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
		* DpchEngData (full: DpchEngWznmNavData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
