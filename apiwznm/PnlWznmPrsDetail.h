/**
	* \file PnlWznmPrsDetail.h
	* API code for job PnlWznmPrsDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMPRSDETAIL_H
#define PNLWZNMPRSDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmPrsDetailDo PnlWznmPrsDetail::VecVDo

#define ContIacWznmPrsDetail PnlWznmPrsDetail::ContIac
#define ContInfWznmPrsDetail PnlWznmPrsDetail::ContInf
#define StatAppWznmPrsDetail PnlWznmPrsDetail::StatApp
#define StatShrWznmPrsDetail PnlWznmPrsDetail::StatShr
#define TagWznmPrsDetail PnlWznmPrsDetail::Tag

#define DpchAppWznmPrsDetailData PnlWznmPrsDetail::DpchAppData
#define DpchAppWznmPrsDetailDo PnlWznmPrsDetail::DpchAppDo
#define DpchEngWznmPrsDetailData PnlWznmPrsDetail::DpchEngData

/**
	* PnlWznmPrsDetail
	*/
namespace PnlWznmPrsDetail {
	/**
		* VecVDo (full: VecVWznmPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJLNEDITCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmPrsDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFFNM = 2;
		static const Sbecore::uint NUMFPUPJLN = 3;
		static const Sbecore::uint NUMSFLSTDRV = 4;
		static const Sbecore::uint NUMFPUPSEX = 5;
		static const Sbecore::uint TXFTEL = 6;
		static const Sbecore::uint TXFEML = 7;
		static const Sbecore::uint TXFSAL = 8;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfFnm = "", const Sbecore::uint numFPupJln = 1, const std::vector<Sbecore::uint>& numsFLstDrv = {}, const Sbecore::uint numFPupSex = 1, const std::string& TxfTel = "", const std::string& TxfEml = "", const std::string& TxfSal = "");

	public:
		std::string TxfTit;
		std::string TxfFnm;
		Sbecore::uint numFPupJln;
		std::vector<Sbecore::uint> numsFLstDrv;
		Sbecore::uint numFPupSex;
		std::string TxfTel;
		std::string TxfEml;
		std::string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmPrsDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTLNM = 1;
		static const Sbecore::uint TXTDRV = 2;

	public:
		ContInf(const std::string& TxtLnm = "", const std::string& TxtDrv = "");

	public:
		std::string TxtLnm;
		std::string TxtDrv;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmPrsDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTDRVALT = 2;
		static const Sbecore::uint LSTDRVNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstDrvAlt = true, const Sbecore::uint LstDrvNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstDrvAlt;
		Sbecore::uint LstDrvNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmPrsDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFTITACTIVE = 3;
		static const Sbecore::uint TXFFNMACTIVE = 4;
		static const Sbecore::uint PUPJLNACTIVE = 5;
		static const Sbecore::uint BUTJLNEDITAVAIL = 6;
		static const Sbecore::uint TXTLNMACTIVE = 7;
		static const Sbecore::uint LSTDRVACTIVE = 8;
		static const Sbecore::uint PUPSEXACTIVE = 9;
		static const Sbecore::uint TXFTELACTIVE = 10;
		static const Sbecore::uint TXFEMLACTIVE = 11;
		static const Sbecore::uint TXFSALACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxfFnmActive = true, const bool PupJlnActive = true, const bool ButJlnEditAvail = true, const bool TxtLnmActive = true, const bool LstDrvActive = true, const bool PupSexActive = true, const bool TxfTelActive = true, const bool TxfEmlActive = true, const bool TxfSalActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxfFnmActive;
		bool PupJlnActive;
		bool ButJlnEditAvail;
		bool TxtLnmActive;
		bool LstDrvActive;
		bool PupSexActive;
		bool TxfTelActive;
		bool TxfEmlActive;
		bool TxfSalActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmPrsDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTTIT = 2;
		static const Sbecore::uint CPTFNM = 3;
		static const Sbecore::uint CPTLNM = 4;
		static const Sbecore::uint CPTDRV = 5;
		static const Sbecore::uint CPTSEX = 6;
		static const Sbecore::uint CPTTEL = 7;
		static const Sbecore::uint CPTEML = 8;
		static const Sbecore::uint CPTSAL = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptTit = "", const std::string& CptFnm = "", const std::string& CptLnm = "", const std::string& CptDrv = "", const std::string& CptSex = "", const std::string& CptTel = "", const std::string& CptEml = "", const std::string& CptSal = "");

	public:
		std::string Cpt;
		std::string CptTit;
		std::string CptFnm;
		std::string CptLnm;
		std::string CptDrv;
		std::string CptSex;
		std::string CptTel;
		std::string CptEml;
		std::string CptSal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmPrsDetailData)
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
		* DpchAppDo (full: DpchAppWznmPrsDetailDo)
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
		* DpchEngData (full: DpchEngWznmPrsDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDRV = 4;
		static const Sbecore::uint FEEDFPUPJLN = 5;
		static const Sbecore::uint FEEDFPUPSEX = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstDrv;
		Sbecore::Xmlio::Feed feedFPupJln;
		Sbecore::Xmlio::Feed feedFPupSex;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

