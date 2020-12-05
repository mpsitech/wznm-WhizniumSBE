/**
	* \file PnlWznmTcoRec.h
	* API code for job PnlWznmTcoRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMTCOREC_H
#define PNLWZNMTCOREC_H

#include "ApiWznm_blks.h"

#define VecVWznmTcoRecDo PnlWznmTcoRec::VecVDo

#define ContInfWznmTcoRec PnlWznmTcoRec::ContInf
#define StatAppWznmTcoRec PnlWznmTcoRec::StatApp
#define StatShrWznmTcoRec PnlWznmTcoRec::StatShr
#define TagWznmTcoRec PnlWznmTcoRec::Tag

#define DpchAppWznmTcoRecDo PnlWznmTcoRec::DpchAppDo
#define DpchEngWznmTcoRecData PnlWznmTcoRec::DpchEngData

/**
	* PnlWznmTcoRec
	*/
namespace PnlWznmTcoRec {
	/**
		* VecVDo (full: VecVWznmTcoRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmTcoRec)
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
	  * StatApp (full: StatAppWznmTcoRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEATITLE = 2;
		static const Sbecore::uint INITDONE1NQUERYCOL = 3;
		static const Sbecore::uint INITDONE1NIMPEXPCOL = 4;
		static const Sbecore::uint INITDONEREF1NCONTROL = 5;
		static const Sbecore::uint INITDONEREF1NQUERYMOD = 6;
		static const Sbecore::uint INITDONE1NCHECK = 7;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneATitle = false, const bool initdone1NQuerycol = false, const bool initdone1NImpexpcol = false, const bool initdoneRef1NControl = false, const bool initdoneRef1NQuerymod = false, const bool initdone1NCheck = false);

	public:
		bool initdoneDetail;
		bool initdoneATitle;
		bool initdone1NQuerycol;
		bool initdone1NImpexpcol;
		bool initdoneRef1NControl;
		bool initdoneRef1NQuerymod;
		bool initdone1NCheck;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmTcoRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFATITLE = 3;
		static const Sbecore::uint PNLATITLEAVAIL = 4;
		static const Sbecore::uint SCRJREF1NQUERYCOL = 5;
		static const Sbecore::uint PNL1NQUERYCOLAVAIL = 6;
		static const Sbecore::uint SCRJREF1NIMPEXPCOL = 7;
		static const Sbecore::uint PNL1NIMPEXPCOLAVAIL = 8;
		static const Sbecore::uint SCRJREFREF1NCONTROL = 9;
		static const Sbecore::uint PNLREF1NCONTROLAVAIL = 10;
		static const Sbecore::uint SCRJREFREF1NQUERYMOD = 11;
		static const Sbecore::uint PNLREF1NQUERYMODAVAIL = 12;
		static const Sbecore::uint SCRJREF1NCHECK = 13;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 14;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefATitle = "", const bool pnlatitleAvail = false, const std::string& scrJref1NQuerycol = "", const bool pnl1nquerycolAvail = false, const std::string& scrJref1NImpexpcol = "", const bool pnl1nimpexpcolAvail = false, const std::string& scrJrefRef1NControl = "", const bool pnlref1ncontrolAvail = false, const std::string& scrJrefRef1NQuerymod = "", const bool pnlref1nquerymodAvail = false, const std::string& scrJref1NCheck = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefATitle;
		bool pnlatitleAvail;
		std::string scrJref1NQuerycol;
		bool pnl1nquerycolAvail;
		std::string scrJref1NImpexpcol;
		bool pnl1nimpexpcolAvail;
		std::string scrJrefRef1NControl;
		bool pnlref1ncontrolAvail;
		std::string scrJrefRef1NQuerymod;
		bool pnlref1nquerymodAvail;
		std::string scrJref1NCheck;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmTcoRec)
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
		* DpchAppDo (full: DpchAppWznmTcoRecDo)
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
		* DpchEngData (full: DpchEngWznmTcoRecData)
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

