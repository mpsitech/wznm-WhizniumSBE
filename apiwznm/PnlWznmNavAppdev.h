/**
	* \file PnlWznmNavAppdev.h
	* API code for job PnlWznmNavAppdev (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef PNLWZNMNAVAPPDEV_H
#define PNLWZNMNAVAPPDEV_H

#include "ApiWznm_blks.h"

#define VecVWznmNavAppdevDo PnlWznmNavAppdev::VecVDo

#define ContIacWznmNavAppdev PnlWznmNavAppdev::ContIac
#define StatAppWznmNavAppdev PnlWznmNavAppdev::StatApp
#define StatShrWznmNavAppdev PnlWznmNavAppdev::StatShr
#define TagWznmNavAppdev PnlWznmNavAppdev::Tag

#define DpchAppWznmNavAppdevData PnlWznmNavAppdev::DpchAppData
#define DpchAppWznmNavAppdevDo PnlWznmNavAppdev::DpchAppDo
#define DpchEngWznmNavAppdevData PnlWznmNavAppdev::DpchEngData

/**
	* PnlWznmNavAppdev
	*/
namespace PnlWznmNavAppdev {
	/**
		* VecVDo (full: VecVWznmNavAppdevDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTAPPVIEWCLICK = 1;
		static const Sbecore::uint BUTAPPNEWCRDCLICK = 2;
		static const Sbecore::uint BUTRTJVIEWCLICK = 3;
		static const Sbecore::uint BUTRTJNEWCRDCLICK = 4;
		static const Sbecore::uint BUTEVTVIEWCLICK = 5;
		static const Sbecore::uint BUTEVTNEWCRDCLICK = 6;
		static const Sbecore::uint BUTSEQVIEWCLICK = 7;
		static const Sbecore::uint BUTSEQNEWCRDCLICK = 8;
		static const Sbecore::uint BUTSTEVIEWCLICK = 9;
		static const Sbecore::uint BUTSTENEWCRDCLICK = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavAppdev)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTAPP = 1;
		static const Sbecore::uint NUMFLSTRTJ = 2;
		static const Sbecore::uint NUMFLSTEVT = 3;
		static const Sbecore::uint NUMFLSTSEQ = 4;
		static const Sbecore::uint NUMFLSTSTE = 5;

	public:
		ContIac(const Sbecore::uint numFLstApp = 1, const Sbecore::uint numFLstRtj = 1, const Sbecore::uint numFLstEvt = 1, const Sbecore::uint numFLstSeq = 1, const Sbecore::uint numFLstSte = 1);

	public:
		Sbecore::uint numFLstApp;
		Sbecore::uint numFLstRtj;
		Sbecore::uint numFLstEvt;
		Sbecore::uint numFLstSeq;
		Sbecore::uint numFLstSte;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNavAppdev)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTAPPALT = 2;
		static const Sbecore::uint LSTRTJALT = 3;
		static const Sbecore::uint LSTEVTALT = 4;
		static const Sbecore::uint LSTSEQALT = 5;
		static const Sbecore::uint LSTSTEALT = 6;
		static const Sbecore::uint LSTAPPNUMFIRSTDISP = 7;
		static const Sbecore::uint LSTRTJNUMFIRSTDISP = 8;
		static const Sbecore::uint LSTEVTNUMFIRSTDISP = 9;
		static const Sbecore::uint LSTSEQNUMFIRSTDISP = 10;
		static const Sbecore::uint LSTSTENUMFIRSTDISP = 11;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstAppAlt = true, const bool LstRtjAlt = true, const bool LstEvtAlt = true, const bool LstSeqAlt = true, const bool LstSteAlt = true, const Sbecore::uint LstAppNumFirstdisp = 1, const Sbecore::uint LstRtjNumFirstdisp = 1, const Sbecore::uint LstEvtNumFirstdisp = 1, const Sbecore::uint LstSeqNumFirstdisp = 1, const Sbecore::uint LstSteNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstAppAlt;
		bool LstRtjAlt;
		bool LstEvtAlt;
		bool LstSeqAlt;
		bool LstSteAlt;
		Sbecore::uint LstAppNumFirstdisp;
		Sbecore::uint LstRtjNumFirstdisp;
		Sbecore::uint LstEvtNumFirstdisp;
		Sbecore::uint LstSeqNumFirstdisp;
		Sbecore::uint LstSteNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavAppdev)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTAPPAVAIL = 1;
		static const Sbecore::uint BUTAPPVIEWACTIVE = 2;
		static const Sbecore::uint LSTRTJAVAIL = 3;
		static const Sbecore::uint BUTRTJVIEWACTIVE = 4;
		static const Sbecore::uint BUTRTJNEWCRDACTIVE = 5;
		static const Sbecore::uint LSTEVTAVAIL = 6;
		static const Sbecore::uint BUTEVTVIEWACTIVE = 7;
		static const Sbecore::uint BUTEVTNEWCRDACTIVE = 8;
		static const Sbecore::uint LSTSEQAVAIL = 9;
		static const Sbecore::uint BUTSEQVIEWACTIVE = 10;
		static const Sbecore::uint BUTSEQNEWCRDACTIVE = 11;
		static const Sbecore::uint LSTSTEAVAIL = 12;
		static const Sbecore::uint BUTSTEVIEWACTIVE = 13;
		static const Sbecore::uint BUTSTENEWCRDACTIVE = 14;

	public:
		StatShr(const bool LstAppAvail = true, const bool ButAppViewActive = true, const bool LstRtjAvail = true, const bool ButRtjViewActive = true, const bool ButRtjNewcrdActive = true, const bool LstEvtAvail = true, const bool ButEvtViewActive = true, const bool ButEvtNewcrdActive = true, const bool LstSeqAvail = true, const bool ButSeqViewActive = true, const bool ButSeqNewcrdActive = true, const bool LstSteAvail = true, const bool ButSteViewActive = true, const bool ButSteNewcrdActive = true);

	public:
		bool LstAppAvail;
		bool ButAppViewActive;
		bool LstRtjAvail;
		bool ButRtjViewActive;
		bool ButRtjNewcrdActive;
		bool LstEvtAvail;
		bool ButEvtViewActive;
		bool ButEvtNewcrdActive;
		bool LstSeqAvail;
		bool ButSeqViewActive;
		bool ButSeqNewcrdActive;
		bool LstSteAvail;
		bool ButSteViewActive;
		bool ButSteNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavAppdev)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTAPP = 2;
		static const Sbecore::uint CPTRTJ = 3;
		static const Sbecore::uint CPTEVT = 4;
		static const Sbecore::uint CPTSEQ = 5;
		static const Sbecore::uint CPTSTE = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptApp = "", const std::string& CptRtj = "", const std::string& CptEvt = "", const std::string& CptSeq = "", const std::string& CptSte = "");

	public:
		std::string Cpt;
		std::string CptApp;
		std::string CptRtj;
		std::string CptEvt;
		std::string CptSeq;
		std::string CptSte;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavAppdevData)
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
		* DpchAppDo (full: DpchAppWznmNavAppdevDo)
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
		* DpchEngData (full: DpchEngWznmNavAppdevData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTAPP = 3;
		static const Sbecore::uint FEEDFLSTEVT = 4;
		static const Sbecore::uint FEEDFLSTRTJ = 5;
		static const Sbecore::uint FEEDFLSTSEQ = 6;
		static const Sbecore::uint FEEDFLSTSTE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstApp;
		Sbecore::Xmlio::Feed feedFLstEvt;
		Sbecore::Xmlio::Feed feedFLstRtj;
		Sbecore::Xmlio::Feed feedFLstSeq;
		Sbecore::Xmlio::Feed feedFLstSte;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

