/**
	* \file DlgWznmVisMissfeat.h
	* API code for job DlgWznmVisMissfeat (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVISMISSFEAT_H
#define DLGWZNMVISMISSFEAT_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmVisMissfeatDo DlgWznmVisMissfeat::VecVDo
#define VecVDlgWznmVisMissfeatSge DlgWznmVisMissfeat::VecVSge

#define ContInfDlgWznmVisMissfeat DlgWznmVisMissfeat::ContInf
#define StatAppDlgWznmVisMissfeat DlgWznmVisMissfeat::StatApp
#define StatShrDlgWznmVisMissfeat DlgWznmVisMissfeat::StatShr
#define TagDlgWznmVisMissfeat DlgWznmVisMissfeat::Tag

#define DpchAppDlgWznmVisMissfeatDo DlgWznmVisMissfeat::DpchAppDo
#define DpchEngDlgWznmVisMissfeatData DlgWznmVisMissfeat::DpchEngData

/**
	* DlgWznmVisMissfeat
	*/
namespace DlgWznmVisMissfeat {
	/**
		* VecVDo (full: VecVDlgWznmVisMissfeatDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CMFBUTRUNCLICK = 1;
		static const Sbecore::uint CMFBUTSTOCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVisMissfeatSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint COMPL = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfDlgWznmVisMissfeat)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint CMFTXTPRG = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& CmfTxtPrg = "");

	public:
		Sbecore::uint numFSge;
		std::string CmfTxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWznmVisMissfeat)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint SHORTMENU = 1;

	public:
		StatApp(const std::string& shortMenu = "");

	public:
		std::string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWznmVisMissfeat)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint CMFBUTRUNACTIVE = 1;
		static const Sbecore::uint CMFBUTSTOACTIVE = 2;
		static const Sbecore::uint BUTDNEACTIVE = 3;

	public:
		StatShr(const bool CmfButRunActive = true, const bool CmfButStoActive = true, const bool ButDneActive = true);

	public:
		bool CmfButRunActive;
		bool CmfButStoActive;
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWznmVisMissfeat)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CMFCPTPRG = 2;
		static const Sbecore::uint CMFBUTRUN = 3;
		static const Sbecore::uint CMFBUTSTO = 4;
		static const Sbecore::uint BUTDNE = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CmfCptPrg = "", const std::string& CmfButRun = "", const std::string& CmfButSto = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string CmfCptPrg;
		std::string CmfButRun;
		std::string CmfButSto;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVisMissfeatDo)
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
		* DpchEngData (full: DpchEngDlgWznmVisMissfeatData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
