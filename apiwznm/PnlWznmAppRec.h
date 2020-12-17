/**
	* \file PnlWznmAppRec.h
	* API code for job PnlWznmAppRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMAPPREC_H
#define PNLWZNMAPPREC_H

#include "ApiWznm_blks.h"

#define VecVWznmAppRecDo PnlWznmAppRec::VecVDo

#define ContInfWznmAppRec PnlWznmAppRec::ContInf
#define StatAppWznmAppRec PnlWznmAppRec::StatApp
#define StatShrWznmAppRec PnlWznmAppRec::StatShr
#define TagWznmAppRec PnlWznmAppRec::Tag

#define DpchAppWznmAppRecDo PnlWznmAppRec::DpchAppDo
#define DpchEngWznmAppRecData PnlWznmAppRec::DpchEngData

/**
	* PnlWznmAppRec
	*/
namespace PnlWznmAppRec {
	/**
		* VecVDo (full: VecVWznmAppRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmAppRec)
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
	  * StatApp (full: StatAppWznmAppRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONE1NRTJOB = 2;
		static const Sbecore::uint INITDONEAPP1NSEQUENCE = 3;
		static const Sbecore::uint INITDONE1NEVENT = 4;
		static const Sbecore::uint INITDONEREF1NFILE = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NRtjob = false, const bool initdoneApp1NSequence = false, const bool initdone1NEvent = false, const bool initdoneRef1NFile = false);

	public:
		bool initdoneDetail;
		bool initdone1NRtjob;
		bool initdoneApp1NSequence;
		bool initdone1NEvent;
		bool initdoneRef1NFile;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmAppRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREF1NRTJOB = 3;
		static const Sbecore::uint SCRJREFAPP1NSEQUENCE = 4;
		static const Sbecore::uint SCRJREF1NEVENT = 5;
		static const Sbecore::uint SCRJREFREF1NFILE = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJref1NRtjob = "", const std::string& scrJrefApp1NSequence = "", const std::string& scrJref1NEvent = "", const std::string& scrJrefRef1NFile = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJref1NRtjob;
		std::string scrJrefApp1NSequence;
		std::string scrJref1NEvent;
		std::string scrJrefRef1NFile;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmAppRec)
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
		* DpchAppDo (full: DpchAppWznmAppRecDo)
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
		* DpchEngData (full: DpchEngWznmAppRecData)
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
