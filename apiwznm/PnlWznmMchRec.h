/**
	* \file PnlWznmMchRec.h
	* API code for job PnlWznmMchRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMMCHREC_H
#define PNLWZNMMCHREC_H

#include "ApiWznm_blks.h"

#define VecVWznmMchRecDo PnlWznmMchRec::VecVDo

#define ContInfWznmMchRec PnlWznmMchRec::ContInf
#define StatAppWznmMchRec PnlWznmMchRec::StatApp
#define StatShrWznmMchRec PnlWznmMchRec::StatShr
#define TagWznmMchRec PnlWznmMchRec::Tag

#define DpchAppWznmMchRecDo PnlWznmMchRec::DpchAppDo
#define DpchEngWznmMchRecData PnlWznmMchRec::DpchEngData

/**
	* PnlWznmMchRec
	*/
namespace PnlWznmMchRec {
	/**
		* VecVDo (full: VecVWznmMchRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmMchRec)
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
	  * StatApp (full: StatAppWznmMchRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEAPAR = 2;
		static const Sbecore::uint INITDONEAMAKEFILE = 3;
		static const Sbecore::uint INITDONE1NRELEASE = 4;
		static const Sbecore::uint INITDONESUP1NMACHINE = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAPar = false, const bool initdoneAMakefile = false, const bool initdone1NRelease = false, const bool initdoneSup1NMachine = false);

	public:
		bool initdoneDetail;
		bool initdoneAPar;
		bool initdoneAMakefile;
		bool initdone1NRelease;
		bool initdoneSup1NMachine;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmMchRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFAPAR = 3;
		static const Sbecore::uint SCRJREFAMAKEFILE = 4;
		static const Sbecore::uint SCRJREF1NRELEASE = 5;
		static const Sbecore::uint SCRJREFSUP1NMACHINE = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAPar = "", const std::string& scrJrefAMakefile = "", const std::string& scrJref1NRelease = "", const std::string& scrJrefSup1NMachine = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAPar;
		std::string scrJrefAMakefile;
		std::string scrJref1NRelease;
		std::string scrJrefSup1NMachine;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmMchRec)
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
		* DpchAppDo (full: DpchAppWznmMchRecDo)
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
		* DpchEngData (full: DpchEngWznmMchRecData)
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
