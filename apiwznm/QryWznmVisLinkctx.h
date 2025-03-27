/**
	* \file QryWznmVisLinkctx.h
	* API code for job QryWznmVisLinkctx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef QRYWZNMVISLINKCTX_H
#define QRYWZNMVISLINKCTX_H

#include "ApiWznm_blks.h"

#define StatShrQryWznmVisLinkctx QryWznmVisLinkctx::StatShr
#define StgIacQryWznmVisLinkctx QryWznmVisLinkctx::StgIac

/**
	* QryWznmVisLinkctx
	*/
namespace QryWznmVisLinkctx {
	/**
	  * StatShr (full: StatShrQryWznmVisLinkctx)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint NTOT = 1;

	public:
		StatShr(const Sbecore::uint ntot = 0);

	public:
		Sbecore::uint ntot;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacQryWznmVisLinkctx)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint JNUM = 1;

	public:
		StgIac(const Sbecore::uint jnum = 0);

	public:
		Sbecore::uint jnum;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

};

#endif
