/**
	* \file PnlWznmNavProject.h
	* API code for job PnlWznmNavProject (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVPROJECT_H
#define PNLWZNMNAVPROJECT_H

#include "ApiWznm_blks.h"

#define VecVWznmNavProjectDo PnlWznmNavProject::VecVDo

#define ContIacWznmNavProject PnlWznmNavProject::ContIac
#define StatAppWznmNavProject PnlWznmNavProject::StatApp
#define StatShrWznmNavProject PnlWznmNavProject::StatShr
#define TagWznmNavProject PnlWznmNavProject::Tag

#define DpchAppWznmNavProjectData PnlWznmNavProject::DpchAppData
#define DpchAppWznmNavProjectDo PnlWznmNavProject::DpchAppDo
#define DpchEngWznmNavProjectData PnlWznmNavProject::DpchEngData

/**
	* PnlWznmNavProject
	*/
namespace PnlWznmNavProject {
	/**
		* VecVDo (full: VecVWznmNavProjectDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPRJVIEWCLICK = 1;
		static const Sbecore::uint BUTPRJNEWCRDCLICK = 2;
		static const Sbecore::uint BUTVERVIEWCLICK = 3;
		static const Sbecore::uint BUTVERNEWCRDCLICK = 4;
		static const Sbecore::uint BUTCAPVIEWCLICK = 5;
		static const Sbecore::uint BUTCAPNEWCRDCLICK = 6;
		static const Sbecore::uint BUTERRVIEWCLICK = 7;
		static const Sbecore::uint BUTERRNEWCRDCLICK = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavProject)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTPRJ = 1;
		static const Sbecore::uint NUMFLSTVER = 2;
		static const Sbecore::uint NUMFLSTCAP = 3;
		static const Sbecore::uint NUMFLSTERR = 4;

	public:
		ContIac(const Sbecore::uint numFLstPrj = 1, const Sbecore::uint numFLstVer = 1, const Sbecore::uint numFLstCap = 1, const Sbecore::uint numFLstErr = 1);

	public:
		Sbecore::uint numFLstPrj;
		Sbecore::uint numFLstVer;
		Sbecore::uint numFLstCap;
		Sbecore::uint numFLstErr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNavProject)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTPRJALT = 2;
		static const Sbecore::uint LSTVERALT = 3;
		static const Sbecore::uint LSTCAPALT = 4;
		static const Sbecore::uint LSTERRALT = 5;
		static const Sbecore::uint LSTPRJNUMFIRSTDISP = 6;
		static const Sbecore::uint LSTVERNUMFIRSTDISP = 7;
		static const Sbecore::uint LSTCAPNUMFIRSTDISP = 8;
		static const Sbecore::uint LSTERRNUMFIRSTDISP = 9;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstPrjAlt = true, const bool LstVerAlt = true, const bool LstCapAlt = true, const bool LstErrAlt = true, const Sbecore::uint LstPrjNumFirstdisp = 1, const Sbecore::uint LstVerNumFirstdisp = 1, const Sbecore::uint LstCapNumFirstdisp = 1, const Sbecore::uint LstErrNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstPrjAlt;
		bool LstVerAlt;
		bool LstCapAlt;
		bool LstErrAlt;
		Sbecore::uint LstPrjNumFirstdisp;
		Sbecore::uint LstVerNumFirstdisp;
		Sbecore::uint LstCapNumFirstdisp;
		Sbecore::uint LstErrNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavProject)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTPRJAVAIL = 1;
		static const Sbecore::uint BUTPRJVIEWACTIVE = 2;
		static const Sbecore::uint LSTVERAVAIL = 3;
		static const Sbecore::uint BUTVERVIEWACTIVE = 4;
		static const Sbecore::uint LSTCAPAVAIL = 5;
		static const Sbecore::uint BUTCAPVIEWACTIVE = 6;
		static const Sbecore::uint BUTCAPNEWCRDACTIVE = 7;
		static const Sbecore::uint LSTERRAVAIL = 8;
		static const Sbecore::uint BUTERRVIEWACTIVE = 9;
		static const Sbecore::uint BUTERRNEWCRDACTIVE = 10;

	public:
		StatShr(const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstVerAvail = true, const bool ButVerViewActive = true, const bool LstCapAvail = true, const bool ButCapViewActive = true, const bool ButCapNewcrdActive = true, const bool LstErrAvail = true, const bool ButErrViewActive = true, const bool ButErrNewcrdActive = true);

	public:
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstVerAvail;
		bool ButVerViewActive;
		bool LstCapAvail;
		bool ButCapViewActive;
		bool ButCapNewcrdActive;
		bool LstErrAvail;
		bool ButErrViewActive;
		bool ButErrNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavProject)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPRJ = 2;
		static const Sbecore::uint CPTVER = 3;
		static const Sbecore::uint CPTCAP = 4;
		static const Sbecore::uint CPTERR = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPrj = "", const std::string& CptVer = "", const std::string& CptCap = "", const std::string& CptErr = "");

	public:
		std::string Cpt;
		std::string CptPrj;
		std::string CptVer;
		std::string CptCap;
		std::string CptErr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavProjectData)
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
		* DpchAppDo (full: DpchAppWznmNavProjectDo)
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
		* DpchEngData (full: DpchEngWznmNavProjectData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCAP = 3;
		static const Sbecore::uint FEEDFLSTERR = 4;
		static const Sbecore::uint FEEDFLSTPRJ = 5;
		static const Sbecore::uint FEEDFLSTVER = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstCap;
		Sbecore::Feed feedFLstErr;
		Sbecore::Feed feedFLstPrj;
		Sbecore::Feed feedFLstVer;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
