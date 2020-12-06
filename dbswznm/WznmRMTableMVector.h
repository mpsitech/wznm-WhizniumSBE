/**
	* \file WznmRMTableMVector.h
	* database access for table TblWznmRMTableMVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMTABLEMVECTOR_H
#define WZNMRMTABLEMVECTOR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMTableMVector: record of TblWznmRMTableMVector
	*/
class WznmRMTableMVector {

public:
	WznmRMTableMVector(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::ubigint refWznmMVector = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMTable;
	Sbecore::ubigint refWznmMSubset;
	Sbecore::ubigint refWznmMVector;

public:
	bool operator==(const WznmRMTableMVector& comp);
	bool operator!=(const WznmRMTableMVector& comp);
};

/**
	* ListWznmRMTableMVector: recordset of TblWznmRMTableMVector
	*/
class ListWznmRMTableMVector {

public:
	ListWznmRMTableMVector();
	ListWznmRMTableMVector(const ListWznmRMTableMVector& src);
	~ListWznmRMTableMVector();

	void clear();
	unsigned int size() const;
	void append(WznmRMTableMVector* rec);

	WznmRMTableMVector* operator[](const Sbecore::uint ix);
	ListWznmRMTableMVector& operator=(const ListWznmRMTableMVector& src);
	bool operator==(const ListWznmRMTableMVector& comp);
	bool operator!=(const ListWznmRMTableMVector& comp);

public:
	std::vector<WznmRMTableMVector*> nodes;
};

/**
	* TblWznmRMTableMVector: C++ wrapper for table TblWznmRMTableMVector
	*/
class TblWznmRMTableMVector {

public:

public:
	TblWznmRMTableMVector();
	virtual ~TblWznmRMTableMVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMTableMVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMTableMVector& rst);

	virtual Sbecore::ubigint insertRec(WznmRMTableMVector* rec);
	Sbecore::ubigint insertNewRec(WznmRMTableMVector** rec = NULL, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::ubigint refWznmMVector = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMTableMVector& rst, WznmRMTableMVector** rec = NULL, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::ubigint refWznmMVector = 0);
	virtual void insertRst(ListWznmRMTableMVector& rst, bool transact = false);
	virtual void updateRec(WznmRMTableMVector* rec);
	virtual void updateRst(ListWznmRMTableMVector& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMTableMVector** rec);
	virtual Sbecore::ubigint loadRefsByVec(Sbecore::ubigint refWznmMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmRMTableMVector& rst);
	virtual Sbecore::ubigint loadRstByVec(Sbecore::ubigint refWznmMVector, const bool append, ListWznmRMTableMVector& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMTableMVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMTableMVector: C++ wrapper for table TblWznmRMTableMVector (MySQL database)
	*/
class MyTblWznmRMTableMVector : public TblWznmRMTableMVector, public Sbecore::MyTable {

public:
	MyTblWznmRMTableMVector();
	~MyTblWznmRMTableMVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMTableMVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMTableMVector& rst);

	Sbecore::ubigint insertRec(WznmRMTableMVector* rec);
	void insertRst(ListWznmRMTableMVector& rst, bool transact = false);
	void updateRec(WznmRMTableMVector* rec);
	void updateRst(ListWznmRMTableMVector& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMTableMVector** rec);
	Sbecore::ubigint loadRefsByVec(Sbecore::ubigint refWznmMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmRMTableMVector& rst);
	Sbecore::ubigint loadRstByVec(Sbecore::ubigint refWznmMVector, const bool append, ListWznmRMTableMVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMTableMVector: C++ wrapper for table TblWznmRMTableMVector (PgSQL database)
	*/
class PgTblWznmRMTableMVector : public TblWznmRMTableMVector, public Sbecore::PgTable {

public:
	PgTblWznmRMTableMVector();
	~PgTblWznmRMTableMVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMTableMVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMTableMVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMTableMVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmRMTableMVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMTableMVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMTableMVector& rst);

	Sbecore::ubigint insertRec(WznmRMTableMVector* rec);
	void insertRst(ListWznmRMTableMVector& rst, bool transact = false);
	void updateRec(WznmRMTableMVector* rec);
	void updateRst(ListWznmRMTableMVector& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMTableMVector** rec);
	Sbecore::ubigint loadRefsByVec(Sbecore::ubigint refWznmMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmRMTableMVector& rst);
	Sbecore::ubigint loadRstByVec(Sbecore::ubigint refWznmMVector, const bool append, ListWznmRMTableMVector& rst);
};
#endif

#endif
