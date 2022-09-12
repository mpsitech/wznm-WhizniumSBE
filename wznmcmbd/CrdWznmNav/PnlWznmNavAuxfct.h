/**
	* \file PnlWznmNavAuxfct.h
	* job handler for job PnlWznmNavAuxfct (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVAUXFCT_H
#define PNLWZNMNAVAUXFCT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavAuxfctDo PnlWznmNavAuxfct::VecVDo

#define StatAppWznmNavAuxfct PnlWznmNavAuxfct::StatApp
#define StatShrWznmNavAuxfct PnlWznmNavAuxfct::StatShr
#define TagWznmNavAuxfct PnlWznmNavAuxfct::Tag

#define DpchAppWznmNavAuxfctDo PnlWznmNavAuxfct::DpchAppDo
#define DpchEngWznmNavAuxfctData PnlWznmNavAuxfct::DpchEngData

/**
	* PnlWznmNavAuxfct
	*/
class PnlWznmNavAuxfct : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavAuxfctDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUTLNEWCRDCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* StatApp (full: StatAppWznmNavAuxfct)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmNavAuxfct)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTUTLNEWCRDAVAIL = 1;

	public:
		StatShr(const bool ButUtlNewcrdAvail = true);

	public:
		bool ButUtlNewcrdAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavAuxfct)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavAuxfctDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmNavAuxfctData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATAPP = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButUtlNewcrdAvail(DbsWznm* dbswznm);

public:
	PnlWznmNavAuxfct(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavAuxfct();

public:
	StatShr statshr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

	void handleDpchAppDoButUtlNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

};

#endif
