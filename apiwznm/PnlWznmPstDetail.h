/**
	* \file PnlWznmPstDetail.h
	* API code for job PnlWznmPstDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMPSTDETAIL_H
#define PNLWZNMPSTDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmPstDetailDo PnlWznmPstDetail::VecVDo

#define ContIacWznmPstDetail PnlWznmPstDetail::ContIac
#define ContInfWznmPstDetail PnlWznmPstDetail::ContInf
#define StatAppWznmPstDetail PnlWznmPstDetail::StatApp
#define StatShrWznmPstDetail PnlWznmPstDetail::StatShr
#define TagWznmPstDetail PnlWznmPstDetail::Tag

#define DpchAppWznmPstDetailData PnlWznmPstDetail::DpchAppData
#define DpchAppWznmPstDetailDo PnlWznmPstDetail::DpchAppDo
#define DpchEngWznmPstDetailData PnlWznmPstDetail::DpchEngData

/**
	* PnlWznmPstDetail
	*/
namespace PnlWznmPstDetail {
	/**
		* VecVDo (full: VecVWznmPstDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJTIEDITCLICK = 2;
		static const Sbecore::uint BUTVERVIEWCLICK = 3;
		static const Sbecore::uint BUTREUVIEWCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmPstDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJTI = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint NUMFPUPSCO = 3;
		static const Sbecore::uint NUMFPUPATY = 4;

	public:
		ContIac(const Sbecore::uint numFPupJti = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupSco = 1, const Sbecore::uint numFPupAty = 1);

	public:
		Sbecore::uint numFPupJti;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupSco;
		Sbecore::uint numFPupAty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmPstDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTVER = 3;
		static const Sbecore::uint TXTREU = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtVer = "", const std::string& TxtReu = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtVer;
		std::string TxtReu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmPstDetail)
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
	  * StatShr (full: StatShrWznmPstDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPJTIACTIVE = 4;
		static const Sbecore::uint BUTJTIEDITAVAIL = 5;
		static const Sbecore::uint TXTTITACTIVE = 6;
		static const Sbecore::uint TXTVERACTIVE = 7;
		static const Sbecore::uint BUTVERVIEWAVAIL = 8;
		static const Sbecore::uint BUTVERVIEWACTIVE = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint PUPSCOACTIVE = 13;
		static const Sbecore::uint PUPATYACTIVE = 14;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupScoActive = true, const bool PupAtyActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool PupScoActive;
		bool PupAtyActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmPstDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTVER = 4;
		static const Sbecore::uint CPTREU = 5;
		static const Sbecore::uint CPTSCO = 6;
		static const Sbecore::uint CPTATY = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptVer = "", const std::string& CptReu = "", const std::string& CptSco = "", const std::string& CptAty = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptVer;
		std::string CptReu;
		std::string CptSco;
		std::string CptAty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmPstDetailData)
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
		* DpchAppDo (full: DpchAppWznmPstDetailDo)
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
		* DpchEngData (full: DpchEngWznmPstDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPATY = 4;
		static const Sbecore::uint FEEDFPUPJTI = 5;
		static const Sbecore::uint FEEDFPUPRET = 6;
		static const Sbecore::uint FEEDFPUPSCO = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupAty;
		Sbecore::Xmlio::Feed feedFPupJti;
		Sbecore::Xmlio::Feed feedFPupRet;
		Sbecore::Xmlio::Feed feedFPupSco;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

