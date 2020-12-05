/**
	* \file PnlWznmCapDetail.h
	* API code for job PnlWznmCapDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMCAPDETAIL_H
#define PNLWZNMCAPDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmCapDetailDo PnlWznmCapDetail::VecVDo

#define ContIacWznmCapDetail PnlWznmCapDetail::ContIac
#define ContInfWznmCapDetail PnlWznmCapDetail::ContInf
#define StatAppWznmCapDetail PnlWznmCapDetail::StatApp
#define StatShrWznmCapDetail PnlWznmCapDetail::StatShr
#define TagWznmCapDetail PnlWznmCapDetail::Tag

#define DpchAppWznmCapDetailData PnlWznmCapDetail::DpchAppData
#define DpchAppWznmCapDetailDo PnlWznmCapDetail::DpchAppDo
#define DpchEngWznmCapDetailData PnlWznmCapDetail::DpchEngData

/**
	* PnlWznmCapDetail
	*/
namespace PnlWznmCapDetail {
	/**
		* VecVDo (full: VecVWznmCapDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTTPLVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmCapDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint NUMSFLSTATF = 2;

	public:
		ContIac(const std::string& TxfTit = "", const std::vector<Sbecore::uint>& numsFLstAtf = {});

	public:
		std::string TxfTit;
		std::vector<Sbecore::uint> numsFLstAtf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmCapDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTTPL = 3;
		static const Sbecore::uint TXTATF = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtTpl = "", const std::string& TxtAtf = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtTpl;
		std::string TxtAtf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmCapDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTATFALT = 2;
		static const Sbecore::uint LSTATFNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstAtfAlt = true, const Sbecore::uint LstAtfNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstAtfAlt;
		Sbecore::uint LstAtfNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmCapDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFTITACTIVE = 4;
		static const Sbecore::uint TXTVERACTIVE = 5;
		static const Sbecore::uint BUTVERVIEWAVAIL = 6;
		static const Sbecore::uint BUTVERVIEWACTIVE = 7;
		static const Sbecore::uint TXTTPLACTIVE = 8;
		static const Sbecore::uint BUTTPLVIEWAVAIL = 9;
		static const Sbecore::uint BUTTPLVIEWACTIVE = 10;
		static const Sbecore::uint LSTATFACTIVE = 11;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtTplActive = true, const bool ButTplViewAvail = true, const bool ButTplViewActive = true, const bool LstAtfActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtTplActive;
		bool ButTplViewAvail;
		bool ButTplViewActive;
		bool LstAtfActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmCapDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTVER = 4;
		static const Sbecore::uint CPTTPL = 5;
		static const Sbecore::uint CPTATF = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptVer = "", const std::string& CptTpl = "", const std::string& CptAtf = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptVer;
		std::string CptTpl;
		std::string CptAtf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmCapDetailData)
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
		* DpchAppDo (full: DpchAppWznmCapDetailDo)
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
		* DpchEngData (full: DpchEngWznmCapDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTATF = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstAtf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

