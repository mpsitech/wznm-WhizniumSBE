/**
	* \file QryWznmVecList.h
	* job handler for job QryWznmVecList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef QRYWZNMVECLIST_H
#define QRYWZNMVECLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryWznmVecListOrd QryWznmVecList::VecVOrd

#define StatAppQryWznmVecList QryWznmVecList::StatApp
#define StatShrQryWznmVecList QryWznmVecList::StatShr
#define StgIacQryWznmVecList QryWznmVecList::StgIac

/**
	* QryWznmVecList
	*/
class QryWznmVecList : public JobWznm {

public:
	/**
		* VecVOrd (full: VecVQryWznmVecListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint TGR = 1;
		static const Sbecore::uint HKU = 2;
		static const Sbecore::uint HKT = 3;
		static const Sbecore::uint VER = 4;
		static const Sbecore::uint TYP = 5;
		static const Sbecore::uint SRF = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryWznmVecList)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 9, const Sbecore::uint ndisp = 25);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 9, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryWznmVecList)
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
		* StgIac (full: StgIacQryWznmVecList)
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
	QryWznmVecList(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~QryWznmVecList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWznmQVecList rst;

	Sbecore::uint ixWznmVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWznm* dbswznm, const bool call = false);
	void rerun_baseSQL(std::string& sqlstr);
	void rerun_filtSQL(std::string& sqlstr, const std::string& preSrf, const Sbecore::uint preTyp, const Sbecore::ubigint preVer, const Sbecore::uint preHkt, const Sbecore::ubigint preHku, const std::string& preTgr, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsWznm* dbswznm);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WznmQVecList* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:
	bool handleRerun(DbsWznm* dbswznm);
	bool handleShow(DbsWznm* dbswznm);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmVecUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVecMod(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmStubChgFromSelf(DbsWznm* dbswznm);

};

#endif
