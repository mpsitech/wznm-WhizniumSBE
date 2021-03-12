/**
	* \file PnlWznmQcoDetail.h
	* API code for job PnlWznmQcoDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMQCODETAIL_H
#define PNLWZNMQCODETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmQcoDetailDo PnlWznmQcoDetail::VecVDo

#define ContIacWznmQcoDetail PnlWznmQcoDetail::ContIac
#define ContInfWznmQcoDetail PnlWznmQcoDetail::ContInf
#define StatAppWznmQcoDetail PnlWznmQcoDetail::StatApp
#define StatShrWznmQcoDetail PnlWznmQcoDetail::StatShr
#define TagWznmQcoDetail PnlWznmQcoDetail::Tag

#define DpchAppWznmQcoDetailData PnlWznmQcoDetail::DpchAppData
#define DpchAppWznmQcoDetailDo PnlWznmQcoDetail::DpchAppDo
#define DpchEngWznmQcoDetailData PnlWznmQcoDetail::DpchEngData

/**
	* PnlWznmQcoDetail
	*/
namespace PnlWznmQcoDetail {
	/**
		* VecVDo (full: VecVWznmQcoDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTQRYVIEWCLICK = 2;
		static const Sbecore::uint BUTSTBVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmQcoDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFSHO = 1;
		static const Sbecore::uint NUMFPUPTYP = 2;
		static const Sbecore::uint NUMSFLSTOCC = 3;

	public:
		ContIac(const std::string& TxfSho = "", const Sbecore::uint numFPupTyp = 1, const std::vector<Sbecore::uint>& numsFLstOcc = {});

	public:
		std::string TxfSho;
		Sbecore::uint numFPupTyp;
		std::vector<Sbecore::uint> numsFLstOcc;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmQcoDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTOCC = 2;
		static const Sbecore::uint TXTQRY = 3;
		static const Sbecore::uint TXTTCO = 4;
		static const Sbecore::uint TXTSTB = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtOcc = "", const std::string& TxtQry = "", const std::string& TxtTco = "", const std::string& TxtStb = "");

	public:
		std::string TxtSrf;
		std::string TxtOcc;
		std::string TxtQry;
		std::string TxtTco;
		std::string TxtStb;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmQcoDetail)
	  */
	class StatApp : public Sbecore::Block {

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
	  * StatShr (full: StatShrWznmQcoDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFSHOACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint LSTOCCACTIVE = 6;
		static const Sbecore::uint TXTQRYACTIVE = 7;
		static const Sbecore::uint BUTQRYVIEWAVAIL = 8;
		static const Sbecore::uint BUTQRYVIEWACTIVE = 9;
		static const Sbecore::uint TXTTCOACTIVE = 10;
		static const Sbecore::uint TXTSTBACTIVE = 11;
		static const Sbecore::uint BUTSTBVIEWAVAIL = 12;
		static const Sbecore::uint BUTSTBVIEWACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfShoActive = true, const bool PupTypActive = true, const bool LstOccActive = true, const bool TxtQryActive = true, const bool ButQryViewAvail = true, const bool ButQryViewActive = true, const bool TxtTcoActive = true, const bool TxtStbActive = true, const bool ButStbViewAvail = true, const bool ButStbViewActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfShoActive;
		bool PupTypActive;
		bool LstOccActive;
		bool TxtQryActive;
		bool ButQryViewAvail;
		bool ButQryViewActive;
		bool TxtTcoActive;
		bool TxtStbActive;
		bool ButStbViewAvail;
		bool ButStbViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmQcoDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTSHO = 3;
		static const Sbecore::uint CPTTYP = 4;
		static const Sbecore::uint CPTOCC = 5;
		static const Sbecore::uint CPTQRY = 6;
		static const Sbecore::uint CPTTCO = 7;
		static const Sbecore::uint CPTSTB = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptSho = "", const std::string& CptTyp = "", const std::string& CptOcc = "", const std::string& CptQry = "", const std::string& CptTco = "", const std::string& CptStb = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptSho;
		std::string CptTyp;
		std::string CptOcc;
		std::string CptQry;
		std::string CptTco;
		std::string CptStb;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmQcoDetailData)
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
		* DpchAppDo (full: DpchAppWznmQcoDetailDo)
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
		* DpchEngData (full: DpchEngWznmQcoDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTOCC = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstOcc;
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
