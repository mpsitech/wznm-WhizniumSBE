/**
	* \file PnlWznmStbRec.h
	* API code for job PnlWznmStbRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMSTBREC_H
#define PNLWZNMSTBREC_H

#include "ApiWznm_blks.h"

#define VecVWznmStbRecDo PnlWznmStbRec::VecVDo

#define ContInfWznmStbRec PnlWznmStbRec::ContInf
#define StatAppWznmStbRec PnlWznmStbRec::StatApp
#define StatShrWznmStbRec PnlWznmStbRec::StatShr
#define TagWznmStbRec PnlWznmStbRec::Tag

#define DpchAppWznmStbRecDo PnlWznmStbRec::DpchAppDo
#define DpchEngWznmStbRecData PnlWznmStbRec::DpchEngData

/**
	* PnlWznmStbRec
	*/
namespace PnlWznmStbRec {
	/**
		* VecVDo (full: VecVWznmStbRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmStbRec)
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
	  * StatApp (full: StatAppWznmStbRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONESUPMNSTUB = 2;
		static const Sbecore::uint INITDONEMNCALL = 3;
		static const Sbecore::uint INITDONEMNSQUAWK = 4;
		static const Sbecore::uint INITDONESUBMNSTUB = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneSupMNStub = false, const bool initdoneMNCall = false, const bool initdoneMNSquawk = false, const bool initdoneSubMNStub = false);

	public:
		bool initdoneDetail;
		bool initdoneSupMNStub;
		bool initdoneMNCall;
		bool initdoneMNSquawk;
		bool initdoneSubMNStub;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmStbRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFSUPMNSTUB = 3;
		static const Sbecore::uint SCRJREFMNCALL = 4;
		static const Sbecore::uint SCRJREFMNSQUAWK = 5;
		static const Sbecore::uint SCRJREFSUBMNSTUB = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefSupMNStub = "", const std::string& scrJrefMNCall = "", const std::string& scrJrefMNSquawk = "", const std::string& scrJrefSubMNStub = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefSupMNStub;
		std::string scrJrefMNCall;
		std::string scrJrefMNSquawk;
		std::string scrJrefSubMNStub;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmStbRec)
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
		* DpchAppDo (full: DpchAppWznmStbRecDo)
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
		* DpchEngData (full: DpchEngWznmStbRecData)
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
