/**
	* \file PnlWznmNavJob.h
	* job handler for job PnlWznmNavJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVJOB_H
#define PNLWZNMNAVJOB_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

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
class PnlWznmNavJob : public JobWznm {

public:
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
	class ContIac : public Sbecore::Block {

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
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWznmNavJob)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstJobAlt = true, const bool LstSgeAlt = true, const bool LstMtdAlt = true, const bool LstBlkAlt = true, const bool LstCalAlt = true, const Sbecore::uint LstJobNumFirstdisp = 1, const Sbecore::uint LstSgeNumFirstdisp = 1, const Sbecore::uint LstMtdNumFirstdisp = 1, const Sbecore::uint LstBlkNumFirstdisp = 1, const Sbecore::uint LstCalNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstJobAlt = true, const bool LstSgeAlt = true, const bool LstMtdAlt = true, const bool LstBlkAlt = true, const bool LstCalAlt = true, const Sbecore::uint LstJobNumFirstdisp = 1, const Sbecore::uint LstSgeNumFirstdisp = 1, const Sbecore::uint LstMtdNumFirstdisp = 1, const Sbecore::uint LstBlkNumFirstdisp = 1, const Sbecore::uint LstCalNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmNavJob)
		*/
	class StatShr : public Sbecore::Block {

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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavJob)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavJobData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavJobDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmNavJobData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTBLK = 3;
		static const Sbecore::uint FEEDFLSTCAL = 4;
		static const Sbecore::uint FEEDFLSTJOB = 5;
		static const Sbecore::uint FEEDFLSTMTD = 6;
		static const Sbecore::uint FEEDFLSTSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstBlk = NULL, Sbecore::Feed* feedFLstCal = NULL, Sbecore::Feed* feedFLstJob = NULL, Sbecore::Feed* feedFLstMtd = NULL, Sbecore::Feed* feedFLstSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstBlk;
		Sbecore::Feed feedFLstCal;
		Sbecore::Feed feedFLstJob;
		Sbecore::Feed feedFLstMtd;
		Sbecore::Feed feedFLstSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstJobAvail(DbsWznm* dbswznm);
	bool evalButJobViewActive(DbsWznm* dbswznm);
	bool evalButJobNewcrdActive(DbsWznm* dbswznm);
	bool evalLstSgeAvail(DbsWznm* dbswznm);
	bool evalButSgeViewActive(DbsWznm* dbswznm);
	bool evalButSgeNewcrdActive(DbsWznm* dbswznm);
	bool evalLstMtdAvail(DbsWznm* dbswznm);
	bool evalButMtdViewActive(DbsWznm* dbswznm);
	bool evalButMtdNewcrdActive(DbsWznm* dbswznm);
	bool evalLstBlkAvail(DbsWznm* dbswznm);
	bool evalButBlkViewActive(DbsWznm* dbswznm);
	bool evalButBlkNewcrdActive(DbsWznm* dbswznm);
	bool evalLstCalAvail(DbsWznm* dbswznm);
	bool evalButCalViewActive(DbsWznm* dbswznm);
	bool evalButCalNewcrdActive(DbsWznm* dbswznm);

public:
	PnlWznmNavJob(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavJob();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstBlk;
	Sbecore::Feed feedFLstCal;
	Sbecore::Feed feedFLstJob;
	Sbecore::Feed feedFLstMtd;
	Sbecore::Feed feedFLstSge;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstJob(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshJob(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstSge(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshSge(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstMtd(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshMtd(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstBlk(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshBlk(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstCal(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshCal(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButJobViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJobNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSgeViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSgeNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMtdViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMtdNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButBlkViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButBlkNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCalViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCalNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
