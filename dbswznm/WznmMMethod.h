/**
	* \file WznmMMethod.h
	* database access for table TblWznmMMethod (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMMETHOD_H
#define WZNMMMETHOD_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMMethod: record of TblWznmMMethod
	*/
class WznmMMethod {

public:
	WznmMMethod(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const bool Execsrv = false, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMJob;
	std::string sref;
	bool Execsrv;
	std::string Comment;

public:
	bool operator==(const WznmMMethod& comp);
	bool operator!=(const WznmMMethod& comp);
};

/**
	* ListWznmMMethod: recordset of TblWznmMMethod
	*/
class ListWznmMMethod {

public:
	ListWznmMMethod();
	ListWznmMMethod(const ListWznmMMethod& src);
	~ListWznmMMethod();

	void clear();
	unsigned int size() const;
	void append(WznmMMethod* rec);

	WznmMMethod* operator[](const Sbecore::uint ix);
	ListWznmMMethod& operator=(const ListWznmMMethod& src);
	bool operator==(const ListWznmMMethod& comp);
	bool operator!=(const ListWznmMMethod& comp);

public:
	std::vector<WznmMMethod*> nodes;
};

/**
	* TblWznmMMethod: C++ wrapper for table TblWznmMMethod
	*/
class TblWznmMMethod {

public:

public:
	TblWznmMMethod();
	virtual ~TblWznmMMethod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMMethod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMMethod& rst);

	virtual Sbecore::ubigint insertRec(WznmMMethod* rec);
	Sbecore::ubigint insertNewRec(WznmMMethod** rec = NULL, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const bool Execsrv = false, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMMethod& rst, WznmMMethod** rec = NULL, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const bool Execsrv = false, const std::string Comment = "");
	virtual void insertRst(ListWznmMMethod& rst, bool transact = false);
	virtual void updateRec(WznmMMethod* rec);
	virtual void updateRst(ListWznmMMethod& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMMethod** rec);
	virtual Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWznmMJob, const bool append, ListWznmMMethod& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMMethod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMMethod: C++ wrapper for table TblWznmMMethod (MySQL database)
	*/
class MyTblWznmMMethod : public TblWznmMMethod, public Sbecore::MyTable {

public:
	MyTblWznmMMethod();
	~MyTblWznmMMethod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMMethod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMMethod& rst);

	Sbecore::ubigint insertRec(WznmMMethod* rec);
	void insertRst(ListWznmMMethod& rst, bool transact = false);
	void updateRec(WznmMMethod* rec);
	void updateRst(ListWznmMMethod& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMMethod** rec);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWznmMJob, const bool append, ListWznmMMethod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMMethod: C++ wrapper for table TblWznmMMethod (PgSQL database)
	*/
class PgTblWznmMMethod : public TblWznmMMethod, public Sbecore::PgTable {

public:
	PgTblWznmMMethod();
	~PgTblWznmMMethod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMMethod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMMethod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMMethod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMMethod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMMethod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMMethod& rst);

	Sbecore::ubigint insertRec(WznmMMethod* rec);
	void insertRst(ListWznmMMethod& rst, bool transact = false);
	void updateRec(WznmMMethod* rec);
	void updateRst(ListWznmMMethod& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMMethod** rec);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWznmMJob, const bool append, ListWznmMMethod& rst);
};
#endif

#endif

