/**
	* \file PnlWznmCarDetail.h
	* API code for job PnlWznmCarDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMCARDETAIL_H
#define PNLWZNMCARDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmCarDetailDo PnlWznmCarDetail::VecVDo

#define ContIacWznmCarDetail PnlWznmCarDetail::ContIac
#define ContInfWznmCarDetail PnlWznmCarDetail::ContInf
#define StatAppWznmCarDetail PnlWznmCarDetail::StatApp
#define StatShrWznmCarDetail PnlWznmCarDetail::StatShr
#define TagWznmCarDetail PnlWznmCarDetail::Tag

#define DpchAppWznmCarDetailData PnlWznmCarDetail::DpchAppData
#define DpchAppWznmCarDetailDo PnlWznmCarDetail::DpchAppDo
#define DpchEngWznmCarDetailData PnlWznmCarDetail::DpchEngData

/**
	* PnlWznmCarDetail
	*/
namespace PnlWznmCarDetail {
	/**
		* VecVDo (full: VecVWznmCarDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJTIEDITCLICK = 2;
		static const Sbecore::uint BUTMDLVIEWCLICK = 3;
		static const Sbecore::uint BUTREUVIEWCLICK = 4;
		static const Sbecore::uint BUTJOBVIEWCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmCarDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJTI = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint TXFAVL = 3;
		static const Sbecore::uint TXFACT = 4;

	public:
		ContIac(const Sbecore::uint numFPupJti = 1, const Sbecore::uint numFPupRet = 1, const std::string& TxfAvl = "", const std::string& TxfAct = "");

	public:
		Sbecore::uint numFPupJti;
		Sbecore::uint numFPupRet;
		std::string TxfAvl;
		std::string TxfAct;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmCarDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTMDL = 3;
		static const Sbecore::uint TXTREU = 4;
		static const Sbecore::uint TXTJOB = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtMdl = "", const std::string& TxtReu = "", const std::string& TxtJob = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtMdl;
		std::string TxtReu;
		std::string TxtJob;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmCarDetail)
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
	  * StatShr (full: StatShrWznmCarDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPJTIACTIVE = 4;
		static const Sbecore::uint BUTJTIEDITAVAIL = 5;
		static const Sbecore::uint TXTTITACTIVE = 6;
		static const Sbecore::uint TXTMDLACTIVE = 7;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 8;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint TXTJOBACTIVE = 13;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 14;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 15;
		static const Sbecore::uint TXFAVLACTIVE = 16;
		static const Sbecore::uint TXFACTACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfAvlActive = true, const bool TxfActActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfAvlActive;
		bool TxfActActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmCarDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTMDL = 4;
		static const Sbecore::uint CPTREU = 5;
		static const Sbecore::uint CPTJOB = 6;
		static const Sbecore::uint CPTAVL = 7;
		static const Sbecore::uint CPTACT = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptMdl = "", const std::string& CptReu = "", const std::string& CptJob = "", const std::string& CptAvl = "", const std::string& CptAct = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptMdl;
		std::string CptReu;
		std::string CptJob;
		std::string CptAvl;
		std::string CptAct;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmCarDetailData)
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
		* DpchAppDo (full: DpchAppWznmCarDetailDo)
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
		* DpchEngData (full: DpchEngWznmCarDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJTI = 4;
		static const Sbecore::uint FEEDFPUPRET = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupJti;
		Sbecore::Xmlio::Feed feedFPupRet;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
