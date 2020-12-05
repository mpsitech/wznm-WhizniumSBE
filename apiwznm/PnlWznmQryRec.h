/**
	* \file PnlWznmQryRec.h
	* API code for job PnlWznmQryRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMQRYREC_H
#define PNLWZNMQRYREC_H

#include "ApiWznm_blks.h"

#define VecVWznmQryRecDo PnlWznmQryRec::VecVDo

#define ContInfWznmQryRec PnlWznmQryRec::ContInf
#define StatAppWznmQryRec PnlWznmQryRec::StatApp
#define StatShrWznmQryRec PnlWznmQryRec::StatShr
#define TagWznmQryRec PnlWznmQryRec::Tag

#define DpchAppWznmQryRecDo PnlWznmQryRec::DpchAppDo
#define DpchEngWznmQryRecData PnlWznmQryRec::DpchEngData

/**
	* PnlWznmQryRec
	*/
namespace PnlWznmQryRec {
	/**
		* VecVDo (full: VecVWznmQryRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmQryRec)
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
	  * StatApp (full: StatAppWznmQryRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEACLAUSE = 2;
		static const Sbecore::uint INITDONEAORDER = 3;
		static const Sbecore::uint INITDONESUP1NQUERY = 4;
		static const Sbecore::uint INITDONE1NQUERYMOD = 5;
		static const Sbecore::uint INITDONEQRY1NQUERYCOL = 6;
		static const Sbecore::uint INITDONEMNTABLE = 7;
		static const Sbecore::uint INITDONEMNPANEL = 8;
		static const Sbecore::uint INITDONEMNDIALOG = 9;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAClause = false, const bool initdoneAOrder = false, const bool initdoneSup1NQuery = false, const bool initdone1NQuerymod = false, const bool initdoneQry1NQuerycol = false, const bool initdoneMNTable = false, const bool initdoneMNPanel = false, const bool initdoneMNDialog = false);

	public:
		bool initdoneDetail;
		bool initdoneAClause;
		bool initdoneAOrder;
		bool initdoneSup1NQuery;
		bool initdone1NQuerymod;
		bool initdoneQry1NQuerycol;
		bool initdoneMNTable;
		bool initdoneMNPanel;
		bool initdoneMNDialog;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmQryRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFACLAUSE = 3;
		static const Sbecore::uint SCRJREFAORDER = 4;
		static const Sbecore::uint SCRJREFSUP1NQUERY = 5;
		static const Sbecore::uint SCRJREF1NQUERYMOD = 6;
		static const Sbecore::uint SCRJREFQRY1NQUERYCOL = 7;
		static const Sbecore::uint SCRJREFMNTABLE = 8;
		static const Sbecore::uint SCRJREFMNPANEL = 9;
		static const Sbecore::uint SCRJREFMNDIALOG = 10;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 11;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAClause = "", const std::string& scrJrefAOrder = "", const std::string& scrJrefSup1NQuery = "", const std::string& scrJref1NQuerymod = "", const std::string& scrJrefQry1NQuerycol = "", const std::string& scrJrefMNTable = "", const std::string& scrJrefMNPanel = "", const std::string& scrJrefMNDialog = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAClause;
		std::string scrJrefAOrder;
		std::string scrJrefSup1NQuery;
		std::string scrJref1NQuerymod;
		std::string scrJrefQry1NQuerycol;
		std::string scrJrefMNTable;
		std::string scrJrefMNPanel;
		std::string scrJrefMNDialog;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmQryRec)
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
		* DpchAppDo (full: DpchAppWznmQryRecDo)
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
		* DpchEngData (full: DpchEngWznmQryRecData)
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

