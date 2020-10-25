/**
	* \file PnlWznmNavDeploy.h
	* API code for job PnlWznmNavDeploy (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMNAVDEPLOY_H
#define PNLWZNMNAVDEPLOY_H

#include "ApiWznm_blks.h"

#define VecVWznmNavDeployDo PnlWznmNavDeploy::VecVDo

#define ContIacWznmNavDeploy PnlWznmNavDeploy::ContIac
#define StatAppWznmNavDeploy PnlWznmNavDeploy::StatApp
#define StatShrWznmNavDeploy PnlWznmNavDeploy::StatShr
#define TagWznmNavDeploy PnlWznmNavDeploy::Tag

#define DpchAppWznmNavDeployData PnlWznmNavDeploy::DpchAppData
#define DpchAppWznmNavDeployDo PnlWznmNavDeploy::DpchAppDo
#define DpchEngWznmNavDeployData PnlWznmNavDeploy::DpchEngData

/**
	* PnlWznmNavDeploy
	*/
namespace PnlWznmNavDeploy {
	/**
		* VecVDo (full: VecVWznmNavDeployDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCMPVIEWCLICK = 1;
		static const Sbecore::uint BUTCMPNEWCRDCLICK = 2;
		static const Sbecore::uint BUTRLSVIEWCLICK = 3;
		static const Sbecore::uint BUTRLSNEWCRDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavDeploy)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTCMP = 1;
		static const Sbecore::uint NUMFLSTRLS = 2;

	public:
		ContIac(const Sbecore::uint numFLstCmp = 1, const Sbecore::uint numFLstRls = 1);

	public:
		Sbecore::uint numFLstCmp;
		Sbecore::uint numFLstRls;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNavDeploy)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTCMPALT = 2;
		static const Sbecore::uint LSTRLSALT = 3;
		static const Sbecore::uint LSTCMPNUMFIRSTDISP = 4;
		static const Sbecore::uint LSTRLSNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstCmpAlt = true, const bool LstRlsAlt = true, const Sbecore::uint LstCmpNumFirstdisp = 1, const Sbecore::uint LstRlsNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstCmpAlt;
		bool LstRlsAlt;
		Sbecore::uint LstCmpNumFirstdisp;
		Sbecore::uint LstRlsNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavDeploy)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTCMPAVAIL = 1;
		static const Sbecore::uint BUTCMPVIEWACTIVE = 2;
		static const Sbecore::uint BUTCMPNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTRLSAVAIL = 4;
		static const Sbecore::uint BUTRLSVIEWACTIVE = 5;
		static const Sbecore::uint BUTRLSNEWCRDACTIVE = 6;

	public:
		StatShr(const bool LstCmpAvail = true, const bool ButCmpViewActive = true, const bool ButCmpNewcrdActive = true, const bool LstRlsAvail = true, const bool ButRlsViewActive = true, const bool ButRlsNewcrdActive = true);

	public:
		bool LstCmpAvail;
		bool ButCmpViewActive;
		bool ButCmpNewcrdActive;
		bool LstRlsAvail;
		bool ButRlsViewActive;
		bool ButRlsNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavDeploy)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTCMP = 2;
		static const Sbecore::uint CPTRLS = 3;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptCmp = "", const std::string& CptRls = "");

	public:
		std::string Cpt;
		std::string CptCmp;
		std::string CptRls;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavDeployData)
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
		* DpchAppDo (full: DpchAppWznmNavDeployDo)
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
		* DpchEngData (full: DpchEngWznmNavDeployData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCMP = 3;
		static const Sbecore::uint FEEDFLSTRLS = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCmp;
		Sbecore::Xmlio::Feed feedFLstRls;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

