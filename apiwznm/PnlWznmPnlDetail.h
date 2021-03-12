/**
	* \file PnlWznmPnlDetail.h
	* API code for job PnlWznmPnlDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMPNLDETAIL_H
#define PNLWZNMPNLDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmPnlDetailDo PnlWznmPnlDetail::VecVDo

#define ContIacWznmPnlDetail PnlWznmPnlDetail::ContIac
#define ContInfWznmPnlDetail PnlWznmPnlDetail::ContInf
#define StatAppWznmPnlDetail PnlWznmPnlDetail::StatApp
#define StatShrWznmPnlDetail PnlWznmPnlDetail::StatShr
#define TagWznmPnlDetail PnlWznmPnlDetail::Tag

#define DpchAppWznmPnlDetailData PnlWznmPnlDetail::DpchAppData
#define DpchAppWznmPnlDetailDo PnlWznmPnlDetail::DpchAppDo
#define DpchEngWznmPnlDetailData PnlWznmPnlDetail::DpchEngData

/**
	* PnlWznmPnlDetail
	*/
namespace PnlWznmPnlDetail {
	/**
		* VecVDo (full: VecVWznmPnlDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCARVIEWCLICK = 2;
		static const Sbecore::uint BUTREUVIEWCLICK = 3;
		static const Sbecore::uint BUTJOBVIEWCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmPnlDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint CHKDET = 3;
		static const Sbecore::uint TXFAVL = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupRet = 1, const bool ChkDet = false, const std::string& TxfAvl = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupRet;
		bool ChkDet;
		std::string TxfAvl;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmPnlDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCAR = 2;
		static const Sbecore::uint TXTREU = 3;
		static const Sbecore::uint TXTJOB = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtCar = "", const std::string& TxtReu = "", const std::string& TxtJob = "");

	public:
		std::string TxtSrf;
		std::string TxtCar;
		std::string TxtReu;
		std::string TxtJob;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmPnlDetail)
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
	  * StatShr (full: StatShrWznmPnlDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPTYPACTIVE = 4;
		static const Sbecore::uint TXTCARACTIVE = 5;
		static const Sbecore::uint BUTCARVIEWAVAIL = 6;
		static const Sbecore::uint BUTCARVIEWACTIVE = 7;
		static const Sbecore::uint TXTREUACTIVE = 8;
		static const Sbecore::uint BUTREUVIEWAVAIL = 9;
		static const Sbecore::uint BUTREUVIEWACTIVE = 10;
		static const Sbecore::uint TXTJOBACTIVE = 11;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 12;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 13;
		static const Sbecore::uint CHKDETACTIVE = 14;
		static const Sbecore::uint TXFAVLACTIVE = 15;
		static const Sbecore::uint TXFCMTACTIVE = 16;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtCarActive = true, const bool ButCarViewAvail = true, const bool ButCarViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool ChkDetActive = true, const bool TxfAvlActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtCarActive;
		bool ButCarViewAvail;
		bool ButCarViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool ChkDetActive;
		bool TxfAvlActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmPnlDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTYP = 3;
		static const Sbecore::uint CPTCAR = 4;
		static const Sbecore::uint CPTREU = 5;
		static const Sbecore::uint CPTJOB = 6;
		static const Sbecore::uint CPTDET = 7;
		static const Sbecore::uint CPTAVL = 8;
		static const Sbecore::uint CPTCMT = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTyp = "", const std::string& CptCar = "", const std::string& CptReu = "", const std::string& CptJob = "", const std::string& CptDet = "", const std::string& CptAvl = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTyp;
		std::string CptCar;
		std::string CptReu;
		std::string CptJob;
		std::string CptDet;
		std::string CptAvl;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmPnlDetailData)
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
		* DpchAppDo (full: DpchAppWznmPnlDetailDo)
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
		* DpchEngData (full: DpchEngWznmPnlDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPRET = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupRet;
		Sbecore::Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
