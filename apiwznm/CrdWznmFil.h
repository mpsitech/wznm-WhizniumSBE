/**
	* \file CrdWznmFil.h
	* API code for job CrdWznmFil (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef CRDWZNMFIL_H
#define CRDWZNMFIL_H

#include "ApiWznm_blks.h"

#define VecVWznmFilDo CrdWznmFil::VecVDo
#define VecVWznmFilSge CrdWznmFil::VecVSge

#define ContInfWznmFil CrdWznmFil::ContInf
#define StatAppWznmFil CrdWznmFil::StatApp
#define StatShrWznmFil CrdWznmFil::StatShr
#define TagWznmFil CrdWznmFil::Tag

#define DpchAppWznmFilDo CrdWznmFil::DpchAppDo
#define DpchEngWznmFilData CrdWznmFil::DpchEngData

/**
	* CrdWznmFil
	*/
namespace CrdWznmFil {
	/**
		* VecVDo (full: VecVWznmFilDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDDLDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWznmFilSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZNMABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmFil)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDFIL = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdFil = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdFil;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmFil)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrWznmFil)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFDLGDOWNLOAD = 1;
		static const Sbecore::uint SCRJREFDLGNEW = 2;
		static const Sbecore::uint SCRJREFHEADBAR = 3;
		static const Sbecore::uint SCRJREFLIST = 4;
		static const Sbecore::uint SCRJREFREC = 5;
		static const Sbecore::uint MSPCRD1AVAIL = 6;
		static const Sbecore::uint MITCRDNEWAVAIL = 7;
		static const Sbecore::uint MITCRDDLDAVAIL = 8;
		static const Sbecore::uint MITCRDDLDACTIVE = 9;

	public:
		StatShr(const std::string& scrJrefDlgdownload = "", const std::string& scrJrefDlgnew = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefList = "", const std::string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdDldAvail = true, const bool MitCrdDldActive = true);

	public:
		std::string scrJrefDlgdownload;
		std::string scrJrefDlgnew;
		std::string scrJrefHeadbar;
		std::string scrJrefList;
		std::string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdDldAvail;
		bool MitCrdDldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmFil)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDNEW = 3;
		static const Sbecore::uint MITCRDDLD = 4;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdNew = "", const std::string& MitCrdDld = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdNew;
		std::string MitCrdDld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmFilDo)
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
		* DpchEngData (full: DpchEngWznmFilData)
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

