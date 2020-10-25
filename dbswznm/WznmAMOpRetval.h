/**
	* \file WznmAMOpRetval.h
	* database access for table TblWznmAMOpRetval (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMAMOPRETVAL_H
#define WZNMAMOPRETVAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMOpRetval: record of TblWznmAMOpRetval
	*/
class WznmAMOpRetval {

public:
	WznmAMOpRetval(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmCAMOpRetval = 0, const Sbecore::ubigint opxRefWznmMOp = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmCAMOpRetval;
	Sbecore::ubigint opxRefWznmMOp;
	Sbecore::uint opxNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	std::string Comment;

public:
	bool operator==(const WznmAMOpRetval& comp);
	bool operator!=(const WznmAMOpRetval& comp);
};

/**
	* ListWznmAMOpRetval: recordset of TblWznmAMOpRetval
	*/
class ListWznmAMOpRetval {

public:
	ListWznmAMOpRetval();
	ListWznmAMOpRetval(const ListWznmAMOpRetval& src);
	~ListWznmAMOpRetval();

	void clear();
	unsigned int size() const;
	void append(WznmAMOpRetval* rec);

	WznmAMOpRetval* operator[](const Sbecore::uint ix);
	ListWznmAMOpRetval& operator=(const ListWznmAMOpRetval& src);
	bool operator==(const ListWznmAMOpRetval& comp);
	bool operator!=(const ListWznmAMOpRetval& comp);

public:
	std::vector<WznmAMOpRetval*> nodes;
};

/**
	* TblWznmAMOpRetval: C++ wrapper for table TblWznmAMOpRetval
	*/
class TblWznmAMOpRetval {

public:

public:
	TblWznmAMOpRetval();
	virtual ~TblWznmAMOpRetval();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMOpRetval** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOpRetval& rst);

	virtual Sbecore::ubigint insertRec(WznmAMOpRetval* rec);
	Sbecore::ubigint insertNewRec(WznmAMOpRetval** rec = NULL, const Sbecore::ubigint refWznmCAMOpRetval = 0, const Sbecore::ubigint opxRefWznmMOp = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMOpRetval& rst, WznmAMOpRetval** rec = NULL, const Sbecore::ubigint refWznmCAMOpRetval = 0, const Sbecore::ubigint opxRefWznmMOp = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmAMOpRetval& rst, bool transact = false);
	virtual void updateRec(WznmAMOpRetval* rec);
	virtual void updateRst(ListWznmAMOpRetval& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMOpRetval** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOpRetval, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOpRetval, const bool append, ListWznmAMOpRetval& rst);
	virtual Sbecore::ubigint loadRstByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, ListWznmAMOpRetval& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMOpRetval& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMOpRetval: C++ wrapper for table TblWznmAMOpRetval (MySQL database)
	*/
class MyTblWznmAMOpRetval : public TblWznmAMOpRetval, public Sbecore::MyTable {

public:
	MyTblWznmAMOpRetval();
	~MyTblWznmAMOpRetval();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMOpRetval** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOpRetval& rst);

	Sbecore::ubigint insertRec(WznmAMOpRetval* rec);
	void insertRst(ListWznmAMOpRetval& rst, bool transact = false);
	void updateRec(WznmAMOpRetval* rec);
	void updateRst(ListWznmAMOpRetval& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMOpRetval** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOpRetval, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOpRetval, const bool append, ListWznmAMOpRetval& rst);
	Sbecore::ubigint loadRstByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, ListWznmAMOpRetval& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMOpRetval: C++ wrapper for table TblWznmAMOpRetval (PgSQL database)
	*/
class PgTblWznmAMOpRetval : public TblWznmAMOpRetval, public Sbecore::PgTable {

public:
	PgTblWznmAMOpRetval();
	~PgTblWznmAMOpRetval();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMOpRetval** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMOpRetval& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMOpRetval** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMOpRetval& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMOpRetval** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOpRetval& rst);

	Sbecore::ubigint insertRec(WznmAMOpRetval* rec);
	void insertRst(ListWznmAMOpRetval& rst, bool transact = false);
	void updateRec(WznmAMOpRetval* rec);
	void updateRst(ListWznmAMOpRetval& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMOpRetval** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOpRetval, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOpRetval, const bool append, ListWznmAMOpRetval& rst);
	Sbecore::ubigint loadRstByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, ListWznmAMOpRetval& rst);
};
#endif

#endif

