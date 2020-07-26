/**
	* \file PnlWznmNavAppdev.h
	* job handler for job PnlWznmNavAppdev (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMNAVAPPDEV_H
#define PNLWZNMNAVAPPDEV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

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
class PnlWznmNavAppdev : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavAppdevDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTAPPVIEWCLICK = 1;
		static const Sbecore::uint BUTAPPNEWCRDCLICK = 2;
		static const Sbecore::uint BUTRTJVIEWCLICK = 3;
		static const Sbecore::uint BUTRTJNEWCRDCLICK = 4;
		static const Sbecore::uint BUTSEQVIEWCLICK = 5;
		static const Sbecore::uint BUTSEQNEWCRDCLICK = 6;
		static const Sbecore::uint BUTSTEVIEWCLICK = 7;
		static const Sbecore::uint BUTSTENEWCRDCLICK = 8;

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
		static const Sbecore::uint NUMFLSTSEQ = 3;
		static const Sbecore::uint NUMFLSTSTE = 4;

	public:
		ContIac(const Sbecore::uint numFLstApp = 1, const Sbecore::uint numFLstRtj = 1, const Sbecore::uint numFLstSeq = 1, const Sbecore::uint numFLstSte = 1);

	public:
		Sbecore::uint numFLstApp;
		Sbecore::uint numFLstRtj;
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
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool LstAppAlt = true, const bool LstRtjAlt = true, const bool LstSeqAlt = true, const bool LstSteAlt = true, const Sbecore::uint LstAppNumFirstdisp = 1, const Sbecore::uint LstRtjNumFirstdisp = 1, const Sbecore::uint LstSeqNumFirstdisp = 1, const Sbecore::uint LstSteNumFirstdisp = 1);
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
		static const Sbecore::uint LSTSEQAVAIL = 6;
		static const Sbecore::uint BUTSEQVIEWACTIVE = 7;
		static const Sbecore::uint BUTSEQNEWCRDACTIVE = 8;
		static const Sbecore::uint LSTSTEAVAIL = 9;
		static const Sbecore::uint BUTSTEVIEWACTIVE = 10;
		static const Sbecore::uint BUTSTENEWCRDACTIVE = 11;

	public:
		StatShr(const bool LstAppAvail = true, const bool ButAppViewActive = true, const bool LstRtjAvail = true, const bool ButRtjViewActive = true, const bool ButRtjNewcrdActive = true, const bool LstSeqAvail = true, const bool ButSeqViewActive = true, const bool ButSeqNewcrdActive = true, const bool LstSteAvail = true, const bool ButSteViewActive = true, const bool ButSteNewcrdActive = true);

	public:
		bool LstAppAvail;
		bool ButAppViewActive;
		bool LstRtjAvail;
		bool ButRtjViewActive;
		bool ButRtjNewcrdActive;
		bool LstSeqAvail;
		bool ButSeqViewActive;
		bool ButSeqNewcrdActive;
		bool LstSteAvail;
		bool ButSteViewActive;
		bool ButSteNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavAppdev)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmNavAppdevData)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavAppdevDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmNavAppdevData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTAPP = 3;
		static const Sbecore::uint FEEDFLSTRTJ = 4;
		static const Sbecore::uint FEEDFLSTSEQ = 5;
		static const Sbecore::uint FEEDFLSTSTE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstApp = NULL, Sbecore::Xmlio::Feed* feedFLstRtj = NULL, Sbecore::Xmlio::Feed* feedFLstSeq = NULL, Sbecore::Xmlio::Feed* feedFLstSte = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstApp;
		Sbecore::Xmlio::Feed feedFLstRtj;
		Sbecore::Xmlio::Feed feedFLstSeq;
		Sbecore::Xmlio::Feed feedFLstSte;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalLstAppAvail(DbsWznm* dbswznm);
	bool evalButAppViewActive(DbsWznm* dbswznm);
	bool evalLstRtjAvail(DbsWznm* dbswznm);
	bool evalButRtjViewActive(DbsWznm* dbswznm);
	bool evalButRtjNewcrdActive(DbsWznm* dbswznm);
	bool evalLstSeqAvail(DbsWznm* dbswznm);
	bool evalButSeqViewActive(DbsWznm* dbswznm);
	bool evalButSeqNewcrdActive(DbsWznm* dbswznm);
	bool evalLstSteAvail(DbsWznm* dbswznm);
	bool evalButSteViewActive(DbsWznm* dbswznm);
	bool evalButSteNewcrdActive(DbsWznm* dbswznm);

public:
	PnlWznmNavAppdev(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavAppdev();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstApp;
	Sbecore::Xmlio::Feed feedFLstRtj;
	Sbecore::Xmlio::Feed feedFLstSeq;
	Sbecore::Xmlio::Feed feedFLstSte;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstApp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshApp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstRtj(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRtj(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstSeq(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshSeq(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshLstSte(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshSte(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButAppViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButAppNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRtjViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRtjNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSeqViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSeqNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSteViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButSteNewcrdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmHusrRunvMod_crdUsrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif

