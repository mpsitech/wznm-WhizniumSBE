/**
	* \file PnlWznmRlsList.h
	* API code for job PnlWznmRlsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMRLSLIST_H
#define PNLWZNMRLSLIST_H

#include "ApiWznm_blks.h"

#include "WznmQRlsList.h"

#include "QryWznmRlsList.h"

#define VecVWznmRlsListDo PnlWznmRlsList::VecVDo

#define ContIacWznmRlsList PnlWznmRlsList::ContIac
#define ContInfWznmRlsList PnlWznmRlsList::ContInf
#define StatShrWznmRlsList PnlWznmRlsList::StatShr
#define StgIacWznmRlsList PnlWznmRlsList::StgIac
#define TagWznmRlsList PnlWznmRlsList::Tag

#define DpchAppWznmRlsListData PnlWznmRlsList::DpchAppData
#define DpchAppWznmRlsListDo PnlWznmRlsList::DpchAppDo
#define DpchEngWznmRlsListData PnlWznmRlsList::DpchEngData

/**
	* PnlWznmRlsList
	*/
namespace PnlWznmRlsList {
	/**
		* VecVDo (full: VecVWznmRlsListDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDELETECLICK = 4;
		static const Sbecore::uint BUTFILTERCLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmRlsList)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFTOS = 1;

	public:
		ContIac(const Sbecore::uint numFTos = 1);

	public:
		Sbecore::uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmRlsList)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTFOR = 1;
		static const Sbecore::uint TXTPRE = 2;
		static const Sbecore::uint BUTFILTERON = 3;
		static const Sbecore::uint NUMFCSIQST = 4;

	public:
		ContInf(const std::string& TxtFor = "", const std::string& TxtPre = "", const bool ButFilterOn = false, const Sbecore::uint numFCsiQst = 1);

	public:
		std::string TxtFor;
		std::string TxtPre;
		bool ButFilterOn;
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWznmRlsList)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWznmRlsList)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOSRFWIDTH = 1;
		static const Sbecore::uint TCOCMPWIDTH = 2;
		static const Sbecore::uint TCOMCHWIDTH = 3;

	public:
		StgIac(const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoCmpWidth = 100, const Sbecore::uint TcoMchWidth = 100);

	public:
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoCmpWidth;
		Sbecore::uint TcoMchWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWznmRlsList)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTFOR = 2;
		static const Sbecore::uint TXTRECORD1 = 3;
		static const Sbecore::uint TXTRECORD2 = 4;
		static const Sbecore::uint TRS = 5;
		static const Sbecore::uint TXTSHOWING1 = 6;
		static const Sbecore::uint TXTSHOWING2 = 7;
		static const Sbecore::uint TCOSRF = 8;
		static const Sbecore::uint TCOCMP = 9;
		static const Sbecore::uint TCOMCH = 10;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtFor = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoSrf = "", const std::string& TcoCmp = "", const std::string& TcoMch = "");

	public:
		std::string Cpt;
		std::string TxtFor;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoSrf;
		std::string TcoCmp;
		std::string TcoMch;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmRlsListData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWznmRlsList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWznmRlsList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWznmRlsListDo)
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
		* DpchEngData (full: DpchEngWznmRlsListData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFCSIQST = 4;
		static const Sbecore::uint FEEDFTOS = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint STGIAC = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint RST = 9;
		static const Sbecore::uint STATAPPQRY = 10;
		static const Sbecore::uint STATSHRQRY = 11;
		static const Sbecore::uint STGIACQRY = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		Sbecore::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWznmQRlsList rst;
		QryWznmRlsList::StatApp statappqry;
		QryWznmRlsList::StatShr statshrqry;
		QryWznmRlsList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
