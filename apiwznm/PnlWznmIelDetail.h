/**
	* \file PnlWznmIelDetail.h
	* API code for job PnlWznmIelDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMIELDETAIL_H
#define PNLWZNMIELDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmIelDetailDo PnlWznmIelDetail::VecVDo

#define ContIacWznmIelDetail PnlWznmIelDetail::ContIac
#define ContInfWznmIelDetail PnlWznmIelDetail::ContInf
#define StatAppWznmIelDetail PnlWznmIelDetail::StatApp
#define StatShrWznmIelDetail PnlWznmIelDetail::StatShr
#define TagWznmIelDetail PnlWznmIelDetail::Tag

#define DpchAppWznmIelDetailData PnlWznmIelDetail::DpchAppData
#define DpchAppWznmIelDetailDo PnlWznmIelDetail::DpchAppDo
#define DpchEngWznmIelDetailData PnlWznmIelDetail::DpchEngData

/**
	* PnlWznmIelDetail
	*/
namespace PnlWznmIelDetail {
	/**
		* VecVDo (full: VecVWznmIelDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTIMEVIEWCLICK = 2;
		static const Sbecore::uint BUTIM2VIEWCLICK = 3;
		static const Sbecore::uint BUTPSTVIEWCLICK = 4;
		static const Sbecore::uint BUTSTBVIEWCLICK = 5;
		static const Sbecore::uint BUTVITVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmIelDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint NUMSFLSTOCC = 3;
		static const Sbecore::uint NUMFPUPCTY = 4;
		static const Sbecore::uint TXFDFV = 5;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupTyp = 1, const std::vector<Sbecore::uint>& numsFLstOcc = {}, const Sbecore::uint numFPupCty = 1, const std::string& TxfDfv = "");

	public:
		std::string TxfSho;
		Sbecore::uint numFPupTyp;
		std::vector<Sbecore::uint> numsFLstOcc;
		Sbecore::uint numFPupCty;
		std::string TxfDfv;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmIelDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTOCC = 2;
		static const Sbecore::uint TXTIME = 3;
		static const Sbecore::uint TXTTCO = 4;
		static const Sbecore::uint TXTIM2 = 5;
		static const Sbecore::uint TXTPST = 6;
		static const Sbecore::uint TXTSTB = 7;
		static const Sbecore::uint TXTVIT = 8;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtOcc = "", const std::string& TxtIme = "", const std::string& TxtTco = "", const std::string& TxtIm2 = "", const std::string& TxtPst = "", const std::string& TxtStb = "", const std::string& TxtVit = "");

	public:
		std::string TxtSrf;
		std::string TxtOcc;
		std::string TxtIme;
		std::string TxtTco;
		std::string TxtIm2;
		std::string TxtPst;
		std::string TxtStb;
		std::string TxtVit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmIelDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTOCCALT = 2;
		static const Sbecore::uint LSTOCCNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstOccAlt = true, const Sbecore::uint LstOccNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstOccAlt;
		Sbecore::uint LstOccNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmIelDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFSHOACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint LSTOCCACTIVE = 6;
		static const Sbecore::uint TXTIMEACTIVE = 7;
		static const Sbecore::uint BUTIMEVIEWAVAIL = 8;
		static const Sbecore::uint BUTIMEVIEWACTIVE = 9;
		static const Sbecore::uint TXTTCOACTIVE = 10;
		static const Sbecore::uint TXTIM2ACTIVE = 11;
		static const Sbecore::uint BUTIM2VIEWAVAIL = 12;
		static const Sbecore::uint BUTIM2VIEWACTIVE = 13;
		static const Sbecore::uint PUPCTYACTIVE = 14;
		static const Sbecore::uint TXFDFVACTIVE = 15;
		static const Sbecore::uint TXTPSTACTIVE = 16;
		static const Sbecore::uint BUTPSTVIEWAVAIL = 17;
		static const Sbecore::uint BUTPSTVIEWACTIVE = 18;
		static const Sbecore::uint TXTSTBACTIVE = 19;
		static const Sbecore::uint BUTSTBVIEWAVAIL = 20;
		static const Sbecore::uint BUTSTBVIEWACTIVE = 21;
		static const Sbecore::uint TXTVITACTIVE = 22;
		static const Sbecore::uint BUTVITVIEWAVAIL = 23;
		static const Sbecore::uint BUTVITVIEWACTIVE = 24;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupTypActive = true, const bool LstOccActive = true, const bool TxtImeActive = true, const bool ButImeViewAvail = true, const bool ButImeViewActive = true, const bool TxtTcoActive = true, const bool TxtIm2Active = true, const bool ButIm2ViewAvail = true, const bool ButIm2ViewActive = true, const bool PupCtyActive = true, const bool TxfDfvActive = true, const bool TxtPstActive = true, const bool ButPstViewAvail = true, const bool ButPstViewActive = true, const bool TxtStbActive = true, const bool ButStbViewAvail = true, const bool ButStbViewActive = true, const bool TxtVitActive = true, const bool ButVitViewAvail = true, const bool ButVitViewActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupTypActive;
		bool LstOccActive;
		bool TxtImeActive;
		bool ButImeViewAvail;
		bool ButImeViewActive;
		bool TxtTcoActive;
		bool TxtIm2Active;
		bool ButIm2ViewAvail;
		bool ButIm2ViewActive;
		bool PupCtyActive;
		bool TxfDfvActive;
		bool TxtPstActive;
		bool ButPstViewAvail;
		bool ButPstViewActive;
		bool TxtStbActive;
		bool ButStbViewAvail;
		bool ButStbViewActive;
		bool TxtVitActive;
		bool ButVitViewAvail;
		bool ButVitViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmIelDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTSHO = 3;
		static const Sbecore::uint CPTTYP = 4;
		static const Sbecore::uint CPTOCC = 5;
		static const Sbecore::uint CPTIME = 6;
		static const Sbecore::uint CPTTCO = 7;
		static const Sbecore::uint CPTIM2 = 8;
		static const Sbecore::uint CPTCTY = 9;
		static const Sbecore::uint CPTDFV = 10;
		static const Sbecore::uint CPTPST = 11;
		static const Sbecore::uint CPTSTB = 12;
		static const Sbecore::uint CPTVIT = 13;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptSho = "", const std::string& CptTyp = "", const std::string& CptOcc = "", const std::string& CptIme = "", const std::string& CptTco = "", const std::string& CptIm2 = "", const std::string& CptCty = "", const std::string& CptDfv = "", const std::string& CptPst = "", const std::string& CptStb = "", const std::string& CptVit = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptSho;
		std::string CptTyp;
		std::string CptOcc;
		std::string CptIme;
		std::string CptTco;
		std::string CptIm2;
		std::string CptCty;
		std::string CptDfv;
		std::string CptPst;
		std::string CptStb;
		std::string CptVit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmIelDetailData)
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
		* DpchAppDo (full: DpchAppWznmIelDetailDo)
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
		* DpchEngData (full: DpchEngWznmIelDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOCC = 4;
		static const Sbecore::uint FEEDFPUPCTY = 5;
		static const Sbecore::uint FEEDFPUPTYP = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstOcc;
		Sbecore::Xmlio::Feed feedFPupCty;
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

