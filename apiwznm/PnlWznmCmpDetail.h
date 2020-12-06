/**
	* \file PnlWznmCmpDetail.h
	* API code for job PnlWznmCmpDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMCMPDETAIL_H
#define PNLWZNMCMPDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmCmpDetailDo PnlWznmCmpDetail::VecVDo

#define ContIacWznmCmpDetail PnlWznmCmpDetail::ContIac
#define ContInfWznmCmpDetail PnlWznmCmpDetail::ContInf
#define StatAppWznmCmpDetail PnlWznmCmpDetail::StatApp
#define StatShrWznmCmpDetail PnlWznmCmpDetail::StatShr
#define TagWznmCmpDetail PnlWznmCmpDetail::Tag

#define DpchAppWznmCmpDetailData PnlWznmCmpDetail::DpchAppData
#define DpchAppWznmCmpDetailDo PnlWznmCmpDetail::DpchAppDo
#define DpchEngWznmCmpDetailData PnlWznmCmpDetail::DpchEngData

/**
	* PnlWznmCmpDetail
	*/
namespace PnlWznmCmpDetail {
	/**
		* VecVDo (full: VecVWznmCmpDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmCmpDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint TXFCMT = 3;

	public:
		ContIac(const std::string& TxfTit = "", const Sbecore::uint numFPupTyp = 1, const std::string& TxfCmt = "");

	public:
		std::string TxfTit;
		Sbecore::uint numFPupTyp;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmCmpDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmCmpDetail)
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
	  * StatShr (full: StatShrWznmCmpDetail)
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
		static const Sbecore::uint TXFCMTACTIVE = 9;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmCmpDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTTYP = 4;
		static const Sbecore::uint CPTVER = 5;
		static const Sbecore::uint CPTCMT = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptTyp = "", const std::string& CptVer = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptTyp;
		std::string CptVer;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmCmpDetailData)
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
		* DpchAppDo (full: DpchAppWznmCmpDetailDo)
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
		* DpchEngData (full: DpchEngWznmCmpDetailData)
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
