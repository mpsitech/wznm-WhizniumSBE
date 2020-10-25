/**
	* \file PnlWznmMtyHeadbar.h
	* job handler for job PnlWznmMtyHeadbar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMMTYHEADBAR_H
#define PNLWZNMMTYHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StgInfWznmMtyHeadbar PnlWznmMtyHeadbar::StgInf
#define TagWznmMtyHeadbar PnlWznmMtyHeadbar::Tag

#define DpchEngWznmMtyHeadbarData PnlWznmMtyHeadbar::DpchEngData

/**
	* PnlWznmMtyHeadbar
	*/
class PnlWznmMtyHeadbar : public JobWznm {

public:
	/**
		* StgInf (full: StgInfWznmMtyHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWznmMtyHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWznmMtyHeadbarData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGINF = 2;
		static const Sbecore::uint TAG = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

public:
	PnlWznmMtyHeadbar(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmMtyHeadbar();

public:

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

};

#endif

