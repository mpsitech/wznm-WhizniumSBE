/**
	* \file PnlWznmTagDetail.h
	* API code for job PnlWznmTagDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMTAGDETAIL_H
#define PNLWZNMTAGDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmTagDetailDo PnlWznmTagDetail::VecVDo

#define ContIacWznmTagDetail PnlWznmTagDetail::ContIac
#define ContInfWznmTagDetail PnlWznmTagDetail::ContInf
#define StatAppWznmTagDetail PnlWznmTagDetail::StatApp
#define StatShrWznmTagDetail PnlWznmTagDetail::StatShr
#define TagWznmTagDetail PnlWznmTagDetail::Tag

#define DpchAppWznmTagDetailData PnlWznmTagDetail::DpchAppData
#define DpchAppWznmTagDetailDo PnlWznmTagDetail::DpchAppDo
#define DpchEngWznmTagDetailData PnlWznmTagDetail::DpchEngData

/**
	* PnlWznmTagDetail
	*/
namespace PnlWznmTagDetail {
	/**
		* VecVDo (full: VecVWznmTagDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJTIEDITCLICK = 2;
		static const Sbecore::uint BUTCPBVIEWCLICK = 3;
		static const Sbecore::uint BUTGRPEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmTagDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJTI = 1;
		static const Sbecore::uint NUMFPUPGRP = 2;
		static const Sbecore::uint TXFGRP = 3;

	public:
		ContIac(const Sbecore::uint numFPupJti = 1, const Sbecore::uint numFPupGrp = 1, const std::string& TxfGrp = "");

	public:
		Sbecore::uint numFPupJti;
		Sbecore::uint numFPupGrp;
		std::string TxfGrp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmTagDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTCPB = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtCpb = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtCpb;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmTagDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint PUPGRPALT = 2;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool PupGrpAlt = false);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool PupGrpAlt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmTagDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFGRPVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPJTIACTIVE = 5;
		static const Sbecore::uint BUTJTIEDITAVAIL = 6;
		static const Sbecore::uint TXTTITACTIVE = 7;
		static const Sbecore::uint TXTCPBACTIVE = 8;
		static const Sbecore::uint BUTCPBVIEWAVAIL = 9;
		static const Sbecore::uint BUTCPBVIEWACTIVE = 10;
		static const Sbecore::uint PUPGRPACTIVE = 11;
		static const Sbecore::uint BUTGRPEDITAVAIL = 12;

	public:
		StatShr(const bool TxfGrpValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtCpbActive = true, const bool ButCpbViewAvail = true, const bool ButCpbViewActive = true, const bool PupGrpActive = true, const bool ButGrpEditAvail = true);

	public:
		bool TxfGrpValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtCpbActive;
		bool ButCpbViewAvail;
		bool ButCpbViewActive;
		bool PupGrpActive;
		bool ButGrpEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmTagDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTCPB = 4;
		static const Sbecore::uint CPTGRP = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptCpb = "", const std::string& CptGrp = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptCpb;
		std::string CptGrp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmTagDetailData)
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
		* DpchAppDo (full: DpchAppWznmTagDetailDo)
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
		* DpchEngData (full: DpchEngWznmTagDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPGRP = 4;
		static const Sbecore::uint FEEDFPUPJTI = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupGrp;
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

