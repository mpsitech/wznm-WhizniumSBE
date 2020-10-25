/**
	* \file PnlWznmTblRec.h
	* API code for job PnlWznmTblRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMTBLREC_H
#define PNLWZNMTBLREC_H

#include "ApiWznm_blks.h"

#define VecVWznmTblRecDo PnlWznmTblRec::VecVDo

#define ContInfWznmTblRec PnlWznmTblRec::ContInf
#define StatAppWznmTblRec PnlWznmTblRec::StatApp
#define StatShrWznmTblRec PnlWznmTblRec::StatShr
#define TagWznmTblRec PnlWznmTblRec::Tag

#define DpchAppWznmTblRecDo PnlWznmTblRec::DpchAppDo
#define DpchEngWznmTblRecData PnlWznmTblRec::DpchEngData

/**
	* PnlWznmTblRec
	*/
namespace PnlWznmTblRec {
	/**
		* VecVDo (full: VecVWznmTblRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmTblRec)
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
	  * StatApp (full: StatAppWznmTblRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEALOADFCT = 2;
		static const Sbecore::uint INITDONEATITLE = 3;
		static const Sbecore::uint INITDONE1NIMPEXP = 4;
		static const Sbecore::uint INITDONE1NCHECK = 5;
		static const Sbecore::uint INITDONEFR1NRELATION = 6;
		static const Sbecore::uint INITDONETO1NRELATION = 7;
		static const Sbecore::uint INITDONE1NSTUB = 8;
		static const Sbecore::uint INITDONE1NSUBSET = 9;
		static const Sbecore::uint INITDONETBL1NTABLECOL = 10;
		static const Sbecore::uint INITDONEREF1NDIALOG = 11;
		static const Sbecore::uint INITDONEREF1NCALL = 12;
		static const Sbecore::uint INITDONESRC1NFEED = 13;
		static const Sbecore::uint INITDONEREF1NPANEL = 14;
		static const Sbecore::uint INITDONEFCT1NTABLECOL = 15;
		static const Sbecore::uint INITDONEHK1NVECTOR = 16;
		static const Sbecore::uint INITDONEREF1NQUERYMOD = 17;
		static const Sbecore::uint INITDONEREF1NRTBLOCK = 18;
		static const Sbecore::uint INITDONEPST1NQUERYMOD = 19;
		static const Sbecore::uint INITDONEMNVECTOR = 20;
		static const Sbecore::uint INITDONEMNQUERY = 21;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneALoadfct = false, const bool initdoneATitle = false, const bool initdone1NImpexp = false, const bool initdone1NCheck = false, const bool initdoneFr1NRelation = false, const bool initdoneTo1NRelation = false, const bool initdone1NStub = false, const bool initdone1NSubset = false, const bool initdoneTbl1NTablecol = false, const bool initdoneRef1NDialog = false, const bool initdoneRef1NCall = false, const bool initdoneSrc1NFeed = false, const bool initdoneRef1NPanel = false, const bool initdoneFct1NTablecol = false, const bool initdoneHk1NVector = false, const bool initdoneRef1NQuerymod = false, const bool initdoneRef1NRtblock = false, const bool initdonePst1NQuerymod = false, const bool initdoneMNVector = false, const bool initdoneMNQuery = false);

	public:
		bool initdoneDetail;
		bool initdoneALoadfct;
		bool initdoneATitle;
		bool initdone1NImpexp;
		bool initdone1NCheck;
		bool initdoneFr1NRelation;
		bool initdoneTo1NRelation;
		bool initdone1NStub;
		bool initdone1NSubset;
		bool initdoneTbl1NTablecol;
		bool initdoneRef1NDialog;
		bool initdoneRef1NCall;
		bool initdoneSrc1NFeed;
		bool initdoneRef1NPanel;
		bool initdoneFct1NTablecol;
		bool initdoneHk1NVector;
		bool initdoneRef1NQuerymod;
		bool initdoneRef1NRtblock;
		bool initdonePst1NQuerymod;
		bool initdoneMNVector;
		bool initdoneMNQuery;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmTblRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFALOADFCT = 3;
		static const Sbecore::uint PNLALOADFCTAVAIL = 4;
		static const Sbecore::uint SCRJREFATITLE = 5;
		static const Sbecore::uint PNLATITLEAVAIL = 6;
		static const Sbecore::uint SCRJREF1NIMPEXP = 7;
		static const Sbecore::uint PNL1NIMPEXPAVAIL = 8;
		static const Sbecore::uint SCRJREF1NCHECK = 9;
		static const Sbecore::uint PNL1NCHECKAVAIL = 10;
		static const Sbecore::uint SCRJREFFR1NRELATION = 11;
		static const Sbecore::uint PNLFR1NRELATIONAVAIL = 12;
		static const Sbecore::uint SCRJREFTO1NRELATION = 13;
		static const Sbecore::uint PNLTO1NRELATIONAVAIL = 14;
		static const Sbecore::uint SCRJREF1NSTUB = 15;
		static const Sbecore::uint PNL1NSTUBAVAIL = 16;
		static const Sbecore::uint SCRJREF1NSUBSET = 17;
		static const Sbecore::uint PNL1NSUBSETAVAIL = 18;
		static const Sbecore::uint SCRJREFTBL1NTABLECOL = 19;
		static const Sbecore::uint SCRJREFREF1NDIALOG = 20;
		static const Sbecore::uint PNLREF1NDIALOGAVAIL = 21;
		static const Sbecore::uint SCRJREFREF1NCALL = 22;
		static const Sbecore::uint PNLREF1NCALLAVAIL = 23;
		static const Sbecore::uint SCRJREFSRC1NFEED = 24;
		static const Sbecore::uint SCRJREFREF1NPANEL = 25;
		static const Sbecore::uint SCRJREFFCT1NTABLECOL = 26;
		static const Sbecore::uint PNLFCT1NTABLECOLAVAIL = 27;
		static const Sbecore::uint SCRJREFHK1NVECTOR = 28;
		static const Sbecore::uint SCRJREFREF1NQUERYMOD = 29;
		static const Sbecore::uint SCRJREFREF1NRTBLOCK = 30;
		static const Sbecore::uint SCRJREFPST1NQUERYMOD = 31;
		static const Sbecore::uint PNLPST1NQUERYMODAVAIL = 32;
		static const Sbecore::uint SCRJREFMNVECTOR = 33;
		static const Sbecore::uint PNLMNVECTORAVAIL = 34;
		static const Sbecore::uint SCRJREFMNQUERY = 35;
		static const Sbecore::uint PNLMNQUERYAVAIL = 36;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 37;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefALoadfct = "", const bool pnlaloadfctAvail = false, const std::string& scrJrefATitle = "", const bool pnlatitleAvail = false, const std::string& scrJref1NImpexp = "", const bool pnl1nimpexpAvail = false, const std::string& scrJref1NCheck = "", const bool pnl1ncheckAvail = false, const std::string& scrJrefFr1NRelation = "", const bool pnlfr1nrelationAvail = false, const std::string& scrJrefTo1NRelation = "", const bool pnlto1nrelationAvail = false, const std::string& scrJref1NStub = "", const bool pnl1nstubAvail = false, const std::string& scrJref1NSubset = "", const bool pnl1nsubsetAvail = false, const std::string& scrJrefTbl1NTablecol = "", const std::string& scrJrefRef1NDialog = "", const bool pnlref1ndialogAvail = false, const std::string& scrJrefRef1NCall = "", const bool pnlref1ncallAvail = false, const std::string& scrJrefSrc1NFeed = "", const std::string& scrJrefRef1NPanel = "", const std::string& scrJrefFct1NTablecol = "", const bool pnlfct1ntablecolAvail = false, const std::string& scrJrefHk1NVector = "", const std::string& scrJrefRef1NQuerymod = "", const std::string& scrJrefRef1NRtblock = "", const std::string& scrJrefPst1NQuerymod = "", const bool pnlpst1nquerymodAvail = false, const std::string& scrJrefMNVector = "", const bool pnlmnvectorAvail = false, const std::string& scrJrefMNQuery = "", const bool pnlmnqueryAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefALoadfct;
		bool pnlaloadfctAvail;
		std::string scrJrefATitle;
		bool pnlatitleAvail;
		std::string scrJref1NImpexp;
		bool pnl1nimpexpAvail;
		std::string scrJref1NCheck;
		bool pnl1ncheckAvail;
		std::string scrJrefFr1NRelation;
		bool pnlfr1nrelationAvail;
		std::string scrJrefTo1NRelation;
		bool pnlto1nrelationAvail;
		std::string scrJref1NStub;
		bool pnl1nstubAvail;
		std::string scrJref1NSubset;
		bool pnl1nsubsetAvail;
		std::string scrJrefTbl1NTablecol;
		std::string scrJrefRef1NDialog;
		bool pnlref1ndialogAvail;
		std::string scrJrefRef1NCall;
		bool pnlref1ncallAvail;
		std::string scrJrefSrc1NFeed;
		std::string scrJrefRef1NPanel;
		std::string scrJrefFct1NTablecol;
		bool pnlfct1ntablecolAvail;
		std::string scrJrefHk1NVector;
		std::string scrJrefRef1NQuerymod;
		std::string scrJrefRef1NRtblock;
		std::string scrJrefPst1NQuerymod;
		bool pnlpst1nquerymodAvail;
		std::string scrJrefMNVector;
		bool pnlmnvectorAvail;
		std::string scrJrefMNQuery;
		bool pnlmnqueryAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmTblRec)
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
		* DpchAppDo (full: DpchAppWznmTblRecDo)
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
		* DpchEngData (full: DpchEngWznmTblRecData)
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

