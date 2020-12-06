/**
	* \file WznmRMQueryMTable.h
	* database access for table TblWznmRMQueryMTable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMQUERYMTABLE_H
#define WZNMRMQUERYMTABLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMQueryMTable: record of TblWznmRMQueryMTable
	*/
class WznmRMQueryMTable {

public:
	WznmRMQueryMTable(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMQuery = 0, const Sbecore::ubigint refWznmMTable = 0, const bool Source = false, const std::string Prefix = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMQuery;
	Sbecore::ubigint refWznmMTable;
	bool Source;
	std::string Prefix;

public:
	bool operator==(const WznmRMQueryMTable& comp);
	bool operator!=(const WznmRMQueryMTable& comp);
};

/**
	* ListWznmRMQueryMTable: recordset of TblWznmRMQueryMTable
	*/
class ListWznmRMQueryMTable {

public:
	ListWznmRMQueryMTable();
	ListWznmRMQueryMTable(const ListWznmRMQueryMTable& src);
	~ListWznmRMQueryMTable();

	void clear();
	unsigned int size() const;
	void append(WznmRMQueryMTable* rec);

	WznmRMQueryMTable* operator[](const Sbecore::uint ix);
	ListWznmRMQueryMTable& operator=(const ListWznmRMQueryMTable& src);
	bool operator==(const ListWznmRMQueryMTable& comp);
	bool operator!=(const ListWznmRMQueryMTable& comp);

public:
	std::vector<WznmRMQueryMTable*> nodes;
};

/**
	* TblWznmRMQueryMTable: C++ wrapper for table TblWznmRMQueryMTable
	*/
class TblWznmRMQueryMTable {

public:

public:
	TblWznmRMQueryMTable();
	virtual ~TblWznmRMQueryMTable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMQueryMTable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMQueryMTable& rst);

	virtual Sbecore::ubigint insertRec(WznmRMQueryMTable* rec);
	Sbecore::ubigint insertNewRec(WznmRMQueryMTable** rec = NULL, const Sbecore::ubigint refWznmMQuery = 0, const Sbecore::ubigint refWznmMTable = 0, const bool Source = false, const std::string Prefix = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmRMQueryMTable& rst, WznmRMQueryMTable** rec = NULL, const Sbecore::ubigint refWznmMQuery = 0, const Sbecore::ubigint refWznmMTable = 0, const bool Source = false, const std::string Prefix = "");
	virtual void insertRst(ListWznmRMQueryMTable& rst, bool transact = false);
	virtual void updateRec(WznmRMQueryMTable* rec);
	virtual void updateRst(ListWznmRMQueryMTable& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMQueryMTable** rec);
	virtual Sbecore::ubigint loadRefsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByQry(Sbecore::ubigint refWznmMQuery, const bool append, ListWznmRMQueryMTable& rst);
	virtual Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmRMQueryMTable& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMQueryMTable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMQueryMTable: C++ wrapper for table TblWznmRMQueryMTable (MySQL database)
	*/
class MyTblWznmRMQueryMTable : public TblWznmRMQueryMTable, public Sbecore::MyTable {

public:
	MyTblWznmRMQueryMTable();
	~MyTblWznmRMQueryMTable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMQueryMTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMQueryMTable& rst);

	Sbecore::ubigint insertRec(WznmRMQueryMTable* rec);
	void insertRst(ListWznmRMQueryMTable& rst, bool transact = false);
	void updateRec(WznmRMQueryMTable* rec);
	void updateRst(ListWznmRMQueryMTable& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMQueryMTable** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint refWznmMQuery, const bool append, ListWznmRMQueryMTable& rst);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmRMQueryMTable& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMQueryMTable: C++ wrapper for table TblWznmRMQueryMTable (PgSQL database)
	*/
class PgTblWznmRMQueryMTable : public TblWznmRMQueryMTable, public Sbecore::PgTable {

public:
	PgTblWznmRMQueryMTable();
	~PgTblWznmRMQueryMTable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMQueryMTable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMQueryMTable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMQueryMTable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmRMQueryMTable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMQueryMTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMQueryMTable& rst);

	Sbecore::ubigint insertRec(WznmRMQueryMTable* rec);
	void insertRst(ListWznmRMQueryMTable& rst, bool transact = false);
	void updateRec(WznmRMQueryMTable* rec);
	void updateRst(ListWznmRMQueryMTable& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMQueryMTable** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint refWznmMQuery, const bool append, ListWznmRMQueryMTable& rst);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmRMQueryMTable& rst);
};
#endif

#endif
