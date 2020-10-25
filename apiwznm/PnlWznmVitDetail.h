/**
	* \file PnlWznmVitDetail.h
	* API code for job PnlWznmVitDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMVITDETAIL_H
#define PNLWZNMVITDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmVitDetailDo PnlWznmVitDetail::VecVDo

#define ContIacWznmVitDetail PnlWznmVitDetail::ContIac
#define ContInfWznmVitDetail PnlWznmVitDetail::ContInf
#define StatAppWznmVitDetail PnlWznmVitDetail::StatApp
#define StatShrWznmVitDetail PnlWznmVitDetail::StatShr
#define TagWznmVitDetail PnlWznmVitDetail::Tag

#define DpchAppWznmVitDetailData PnlWznmVitDetail::DpchAppData
#define DpchAppWznmVitDetailDo PnlWznmVitDetail::DpchAppDo
#define DpchEngWznmVitDetailData PnlWznmVitDetail::DpchEngData

/**
	* PnlWznmVitDetail
	*/
namespace PnlWznmVitDetail {
	/**
		* VecVDo (full: VecVWznmVitDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJEDITCLICK = 2;
		static const Sbecore::uint BUTVECVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmVitDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJ = 1;
		static const Sbecore::uint TXFAVL = 2;
		static const Sbecore::uint TXFIMP = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const Sbecore::uint numFPupJ = 1, const std::string& TxfAvl = "", const std::string& TxfImp = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupJ;
		std::string TxfAvl;
		std::string TxfImp;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmVitDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTVEC = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtVec = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtVec;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmVitDetail)
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
	  * StatShr (full: StatShrWznmVitDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPJACTIVE = 4;
		static const Sbecore::uint BUTJEDITAVAIL = 5;
		static const Sbecore::uint TXTTITACTIVE = 6;
		static const Sbecore::uint TXTVECACTIVE = 7;
		static const Sbecore::uint BUTVECVIEWAVAIL = 8;
		static const Sbecore::uint BUTVECVIEWACTIVE = 9;
		static const Sbecore::uint TXFAVLACTIVE = 10;
		static const Sbecore::uint TXFIMPACTIVE = 11;
		static const Sbecore::uint TXFCMTACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtTitActive = true, const bool TxtVecActive = true, const bool ButVecViewAvail = true, const bool ButVecViewActive = true, const bool TxfAvlActive = true, const bool TxfImpActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtTitActive;
		bool TxtVecActive;
		bool ButVecViewAvail;
		bool ButVecViewActive;
		bool TxfAvlActive;
		bool TxfImpActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmVitDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTVEC = 4;
		static const Sbecore::uint CPTAVL = 5;
		static const Sbecore::uint CPTIMP = 6;
		static const Sbecore::uint CPTCMT = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptVec = "", const std::string& CptAvl = "", const std::string& CptImp = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptVec;
		std::string CptAvl;
		std::string CptImp;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmVitDetailData)
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
		* DpchAppDo (full: DpchAppWznmVitDetailDo)
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
		* DpchEngData (full: DpchEngWznmVitDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJ = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupJ;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

