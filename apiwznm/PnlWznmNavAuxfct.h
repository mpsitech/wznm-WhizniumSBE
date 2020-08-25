/**
	* \file PnlWznmNavAuxfct.h
	* API code for job PnlWznmNavAuxfct (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef PNLWZNMNAVAUXFCT_H
#define PNLWZNMNAVAUXFCT_H

#include "ApiWznm_blks.h"

#define VecVWznmNavAuxfctDo PnlWznmNavAuxfct::VecVDo

#define StatAppWznmNavAuxfct PnlWznmNavAuxfct::StatApp
#define StatShrWznmNavAuxfct PnlWznmNavAuxfct::StatShr
#define TagWznmNavAuxfct PnlWznmNavAuxfct::Tag

#define DpchAppWznmNavAuxfctDo PnlWznmNavAuxfct::DpchAppDo
#define DpchEngWznmNavAuxfctData PnlWznmNavAuxfct::DpchEngData

/**
	* PnlWznmNavAuxfct
	*/
namespace PnlWznmNavAuxfct {
	/**
		* VecVDo (full: VecVWznmNavAuxfctDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUTLNEWCRDCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * StatApp (full: StatAppWznmNavAuxfct)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrWznmNavAuxfct)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTUTLNEWCRDAVAIL = 1;

	public:
		StatShr(const bool ButUtlNewcrdAvail = true);

	public:
		bool ButUtlNewcrdAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavAuxfct)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTUTL = 2;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptUtl = "");

	public:
		std::string Cpt;
		std::string CptUtl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavAuxfctDo)
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
		* DpchEngData (full: DpchEngWznmNavAuxfctData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STATAPP = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

