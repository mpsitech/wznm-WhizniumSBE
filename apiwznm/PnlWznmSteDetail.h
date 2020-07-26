/**
	* \file PnlWznmSteDetail.h
	* API code for job PnlWznmSteDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMSTEDETAIL_H
#define PNLWZNMSTEDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmSteDetailDo PnlWznmSteDetail::VecVDo

#define ContIacWznmSteDetail PnlWznmSteDetail::ContIac
#define ContInfWznmSteDetail PnlWznmSteDetail::ContInf
#define StatAppWznmSteDetail PnlWznmSteDetail::StatApp
#define StatShrWznmSteDetail PnlWznmSteDetail::StatShr
#define TagWznmSteDetail PnlWznmSteDetail::Tag

#define DpchAppWznmSteDetailData PnlWznmSteDetail::DpchAppData
#define DpchAppWznmSteDetailDo PnlWznmSteDetail::DpchAppDo
#define DpchEngWznmSteDetailData PnlWznmSteDetail::DpchEngData

/**
	* PnlWznmSteDetail
	*/
namespace PnlWznmSteDetail {
	/**
		* VecVDo (full: VecVWznmSteDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTSEQVIEWCLICK = 2;
		static const Sbecore::uint BUTERJVIEWCLICK = 3;
		static const Sbecore::uint BUTEVEVIEWCLICK = 4;
		static const Sbecore::uint BUTEVIVIEWCLICK = 5;
		static const Sbecore::uint BUTESNVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmSteDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPEAC = 1;
		static const Sbecore::uint NUMFPUPLAC = 2;
		static const Sbecore::uint CHKCST = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const Sbecore::uint numFPupEac = 1, const Sbecore::uint numFPupLac = 1, const bool ChkCst = false, const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupEac;
		Sbecore::uint numFPupLac;
		bool ChkCst;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmSteDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTSEQ = 2;
		static const Sbecore::uint TXTERJ = 3;
		static const Sbecore::uint TXTEVE = 4;
		static const Sbecore::uint TXTEVI = 5;
		static const Sbecore::uint TXTESN = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtSeq = "", const std::string& TxtErj = "", const std::string& TxtEve = "", const std::string& TxtEvi = "", const std::string& TxtEsn = "");

	public:
		std::string TxtSrf;
		std::string TxtSeq;
		std::string TxtErj;
		std::string TxtEve;
		std::string TxtEvi;
		std::string TxtEsn;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmSteDetail)
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
	  * StatShr (full: StatShrWznmSteDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXTSEQACTIVE = 4;
		static const Sbecore::uint BUTSEQVIEWAVAIL = 5;
		static const Sbecore::uint BUTSEQVIEWACTIVE = 6;
		static const Sbecore::uint PUPEACACTIVE = 7;
		static const Sbecore::uint TXTERJACTIVE = 8;
		static const Sbecore::uint BUTERJVIEWAVAIL = 9;
		static const Sbecore::uint BUTERJVIEWACTIVE = 10;
		static const Sbecore::uint TXTEVEACTIVE = 11;
		static const Sbecore::uint BUTEVEVIEWAVAIL = 12;
		static const Sbecore::uint BUTEVEVIEWACTIVE = 13;
		static const Sbecore::uint TXTEVIACTIVE = 14;
		static const Sbecore::uint BUTEVIVIEWAVAIL = 15;
		static const Sbecore::uint BUTEVIVIEWACTIVE = 16;
		static const Sbecore::uint TXTESNACTIVE = 17;
		static const Sbecore::uint BUTESNVIEWAVAIL = 18;
		static const Sbecore::uint BUTESNVIEWACTIVE = 19;
		static const Sbecore::uint PUPLACACTIVE = 20;
		static const Sbecore::uint CHKCSTACTIVE = 21;
		static const Sbecore::uint TXFCMTACTIVE = 22;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtSeqActive = true, const bool ButSeqViewAvail = true, const bool ButSeqViewActive = true, const bool PupEacActive = true, const bool TxtErjActive = true, const bool ButErjViewAvail = true, const bool ButErjViewActive = true, const bool TxtEveActive = true, const bool ButEveViewAvail = true, const bool ButEveViewActive = true, const bool TxtEviActive = true, const bool ButEviViewAvail = true, const bool ButEviViewActive = true, const bool TxtEsnActive = true, const bool ButEsnViewAvail = true, const bool ButEsnViewActive = true, const bool PupLacActive = true, const bool ChkCstActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtSeqActive;
		bool ButSeqViewAvail;
		bool ButSeqViewActive;
		bool PupEacActive;
		bool TxtErjActive;
		bool ButErjViewAvail;
		bool ButErjViewActive;
		bool TxtEveActive;
		bool ButEveViewAvail;
		bool ButEveViewActive;
		bool TxtEviActive;
		bool ButEviViewAvail;
		bool ButEviViewActive;
		bool TxtEsnActive;
		bool ButEsnViewAvail;
		bool ButEsnViewActive;
		bool PupLacActive;
		bool ChkCstActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmSteDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTSEQ = 3;
		static const Sbecore::uint CPTEAC = 4;
		static const Sbecore::uint CPTERJ = 5;
		static const Sbecore::uint CPTEVE = 6;
		static const Sbecore::uint CPTEVI = 7;
		static const Sbecore::uint CPTESN = 8;
		static const Sbecore::uint CPTLAC = 9;
		static const Sbecore::uint CPTCST = 10;
		static const Sbecore::uint CPTCMT = 11;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptSeq = "", const std::string& CptEac = "", const std::string& CptErj = "", const std::string& CptEve = "", const std::string& CptEvi = "", const std::string& CptEsn = "", const std::string& CptLac = "", const std::string& CptCst = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptSeq;
		std::string CptEac;
		std::string CptErj;
		std::string CptEve;
		std::string CptEvi;
		std::string CptEsn;
		std::string CptLac;
		std::string CptCst;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmSteDetailData)
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
		* DpchAppDo (full: DpchAppWznmSteDetailDo)
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
		* DpchEngData (full: DpchEngWznmSteDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPEAC = 4;
		static const Sbecore::uint FEEDFPUPLAC = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupEac;
		Sbecore::Xmlio::Feed feedFPupLac;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

