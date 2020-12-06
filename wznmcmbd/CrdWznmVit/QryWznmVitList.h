/**
	* \file QryWznmVitList.h
	* job handler for job QryWznmVitList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef QRYWZNMVITLIST_H
#define QRYWZNMVITLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryWznmVitListOrd QryWznmVitList::VecVOrd

#define StatAppQryWznmVitList QryWznmVitList::StatApp
#define StatShrQryWznmVitList QryWznmVitList::StatShr
#define StgIacQryWznmVitList QryWznmVitList::StgIac

/**
	* QryWznmVitList
	*/
class QryWznmVitList : public JobWznm {

public:
	/**
		* VecVOrd (full: VecVQryWznmVitListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint VEC = 1;
		static const Sbecore::uint SRF = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryWznmVitList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 3, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryWznmVitList)
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
		* StgIac (full: StgIacQryWznmVitList)
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
	QryWznmVitList(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~QryWznmVitList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWznmQVitList rst;

	Sbecore::uint ixWznmVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWznm* dbswznm, const bool call = false);
	void rerun_baseSQL(std::string& sqlstr);
	void rerun_filtSQL(std::string& sqlstr, const std::string& preSrf, const Sbecore::ubigint preVec, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsWznm* dbswznm);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WznmQVitList* getRecByJnum(const Sbecore::uint jnum);

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
	bool handleCallWznmVitMod(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVitUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
