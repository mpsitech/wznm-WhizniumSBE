/**
	* \file QryWznmMtyAMakefile.h
	* job handler for job QryWznmMtyAMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef QRYWZNMMTYAMAKEFILE_H
#define QRYWZNMMTYAMAKEFILE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatAppQryWznmMtyAMakefile QryWznmMtyAMakefile::StatApp
#define StatShrQryWznmMtyAMakefile QryWznmMtyAMakefile::StatShr
#define StgIacQryWznmMtyAMakefile QryWznmMtyAMakefile::StgIac

/**
	* QryWznmMtyAMakefile
	*/
class QryWznmMtyAMakefile : public JobWznm {

public:
	/**
		* StatApp (full: StatAppQryWznmMtyAMakefile)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 3, const Sbecore::uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryWznmMtyAMakefile)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NTOT = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StatShr(const Sbecore::uint ntot = 0, const Sbecore::uint jnumFirstload = 0, const Sbecore::uint nload = 0);

	public:
		Sbecore::uint ntot;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryWznmMtyAMakefile)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JNUM = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StgIac(const Sbecore::uint jnum = 0, const Sbecore::uint jnumFirstload = 1, const Sbecore::uint nload = 100);

	public:
		Sbecore::uint jnum;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryWznmMtyAMakefile(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~QryWznmMtyAMakefile();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWznmQMtyAMakefile rst;

	Sbecore::uint ixWznmVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWznm* dbswznm, const bool call = false);
	void rerun_filtSQL(std::string& sqlstr, const std::string& preX1, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);

	void fetch(DbsWznm* dbswznm);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WznmQMtyAMakefile* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:
	bool handleRerun(DbsWznm* dbswznm);
	bool handleShow(DbsWznm* dbswznm);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmStubChgFromSelf(DbsWznm* dbswznm);
	bool handleCallWznmMtyAmkfMod_mtyEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif

