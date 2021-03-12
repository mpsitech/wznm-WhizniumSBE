/**
	* \file PnlWznmRelDetail.h
	* API code for job PnlWznmRelDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMRELDETAIL_H
#define PNLWZNMRELDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmRelDetailDo PnlWznmRelDetail::VecVDo

#define ContIacWznmRelDetail PnlWznmRelDetail::ContIac
#define ContInfWznmRelDetail PnlWznmRelDetail::ContInf
#define StatAppWznmRelDetail PnlWznmRelDetail::StatApp
#define StatShrWznmRelDetail PnlWznmRelDetail::StatShr
#define TagWznmRelDetail PnlWznmRelDetail::Tag

#define DpchAppWznmRelDetailData PnlWznmRelDetail::DpchAppData
#define DpchAppWznmRelDetailDo PnlWznmRelDetail::DpchAppDo
#define DpchEngWznmRelDetailData PnlWznmRelDetail::DpchEngData

/**
	* PnlWznmRelDetail
	*/
namespace PnlWznmRelDetail {
	/**
		* VecVDo (full: VecVWznmRelDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTFRSVIEWCLICK = 2;
		static const Sbecore::uint BUTTOSVIEWCLICK = 3;
		static const Sbecore::uint BUTCLUVIEWCLICK = 4;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 5;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 6;
		static const Sbecore::uint BUTVERVIEWCLICK = 7;
		static const Sbecore::uint BUTSUPVIEWCLICK = 8;
		static const Sbecore::uint BUTOPTEDITCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmRelDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint TXFPFX = 3;
		static const Sbecore::uint NUMSFLSTOPT = 4;
		static const Sbecore::uint TXFOPT = 5;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFLstClu = 1, const std::string& TxfPfx = "", const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFLstClu;
		std::string TxfPfx;
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmRelDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTFRT = 1;
		static const Sbecore::uint TXTFRS = 2;
		static const Sbecore::uint TXTTOT = 3;
		static const Sbecore::uint TXTTOS = 4;
		static const Sbecore::uint TXTCLU = 5;
		static const Sbecore::uint TXTVER = 6;
		static const Sbecore::uint TXTSUP = 7;
		static const Sbecore::uint TXTTBL = 8;

	public:
		ContInf(const std::string& TxtFrt = "", const std::string& TxtFrs = "", const std::string& TxtTot = "", const std::string& TxtTos = "", const std::string& TxtClu = "", const std::string& TxtVer = "", const std::string& TxtSup = "", const std::string& TxtTbl = "");

	public:
		std::string TxtFrt;
		std::string TxtFrs;
		std::string TxtTot;
		std::string TxtTos;
		std::string TxtClu;
		std::string TxtVer;
		std::string TxtSup;
		std::string TxtTbl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmRelDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTCLUALT = 2;
		static const Sbecore::uint LSTOPTALT = 3;
		static const Sbecore::uint LSTCLUNUMFIRSTDISP = 4;
		static const Sbecore::uint LSTOPTNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstCluAlt = true, const bool LstOptAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1, const Sbecore::uint LstOptNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstCluAlt;
		bool LstOptAlt;
		Sbecore::uint LstCluNumFirstdisp;
		Sbecore::uint LstOptNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmRelDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFOPTVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTFRTACTIVE = 4;
		static const Sbecore::uint TXTFRSACTIVE = 5;
		static const Sbecore::uint BUTFRSVIEWAVAIL = 6;
		static const Sbecore::uint BUTFRSVIEWACTIVE = 7;
		static const Sbecore::uint TXTTOTACTIVE = 8;
		static const Sbecore::uint TXTTOSACTIVE = 9;
		static const Sbecore::uint BUTTOSVIEWAVAIL = 10;
		static const Sbecore::uint BUTTOSVIEWACTIVE = 11;
		static const Sbecore::uint PUPTYPACTIVE = 12;
		static const Sbecore::uint LSTCLUACTIVE = 13;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 14;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 15;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 16;
		static const Sbecore::uint TXTVERACTIVE = 17;
		static const Sbecore::uint BUTVERVIEWAVAIL = 18;
		static const Sbecore::uint BUTVERVIEWACTIVE = 19;
		static const Sbecore::uint TXTSUPACTIVE = 20;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 21;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 22;
		static const Sbecore::uint TXTTBLACTIVE = 23;
		static const Sbecore::uint TXFPFXACTIVE = 24;
		static const Sbecore::uint LSTOPTACTIVE = 25;
		static const Sbecore::uint BUTOPTEDITAVAIL = 26;

	public:
		StatShr(const bool TxfOptValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtFrtActive = true, const bool TxtFrsActive = true, const bool ButFrsViewAvail = true, const bool ButFrsViewActive = true, const bool TxtTotActive = true, const bool TxtTosActive = true, const bool ButTosViewAvail = true, const bool ButTosViewActive = true, const bool PupTypActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTblActive = true, const bool TxfPfxActive = true, const bool LstOptActive = true, const bool ButOptEditAvail = true);

	public:
		bool TxfOptValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtFrtActive;
		bool TxtFrsActive;
		bool ButFrsViewAvail;
		bool ButFrsViewActive;
		bool TxtTotActive;
		bool TxtTosActive;
		bool ButTosViewAvail;
		bool ButTosViewActive;
		bool PupTypActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtTblActive;
		bool TxfPfxActive;
		bool LstOptActive;
		bool ButOptEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmRelDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTFRT = 2;
		static const Sbecore::uint CPTFRS = 3;
		static const Sbecore::uint CPTTOT = 4;
		static const Sbecore::uint CPTTOS = 5;
		static const Sbecore::uint CPTTYP = 6;
		static const Sbecore::uint CPTCLU = 7;
		static const Sbecore::uint CPTVER = 8;
		static const Sbecore::uint CPTSUP = 9;
		static const Sbecore::uint CPTTBL = 10;
		static const Sbecore::uint CPTPFX = 11;
		static const Sbecore::uint CPTOPT = 12;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptFrt = "", const std::string& CptFrs = "", const std::string& CptTot = "", const std::string& CptTos = "", const std::string& CptTyp = "", const std::string& CptClu = "", const std::string& CptVer = "", const std::string& CptSup = "", const std::string& CptTbl = "", const std::string& CptPfx = "", const std::string& CptOpt = "");

	public:
		std::string Cpt;
		std::string CptFrt;
		std::string CptFrs;
		std::string CptTot;
		std::string CptTos;
		std::string CptTyp;
		std::string CptClu;
		std::string CptVer;
		std::string CptSup;
		std::string CptTbl;
		std::string CptPfx;
		std::string CptOpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmRelDetailData)
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
		* DpchAppDo (full: DpchAppWznmRelDetailDo)
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
		* DpchEngData (full: DpchEngWznmRelDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFLSTOPT = 5;
		static const Sbecore::uint FEEDFPUPTYP = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFLstOpt;
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
