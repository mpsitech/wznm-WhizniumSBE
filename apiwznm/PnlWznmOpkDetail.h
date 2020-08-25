/**
	* \file PnlWznmOpkDetail.h
	* API code for job PnlWznmOpkDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef PNLWZNMOPKDETAIL_H
#define PNLWZNMOPKDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmOpkDetailDo PnlWznmOpkDetail::VecVDo

#define ContIacWznmOpkDetail PnlWznmOpkDetail::ContIac
#define ContInfWznmOpkDetail PnlWznmOpkDetail::ContInf
#define StatAppWznmOpkDetail PnlWznmOpkDetail::StatApp
#define StatShrWznmOpkDetail PnlWznmOpkDetail::StatShr
#define TagWznmOpkDetail PnlWznmOpkDetail::Tag

#define DpchAppWznmOpkDetailData PnlWznmOpkDetail::DpchAppData
#define DpchAppWznmOpkDetailDo PnlWznmOpkDetail::DpchAppDo
#define DpchEngWznmOpkDetailData PnlWznmOpkDetail::DpchEngData

/**
	* PnlWznmOpkDetail
	*/
namespace PnlWznmOpkDetail {
	/**
		* VecVDo (full: VecVWznmOpkDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTSQKNEWCLICK = 3;
		static const Sbecore::uint BUTSQKDELETECLICK = 4;
		static const Sbecore::uint BUTSQKJTIEDITCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmOpkDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint CHKSHD = 3;
		static const Sbecore::uint TXFCMT = 4;
		static const Sbecore::uint NUMFPUPSQKJTI = 5;
		static const Sbecore::uint TXFSQKEXA = 6;

	public:
		ContIac(const std::string& TxfTit = "", const Sbecore::uint numFPupTyp = 1, const bool ChkShd = false, const std::string& TxfCmt = "", const Sbecore::uint numFPupSqkJti = 1, const std::string& TxfSqkExa = "");

	public:
		std::string TxfTit;
		Sbecore::uint numFPupTyp;
		bool ChkShd;
		std::string TxfCmt;
		Sbecore::uint numFPupSqkJti;
		std::string TxfSqkExa;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmOpkDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTSQKTIT = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtSqkTit = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtSqkTit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmOpkDetail)
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
	  * StatShr (full: StatShrWznmOpkDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFTITACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint TXTVERACTIVE = 6;
		static const Sbecore::uint BUTVERVIEWAVAIL = 7;
		static const Sbecore::uint BUTVERVIEWACTIVE = 8;
		static const Sbecore::uint CHKSHDACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;
		static const Sbecore::uint BUTSQKNEWAVAIL = 11;
		static const Sbecore::uint BUTSQKDELETEAVAIL = 12;
		static const Sbecore::uint PUPSQKJTIAVAIL = 13;
		static const Sbecore::uint PUPSQKJTIACTIVE = 14;
		static const Sbecore::uint BUTSQKJTIEDITAVAIL = 15;
		static const Sbecore::uint TXTSQKTITAVAIL = 16;
		static const Sbecore::uint TXTSQKTITACTIVE = 17;
		static const Sbecore::uint TXFSQKEXAAVAIL = 18;
		static const Sbecore::uint TXFSQKEXAACTIVE = 19;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool ChkShdActive = true, const bool TxfCmtActive = true, const bool ButSqkNewAvail = true, const bool ButSqkDeleteAvail = true, const bool PupSqkJtiAvail = true, const bool PupSqkJtiActive = true, const bool ButSqkJtiEditAvail = true, const bool TxtSqkTitAvail = true, const bool TxtSqkTitActive = true, const bool TxfSqkExaAvail = true, const bool TxfSqkExaActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool ChkShdActive;
		bool TxfCmtActive;
		bool ButSqkNewAvail;
		bool ButSqkDeleteAvail;
		bool PupSqkJtiAvail;
		bool PupSqkJtiActive;
		bool ButSqkJtiEditAvail;
		bool TxtSqkTitAvail;
		bool TxtSqkTitActive;
		bool TxfSqkExaAvail;
		bool TxfSqkExaActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmOpkDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTTYP = 4;
		static const Sbecore::uint CPTVER = 5;
		static const Sbecore::uint CPTSHD = 6;
		static const Sbecore::uint CPTCMT = 7;
		static const Sbecore::uint HDGSQK = 8;
		static const Sbecore::uint CPTSQKTIT = 9;
		static const Sbecore::uint CPTSQKEXA = 10;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptTyp = "", const std::string& CptVer = "", const std::string& CptShd = "", const std::string& CptCmt = "", const std::string& HdgSqk = "", const std::string& CptSqkTit = "", const std::string& CptSqkExa = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptTyp;
		std::string CptVer;
		std::string CptShd;
		std::string CptCmt;
		std::string HdgSqk;
		std::string CptSqkTit;
		std::string CptSqkExa;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmOpkDetailData)
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
		* DpchAppDo (full: DpchAppWznmOpkDetailDo)
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
		* DpchEngData (full: DpchEngWznmOpkDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPSQKJTI = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupSqkJti;
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

