/**
	* \file PnlWznmOpxDetail.h
	* API code for job PnlWznmOpxDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMOPXDETAIL_H
#define PNLWZNMOPXDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmOpxDetailDo PnlWznmOpxDetail::VecVDo

#define ContIacWznmOpxDetail PnlWznmOpxDetail::ContIac
#define ContInfWznmOpxDetail PnlWznmOpxDetail::ContInf
#define StatAppWznmOpxDetail PnlWznmOpxDetail::StatApp
#define StatShrWznmOpxDetail PnlWznmOpxDetail::StatShr
#define TagWznmOpxDetail PnlWznmOpxDetail::Tag

#define DpchAppWznmOpxDetailData PnlWznmOpxDetail::DpchAppData
#define DpchAppWznmOpxDetailDo PnlWznmOpxDetail::DpchAppDo
#define DpchEngWznmOpxDetailData PnlWznmOpxDetail::DpchEngData

/**
	* PnlWznmOpxDetail
	*/
namespace PnlWznmOpxDetail {
	/**
		* VecVDo (full: VecVWznmOpxDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTOPKVIEWCLICK = 2;
		static const Sbecore::uint BUTSQKNEWCLICK = 3;
		static const Sbecore::uint BUTSQKDELETECLICK = 4;
		static const Sbecore::uint BUTSQKJTIEDITCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmOpxDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint CHKSHD = 1;
		static const Sbecore::uint TXFCMT = 2;
		static const Sbecore::uint NUMFPUPSQKJTI = 3;
		static const Sbecore::uint TXFSQKEXA = 4;

	public:
		ContIac(const bool ChkShd = false, const std::string& TxfCmt = "", const Sbecore::uint numFPupSqkJti = 1, const std::string& TxfSqkExa = "");

	public:
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
	  * ContInf (full: ContInfWznmOpxDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTOPK = 2;
		static const Sbecore::uint TXTSQKTIT = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtOpk = "", const std::string& TxtSqkTit = "");

	public:
		std::string TxtSrf;
		std::string TxtOpk;
		std::string TxtSqkTit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmOpxDetail)
	  */
	class StatApp : public Sbecore::Block {

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
	  * StatShr (full: StatShrWznmOpxDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXTOPKACTIVE = 4;
		static const Sbecore::uint BUTOPKVIEWAVAIL = 5;
		static const Sbecore::uint BUTOPKVIEWACTIVE = 6;
		static const Sbecore::uint CHKSHDACTIVE = 7;
		static const Sbecore::uint TXFCMTACTIVE = 8;
		static const Sbecore::uint BUTSQKNEWAVAIL = 9;
		static const Sbecore::uint BUTSQKDELETEAVAIL = 10;
		static const Sbecore::uint PUPSQKJTIAVAIL = 11;
		static const Sbecore::uint PUPSQKJTIACTIVE = 12;
		static const Sbecore::uint BUTSQKJTIEDITAVAIL = 13;
		static const Sbecore::uint TXTSQKTITAVAIL = 14;
		static const Sbecore::uint TXTSQKTITACTIVE = 15;
		static const Sbecore::uint TXFSQKEXAAVAIL = 16;
		static const Sbecore::uint TXFSQKEXAACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtOpkActive = true, const bool ButOpkViewAvail = true, const bool ButOpkViewActive = true, const bool ChkShdActive = true, const bool TxfCmtActive = true, const bool ButSqkNewAvail = true, const bool ButSqkDeleteAvail = true, const bool PupSqkJtiAvail = true, const bool PupSqkJtiActive = true, const bool ButSqkJtiEditAvail = true, const bool TxtSqkTitAvail = true, const bool TxtSqkTitActive = true, const bool TxfSqkExaAvail = true, const bool TxfSqkExaActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtOpkActive;
		bool ButOpkViewAvail;
		bool ButOpkViewActive;
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
	  * Tag (full: TagWznmOpxDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTOPK = 3;
		static const Sbecore::uint CPTSHD = 4;
		static const Sbecore::uint CPTCMT = 5;
		static const Sbecore::uint HDGSQK = 6;
		static const Sbecore::uint CPTSQKTIT = 7;
		static const Sbecore::uint CPTSQKEXA = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptOpk = "", const std::string& CptShd = "", const std::string& CptCmt = "", const std::string& HdgSqk = "", const std::string& CptSqkTit = "", const std::string& CptSqkExa = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptOpk;
		std::string CptShd;
		std::string CptCmt;
		std::string HdgSqk;
		std::string CptSqkTit;
		std::string CptSqkExa;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmOpxDetailData)
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
		* DpchAppDo (full: DpchAppWznmOpxDetailDo)
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
		* DpchEngData (full: DpchEngWznmOpxDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPSQKJTI = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupSqkJti;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
