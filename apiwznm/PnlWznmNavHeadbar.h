/**
	* \file PnlWznmNavHeadbar.h
	* API code for job PnlWznmNavHeadbar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVHEADBAR_H
#define PNLWZNMNAVHEADBAR_H

#include "ApiWznm_blks.h"

#define StatShrWznmNavHeadbar PnlWznmNavHeadbar::StatShr
#define StgInfWznmNavHeadbar PnlWznmNavHeadbar::StgInf
#define TagWznmNavHeadbar PnlWznmNavHeadbar::Tag

#define DpchEngWznmNavHeadbarData PnlWznmNavHeadbar::DpchEngData

/**
	* PnlWznmNavHeadbar
	*/
namespace PnlWznmNavHeadbar {
	/**
	  * StatShr (full: StatShrWznmNavHeadbar)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgInf (full: StgInfWznmNavHeadbar)
	  */
	class StgInf : public Sbecore::Block {

	public:
		static const Sbecore::uint MENAPPCPTWIDTH = 1;
		static const Sbecore::uint MENAPPWIDTH = 2;
		static const Sbecore::uint MENSESCPTWIDTH = 3;
		static const Sbecore::uint MENSESWIDTH = 4;
		static const Sbecore::uint MENCRDCPTWIDTH = 5;
		static const Sbecore::uint MENCRDWIDTH = 6;

	public:
		StgInf(const Sbecore::uint MenAppCptwidth = 100, const Sbecore::uint MenAppWidth = 100, const Sbecore::uint MenSesCptwidth = 100, const Sbecore::uint MenSesWidth = 100, const Sbecore::uint MenCrdCptwidth = 100, const Sbecore::uint MenCrdWidth = 100);

	public:
		Sbecore::uint MenAppCptwidth;
		Sbecore::uint MenAppWidth;
		Sbecore::uint MenSesCptwidth;
		Sbecore::uint MenSesWidth;
		Sbecore::uint MenCrdCptwidth;
		Sbecore::uint MenCrdWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StgInf* comp);
		std::set<Sbecore::uint> diff(const StgInf* comp);
	};

	/**
	  * Tag (full: TagWznmNavHeadbar)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MENAPP = 1;
		static const Sbecore::uint MENSES = 2;
		static const Sbecore::uint MENCRD = 3;

	public:
		Tag(const std::string& MenApp = "", const std::string& MenSes = "", const std::string& MenCrd = "");

	public:
		std::string MenApp;
		std::string MenSes;
		std::string MenCrd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmNavHeadbarData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint STGINF = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		StatShr statshr;
		StgInf stginf;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
