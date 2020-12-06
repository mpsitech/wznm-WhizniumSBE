/**
	* \file WznmAMJobVar.h
	* database access for table TblWznmAMJobVar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMJOBVAR_H
#define WZNMAMJOBVAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMJobVar: record of TblWznmAMJobVar
	*/
class WznmAMJobVar {

public:
	WznmAMJobVar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmCAMJobVar = 0, const Sbecore::ubigint jobRefWznmMJob = 0, const Sbecore::uint jobNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint Length = 0, const bool Shr = false, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmCAMJobVar;
	Sbecore::ubigint jobRefWznmMJob;
	Sbecore::uint jobNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	Sbecore::uint Length;
	bool Shr;
	std::string Comment;

public:
	bool operator==(const WznmAMJobVar& comp);
	bool operator!=(const WznmAMJobVar& comp);
};

/**
	* ListWznmAMJobVar: recordset of TblWznmAMJobVar
	*/
class ListWznmAMJobVar {

public:
	ListWznmAMJobVar();
	ListWznmAMJobVar(const ListWznmAMJobVar& src);
	~ListWznmAMJobVar();

	void clear();
	unsigned int size() const;
	void append(WznmAMJobVar* rec);

	WznmAMJobVar* operator[](const Sbecore::uint ix);
	ListWznmAMJobVar& operator=(const ListWznmAMJobVar& src);
	bool operator==(const ListWznmAMJobVar& comp);
	bool operator!=(const ListWznmAMJobVar& comp);

public:
	std::vector<WznmAMJobVar*> nodes;
};

/**
	* TblWznmAMJobVar: C++ wrapper for table TblWznmAMJobVar
	*/
class TblWznmAMJobVar {

public:

public:
	TblWznmAMJobVar();
	virtual ~TblWznmAMJobVar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMJobVar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMJobVar& rst);

	virtual Sbecore::ubigint insertRec(WznmAMJobVar* rec);
	Sbecore::ubigint insertNewRec(WznmAMJobVar** rec = NULL, const Sbecore::ubigint refWznmCAMJobVar = 0, const Sbecore::ubigint jobRefWznmMJob = 0, const Sbecore::uint jobNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint Length = 0, const bool Shr = false, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMJobVar& rst, WznmAMJobVar** rec = NULL, const Sbecore::ubigint refWznmCAMJobVar = 0, const Sbecore::ubigint jobRefWznmMJob = 0, const Sbecore::uint jobNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint Length = 0, const bool Shr = false, const std::string Comment = "");
	virtual void insertRst(ListWznmAMJobVar& rst, bool transact = false);
	virtual void updateRec(WznmAMJobVar* rec);
	virtual void updateRst(ListWznmAMJobVar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMJobVar** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMJobVar, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMJobVar, const bool append, ListWznmAMJobVar& rst);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, ListWznmAMJobVar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMJobVar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMJobVar: C++ wrapper for table TblWznmAMJobVar (MySQL database)
	*/
class MyTblWznmAMJobVar : public TblWznmAMJobVar, public Sbecore::MyTable {

public:
	MyTblWznmAMJobVar();
	~MyTblWznmAMJobVar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMJobVar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMJobVar& rst);

	Sbecore::ubigint insertRec(WznmAMJobVar* rec);
	void insertRst(ListWznmAMJobVar& rst, bool transact = false);
	void updateRec(WznmAMJobVar* rec);
	void updateRst(ListWznmAMJobVar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMJobVar** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMJobVar, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMJobVar, const bool append, ListWznmAMJobVar& rst);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, ListWznmAMJobVar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMJobVar: C++ wrapper for table TblWznmAMJobVar (PgSQL database)
	*/
class PgTblWznmAMJobVar : public TblWznmAMJobVar, public Sbecore::PgTable {

public:
	PgTblWznmAMJobVar();
	~PgTblWznmAMJobVar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMJobVar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMJobVar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMJobVar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMJobVar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMJobVar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMJobVar& rst);

	Sbecore::ubigint insertRec(WznmAMJobVar* rec);
	void insertRst(ListWznmAMJobVar& rst, bool transact = false);
	void updateRec(WznmAMJobVar* rec);
	void updateRst(ListWznmAMJobVar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMJobVar** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMJobVar, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMJobVar, const bool append, ListWznmAMJobVar& rst);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, ListWznmAMJobVar& rst);
};
#endif

#endif
