/**
	* \file QryWznmVisLinkctx.h
	* job handler for job QryWznmVisLinkctx (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef QRYWZNMVISLINKCTX_H
#define QRYWZNMVISLINKCTX_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatShrQryWznmVisLinkctx QryWznmVisLinkctx::StatShr
#define StgIacQryWznmVisLinkctx QryWznmVisLinkctx::StgIac

/**
	* QryWznmVisLinkctx
	*/
class QryWznmVisLinkctx : public JobWznm {

public:
	/**
		* StatShr (full: StatShrQryWznmVisLinkctx)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint NTOT = 1;

	public:
		StatShr(const Sbecore::uint ntot = 0);

	public:
		Sbecore::uint ntot;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryWznmVisLinkctx)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint JNUM = 1;

	public:
		StgIac(const Sbecore::uint jnum = 0);

	public:
		Sbecore::uint jnum;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryWznmVisLinkctx(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~QryWznmVisLinkctx();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWznmQVisLinkctx rst;

	Sbecore::uint ixWznmVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWznm* dbswznm, const bool call = false);

	void fetch(DbsWznm* dbswznm);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WznmQVisLinkctx* getRecByJnum(const Sbecore::uint jnum);

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

};

#endif
