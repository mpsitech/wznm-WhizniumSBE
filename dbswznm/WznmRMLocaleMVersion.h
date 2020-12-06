/**
	* \file WznmRMLocaleMVersion.h
	* database access for table TblWznmRMLocaleMVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMLOCALEMVERSION_H
#define WZNMRMLOCALEMVERSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMLocaleMVersion: record of TblWznmRMLocaleMVersion
	*/
class WznmRMLocaleMVersion {

public:
	WznmRMLocaleMVersion(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMLocale = 0, const Sbecore::ubigint refWznmMVersion = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMLocale;
	Sbecore::ubigint refWznmMVersion;

public:
	bool operator==(const WznmRMLocaleMVersion& comp);
	bool operator!=(const WznmRMLocaleMVersion& comp);
};

/**
	* ListWznmRMLocaleMVersion: recordset of TblWznmRMLocaleMVersion
	*/
class ListWznmRMLocaleMVersion {

public:
	ListWznmRMLocaleMVersion();
	ListWznmRMLocaleMVersion(const ListWznmRMLocaleMVersion& src);
	~ListWznmRMLocaleMVersion();

	void clear();
	unsigned int size() const;
	void append(WznmRMLocaleMVersion* rec);

	WznmRMLocaleMVersion* operator[](const Sbecore::uint ix);
	ListWznmRMLocaleMVersion& operator=(const ListWznmRMLocaleMVersion& src);
	bool operator==(const ListWznmRMLocaleMVersion& comp);
	bool operator!=(const ListWznmRMLocaleMVersion& comp);

public:
	std::vector<WznmRMLocaleMVersion*> nodes;
};

/**
	* TblWznmRMLocaleMVersion: C++ wrapper for table TblWznmRMLocaleMVersion
	*/
class TblWznmRMLocaleMVersion {

public:

public:
	TblWznmRMLocaleMVersion();
	virtual ~TblWznmRMLocaleMVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMLocaleMVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMLocaleMVersion& rst);

	virtual Sbecore::ubigint insertRec(WznmRMLocaleMVersion* rec);
	Sbecore::ubigint insertNewRec(WznmRMLocaleMVersion** rec = NULL, const Sbecore::ubigint refWznmMLocale = 0, const Sbecore::ubigint refWznmMVersion = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMLocaleMVersion& rst, WznmRMLocaleMVersion** rec = NULL, const Sbecore::ubigint refWznmMLocale = 0, const Sbecore::ubigint refWznmMVersion = 0);
	virtual void insertRst(ListWznmRMLocaleMVersion& rst, bool transact = false);
	virtual void updateRec(WznmRMLocaleMVersion* rec);
	virtual void updateRst(ListWznmRMLocaleMVersion& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMLocaleMVersion** rec);
	virtual Sbecore::ubigint loadLocsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refWznmMLocales);
	virtual Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadVersByLoc(Sbecore::ubigint refWznmMLocale, const bool append, std::vector<Sbecore::ubigint>& refWznmMVersions);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMLocaleMVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMLocaleMVersion: C++ wrapper for table TblWznmRMLocaleMVersion (MySQL database)
	*/
class MyTblWznmRMLocaleMVersion : public TblWznmRMLocaleMVersion, public Sbecore::MyTable {

public:
	MyTblWznmRMLocaleMVersion();
	~MyTblWznmRMLocaleMVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMLocaleMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMLocaleMVersion& rst);

	Sbecore::ubigint insertRec(WznmRMLocaleMVersion* rec);
	void insertRst(ListWznmRMLocaleMVersion& rst, bool transact = false);
	void updateRec(WznmRMLocaleMVersion* rec);
	void updateRst(ListWznmRMLocaleMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMLocaleMVersion** rec);
	Sbecore::ubigint loadLocsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refWznmMLocales);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadVersByLoc(Sbecore::ubigint refWznmMLocale, const bool append, std::vector<Sbecore::ubigint>& refWznmMVersions);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMLocaleMVersion: C++ wrapper for table TblWznmRMLocaleMVersion (PgSQL database)
	*/
class PgTblWznmRMLocaleMVersion : public TblWznmRMLocaleMVersion, public Sbecore::PgTable {

public:
	PgTblWznmRMLocaleMVersion();
	~PgTblWznmRMLocaleMVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMLocaleMVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMLocaleMVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMLocaleMVersion** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMLocaleMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMLocaleMVersion& rst);

	Sbecore::ubigint insertRec(WznmRMLocaleMVersion* rec);
	void insertRst(ListWznmRMLocaleMVersion& rst, bool transact = false);
	void updateRec(WznmRMLocaleMVersion* rec);
	void updateRst(ListWznmRMLocaleMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMLocaleMVersion** rec);
	Sbecore::ubigint loadLocsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refWznmMLocales);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadVersByLoc(Sbecore::ubigint refWznmMLocale, const bool append, std::vector<Sbecore::ubigint>& refWznmMVersions);
};
#endif

#endif
