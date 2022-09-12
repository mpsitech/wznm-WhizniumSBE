/**
	* \file PnlWznmVerRec.h
	* API code for job PnlWznmVerRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMVERREC_H
#define PNLWZNMVERREC_H

#include "ApiWznm_blks.h"

#define VecVWznmVerRecDo PnlWznmVerRec::VecVDo

#define ContInfWznmVerRec PnlWznmVerRec::ContInf
#define StatAppWznmVerRec PnlWznmVerRec::StatApp
#define StatShrWznmVerRec PnlWznmVerRec::StatShr
#define TagWznmVerRec PnlWznmVerRec::Tag

#define DpchAppWznmVerRecDo PnlWznmVerRec::DpchAppDo
#define DpchEngWznmVerRecData PnlWznmVerRec::DpchEngData

/**
	* PnlWznmVerRec
	*/
namespace PnlWznmVerRec {
	/**
		* VecVDo (full: VecVWznmVerRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmVerRec)
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
	  * StatApp (full: StatAppWznmVerRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEVER1NERROR = 2;
		static const Sbecore::uint INITDONEVER1NAPP = 3;
		static const Sbecore::uint INITDONE1NCAPABILITY = 4;
		static const Sbecore::uint INITDONE1NVECTOR = 5;
		static const Sbecore::uint INITDONE1NTABLE = 6;
		static const Sbecore::uint INITDONE1NRELATION = 7;
		static const Sbecore::uint INITDONE1NQUERY = 8;
		static const Sbecore::uint INITDONE1NPRESET = 9;
		static const Sbecore::uint INITDONEVER1NMODULE = 10;
		static const Sbecore::uint INITDONE1NOPPACK = 11;
		static const Sbecore::uint INITDONE1NJOB = 12;
		static const Sbecore::uint INITDONE1NIMPEXPCPLX = 13;
		static const Sbecore::uint INITDONE1NCALL = 14;
		static const Sbecore::uint INITDONE1NCOMPONENT = 15;
		static const Sbecore::uint INITDONEBVR1NVERSION = 16;
		static const Sbecore::uint INITDONE1NBLOCK = 17;
		static const Sbecore::uint INITDONEREF1NFILE = 18;
		static const Sbecore::uint INITDONEMNLOCALE = 19;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneVer1NError = false, const bool initdoneVer1NApp = false, const bool initdone1NCapability = false, const bool initdone1NVector = false, const bool initdone1NTable = false, const bool initdone1NRelation = false, const bool initdone1NQuery = false, const bool initdone1NPreset = false, const bool initdoneVer1NModule = false, const bool initdone1NOppack = false, const bool initdone1NJob = false, const bool initdone1NImpexpcplx = false, const bool initdone1NCall = false, const bool initdone1NComponent = false, const bool initdoneBvr1NVersion = false, const bool initdone1NBlock = false, const bool initdoneRef1NFile = false, const bool initdoneMNLocale = false);

	public:
		bool initdoneDetail;
		bool initdoneVer1NError;
		bool initdoneVer1NApp;
		bool initdone1NCapability;
		bool initdone1NVector;
		bool initdone1NTable;
		bool initdone1NRelation;
		bool initdone1NQuery;
		bool initdone1NPreset;
		bool initdoneVer1NModule;
		bool initdone1NOppack;
		bool initdone1NJob;
		bool initdone1NImpexpcplx;
		bool initdone1NCall;
		bool initdone1NComponent;
		bool initdoneBvr1NVersion;
		bool initdone1NBlock;
		bool initdoneRef1NFile;
		bool initdoneMNLocale;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmVerRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFVER1NERROR = 3;
		static const Sbecore::uint SCRJREFVER1NAPP = 4;
		static const Sbecore::uint SCRJREF1NCAPABILITY = 5;
		static const Sbecore::uint SCRJREF1NVECTOR = 6;
		static const Sbecore::uint SCRJREF1NTABLE = 7;
		static const Sbecore::uint SCRJREF1NRELATION = 8;
		static const Sbecore::uint SCRJREF1NQUERY = 9;
		static const Sbecore::uint SCRJREF1NPRESET = 10;
		static const Sbecore::uint SCRJREFVER1NMODULE = 11;
		static const Sbecore::uint SCRJREF1NOPPACK = 12;
		static const Sbecore::uint SCRJREF1NJOB = 13;
		static const Sbecore::uint SCRJREF1NIMPEXPCPLX = 14;
		static const Sbecore::uint SCRJREF1NCALL = 15;
		static const Sbecore::uint SCRJREF1NCOMPONENT = 16;
		static const Sbecore::uint SCRJREFBVR1NVERSION = 17;
		static const Sbecore::uint SCRJREF1NBLOCK = 18;
		static const Sbecore::uint SCRJREFREF1NFILE = 19;
		static const Sbecore::uint SCRJREFMNLOCALE = 20;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 21;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefVer1NError = "", const std::string& scrJrefVer1NApp = "", const std::string& scrJref1NCapability = "", const std::string& scrJref1NVector = "", const std::string& scrJref1NTable = "", const std::string& scrJref1NRelation = "", const std::string& scrJref1NQuery = "", const std::string& scrJref1NPreset = "", const std::string& scrJrefVer1NModule = "", const std::string& scrJref1NOppack = "", const std::string& scrJref1NJob = "", const std::string& scrJref1NImpexpcplx = "", const std::string& scrJref1NCall = "", const std::string& scrJref1NComponent = "", const std::string& scrJrefBvr1NVersion = "", const std::string& scrJref1NBlock = "", const std::string& scrJrefRef1NFile = "", const std::string& scrJrefMNLocale = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefVer1NError;
		std::string scrJrefVer1NApp;
		std::string scrJref1NCapability;
		std::string scrJref1NVector;
		std::string scrJref1NTable;
		std::string scrJref1NRelation;
		std::string scrJref1NQuery;
		std::string scrJref1NPreset;
		std::string scrJrefVer1NModule;
		std::string scrJref1NOppack;
		std::string scrJref1NJob;
		std::string scrJref1NImpexpcplx;
		std::string scrJref1NCall;
		std::string scrJref1NComponent;
		std::string scrJrefBvr1NVersion;
		std::string scrJref1NBlock;
		std::string scrJrefRef1NFile;
		std::string scrJrefMNLocale;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmVerRec)
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
		* DpchAppDo (full: DpchAppWznmVerRecDo)
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
		* DpchEngData (full: DpchEngWznmVerRecData)
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
