/**
	* \file QryWznmVerVer1NModule.h
	* API code for job QryWznmVerVer1NModule (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef QRYWZNMVERVER1NMODULE_H
#define QRYWZNMVERVER1NMODULE_H

#include "ApiWznm_blks.h"

#define StatAppQryWznmVerVer1NModule QryWznmVerVer1NModule::StatApp
#define StatShrQryWznmVerVer1NModule QryWznmVerVer1NModule::StatShr
#define StgIacQryWznmVerVer1NModule QryWznmVerVer1NModule::StgIac

/**
	* QryWznmVerVer1NModule
	*/
namespace QryWznmVerVer1NModule {
	/**
	  * StatApp (full: StatAppQryWznmVerVer1NModule)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint FIRSTCOL = 1;
		static const Sbecore::uint JNUMFIRSTDISP = 2;
		static const Sbecore::uint NCOL = 3;
		static const Sbecore::uint NDISP = 4;

	public:
		StatApp(const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 1, const Sbecore::uint ndisp = 10);

	public:
		Sbecore::uint firstcol;
		Sbecore::uint jnumFirstdisp;
		Sbecore::uint ncol;
		Sbecore::uint ndisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrQryWznmVerVer1NModule)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NTOT = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StatShr(const Sbecore::uint ntot = 0, const Sbecore::uint jnumFirstload = 0, const Sbecore::uint nload = 0);

	public:
		Sbecore::uint ntot;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacQryWznmVerVer1NModule)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JNUM = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StgIac(const Sbecore::uint jnum = 0, const Sbecore::uint jnumFirstload = 1, const Sbecore::uint nload = 100);

	public:
		Sbecore::uint jnum;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

};

#endif

