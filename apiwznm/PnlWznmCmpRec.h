/**
	* \file PnlWznmCmpRec.h
	* API code for job PnlWznmCmpRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMCMPREC_H
#define PNLWZNMCMPREC_H

#include "ApiWznm_blks.h"

#define VecVWznmCmpRecDo PnlWznmCmpRec::VecVDo

#define ContInfWznmCmpRec PnlWznmCmpRec::ContInf
#define StatAppWznmCmpRec PnlWznmCmpRec::StatApp
#define StatShrWznmCmpRec PnlWznmCmpRec::StatShr
#define TagWznmCmpRec PnlWznmCmpRec::Tag

#define DpchAppWznmCmpRecDo PnlWznmCmpRec::DpchAppDo
#define DpchEngWznmCmpRecData PnlWznmCmpRec::DpchEngData

/**
	* PnlWznmCmpRec
	*/
namespace PnlWznmCmpRec {
	/**
		* VecVDo (full: VecVWznmCmpRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmCmpRec)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmCmpRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONE1NRELEASE = 2;
		static const Sbecore::uint INITDONEMNOPPACK = 3;
		static const Sbecore::uint INITDONEMNLIBRARY = 4;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NRelease = false, const bool initdoneMNOppack = false, const bool initdoneMNLibrary = false);

	public:
		bool initdoneDetail;
		bool initdone1NRelease;
		bool initdoneMNOppack;
		bool initdoneMNLibrary;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmCmpRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREF1NRELEASE = 3;
		static const Sbecore::uint SCRJREFMNOPPACK = 4;
		static const Sbecore::uint PNLMNOPPACKAVAIL = 5;
		static const Sbecore::uint SCRJREFMNLIBRARY = 6;
		static const Sbecore::uint PNLMNLIBRARYAVAIL = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJref1NRelease = "", const std::string& scrJrefMNOppack = "", const bool pnlmnoppackAvail = false, const std::string& scrJrefMNLibrary = "", const bool pnlmnlibraryAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJref1NRelease;
		std::string scrJrefMNOppack;
		bool pnlmnoppackAvail;
		std::string scrJrefMNLibrary;
		bool pnlmnlibraryAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmCmpRec)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;

	public:
		Tag(const std::string& Cpt = "");

	public:
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmCmpRecDo)
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
		* DpchEngData (full: DpchEngWznmCmpRecData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
