/**
	* \file JobWznmIexJtr.h
	* job handler for job JobWznmIexJtr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZNMIEXJTR_H
#define JOBWZNMIEXJTR_H

#include "IexWznmJtr.h"

// IP include.cust --- INSERT

#define VecVJobWznmIexJtrSge JobWznmIexJtr::VecVSge

/**
	* JobWznmIexJtr
	*/
class JobWznmIexJtr : public JobWznm {

public:
	/**
		* VecVSge (full: VecVJobWznmIexJtrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PARSE = 2;
		static const Sbecore::uint PRSERR = 3;
		static const Sbecore::uint PRSDONE = 4;
		static const Sbecore::uint IMPORT = 5;
		static const Sbecore::uint IMPERR = 6;
		static const Sbecore::uint REVERSE = 7;
		static const Sbecore::uint COLLECT = 8;
		static const Sbecore::uint CLTDONE = 9;
		static const Sbecore::uint EXPORT = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

public:
	JobWznmIexJtr(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~JobWznmIexJtr();

public:

	std::string fullpath;
	bool xmlNotTxt;
	std::string rectpath;

	Sbecore::uint lineno;
	Sbecore::uint impcnt;

	std::map<Sbecore::uint,Sbecore::uint> icsWznmVIop;

	bool shorttags;

	IexWznmJtr::ImeIMBlock2 imeimblock2;
	IexWznmJtr::ImeIMCall imeimcall;
	IexWznmJtr::ImeIMJob imeimjob;
	IexWznmJtr::ImeIRMCallMStub imeirmcallmstub;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void reset(DbsWznm* dbswznm);

	void parseFromFile(DbsWznm* dbswznm, const std::string& _fullpath, const bool _xmlNotTxt, const std::string& _rectpath = "");
	void import(DbsWznm* dbswznm);
	void reverse(DbsWznm* dbswznm);
	void collect(DbsWznm* dbswznm, const std::map<Sbecore::uint,Sbecore::uint>& _icsWznmVIop = IexWznmJtr::icsWznmVIopInsAll());
	void exportToFile(DbsWznm* dbswznm, const std::string& _fullpath, const bool _xmlNotTxt, const bool _shorttags = true);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeParse(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeParse(DbsWznm* dbswznm);
	Sbecore::uint enterSgePrserr(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePrserr(DbsWznm* dbswznm);
	Sbecore::uint enterSgePrsdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgePrsdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeImport(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeImport(DbsWznm* dbswznm);
	Sbecore::uint enterSgeImperr(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeImperr(DbsWznm* dbswznm);
	Sbecore::uint enterSgeReverse(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeReverse(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCollect(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCollect(DbsWznm* dbswznm);
	Sbecore::uint enterSgeCltdone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeCltdone(DbsWznm* dbswznm);
	Sbecore::uint enterSgeExport(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeExport(DbsWznm* dbswznm);
	Sbecore::uint enterSgeDone(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeDone(DbsWznm* dbswznm);

};

#endif
