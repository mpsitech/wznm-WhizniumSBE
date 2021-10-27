/**
	* \file PnlWznmOpkRec.h
	* API code for job PnlWznmOpkRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMOPKREC_H
#define PNLWZNMOPKREC_H

#include "ApiWznm_blks.h"

#define VecVWznmOpkRecDo PnlWznmOpkRec::VecVDo

#define ContInfWznmOpkRec PnlWznmOpkRec::ContInf
#define StatAppWznmOpkRec PnlWznmOpkRec::StatApp
#define StatShrWznmOpkRec PnlWznmOpkRec::StatShr
#define TagWznmOpkRec PnlWznmOpkRec::Tag

#define DpchAppWznmOpkRecDo PnlWznmOpkRec::DpchAppDo
#define DpchEngWznmOpkRecData PnlWznmOpkRec::DpchEngData

/**
	* PnlWznmOpkRec
	*/
namespace PnlWznmOpkRec {
	/**
		* VecVDo (full: VecVWznmOpkRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmOpkRec)
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
	  * StatApp (full: StatAppWznmOpkRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEAINVARG = 2;
		static const Sbecore::uint INITDONEARETVAL = 3;
		static const Sbecore::uint INITDONE1NOP = 4;
		static const Sbecore::uint INITDONEREF1NBLOCK = 5;
		static const Sbecore::uint INITDONEMNJOB = 6;
		static const Sbecore::uint INITDONEMNLIBRARY = 7;
		static const Sbecore::uint INITDONEMNCOMPONENT = 8;
		static const Sbecore::uint INITDONESQKMNSTUB = 9;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAInvarg = false, const bool initdoneARetval = false, const bool initdone1NOp = false, const bool initdoneRef1NBlock = false, const bool initdoneMNJob = false, const bool initdoneMNLibrary = false, const bool initdoneMNComponent = false, const bool initdoneSqkMNStub = false);

	public:
		bool initdoneDetail;
		bool initdoneAInvarg;
		bool initdoneARetval;
		bool initdone1NOp;
		bool initdoneRef1NBlock;
		bool initdoneMNJob;
		bool initdoneMNLibrary;
		bool initdoneMNComponent;
		bool initdoneSqkMNStub;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmOpkRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFAINVARG = 3;
		static const Sbecore::uint SCRJREFARETVAL = 4;
		static const Sbecore::uint SCRJREF1NOP = 5;
		static const Sbecore::uint SCRJREFREF1NBLOCK = 6;
		static const Sbecore::uint SCRJREFMNJOB = 7;
		static const Sbecore::uint SCRJREFMNLIBRARY = 8;
		static const Sbecore::uint SCRJREFMNCOMPONENT = 9;
		static const Sbecore::uint SCRJREFSQKMNSTUB = 10;
		static const Sbecore::uint PNLSQKMNSTUBAVAIL = 11;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 12;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAInvarg = "", const std::string& scrJrefARetval = "", const std::string& scrJref1NOp = "", const std::string& scrJrefRef1NBlock = "", const std::string& scrJrefMNJob = "", const std::string& scrJrefMNLibrary = "", const std::string& scrJrefMNComponent = "", const std::string& scrJrefSqkMNStub = "", const bool pnlsqkmnstubAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAInvarg;
		std::string scrJrefARetval;
		std::string scrJref1NOp;
		std::string scrJrefRef1NBlock;
		std::string scrJrefMNJob;
		std::string scrJrefMNLibrary;
		std::string scrJrefMNComponent;
		std::string scrJrefSqkMNStub;
		bool pnlsqkmnstubAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmOpkRec)
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
		* DpchAppDo (full: DpchAppWznmOpkRecDo)
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
		* DpchEngData (full: DpchEngWznmOpkRecData)
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
