/**
	* \file PnlWznmSgeDetail.h
	* API code for job PnlWznmSgeDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMSGEDETAIL_H
#define PNLWZNMSGEDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmSgeDetailDo PnlWznmSgeDetail::VecVDo

#define ContIacWznmSgeDetail PnlWznmSgeDetail::ContIac
#define ContInfWznmSgeDetail PnlWznmSgeDetail::ContInf
#define StatAppWznmSgeDetail PnlWznmSgeDetail::StatApp
#define StatShrWznmSgeDetail PnlWznmSgeDetail::StatShr
#define TagWznmSgeDetail PnlWznmSgeDetail::Tag

#define DpchAppWznmSgeDetailData PnlWznmSgeDetail::DpchAppData
#define DpchAppWznmSgeDetailDo PnlWznmSgeDetail::DpchAppDo
#define DpchEngWznmSgeDetailData PnlWznmSgeDetail::DpchEngData

/**
	* PnlWznmSgeDetail
	*/
namespace PnlWznmSgeDetail {
	/**
		* VecVDo (full: VecVWznmSgeDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJOBVIEWCLICK = 2;
		static const Sbecore::uint BUTSNXVIEWCLICK = 3;
		static const Sbecore::uint BUTFNXVIEWCLICK = 4;
		static const Sbecore::uint BUTSQKNEWCLICK = 5;
		static const Sbecore::uint BUTSQKDELETECLICK = 6;
		static const Sbecore::uint BUTSQKJTIEDITCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmSgeDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint TXFMON = 2;
		static const Sbecore::uint TXFCMT = 3;
		static const Sbecore::uint NUMFPUPSQKJTI = 4;
		static const Sbecore::uint TXFSQKEXA = 5;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const std::string& TxfMon = "", const std::string& TxfCmt = "", const Sbecore::uint numFPupSqkJti = 1, const std::string& TxfSqkExa = "");

	public:
		Sbecore::uint numFPupTyp;
		std::string TxfMon;
		std::string TxfCmt;
		Sbecore::uint numFPupSqkJti;
		std::string TxfSqkExa;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmSgeDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTJOB = 2;
		static const Sbecore::uint TXTSNX = 3;
		static const Sbecore::uint TXTFNX = 4;
		static const Sbecore::uint TXTSQKTIT = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtJob = "", const std::string& TxtSnx = "", const std::string& TxtFnx = "", const std::string& TxtSqkTit = "");

	public:
		std::string TxtSrf;
		std::string TxtJob;
		std::string TxtSnx;
		std::string TxtFnx;
		std::string TxtSqkTit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmSgeDetail)
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
	  * StatShr (full: StatShrWznmSgeDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPTYPACTIVE = 4;
		static const Sbecore::uint TXTJOBACTIVE = 5;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 6;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 7;
		static const Sbecore::uint TXFMONACTIVE = 8;
		static const Sbecore::uint TXTSNXACTIVE = 9;
		static const Sbecore::uint BUTSNXVIEWAVAIL = 10;
		static const Sbecore::uint BUTSNXVIEWACTIVE = 11;
		static const Sbecore::uint TXTFNXACTIVE = 12;
		static const Sbecore::uint BUTFNXVIEWAVAIL = 13;
		static const Sbecore::uint BUTFNXVIEWACTIVE = 14;
		static const Sbecore::uint TXFCMTACTIVE = 15;
		static const Sbecore::uint BUTSQKNEWAVAIL = 16;
		static const Sbecore::uint BUTSQKDELETEAVAIL = 17;
		static const Sbecore::uint PUPSQKJTIAVAIL = 18;
		static const Sbecore::uint PUPSQKJTIACTIVE = 19;
		static const Sbecore::uint BUTSQKJTIEDITAVAIL = 20;
		static const Sbecore::uint TXTSQKTITAVAIL = 21;
		static const Sbecore::uint TXTSQKTITACTIVE = 22;
		static const Sbecore::uint TXFSQKEXAAVAIL = 23;
		static const Sbecore::uint TXFSQKEXAACTIVE = 24;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfMonActive = true, const bool TxtSnxActive = true, const bool ButSnxViewAvail = true, const bool ButSnxViewActive = true, const bool TxtFnxActive = true, const bool ButFnxViewAvail = true, const bool ButFnxViewActive = true, const bool TxfCmtActive = true, const bool ButSqkNewAvail = true, const bool ButSqkDeleteAvail = true, const bool PupSqkJtiAvail = true, const bool PupSqkJtiActive = true, const bool ButSqkJtiEditAvail = true, const bool TxtSqkTitAvail = true, const bool TxtSqkTitActive = true, const bool TxfSqkExaAvail = true, const bool TxfSqkExaActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfMonActive;
		bool TxtSnxActive;
		bool ButSnxViewAvail;
		bool ButSnxViewActive;
		bool TxtFnxActive;
		bool ButFnxViewAvail;
		bool ButFnxViewActive;
		bool TxfCmtActive;
		bool ButSqkNewAvail;
		bool ButSqkDeleteAvail;
		bool PupSqkJtiAvail;
		bool PupSqkJtiActive;
		bool ButSqkJtiEditAvail;
		bool TxtSqkTitAvail;
		bool TxtSqkTitActive;
		bool TxfSqkExaAvail;
		bool TxfSqkExaActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmSgeDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTYP = 3;
		static const Sbecore::uint CPTJOB = 4;
		static const Sbecore::uint CPTMON = 5;
		static const Sbecore::uint CPTSNX = 6;
		static const Sbecore::uint CPTFNX = 7;
		static const Sbecore::uint CPTCMT = 8;
		static const Sbecore::uint HDGSQK = 9;
		static const Sbecore::uint CPTSQKTIT = 10;
		static const Sbecore::uint CPTSQKEXA = 11;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTyp = "", const std::string& CptJob = "", const std::string& CptMon = "", const std::string& CptSnx = "", const std::string& CptFnx = "", const std::string& CptCmt = "", const std::string& HdgSqk = "", const std::string& CptSqkTit = "", const std::string& CptSqkExa = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTyp;
		std::string CptJob;
		std::string CptMon;
		std::string CptSnx;
		std::string CptFnx;
		std::string CptCmt;
		std::string HdgSqk;
		std::string CptSqkTit;
		std::string CptSqkExa;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmSgeDetailData)
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
		* DpchAppDo (full: DpchAppWznmSgeDetailDo)
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
		* DpchEngData (full: DpchEngWznmSgeDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPSQKJTI = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupSqkJti;
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

