/**
	* \file PnlWznmNavJob.h
	* API code for job PnlWznmNavJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVJOB_H
#define PNLWZNMNAVJOB_H

#include "ApiWznm_blks.h"

#define VecVWznmNavJobDo PnlWznmNavJob::VecVDo

#define ContIacWznmNavJob PnlWznmNavJob::ContIac
#define StatAppWznmNavJob PnlWznmNavJob::StatApp
#define StatShrWznmNavJob PnlWznmNavJob::StatShr
#define TagWznmNavJob PnlWznmNavJob::Tag

#define DpchAppWznmNavJobData PnlWznmNavJob::DpchAppData
#define DpchAppWznmNavJobDo PnlWznmNavJob::DpchAppDo
#define DpchEngWznmNavJobData PnlWznmNavJob::DpchEngData

/**
	* PnlWznmNavJob
	*/
namespace PnlWznmNavJob {
	/**
		* VecVDo (full: VecVWznmNavJobDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTJOBVIEWCLICK = 1;
		static const Sbecore::uint BUTJOBNEWCRDCLICK = 2;
		static const Sbecore::uint BUTSGEVIEWCLICK = 3;
		static const Sbecore::uint BUTSGENEWCRDCLICK = 4;
		static const Sbecore::uint BUTMTDVIEWCLICK = 5;
		static const Sbecore::uint BUTMTDNEWCRDCLICK = 6;
		static const Sbecore::uint BUTBLKVIEWCLICK = 7;
		static const Sbecore::uint BUTBLKNEWCRDCLICK = 8;
		static const Sbecore::uint BUTCALVIEWCLICK = 9;
		static const Sbecore::uint BUTCALNEWCRDCLICK = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavJob)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTJOB = 1;
		static const Sbecore::uint NUMFLSTSGE = 2;
		static const Sbecore::uint NUMFLSTMTD = 3;
		static const Sbecore::uint NUMFLSTBLK = 4;
		static const Sbecore::uint NUMFLSTCAL = 5;

	public:
		ContIac(const Sbecore::uint numFLstJob = 1, const Sbecore::uint numFLstSge = 1, const Sbecore::uint numFLstMtd = 1, const Sbecore::uint numFLstBlk = 1, const Sbecore::uint numFLstCal = 1);

	public:
		Sbecore::uint numFLstJob;
		Sbecore::uint numFLstSge;
		Sbecore::uint numFLstMtd;
		Sbecore::uint numFLstBlk;
		Sbecore::uint numFLstCal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWznmNavJob)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint LSTJOBALT = 2;
		static const Sbecore::uint LSTSGEALT = 3;
		static const Sbecore::uint LSTMTDALT = 4;
		static const Sbecore::uint LSTBLKALT = 5;
		static const Sbecore::uint LSTCALALT = 6;
		static const Sbecore::uint LSTJOBNUMFIRSTDISP = 7;
		static const Sbecore::uint LSTSGENUMFIRSTDISP = 8;
		static const Sbecore::uint LSTMTDNUMFIRSTDISP = 9;
		static const Sbecore::uint LSTBLKNUMFIRSTDISP = 10;
		static const Sbecore::uint LSTCALNUMFIRSTDISP = 11;

	public:
		StatApp(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstJobAlt = true, const bool LstSgeAlt = true, const bool LstMtdAlt = true, const bool LstBlkAlt = true, const bool LstCalAlt = true, const Sbecore::uint LstJobNumFirstdisp = 1, const Sbecore::uint LstSgeNumFirstdisp = 1, const Sbecore::uint LstMtdNumFirstdisp = 1, const Sbecore::uint LstBlkNumFirstdisp = 1, const Sbecore::uint LstCalNumFirstdisp = 1);

	public:
		Sbecore::uint ixWznmVExpstate;
		bool LstJobAlt;
		bool LstSgeAlt;
		bool LstMtdAlt;
		bool LstBlkAlt;
		bool LstCalAlt;
		Sbecore::uint LstJobNumFirstdisp;
		Sbecore::uint LstSgeNumFirstdisp;
		Sbecore::uint LstMtdNumFirstdisp;
		Sbecore::uint LstBlkNumFirstdisp;
		Sbecore::uint LstCalNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWznmNavJob)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTJOBAVAIL = 1;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 2;
		static const Sbecore::uint BUTJOBNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTSGEAVAIL = 4;
		static const Sbecore::uint BUTSGEVIEWACTIVE = 5;
		static const Sbecore::uint BUTSGENEWCRDACTIVE = 6;
		static const Sbecore::uint LSTMTDAVAIL = 7;
		static const Sbecore::uint BUTMTDVIEWACTIVE = 8;
		static const Sbecore::uint BUTMTDNEWCRDACTIVE = 9;
		static const Sbecore::uint LSTBLKAVAIL = 10;
		static const Sbecore::uint BUTBLKVIEWACTIVE = 11;
		static const Sbecore::uint BUTBLKNEWCRDACTIVE = 12;
		static const Sbecore::uint LSTCALAVAIL = 13;
		static const Sbecore::uint BUTCALVIEWACTIVE = 14;
		static const Sbecore::uint BUTCALNEWCRDACTIVE = 15;

	public:
		StatShr(const bool LstJobAvail = true, const bool ButJobViewActive = true, const bool ButJobNewcrdActive = true, const bool LstSgeAvail = true, const bool ButSgeViewActive = true, const bool ButSgeNewcrdActive = true, const bool LstMtdAvail = true, const bool ButMtdViewActive = true, const bool ButMtdNewcrdActive = true, const bool LstBlkAvail = true, const bool ButBlkViewActive = true, const bool ButBlkNewcrdActive = true, const bool LstCalAvail = true, const bool ButCalViewActive = true, const bool ButCalNewcrdActive = true);

	public:
		bool LstJobAvail;
		bool ButJobViewActive;
		bool ButJobNewcrdActive;
		bool LstSgeAvail;
		bool ButSgeViewActive;
		bool ButSgeNewcrdActive;
		bool LstMtdAvail;
		bool ButMtdViewActive;
		bool ButMtdNewcrdActive;
		bool LstBlkAvail;
		bool ButBlkViewActive;
		bool ButBlkNewcrdActive;
		bool LstCalAvail;
		bool ButCalViewActive;
		bool ButCalNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWznmNavJob)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTJOB = 2;
		static const Sbecore::uint CPTSGE = 3;
		static const Sbecore::uint CPTMTD = 4;
		static const Sbecore::uint CPTBLK = 5;
		static const Sbecore::uint CPTCAL = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptJob = "", const std::string& CptSge = "", const std::string& CptMtd = "", const std::string& CptBlk = "", const std::string& CptCal = "");

	public:
		std::string Cpt;
		std::string CptJob;
		std::string CptSge;
		std::string CptMtd;
		std::string CptBlk;
		std::string CptCal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavJobData)
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
		* DpchAppDo (full: DpchAppWznmNavJobDo)
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
		* DpchEngData (full: DpchEngWznmNavJobData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTBLK = 3;
		static const Sbecore::uint FEEDFLSTCAL = 4;
		static const Sbecore::uint FEEDFLSTJOB = 5;
		static const Sbecore::uint FEEDFLSTMTD = 6;
		static const Sbecore::uint FEEDFLSTSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstBlk;
		Sbecore::Xmlio::Feed feedFLstCal;
		Sbecore::Xmlio::Feed feedFLstJob;
		Sbecore::Xmlio::Feed feedFLstMtd;
		Sbecore::Xmlio::Feed feedFLstSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
