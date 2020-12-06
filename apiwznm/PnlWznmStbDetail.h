/**
	* \file PnlWznmStbDetail.h
	* API code for job PnlWznmStbDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMSTBDETAIL_H
#define PNLWZNMSTBDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmStbDetailDo PnlWznmStbDetail::VecVDo

#define ContIacWznmStbDetail PnlWznmStbDetail::ContIac
#define ContInfWznmStbDetail PnlWznmStbDetail::ContInf
#define StatAppWznmStbDetail PnlWznmStbDetail::StatApp
#define StatShrWznmStbDetail PnlWznmStbDetail::StatShr
#define TagWznmStbDetail PnlWznmStbDetail::Tag

#define DpchAppWznmStbDetailData PnlWznmStbDetail::DpchAppData
#define DpchAppWznmStbDetailDo PnlWznmStbDetail::DpchAppDo
#define DpchEngWznmStbDetailData PnlWznmStbDetail::DpchEngData

/**
	* PnlWznmStbDetail
	*/
namespace PnlWznmStbDetail {
	/**
		* VecVDo (full: VecVWznmStbDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTSBSVIEWCLICK = 2;
		static const Sbecore::uint BUTTCOVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmStbDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint CHKHRC = 2;
		static const Sbecore::uint CHKLCL = 3;
		static const Sbecore::uint TXFEXA = 4;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const bool ChkHrc = false, const bool ChkLcl = false, const std::string& TxfExa = "");

	public:
		Sbecore::uint numFPupTyp;
		bool ChkHrc;
		bool ChkLcl;
		std::string TxfExa;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmStbDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTBL = 2;
		static const Sbecore::uint TXTSBS = 3;
		static const Sbecore::uint TXTTCO = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTbl = "", const std::string& TxtSbs = "", const std::string& TxtTco = "");

	public:
		std::string TxtSrf;
		std::string TxtTbl;
		std::string TxtSbs;
		std::string TxtTco;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmStbDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);

	public:
		Sbecore::uint ixWznmVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmStbDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPTYPACTIVE = 4;
		static const Sbecore::uint TXTTBLACTIVE = 5;
		static const Sbecore::uint TXTSBSACTIVE = 6;
		static const Sbecore::uint BUTSBSVIEWAVAIL = 7;
		static const Sbecore::uint BUTSBSVIEWACTIVE = 8;
		static const Sbecore::uint CHKHRCACTIVE = 9;
		static const Sbecore::uint TXTTCOACTIVE = 10;
		static const Sbecore::uint BUTTCOVIEWAVAIL = 11;
		static const Sbecore::uint BUTTCOVIEWACTIVE = 12;
		static const Sbecore::uint CHKLCLACTIVE = 13;
		static const Sbecore::uint TXFEXAACTIVE = 14;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtTblActive = true, const bool TxtSbsActive = true, const bool ButSbsViewAvail = true, const bool ButSbsViewActive = true, const bool ChkHrcActive = true, const bool TxtTcoActive = true, const bool ButTcoViewAvail = true, const bool ButTcoViewActive = true, const bool ChkLclActive = true, const bool TxfExaActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtTblActive;
		bool TxtSbsActive;
		bool ButSbsViewAvail;
		bool ButSbsViewActive;
		bool ChkHrcActive;
		bool TxtTcoActive;
		bool ButTcoViewAvail;
		bool ButTcoViewActive;
		bool ChkLclActive;
		bool TxfExaActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmStbDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTYP = 3;
		static const Sbecore::uint CPTTBL = 4;
		static const Sbecore::uint CPTSBS = 5;
		static const Sbecore::uint CPTHRC = 6;
		static const Sbecore::uint CPTTCO = 7;
		static const Sbecore::uint CPTLCL = 8;
		static const Sbecore::uint CPTEXA = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTyp = "", const std::string& CptTbl = "", const std::string& CptSbs = "", const std::string& CptHrc = "", const std::string& CptTco = "", const std::string& CptLcl = "", const std::string& CptExa = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTyp;
		std::string CptTbl;
		std::string CptSbs;
		std::string CptHrc;
		std::string CptTco;
		std::string CptLcl;
		std::string CptExa;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmStbDetailData)
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
		* DpchAppDo (full: DpchAppWznmStbDetailDo)
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
		* DpchEngData (full: DpchEngWznmStbDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPTYP = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
