/**
	* \file WznmAMOppackRetval.h
	* database access for table TblWznmAMOppackRetval (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMOPPACKRETVAL_H
#define WZNMAMOPPACKRETVAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMOppackRetval: record of TblWznmAMOppackRetval
	*/
class WznmAMOppackRetval {

public:
	WznmAMOppackRetval(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmCAMOppackRetval = 0, const Sbecore::ubigint opkRefWznmMOppack = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmCAMOppackRetval;
	Sbecore::ubigint opkRefWznmMOppack;
	Sbecore::uint opkNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	std::string Comment;

public:
	bool operator==(const WznmAMOppackRetval& comp);
	bool operator!=(const WznmAMOppackRetval& comp);
};

/**
	* ListWznmAMOppackRetval: recordset of TblWznmAMOppackRetval
	*/
class ListWznmAMOppackRetval {

public:
	ListWznmAMOppackRetval();
	ListWznmAMOppackRetval(const ListWznmAMOppackRetval& src);
	~ListWznmAMOppackRetval();

	void clear();
	unsigned int size() const;
	void append(WznmAMOppackRetval* rec);

	WznmAMOppackRetval* operator[](const Sbecore::uint ix);
	ListWznmAMOppackRetval& operator=(const ListWznmAMOppackRetval& src);
	bool operator==(const ListWznmAMOppackRetval& comp);
	bool operator!=(const ListWznmAMOppackRetval& comp);

public:
	std::vector<WznmAMOppackRetval*> nodes;
};

/**
	* TblWznmAMOppackRetval: C++ wrapper for table TblWznmAMOppackRetval
	*/
class TblWznmAMOppackRetval {

public:

public:
	TblWznmAMOppackRetval();
	virtual ~TblWznmAMOppackRetval();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMOppackRetval** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOppackRetval& rst);

	virtual Sbecore::ubigint insertRec(WznmAMOppackRetval* rec);
	Sbecore::ubigint insertNewRec(WznmAMOppackRetval** rec = NULL, const Sbecore::ubigint refWznmCAMOppackRetval = 0, const Sbecore::ubigint opkRefWznmMOppack = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMOppackRetval& rst, WznmAMOppackRetval** rec = NULL, const Sbecore::ubigint refWznmCAMOppackRetval = 0, const Sbecore::ubigint opkRefWznmMOppack = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmAMOppackRetval& rst, bool transact = false);
	virtual void updateRec(WznmAMOppackRetval* rec);
	virtual void updateRst(ListWznmAMOppackRetval& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMOppackRetval** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOppackRetval, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOppackRetval, const bool append, ListWznmAMOppackRetval& rst);
	virtual Sbecore::ubigint loadRstByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, ListWznmAMOppackRetval& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMOppackRetval& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMOppackRetval: C++ wrapper for table TblWznmAMOppackRetval (MySQL database)
	*/
class MyTblWznmAMOppackRetval : public TblWznmAMOppackRetval, public Sbecore::MyTable {

public:
	MyTblWznmAMOppackRetval();
	~MyTblWznmAMOppackRetval();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMOppackRetval** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOppackRetval& rst);

	Sbecore::ubigint insertRec(WznmAMOppackRetval* rec);
	void insertRst(ListWznmAMOppackRetval& rst, bool transact = false);
	void updateRec(WznmAMOppackRetval* rec);
	void updateRst(ListWznmAMOppackRetval& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMOppackRetval** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOppackRetval, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOppackRetval, const bool append, ListWznmAMOppackRetval& rst);
	Sbecore::ubigint loadRstByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, ListWznmAMOppackRetval& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMOppackRetval: C++ wrapper for table TblWznmAMOppackRetval (PgSQL database)
	*/
class PgTblWznmAMOppackRetval : public TblWznmAMOppackRetval, public Sbecore::PgTable {

public:
	PgTblWznmAMOppackRetval();
	~PgTblWznmAMOppackRetval();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMOppackRetval** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMOppackRetval& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMOppackRetval** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMOppackRetval& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMOppackRetval** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOppackRetval& rst);

	Sbecore::ubigint insertRec(WznmAMOppackRetval* rec);
	void insertRst(ListWznmAMOppackRetval& rst, bool transact = false);
	void updateRec(WznmAMOppackRetval* rec);
	void updateRst(ListWznmAMOppackRetval& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMOppackRetval** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOppackRetval, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOppackRetval, const bool append, ListWznmAMOppackRetval& rst);
	Sbecore::ubigint loadRstByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, ListWznmAMOppackRetval& rst);
};
#endif

#endif

