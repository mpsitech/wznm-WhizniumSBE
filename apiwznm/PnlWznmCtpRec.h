/**
	* \file PnlWznmCtpRec.h
	* API code for job PnlWznmCtpRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef PNLWZNMCTPREC_H
#define PNLWZNMCTPREC_H

#include "ApiWznm_blks.h"

#define VecVWznmCtpRecDo PnlWznmCtpRec::VecVDo

#define ContInfWznmCtpRec PnlWznmCtpRec::ContInf
#define StatAppWznmCtpRec PnlWznmCtpRec::StatApp
#define StatShrWznmCtpRec PnlWznmCtpRec::StatShr
#define TagWznmCtpRec PnlWznmCtpRec::Tag

#define DpchAppWznmCtpRecDo PnlWznmCtpRec::DpchAppDo
#define DpchEngWznmCtpRecData PnlWznmCtpRec::DpchEngData

/**
	* PnlWznmCtpRec
	*/
namespace PnlWznmCtpRec {
	/**
		* VecVDo (full: VecVWznmCtpRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmCtpRec)
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
	  * StatApp (full: StatAppWznmCtpRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEKPARKEY = 2;
		static const Sbecore::uint INITDONEKKEY = 3;
		static const Sbecore::uint INITDONEAPAR = 4;
		static const Sbecore::uint INITDONE1NTAG = 5;
		static const Sbecore::uint INITDONETPL1NCAPABILITY = 6;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKParKey = false, const bool initdoneKKey = false, const bool initdoneAPar = false, const bool initdone1NTag = false, const bool initdoneTpl1NCapability = false);

	public:
		bool initdoneDetail;
		bool initdoneKParKey;
		bool initdoneKKey;
		bool initdoneAPar;
		bool initdone1NTag;
		bool initdoneTpl1NCapability;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmCtpRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFKPARKEY = 3;
		static const Sbecore::uint SCRJREFKKEY = 4;
		static const Sbecore::uint SCRJREFAPAR = 5;
		static const Sbecore::uint SCRJREF1NTAG = 6;
		static const Sbecore::uint SCRJREFTPL1NCAPABILITY = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefKParKey = "", const std::string& scrJrefKKey = "", const std::string& scrJrefAPar = "", const std::string& scrJref1NTag = "", const std::string& scrJrefTpl1NCapability = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefKParKey;
		std::string scrJrefKKey;
		std::string scrJrefAPar;
		std::string scrJref1NTag;
		std::string scrJrefTpl1NCapability;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmCtpRec)
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
		* DpchAppDo (full: DpchAppWznmCtpRecDo)
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
		* DpchEngData (full: DpchEngWznmCtpRecData)
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

