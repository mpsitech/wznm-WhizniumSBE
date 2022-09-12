/**
	* \file QryWznmMchList.h
	* job handler for job QryWznmMchList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef QRYWZNMMCHLIST_H
#define QRYWZNMMCHLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryWznmMchListOrd QryWznmMchList::VecVOrd

#define StatAppQryWznmMchList QryWznmMchList::StatApp
#define StatShrQryWznmMchList QryWznmMchList::StatShr
#define StgIacQryWznmMchList QryWznmMchList::StgIac

/**
	* QryWznmMchList
	*/
class QryWznmMchList : public JobWznm {

public:
	/**
		* VecVOrd (full: VecVQryWznmMchListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint SUP = 1;
		static const Sbecore::uint SRF = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryWznmMchList)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 2, const Sbecore::uint ndisp = 25);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 2, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryWznmMchList)
		*/
	class StatShr : public Sbecore::Block {

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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryWznmMchList)
		*/
	class StgIac : public Sbecore::Block {

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
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryWznmMchList(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~QryWznmMchList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWznmQMchList rst;

	Sbecore::uint ixWznmVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWznm* dbswznm, const bool call = false);
	void rerun_filtSQL(std::string& sqlstr, const std::string& preSrf, const Sbecore::ubigint preSup, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsWznm* dbswznm);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WznmQMchList* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:
	bool handleRerun(DbsWznm* dbswznm);
	bool handleShow(DbsWznm* dbswznm);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmMchUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmMchMod(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmStubChgFromSelf(DbsWznm* dbswznm);

};

#endif
