/**
	* \file RootWznm.h
	* API code for job RootWznm (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef ROOTWZNM_H
#define ROOTWZNM_H

#include "ApiWznm_blks.h"

#define VecVRootWznmSge RootWznm::VecVSge

#define DpchAppRootWznmLogin RootWznm::DpchAppLogin
#define DpchEngRootWznmData RootWznm::DpchEngData

/**
	* RootWznm
	*/
namespace RootWznm {
	/**
		* VecVSge (full: VecVRootWznmSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint SYNC = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* DpchAppLogin (full: DpchAppRootWznmLogin)
		*/
	class DpchAppLogin : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint USERNAME = 2;
		static const Sbecore::uint PASSWORD = 3;
		static const Sbecore::uint M2MNOTREG = 4;
		static const Sbecore::uint CHKSUSPSESS = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchAppLogin(const std::string& scrJref = "", const std::string& username = "", const std::string& password = "", const bool m2mNotReg = false, const bool chksuspsess = false, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::string username;
		std::string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngRootWznmData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint FEEDFENSSPS = 2;

	public:
		DpchEngData();

	public:
		Sbecore::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
