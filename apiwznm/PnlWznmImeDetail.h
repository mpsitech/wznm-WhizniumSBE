/**
	* \file PnlWznmImeDetail.h
	* API code for job PnlWznmImeDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMIMEDETAIL_H
#define PNLWZNMIMEDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmImeDetailDo PnlWznmImeDetail::VecVDo

#define ContIacWznmImeDetail PnlWznmImeDetail::ContIac
#define ContInfWznmImeDetail PnlWznmImeDetail::ContInf
#define StatAppWznmImeDetail PnlWznmImeDetail::StatApp
#define StatShrWznmImeDetail PnlWznmImeDetail::StatShr
#define TagWznmImeDetail PnlWznmImeDetail::Tag

#define DpchAppWznmImeDetailData PnlWznmImeDetail::DpchAppData
#define DpchAppWznmImeDetailDo PnlWznmImeDetail::DpchAppDo
#define DpchEngWznmImeDetailData PnlWznmImeDetail::DpchEngData

/**
	* PnlWznmImeDetail
	*/
namespace PnlWznmImeDetail {
	/**
		* VecVDo (full: VecVWznmImeDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTIEXVIEWCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;
		static const Sbecore::uint BUTRTRVIEWCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmImeDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMSFLSTIOP = 1;
		static const Sbecore::uint NUMFLSTRTR = 2;
		static const Sbecore::uint TXFRTR = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const std::vector<Sbecore::uint>& numsFLstIop = {}, const Sbecore::uint numFLstRtr = 1, const std::string& TxfRtr = "", const std::string& TxfCmt = "");

	public:
		std::vector<Sbecore::uint> numsFLstIop;
		Sbecore::uint numFLstRtr;
		std::string TxfRtr;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmImeDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTIEX = 2;
		static const Sbecore::uint TXTSUP = 3;
		static const Sbecore::uint TXTTBL = 4;
		static const Sbecore::uint TXTIOP = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtIex = "", const std::string& TxtSup = "", const std::string& TxtTbl = "", const std::string& TxtIop = "");

	public:
		std::string TxtSrf;
		std::string TxtIex;
		std::string TxtSup;
		std::string TxtTbl;
		std::string TxtIop;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmImeDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTIOPALT = 2;
		static const Sbecore::uint LSTRTRALT = 3;
		static const Sbecore::uint LSTIOPNUMFIRSTDISP = 4;
		static const Sbecore::uint LSTRTRNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstIopAlt = true, const bool LstRtrAlt = true, const Sbecore::uint LstIopNumFirstdisp = 1, const Sbecore::uint LstRtrNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstIopAlt;
		bool LstRtrAlt;
		Sbecore::uint LstIopNumFirstdisp;
		Sbecore::uint LstRtrNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmImeDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFRTRVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXTIEXACTIVE = 5;
		static const Sbecore::uint BUTIEXVIEWAVAIL = 6;
		static const Sbecore::uint BUTIEXVIEWACTIVE = 7;
		static const Sbecore::uint TXTSUPACTIVE = 8;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 9;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 10;
		static const Sbecore::uint TXTTBLACTIVE = 11;
		static const Sbecore::uint LSTIOPACTIVE = 12;
		static const Sbecore::uint LSTRTRACTIVE = 13;
		static const Sbecore::uint BUTRTRVIEWAVAIL = 14;
		static const Sbecore::uint BUTRTRVIEWACTIVE = 15;
		static const Sbecore::uint TXFCMTACTIVE = 16;

	public:
		StatShr(const bool TxfRtrValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtIexActive = true, const bool ButIexViewAvail = true, const bool ButIexViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTblActive = true, const bool LstIopActive = true, const bool LstRtrActive = true, const bool ButRtrViewAvail = true, const bool ButRtrViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfRtrValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtIexActive;
		bool ButIexViewAvail;
		bool ButIexViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtTblActive;
		bool LstIopActive;
		bool LstRtrActive;
		bool ButRtrViewAvail;
		bool ButRtrViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmImeDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTIEX = 3;
		static const Sbecore::uint CPTSUP = 4;
		static const Sbecore::uint CPTTBL = 5;
		static const Sbecore::uint CPTIOP = 6;
		static const Sbecore::uint CPTRTR = 7;
		static const Sbecore::uint CPTCMT = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptIex = "", const std::string& CptSup = "", const std::string& CptTbl = "", const std::string& CptIop = "", const std::string& CptRtr = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptIex;
		std::string CptSup;
		std::string CptTbl;
		std::string CptIop;
		std::string CptRtr;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmImeDetailData)
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
		* DpchAppDo (full: DpchAppWznmImeDetailDo)
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
		* DpchEngData (full: DpchEngWznmImeDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTIOP = 4;
		static const Sbecore::uint FEEDFLSTRTR = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstIop;
		Sbecore::Feed feedFLstRtr;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
