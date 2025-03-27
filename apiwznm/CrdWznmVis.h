/**
	* \file CrdWznmVis.h
	* API code for job CrdWznmVis (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef CRDWZNMVIS_H
#define CRDWZNMVIS_H

#include "ApiWznm_blks.h"

#define VecVWznmVisDo CrdWznmVis::VecVDo
#define VecVWznmVisSge CrdWznmVis::VecVSge

#define ContInfWznmVis CrdWznmVis::ContInf
#define StatAppWznmVis CrdWznmVis::StatApp
#define StatShrWznmVis CrdWznmVis::StatShr
#define TagWznmVis CrdWznmVis::Tag

#define DpchAppWznmVisDo CrdWznmVis::DpchAppDo
#define DpchEngWznmVisData CrdWznmVis::DpchEngData

/**
	* CrdWznmVis
	*/
namespace CrdWznmVis {
	/**
		* VecVDo (full: VecVWznmVisDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDISTCLICK = 4;
		static const Sbecore::uint MITCRDCMFCLICK = 5;
		static const Sbecore::uint MITCRDWRCCLICK = 6;
		static const Sbecore::uint MITCRDESTCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWznmVisSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZNMABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmVis)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDVIS = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdVis = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdVis;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmVis)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONEHEADBAR = 5;
		static const Sbecore::uint INITDONELIST = 6;
		static const Sbecore::uint INITDONEREC = 7;

	public:
		StatApp(const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);

	public:
		Sbecore::uint ixWznmVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneHeadbar;
		bool initdoneList;
		bool initdoneRec;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmVis)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint SCRJREFDLGEXPSTR = 1;
		static const Sbecore::uint SCRJREFDLGIMPSTR = 2;
		static const Sbecore::uint SCRJREFDLGMISSFEAT = 3;
		static const Sbecore::uint SCRJREFDLGNEW = 4;
		static const Sbecore::uint SCRJREFDLGWRITE = 5;
		static const Sbecore::uint SCRJREFHEADBAR = 6;
		static const Sbecore::uint SCRJREFLIST = 7;
		static const Sbecore::uint SCRJREFREC = 8;
		static const Sbecore::uint MSPCRD1AVAIL = 9;
		static const Sbecore::uint MITCRDNEWAVAIL = 10;
		static const Sbecore::uint MITCRDISTAVAIL = 11;
		static const Sbecore::uint MITCRDISTACTIVE = 12;
		static const Sbecore::uint MITCRDCMFAVAIL = 13;
		static const Sbecore::uint MITCRDCMFACTIVE = 14;
		static const Sbecore::uint MITCRDWRCAVAIL = 15;
		static const Sbecore::uint MITCRDWRCACTIVE = 16;
		static const Sbecore::uint MITCRDESTACTIVE = 17;

	public:
		StatShr(const std::string& scrJrefDlgexpstr = "", const std::string& scrJrefDlgimpstr = "", const std::string& scrJrefDlgmissfeat = "", const std::string& scrJrefDlgnew = "", const std::string& scrJrefDlgwrite = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefList = "", const std::string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdIstAvail = true, const bool MitCrdIstActive = true, const bool MitCrdCmfAvail = true, const bool MitCrdCmfActive = true, const bool MitCrdWrcAvail = true, const bool MitCrdWrcActive = true, const bool MitCrdEstActive = true);

	public:
		std::string scrJrefDlgexpstr;
		std::string scrJrefDlgimpstr;
		std::string scrJrefDlgmissfeat;
		std::string scrJrefDlgnew;
		std::string scrJrefDlgwrite;
		std::string scrJrefHeadbar;
		std::string scrJrefList;
		std::string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdIstAvail;
		bool MitCrdIstActive;
		bool MitCrdCmfAvail;
		bool MitCrdCmfActive;
		bool MitCrdWrcAvail;
		bool MitCrdWrcActive;
		bool MitCrdEstActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmVis)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDNEW = 3;
		static const Sbecore::uint MITCRDIST = 4;
		static const Sbecore::uint MITCRDCMF = 5;
		static const Sbecore::uint MITCRDWRC = 6;
		static const Sbecore::uint MITCRDEST = 7;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdNew = "", const std::string& MitCrdIst = "", const std::string& MitCrdCmf = "", const std::string& MitCrdWrc = "", const std::string& MitCrdEst = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdNew;
		std::string MitCrdIst;
		std::string MitCrdCmf;
		std::string MitCrdWrc;
		std::string MitCrdEst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmVisDo)
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
		* DpchEngData (full: DpchEngWznmVisData)
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
