/**
	* \file PnlWznmQryDetail.h
	* API code for job PnlWznmQryDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMQRYDETAIL_H
#define PNLWZNMQRYDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmQryDetailDo PnlWznmQryDetail::VecVDo

#define ContIacWznmQryDetail PnlWznmQryDetail::ContIac
#define ContInfWznmQryDetail PnlWznmQryDetail::ContInf
#define StatAppWznmQryDetail PnlWznmQryDetail::StatApp
#define StatShrWznmQryDetail PnlWznmQryDetail::StatShr
#define TagWznmQryDetail PnlWznmQryDetail::Tag

#define DpchAppWznmQryDetailData PnlWznmQryDetail::DpchAppData
#define DpchAppWznmQryDetailDo PnlWznmQryDetail::DpchAppDo
#define DpchEngWznmQryDetailData PnlWznmQryDetail::DpchEngData

/**
	* PnlWznmQryDetail
	*/
namespace PnlWznmQryDetail {
	/**
		* VecVDo (full: VecVWznmQryDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVERVIEWCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;
		static const Sbecore::uint BUTJOBVIEWCLICK = 4;
		static const Sbecore::uint BUTINOVIEWCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmQryDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint CHKLOF = 2;
		static const Sbecore::uint NUMFLSTINO = 3;
		static const Sbecore::uint TXFINO = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const bool ChkLof = false, const Sbecore::uint numFLstIno = 1, const std::string& TxfIno = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupTyp;
		bool ChkLof;
		Sbecore::uint numFLstIno;
		std::string TxfIno;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmQryDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVER = 2;
		static const Sbecore::uint TXTSUP = 3;
		static const Sbecore::uint TXTTBL = 4;
		static const Sbecore::uint TXTQTB = 5;
		static const Sbecore::uint TXTJOB = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVer = "", const std::string& TxtSup = "", const std::string& TxtTbl = "", const std::string& TxtQtb = "", const std::string& TxtJob = "");

	public:
		std::string TxtSrf;
		std::string TxtVer;
		std::string TxtSup;
		std::string TxtTbl;
		std::string TxtQtb;
		std::string TxtJob;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmQryDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTINOALT = 2;
		static const Sbecore::uint LSTINONUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstInoAlt = true, const Sbecore::uint LstInoNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstInoAlt;
		Sbecore::uint LstInoNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmQryDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFINOVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint TXTVERACTIVE = 6;
		static const Sbecore::uint BUTVERVIEWAVAIL = 7;
		static const Sbecore::uint BUTVERVIEWACTIVE = 8;
		static const Sbecore::uint TXTSUPACTIVE = 9;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 10;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 11;
		static const Sbecore::uint TXTTBLACTIVE = 12;
		static const Sbecore::uint TXTQTBACTIVE = 13;
		static const Sbecore::uint TXTJOBACTIVE = 14;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 15;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 16;
		static const Sbecore::uint CHKLOFACTIVE = 17;
		static const Sbecore::uint LSTINOACTIVE = 18;
		static const Sbecore::uint BUTINOVIEWAVAIL = 19;
		static const Sbecore::uint BUTINOVIEWACTIVE = 20;
		static const Sbecore::uint TXFCMTACTIVE = 21;

	public:
		StatShr(const bool TxfInoValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtVerActive = true, const bool ButVerViewAvail = true, const bool ButVerViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTblActive = true, const bool TxtQtbActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool ChkLofActive = true, const bool LstInoActive = true, const bool ButInoViewAvail = true, const bool ButInoViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfInoValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtVerActive;
		bool ButVerViewAvail;
		bool ButVerViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtTblActive;
		bool TxtQtbActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool ChkLofActive;
		bool LstInoActive;
		bool ButInoViewAvail;
		bool ButInoViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmQryDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTYP = 3;
		static const Sbecore::uint CPTVER = 4;
		static const Sbecore::uint CPTSUP = 5;
		static const Sbecore::uint CPTTBL = 6;
		static const Sbecore::uint CPTQTB = 7;
		static const Sbecore::uint CPTJOB = 8;
		static const Sbecore::uint CPTLOF = 9;
		static const Sbecore::uint CPTINO = 10;
		static const Sbecore::uint CPTCMT = 11;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTyp = "", const std::string& CptVer = "", const std::string& CptSup = "", const std::string& CptTbl = "", const std::string& CptQtb = "", const std::string& CptJob = "", const std::string& CptLof = "", const std::string& CptIno = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTyp;
		std::string CptVer;
		std::string CptSup;
		std::string CptTbl;
		std::string CptQtb;
		std::string CptJob;
		std::string CptLof;
		std::string CptIno;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmQryDetailData)
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
		* DpchAppDo (full: DpchAppWznmQryDetailDo)
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
		* DpchEngData (full: DpchEngWznmQryDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTINO = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstIno;
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

