/**
	* \file PnlWznmRelRec.h
	* API code for job PnlWznmRelRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMRELREC_H
#define PNLWZNMRELREC_H

#include "ApiWznm_blks.h"

#define VecVWznmRelRecDo PnlWznmRelRec::VecVDo

#define ContInfWznmRelRec PnlWznmRelRec::ContInf
#define StatAppWznmRelRec PnlWznmRelRec::StatApp
#define StatShrWznmRelRec PnlWznmRelRec::StatShr
#define TagWznmRelRec PnlWznmRelRec::Tag

#define DpchAppWznmRelRecDo PnlWznmRelRec::DpchAppDo
#define DpchEngWznmRelRecData PnlWznmRelRec::DpchEngData

/**
	* PnlWznmRelRec
	*/
namespace PnlWznmRelRec {
	/**
		* VecVDo (full: VecVWznmRelRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmRelRec)
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
	  * StatApp (full: StatAppWznmRelRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEATITLE = 2;
		static const Sbecore::uint INITDONE1NTABLECOL = 3;
		static const Sbecore::uint INITDONESUP1NRELATION = 4;
		static const Sbecore::uint INITDONEREF1NPANEL = 5;
		static const Sbecore::uint INITDONEREF1NCONTROL = 6;
		static const Sbecore::uint INITDONEREF1NDIALOG = 7;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneATitle = false, const bool initdone1NTablecol = false, const bool initdoneSup1NRelation = false, const bool initdoneRef1NPanel = false, const bool initdoneRef1NControl = false, const bool initdoneRef1NDialog = false);

	public:
		bool initdoneDetail;
		bool initdoneATitle;
		bool initdone1NTablecol;
		bool initdoneSup1NRelation;
		bool initdoneRef1NPanel;
		bool initdoneRef1NControl;
		bool initdoneRef1NDialog;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmRelRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFATITLE = 3;
		static const Sbecore::uint SCRJREF1NTABLECOL = 4;
		static const Sbecore::uint SCRJREFSUP1NRELATION = 5;
		static const Sbecore::uint SCRJREFREF1NPANEL = 6;
		static const Sbecore::uint SCRJREFREF1NCONTROL = 7;
		static const Sbecore::uint SCRJREFREF1NDIALOG = 8;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 9;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefATitle = "", const std::string& scrJref1NTablecol = "", const std::string& scrJrefSup1NRelation = "", const std::string& scrJrefRef1NPanel = "", const std::string& scrJrefRef1NControl = "", const std::string& scrJrefRef1NDialog = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefATitle;
		std::string scrJref1NTablecol;
		std::string scrJrefSup1NRelation;
		std::string scrJrefRef1NPanel;
		std::string scrJrefRef1NControl;
		std::string scrJrefRef1NDialog;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmRelRec)
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
		* DpchAppDo (full: DpchAppWznmRelRecDo)
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
		* DpchEngData (full: DpchEngWznmRelRecData)
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

