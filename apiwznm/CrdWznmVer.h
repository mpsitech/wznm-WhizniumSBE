/**
	* \file CrdWznmVer.h
	* API code for job CrdWznmVer (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef CRDWZNMVER_H
#define CRDWZNMVER_H

#include "ApiWznm_blks.h"

#define VecVWznmVerDo CrdWznmVer::VecVDo
#define VecVWznmVerSge CrdWznmVer::VecVSge

#define ContInfWznmVer CrdWznmVer::ContInf
#define StatAppWznmVer CrdWznmVer::StatApp
#define StatShrWznmVer CrdWznmVer::StatShr
#define TagWznmVer CrdWznmVer::Tag

#define DpchAppWznmVerDo CrdWznmVer::DpchAppDo
#define DpchEngWznmVerData CrdWznmVer::DpchEngData

/**
	* CrdWznmVer
	*/
namespace CrdWznmVer {
	/**
		* VecVDo (full: VecVWznmVerDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDPCVCLICK = 4;
		static const Sbecore::uint MITCRDIDPCLICK = 5;
		static const Sbecore::uint MITCRDIGBCLICK = 6;
		static const Sbecore::uint MITCRDWSKCLICK = 7;
		static const Sbecore::uint MITCRDIDBCLICK = 8;
		static const Sbecore::uint MITCRDIBUCLICK = 9;
		static const Sbecore::uint MITCRDIIECLICK = 10;
		static const Sbecore::uint MITCRDIOPCLICK = 11;
		static const Sbecore::uint MITCRDICJCLICK = 12;
		static const Sbecore::uint MITCRDGUICLICK = 13;
		static const Sbecore::uint MITCRDAUICLICK = 14;
		static const Sbecore::uint MITCRDGJTCLICK = 15;
		static const Sbecore::uint MITCRDAJTCLICK = 16;
		static const Sbecore::uint MITCRDFNMCLICK = 17;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWznmVerSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZNMABT = 2;
		static const Sbecore::uint ALRCVW = 3;
		static const Sbecore::uint SETPRJCVR = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmVer)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDVER = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdVer = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmVer)
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
	  * StatShr (full: StatShrWznmVer)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFDLGBSCUI = 1;
		static const Sbecore::uint SCRJREFDLGCUSTJOB = 2;
		static const Sbecore::uint SCRJREFDLGCUSTJTR = 3;
		static const Sbecore::uint SCRJREFDLGCUSTUI = 4;
		static const Sbecore::uint SCRJREFDLGDBSTR = 5;
		static const Sbecore::uint SCRJREFDLGDEPLOY = 6;
		static const Sbecore::uint SCRJREFDLGFINMOD = 7;
		static const Sbecore::uint SCRJREFDLGGENJTR = 8;
		static const Sbecore::uint SCRJREFDLGGENUI = 9;
		static const Sbecore::uint SCRJREFDLGGLOBAL = 10;
		static const Sbecore::uint SCRJREFDLGIMPEXP = 11;
		static const Sbecore::uint SCRJREFDLGNEW = 12;
		static const Sbecore::uint SCRJREFDLGOPPACK = 13;
		static const Sbecore::uint SCRJREFDLGWRSTKIT = 14;
		static const Sbecore::uint SCRJREFHEADBAR = 15;
		static const Sbecore::uint SCRJREFLIST = 16;
		static const Sbecore::uint SCRJREFREC = 17;
		static const Sbecore::uint MSPCRD1AVAIL = 18;
		static const Sbecore::uint MITCRDNEWAVAIL = 19;
		static const Sbecore::uint MITCRDPCVAVAIL = 20;
		static const Sbecore::uint MITCRDPCVACTIVE = 21;
		static const Sbecore::uint MSPCRD3AVAIL = 22;
		static const Sbecore::uint MITCRDIDPAVAIL = 23;
		static const Sbecore::uint MITCRDIDPACTIVE = 24;
		static const Sbecore::uint MITCRDIGBAVAIL = 25;
		static const Sbecore::uint MITCRDIGBACTIVE = 26;
		static const Sbecore::uint MSPCRD4AVAIL = 27;
		static const Sbecore::uint MITCRDWSKAVAIL = 28;
		static const Sbecore::uint MITCRDWSKACTIVE = 29;
		static const Sbecore::uint MSPCRD5AVAIL = 30;
		static const Sbecore::uint MITCRDIDBAVAIL = 31;
		static const Sbecore::uint MITCRDIDBACTIVE = 32;
		static const Sbecore::uint MITCRDIBUAVAIL = 33;
		static const Sbecore::uint MITCRDIBUACTIVE = 34;
		static const Sbecore::uint MITCRDIIEAVAIL = 35;
		static const Sbecore::uint MITCRDIIEACTIVE = 36;
		static const Sbecore::uint MITCRDIOPAVAIL = 37;
		static const Sbecore::uint MITCRDIOPACTIVE = 38;
		static const Sbecore::uint MITCRDICJAVAIL = 39;
		static const Sbecore::uint MITCRDICJACTIVE = 40;
		static const Sbecore::uint MSPCRD6AVAIL = 41;
		static const Sbecore::uint MITCRDGUIAVAIL = 42;
		static const Sbecore::uint MITCRDGUIACTIVE = 43;
		static const Sbecore::uint MITCRDAUIAVAIL = 44;
		static const Sbecore::uint MITCRDAUIACTIVE = 45;
		static const Sbecore::uint MITCRDGJTAVAIL = 46;
		static const Sbecore::uint MITCRDGJTACTIVE = 47;
		static const Sbecore::uint MITCRDAJTAVAIL = 48;
		static const Sbecore::uint MITCRDAJTACTIVE = 49;
		static const Sbecore::uint MSPCRD7AVAIL = 50;
		static const Sbecore::uint MITCRDFNMAVAIL = 51;
		static const Sbecore::uint MITCRDFNMACTIVE = 52;

	public:
		StatShr(const std::string& scrJrefDlgbscui = "", const std::string& scrJrefDlgcustjob = "", const std::string& scrJrefDlgcustjtr = "", const std::string& scrJrefDlgcustui = "", const std::string& scrJrefDlgdbstr = "", const std::string& scrJrefDlgdeploy = "", const std::string& scrJrefDlgfinmod = "", const std::string& scrJrefDlggenjtr = "", const std::string& scrJrefDlggenui = "", const std::string& scrJrefDlgglobal = "", const std::string& scrJrefDlgimpexp = "", const std::string& scrJrefDlgnew = "", const std::string& scrJrefDlgoppack = "", const std::string& scrJrefDlgwrstkit = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefList = "", const std::string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdPcvAvail = true, const bool MitCrdPcvActive = true, const bool MspCrd3Avail = true, const bool MitCrdIdpAvail = true, const bool MitCrdIdpActive = true, const bool MitCrdIgbAvail = true, const bool MitCrdIgbActive = true, const bool MspCrd4Avail = true, const bool MitCrdWskAvail = true, const bool MitCrdWskActive = true, const bool MspCrd5Avail = true, const bool MitCrdIdbAvail = true, const bool MitCrdIdbActive = true, const bool MitCrdIbuAvail = true, const bool MitCrdIbuActive = true, const bool MitCrdIieAvail = true, const bool MitCrdIieActive = true, const bool MitCrdIopAvail = true, const bool MitCrdIopActive = true, const bool MitCrdIcjAvail = true, const bool MitCrdIcjActive = true, const bool MspCrd6Avail = true, const bool MitCrdGuiAvail = true, const bool MitCrdGuiActive = true, const bool MitCrdAuiAvail = true, const bool MitCrdAuiActive = true, const bool MitCrdGjtAvail = true, const bool MitCrdGjtActive = true, const bool MitCrdAjtAvail = true, const bool MitCrdAjtActive = true, const bool MspCrd7Avail = true, const bool MitCrdFnmAvail = true, const bool MitCrdFnmActive = true);

	public:
		std::string scrJrefDlgbscui;
		std::string scrJrefDlgcustjob;
		std::string scrJrefDlgcustjtr;
		std::string scrJrefDlgcustui;
		std::string scrJrefDlgdbstr;
		std::string scrJrefDlgdeploy;
		std::string scrJrefDlgfinmod;
		std::string scrJrefDlggenjtr;
		std::string scrJrefDlggenui;
		std::string scrJrefDlgglobal;
		std::string scrJrefDlgimpexp;
		std::string scrJrefDlgnew;
		std::string scrJrefDlgoppack;
		std::string scrJrefDlgwrstkit;
		std::string scrJrefHeadbar;
		std::string scrJrefList;
		std::string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdPcvAvail;
		bool MitCrdPcvActive;
		bool MspCrd3Avail;
		bool MitCrdIdpAvail;
		bool MitCrdIdpActive;
		bool MitCrdIgbAvail;
		bool MitCrdIgbActive;
		bool MspCrd4Avail;
		bool MitCrdWskAvail;
		bool MitCrdWskActive;
		bool MspCrd5Avail;
		bool MitCrdIdbAvail;
		bool MitCrdIdbActive;
		bool MitCrdIbuAvail;
		bool MitCrdIbuActive;
		bool MitCrdIieAvail;
		bool MitCrdIieActive;
		bool MitCrdIopAvail;
		bool MitCrdIopActive;
		bool MitCrdIcjAvail;
		bool MitCrdIcjActive;
		bool MspCrd6Avail;
		bool MitCrdGuiAvail;
		bool MitCrdGuiActive;
		bool MitCrdAuiAvail;
		bool MitCrdAuiActive;
		bool MitCrdGjtAvail;
		bool MitCrdGjtActive;
		bool MitCrdAjtAvail;
		bool MitCrdAjtActive;
		bool MspCrd7Avail;
		bool MitCrdFnmAvail;
		bool MitCrdFnmActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmVer)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDNEW = 3;
		static const Sbecore::uint MITCRDPCV = 4;
		static const Sbecore::uint MITCRDIDP = 5;
		static const Sbecore::uint MITCRDIGB = 6;
		static const Sbecore::uint MITCRDWSK = 7;
		static const Sbecore::uint MITCRDIDB = 8;
		static const Sbecore::uint MITCRDIBU = 9;
		static const Sbecore::uint MITCRDIIE = 10;
		static const Sbecore::uint MITCRDIOP = 11;
		static const Sbecore::uint MITCRDICJ = 12;
		static const Sbecore::uint MITCRDGUI = 13;
		static const Sbecore::uint MITCRDAUI = 14;
		static const Sbecore::uint MITCRDGJT = 15;
		static const Sbecore::uint MITCRDAJT = 16;
		static const Sbecore::uint MITCRDFNM = 17;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdNew = "", const std::string& MitCrdPcv = "", const std::string& MitCrdIdp = "", const std::string& MitCrdIgb = "", const std::string& MitCrdWsk = "", const std::string& MitCrdIdb = "", const std::string& MitCrdIbu = "", const std::string& MitCrdIie = "", const std::string& MitCrdIop = "", const std::string& MitCrdIcj = "", const std::string& MitCrdGui = "", const std::string& MitCrdAui = "", const std::string& MitCrdGjt = "", const std::string& MitCrdAjt = "", const std::string& MitCrdFnm = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdNew;
		std::string MitCrdPcv;
		std::string MitCrdIdp;
		std::string MitCrdIgb;
		std::string MitCrdWsk;
		std::string MitCrdIdb;
		std::string MitCrdIbu;
		std::string MitCrdIie;
		std::string MitCrdIop;
		std::string MitCrdIcj;
		std::string MitCrdGui;
		std::string MitCrdAui;
		std::string MitCrdGjt;
		std::string MitCrdAjt;
		std::string MitCrdFnm;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmVerDo)
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
		* DpchEngData (full: DpchEngWznmVerData)
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

