/**
	* \file PnlWznmVecDetail.h
	* API code for job PnlWznmVecDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef PNLWZNMVECDETAIL_H
#define PNLWZNMVECDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmVecDetailDo PnlWznmVecDetail::VecVDo

#define ContIacWznmVecDetail PnlWznmVecDetail::ContIac
#define ContInfWznmVecDetail PnlWznmVecDetail::ContInf
#define StatAppWznmVecDetail PnlWznmVecDetail::StatApp
#define StatShrWznmVecDetail PnlWznmVecDetail::StatShr
#define TagWznmVecDetail PnlWznmVecDetail::Tag

#define DpchAppWznmVecDetailData PnlWznmVecDetail::DpchAppData
#define DpchAppWznmVecDetailDo PnlWznmVecDetail::DpchAppDo
#define DpchEngWznmVecDetailData PnlWznmVecDetail::DpchEngData

/**
	* PnlWznmVecDetail
	*/
namespace PnlWznmVecDetail {
	/**
		* VecVDo (full: VecVWznmVecDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTHKUVIEWCLICK = 3;
		static const Sbecore::uint BUTTGREDITCLICK = 4;
		static const Sbecore::uint BUTOPTEDITCLICK = 5;
		static const Sbecore::uint BUTPSTNEWCLICK = 6;
		static const Sbecore::uint BUTPSTDELETECLICK = 7;
		static const Sbecore::uint BUTPSTJTIEDITCLICK = 8;
		static const Sbecore::uint BUTPSTVERVIEWCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmVecDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFPUPHKT = 2;
		static const Sbecore::uint NUMFPUPTGR = 3;
		static const Sbecore::uint TXFTGR = 4;
		static const Sbecore::uint NUMSFLSTOPT = 5;
		static const Sbecore::uint TXFOPT = 6;
		static const Sbecore::uint NUMFPUPPSTJTI = 7;
		static const Sbecore::uint NUMFPUPPSTSCO = 8;
		static const Sbecore::uint NUMFPUPPSTATY = 9;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupHkt = 1, const Sbecore::uint numFPupTgr = 1, const std::string& TxfTgr = "", const std::vector<Sbecore::uint>& numsFLstOpt = {}, const std::string& TxfOpt = "", const Sbecore::uint numFPupPstJti = 1, const Sbecore::uint numFPupPstSco = 1, const Sbecore::uint numFPupPstAty = 1);

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupHkt;
		Sbecore::uint numFPupTgr;
		std::string TxfTgr;
		std::vector<Sbecore::uint> numsFLstOpt;
		std::string TxfOpt;
		Sbecore::uint numFPupPstJti;
		Sbecore::uint numFPupPstSco;
		Sbecore::uint numFPupPstAty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmVecDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTHKU = 3;
		static const Sbecore::uint TXTPSTSRF = 4;
		static const Sbecore::uint TXTPSTTIT = 5;
		static const Sbecore::uint TXTPSTVER = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtHku = "", const std::string& TxtPstSrf = "", const std::string& TxtPstTit = "", const std::string& TxtPstVer = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtHku;
		std::string TxtPstSrf;
		std::string TxtPstTit;
		std::string TxtPstVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmVecDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint PUPTGRALT = 2;
		static const Sbecore::uint LSTOPTALT = 3;
		static const Sbecore::uint LSTOPTNUMFIRSTDISP = 4;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool PupTgrAlt = false, const bool LstOptAlt = true, const Sbecore::uint LstOptNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool PupTgrAlt;
		bool LstOptAlt;
		Sbecore::uint LstOptNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmVecDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTGRVALID = 1;
		static const Sbecore::uint TXFOPTVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint PUPTYPACTIVE = 6;
		static const Sbecore::uint TXTVERACTIVE = 7;
		static const Sbecore::uint BUTVERVIEWAVAIL = 8;
		static const Sbecore::uint BUTVERVIEWACTIVE = 9;
		static const Sbecore::uint TXTHKUACTIVE = 10;
		static const Sbecore::uint BUTHKUVIEWAVAIL = 11;
		static const Sbecore::uint BUTHKUVIEWACTIVE = 12;
		static const Sbecore::uint PUPTGRACTIVE = 13;
		static const Sbecore::uint BUTTGREDITAVAIL = 14;
		static const Sbecore::uint LSTOPTACTIVE = 15;
		static const Sbecore::uint BUTOPTEDITAVAIL = 16;
		static const Sbecore::uint BUTPSTNEWAVAIL = 17;
		static const Sbecore::uint BUTPSTDELETEAVAIL = 18;
		static const Sbecore::uint TXTPSTSRFAVAIL = 19;
		static const Sbecore::uint TXTPSTSRFACTIVE = 20;
		static const Sbecore::uint PUPPSTJTIAVAIL = 21;
		static const Sbecore::uint PUPPSTJTIACTIVE = 22;
		static const Sbecore::uint BUTPSTJTIEDITAVAIL = 23;
		static const Sbecore::uint TXTPSTTITAVAIL = 24;
		static const Sbecore::uint TXTPSTTITACTIVE = 25;
		static const Sbecore::uint TXTPSTVERAVAIL = 26;
		static const Sbecore::uint TXTPSTVERACTIVE = 27;
		static const Sbecore::uint BUTPSTVERVIEWAVAIL = 28;
		static const Sbecore::uint BUTPSTVERVIEWACTIVE = 29;
		static const Sbecore::uint PUPPSTSCOAVAIL = 30;
		static const Sbecore::uint PUPPSTSCOACTIVE = 31;
		static const Sbecore::uint PUPPSTATYAVAIL = 32;
		static const Sbecore::uint PUPPSTATYACTIVE = 33;

	public:
		StatShr(const bool TxfTgrValid = false, const bool TxfOptValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtHkuActive = true, const bool ButHkuViewAvail = true, const bool ButHkuViewActive = true, const bool PupTgrActive = true, const bool ButTgrEditAvail = true, const bool LstOptActive = true, const bool ButOptEditAvail = true, const bool ButPstNewAvail = true, const bool ButPstDeleteAvail = true, const bool TxtPstSrfAvail = true, const bool TxtPstSrfActive = true, const bool PupPstJtiAvail = true, const bool PupPstJtiActive = true, const bool ButPstJtiEditAvail = true, const bool TxtPstTitAvail = true, const bool TxtPstTitActive = true, const bool TxtPstVerAvail = true, const bool TxtPstVerActive = true, const bool ButPstVerViewAvail = true, const bool ButPstVerViewActive = true, const bool PupPstScoAvail = true, const bool PupPstScoActive = true, const bool PupPstAtyAvail = true, const bool PupPstAtyActive = true);

	public:
		bool TxfTgrValid;
		bool TxfOptValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtHkuActive;
		bool ButHkuViewAvail;
		bool ButHkuViewActive;
		bool PupTgrActive;
		bool ButTgrEditAvail;
		bool LstOptActive;
		bool ButOptEditAvail;
		bool ButPstNewAvail;
		bool ButPstDeleteAvail;
		bool TxtPstSrfAvail;
		bool TxtPstSrfActive;
		bool PupPstJtiAvail;
		bool PupPstJtiActive;
		bool ButPstJtiEditAvail;
		bool TxtPstTitAvail;
		bool TxtPstTitActive;
		bool TxtPstVerAvail;
		bool TxtPstVerActive;
		bool ButPstVerViewAvail;
		bool ButPstVerViewActive;
		bool PupPstScoAvail;
		bool PupPstScoActive;
		bool PupPstAtyAvail;
		bool PupPstAtyActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmVecDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTYP = 3;
		static const Sbecore::uint CPTVER = 4;
		static const Sbecore::uint CPTHKU = 5;
		static const Sbecore::uint CPTTGR = 6;
		static const Sbecore::uint CPTOPT = 7;
		static const Sbecore::uint HDGPST = 8;
		static const Sbecore::uint CPTPSTSRF = 9;
		static const Sbecore::uint CPTPSTTIT = 10;
		static const Sbecore::uint CPTPSTVER = 11;
		static const Sbecore::uint CPTPSTSCO = 12;
		static const Sbecore::uint CPTPSTATY = 13;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTyp = "", const std::string& CptVer = "", const std::string& CptHku = "", const std::string& CptTgr = "", const std::string& CptOpt = "", const std::string& HdgPst = "", const std::string& CptPstSrf = "", const std::string& CptPstTit = "", const std::string& CptPstVer = "", const std::string& CptPstSco = "", const std::string& CptPstAty = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTyp;
		std::string CptVer;
		std::string CptHku;
		std::string CptTgr;
		std::string CptOpt;
		std::string HdgPst;
		std::string CptPstSrf;
		std::string CptPstTit;
		std::string CptPstVer;
		std::string CptPstSco;
		std::string CptPstAty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmVecDetailData)
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
		* DpchAppDo (full: DpchAppWznmVecDetailDo)
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
		* DpchEngData (full: DpchEngWznmVecDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOPT = 4;
		static const Sbecore::uint FEEDFPUPHKT = 5;
		static const Sbecore::uint FEEDFPUPPSTATY = 6;
		static const Sbecore::uint FEEDFPUPPSTJTI = 7;
		static const Sbecore::uint FEEDFPUPPSTSCO = 8;
		static const Sbecore::uint FEEDFPUPTGR = 9;
		static const Sbecore::uint FEEDFPUPTYP = 10;
		static const Sbecore::uint STATAPP = 11;
		static const Sbecore::uint STATSHR = 12;
		static const Sbecore::uint TAG = 13;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstOpt;
		Sbecore::Xmlio::Feed feedFPupHkt;
		Sbecore::Xmlio::Feed feedFPupPstAty;
		Sbecore::Xmlio::Feed feedFPupPstJti;
		Sbecore::Xmlio::Feed feedFPupPstSco;
		Sbecore::Xmlio::Feed feedFPupTgr;
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

