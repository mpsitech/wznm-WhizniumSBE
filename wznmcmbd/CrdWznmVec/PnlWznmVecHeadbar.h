/**
	* \file PnlWznmVecHeadbar.h
	* job handler for job PnlWznmVecHeadbar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMVECHEADBAR_H
#define PNLWZNMVECHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StgInfWznmVecHeadbar PnlWznmVecHeadbar::StgInf
#define TagWznmVecHeadbar PnlWznmVecHeadbar::Tag

#define DpchEngWznmVecHeadbarData PnlWznmVecHeadbar::DpchEngData

/**
	* PnlWznmVecHeadbar
	*/
class PnlWznmVecHeadbar : public JobWznm {

public:
	/**
		* StgInf (full: StgInfWznmVecHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWznmVecHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWznmVecHeadbarData)
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
	PnlWznmVecHeadbar(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmVecHeadbar();

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

