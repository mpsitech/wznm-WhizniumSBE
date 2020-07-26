/**
	* \file PnlWznmTblDetail.h
	* API code for job PnlWznmTblDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMTBLDETAIL_H
#define PNLWZNMTBLDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmTblDetailDo PnlWznmTblDetail::VecVDo

#define ContIacWznmTblDetail PnlWznmTblDetail::ContIac
#define ContInfWznmTblDetail PnlWznmTblDetail::ContInf
#define StatAppWznmTblDetail PnlWznmTblDetail::StatApp
#define StatShrWznmTblDetail PnlWznmTblDetail::StatShr
#define TagWznmTblDetail PnlWznmTblDetail::Tag

#define DpchAppWznmTblDetailData PnlWznmTblDetail::DpchAppData
#define DpchAppWznmTblDetailDo PnlWznmTblDetail::DpchAppDo
#define DpchEngWznmTblDetailData PnlWznmTblDetail::DpchEngData

/**
	* PnlWznmTblDetail
	*/
namespace PnlWznmTblDetail {
	/**
		* VecVDo (full: VecVWznmTblDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTREUVIEWCLICK = 3;
		static const Sbecore::uint BUTCARVIEWCLICK = 4;
		static const Sbecore::uint BUTUNQVIEWCLICK = 5;
		static const Sbecore::uint BUTPSTNEWCLICK = 6;
		static const Sbecore::uint BUTPSTDELETECLICK = 7;
		static const Sbecore::uint BUTPSTJTIEDITCLICK = 8;
		static const Sbecore::uint BUTPSTVERVIEWCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmTblDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint NUMFPUPRET = 3;
		static const Sbecore::uint NUMFLSTUNQ = 4;
		static const Sbecore::uint TXFUNQ = 5;
		static const Sbecore::uint TXFCMT = 6;
		static const Sbecore::uint NUMFPUPPSTJTI = 7;
		static const Sbecore::uint NUMFPUPPSTSCO = 8;
		static const Sbecore::uint NUMFPUPPSTATY = 9;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFLstUnq = 1, const std::string& TxfUnq = "", const std::string& TxfCmt = "", const Sbecore::uint numFPupPstJti = 1, const Sbecore::uint numFPupPstSco = 1, const Sbecore::uint numFPupPstAty = 1);

	public:
		std::string TxfSho;
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFLstUnq;
		std::string TxfUnq;
		std::string TxfCmt;
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
	  * ContInf (full: ContInfWznmTblDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTREU = 3;
		static const Sbecore::uint TXTCAR = 4;
		static const Sbecore::uint TXTPSTSRF = 5;
		static const Sbecore::uint TXTPSTTIT = 6;
		static const Sbecore::uint TXTPSTVER = 7;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtReu = "", const std::string& TxtCar = "", const std::string& TxtPstSrf = "", const std::string& TxtPstTit = "", const std::string& TxtPstVer = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtReu;
		std::string TxtCar;
		std::string TxtPstSrf;
		std::string TxtPstTit;
		std::string TxtPstVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmTblDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTUNQALT = 2;
		static const Sbecore::uint LSTUNQNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstUnqAlt = true, const Sbecore::uint LstUnqNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstUnqAlt;
		Sbecore::uint LstUnqNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmTblDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFUNQVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXFSHOACTIVE = 5;
		static const Sbecore::uint PUPTYPACTIVE = 6;
		static const Sbecore::uint TXTVERACTIVE = 7;
		static const Sbecore::uint BUTVERVIEWAVAIL = 8;
		static const Sbecore::uint BUTVERVIEWACTIVE = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint TXTCARAVAIL = 13;
		static const Sbecore::uint TXTCARACTIVE = 14;
		static const Sbecore::uint BUTCARVIEWAVAIL = 15;
		static const Sbecore::uint BUTCARVIEWACTIVE = 16;
		static const Sbecore::uint LSTUNQAVAIL = 17;
		static const Sbecore::uint LSTUNQACTIVE = 18;
		static const Sbecore::uint BUTUNQVIEWAVAIL = 19;
		static const Sbecore::uint BUTUNQVIEWACTIVE = 20;
		static const Sbecore::uint TXFCMTACTIVE = 21;
		static const Sbecore::uint SEPPSTAVAIL = 22;
		static const Sbecore::uint HDGPSTAVAIL = 23;
		static const Sbecore::uint BUTPSTNEWAVAIL = 24;
		static const Sbecore::uint BUTPSTDELETEAVAIL = 25;
		static const Sbecore::uint TXTPSTSRFAVAIL = 26;
		static const Sbecore::uint TXTPSTSRFACTIVE = 27;
		static const Sbecore::uint PUPPSTJTIAVAIL = 28;
		static const Sbecore::uint PUPPSTJTIACTIVE = 29;
		static const Sbecore::uint BUTPSTJTIEDITAVAIL = 30;
		static const Sbecore::uint TXTPSTTITAVAIL = 31;
		static const Sbecore::uint TXTPSTTITACTIVE = 32;
		static const Sbecore::uint TXTPSTVERAVAIL = 33;
		static const Sbecore::uint TXTPSTVERACTIVE = 34;
		static const Sbecore::uint BUTPSTVERVIEWAVAIL = 35;
		static const Sbecore::uint BUTPSTVERVIEWACTIVE = 36;
		static const Sbecore::uint PUPPSTSCOAVAIL = 37;
		static const Sbecore::uint PUPPSTSCOACTIVE = 38;
		static const Sbecore::uint PUPPSTATYAVAIL = 39;
		static const Sbecore::uint PUPPSTATYACTIVE = 40;

	public:
		StatShr(const bool TxfUnqValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxtCarAvail = true, const bool TxtCarActive = true, const bool ButCarViewAvail = true, const bool ButCarViewActive = true, const bool LstUnqAvail = true, const bool LstUnqActive = true, const bool ButUnqViewAvail = true, const bool ButUnqViewActive = true, const bool TxfCmtActive = true, const bool SepPstAvail = true, const bool HdgPstAvail = true, const bool ButPstNewAvail = true, const bool ButPstDeleteAvail = true, const bool TxtPstSrfAvail = true, const bool TxtPstSrfActive = true, const bool PupPstJtiAvail = true, const bool PupPstJtiActive = true, const bool ButPstJtiEditAvail = true, const bool TxtPstTitAvail = true, const bool TxtPstTitActive = true, const bool TxtPstVerAvail = true, const bool TxtPstVerActive = true, const bool ButPstVerViewAvail = true, const bool ButPstVerViewActive = true, const bool PupPstScoAvail = true, const bool PupPstScoActive = true, const bool PupPstAtyAvail = true, const bool PupPstAtyActive = true);

	public:
		bool TxfUnqValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxtCarAvail;
		bool TxtCarActive;
		bool ButCarViewAvail;
		bool ButCarViewActive;
		bool LstUnqAvail;
		bool LstUnqActive;
		bool ButUnqViewAvail;
		bool ButUnqViewActive;
		bool TxfCmtActive;
		bool SepPstAvail;
		bool HdgPstAvail;
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
	  * Tag (full: TagWznmTblDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTSHO = 3;
		static const Sbecore::uint CPTTYP = 4;
		static const Sbecore::uint CPTVER = 5;
		static const Sbecore::uint CPTREU = 6;
		static const Sbecore::uint CPTCAR = 7;
		static const Sbecore::uint CPTUNQ = 8;
		static const Sbecore::uint CPTCMT = 9;
		static const Sbecore::uint HDGPST = 10;
		static const Sbecore::uint CPTPSTSRF = 11;
		static const Sbecore::uint CPTPSTTIT = 12;
		static const Sbecore::uint CPTPSTVER = 13;
		static const Sbecore::uint CPTPSTSCO = 14;
		static const Sbecore::uint CPTPSTATY = 15;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptSho = "", const std::string& CptTyp = "", const std::string& CptVer = "", const std::string& CptReu = "", const std::string& CptCar = "", const std::string& CptUnq = "", const std::string& CptCmt = "", const std::string& HdgPst = "", const std::string& CptPstSrf = "", const std::string& CptPstTit = "", const std::string& CptPstVer = "", const std::string& CptPstSco = "", const std::string& CptPstAty = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptSho;
		std::string CptTyp;
		std::string CptVer;
		std::string CptReu;
		std::string CptCar;
		std::string CptUnq;
		std::string CptCmt;
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
		* DpchAppData (full: DpchAppWznmTblDetailData)
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
		* DpchAppDo (full: DpchAppWznmTblDetailDo)
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
		* DpchEngData (full: DpchEngWznmTblDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTUNQ = 4;
		static const Sbecore::uint FEEDFPUPPSTATY = 5;
		static const Sbecore::uint FEEDFPUPPSTJTI = 6;
		static const Sbecore::uint FEEDFPUPPSTSCO = 7;
		static const Sbecore::uint FEEDFPUPRET = 8;
		static const Sbecore::uint FEEDFPUPTYP = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint TAG = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstUnq;
		Sbecore::Xmlio::Feed feedFPupPstAty;
		Sbecore::Xmlio::Feed feedFPupPstJti;
		Sbecore::Xmlio::Feed feedFPupPstSco;
		Sbecore::Xmlio::Feed feedFPupRet;
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

