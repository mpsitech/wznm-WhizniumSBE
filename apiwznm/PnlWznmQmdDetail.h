/**
	* \file PnlWznmQmdDetail.h
	* API code for job PnlWznmQmdDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMQMDDETAIL_H
#define PNLWZNMQMDDETAIL_H

#include "ApiWznm_blks.h"

#define VecVWznmQmdDetailDo PnlWznmQmdDetail::VecVDo

#define ContIacWznmQmdDetail PnlWznmQmdDetail::ContIac
#define ContInfWznmQmdDetail PnlWznmQmdDetail::ContInf
#define StatAppWznmQmdDetail PnlWznmQmdDetail::StatApp
#define StatShrWznmQmdDetail PnlWznmQmdDetail::StatShr
#define TagWznmQmdDetail PnlWznmQmdDetail::Tag

#define DpchAppWznmQmdDetailData PnlWznmQmdDetail::DpchAppData
#define DpchAppWznmQmdDetailDo PnlWznmQmdDetail::DpchAppDo
#define DpchEngWznmQmdDetailData PnlWznmQmdDetail::DpchEngData

/**
	* PnlWznmQmdDetail
	*/
namespace PnlWznmQmdDetail {
	/**
		* VecVDo (full: VecVWznmQmdDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTQRYVIEWCLICK = 2;
		static const Sbecore::uint BUTPSTVIEWCLICK = 3;
		static const Sbecore::uint BUTREUVIEWCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmQmdDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint TXFAVL = 3;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupRet = 1, const std::string& TxfAvl = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupRet;
		std::string TxfAvl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmQmdDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTQRY = 1;
		static const Sbecore::uint TXTPST = 2;
		static const Sbecore::uint TXTREU = 3;

	public:
		ContInf(const std::string& TxtQry = "", const std::string& TxtPst = "", const std::string& TxtReu = "");

	public:
		std::string TxtQry;
		std::string TxtPst;
		std::string TxtReu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmQmdDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);

	public:
		Sbecore::uint ixWznmVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmQmdDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint PUPTYPACTIVE = 3;
		static const Sbecore::uint TXTQRYACTIVE = 4;
		static const Sbecore::uint BUTQRYVIEWAVAIL = 5;
		static const Sbecore::uint BUTQRYVIEWACTIVE = 6;
		static const Sbecore::uint TXTPSTACTIVE = 7;
		static const Sbecore::uint BUTPSTVIEWAVAIL = 8;
		static const Sbecore::uint BUTPSTVIEWACTIVE = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint TXFAVLACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool PupTypActive = true, const bool TxtQryActive = true, const bool ButQryViewAvail = true, const bool ButQryViewActive = true, const bool TxtPstActive = true, const bool ButPstViewAvail = true, const bool ButPstViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxfAvlActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool PupTypActive;
		bool TxtQryActive;
		bool ButQryViewAvail;
		bool ButQryViewActive;
		bool TxtPstActive;
		bool ButPstViewAvail;
		bool ButPstViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxfAvlActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmQmdDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTTYP = 2;
		static const Sbecore::uint CPTQRY = 3;
		static const Sbecore::uint CPTPST = 4;
		static const Sbecore::uint CPTREU = 5;
		static const Sbecore::uint CPTAVL = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptTyp = "", const std::string& CptQry = "", const std::string& CptPst = "", const std::string& CptReu = "", const std::string& CptAvl = "");

	public:
		std::string Cpt;
		std::string CptTyp;
		std::string CptQry;
		std::string CptPst;
		std::string CptReu;
		std::string CptAvl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmQmdDetailData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmQmdDetailDo)
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
		* DpchEngData (full: DpchEngWznmQmdDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPRET = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupRet;
		Sbecore::Xmlio::Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

