/**
	* \file PnlWznmNavPre.h
	* job handler for job PnlWznmNavPre (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMNAVPRE_H
#define PNLWZNMNAVPRE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmNavPreDo PnlWznmNavPre::VecVDo

#define ContInfWznmNavPre PnlWznmNavPre::ContInf
#define StatShrWznmNavPre PnlWznmNavPre::StatShr
#define TagWznmNavPre PnlWznmNavPre::Tag

#define DpchAppWznmNavPreDo PnlWznmNavPre::DpchAppDo
#define DpchEngWznmNavPreData PnlWznmNavPre::DpchEngData

/**
	* PnlWznmNavPre
	*/
class PnlWznmNavPre : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmNavPreDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTAPPREMOVECLICK = 1;
		static const Sbecore::uint BUTVERREMOVECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmNavPre)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTAPP = 1;
		static const Sbecore::uint TXTVER = 2;

	public:
		ContInf(const std::string& TxtApp = "", const std::string& TxtVer = "");

	public:
		std::string TxtApp;
		std::string TxtVer;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWznmNavPre)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTAPPAVAIL = 1;
		static const Sbecore::uint TXTVERAVAIL = 2;

	public:
		StatShr(const bool TxtAppAvail = true, const bool TxtVerAvail = true);

	public:
		bool TxtAppAvail;
		bool TxtVerAvail;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmNavPre)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmNavPreDo)
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
		* DpchEngData (full: DpchEngWznmNavPreData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalTxtAppAvail(DbsWznm* dbswznm);
	bool evalTxtVerAvail(DbsWznm* dbswznm);

public:
	PnlWznmNavPre(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmNavPre();

public:
	ContInf continf;
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

	void handleDpchAppDoButAppRemoveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButVerRemoveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

};

#endif
