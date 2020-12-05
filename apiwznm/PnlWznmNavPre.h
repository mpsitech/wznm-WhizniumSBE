/**
	* \file PnlWznmNavPre.h
	* API code for job PnlWznmNavPre (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVPRE_H
#define PNLWZNMNAVPRE_H

#include "ApiWznm_blks.h"

#define VecVWznmNavPreDo PnlWznmNavPre::VecVDo

#define ContInfWznmNavPre PnlWznmNavPre::ContInf
#define StatShrWznmNavPre PnlWznmNavPre::StatShr
#define TagWznmNavPre PnlWznmNavPre::Tag

#define DpchAppWznmNavPreDo PnlWznmNavPre::DpchAppDo
#define DpchEngWznmNavPreData PnlWznmNavPre::DpchEngData

/**
	* PnlWznmNavPre
	*/
namespace PnlWznmNavPre {
	/**
		* VecVDo (full: VecVWznmNavPreDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTAPPREMOVECLICK = 1;
		static const Sbecore::uint BUTVERREMOVECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmNavPre)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTAPP = 1;
		static const Sbecore::uint TXTVER = 2;

	public:
		ContInf(const std::string& TxtApp = "", const std::string& TxtVer = "");

	public:
		std::string TxtApp;
		std::string TxtVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavPre)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTAPPAVAIL = 1;
		static const Sbecore::uint TXTVERAVAIL = 2;

	public:
		StatShr(const bool TxtAppAvail = true, const bool TxtVerAvail = true);

	public:
		bool TxtAppAvail;
		bool TxtVerAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavPre)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTAPP = 1;
		static const Sbecore::uint CPTVER = 2;

	public:
		Tag(const std::string& CptApp = "", const std::string& CptVer = "");

	public:
		std::string CptApp;
		std::string CptVer;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavPreDo)
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
		* DpchEngData (full: DpchEngWznmNavPreData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

