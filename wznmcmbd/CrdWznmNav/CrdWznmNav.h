/**
	* \file CrdWznmNav.h
	* job handler for job CrdWznmNav (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZNMNAV_H
#define CRDWZNMNAV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmNavAuxfct.h"
#include "PnlWznmNavAppdev.h"
#include "PnlWznmNavJob.h"
#include "PnlWznmNavDeploy.h"
#include "PnlWznmNavComp.h"
#include "PnlWznmNavUix.h"
#include "PnlWznmNavDbstr.h"
#include "PnlWznmNavProject.h"
#include "PnlWznmNavGlobal.h"
#include "PnlWznmNavAdmin.h"
#include "PnlWznmNavPre.h"
#include "PnlWznmNavHeadbar.h"
#include "DlgWznmNavLoaini.h"
#include "DlgWznmNavMnglic.h"

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
class CrdWznmNav : public JobWznm {

public:
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
		static const Sbecore::uint MITCRDAPPCLICK = 46;
		static const Sbecore::uint MITCRDRTJCLICK = 47;
		static const Sbecore::uint MITCRDEVTCLICK = 48;
		static const Sbecore::uint MITCRDSEQCLICK = 49;
		static const Sbecore::uint MITCRDSTECLICK = 50;
		static const Sbecore::uint MITCRDUTLCLICK = 51;
		static const Sbecore::uint MITAPPMLCCLICK = 52;
		static const Sbecore::uint MITAPPLOICLICK = 53;

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

		static void fillFeed(Sbecore::Feed& feed);
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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmNav)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneGlobal = false, const bool initdoneProject = false, const bool initdoneDbstr = false, const bool initdoneUix = false, const bool initdoneComp = false, const bool initdoneJob = false, const bool initdoneDeploy = false, const bool initdoneAppdev = false, const bool initdoneAuxfct = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneGlobal = false, const bool initdoneProject = false, const bool initdoneDbstr = false, const bool initdoneUix = false, const bool initdoneComp = false, const bool initdoneJob = false, const bool initdoneDeploy = false, const bool initdoneAppdev = false, const bool initdoneAuxfct = false);
	};

	/**
		* StatShr (full: StatShrWznmNav)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFDLGLOAINI = 1;
		static const Sbecore::uint JREFDLGMNGLIC = 2;
		static const Sbecore::uint JREFHEADBAR = 3;
		static const Sbecore::uint JREFPRE = 4;
		static const Sbecore::uint PNLPREAVAIL = 5;
		static const Sbecore::uint JREFADMIN = 6;
		static const Sbecore::uint PNLADMINAVAIL = 7;
		static const Sbecore::uint JREFGLOBAL = 8;
		static const Sbecore::uint PNLGLOBALAVAIL = 9;
		static const Sbecore::uint JREFPROJECT = 10;
		static const Sbecore::uint PNLPROJECTAVAIL = 11;
		static const Sbecore::uint JREFDBSTR = 12;
		static const Sbecore::uint PNLDBSTRAVAIL = 13;
		static const Sbecore::uint JREFUIX = 14;
		static const Sbecore::uint PNLUIXAVAIL = 15;
		static const Sbecore::uint JREFCOMP = 16;
		static const Sbecore::uint PNLCOMPAVAIL = 17;
		static const Sbecore::uint JREFJOB = 18;
		static const Sbecore::uint PNLJOBAVAIL = 19;
		static const Sbecore::uint JREFDEPLOY = 20;
		static const Sbecore::uint PNLDEPLOYAVAIL = 21;
		static const Sbecore::uint JREFAPPDEV = 22;
		static const Sbecore::uint PNLAPPDEVAVAIL = 23;
		static const Sbecore::uint JREFAUXFCT = 24;
		static const Sbecore::uint PNLAUXFCTAVAIL = 25;
		static const Sbecore::uint MITSESSPSAVAIL = 26;
		static const Sbecore::uint MSPCRD1AVAIL = 27;
		static const Sbecore::uint MITCRDUSGAVAIL = 28;
		static const Sbecore::uint MITCRDUSRAVAIL = 29;
		static const Sbecore::uint MITCRDPRSAVAIL = 30;
		static const Sbecore::uint MITCRDFILAVAIL = 31;
		static const Sbecore::uint MSPCRD2AVAIL = 32;
		static const Sbecore::uint MITCRDLOCAVAIL = 33;
		static const Sbecore::uint MITCRDTAGAVAIL = 34;
		static const Sbecore::uint MITCRDCTPAVAIL = 35;
		static const Sbecore::uint MITCRDMCHAVAIL = 36;
		static const Sbecore::uint MITCRDLIBAVAIL = 37;
		static const Sbecore::uint MSPCRD3AVAIL = 38;
		static const Sbecore::uint MITCRDPRJAVAIL = 39;
		static const Sbecore::uint MITCRDVERAVAIL = 40;
		static const Sbecore::uint MITCRDCAPAVAIL = 41;
		static const Sbecore::uint MITCRDCAPACTIVE = 42;
		static const Sbecore::uint MITCRDERRAVAIL = 43;
		static const Sbecore::uint MITCRDERRACTIVE = 44;
		static const Sbecore::uint MSPCRD4AVAIL = 45;
		static const Sbecore::uint MITCRDTBLAVAIL = 46;
		static const Sbecore::uint MITCRDTBLACTIVE = 47;
		static const Sbecore::uint MITCRDTCOAVAIL = 48;
		static const Sbecore::uint MITCRDTCOACTIVE = 49;
		static const Sbecore::uint MITCRDSBSAVAIL = 50;
		static const Sbecore::uint MITCRDSBSACTIVE = 51;
		static const Sbecore::uint MITCRDRELAVAIL = 52;
		static const Sbecore::uint MITCRDRELACTIVE = 53;
		static const Sbecore::uint MITCRDVECAVAIL = 54;
		static const Sbecore::uint MITCRDVECACTIVE = 55;
		static const Sbecore::uint MITCRDVITAVAIL = 56;
		static const Sbecore::uint MITCRDVITACTIVE = 57;
		static const Sbecore::uint MITCRDCHKAVAIL = 58;
		static const Sbecore::uint MITCRDCHKACTIVE = 59;
		static const Sbecore::uint MITCRDSTBAVAIL = 60;
		static const Sbecore::uint MITCRDSTBACTIVE = 61;
		static const Sbecore::uint MITCRDIEXAVAIL = 62;
		static const Sbecore::uint MITCRDIEXACTIVE = 63;
		static const Sbecore::uint MITCRDIMEAVAIL = 64;
		static const Sbecore::uint MITCRDIMEACTIVE = 65;
		static const Sbecore::uint MSPCRD5AVAIL = 66;
		static const Sbecore::uint MITCRDPSTAVAIL = 67;
		static const Sbecore::uint MITCRDPSTACTIVE = 68;
		static const Sbecore::uint MITCRDMDLAVAIL = 69;
		static const Sbecore::uint MITCRDMDLACTIVE = 70;
		static const Sbecore::uint MITCRDCARAVAIL = 71;
		static const Sbecore::uint MITCRDCARACTIVE = 72;
		static const Sbecore::uint MITCRDDLGAVAIL = 73;
		static const Sbecore::uint MITCRDDLGACTIVE = 74;
		static const Sbecore::uint MITCRDPNLAVAIL = 75;
		static const Sbecore::uint MITCRDPNLACTIVE = 76;
		static const Sbecore::uint MITCRDQRYAVAIL = 77;
		static const Sbecore::uint MITCRDQRYACTIVE = 78;
		static const Sbecore::uint MITCRDQCOAVAIL = 79;
		static const Sbecore::uint MITCRDQCOACTIVE = 80;
		static const Sbecore::uint MITCRDQMDAVAIL = 81;
		static const Sbecore::uint MITCRDQMDACTIVE = 82;
		static const Sbecore::uint MITCRDCONAVAIL = 83;
		static const Sbecore::uint MITCRDCONACTIVE = 84;
		static const Sbecore::uint MSPCRD6AVAIL = 85;
		static const Sbecore::uint MITCRDOPKAVAIL = 86;
		static const Sbecore::uint MITCRDOPKACTIVE = 87;
		static const Sbecore::uint MITCRDOPXAVAIL = 88;
		static const Sbecore::uint MITCRDOPXACTIVE = 89;
		static const Sbecore::uint MSPCRD7AVAIL = 90;
		static const Sbecore::uint MITCRDJOBAVAIL = 91;
		static const Sbecore::uint MITCRDJOBACTIVE = 92;
		static const Sbecore::uint MITCRDSGEAVAIL = 93;
		static const Sbecore::uint MITCRDSGEACTIVE = 94;
		static const Sbecore::uint MITCRDMTDAVAIL = 95;
		static const Sbecore::uint MITCRDMTDACTIVE = 96;
		static const Sbecore::uint MITCRDBLKAVAIL = 97;
		static const Sbecore::uint MITCRDBLKACTIVE = 98;
		static const Sbecore::uint MITCRDCALAVAIL = 99;
		static const Sbecore::uint MITCRDCALACTIVE = 100;
		static const Sbecore::uint MSPCRD8AVAIL = 101;
		static const Sbecore::uint MITCRDCMPAVAIL = 102;
		static const Sbecore::uint MITCRDRLSAVAIL = 103;
		static const Sbecore::uint MITCRDRLSACTIVE = 104;
		static const Sbecore::uint MSPCRD9AVAIL = 105;
		static const Sbecore::uint MITCRDAPPAVAIL = 106;
		static const Sbecore::uint MITCRDRTJAVAIL = 107;
		static const Sbecore::uint MITCRDRTJACTIVE = 108;
		static const Sbecore::uint MITCRDEVTAVAIL = 109;
		static const Sbecore::uint MITCRDEVTACTIVE = 110;
		static const Sbecore::uint MITCRDSEQAVAIL = 111;
		static const Sbecore::uint MITCRDSEQACTIVE = 112;
		static const Sbecore::uint MITCRDSTEAVAIL = 113;
		static const Sbecore::uint MITCRDSTEACTIVE = 114;
		static const Sbecore::uint MSPCRD10AVAIL = 115;
		static const Sbecore::uint MITCRDUTLAVAIL = 116;
		static const Sbecore::uint MSPAPP2AVAIL = 117;
		static const Sbecore::uint MITAPPMLCAVAIL = 118;
		static const Sbecore::uint MITAPPLOIAVAIL = 119;

	public:
		StatShr(const Sbecore::ubigint jrefDlgloaini = 0, const Sbecore::ubigint jrefDlgmnglic = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefPre = 0, const bool pnlpreAvail = false, const Sbecore::ubigint jrefAdmin = 0, const bool pnladminAvail = false, const Sbecore::ubigint jrefGlobal = 0, const bool pnlglobalAvail = false, const Sbecore::ubigint jrefProject = 0, const bool pnlprojectAvail = false, const Sbecore::ubigint jrefDbstr = 0, const bool pnldbstrAvail = false, const Sbecore::ubigint jrefUix = 0, const bool pnluixAvail = false, const Sbecore::ubigint jrefComp = 0, const bool pnlcompAvail = false, const Sbecore::ubigint jrefJob = 0, const bool pnljobAvail = false, const Sbecore::ubigint jrefDeploy = 0, const bool pnldeployAvail = false, const Sbecore::ubigint jrefAppdev = 0, const bool pnlappdevAvail = false, const Sbecore::ubigint jrefAuxfct = 0, const bool pnlauxfctAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MspCrd2Avail = true, const bool MitCrdLocAvail = true, const bool MitCrdTagAvail = true, const bool MitCrdCtpAvail = true, const bool MitCrdMchAvail = true, const bool MitCrdLibAvail = true, const bool MspCrd3Avail = true, const bool MitCrdPrjAvail = true, const bool MitCrdVerAvail = true, const bool MitCrdCapAvail = true, const bool MitCrdCapActive = true, const bool MitCrdErrAvail = true, const bool MitCrdErrActive = true, const bool MspCrd4Avail = true, const bool MitCrdTblAvail = true, const bool MitCrdTblActive = true, const bool MitCrdTcoAvail = true, const bool MitCrdTcoActive = true, const bool MitCrdSbsAvail = true, const bool MitCrdSbsActive = true, const bool MitCrdRelAvail = true, const bool MitCrdRelActive = true, const bool MitCrdVecAvail = true, const bool MitCrdVecActive = true, const bool MitCrdVitAvail = true, const bool MitCrdVitActive = true, const bool MitCrdChkAvail = true, const bool MitCrdChkActive = true, const bool MitCrdStbAvail = true, const bool MitCrdStbActive = true, const bool MitCrdIexAvail = true, const bool MitCrdIexActive = true, const bool MitCrdImeAvail = true, const bool MitCrdImeActive = true, const bool MspCrd5Avail = true, const bool MitCrdPstAvail = true, const bool MitCrdPstActive = true, const bool MitCrdMdlAvail = true, const bool MitCrdMdlActive = true, const bool MitCrdCarAvail = true, const bool MitCrdCarActive = true, const bool MitCrdDlgAvail = true, const bool MitCrdDlgActive = true, const bool MitCrdPnlAvail = true, const bool MitCrdPnlActive = true, const bool MitCrdQryAvail = true, const bool MitCrdQryActive = true, const bool MitCrdQcoAvail = true, const bool MitCrdQcoActive = true, const bool MitCrdQmdAvail = true, const bool MitCrdQmdActive = true, const bool MitCrdConAvail = true, const bool MitCrdConActive = true, const bool MspCrd6Avail = true, const bool MitCrdOpkAvail = true, const bool MitCrdOpkActive = true, const bool MitCrdOpxAvail = true, const bool MitCrdOpxActive = true, const bool MspCrd7Avail = true, const bool MitCrdJobAvail = true, const bool MitCrdJobActive = true, const bool MitCrdSgeAvail = true, const bool MitCrdSgeActive = true, const bool MitCrdMtdAvail = true, const bool MitCrdMtdActive = true, const bool MitCrdBlkAvail = true, const bool MitCrdBlkActive = true, const bool MitCrdCalAvail = true, const bool MitCrdCalActive = true, const bool MspCrd8Avail = true, const bool MitCrdCmpAvail = true, const bool MitCrdRlsAvail = true, const bool MitCrdRlsActive = true, const bool MspCrd9Avail = true, const bool MitCrdAppAvail = true, const bool MitCrdRtjAvail = true, const bool MitCrdRtjActive = true, const bool MitCrdEvtAvail = true, const bool MitCrdEvtActive = true, const bool MitCrdSeqAvail = true, const bool MitCrdSeqActive = true, const bool MitCrdSteAvail = true, const bool MitCrdSteActive = true, const bool MspCrd10Avail = true, const bool MitCrdUtlAvail = true, const bool MspApp2Avail = true, const bool MitAppMlcAvail = true, const bool MitAppLoiAvail = true);

	public:
		Sbecore::ubigint jrefDlgloaini;
		Sbecore::ubigint jrefDlgmnglic;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefPre;
		bool pnlpreAvail;
		Sbecore::ubigint jrefAdmin;
		bool pnladminAvail;
		Sbecore::ubigint jrefGlobal;
		bool pnlglobalAvail;
		Sbecore::ubigint jrefProject;
		bool pnlprojectAvail;
		Sbecore::ubigint jrefDbstr;
		bool pnldbstrAvail;
		Sbecore::ubigint jrefUix;
		bool pnluixAvail;
		Sbecore::ubigint jrefComp;
		bool pnlcompAvail;
		Sbecore::ubigint jrefJob;
		bool pnljobAvail;
		Sbecore::ubigint jrefDeploy;
		bool pnldeployAvail;
		Sbecore::ubigint jrefAppdev;
		bool pnlappdevAvail;
		Sbecore::ubigint jrefAuxfct;
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
		bool MitCrdAppAvail;
		bool MitCrdRtjAvail;
		bool MitCrdRtjActive;
		bool MitCrdEvtAvail;
		bool MitCrdEvtActive;
		bool MitCrdSeqAvail;
		bool MitCrdSeqActive;
		bool MitCrdSteAvail;
		bool MitCrdSteActive;
		bool MspCrd10Avail;
		bool MitCrdUtlAvail;
		bool MspApp2Avail;
		bool MitAppMlcAvail;
		bool MitAppLoiAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNav)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmNavData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalPnlpreAvail(DbsWznm* dbswznm);
	bool evalPnladminAvail(DbsWznm* dbswznm);
	bool evalPnlglobalAvail(DbsWznm* dbswznm);
	bool evalPnlprojectAvail(DbsWznm* dbswznm);
	bool evalPnldbstrAvail(DbsWznm* dbswznm);
	bool evalPnluixAvail(DbsWznm* dbswznm);
	bool evalPnlcompAvail(DbsWznm* dbswznm);
	bool evalPnljobAvail(DbsWznm* dbswznm);
	bool evalPnldeployAvail(DbsWznm* dbswznm);
	bool evalPnlappdevAvail(DbsWznm* dbswznm);
	bool evalPnlauxfctAvail(DbsWznm* dbswznm);
	bool evalMitSesSpsAvail(DbsWznm* dbswznm);
	bool evalMspCrd1Avail(DbsWznm* dbswznm);
	bool evalMitCrdUsgAvail(DbsWznm* dbswznm);
	bool evalMitCrdUsrAvail(DbsWznm* dbswznm);
	bool evalMitCrdPrsAvail(DbsWznm* dbswznm);
	bool evalMitCrdFilAvail(DbsWznm* dbswznm);
	bool evalMspCrd2Avail(DbsWznm* dbswznm);
	bool evalMitCrdLocAvail(DbsWznm* dbswznm);
	bool evalMitCrdTagAvail(DbsWznm* dbswznm);
	bool evalMitCrdCtpAvail(DbsWznm* dbswznm);
	bool evalMitCrdMchAvail(DbsWznm* dbswznm);
	bool evalMitCrdLibAvail(DbsWznm* dbswznm);
	bool evalMspCrd3Avail(DbsWznm* dbswznm);
	bool evalMitCrdPrjAvail(DbsWznm* dbswznm);
	bool evalMitCrdVerAvail(DbsWznm* dbswznm);
	bool evalMitCrdCapAvail(DbsWznm* dbswznm);
	bool evalMitCrdCapActive(DbsWznm* dbswznm);
	bool evalMitCrdErrAvail(DbsWznm* dbswznm);
	bool evalMitCrdErrActive(DbsWznm* dbswznm);
	bool evalMspCrd4Avail(DbsWznm* dbswznm);
	bool evalMitCrdTblAvail(DbsWznm* dbswznm);
	bool evalMitCrdTblActive(DbsWznm* dbswznm);
	bool evalMitCrdTcoAvail(DbsWznm* dbswznm);
	bool evalMitCrdTcoActive(DbsWznm* dbswznm);
	bool evalMitCrdSbsAvail(DbsWznm* dbswznm);
	bool evalMitCrdSbsActive(DbsWznm* dbswznm);
	bool evalMitCrdRelAvail(DbsWznm* dbswznm);
	bool evalMitCrdRelActive(DbsWznm* dbswznm);
	bool evalMitCrdVecAvail(DbsWznm* dbswznm);
	bool evalMitCrdVecActive(DbsWznm* dbswznm);
	bool evalMitCrdVitAvail(DbsWznm* dbswznm);
	bool evalMitCrdVitActive(DbsWznm* dbswznm);
	bool evalMitCrdChkAvail(DbsWznm* dbswznm);
	bool evalMitCrdChkActive(DbsWznm* dbswznm);
	bool evalMitCrdStbAvail(DbsWznm* dbswznm);
	bool evalMitCrdStbActive(DbsWznm* dbswznm);
	bool evalMitCrdIexAvail(DbsWznm* dbswznm);
	bool evalMitCrdIexActive(DbsWznm* dbswznm);
	bool evalMitCrdImeAvail(DbsWznm* dbswznm);
	bool evalMitCrdImeActive(DbsWznm* dbswznm);
	bool evalMspCrd5Avail(DbsWznm* dbswznm);
	bool evalMitCrdPstAvail(DbsWznm* dbswznm);
	bool evalMitCrdPstActive(DbsWznm* dbswznm);
	bool evalMitCrdMdlAvail(DbsWznm* dbswznm);
	bool evalMitCrdMdlActive(DbsWznm* dbswznm);
	bool evalMitCrdCarAvail(DbsWznm* dbswznm);
	bool evalMitCrdCarActive(DbsWznm* dbswznm);
	bool evalMitCrdDlgAvail(DbsWznm* dbswznm);
	bool evalMitCrdDlgActive(DbsWznm* dbswznm);
	bool evalMitCrdPnlAvail(DbsWznm* dbswznm);
	bool evalMitCrdPnlActive(DbsWznm* dbswznm);
	bool evalMitCrdQryAvail(DbsWznm* dbswznm);
	bool evalMitCrdQryActive(DbsWznm* dbswznm);
	bool evalMitCrdQcoAvail(DbsWznm* dbswznm);
	bool evalMitCrdQcoActive(DbsWznm* dbswznm);
	bool evalMitCrdQmdAvail(DbsWznm* dbswznm);
	bool evalMitCrdQmdActive(DbsWznm* dbswznm);
	bool evalMitCrdConAvail(DbsWznm* dbswznm);
	bool evalMitCrdConActive(DbsWznm* dbswznm);
	bool evalMspCrd6Avail(DbsWznm* dbswznm);
	bool evalMitCrdOpkAvail(DbsWznm* dbswznm);
	bool evalMitCrdOpkActive(DbsWznm* dbswznm);
	bool evalMitCrdOpxAvail(DbsWznm* dbswznm);
	bool evalMitCrdOpxActive(DbsWznm* dbswznm);
	bool evalMspCrd7Avail(DbsWznm* dbswznm);
	bool evalMitCrdJobAvail(DbsWznm* dbswznm);
	bool evalMitCrdJobActive(DbsWznm* dbswznm);
	bool evalMitCrdSgeAvail(DbsWznm* dbswznm);
	bool evalMitCrdSgeActive(DbsWznm* dbswznm);
	bool evalMitCrdMtdAvail(DbsWznm* dbswznm);
	bool evalMitCrdMtdActive(DbsWznm* dbswznm);
	bool evalMitCrdBlkAvail(DbsWznm* dbswznm);
	bool evalMitCrdBlkActive(DbsWznm* dbswznm);
	bool evalMitCrdCalAvail(DbsWznm* dbswznm);
	bool evalMitCrdCalActive(DbsWznm* dbswznm);
	bool evalMspCrd8Avail(DbsWznm* dbswznm);
	bool evalMitCrdCmpAvail(DbsWznm* dbswznm);
	bool evalMitCrdRlsAvail(DbsWznm* dbswznm);
	bool evalMitCrdRlsActive(DbsWznm* dbswznm);
	bool evalMspCrd9Avail(DbsWznm* dbswznm);
	bool evalMitCrdAppAvail(DbsWznm* dbswznm);
	bool evalMitCrdRtjAvail(DbsWznm* dbswznm);
	bool evalMitCrdRtjActive(DbsWznm* dbswznm);
	bool evalMitCrdEvtAvail(DbsWznm* dbswznm);
	bool evalMitCrdEvtActive(DbsWznm* dbswznm);
	bool evalMitCrdSeqAvail(DbsWznm* dbswznm);
	bool evalMitCrdSeqActive(DbsWznm* dbswznm);
	bool evalMitCrdSteAvail(DbsWznm* dbswznm);
	bool evalMitCrdSteActive(DbsWznm* dbswznm);
	bool evalMspCrd10Avail(DbsWznm* dbswznm);
	bool evalMitCrdUtlAvail(DbsWznm* dbswznm);
	bool evalMspApp2Avail(DbsWznm* dbswznm);
	bool evalMitAppMlcAvail(DbsWznm* dbswznm);
	bool evalMitAppLoiAvail(DbsWznm* dbswznm);

public:
	CrdWznmNav(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~CrdWznmNav();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlWznmNavAuxfct* pnlauxfct;
	PnlWznmNavAppdev* pnlappdev;
	PnlWznmNavJob* pnljob;
	PnlWznmNavDeploy* pnldeploy;
	PnlWznmNavComp* pnlcomp;
	PnlWznmNavUix* pnluix;
	PnlWznmNavDbstr* pnldbstr;
	PnlWznmNavProject* pnlproject;
	PnlWznmNavGlobal* pnlglobal;
	PnlWznmNavAdmin* pnladmin;
	PnlWznmNavPre* pnlpre;
	PnlWznmNavHeadbar* pnlheadbar;
	DlgWznmNavLoaini* dlgloaini;
	DlgWznmNavMnglic* dlgmnglic;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void warnTerm(DbsWznm* dbswznm);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

	void handleDpchAppDoClose(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitSesSpsClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitSesTrmClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdFilClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdLocClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdTagClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdCtpClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdMchClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdLibClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdPrjClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdVerClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdCapClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdErrClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdTblClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdTcoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdSbsClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdRelClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdVecClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdVitClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdChkClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdStbClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdIexClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdImeClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdPstClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdMdlClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdCarClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdDlgClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdPnlClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdQryClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdQcoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdQmdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdConClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdOpkClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdOpxClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdJobClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdSgeClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdMtdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdBlkClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdCalClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdCmpClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdRlsClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdAppClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdRtjClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdEvtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdSeqClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdSteClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdUtlClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitAppMlcClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmDlgClose(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrwznmabt(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrwznmabt(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrwznmtrm(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrwznmtrm(DbsWznm* dbswznm);

};

#endif
