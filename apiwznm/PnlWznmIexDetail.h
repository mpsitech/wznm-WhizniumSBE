/**
	* \file PnlWznmIexDetail.h
	* API code for job PnlWznmIexDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMIEXDETAIL_H
#define PNLWZNMIEXDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmIexDetailDo PnlWznmIexDetail::VecVDo

#define ContIacWznmIexDetail PnlWznmIexDetail::ContIac
#define ContInfWznmIexDetail PnlWznmIexDetail::ContInf
#define StatAppWznmIexDetail PnlWznmIexDetail::StatApp
#define StatShrWznmIexDetail PnlWznmIexDetail::StatShr
#define TagWznmIexDetail PnlWznmIexDetail::Tag

#define DpchAppWznmIexDetailData PnlWznmIexDetail::DpchAppData
#define DpchAppWznmIexDetailDo PnlWznmIexDetail::DpchAppDo
#define DpchEngWznmIexDetailData PnlWznmIexDetail::DpchEngData

/**
	* PnlWznmIexDetail
	*/
namespace PnlWznmIexDetail {
	/**
		* VecVDo (full: VecVWznmIexDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJTIEDITCLICK = 2;
		static const Sbecore::uint BUTVERVIEWCLICK = 3;
		static const Sbecore::uint BUTJOBVIEWCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmIexDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPJTI = 2;
		static const Sbecore::uint TXFMIV = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupJti = 1, const std::string& TxfMiv = "", const std::string& TxfCmt = "");

	public:
		std::string TxfSho;
		Sbecore::uint numFPupJti;
		std::string TxfMiv;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmIexDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTVER = 3;
		static const Sbecore::uint TXTJOB = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtVer = "", const std::string& TxtJob = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtVer;
		std::string TxtJob;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmIexDetail)
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
	  * StatShr (full: StatShrWznmIexDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFSHOACTIVE = 4;
		static const Sbecore::uint PUPJTIACTIVE = 5;
		static const Sbecore::uint BUTJTIEDITAVAIL = 6;
		static const Sbecore::uint TXTTITACTIVE = 7;
		static const Sbecore::uint TXTVERACTIVE = 8;
		static const Sbecore::uint BUTVERVIEWAVAIL = 9;
		static const Sbecore::uint BUTVERVIEWACTIVE = 10;
		static const Sbecore::uint TXTJOBACTIVE = 11;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 12;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 13;
		static const Sbecore::uint TXFMIVACTIVE = 14;
		static const Sbecore::uint TXFCMTACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfMivActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfMivActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmIexDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTSHO = 3;
		static const Sbecore::uint CPTTIT = 4;
		static const Sbecore::uint CPTVER = 5;
		static const Sbecore::uint CPTJOB = 6;
		static const Sbecore::uint CPTMIV = 7;
		static const Sbecore::uint CPTCMT = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptSho = "", const std::string& CptTit = "", const std::string& CptVer = "", const std::string& CptJob = "", const std::string& CptMiv = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptSho;
		std::string CptTit;
		std::string CptVer;
		std::string CptJob;
		std::string CptMiv;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmIexDetailData)
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
		* DpchAppDo (full: DpchAppWznmIexDetailDo)
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
		* DpchEngData (full: DpchEngWznmIexDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJTI = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupJti;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

