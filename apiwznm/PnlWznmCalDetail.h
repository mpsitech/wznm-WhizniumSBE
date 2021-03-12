/**
	* \file PnlWznmCalDetail.h
	* API code for job PnlWznmCalDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMCALDETAIL_H
#define PNLWZNMCALDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmCalDetailDo PnlWznmCalDetail::VecVDo

#define ContIacWznmCalDetail PnlWznmCalDetail::ContIac
#define ContInfWznmCalDetail PnlWznmCalDetail::ContInf
#define StatAppWznmCalDetail PnlWznmCalDetail::StatApp
#define StatShrWznmCalDetail PnlWznmCalDetail::StatShr
#define TagWznmCalDetail PnlWznmCalDetail::Tag

#define DpchAppWznmCalDetailData PnlWznmCalDetail::DpchAppData
#define DpchAppWznmCalDetailDo PnlWznmCalDetail::DpchAppDo
#define DpchEngWznmCalDetailData PnlWznmCalDetail::DpchEngData

/**
	* PnlWznmCalDetail
	*/
namespace PnlWznmCalDetail {
	/**
		* VecVDo (full: VecVWznmCalDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTREUVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmCalDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint NUMSFLSTIAT = 3;
		static const Sbecore::uint NUMSFLSTRAT = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupRet = 1, const std::vector<Sbecore::uint>& numsFLstIat = {}, const std::vector<Sbecore::uint>& numsFLstRat = {}, const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupRet;
		std::vector<Sbecore::uint> numsFLstIat;
		std::vector<Sbecore::uint> numsFLstRat;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmCalDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTREU = 3;
		static const Sbecore::uint TXTIAT = 4;
		static const Sbecore::uint TXTRAT = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtReu = "", const std::string& TxtIat = "", const std::string& TxtRat = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtReu;
		std::string TxtIat;
		std::string TxtRat;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmCalDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTIATALT = 2;
		static const Sbecore::uint LSTRATALT = 3;
		static const Sbecore::uint LSTIATNUMFIRSTDISP = 4;
		static const Sbecore::uint LSTRATNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstIatAlt = true, const bool LstRatAlt = true, const Sbecore::uint LstIatNumFirstdisp = 1, const Sbecore::uint LstRatNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstIatAlt;
		bool LstRatAlt;
		Sbecore::uint LstIatNumFirstdisp;
		Sbecore::uint LstRatNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmCalDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPTYPACTIVE = 4;
		static const Sbecore::uint TXTVERACTIVE = 5;
		static const Sbecore::uint BUTVERVIEWAVAIL = 6;
		static const Sbecore::uint BUTVERVIEWACTIVE = 7;
		static const Sbecore::uint TXTREUACTIVE = 8;
		static const Sbecore::uint BUTREUVIEWAVAIL = 9;
		static const Sbecore::uint BUTREUVIEWACTIVE = 10;
		static const Sbecore::uint LSTIATACTIVE = 11;
		static const Sbecore::uint LSTRATACTIVE = 12;
		static const Sbecore::uint TXFCMTACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool LstIatActive = true, const bool LstRatActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool LstIatActive;
		bool LstRatActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmCalDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTYP = 3;
		static const Sbecore::uint CPTVER = 4;
		static const Sbecore::uint CPTREU = 5;
		static const Sbecore::uint CPTIAT = 6;
		static const Sbecore::uint CPTRAT = 7;
		static const Sbecore::uint CPTCMT = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTyp = "", const std::string& CptVer = "", const std::string& CptReu = "", const std::string& CptIat = "", const std::string& CptRat = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTyp;
		std::string CptVer;
		std::string CptReu;
		std::string CptIat;
		std::string CptRat;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmCalDetailData)
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
		* DpchAppDo (full: DpchAppWznmCalDetailDo)
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
		* DpchEngData (full: DpchEngWznmCalDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTIAT = 4;
		static const Sbecore::uint FEEDFLSTRAT = 5;
		static const Sbecore::uint FEEDFPUPRET = 6;
		static const Sbecore::uint FEEDFPUPTYP = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstIat;
		Sbecore::Feed feedFLstRat;
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
