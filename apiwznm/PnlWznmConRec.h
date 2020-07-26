/**
	* \file PnlWznmConRec.h
	* API code for job PnlWznmConRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMCONREC_H
#define PNLWZNMCONREC_H

#include "ApiWznm_blks.h"

#define VecVWznmConRecDo PnlWznmConRec::VecVDo

#define ContInfWznmConRec PnlWznmConRec::ContInf
#define StatAppWznmConRec PnlWznmConRec::StatApp
#define StatShrWznmConRec PnlWznmConRec::StatShr
#define TagWznmConRec PnlWznmConRec::Tag

#define DpchAppWznmConRecDo PnlWznmConRec::DpchAppDo
#define DpchEngWznmConRecData PnlWznmConRec::DpchEngData

/**
	* PnlWznmConRec
	*/
namespace PnlWznmConRec {
	/**
		* VecVDo (full: VecVWznmConRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmConRec)
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
	  * StatApp (full: StatAppWznmConRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEAPAR = 2;
		static const Sbecore::uint INITDONESUP1NCONTROL = 3;
		static const Sbecore::uint INITDONEFEDREF1NRTBLOCK = 4;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAPar = false, const bool initdoneSup1NControl = false, const bool initdoneFedRef1NRtblock = false);

	public:
		bool initdoneDetail;
		bool initdoneAPar;
		bool initdoneSup1NControl;
		bool initdoneFedRef1NRtblock;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmConRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFAPAR = 3;
		static const Sbecore::uint SCRJREFSUP1NCONTROL = 4;
		static const Sbecore::uint SCRJREFFEDREF1NRTBLOCK = 5;
		static const Sbecore::uint PNLFEDREF1NRTBLOCKAVAIL = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAPar = "", const std::string& scrJrefSup1NControl = "", const std::string& scrJrefFedRef1NRtblock = "", const bool pnlfedref1nrtblockAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAPar;
		std::string scrJrefSup1NControl;
		std::string scrJrefFedRef1NRtblock;
		bool pnlfedref1nrtblockAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmConRec)
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
		* DpchAppDo (full: DpchAppWznmConRecDo)
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
		* DpchEngData (full: DpchEngWznmConRecData)
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

