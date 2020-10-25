/**
	* \file DlgWznmAppNew.h
	* API code for job DlgWznmAppNew (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef DLGWZNMAPPNEW_H
#define DLGWZNMAPPNEW_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmAppNewDo DlgWznmAppNew::VecVDo
#define VecVDlgWznmAppNewSge DlgWznmAppNew::VecVSge

#define ContIacDlgWznmAppNew DlgWznmAppNew::ContIac
#define ContInfDlgWznmAppNew DlgWznmAppNew::ContInf
#define StatAppDlgWznmAppNew DlgWznmAppNew::StatApp
#define StatShrDlgWznmAppNew DlgWznmAppNew::StatShr
#define TagDlgWznmAppNew DlgWznmAppNew::Tag

#define DpchAppDlgWznmAppNewData DlgWznmAppNew::DpchAppData
#define DpchAppDlgWznmAppNewDo DlgWznmAppNew::DpchAppDo
#define DpchEngDlgWznmAppNewData DlgWznmAppNew::DpchEngData

/**
	* DlgWznmAppNew
	*/
namespace DlgWznmAppNew {
	/**
		* VecVDo (full: VecVDlgWznmAppNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmAppNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmAppNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDETPUPTRG = 1;
		static const Sbecore::uint NUMFDETPUPVER = 2;
		static const Sbecore::uint DETTXFSHO = 3;
		static const Sbecore::uint DETTXFTIT = 4;

	public:
		ContIac(const Sbecore::uint numFDetPupTrg = 1, const Sbecore::uint numFDetPupVer = 1, const std::string& DetTxfSho = "", const std::string& DetTxfTit = "");

	public:
		Sbecore::uint numFDetPupTrg;
		Sbecore::uint numFDetPupVer;
		std::string DetTxfSho;
		std::string DetTxfTit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmAppNew)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWznmAppNew)
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
	  * StatShr (full: StatShrDlgWznmAppNew)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCNCACTIVE = 1;
		static const Sbecore::uint BUTCREACTIVE = 2;

	public:
		StatShr(const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool ButCncActive;
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWznmAppNew)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint DETCPTTRG = 2;
		static const Sbecore::uint DETCPTVER = 3;
		static const Sbecore::uint DETCPTSHO = 4;
		static const Sbecore::uint DETCPTTIT = 5;
		static const Sbecore::uint BUTCNC = 6;
		static const Sbecore::uint BUTCRE = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& DetCptTrg = "", const std::string& DetCptVer = "", const std::string& DetCptSho = "", const std::string& DetCptTit = "", const std::string& ButCnc = "", const std::string& ButCre = "");

	public:
		std::string Cpt;
		std::string DetCptTrg;
		std::string DetCptVer;
		std::string DetCptSho;
		std::string DetCptTit;
		std::string ButCnc;
		std::string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmAppNewData)
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
		* DpchAppDo (full: DpchAppDlgWznmAppNewDo)
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
		* DpchEngData (full: DpchEngDlgWznmAppNewData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETPUPTRG = 4;
		static const Sbecore::uint FEEDFDETPUPVER = 5;
		static const Sbecore::uint FEEDFSGE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetPupTrg;
		Sbecore::Xmlio::Feed feedFDetPupVer;
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

