/**
	* \file PnlWznmRtjDetail.h
	* API code for job PnlWznmRtjDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMRTJDETAIL_H
#define PNLWZNMRTJDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmRtjDetailDo PnlWznmRtjDetail::VecVDo

#define ContIacWznmRtjDetail PnlWznmRtjDetail::ContIac
#define ContInfWznmRtjDetail PnlWznmRtjDetail::ContInf
#define StatAppWznmRtjDetail PnlWznmRtjDetail::StatApp
#define StatShrWznmRtjDetail PnlWznmRtjDetail::StatShr
#define TagWznmRtjDetail PnlWznmRtjDetail::Tag

#define DpchAppWznmRtjDetailData PnlWznmRtjDetail::DpchAppData
#define DpchAppWznmRtjDetailDo PnlWznmRtjDetail::DpchAppDo
#define DpchEngWznmRtjDetailData PnlWznmRtjDetail::DpchEngData

/**
	* PnlWznmRtjDetail
	*/
namespace PnlWznmRtjDetail {
	/**
		* VecVDo (full: VecVWznmRtjDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTAPPVIEWCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;
		static const Sbecore::uint BUTJOBVIEWCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmRtjDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCMT = 1;

	public:
		ContIac(const std::string& TxfCmt = "");

	public:
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmRtjDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTAPP = 2;
		static const Sbecore::uint TXTSUP = 3;
		static const Sbecore::uint TXTJOB = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtApp = "", const std::string& TxtSup = "", const std::string& TxtJob = "");

	public:
		std::string TxtSrf;
		std::string TxtApp;
		std::string TxtSup;
		std::string TxtJob;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmRtjDetail)
	  */
	class StatApp : public Sbecore::Block {

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
	  * StatShr (full: StatShrWznmRtjDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXTAPPACTIVE = 4;
		static const Sbecore::uint BUTAPPVIEWAVAIL = 5;
		static const Sbecore::uint BUTAPPVIEWACTIVE = 6;
		static const Sbecore::uint TXTSUPACTIVE = 7;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 8;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 9;
		static const Sbecore::uint TXTJOBACTIVE = 10;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 11;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 12;
		static const Sbecore::uint TXFCMTACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtAppActive = true, const bool ButAppViewAvail = true, const bool ButAppViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtAppActive;
		bool ButAppViewAvail;
		bool ButAppViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmRtjDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTAPP = 3;
		static const Sbecore::uint CPTSUP = 4;
		static const Sbecore::uint CPTJOB = 5;
		static const Sbecore::uint CPTCMT = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptApp = "", const std::string& CptSup = "", const std::string& CptJob = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptApp;
		std::string CptSup;
		std::string CptJob;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmRtjDetailData)
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
		* DpchAppDo (full: DpchAppWznmRtjDetailDo)
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
		* DpchEngData (full: DpchEngWznmRtjDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
