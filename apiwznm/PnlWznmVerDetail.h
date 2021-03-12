/**
	* \file PnlWznmVerDetail.h
	* API code for job PnlWznmVerDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMVERDETAIL_H
#define PNLWZNMVERDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmVerDetailDo PnlWznmVerDetail::VecVDo

#define ContIacWznmVerDetail PnlWznmVerDetail::ContIac
#define ContInfWznmVerDetail PnlWznmVerDetail::ContInf
#define StatAppWznmVerDetail PnlWznmVerDetail::StatApp
#define StatShrWznmVerDetail PnlWznmVerDetail::StatShr
#define TagWznmVerDetail PnlWznmVerDetail::Tag

#define DpchAppWznmVerDetailData PnlWznmVerDetail::DpchAppData
#define DpchAppWznmVerDetailDo PnlWznmVerDetail::DpchAppDo
#define DpchEngWznmVerDetailData PnlWznmVerDetail::DpchEngData

/**
	* PnlWznmVerDetail
	*/
namespace PnlWznmVerDetail {
	/**
		* VecVDo (full: VecVWznmVerDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRJVIEWCLICK = 2;
		static const Sbecore::uint BUTBVRVIEWCLICK = 3;
		static const Sbecore::uint BUTLOCVIEWCLICK = 4;
		static const Sbecore::uint BUTJSTEDITCLICK = 5;
		static const Sbecore::uint BUTJEDITCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmVerDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFMAJ = 1;
		static const Sbecore::uint TXFMIN = 2;
		static const Sbecore::uint TXFSUB = 3;
		static const Sbecore::uint NUMFPUPJST = 4;
		static const Sbecore::uint NUMFPUPSTE = 5;
		static const Sbecore::uint NUMSFLSTDTY = 6;
		static const Sbecore::uint NUMSFLSTOPT = 7;
		static const Sbecore::uint NUMFPUPJ = 8;
		static const Sbecore::uint TXFCMT = 9;

	public:
		ContIac(const std::string& TxfMaj = "", const std::string& TxfMin = "", const std::string& TxfSub = "", const Sbecore::uint numFPupJst = 1, const Sbecore::uint numFPupSte = 1, const std::vector<Sbecore::uint>& numsFLstDty = {}, const std::vector<Sbecore::uint>& numsFLstOpt = {}, const Sbecore::uint numFPupJ = 1, const std::string& TxfCmt = "");

	public:
		std::string TxfMaj;
		std::string TxfMin;
		std::string TxfSub;
		Sbecore::uint numFPupJst;
		Sbecore::uint numFPupSte;
		std::vector<Sbecore::uint> numsFLstDty;
		std::vector<Sbecore::uint> numsFLstOpt;
		Sbecore::uint numFPupJ;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmVerDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRJ = 1;
		static const Sbecore::uint TXTBVR = 2;
		static const Sbecore::uint TXTLOC = 3;
		static const Sbecore::uint TXTDTY = 4;
		static const Sbecore::uint TXTOPT = 5;
		static const Sbecore::uint TXTAB1 = 6;
		static const Sbecore::uint TXTAB2 = 7;
		static const Sbecore::uint TXTAB3 = 8;

	public:
		ContInf(const std::string& TxtPrj = "", const std::string& TxtBvr = "", const std::string& TxtLoc = "", const std::string& TxtDty = "", const std::string& TxtOpt = "", const std::string& TxtAb1 = "", const std::string& TxtAb2 = "", const std::string& TxtAb3 = "");

	public:
		std::string TxtPrj;
		std::string TxtBvr;
		std::string TxtLoc;
		std::string TxtDty;
		std::string TxtOpt;
		std::string TxtAb1;
		std::string TxtAb2;
		std::string TxtAb3;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmVerDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTDTYALT = 2;
		static const Sbecore::uint LSTOPTALT = 3;
		static const Sbecore::uint LSTDTYNUMFIRSTDISP = 4;
		static const Sbecore::uint LSTOPTNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstDtyAlt = true, const bool LstOptAlt = true, const Sbecore::uint LstDtyNumFirstdisp = 1, const Sbecore::uint LstOptNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstDtyAlt;
		bool LstOptAlt;
		Sbecore::uint LstDtyNumFirstdisp;
		Sbecore::uint LstOptNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmVerDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRJACTIVE = 3;
		static const Sbecore::uint BUTPRJVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRJVIEWACTIVE = 5;
		static const Sbecore::uint TXFMAJACTIVE = 6;
		static const Sbecore::uint TXFMINACTIVE = 7;
		static const Sbecore::uint TXFSUBACTIVE = 8;
		static const Sbecore::uint TXTBVRACTIVE = 9;
		static const Sbecore::uint BUTBVRVIEWAVAIL = 10;
		static const Sbecore::uint BUTBVRVIEWACTIVE = 11;
		static const Sbecore::uint TXTLOCACTIVE = 12;
		static const Sbecore::uint BUTLOCVIEWAVAIL = 13;
		static const Sbecore::uint BUTLOCVIEWACTIVE = 14;
		static const Sbecore::uint PUPJSTACTIVE = 15;
		static const Sbecore::uint BUTJSTEDITAVAIL = 16;
		static const Sbecore::uint PUPSTEACTIVE = 17;
		static const Sbecore::uint LSTDTYACTIVE = 18;
		static const Sbecore::uint LSTOPTACTIVE = 19;
		static const Sbecore::uint PUPJACTIVE = 20;
		static const Sbecore::uint BUTJEDITAVAIL = 21;
		static const Sbecore::uint TXTAB1ACTIVE = 22;
		static const Sbecore::uint TXTAB2ACTIVE = 23;
		static const Sbecore::uint TXTAB3ACTIVE = 24;
		static const Sbecore::uint TXFCMTACTIVE = 25;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrjActive = true, const bool ButPrjViewAvail = true, const bool ButPrjViewActive = true, const bool TxfMajActive = true, const bool TxfMinActive = true, const bool TxfSubActive = true, const bool TxtBvrActive = true, const bool ButBvrViewAvail = true, const bool ButBvrViewActive = true, const bool TxtLocActive = true, const bool ButLocViewAvail = true, const bool ButLocViewActive = true, const bool PupJstActive = true, const bool ButJstEditAvail = true, const bool PupSteActive = true, const bool LstDtyActive = true, const bool LstOptActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtAb1Active = true, const bool TxtAb2Active = true, const bool TxtAb3Active = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrjActive;
		bool ButPrjViewAvail;
		bool ButPrjViewActive;
		bool TxfMajActive;
		bool TxfMinActive;
		bool TxfSubActive;
		bool TxtBvrActive;
		bool ButBvrViewAvail;
		bool ButBvrViewActive;
		bool TxtLocActive;
		bool ButLocViewAvail;
		bool ButLocViewActive;
		bool PupJstActive;
		bool ButJstEditAvail;
		bool PupSteActive;
		bool LstDtyActive;
		bool LstOptActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtAb1Active;
		bool TxtAb2Active;
		bool TxtAb3Active;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmVerDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPRJ = 2;
		static const Sbecore::uint CPTMAJ = 3;
		static const Sbecore::uint CPTMIN = 4;
		static const Sbecore::uint CPTSUB = 5;
		static const Sbecore::uint CPTBVR = 6;
		static const Sbecore::uint CPTLOC = 7;
		static const Sbecore::uint CPTSTE = 8;
		static const Sbecore::uint CPTDTY = 9;
		static const Sbecore::uint CPTOPT = 10;
		static const Sbecore::uint CPTAB1 = 11;
		static const Sbecore::uint CPTAB2 = 12;
		static const Sbecore::uint CPTAB3 = 13;
		static const Sbecore::uint CPTCMT = 14;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPrj = "", const std::string& CptMaj = "", const std::string& CptMin = "", const std::string& CptSub = "", const std::string& CptBvr = "", const std::string& CptLoc = "", const std::string& CptSte = "", const std::string& CptDty = "", const std::string& CptOpt = "", const std::string& CptAb1 = "", const std::string& CptAb2 = "", const std::string& CptAb3 = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptPrj;
		std::string CptMaj;
		std::string CptMin;
		std::string CptSub;
		std::string CptBvr;
		std::string CptLoc;
		std::string CptSte;
		std::string CptDty;
		std::string CptOpt;
		std::string CptAb1;
		std::string CptAb2;
		std::string CptAb3;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmVerDetailData)
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
		* DpchAppDo (full: DpchAppWznmVerDetailDo)
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
		* DpchEngData (full: DpchEngWznmVerDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDTY = 4;
		static const Sbecore::uint FEEDFLSTOPT = 5;
		static const Sbecore::uint FEEDFPUPJ = 6;
		static const Sbecore::uint FEEDFPUPJST = 7;
		static const Sbecore::uint FEEDFPUPSTE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstDty;
		Sbecore::Feed feedFLstOpt;
		Sbecore::Feed feedFPupJ;
		Sbecore::Feed feedFPupJst;
		Sbecore::Feed feedFPupSte;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
