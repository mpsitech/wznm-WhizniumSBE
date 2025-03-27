/**
	* \file PnlWznmNavVisual.h
	* job handler for job PnlWznmNavVisual (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVVISUAL_H
#define PNLWZNMNAVVISUAL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavVisualDo PnlWznmNavVisual::VecVDo

#define ContIacWznmNavVisual PnlWznmNavVisual::ContIac
#define StatAppWznmNavVisual PnlWznmNavVisual::StatApp
#define StatShrWznmNavVisual PnlWznmNavVisual::StatShr
#define TagWznmNavVisual PnlWznmNavVisual::Tag

#define DpchAppWznmNavVisualData PnlWznmNavVisual::DpchAppData
#define DpchAppWznmNavVisualDo PnlWznmNavVisual::DpchAppDo
#define DpchEngWznmNavVisualData PnlWznmNavVisual::DpchEngData

/**
	* PnlWznmNavVisual
	*/
class PnlWznmNavVisual : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavVisualDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTVISVIEWCLICK = 1;
		static const Sbecore::uint BUTVISNEWCRDCLICK = 2;
		static const Sbecore::uint BUTSHTVIEWCLICK = 3;
		static const Sbecore::uint BUTSHTNEWCRDCLICK = 4;
		static const Sbecore::uint BUTBOXVIEWCLICK = 5;
		static const Sbecore::uint BUTBOXNEWCRDCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmNavVisual)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTVIS = 1;
		static const Sbecore::uint NUMFLSTSHT = 2;
		static const Sbecore::uint NUMFLSTBOX = 3;

	public:
		ContIac(const Sbecore::uint numFLstVis = 1, const Sbecore::uint numFLstSht = 1, const Sbecore::uint numFLstBox = 1);

	public:
		Sbecore::uint numFLstVis;
		Sbecore::uint numFLstSht;
		Sbecore::uint numFLstBox;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWznmNavVisual)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstVisAlt = true, const bool LstShtAlt = true, const bool LstBoxAlt = true, const Sbecore::uint LstVisNumFirstdisp = 1, const Sbecore::uint LstShtNumFirstdisp = 1, const Sbecore::uint LstBoxNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstVisAlt = true, const bool LstShtAlt = true, const bool LstBoxAlt = true, const Sbecore::uint LstVisNumFirstdisp = 1, const Sbecore::uint LstShtNumFirstdisp = 1, const Sbecore::uint LstBoxNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWznmNavVisual)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTVISAVAIL = 1;
		static const Sbecore::uint BUTVISVIEWACTIVE = 2;
		static const Sbecore::uint LSTSHTAVAIL = 3;
		static const Sbecore::uint BUTSHTVIEWACTIVE = 4;
		static const Sbecore::uint BUTSHTNEWCRDACTIVE = 5;
		static const Sbecore::uint LSTBOXAVAIL = 6;
		static const Sbecore::uint BUTBOXVIEWACTIVE = 7;
		static const Sbecore::uint BUTBOXNEWCRDACTIVE = 8;

	public:
		StatShr(const bool LstVisAvail = true, const bool ButVisViewActive = true, const bool LstShtAvail = true, const bool ButShtViewActive = true, const bool ButShtNewcrdActive = true, const bool LstBoxAvail = true, const bool ButBoxViewActive = true, const bool ButBoxNewcrdActive = true);

	public:
		bool LstVisAvail;
		bool ButVisViewActive;
		bool LstShtAvail;
		bool ButShtViewActive;
		bool ButShtNewcrdActive;
		bool LstBoxAvail;
		bool ButBoxViewActive;
		bool ButBoxNewcrdActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavVisual)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavVisualData)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavVisualDo)
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
		* DpchEngData (full: DpchEngWznmNavVisualData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTBOX = 3;
		static const Sbecore::uint FEEDFLSTSHT = 4;
		static const Sbecore::uint FEEDFLSTVIS = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstBox = NULL, Sbecore::Feed* feedFLstSht = NULL, Sbecore::Feed* feedFLstVis = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstBox;
		Sbecore::Feed feedFLstSht;
		Sbecore::Feed feedFLstVis;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstVisAvail(DbsWznm* dbswznm);
	bool evalButVisViewActive(DbsWznm* dbswznm);
	bool evalLstShtAvail(DbsWznm* dbswznm);
	bool evalButShtViewActive(DbsWznm* dbswznm);
	bool evalButShtNewcrdActive(DbsWznm* dbswznm);
	bool evalLstBoxAvail(DbsWznm* dbswznm);
	bool evalButBoxViewActive(DbsWznm* dbswznm);
	bool evalButBoxNewcrdActive(DbsWznm* dbswznm);

public:
	PnlWznmNavVisual(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavVisual();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstBox;
	Sbecore::Feed feedFLstSht;
	Sbecore::Feed feedFLstVis;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstVis(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshVis(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstSht(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshSht(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstBox(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshBox(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButVisViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVisNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButShtViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButShtNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButBoxViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButBoxNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
