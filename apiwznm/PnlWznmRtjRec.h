/**
	* \file PnlWznmRtjRec.h
	* API code for job PnlWznmRtjRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMRTJREC_H
#define PNLWZNMRTJREC_H

#include "ApiWznm_blks.h"

#define VecVWznmRtjRecDo PnlWznmRtjRec::VecVDo

#define ContInfWznmRtjRec PnlWznmRtjRec::ContInf
#define StatAppWznmRtjRec PnlWznmRtjRec::StatApp
#define StatShrWznmRtjRec PnlWznmRtjRec::StatShr
#define TagWznmRtjRec PnlWznmRtjRec::Tag

#define DpchAppWznmRtjRecDo PnlWznmRtjRec::DpchAppDo
#define DpchEngWznmRtjRecData PnlWznmRtjRec::DpchEngData

/**
	* PnlWznmRtjRec
	*/
namespace PnlWznmRtjRec {
	/**
		* VecVDo (full: VecVWznmRtjRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmRtjRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

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
	  * StatApp (full: StatAppWznmRtjRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONE1NRTBLOCK = 2;
		static const Sbecore::uint INITDONE1NRTDPCH = 3;
		static const Sbecore::uint INITDONESUP1NRTJOB = 4;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NRtblock = false, const bool initdone1NRtdpch = false, const bool initdoneSup1NRtjob = false);

	public:
		bool initdoneDetail;
		bool initdone1NRtblock;
		bool initdone1NRtdpch;
		bool initdoneSup1NRtjob;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmRtjRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREF1NRTBLOCK = 3;
		static const Sbecore::uint SCRJREF1NRTDPCH = 4;
		static const Sbecore::uint SCRJREFSUP1NRTJOB = 5;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 6;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJref1NRtblock = "", const std::string& scrJref1NRtdpch = "", const std::string& scrJrefSup1NRtjob = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJref1NRtblock;
		std::string scrJref1NRtdpch;
		std::string scrJrefSup1NRtjob;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmRtjRec)
	  */
	class Tag : public Sbecore::Xmlio::Block {

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
		* DpchAppDo (full: DpchAppWznmRtjRecDo)
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
		* DpchEngData (full: DpchEngWznmRtjRecData)
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
