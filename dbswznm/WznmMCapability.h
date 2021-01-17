/**
	* \file WznmMCapability.h
	* database access for table TblWznmMCapability (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMCAPABILITY_H
#define WZNMMCAPABILITY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmWMCapabilityArtefact TblWznmMCapability::VecWArtefact
#define VecWznmWMCapabilitySubset TblWznmMCapability::VecWSubset

/**
	* WznmMCapability: record of TblWznmMCapability
	*/
class WznmMCapability {

public:
	WznmMCapability(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint tplRefWznmMCapability = 0, const std::string sref = "", const Sbecore::uint ixWArtefact = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::ubigint tplRefWznmMCapability;
	std::string sref;
	Sbecore::uint ixWArtefact;
	std::string Title;

public:
	bool operator==(const WznmMCapability& comp);
	bool operator!=(const WznmMCapability& comp);
};

/**
	* ListWznmMCapability: recordset of TblWznmMCapability
	*/
class ListWznmMCapability {

public:
	ListWznmMCapability();
	ListWznmMCapability(const ListWznmMCapability& src);
	~ListWznmMCapability();

	void clear();
	unsigned int size() const;
	void append(WznmMCapability* rec);

	WznmMCapability* operator[](const Sbecore::uint ix);
	ListWznmMCapability& operator=(const ListWznmMCapability& src);
	bool operator==(const ListWznmMCapability& comp);
	bool operator!=(const ListWznmMCapability& comp);

public:
	std::vector<WznmMCapability*> nodes;
};

/**
	* TblWznmMCapability: C++ wrapper for table TblWznmMCapability
	*/
class TblWznmMCapability {

public:
	/**
		* VecWArtefact (full: VecWznmWMCapabilityArtefact)
		*/
	class VecWArtefact {

	public:
		static const Sbecore::uint DBS = 1;
		static const Sbecore::uint BUI = 2;
		static const Sbecore::uint IEX = 4;
		static const Sbecore::uint SRVGBLCODE = 8;
		static const Sbecore::uint SRVJOBCODE = 16;
		static const Sbecore::uint WEBGBLCODE = 32;
		static const Sbecore::uint WEBJOBCODE = 64;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWSubset (full: VecWznmWMCapabilitySubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSWZNMBMCAPABILITYCAP = 1;
		static const Sbecore::uint SBSWZNMBMCAPABILITYCTP = 2;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

public:
	TblWznmMCapability();
	virtual ~TblWznmMCapability();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMCapability** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCapability& rst);

	virtual Sbecore::ubigint insertRec(WznmMCapability* rec);
	Sbecore::ubigint insertNewRec(WznmMCapability** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint tplRefWznmMCapability = 0, const std::string sref = "", const Sbecore::uint ixWArtefact = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMCapability& rst, WznmMCapability** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint tplRefWznmMCapability = 0, const std::string sref = "", const Sbecore::uint ixWArtefact = 0, const std::string Title = "");
	virtual void insertRst(ListWznmMCapability& rst, bool transact = false);
	virtual void updateRec(WznmMCapability* rec);
	virtual void updateRst(ListWznmMCapability& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMCapability** rec);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMCapability& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMCapability& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMCapability: C++ wrapper for table TblWznmMCapability (MySQL database)
	*/
class MyTblWznmMCapability : public TblWznmMCapability, public Sbecore::MyTable {

public:
	MyTblWznmMCapability();
	~MyTblWznmMCapability();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMCapability** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCapability& rst);

	Sbecore::ubigint insertRec(WznmMCapability* rec);
	void insertRst(ListWznmMCapability& rst, bool transact = false);
	void updateRec(WznmMCapability* rec);
	void updateRst(ListWznmMCapability& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMCapability** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMCapability& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMCapability: C++ wrapper for table TblWznmMCapability (PgSQL database)
	*/
class PgTblWznmMCapability : public TblWznmMCapability, public Sbecore::PgTable {

public:
	PgTblWznmMCapability();
	~PgTblWznmMCapability();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMCapability** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMCapability& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMCapability** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMCapability& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMCapability** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCapability& rst);

	Sbecore::ubigint insertRec(WznmMCapability* rec);
	void insertRst(ListWznmMCapability& rst, bool transact = false);
	void updateRec(WznmMCapability* rec);
	void updateRst(ListWznmMCapability& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMCapability** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMCapability& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
