/**
	* \file DlgWznmUsrMngkeypair.h
	* API code for job DlgWznmUsrMngkeypair (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef DLGWZNMUSRMNGKEYPAIR_H
#define DLGWZNMUSRMNGKEYPAIR_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmUsrMngkeypairDo DlgWznmUsrMngkeypair::VecVDo
#define VecVDlgWznmUsrMngkeypairSge DlgWznmUsrMngkeypair::VecVSge

#define ContInfDlgWznmUsrMngkeypair DlgWznmUsrMngkeypair::ContInf
#define StatAppDlgWznmUsrMngkeypair DlgWznmUsrMngkeypair::StatApp
#define StatShrDlgWznmUsrMngkeypair DlgWznmUsrMngkeypair::StatShr
#define TagDlgWznmUsrMngkeypair DlgWznmUsrMngkeypair::Tag

#define DpchAppDlgWznmUsrMngkeypairDo DlgWznmUsrMngkeypair::DpchAppDo
#define DpchEngDlgWznmUsrMngkeypairData DlgWznmUsrMngkeypair::DpchEngData

/**
	* DlgWznmUsrMngkeypair
	*/
namespace DlgWznmUsrMngkeypair {
	/**
		* VecVDo (full: VecVDlgWznmUsrMngkeypairDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTDELCLICK = 1;
		static const Sbecore::uint DETBUTGENCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmUsrMngkeypairSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint NF = 1;
		static const Sbecore::uint FOUND = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfDlgWznmUsrMngkeypair)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint DETTXTSTE = 2;
		static const Sbecore::uint DETDLD = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& DetTxtSte = "", const std::string& DetDld = "file");

	public:
		Sbecore::uint numFSge;
		std::string DetTxtSte;
		std::string DetDld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWznmUsrMngkeypair)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrDlgWznmUsrMngkeypair)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DETBUTDELAVAIL = 1;
		static const Sbecore::uint DETBUTGENAVAIL = 2;
		static const Sbecore::uint DETDLDACTIVE = 3;

	public:
		StatShr(const bool DetButDelAvail = true, const bool DetButGenAvail = true, const bool DetDldActive = true);

	public:
		bool DetButDelAvail;
		bool DetButGenAvail;
		bool DetDldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWznmUsrMngkeypair)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint DETCPTSTE = 2;
		static const Sbecore::uint DETBUTDEL = 3;
		static const Sbecore::uint DETBUTGEN = 4;
		static const Sbecore::uint DETDLD = 5;
		static const Sbecore::uint BUTDNE = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& DetCptSte = "", const std::string& DetButDel = "", const std::string& DetButGen = "", const std::string& DetDld = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string DetCptSte;
		std::string DetButDel;
		std::string DetButGen;
		std::string DetDld;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmUsrMngkeypairDo)
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
		* DpchEngData (full: DpchEngDlgWznmUsrMngkeypairData)
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
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

