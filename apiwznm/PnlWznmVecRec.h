/**
	* \file PnlWznmVecRec.h
	* API code for job PnlWznmVecRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMVECREC_H
#define PNLWZNMVECREC_H

#include "ApiWznm_blks.h"

#define VecVWznmVecRecDo PnlWznmVecRec::VecVDo

#define ContInfWznmVecRec PnlWznmVecRec::ContInf
#define StatAppWznmVecRec PnlWznmVecRec::StatApp
#define StatShrWznmVecRec PnlWznmVecRec::StatShr
#define TagWznmVecRec PnlWznmVecRec::Tag

#define DpchAppWznmVecRecDo PnlWznmVecRec::DpchAppDo
#define DpchEngWznmVecRecData PnlWznmVecRec::DpchEngData

/**
	* PnlWznmVecRec
	*/
namespace PnlWznmVecRec {
	/**
		* VecVDo (full: VecVWznmVecRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmVecRec)
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
	  * StatApp (full: StatAppWznmVecRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEATITLE = 2;
		static const Sbecore::uint INITDONEVEC1NVECTORITEM = 3;
		static const Sbecore::uint INITDONESRC1NFEED = 4;
		static const Sbecore::uint INITDONEREF1NPANEL = 5;
		static const Sbecore::uint INITDONEFCT1NTABLECOL = 6;
		static const Sbecore::uint INITDONEPST1NQUERYMOD = 7;
		static const Sbecore::uint INITDONEMNTABLE = 8;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneATitle = false, const bool initdoneVec1NVectoritem = false, const bool initdoneSrc1NFeed = false, const bool initdoneRef1NPanel = false, const bool initdoneFct1NTablecol = false, const bool initdonePst1NQuerymod = false, const bool initdoneMNTable = false);

	public:
		bool initdoneDetail;
		bool initdoneATitle;
		bool initdoneVec1NVectoritem;
		bool initdoneSrc1NFeed;
		bool initdoneRef1NPanel;
		bool initdoneFct1NTablecol;
		bool initdonePst1NQuerymod;
		bool initdoneMNTable;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmVecRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFATITLE = 3;
		static const Sbecore::uint SCRJREFVEC1NVECTORITEM = 4;
		static const Sbecore::uint SCRJREFSRC1NFEED = 5;
		static const Sbecore::uint SCRJREFREF1NPANEL = 6;
		static const Sbecore::uint SCRJREFFCT1NTABLECOL = 7;
		static const Sbecore::uint PNLFCT1NTABLECOLAVAIL = 8;
		static const Sbecore::uint SCRJREFPST1NQUERYMOD = 9;
		static const Sbecore::uint PNLPST1NQUERYMODAVAIL = 10;
		static const Sbecore::uint SCRJREFMNTABLE = 11;
		static const Sbecore::uint PNLMNTABLEAVAIL = 12;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 13;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefATitle = "", const std::string& scrJrefVec1NVectoritem = "", const std::string& scrJrefSrc1NFeed = "", const std::string& scrJrefRef1NPanel = "", const std::string& scrJrefFct1NTablecol = "", const bool pnlfct1ntablecolAvail = false, const std::string& scrJrefPst1NQuerymod = "", const bool pnlpst1nquerymodAvail = false, const std::string& scrJrefMNTable = "", const bool pnlmntableAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefATitle;
		std::string scrJrefVec1NVectoritem;
		std::string scrJrefSrc1NFeed;
		std::string scrJrefRef1NPanel;
		std::string scrJrefFct1NTablecol;
		bool pnlfct1ntablecolAvail;
		std::string scrJrefPst1NQuerymod;
		bool pnlpst1nquerymodAvail;
		std::string scrJrefMNTable;
		bool pnlmntableAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmVecRec)
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
		* DpchAppDo (full: DpchAppWznmVecRecDo)
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
		* DpchEngData (full: DpchEngWznmVecRecData)
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

