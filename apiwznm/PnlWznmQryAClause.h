/**
	* \file PnlWznmQryAClause.h
	* API code for job PnlWznmQryAClause (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMQRYACLAUSE_H
#define PNLWZNMQRYACLAUSE_H

#include "ApiWznm_blks.h"

#include "WznmQQryAClause.h"

#include "QryWznmQryAClause.h"

#define VecVWznmQryAClauseDo PnlWznmQryAClause::VecVDo

#define ContInfWznmQryAClause PnlWznmQryAClause::ContInf
#define StatAppWznmQryAClause PnlWznmQryAClause::StatApp
#define StatShrWznmQryAClause PnlWznmQryAClause::StatShr
#define StgIacWznmQryAClause PnlWznmQryAClause::StgIac
#define TagWznmQryAClause PnlWznmQryAClause::Tag

#define DpchAppWznmQryAClauseData PnlWznmQryAClause::DpchAppData
#define DpchAppWznmQryAClauseDo PnlWznmQryAClause::DpchAppDo
#define DpchEngWznmQryAClauseData PnlWznmQryAClause::DpchEngData

/**
	* PnlWznmQryAClause
	*/
namespace PnlWznmQryAClause {
	/**
		* VecVDo (full: VecVWznmQryAClauseDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUPCLICK = 1;
		static const Sbecore::uint BUTDOWNCLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDUPLICATECLICK = 4;
		static const Sbecore::uint BUTDELETECLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmQryAClause)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWznmQryAClause)
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
	  * StatShr (full: StatShrWznmQryAClause)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTUPAVAIL = 1;
		static const Sbecore::uint BUTUPACTIVE = 2;
		static const Sbecore::uint BUTDOWNAVAIL = 3;
		static const Sbecore::uint BUTDOWNACTIVE = 4;
		static const Sbecore::uint BUTNEWAVAIL = 5;
		static const Sbecore::uint BUTDUPLICATEAVAIL = 6;
		static const Sbecore::uint BUTDUPLICATEACTIVE = 7;
		static const Sbecore::uint BUTDELETEAVAIL = 8;
		static const Sbecore::uint BUTDELETEACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWznmQryAClause)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOQMDWIDTH = 1;
		static const Sbecore::uint TCOTYPWIDTH = 2;
		static const Sbecore::uint TCOCSEWIDTH = 3;
		static const Sbecore::uint TCOPSTWIDTH = 4;
		static const Sbecore::uint TCOVECWIDTH = 5;
		static const Sbecore::uint TCOVITWIDTH = 6;

	public:
		StgIac(const Sbecore::uint TcoQmdWidth = 100, const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoCseWidth = 100, const Sbecore::uint TcoPstWidth = 100, const Sbecore::uint TcoVecWidth = 100, const Sbecore::uint TcoVitWidth = 100);

	public:
		Sbecore::uint TcoQmdWidth;
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoCseWidth;
		Sbecore::uint TcoPstWidth;
		Sbecore::uint TcoVecWidth;
		Sbecore::uint TcoVitWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWznmQryAClause)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOQMD = 7;
		static const Sbecore::uint TCOTYP = 8;
		static const Sbecore::uint TCOCSE = 9;
		static const Sbecore::uint TCOPST = 10;
		static const Sbecore::uint TCOVEC = 11;
		static const Sbecore::uint TCOVIT = 12;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoQmd = "", const std::string& TcoTyp = "", const std::string& TcoCse = "", const std::string& TcoPst = "", const std::string& TcoVec = "", const std::string& TcoVit = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoQmd;
		std::string TcoTyp;
		std::string TcoCse;
		std::string TcoPst;
		std::string TcoVec;
		std::string TcoVit;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmQryAClauseData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWznmQryAClause::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWznmQryAClause::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmQryAClauseDo)
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
		* DpchEngData (full: DpchEngWznmQryAClauseData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint STGIAC = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint RST = 8;
		static const Sbecore::uint STATAPPQRY = 9;
		static const Sbecore::uint STATSHRQRY = 10;
		static const Sbecore::uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWznmQQryAClause rst;
		QryWznmQryAClause::StatApp statappqry;
		QryWznmQryAClause::StatShr statshrqry;
		QryWznmQryAClause::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

