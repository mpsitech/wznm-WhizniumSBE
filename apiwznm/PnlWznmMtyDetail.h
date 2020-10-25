/**
	* \file PnlWznmMtyDetail.h
	* API code for job PnlWznmMtyDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMMTYDETAIL_H
#define PNLWZNMMTYDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmMtyDetailDo PnlWznmMtyDetail::VecVDo

#define ContIacWznmMtyDetail PnlWznmMtyDetail::ContIac
#define ContInfWznmMtyDetail PnlWznmMtyDetail::ContInf
#define StatAppWznmMtyDetail PnlWznmMtyDetail::StatApp
#define StatShrWznmMtyDetail PnlWznmMtyDetail::StatShr
#define TagWznmMtyDetail PnlWznmMtyDetail::Tag

#define DpchAppWznmMtyDetailData PnlWznmMtyDetail::DpchAppData
#define DpchAppWznmMtyDetailDo PnlWznmMtyDetail::DpchAppDo
#define DpchEngWznmMtyDetailData PnlWznmMtyDetail::DpchEngData

/**
	* PnlWznmMtyDetail
	*/
namespace PnlWznmMtyDetail {
	/**
		* VecVDo (full: VecVWznmMtyDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTOSEDITCLICK = 2;
		static const Sbecore::uint BUTCCHVIEWCLICK = 3;
		static const Sbecore::uint BUTPKMEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmMtyDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPACH = 1;
		static const Sbecore::uint NUMFPUPOS = 2;
		static const Sbecore::uint TXFOS = 3;
		static const Sbecore::uint NUMFPUPPKM = 4;
		static const Sbecore::uint TXFPKM = 5;
		static const Sbecore::uint TXFCMT = 6;

	public:
		ContIac(const Sbecore::uint numFPupAch = 1, const Sbecore::uint numFPupOs = 1, const std::string& TxfOs = "", const Sbecore::uint numFPupPkm = 1, const std::string& TxfPkm = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupAch;
		Sbecore::uint numFPupOs;
		std::string TxfOs;
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
	  * ContInf (full: ContInfWznmMtyDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCCH = 2;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtCch = "");

	public:
		std::string TxtSrf;
		std::string TxtCch;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmMtyDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint PUPOSALT = 2;
		static const Sbecore::uint PUPPKMALT = 3;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool PupOsAlt = false, const bool PupPkmAlt = false);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool PupOsAlt;
		bool PupPkmAlt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmMtyDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFOSVALID = 1;
		static const Sbecore::uint TXFPKMVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint PUPACHACTIVE = 6;
		static const Sbecore::uint PUPOSACTIVE = 7;
		static const Sbecore::uint BUTOSEDITAVAIL = 8;
		static const Sbecore::uint TXTCCHACTIVE = 9;
		static const Sbecore::uint BUTCCHVIEWAVAIL = 10;
		static const Sbecore::uint BUTCCHVIEWACTIVE = 11;
		static const Sbecore::uint PUPPKMACTIVE = 12;
		static const Sbecore::uint BUTPKMEDITAVAIL = 13;
		static const Sbecore::uint TXFCMTACTIVE = 14;

	public:
		StatShr(const bool TxfOsValid = false, const bool TxfPkmValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupAchActive = true, const bool PupOsActive = true, const bool ButOsEditAvail = true, const bool TxtCchActive = true, const bool ButCchViewAvail = true, const bool ButCchViewActive = true, const bool PupPkmActive = true, const bool ButPkmEditAvail = true, const bool TxfCmtActive = true);

	public:
		bool TxfOsValid;
		bool TxfPkmValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupAchActive;
		bool PupOsActive;
		bool ButOsEditAvail;
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
	  * Tag (full: TagWznmMtyDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTACH = 3;
		static const Sbecore::uint CPTOS = 4;
		static const Sbecore::uint CPTCCH = 5;
		static const Sbecore::uint CPTPKM = 6;
		static const Sbecore::uint CPTCMT = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptAch = "", const std::string& CptOs = "", const std::string& CptCch = "", const std::string& CptPkm = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptAch;
		std::string CptOs;
		std::string CptCch;
		std::string CptPkm;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmMtyDetailData)
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
		* DpchAppDo (full: DpchAppWznmMtyDetailDo)
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
		* DpchEngData (full: DpchEngWznmMtyDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPACH = 4;
		static const Sbecore::uint FEEDFPUPOS = 5;
		static const Sbecore::uint FEEDFPUPPKM = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupAch;
		Sbecore::Xmlio::Feed feedFPupOs;
		Sbecore::Xmlio::Feed feedFPupPkm;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

