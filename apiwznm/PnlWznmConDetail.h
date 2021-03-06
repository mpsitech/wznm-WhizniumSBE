/**
	* \file PnlWznmConDetail.h
	* API code for job PnlWznmConDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMCONDETAIL_H
#define PNLWZNMCONDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmConDetailDo PnlWznmConDetail::VecVDo

#define ContIacWznmConDetail PnlWznmConDetail::ContIac
#define ContInfWznmConDetail PnlWznmConDetail::ContInf
#define StatAppWznmConDetail PnlWznmConDetail::StatApp
#define StatShrWznmConDetail PnlWznmConDetail::StatShr
#define TagWznmConDetail PnlWznmConDetail::Tag

#define DpchAppWznmConDetailData PnlWznmConDetail::DpchAppData
#define DpchAppWznmConDetailDo PnlWznmConDetail::DpchAppDo
#define DpchEngWznmConDetailData PnlWznmConDetail::DpchEngData

/**
	* PnlWznmConDetail
	*/
namespace PnlWznmConDetail {
	/**
		* VecVDo (full: VecVWznmConDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJTIEDITCLICK = 2;
		static const Sbecore::uint BUTCLUVIEWCLICK = 3;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 4;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 5;
		static const Sbecore::uint BUTHKUVIEWCLICK = 6;
		static const Sbecore::uint BUTREUVIEWCLICK = 7;
		static const Sbecore::uint BUTSUPVIEWCLICK = 8;
		static const Sbecore::uint BUTTAGVIEWCLICK = 9;
		static const Sbecore::uint BUTSTSVIEWCLICK = 10;
		static const Sbecore::uint BUTSHSVIEWCLICK = 11;
		static const Sbecore::uint BUTOPTEDITCLICK = 12;
		static const Sbecore::uint BUTFEDNEWCLICK = 13;
		static const Sbecore::uint BUTFEDDELETECLICK = 14;
		static const Sbecore::uint BUTFEDSRUVIEWCLICK = 15;
		static const Sbecore::uint BUTFEDVITVIEWCLICK = 16;
		static const Sbecore::uint BUTFEDTAGVIEWCLICK = 17;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmConDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPJTI = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint NUMFLSTCLU = 3;
		static const Sbecore::uint NUMFPUPHKT = 4;
		static const Sbecore::uint NUMFPUPRET = 5;
		static const Sbecore::uint NUMFPUPSCO = 6;
		static const Sbecore::uint NUMFPUPSTY = 7;
		static const Sbecore::uint NUMFLSTTAG = 8;
		static const Sbecore::uint TXFTAG = 9;
		static const Sbecore::uint TXFAVL = 10;
		static const Sbecore::uint TXFACT = 11;
		static const Sbecore::uint NUMSFLSTOPT = 12;
		static const Sbecore::uint TXFOPT = 13;
		static const Sbecore::uint NUMFPUPFEDSRT = 14;
		static const Sbecore::uint NUMFLSTFEDVIT = 15;
		static const Sbecore::uint TXFFEDVIT = 16;
		static const Sbecore::uint NUMFLSTFEDTAG = 17;
		static const Sbecore::uint TXFFEDTAG = 18;
		static const Sbecore::uint TXFFEDCMT = 19;

	public:
		ContIac(const Sbecore::uint numFPupJti = 1, const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupHkt = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupSco = 1, const Sbecore::uint numFPupSty = 1, const Sbecore::uint numFLstTag = 1, const std::string& TxfTag = "", const std::string& TxfAvl = "", const std::string& TxfAct = "", const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "", const Sbecore::uint numFPupFedSrt = 1, const Sbecore::uint numFLstFedVit = 1, const std::string& TxfFedVit = "", const Sbecore::uint numFLstFedTag = 1, const std::string& TxfFedTag = "", const std::string& TxfFedCmt = "");

	public:
		Sbecore::uint numFPupJti;
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupHkt;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupSco;
		Sbecore::uint numFPupSty;
		Sbecore::uint numFLstTag;
		std::string TxfTag;
		std::string TxfAvl;
		std::string TxfAct;
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;
		Sbecore::uint numFPupFedSrt;
		Sbecore::uint numFLstFedVit;
		std::string TxfFedVit;
		Sbecore::uint numFLstFedTag;
		std::string TxfFedTag;
		std::string TxfFedCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmConDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTCLU = 3;
		static const Sbecore::uint TXTHKU = 4;
		static const Sbecore::uint TXTREU = 5;
		static const Sbecore::uint TXTSUP = 6;
		static const Sbecore::uint TXTSTS = 7;
		static const Sbecore::uint TXTSHS = 8;
		static const Sbecore::uint TXTFEDSRF = 9;
		static const Sbecore::uint TXTFEDSRU = 10;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtClu = "", const std::string& TxtHku = "", const std::string& TxtReu = "", const std::string& TxtSup = "", const std::string& TxtSts = "", const std::string& TxtShs = "", const std::string& TxtFedSrf = "", const std::string& TxtFedSru = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtClu;
		std::string TxtHku;
		std::string TxtReu;
		std::string TxtSup;
		std::string TxtSts;
		std::string TxtShs;
		std::string TxtFedSrf;
		std::string TxtFedSru;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmConDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTCLUALT = 2;
		static const Sbecore::uint LSTTAGALT = 3;
		static const Sbecore::uint LSTOPTALT = 4;
		static const Sbecore::uint LSTFEDVITALT = 5;
		static const Sbecore::uint LSTFEDTAGALT = 6;
		static const Sbecore::uint LSTCLUNUMFIRSTDISP = 7;
		static const Sbecore::uint LSTTAGNUMFIRSTDISP = 8;
		static const Sbecore::uint LSTOPTNUMFIRSTDISP = 9;
		static const Sbecore::uint LSTFEDVITNUMFIRSTDISP = 10;
		static const Sbecore::uint LSTFEDTAGNUMFIRSTDISP = 11;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstCluAlt = true, const bool LstTagAlt = true, const bool LstOptAlt = true, const bool LstFedVitAlt = true, const bool LstFedTagAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1, const Sbecore::uint LstTagNumFirstdisp = 1, const Sbecore::uint LstOptNumFirstdisp = 1, const Sbecore::uint LstFedVitNumFirstdisp = 1, const Sbecore::uint LstFedTagNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstCluAlt;
		bool LstTagAlt;
		bool LstOptAlt;
		bool LstFedVitAlt;
		bool LstFedTagAlt;
		Sbecore::uint LstCluNumFirstdisp;
		Sbecore::uint LstTagNumFirstdisp;
		Sbecore::uint LstOptNumFirstdisp;
		Sbecore::uint LstFedVitNumFirstdisp;
		Sbecore::uint LstFedTagNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmConDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFTAGVALID = 1;
		static const Sbecore::uint TXFOPTVALID = 2;
		static const Sbecore::uint TXFFEDVITVALID = 3;
		static const Sbecore::uint TXFFEDTAGVALID = 4;
		static const Sbecore::uint BUTSAVEAVAIL = 5;
		static const Sbecore::uint BUTSAVEACTIVE = 6;
		static const Sbecore::uint TXTSRFACTIVE = 7;
		static const Sbecore::uint PUPJTIACTIVE = 8;
		static const Sbecore::uint BUTJTIEDITAVAIL = 9;
		static const Sbecore::uint TXTTITACTIVE = 10;
		static const Sbecore::uint PUPTYPACTIVE = 11;
		static const Sbecore::uint LSTCLUACTIVE = 12;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 13;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 14;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 15;
		static const Sbecore::uint TXTHKUACTIVE = 16;
		static const Sbecore::uint BUTHKUVIEWAVAIL = 17;
		static const Sbecore::uint BUTHKUVIEWACTIVE = 18;
		static const Sbecore::uint TXTREUACTIVE = 19;
		static const Sbecore::uint BUTREUVIEWAVAIL = 20;
		static const Sbecore::uint BUTREUVIEWACTIVE = 21;
		static const Sbecore::uint TXTSUPACTIVE = 22;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 23;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 24;
		static const Sbecore::uint PUPSCOACTIVE = 25;
		static const Sbecore::uint PUPSTYACTIVE = 26;
		static const Sbecore::uint LSTTAGACTIVE = 27;
		static const Sbecore::uint BUTTAGVIEWAVAIL = 28;
		static const Sbecore::uint BUTTAGVIEWACTIVE = 29;
		static const Sbecore::uint TXTSTSACTIVE = 30;
		static const Sbecore::uint BUTSTSVIEWAVAIL = 31;
		static const Sbecore::uint BUTSTSVIEWACTIVE = 32;
		static const Sbecore::uint TXTSHSACTIVE = 33;
		static const Sbecore::uint BUTSHSVIEWAVAIL = 34;
		static const Sbecore::uint BUTSHSVIEWACTIVE = 35;
		static const Sbecore::uint TXFAVLACTIVE = 36;
		static const Sbecore::uint TXFACTACTIVE = 37;
		static const Sbecore::uint LSTOPTACTIVE = 38;
		static const Sbecore::uint BUTOPTEDITAVAIL = 39;
		static const Sbecore::uint SEPFEDAVAIL = 40;
		static const Sbecore::uint HDGFEDAVAIL = 41;
		static const Sbecore::uint BUTFEDNEWAVAIL = 42;
		static const Sbecore::uint BUTFEDDELETEAVAIL = 43;
		static const Sbecore::uint TXTFEDSRFAVAIL = 44;
		static const Sbecore::uint TXTFEDSRFACTIVE = 45;
		static const Sbecore::uint TXTFEDSRUAVAIL = 46;
		static const Sbecore::uint TXTFEDSRUACTIVE = 47;
		static const Sbecore::uint BUTFEDSRUVIEWAVAIL = 48;
		static const Sbecore::uint BUTFEDSRUVIEWACTIVE = 49;
		static const Sbecore::uint LSTFEDVITAVAIL = 50;
		static const Sbecore::uint LSTFEDVITACTIVE = 51;
		static const Sbecore::uint BUTFEDVITVIEWAVAIL = 52;
		static const Sbecore::uint BUTFEDVITVIEWACTIVE = 53;
		static const Sbecore::uint LSTFEDTAGAVAIL = 54;
		static const Sbecore::uint LSTFEDTAGACTIVE = 55;
		static const Sbecore::uint BUTFEDTAGVIEWAVAIL = 56;
		static const Sbecore::uint BUTFEDTAGVIEWACTIVE = 57;
		static const Sbecore::uint TXFFEDCMTAVAIL = 58;
		static const Sbecore::uint TXFFEDCMTACTIVE = 59;

	public:
		StatShr(const bool TxfTagValid = false, const bool TxfOptValid = false, const bool TxfFedVitValid = false, const bool TxfFedTagValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool PupTypActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtHkuActive = true, const bool ButHkuViewAvail = true, const bool ButHkuViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool PupScoActive = true, const bool PupStyActive = true, const bool LstTagActive = true, const bool ButTagViewAvail = true, const bool ButTagViewActive = true, const bool TxtStsActive = true, const bool ButStsViewAvail = true, const bool ButStsViewActive = true, const bool TxtShsActive = true, const bool ButShsViewAvail = true, const bool ButShsViewActive = true, const bool TxfAvlActive = true, const bool TxfActActive = true, const bool LstOptActive = true, const bool ButOptEditAvail = true, const bool SepFedAvail = true, const bool HdgFedAvail = true, const bool ButFedNewAvail = true, const bool ButFedDeleteAvail = true, const bool TxtFedSrfAvail = true, const bool TxtFedSrfActive = true, const bool TxtFedSruAvail = true, const bool TxtFedSruActive = true, const bool ButFedSruViewAvail = true, const bool ButFedSruViewActive = true, const bool LstFedVitAvail = true, const bool LstFedVitActive = true, const bool ButFedVitViewAvail = true, const bool ButFedVitViewActive = true, const bool LstFedTagAvail = true, const bool LstFedTagActive = true, const bool ButFedTagViewAvail = true, const bool ButFedTagViewActive = true, const bool TxfFedCmtAvail = true, const bool TxfFedCmtActive = true);

	public:
		bool TxfTagValid;
		bool TxfOptValid;
		bool TxfFedVitValid;
		bool TxfFedTagValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool PupTypActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtHkuActive;
		bool ButHkuViewAvail;
		bool ButHkuViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool PupScoActive;
		bool PupStyActive;
		bool LstTagActive;
		bool ButTagViewAvail;
		bool ButTagViewActive;
		bool TxtStsActive;
		bool ButStsViewAvail;
		bool ButStsViewActive;
		bool TxtShsActive;
		bool ButShsViewAvail;
		bool ButShsViewActive;
		bool TxfAvlActive;
		bool TxfActActive;
		bool LstOptActive;
		bool ButOptEditAvail;
		bool SepFedAvail;
		bool HdgFedAvail;
		bool ButFedNewAvail;
		bool ButFedDeleteAvail;
		bool TxtFedSrfAvail;
		bool TxtFedSrfActive;
		bool TxtFedSruAvail;
		bool TxtFedSruActive;
		bool ButFedSruViewAvail;
		bool ButFedSruViewActive;
		bool LstFedVitAvail;
		bool LstFedVitActive;
		bool ButFedVitViewAvail;
		bool ButFedVitViewActive;
		bool LstFedTagAvail;
		bool LstFedTagActive;
		bool ButFedTagViewAvail;
		bool ButFedTagViewActive;
		bool TxfFedCmtAvail;
		bool TxfFedCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmConDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTTYP = 4;
		static const Sbecore::uint CPTCLU = 5;
		static const Sbecore::uint CPTHKU = 6;
		static const Sbecore::uint CPTREU = 7;
		static const Sbecore::uint CPTSUP = 8;
		static const Sbecore::uint CPTSCO = 9;
		static const Sbecore::uint CPTSTY = 10;
		static const Sbecore::uint CPTTAG = 11;
		static const Sbecore::uint CPTSTS = 12;
		static const Sbecore::uint CPTSHS = 13;
		static const Sbecore::uint CPTAVL = 14;
		static const Sbecore::uint CPTACT = 15;
		static const Sbecore::uint CPTOPT = 16;
		static const Sbecore::uint HDGFED = 17;
		static const Sbecore::uint CPTFEDSRF = 18;
		static const Sbecore::uint CPTFEDSRU = 19;
		static const Sbecore::uint CPTFEDVIT = 20;
		static const Sbecore::uint CPTFEDTAG = 21;
		static const Sbecore::uint CPTFEDCMT = 22;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptTyp = "", const std::string& CptClu = "", const std::string& CptHku = "", const std::string& CptReu = "", const std::string& CptSup = "", const std::string& CptSco = "", const std::string& CptSty = "", const std::string& CptTag = "", const std::string& CptSts = "", const std::string& CptShs = "", const std::string& CptAvl = "", const std::string& CptAct = "", const std::string& CptOpt = "", const std::string& HdgFed = "", const std::string& CptFedSrf = "", const std::string& CptFedSru = "", const std::string& CptFedVit = "", const std::string& CptFedTag = "", const std::string& CptFedCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptTyp;
		std::string CptClu;
		std::string CptHku;
		std::string CptReu;
		std::string CptSup;
		std::string CptSco;
		std::string CptSty;
		std::string CptTag;
		std::string CptSts;
		std::string CptShs;
		std::string CptAvl;
		std::string CptAct;
		std::string CptOpt;
		std::string HdgFed;
		std::string CptFedSrf;
		std::string CptFedSru;
		std::string CptFedVit;
		std::string CptFedTag;
		std::string CptFedCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmConDetailData)
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
		* DpchAppDo (full: DpchAppWznmConDetailDo)
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
		* DpchEngData (full: DpchEngWznmConDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFLSTFEDTAG = 5;
		static const Sbecore::uint FEEDFLSTFEDVIT = 6;
		static const Sbecore::uint FEEDFLSTOPT = 7;
		static const Sbecore::uint FEEDFLSTTAG = 8;
		static const Sbecore::uint FEEDFPUPFEDSRT = 9;
		static const Sbecore::uint FEEDFPUPHKT = 10;
		static const Sbecore::uint FEEDFPUPJTI = 11;
		static const Sbecore::uint FEEDFPUPRET = 12;
		static const Sbecore::uint FEEDFPUPSCO = 13;
		static const Sbecore::uint FEEDFPUPSTY = 14;
		static const Sbecore::uint FEEDFPUPTYP = 15;
		static const Sbecore::uint STATAPP = 16;
		static const Sbecore::uint STATSHR = 17;
		static const Sbecore::uint TAG = 18;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFLstFedTag;
		Sbecore::Feed feedFLstFedVit;
		Sbecore::Feed feedFLstOpt;
		Sbecore::Feed feedFLstTag;
		Sbecore::Feed feedFPupFedSrt;
		Sbecore::Feed feedFPupHkt;
		Sbecore::Feed feedFPupJti;
		Sbecore::Feed feedFPupRet;
		Sbecore::Feed feedFPupSco;
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
