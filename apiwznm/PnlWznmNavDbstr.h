/**
	* \file PnlWznmNavDbstr.h
	* API code for job PnlWznmNavDbstr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVDBSTR_H
#define PNLWZNMNAVDBSTR_H

#include "ApiWznm_blks.h"

#define VecVWznmNavDbstrDo PnlWznmNavDbstr::VecVDo

#define ContIacWznmNavDbstr PnlWznmNavDbstr::ContIac
#define StatAppWznmNavDbstr PnlWznmNavDbstr::StatApp
#define StatShrWznmNavDbstr PnlWznmNavDbstr::StatShr
#define TagWznmNavDbstr PnlWznmNavDbstr::Tag

#define DpchAppWznmNavDbstrData PnlWznmNavDbstr::DpchAppData
#define DpchAppWznmNavDbstrDo PnlWznmNavDbstr::DpchAppDo
#define DpchEngWznmNavDbstrData PnlWznmNavDbstr::DpchEngData

/**
	* PnlWznmNavDbstr
	*/
namespace PnlWznmNavDbstr {
	/**
		* VecVDo (full: VecVWznmNavDbstrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTTBLVIEWCLICK = 1;
		static const Sbecore::uint BUTTBLNEWCRDCLICK = 2;
		static const Sbecore::uint BUTTCOVIEWCLICK = 3;
		static const Sbecore::uint BUTTCONEWCRDCLICK = 4;
		static const Sbecore::uint BUTSBSVIEWCLICK = 5;
		static const Sbecore::uint BUTSBSNEWCRDCLICK = 6;
		static const Sbecore::uint BUTRELVIEWCLICK = 7;
		static const Sbecore::uint BUTRELNEWCRDCLICK = 8;
		static const Sbecore::uint BUTVECVIEWCLICK = 9;
		static const Sbecore::uint BUTVECNEWCRDCLICK = 10;
		static const Sbecore::uint BUTVITVIEWCLICK = 11;
		static const Sbecore::uint BUTVITNEWCRDCLICK = 12;
		static const Sbecore::uint BUTCHKVIEWCLICK = 13;
		static const Sbecore::uint BUTCHKNEWCRDCLICK = 14;
		static const Sbecore::uint BUTSTBVIEWCLICK = 15;
		static const Sbecore::uint BUTSTBNEWCRDCLICK = 16;
		static const Sbecore::uint BUTIEXVIEWCLICK = 17;
		static const Sbecore::uint BUTIEXNEWCRDCLICK = 18;
		static const Sbecore::uint BUTIMEVIEWCLICK = 19;
		static const Sbecore::uint BUTIMENEWCRDCLICK = 20;
		static const Sbecore::uint BUTIELVIEWCLICK = 21;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavDbstr)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTTBL = 1;
		static const Sbecore::uint NUMFLSTTCO = 2;
		static const Sbecore::uint NUMFLSTSBS = 3;
		static const Sbecore::uint NUMFLSTREL = 4;
		static const Sbecore::uint NUMFLSTVEC = 5;
		static const Sbecore::uint NUMFLSTVIT = 6;
		static const Sbecore::uint NUMFLSTCHK = 7;
		static const Sbecore::uint NUMFLSTSTB = 8;
		static const Sbecore::uint NUMFLSTIEX = 9;
		static const Sbecore::uint NUMFLSTIME = 10;
		static const Sbecore::uint NUMFLSTIEL = 11;

	public:
		ContIac(const Sbecore::uint numFLstTbl = 1, const Sbecore::uint numFLstTco = 1, const Sbecore::uint numFLstSbs = 1, const Sbecore::uint numFLstRel = 1, const Sbecore::uint numFLstVec = 1, const Sbecore::uint numFLstVit = 1, const Sbecore::uint numFLstChk = 1, const Sbecore::uint numFLstStb = 1, const Sbecore::uint numFLstIex = 1, const Sbecore::uint numFLstIme = 1, const Sbecore::uint numFLstIel = 1);

	public:
		Sbecore::uint numFLstTbl;
		Sbecore::uint numFLstTco;
		Sbecore::uint numFLstSbs;
		Sbecore::uint numFLstRel;
		Sbecore::uint numFLstVec;
		Sbecore::uint numFLstVit;
		Sbecore::uint numFLstChk;
		Sbecore::uint numFLstStb;
		Sbecore::uint numFLstIex;
		Sbecore::uint numFLstIme;
		Sbecore::uint numFLstIel;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNavDbstr)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTTBLALT = 2;
		static const Sbecore::uint LSTTCOALT = 3;
		static const Sbecore::uint LSTSBSALT = 4;
		static const Sbecore::uint LSTRELALT = 5;
		static const Sbecore::uint LSTVECALT = 6;
		static const Sbecore::uint LSTVITALT = 7;
		static const Sbecore::uint LSTCHKALT = 8;
		static const Sbecore::uint LSTSTBALT = 9;
		static const Sbecore::uint LSTIEXALT = 10;
		static const Sbecore::uint LSTIMEALT = 11;
		static const Sbecore::uint LSTIELALT = 12;
		static const Sbecore::uint LSTTBLNUMFIRSTDISP = 13;
		static const Sbecore::uint LSTTCONUMFIRSTDISP = 14;
		static const Sbecore::uint LSTSBSNUMFIRSTDISP = 15;
		static const Sbecore::uint LSTRELNUMFIRSTDISP = 16;
		static const Sbecore::uint LSTVECNUMFIRSTDISP = 17;
		static const Sbecore::uint LSTVITNUMFIRSTDISP = 18;
		static const Sbecore::uint LSTCHKNUMFIRSTDISP = 19;
		static const Sbecore::uint LSTSTBNUMFIRSTDISP = 20;
		static const Sbecore::uint LSTIEXNUMFIRSTDISP = 21;
		static const Sbecore::uint LSTIMENUMFIRSTDISP = 22;
		static const Sbecore::uint LSTIELNUMFIRSTDISP = 23;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstTblAlt = true, const bool LstTcoAlt = true, const bool LstSbsAlt = true, const bool LstRelAlt = true, const bool LstVecAlt = true, const bool LstVitAlt = true, const bool LstChkAlt = true, const bool LstStbAlt = true, const bool LstIexAlt = true, const bool LstImeAlt = true, const bool LstIelAlt = true, const Sbecore::uint LstTblNumFirstdisp = 1, const Sbecore::uint LstTcoNumFirstdisp = 1, const Sbecore::uint LstSbsNumFirstdisp = 1, const Sbecore::uint LstRelNumFirstdisp = 1, const Sbecore::uint LstVecNumFirstdisp = 1, const Sbecore::uint LstVitNumFirstdisp = 1, const Sbecore::uint LstChkNumFirstdisp = 1, const Sbecore::uint LstStbNumFirstdisp = 1, const Sbecore::uint LstIexNumFirstdisp = 1, const Sbecore::uint LstImeNumFirstdisp = 1, const Sbecore::uint LstIelNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstTblAlt;
		bool LstTcoAlt;
		bool LstSbsAlt;
		bool LstRelAlt;
		bool LstVecAlt;
		bool LstVitAlt;
		bool LstChkAlt;
		bool LstStbAlt;
		bool LstIexAlt;
		bool LstImeAlt;
		bool LstIelAlt;
		Sbecore::uint LstTblNumFirstdisp;
		Sbecore::uint LstTcoNumFirstdisp;
		Sbecore::uint LstSbsNumFirstdisp;
		Sbecore::uint LstRelNumFirstdisp;
		Sbecore::uint LstVecNumFirstdisp;
		Sbecore::uint LstVitNumFirstdisp;
		Sbecore::uint LstChkNumFirstdisp;
		Sbecore::uint LstStbNumFirstdisp;
		Sbecore::uint LstIexNumFirstdisp;
		Sbecore::uint LstImeNumFirstdisp;
		Sbecore::uint LstIelNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavDbstr)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTTBLAVAIL = 1;
		static const Sbecore::uint BUTTBLVIEWACTIVE = 2;
		static const Sbecore::uint BUTTBLNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTTCOAVAIL = 4;
		static const Sbecore::uint BUTTCOVIEWACTIVE = 5;
		static const Sbecore::uint BUTTCONEWCRDACTIVE = 6;
		static const Sbecore::uint LSTSBSAVAIL = 7;
		static const Sbecore::uint BUTSBSVIEWACTIVE = 8;
		static const Sbecore::uint BUTSBSNEWCRDACTIVE = 9;
		static const Sbecore::uint LSTRELAVAIL = 10;
		static const Sbecore::uint BUTRELVIEWACTIVE = 11;
		static const Sbecore::uint BUTRELNEWCRDACTIVE = 12;
		static const Sbecore::uint LSTVECAVAIL = 13;
		static const Sbecore::uint BUTVECVIEWACTIVE = 14;
		static const Sbecore::uint BUTVECNEWCRDACTIVE = 15;
		static const Sbecore::uint LSTVITAVAIL = 16;
		static const Sbecore::uint BUTVITVIEWACTIVE = 17;
		static const Sbecore::uint BUTVITNEWCRDACTIVE = 18;
		static const Sbecore::uint LSTCHKAVAIL = 19;
		static const Sbecore::uint BUTCHKVIEWACTIVE = 20;
		static const Sbecore::uint BUTCHKNEWCRDACTIVE = 21;
		static const Sbecore::uint LSTSTBAVAIL = 22;
		static const Sbecore::uint BUTSTBVIEWACTIVE = 23;
		static const Sbecore::uint BUTSTBNEWCRDACTIVE = 24;
		static const Sbecore::uint LSTIEXAVAIL = 25;
		static const Sbecore::uint BUTIEXVIEWACTIVE = 26;
		static const Sbecore::uint BUTIEXNEWCRDACTIVE = 27;
		static const Sbecore::uint LSTIMEAVAIL = 28;
		static const Sbecore::uint BUTIMEVIEWACTIVE = 29;
		static const Sbecore::uint BUTIMENEWCRDACTIVE = 30;
		static const Sbecore::uint LSTIELAVAIL = 31;
		static const Sbecore::uint BUTIELVIEWACTIVE = 32;

	public:
		StatShr(const bool LstTblAvail = true, const bool ButTblViewActive = true, const bool ButTblNewcrdActive = true, const bool LstTcoAvail = true, const bool ButTcoViewActive = true, const bool ButTcoNewcrdActive = true, const bool LstSbsAvail = true, const bool ButSbsViewActive = true, const bool ButSbsNewcrdActive = true, const bool LstRelAvail = true, const bool ButRelViewActive = true, const bool ButRelNewcrdActive = true, const bool LstVecAvail = true, const bool ButVecViewActive = true, const bool ButVecNewcrdActive = true, const bool LstVitAvail = true, const bool ButVitViewActive = true, const bool ButVitNewcrdActive = true, const bool LstChkAvail = true, const bool ButChkViewActive = true, const bool ButChkNewcrdActive = true, const bool LstStbAvail = true, const bool ButStbViewActive = true, const bool ButStbNewcrdActive = true, const bool LstIexAvail = true, const bool ButIexViewActive = true, const bool ButIexNewcrdActive = true, const bool LstImeAvail = true, const bool ButImeViewActive = true, const bool ButImeNewcrdActive = true, const bool LstIelAvail = true, const bool ButIelViewActive = true);

	public:
		bool LstTblAvail;
		bool ButTblViewActive;
		bool ButTblNewcrdActive;
		bool LstTcoAvail;
		bool ButTcoViewActive;
		bool ButTcoNewcrdActive;
		bool LstSbsAvail;
		bool ButSbsViewActive;
		bool ButSbsNewcrdActive;
		bool LstRelAvail;
		bool ButRelViewActive;
		bool ButRelNewcrdActive;
		bool LstVecAvail;
		bool ButVecViewActive;
		bool ButVecNewcrdActive;
		bool LstVitAvail;
		bool ButVitViewActive;
		bool ButVitNewcrdActive;
		bool LstChkAvail;
		bool ButChkViewActive;
		bool ButChkNewcrdActive;
		bool LstStbAvail;
		bool ButStbViewActive;
		bool ButStbNewcrdActive;
		bool LstIexAvail;
		bool ButIexViewActive;
		bool ButIexNewcrdActive;
		bool LstImeAvail;
		bool ButImeViewActive;
		bool ButImeNewcrdActive;
		bool LstIelAvail;
		bool ButIelViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavDbstr)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTTBL = 2;
		static const Sbecore::uint CPTTCO = 3;
		static const Sbecore::uint CPTSBS = 4;
		static const Sbecore::uint CPTREL = 5;
		static const Sbecore::uint CPTVEC = 6;
		static const Sbecore::uint CPTVIT = 7;
		static const Sbecore::uint CPTCHK = 8;
		static const Sbecore::uint CPTSTB = 9;
		static const Sbecore::uint CPTIEX = 10;
		static const Sbecore::uint CPTIME = 11;
		static const Sbecore::uint CPTIEL = 12;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptTbl = "", const std::string& CptTco = "", const std::string& CptSbs = "", const std::string& CptRel = "", const std::string& CptVec = "", const std::string& CptVit = "", const std::string& CptChk = "", const std::string& CptStb = "", const std::string& CptIex = "", const std::string& CptIme = "", const std::string& CptIel = "");

	public:
		std::string Cpt;
		std::string CptTbl;
		std::string CptTco;
		std::string CptSbs;
		std::string CptRel;
		std::string CptVec;
		std::string CptVit;
		std::string CptChk;
		std::string CptStb;
		std::string CptIex;
		std::string CptIme;
		std::string CptIel;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavDbstrData)
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
		* DpchAppDo (full: DpchAppWznmNavDbstrDo)
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
		* DpchEngData (full: DpchEngWznmNavDbstrData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCHK = 3;
		static const Sbecore::uint FEEDFLSTIEL = 4;
		static const Sbecore::uint FEEDFLSTIEX = 5;
		static const Sbecore::uint FEEDFLSTIME = 6;
		static const Sbecore::uint FEEDFLSTREL = 7;
		static const Sbecore::uint FEEDFLSTSBS = 8;
		static const Sbecore::uint FEEDFLSTSTB = 9;
		static const Sbecore::uint FEEDFLSTTBL = 10;
		static const Sbecore::uint FEEDFLSTTCO = 11;
		static const Sbecore::uint FEEDFLSTVEC = 12;
		static const Sbecore::uint FEEDFLSTVIT = 13;
		static const Sbecore::uint STATAPP = 14;
		static const Sbecore::uint STATSHR = 15;
		static const Sbecore::uint TAG = 16;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstChk;
		Sbecore::Xmlio::Feed feedFLstIel;
		Sbecore::Xmlio::Feed feedFLstIex;
		Sbecore::Xmlio::Feed feedFLstIme;
		Sbecore::Xmlio::Feed feedFLstRel;
		Sbecore::Xmlio::Feed feedFLstSbs;
		Sbecore::Xmlio::Feed feedFLstStb;
		Sbecore::Xmlio::Feed feedFLstTbl;
		Sbecore::Xmlio::Feed feedFLstTco;
		Sbecore::Xmlio::Feed feedFLstVec;
		Sbecore::Xmlio::Feed feedFLstVit;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
