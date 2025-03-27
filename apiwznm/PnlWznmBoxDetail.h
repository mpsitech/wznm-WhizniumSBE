/**
	* \file PnlWznmBoxDetail.h
	* API code for job PnlWznmBoxDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef PNLWZNMBOXDETAIL_H
#define PNLWZNMBOXDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmBoxDetailDo PnlWznmBoxDetail::VecVDo

#define ContIacWznmBoxDetail PnlWznmBoxDetail::ContIac
#define ContInfWznmBoxDetail PnlWznmBoxDetail::ContInf
#define StatAppWznmBoxDetail PnlWznmBoxDetail::StatApp
#define StatShrWznmBoxDetail PnlWznmBoxDetail::StatShr
#define TagWznmBoxDetail PnlWznmBoxDetail::Tag

#define DpchAppWznmBoxDetailData PnlWznmBoxDetail::DpchAppData
#define DpchAppWznmBoxDetailDo PnlWznmBoxDetail::DpchAppDo
#define DpchEngWznmBoxDetailData PnlWznmBoxDetail::DpchEngData

/**
	* PnlWznmBoxDetail
	*/
namespace PnlWznmBoxDetail {
	/**
		* VecVDo (full: VecVWznmBoxDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTSHTVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmBoxDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPY = 1;
		static const Sbecore::uint TXFX = 2;
		static const Sbecore::uint TXFY = 3;

	public:
		ContIac(const Sbecore::uint numFPupY = 1, const std::string& TxfX = "", const std::string& TxfY = "");

	public:
		Sbecore::uint numFPupY;
		std::string TxfX;
		std::string TxfY;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmBoxDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSHT = 1;
		static const Sbecore::uint TXTUNV = 2;

	public:
		ContInf(const std::string& TxtSht = "", const std::string& TxtUnv = "");

	public:
		std::string TxtSht;
		std::string TxtUnv;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmBoxDetail)
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
	  * StatShr (full: StatShrWznmBoxDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSHTACTIVE = 3;
		static const Sbecore::uint BUTSHTVIEWAVAIL = 4;
		static const Sbecore::uint BUTSHTVIEWACTIVE = 5;
		static const Sbecore::uint TXTUNVACTIVE = 6;
		static const Sbecore::uint TXFXACTIVE = 7;
		static const Sbecore::uint TXFYACTIVE = 8;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtShtActive = true, const bool ButShtViewAvail = true, const bool ButShtViewActive = true, const bool TxtUnvActive = true, const bool TxfXActive = true, const bool TxfYActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtShtActive;
		bool ButShtViewAvail;
		bool ButShtViewActive;
		bool TxtUnvActive;
		bool TxfXActive;
		bool TxfYActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmBoxDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSHT = 2;
		static const Sbecore::uint CPTUNV = 3;
		static const Sbecore::uint CPTX = 4;
		static const Sbecore::uint CPTY = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSht = "", const std::string& CptUnv = "", const std::string& CptX = "", const std::string& CptY = "");

	public:
		std::string Cpt;
		std::string CptSht;
		std::string CptUnv;
		std::string CptX;
		std::string CptY;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmBoxDetailData)
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
		* DpchAppDo (full: DpchAppWznmBoxDetailDo)
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
		* DpchEngData (full: DpchEngWznmBoxDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPY = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupY;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
