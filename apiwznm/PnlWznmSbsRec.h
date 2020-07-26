/**
	* \file PnlWznmSbsRec.h
	* API code for job PnlWznmSbsRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMSBSREC_H
#define PNLWZNMSBSREC_H

#include "ApiWznm_blks.h"

#define VecVWznmSbsRecDo PnlWznmSbsRec::VecVDo

#define ContInfWznmSbsRec PnlWznmSbsRec::ContInf
#define StatAppWznmSbsRec PnlWznmSbsRec::StatApp
#define StatShrWznmSbsRec PnlWznmSbsRec::StatShr
#define TagWznmSbsRec PnlWznmSbsRec::Tag

#define DpchAppWznmSbsRecDo PnlWznmSbsRec::DpchAppDo
#define DpchEngWznmSbsRecData PnlWznmSbsRec::DpchEngData

/**
	* PnlWznmSbsRec
	*/
namespace PnlWznmSbsRec {
	/**
		* VecVDo (full: VecVWznmSbsRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmSbsRec)
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
	  * StatApp (full: StatAppWznmSbsRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEATITLE = 2;
		static const Sbecore::uint INITDONE1NSTUB = 3;
		static const Sbecore::uint INITDONE1NTABLECOL = 4;
		static const Sbecore::uint INITDONETOS1NRELATION = 5;
		static const Sbecore::uint INITDONEFRS1NRELATION = 6;
		static const Sbecore::uint INITDONEPST1NQUERYMOD = 7;
		static const Sbecore::uint INITDONEASBMNSUBSET = 8;
		static const Sbecore::uint INITDONEBSBMNSUBSET = 9;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneATitle = false, const bool initdone1NStub = false, const bool initdone1NTablecol = false, const bool initdoneTos1NRelation = false, const bool initdoneFrs1NRelation = false, const bool initdonePst1NQuerymod = false, const bool initdoneAsbMNSubset = false, const bool initdoneBsbMNSubset = false);

	public:
		bool initdoneDetail;
		bool initdoneATitle;
		bool initdone1NStub;
		bool initdone1NTablecol;
		bool initdoneTos1NRelation;
		bool initdoneFrs1NRelation;
		bool initdonePst1NQuerymod;
		bool initdoneAsbMNSubset;
		bool initdoneBsbMNSubset;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmSbsRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFATITLE = 3;
		static const Sbecore::uint SCRJREF1NSTUB = 4;
		static const Sbecore::uint SCRJREF1NTABLECOL = 5;
		static const Sbecore::uint SCRJREFTOS1NRELATION = 6;
		static const Sbecore::uint SCRJREFFRS1NRELATION = 7;
		static const Sbecore::uint SCRJREFPST1NQUERYMOD = 8;
		static const Sbecore::uint PNLPST1NQUERYMODAVAIL = 9;
		static const Sbecore::uint SCRJREFASBMNSUBSET = 10;
		static const Sbecore::uint SCRJREFBSBMNSUBSET = 11;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 12;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefATitle = "", const std::string& scrJref1NStub = "", const std::string& scrJref1NTablecol = "", const std::string& scrJrefTos1NRelation = "", const std::string& scrJrefFrs1NRelation = "", const std::string& scrJrefPst1NQuerymod = "", const bool pnlpst1nquerymodAvail = false, const std::string& scrJrefAsbMNSubset = "", const std::string& scrJrefBsbMNSubset = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefATitle;
		std::string scrJref1NStub;
		std::string scrJref1NTablecol;
		std::string scrJrefTos1NRelation;
		std::string scrJrefFrs1NRelation;
		std::string scrJrefPst1NQuerymod;
		bool pnlpst1nquerymodAvail;
		std::string scrJrefAsbMNSubset;
		std::string scrJrefBsbMNSubset;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmSbsRec)
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
		* DpchAppDo (full: DpchAppWznmSbsRecDo)
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
		* DpchEngData (full: DpchEngWznmSbsRecData)
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

