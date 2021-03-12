/**
	* \file PnlWznmLibRec.h
	* API code for job PnlWznmLibRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMLIBREC_H
#define PNLWZNMLIBREC_H

#include "ApiWznm_blks.h"

#define VecVWznmLibRecDo PnlWznmLibRec::VecVDo

#define ContInfWznmLibRec PnlWznmLibRec::ContInf
#define StatAppWznmLibRec PnlWznmLibRec::StatApp
#define StatShrWznmLibRec PnlWznmLibRec::StatShr
#define TagWznmLibRec PnlWznmLibRec::Tag

#define DpchAppWznmLibRecDo PnlWznmLibRec::DpchAppDo
#define DpchEngWznmLibRecData PnlWznmLibRec::DpchEngData

/**
	* PnlWznmLibRec
	*/
namespace PnlWznmLibRec {
	/**
		* VecVDo (full: VecVWznmLibRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmLibRec)
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
	  * StatApp (full: StatAppWznmLibRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEAPKGLIST = 2;
		static const Sbecore::uint INITDONEAMAKEFILE = 3;
		static const Sbecore::uint INITDONEREF1NFILE = 4;
		static const Sbecore::uint INITDONEMNOPPACK = 5;
		static const Sbecore::uint INITDONEMNCOMPONENT = 6;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAPkglist = false, const bool initdoneAMakefile = false, const bool initdoneRef1NFile = false, const bool initdoneMNOppack = false, const bool initdoneMNComponent = false);

	public:
		bool initdoneDetail;
		bool initdoneAPkglist;
		bool initdoneAMakefile;
		bool initdoneRef1NFile;
		bool initdoneMNOppack;
		bool initdoneMNComponent;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmLibRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFAPKGLIST = 3;
		static const Sbecore::uint SCRJREFAMAKEFILE = 4;
		static const Sbecore::uint SCRJREFREF1NFILE = 5;
		static const Sbecore::uint SCRJREFMNOPPACK = 6;
		static const Sbecore::uint SCRJREFMNCOMPONENT = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAPkglist = "", const std::string& scrJrefAMakefile = "", const std::string& scrJrefRef1NFile = "", const std::string& scrJrefMNOppack = "", const std::string& scrJrefMNComponent = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAPkglist;
		std::string scrJrefAMakefile;
		std::string scrJrefRef1NFile;
		std::string scrJrefMNOppack;
		std::string scrJrefMNComponent;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmLibRec)
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
		* DpchAppDo (full: DpchAppWznmLibRecDo)
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
		* DpchEngData (full: DpchEngWznmLibRecData)
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
