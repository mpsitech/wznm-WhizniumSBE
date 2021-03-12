/**
	* \file PnlWznmMchDetail.h
	* API code for job PnlWznmMchDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMMCHDETAIL_H
#define PNLWZNMMCHDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmMchDetailDo PnlWznmMchDetail::VecVDo

#define ContIacWznmMchDetail PnlWznmMchDetail::ContIac
#define ContInfWznmMchDetail PnlWznmMchDetail::ContInf
#define StatAppWznmMchDetail PnlWznmMchDetail::StatApp
#define StatShrWznmMchDetail PnlWznmMchDetail::StatShr
#define TagWznmMchDetail PnlWznmMchDetail::Tag

#define DpchAppWznmMchDetailData PnlWznmMchDetail::DpchAppData
#define DpchAppWznmMchDetailDo PnlWznmMchDetail::DpchAppDo
#define DpchEngWznmMchDetailData PnlWznmMchDetail::DpchEngData

/**
	* PnlWznmMchDetail
	*/
namespace PnlWznmMchDetail {
	/**
		* VecVDo (full: VecVWznmMchDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTSUPVIEWCLICK = 2;
		static const Sbecore::uint BUTCCHVIEWCLICK = 3;
		static const Sbecore::uint BUTPKMEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmMchDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPPKM = 1;
		static const Sbecore::uint TXFPKM = 2;
		static const Sbecore::uint TXFCMT = 3;

	public:
		ContIac(const Sbecore::uint numFPupPkm = 1, const std::string& TxfPkm = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupPkm;
		std::string TxfPkm;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmMchDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTSUP = 2;
		static const Sbecore::uint TXTCCH = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtSup = "", const std::string& TxtCch = "");

	public:
		std::string TxtSrf;
		std::string TxtSup;
		std::string TxtCch;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmMchDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint PUPPKMALT = 2;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool PupPkmAlt = false);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool PupPkmAlt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmMchDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFPKMVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint TXTSUPACTIVE = 5;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 6;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 7;
		static const Sbecore::uint TXTCCHACTIVE = 8;
		static const Sbecore::uint BUTCCHVIEWAVAIL = 9;
		static const Sbecore::uint BUTCCHVIEWACTIVE = 10;
		static const Sbecore::uint PUPPKMACTIVE = 11;
		static const Sbecore::uint BUTPKMEDITAVAIL = 12;
		static const Sbecore::uint TXFCMTACTIVE = 13;

	public:
		StatShr(const bool TxfPkmValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtCchActive = true, const bool ButCchViewAvail = true, const bool ButCchViewActive = true, const bool PupPkmActive = true, const bool ButPkmEditAvail = true, const bool TxfCmtActive = true);

	public:
		bool TxfPkmValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtCchActive;
		bool ButCchViewAvail;
		bool ButCchViewActive;
		bool PupPkmActive;
		bool ButPkmEditAvail;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmMchDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTSUP = 3;
		static const Sbecore::uint CPTCCH = 4;
		static const Sbecore::uint CPTPKM = 5;
		static const Sbecore::uint CPTCMT = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptSup = "", const std::string& CptCch = "", const std::string& CptPkm = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptSup;
		std::string CptCch;
		std::string CptPkm;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmMchDetailData)
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
		* DpchAppDo (full: DpchAppWznmMchDetailDo)
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
		* DpchEngData (full: DpchEngWznmMchDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPPKM = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupPkm;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
