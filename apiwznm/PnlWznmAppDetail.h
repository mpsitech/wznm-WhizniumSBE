/**
	* \file PnlWznmAppDetail.h
	* API code for job PnlWznmAppDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMAPPDETAIL_H
#define PNLWZNMAPPDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmAppDetailDo PnlWznmAppDetail::VecVDo

#define ContIacWznmAppDetail PnlWznmAppDetail::ContIac
#define ContInfWznmAppDetail PnlWznmAppDetail::ContInf
#define StatAppWznmAppDetail PnlWznmAppDetail::StatApp
#define StatShrWznmAppDetail PnlWznmAppDetail::StatShr
#define TagWznmAppDetail PnlWznmAppDetail::Tag

#define DpchAppWznmAppDetailData PnlWznmAppDetail::DpchAppData
#define DpchAppWznmAppDetailDo PnlWznmAppDetail::DpchAppDo
#define DpchEngWznmAppDetailData PnlWznmAppDetail::DpchEngData

/**
	* PnlWznmAppDetail
	*/
namespace PnlWznmAppDetail {
	/**
		* VecVDo (full: VecVWznmAppDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmAppDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint TXFTIT = 2;
		static const Sbecore::uint NUMFPUPTRG = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const std::string& TxfSho = "", const std::string& TxfTit = "", const Sbecore::uint numFPupTrg = 1, const std::string& TxfCmt = "");

	public:
		std::string TxfSho;
		std::string TxfTit;
		Sbecore::uint numFPupTrg;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmAppDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTVER = 1;

	public:
		ContInf(const std::string& TxtVer = "");

	public:
		std::string TxtVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmAppDetail)
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
	  * StatShr (full: StatShrWznmAppDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFSHOACTIVE = 3;
		static const Sbecore::uint TXFTITACTIVE = 4;
		static const Sbecore::uint PUPTRGACTIVE = 5;
		static const Sbecore::uint TXTVERACTIVE = 6;
		static const Sbecore::uint BUTVERVIEWAVAIL = 7;
		static const Sbecore::uint BUTVERVIEWACTIVE = 8;
		static const Sbecore::uint TXFCMTACTIVE = 9;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfShoActive = true, const bool TxfTitActive = true, const bool PupTrgActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfShoActive;
		bool TxfTitActive;
		bool PupTrgActive;
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
	  * Tag (full: TagWznmAppDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSHO = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTTRG = 4;
		static const Sbecore::uint CPTVER = 5;
		static const Sbecore::uint CPTCMT = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSho = "", const std::string& CptTit = "", const std::string& CptTrg = "", const std::string& CptVer = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSho;
		std::string CptTit;
		std::string CptTrg;
		std::string CptVer;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmAppDetailData)
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
		* DpchAppDo (full: DpchAppWznmAppDetailDo)
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
		* DpchEngData (full: DpchEngWznmAppDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPTRG = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupTrg;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

