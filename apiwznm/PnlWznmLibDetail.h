/**
	* \file PnlWznmLibDetail.h
	* API code for job PnlWznmLibDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef PNLWZNMLIBDETAIL_H
#define PNLWZNMLIBDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmLibDetailDo PnlWznmLibDetail::VecVDo

#define ContIacWznmLibDetail PnlWznmLibDetail::ContIac
#define ContInfWznmLibDetail PnlWznmLibDetail::ContInf
#define StatAppWznmLibDetail PnlWznmLibDetail::StatApp
#define StatShrWznmLibDetail PnlWznmLibDetail::StatShr
#define TagWznmLibDetail PnlWznmLibDetail::Tag

#define DpchAppWznmLibDetailData PnlWznmLibDetail::DpchAppData
#define DpchAppWznmLibDetailDo PnlWznmLibDetail::DpchAppDo
#define DpchEngWznmLibDetailData PnlWznmLibDetail::DpchEngData

/**
	* PnlWznmLibDetail
	*/
namespace PnlWznmLibDetail {
	/**
		* VecVDo (full: VecVWznmLibDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTLTYEDITCLICK = 2;
		static const Sbecore::uint BUTDEPVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmLibDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFVER = 2;
		static const Sbecore::uint NUMFPUPLTY = 3;
		static const Sbecore::uint TXFLTY = 4;
		static const Sbecore::uint NUMFLSTDEP = 5;
		static const Sbecore::uint TXFDEP = 6;
		static const Sbecore::uint TXFCMT = 7;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfVer = "", const Sbecore::uint numFPupLty = 1, const std::string& TxfLty = "", const Sbecore::uint numFLstDep = 1, const std::string& TxfDep = "", const std::string& TxfCmt = "");

	public:
		std::string TxfTit;
		std::string TxfVer;
		Sbecore::uint numFPupLty;
		std::string TxfLty;
		Sbecore::uint numFLstDep;
		std::string TxfDep;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmLibDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;

	public:
		ContInf(const std::string& TxtSrf = "");

	public:
		std::string TxtSrf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmLibDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint PUPLTYALT = 2;
		static const Sbecore::uint LSTDEPALT = 3;
		static const Sbecore::uint LSTDEPNUMFIRSTDISP = 4;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool PupLtyAlt = false, const bool LstDepAlt = true, const Sbecore::uint LstDepNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool PupLtyAlt;
		bool LstDepAlt;
		Sbecore::uint LstDepNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmLibDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFLTYVALID = 1;
		static const Sbecore::uint TXFDEPVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint TXFTITACTIVE = 6;
		static const Sbecore::uint TXFVERACTIVE = 7;
		static const Sbecore::uint PUPLTYACTIVE = 8;
		static const Sbecore::uint BUTLTYEDITAVAIL = 9;
		static const Sbecore::uint LSTDEPACTIVE = 10;
		static const Sbecore::uint BUTDEPVIEWAVAIL = 11;
		static const Sbecore::uint BUTDEPVIEWACTIVE = 12;
		static const Sbecore::uint TXFCMTACTIVE = 13;

	public:
		StatShr(const bool TxfLtyValid = false, const bool TxfDepValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool TxfVerActive = true, const bool PupLtyActive = true, const bool ButLtyEditAvail = true, const bool LstDepActive = true, const bool ButDepViewAvail = true, const bool ButDepViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfLtyValid;
		bool TxfDepValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool TxfVerActive;
		bool PupLtyActive;
		bool ButLtyEditAvail;
		bool LstDepActive;
		bool ButDepViewAvail;
		bool ButDepViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmLibDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTVER = 4;
		static const Sbecore::uint CPTLTY = 5;
		static const Sbecore::uint CPTDEP = 6;
		static const Sbecore::uint CPTCMT = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptVer = "", const std::string& CptLty = "", const std::string& CptDep = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptVer;
		std::string CptLty;
		std::string CptDep;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmLibDetailData)
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
		* DpchAppDo (full: DpchAppWznmLibDetailDo)
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
		* DpchEngData (full: DpchEngWznmLibDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDEP = 4;
		static const Sbecore::uint FEEDFPUPLTY = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstDep;
		Sbecore::Xmlio::Feed feedFPupLty;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

