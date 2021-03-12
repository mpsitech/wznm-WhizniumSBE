/**
	* \file DlgWznmVerFinmod.h
	* API code for job DlgWznmVerFinmod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVERFINMOD_H
#define DLGWZNMVERFINMOD_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmVerFinmodDo DlgWznmVerFinmod::VecVDo
#define VecVDlgWznmVerFinmodSge DlgWznmVerFinmod::VecVSge

#define ContInfDlgWznmVerFinmod DlgWznmVerFinmod::ContInf
#define StatAppDlgWznmVerFinmod DlgWznmVerFinmod::StatApp
#define StatShrDlgWznmVerFinmod DlgWznmVerFinmod::StatShr
#define TagDlgWznmVerFinmod DlgWznmVerFinmod::Tag

#define DpchAppDlgWznmVerFinmodDo DlgWznmVerFinmod::DpchAppDo
#define DpchEngDlgWznmVerFinmodData DlgWznmVerFinmod::DpchEngData

/**
	* DlgWznmVerFinmod
	*/
namespace DlgWznmVerFinmod {
	/**
		* VecVDo (full: VecVDlgWznmVerFinmodDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint FNMBUTRUNCLICK = 1;
		static const Sbecore::uint FNMBUTSTOCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVerFinmodSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint FINMOD = 2;
		static const Sbecore::uint SYNC = 3;
		static const Sbecore::uint DONE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfDlgWznmVerFinmod)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint FNMTXTPRG = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& FnmTxtPrg = "");

	public:
		Sbecore::uint numFSge;
		std::string FnmTxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWznmVerFinmod)
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
	  * StatShr (full: StatShrDlgWznmVerFinmod)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint FNMBUTRUNACTIVE = 1;
		static const Sbecore::uint FNMBUTSTOACTIVE = 2;
		static const Sbecore::uint BUTDNEACTIVE = 3;

	public:
		StatShr(const bool FnmButRunActive = true, const bool FnmButStoActive = true, const bool ButDneActive = true);

	public:
		bool FnmButRunActive;
		bool FnmButStoActive;
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWznmVerFinmod)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint FNMCPTPRG = 2;
		static const Sbecore::uint FNMBUTRUN = 3;
		static const Sbecore::uint FNMBUTSTO = 4;
		static const Sbecore::uint BUTDNE = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& FnmCptPrg = "", const std::string& FnmButRun = "", const std::string& FnmButSto = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string FnmCptPrg;
		std::string FnmButRun;
		std::string FnmButSto;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVerFinmodDo)
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
		* DpchEngData (full: DpchEngDlgWznmVerFinmodData)
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
