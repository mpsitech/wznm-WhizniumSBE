/**
	* \file PnlWznmTcoDetail.h
	* API code for job PnlWznmTcoDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMTCODETAIL_H
#define PNLWZNMTCODETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmTcoDetailDo PnlWznmTcoDetail::VecVDo

#define ContIacWznmTcoDetail PnlWznmTcoDetail::ContIac
#define ContInfWznmTcoDetail PnlWznmTcoDetail::ContInf
#define StatAppWznmTcoDetail PnlWznmTcoDetail::StatApp
#define StatShrWznmTcoDetail PnlWznmTcoDetail::StatShr
#define TagWznmTcoDetail PnlWznmTcoDetail::Tag

#define DpchAppWznmTcoDetailData PnlWznmTcoDetail::DpchAppData
#define DpchAppWznmTcoDetailDo PnlWznmTcoDetail::DpchAppDo
#define DpchEngWznmTcoDetailData PnlWznmTcoDetail::DpchEngData

/**
	* PnlWznmTcoDetail
	*/
namespace PnlWznmTcoDetail {
	/**
		* VecVDo (full: VecVWznmTcoDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTTBLVIEWCLICK = 2;
		static const Sbecore::uint BUTSBSVIEWCLICK = 3;
		static const Sbecore::uint BUTRELVIEWCLICK = 4;
		static const Sbecore::uint BUTFCUVIEWCLICK = 5;
		static const Sbecore::uint BUTOPTEDITCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmTcoDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint NUMFPUPFCT = 3;
		static const Sbecore::uint NUMFPUPSTY = 4;
		static const Sbecore::uint NUMFPUPAXF = 5;
		static const Sbecore::uint NUMSFLSTOPT = 6;
		static const Sbecore::uint TXFOPT = 7;
		static const Sbecore::uint CHKPNC = 8;
		static const Sbecore::uint CHKEPO = 9;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupFct = 1, const Sbecore::uint numFPupSty = 1, const Sbecore::uint numFPupAxf = 1, const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "", const bool ChkPnc = false, const bool ChkEpo = false);

	public:
		std::string TxfSho;
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupFct;
		Sbecore::uint numFPupSty;
		Sbecore::uint numFPupAxf;
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;
		bool ChkPnc;
		bool ChkEpo;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmTcoDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTBL = 2;
		static const Sbecore::uint TXTSBS = 3;
		static const Sbecore::uint TXTREL = 4;
		static const Sbecore::uint TXTFCU = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTbl = "", const std::string& TxtSbs = "", const std::string& TxtRel = "", const std::string& TxtFcu = "");

	public:
		std::string TxtSrf;
		std::string TxtTbl;
		std::string TxtSbs;
		std::string TxtRel;
		std::string TxtFcu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmTcoDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTOPTALT = 2;
		static const Sbecore::uint LSTOPTNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOptAlt = true, const Sbecore::uint LstOptNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstOptAlt;
		Sbecore::uint LstOptNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmTcoDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFSHOACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint TXTTBLACTIVE = 6;
		static const Sbecore::uint BUTTBLVIEWAVAIL = 7;
		static const Sbecore::uint BUTTBLVIEWACTIVE = 8;
		static const Sbecore::uint TXTSBSAVAIL = 9;
		static const Sbecore::uint TXTSBSACTIVE = 10;
		static const Sbecore::uint BUTSBSVIEWAVAIL = 11;
		static const Sbecore::uint BUTSBSVIEWACTIVE = 12;
		static const Sbecore::uint TXTRELAVAIL = 13;
		static const Sbecore::uint TXTRELACTIVE = 14;
		static const Sbecore::uint BUTRELVIEWAVAIL = 15;
		static const Sbecore::uint BUTRELVIEWACTIVE = 16;
		static const Sbecore::uint TXTFCUAVAIL = 17;
		static const Sbecore::uint TXTFCUACTIVE = 18;
		static const Sbecore::uint BUTFCUVIEWAVAIL = 19;
		static const Sbecore::uint BUTFCUVIEWACTIVE = 20;
		static const Sbecore::uint PUPSTYACTIVE = 21;
		static const Sbecore::uint PUPAXFACTIVE = 22;
		static const Sbecore::uint LSTOPTACTIVE = 23;
		static const Sbecore::uint TXFOPTVALID = 24;
		static const Sbecore::uint BUTOPTEDITAVAIL = 25;
		static const Sbecore::uint CHKPNCACTIVE = 26;
		static const Sbecore::uint CHKEPOACTIVE = 27;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupTypActive = true, const bool TxtTblActive = true, const bool ButTblViewAvail = true, const bool ButTblViewActive = true, const bool TxtSbsAvail = true, const bool TxtSbsActive = true, const bool ButSbsViewAvail = true, const bool ButSbsViewActive = true, const bool TxtRelAvail = true, const bool TxtRelActive = true, const bool ButRelViewAvail = true, const bool ButRelViewActive = true, const bool TxtFcuAvail = true, const bool TxtFcuActive = true, const bool ButFcuViewAvail = true, const bool ButFcuViewActive = true, const bool PupStyActive = true, const bool PupAxfActive = true, const bool LstOptActive = true, const bool TxfOptValid = false, const bool ButOptEditAvail = true, const bool ChkPncActive = true, const bool ChkEpoActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupTypActive;
		bool TxtTblActive;
		bool ButTblViewAvail;
		bool ButTblViewActive;
		bool TxtSbsAvail;
		bool TxtSbsActive;
		bool ButSbsViewAvail;
		bool ButSbsViewActive;
		bool TxtRelAvail;
		bool TxtRelActive;
		bool ButRelViewAvail;
		bool ButRelViewActive;
		bool TxtFcuAvail;
		bool TxtFcuActive;
		bool ButFcuViewAvail;
		bool ButFcuViewActive;
		bool PupStyActive;
		bool PupAxfActive;
		bool LstOptActive;
		bool TxfOptValid;
		bool ButOptEditAvail;
		bool ChkPncActive;
		bool ChkEpoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmTcoDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTSHO = 3;
		static const Sbecore::uint CPTTYP = 4;
		static const Sbecore::uint CPTTBL = 5;
		static const Sbecore::uint CPTSBS = 6;
		static const Sbecore::uint CPTREL = 7;
		static const Sbecore::uint CPTFCU = 8;
		static const Sbecore::uint CPTSTY = 9;
		static const Sbecore::uint CPTAXF = 10;
		static const Sbecore::uint CPTOPT = 11;
		static const Sbecore::uint CPTPNC = 12;
		static const Sbecore::uint CPTEPO = 13;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptSho = "", const std::string& CptTyp = "", const std::string& CptTbl = "", const std::string& CptSbs = "", const std::string& CptRel = "", const std::string& CptFcu = "", const std::string& CptSty = "", const std::string& CptAxf = "", const std::string& CptOpt = "", const std::string& CptPnc = "", const std::string& CptEpo = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptSho;
		std::string CptTyp;
		std::string CptTbl;
		std::string CptSbs;
		std::string CptRel;
		std::string CptFcu;
		std::string CptSty;
		std::string CptAxf;
		std::string CptOpt;
		std::string CptPnc;
		std::string CptEpo;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmTcoDetailData)
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
		* DpchAppDo (full: DpchAppWznmTcoDetailDo)
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
		* DpchEngData (full: DpchEngWznmTcoDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOPT = 4;
		static const Sbecore::uint FEEDFPUPAXF = 5;
		static const Sbecore::uint FEEDFPUPFCT = 6;
		static const Sbecore::uint FEEDFPUPSTY = 7;
		static const Sbecore::uint FEEDFPUPTYP = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstOpt;
		Sbecore::Feed feedFPupAxf;
		Sbecore::Feed feedFPupFct;
		Sbecore::Feed feedFPupSty;
		Sbecore::Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
