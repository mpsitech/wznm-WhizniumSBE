/**
	* \file PnlWznmSbsDetail.h
	* API code for job PnlWznmSbsDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMSBSDETAIL_H
#define PNLWZNMSBSDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmSbsDetailDo PnlWznmSbsDetail::VecVDo

#define ContIacWznmSbsDetail PnlWznmSbsDetail::ContIac
#define ContInfWznmSbsDetail PnlWznmSbsDetail::ContInf
#define StatAppWznmSbsDetail PnlWznmSbsDetail::StatApp
#define StatShrWznmSbsDetail PnlWznmSbsDetail::StatShr
#define TagWznmSbsDetail PnlWznmSbsDetail::Tag

#define DpchAppWznmSbsDetailData PnlWznmSbsDetail::DpchAppData
#define DpchAppWznmSbsDetailDo PnlWznmSbsDetail::DpchAppDo
#define DpchEngWznmSbsDetailData PnlWznmSbsDetail::DpchEngData

/**
	* PnlWznmSbsDetail
	*/
namespace PnlWznmSbsDetail {
	/**
		* VecVDo (full: VecVWznmSbsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCARVIEWCLICK = 2;
		static const Sbecore::uint BUTPSTNEWCLICK = 3;
		static const Sbecore::uint BUTPSTDELETECLICK = 4;
		static const Sbecore::uint BUTPSTJTIEDITCLICK = 5;
		static const Sbecore::uint BUTPSTVERVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmSbsDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint TXFCND = 2;
		static const Sbecore::uint TXFCMT = 3;
		static const Sbecore::uint NUMFPUPPSTJTI = 4;
		static const Sbecore::uint NUMFPUPPSTSCO = 5;
		static const Sbecore::uint NUMFPUPPSTATY = 6;

	public:
		ContIac(const std::string& TxfSho = "", const std::string& TxfCnd = "", const std::string& TxfCmt = "", const Sbecore::uint numFPupPstJti = 1, const Sbecore::uint numFPupPstSco = 1, const Sbecore::uint numFPupPstAty = 1);

	public:
		std::string TxfSho;
		std::string TxfCnd;
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
	  * ContInf (full: ContInfWznmSbsDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTBL = 2;
		static const Sbecore::uint TXTCAR = 3;
		static const Sbecore::uint TXTPSTSRF = 4;
		static const Sbecore::uint TXTPSTTIT = 5;
		static const Sbecore::uint TXTPSTVER = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTbl = "", const std::string& TxtCar = "", const std::string& TxtPstSrf = "", const std::string& TxtPstTit = "", const std::string& TxtPstVer = "");

	public:
		std::string TxtSrf;
		std::string TxtTbl;
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
	  * StatApp (full: StatAppWznmSbsDetail)
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
	  * StatShr (full: StatShrWznmSbsDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFSHOACTIVE = 4;
		static const Sbecore::uint TXTTBLACTIVE = 5;
		static const Sbecore::uint TXTCARACTIVE = 6;
		static const Sbecore::uint BUTCARVIEWAVAIL = 7;
		static const Sbecore::uint BUTCARVIEWACTIVE = 8;
		static const Sbecore::uint TXFCNDACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;
		static const Sbecore::uint BUTPSTNEWAVAIL = 11;
		static const Sbecore::uint BUTPSTDELETEAVAIL = 12;
		static const Sbecore::uint TXTPSTSRFAVAIL = 13;
		static const Sbecore::uint TXTPSTSRFACTIVE = 14;
		static const Sbecore::uint PUPPSTJTIAVAIL = 15;
		static const Sbecore::uint PUPPSTJTIACTIVE = 16;
		static const Sbecore::uint BUTPSTJTIEDITAVAIL = 17;
		static const Sbecore::uint TXTPSTTITAVAIL = 18;
		static const Sbecore::uint TXTPSTTITACTIVE = 19;
		static const Sbecore::uint TXTPSTVERAVAIL = 20;
		static const Sbecore::uint TXTPSTVERACTIVE = 21;
		static const Sbecore::uint BUTPSTVERVIEWAVAIL = 22;
		static const Sbecore::uint BUTPSTVERVIEWACTIVE = 23;
		static const Sbecore::uint PUPPSTSCOAVAIL = 24;
		static const Sbecore::uint PUPPSTSCOACTIVE = 25;
		static const Sbecore::uint PUPPSTATYAVAIL = 26;
		static const Sbecore::uint PUPPSTATYACTIVE = 27;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool TxtTblActive = true, const bool TxtCarActive = true, const bool ButCarViewAvail = true, const bool ButCarViewActive = true, const bool TxfCndActive = true, const bool TxfCmtActive = true, const bool ButPstNewAvail = true, const bool ButPstDeleteAvail = true, const bool TxtPstSrfAvail = true, const bool TxtPstSrfActive = true, const bool PupPstJtiAvail = true, const bool PupPstJtiActive = true, const bool ButPstJtiEditAvail = true, const bool TxtPstTitAvail = true, const bool TxtPstTitActive = true, const bool TxtPstVerAvail = true, const bool TxtPstVerActive = true, const bool ButPstVerViewAvail = true, const bool ButPstVerViewActive = true, const bool PupPstScoAvail = true, const bool PupPstScoActive = true, const bool PupPstAtyAvail = true, const bool PupPstAtyActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool TxtTblActive;
		bool TxtCarActive;
		bool ButCarViewAvail;
		bool ButCarViewActive;
		bool TxfCndActive;
		bool TxfCmtActive;
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
	  * Tag (full: TagWznmSbsDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTSHO = 3;
		static const Sbecore::uint CPTTBL = 4;
		static const Sbecore::uint CPTCAR = 5;
		static const Sbecore::uint CPTCND = 6;
		static const Sbecore::uint CPTCMT = 7;
		static const Sbecore::uint HDGPST = 8;
		static const Sbecore::uint CPTPSTSRF = 9;
		static const Sbecore::uint CPTPSTTIT = 10;
		static const Sbecore::uint CPTPSTVER = 11;
		static const Sbecore::uint CPTPSTSCO = 12;
		static const Sbecore::uint CPTPSTATY = 13;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptSho = "", const std::string& CptTbl = "", const std::string& CptCar = "", const std::string& CptCnd = "", const std::string& CptCmt = "", const std::string& HdgPst = "", const std::string& CptPstSrf = "", const std::string& CptPstTit = "", const std::string& CptPstVer = "", const std::string& CptPstSco = "", const std::string& CptPstAty = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptSho;
		std::string CptTbl;
		std::string CptCar;
		std::string CptCnd;
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
		* DpchAppData (full: DpchAppWznmSbsDetailData)
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
		* DpchAppDo (full: DpchAppWznmSbsDetailDo)
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
		* DpchEngData (full: DpchEngWznmSbsDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPPSTATY = 4;
		static const Sbecore::uint FEEDFPUPPSTJTI = 5;
		static const Sbecore::uint FEEDFPUPPSTSCO = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupPstAty;
		Sbecore::Xmlio::Feed feedFPupPstJti;
		Sbecore::Xmlio::Feed feedFPupPstSco;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

