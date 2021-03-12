/**
	* \file PnlWznmNavHeadbar.h
	* job handler for job PnlWznmNavHeadbar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVHEADBAR_H
#define PNLWZNMNAVHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatShrWznmNavHeadbar PnlWznmNavHeadbar::StatShr
#define StgInfWznmNavHeadbar PnlWznmNavHeadbar::StgInf
#define TagWznmNavHeadbar PnlWznmNavHeadbar::Tag

#define DpchEngWznmNavHeadbarData PnlWznmNavHeadbar::DpchEngData

/**
	* PnlWznmNavHeadbar
	*/
class PnlWznmNavHeadbar : public JobWznm {

public:
	/**
		* StatShr (full: StatShrWznmNavHeadbar)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgInf (full: StgInfWznmNavHeadbar)
		*/
	class StgInf {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWznmNavHeadbar)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWznmNavHeadbarData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint STGINF = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalMenCrdAvail(DbsWznm* dbswznm);
	bool evalMspCrd1Avail(DbsWznm* dbswznm);
	bool evalMitCrdUsgAvail(DbsWznm* dbswznm);
	bool evalMitCrdUsrAvail(DbsWznm* dbswznm);
	bool evalMitCrdPrsAvail(DbsWznm* dbswznm);
	bool evalMitCrdFilAvail(DbsWznm* dbswznm);
	bool evalMspCrd2Avail(DbsWznm* dbswznm);
	bool evalMitCrdLocAvail(DbsWznm* dbswznm);
	bool evalMitCrdTagAvail(DbsWznm* dbswznm);
	bool evalMitCrdCtpAvail(DbsWznm* dbswznm);
	bool evalMitCrdMchAvail(DbsWznm* dbswznm);
	bool evalMitCrdLibAvail(DbsWznm* dbswznm);
	bool evalMspCrd3Avail(DbsWznm* dbswznm);
	bool evalMitCrdPrjAvail(DbsWznm* dbswznm);
	bool evalMitCrdVerAvail(DbsWznm* dbswznm);
	bool evalMitCrdCapAvail(DbsWznm* dbswznm);
	bool evalMitCrdErrAvail(DbsWznm* dbswznm);
	bool evalMspCrd4Avail(DbsWznm* dbswznm);
	bool evalMitCrdTblAvail(DbsWznm* dbswznm);
	bool evalMitCrdTcoAvail(DbsWznm* dbswznm);
	bool evalMitCrdSbsAvail(DbsWznm* dbswznm);
	bool evalMitCrdRelAvail(DbsWznm* dbswznm);
	bool evalMitCrdVecAvail(DbsWznm* dbswznm);
	bool evalMitCrdVitAvail(DbsWznm* dbswznm);
	bool evalMitCrdChkAvail(DbsWznm* dbswznm);
	bool evalMitCrdStbAvail(DbsWznm* dbswznm);
	bool evalMitCrdIexAvail(DbsWznm* dbswznm);
	bool evalMitCrdImeAvail(DbsWznm* dbswznm);
	bool evalMspCrd5Avail(DbsWznm* dbswznm);
	bool evalMitCrdPstAvail(DbsWznm* dbswznm);
	bool evalMitCrdMdlAvail(DbsWznm* dbswznm);
	bool evalMitCrdCarAvail(DbsWznm* dbswznm);
	bool evalMitCrdDlgAvail(DbsWznm* dbswznm);
	bool evalMitCrdPnlAvail(DbsWznm* dbswznm);
	bool evalMitCrdQryAvail(DbsWznm* dbswznm);
	bool evalMitCrdQcoAvail(DbsWznm* dbswznm);
	bool evalMitCrdQmdAvail(DbsWznm* dbswznm);
	bool evalMitCrdConAvail(DbsWznm* dbswznm);
	bool evalMspCrd6Avail(DbsWznm* dbswznm);
	bool evalMitCrdOpkAvail(DbsWznm* dbswznm);
	bool evalMitCrdOpxAvail(DbsWznm* dbswznm);
	bool evalMspCrd7Avail(DbsWznm* dbswznm);
	bool evalMitCrdJobAvail(DbsWznm* dbswznm);
	bool evalMitCrdSgeAvail(DbsWznm* dbswznm);
	bool evalMitCrdMtdAvail(DbsWznm* dbswznm);
	bool evalMitCrdBlkAvail(DbsWznm* dbswznm);
	bool evalMitCrdCalAvail(DbsWznm* dbswznm);
	bool evalMspCrd8Avail(DbsWznm* dbswznm);
	bool evalMitCrdCmpAvail(DbsWznm* dbswznm);
	bool evalMitCrdRlsAvail(DbsWznm* dbswznm);
	bool evalMspCrd9Avail(DbsWznm* dbswznm);
	bool evalMitCrdAppAvail(DbsWznm* dbswznm);
	bool evalMitCrdRtjAvail(DbsWznm* dbswznm);
	bool evalMitCrdEvtAvail(DbsWznm* dbswznm);
	bool evalMitCrdSeqAvail(DbsWznm* dbswznm);
	bool evalMitCrdSteAvail(DbsWznm* dbswznm);
	bool evalMspCrd10Avail(DbsWznm* dbswznm);
	bool evalMitCrdUtlAvail(DbsWznm* dbswznm);

public:
	PnlWznmNavHeadbar(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavHeadbar();

public:
	StatShr statshr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

};

#endif
