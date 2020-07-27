/**
	* \file SessWznm.h
	* API code for job SessWznm (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SESSWZNM_H
#define SESSWZNM_H

#include "ApiWznm_blks.h"

#define StatShrSessWznm SessWznm::StatShr

#define DpchEngSessWznmData SessWznm::DpchEngData

/**
	* SessWznm
	*/
namespace SessWznm {
	/**
	  * StatShr (full: StatShrSessWznm)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFCRDNAV = 1;

	public:
		StatShr(const std::string& scrJrefCrdnav = "");

	public:
		std::string scrJrefCrdnav;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessWznmData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint FEEDFENSSEC = 2;
		static const Sbecore::uint STATSHR = 3;

	public:
		DpchEngData();

	public:
		Sbecore::Xmlio::Feed feedFEnsSec;
		StatShr statshr;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
