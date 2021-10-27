/**
	* \file PnlWznmJobRec.h
	* API code for job PnlWznmJobRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMJOBREC_H
#define PNLWZNMJOBREC_H

#include "ApiWznm_blks.h"

#define VecVWznmJobRecDo PnlWznmJobRec::VecVDo

#define ContInfWznmJobRec PnlWznmJobRec::ContInf
#define StatAppWznmJobRec PnlWznmJobRec::StatApp
#define StatShrWznmJobRec PnlWznmJobRec::StatShr
#define TagWznmJobRec PnlWznmJobRec::Tag

#define DpchAppWznmJobRecDo PnlWznmJobRec::DpchAppDo
#define DpchEngWznmJobRecData PnlWznmJobRec::DpchEngData

/**
	* PnlWznmJobRec
	*/
namespace PnlWznmJobRec {
	/**
		* VecVDo (full: VecVWznmJobRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmJobRec)
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
	  * StatApp (full: StatAppWznmJobRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEAVAR = 2;
		static const Sbecore::uint INITDONEACMD = 3;
		static const Sbecore::uint INITDONE1NRTJOB = 4;
		static const Sbecore::uint INITDONE1NMETHOD = 5;
		static const Sbecore::uint INITDONEJOB1NSTAGE = 6;
		static const Sbecore::uint INITDONE1NSENSITIVITY = 7;
		static const Sbecore::uint INITDONEHK1NVECTOR = 8;
		static const Sbecore::uint INITDONEREF1NBLOCK = 9;
		static const Sbecore::uint INITDONEMNOP = 10;
		static const Sbecore::uint INITDONEMNOPPACK = 11;
		static const Sbecore::uint INITDONESUPMNJOB = 12;
		static const Sbecore::uint INITDONESUBMNJOB = 13;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAVar = false, const bool initdoneACmd = false, const bool initdone1NRtjob = false, const bool initdone1NMethod = false, const bool initdoneJob1NStage = false, const bool initdone1NSensitivity = false, const bool initdoneHk1NVector = false, const bool initdoneRef1NBlock = false, const bool initdoneMNOp = false, const bool initdoneMNOppack = false, const bool initdoneSupMNJob = false, const bool initdoneSubMNJob = false);

	public:
		bool initdoneDetail;
		bool initdoneAVar;
		bool initdoneACmd;
		bool initdone1NRtjob;
		bool initdone1NMethod;
		bool initdoneJob1NStage;
		bool initdone1NSensitivity;
		bool initdoneHk1NVector;
		bool initdoneRef1NBlock;
		bool initdoneMNOp;
		bool initdoneMNOppack;
		bool initdoneSupMNJob;
		bool initdoneSubMNJob;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmJobRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFAVAR = 3;
		static const Sbecore::uint SCRJREFACMD = 4;
		static const Sbecore::uint SCRJREF1NRTJOB = 5;
		static const Sbecore::uint SCRJREF1NMETHOD = 6;
		static const Sbecore::uint SCRJREFJOB1NSTAGE = 7;
		static const Sbecore::uint SCRJREF1NSENSITIVITY = 8;
		static const Sbecore::uint SCRJREFHK1NVECTOR = 9;
		static const Sbecore::uint SCRJREFREF1NBLOCK = 10;
		static const Sbecore::uint SCRJREFMNOP = 11;
		static const Sbecore::uint SCRJREFMNOPPACK = 12;
		static const Sbecore::uint SCRJREFSUPMNJOB = 13;
		static const Sbecore::uint SCRJREFSUBMNJOB = 14;
		static const Sbecore::uint PNLSUBMNJOBAVAIL = 15;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 16;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAVar = "", const std::string& scrJrefACmd = "", const std::string& scrJref1NRtjob = "", const std::string& scrJref1NMethod = "", const std::string& scrJrefJob1NStage = "", const std::string& scrJref1NSensitivity = "", const std::string& scrJrefHk1NVector = "", const std::string& scrJrefRef1NBlock = "", const std::string& scrJrefMNOp = "", const std::string& scrJrefMNOppack = "", const std::string& scrJrefSupMNJob = "", const std::string& scrJrefSubMNJob = "", const bool pnlsubmnjobAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAVar;
		std::string scrJrefACmd;
		std::string scrJref1NRtjob;
		std::string scrJref1NMethod;
		std::string scrJrefJob1NStage;
		std::string scrJref1NSensitivity;
		std::string scrJrefHk1NVector;
		std::string scrJrefRef1NBlock;
		std::string scrJrefMNOp;
		std::string scrJrefMNOppack;
		std::string scrJrefSupMNJob;
		std::string scrJrefSubMNJob;
		bool pnlsubmnjobAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmJobRec)
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
		* DpchAppDo (full: DpchAppWznmJobRecDo)
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
		* DpchEngData (full: DpchEngWznmJobRecData)
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
