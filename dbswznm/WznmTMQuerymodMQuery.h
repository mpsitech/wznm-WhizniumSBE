/**
	* \file WznmTMQuerymodMQuery.h
	* database access for table TblWznmTMQuerymodMQuery (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMTMQUERYMODMQUERY_H
#define WZNMTMQUERYMODMQUERY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmTMQuerymodMQuery: record of TblWznmTMQuerymodMQuery
	*/
class WznmTMQuerymodMQuery {

public:
	WznmTMQuerymodMQuery(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMQuerymod = 0, const Sbecore::ubigint refR = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMQuerymod;
	Sbecore::ubigint refR;

public:
	bool operator==(const WznmTMQuerymodMQuery& comp);
	bool operator!=(const WznmTMQuerymodMQuery& comp);
};

/**
	* ListWznmTMQuerymodMQuery: recordset of TblWznmTMQuerymodMQuery
	*/
class ListWznmTMQuerymodMQuery {

public:
	ListWznmTMQuerymodMQuery();
	ListWznmTMQuerymodMQuery(const ListWznmTMQuerymodMQuery& src);
	~ListWznmTMQuerymodMQuery();

	void clear();
	unsigned int size() const;
	void append(WznmTMQuerymodMQuery* rec);

	WznmTMQuerymodMQuery* operator[](const Sbecore::uint ix);
	ListWznmTMQuerymodMQuery& operator=(const ListWznmTMQuerymodMQuery& src);
	bool operator==(const ListWznmTMQuerymodMQuery& comp);
	bool operator!=(const ListWznmTMQuerymodMQuery& comp);

public:
	std::vector<WznmTMQuerymodMQuery*> nodes;
};

/**
	* TblWznmTMQuerymodMQuery: C++ wrapper for table TblWznmTMQuerymodMQuery
	*/
class TblWznmTMQuerymodMQuery {

public:

public:
	TblWznmTMQuerymodMQuery();
	virtual ~TblWznmTMQuerymodMQuery();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmTMQuerymodMQuery** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmTMQuerymodMQuery& rst);

	virtual Sbecore::ubigint insertRec(WznmTMQuerymodMQuery* rec);
	Sbecore::ubigint insertNewRec(WznmTMQuerymodMQuery** rec = NULL, const Sbecore::ubigint refWznmMQuerymod = 0, const Sbecore::ubigint refR = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmTMQuerymodMQuery& rst, WznmTMQuerymodMQuery** rec = NULL, const Sbecore::ubigint refWznmMQuerymod = 0, const Sbecore::ubigint refR = 0);
	virtual void insertRst(ListWznmTMQuerymodMQuery& rst, bool transact = false);
	virtual void updateRec(WznmTMQuerymodMQuery* rec);
	virtual void updateRst(ListWznmTMQuerymodMQuery& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmTMQuerymodMQuery** rec);
	virtual Sbecore::ubigint loadRefsByR(Sbecore::ubigint refR, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByR(Sbecore::ubigint refR, const bool append, ListWznmTMQuerymodMQuery& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmTMQuerymodMQuery& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmTMQuerymodMQuery: C++ wrapper for table TblWznmTMQuerymodMQuery (MySQL database)
	*/
class MyTblWznmTMQuerymodMQuery : public TblWznmTMQuerymodMQuery, public Sbecore::MyTable {

public:
	MyTblWznmTMQuerymodMQuery();
	~MyTblWznmTMQuerymodMQuery();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmTMQuerymodMQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmTMQuerymodMQuery& rst);

	Sbecore::ubigint insertRec(WznmTMQuerymodMQuery* rec);
	void insertRst(ListWznmTMQuerymodMQuery& rst, bool transact = false);
	void updateRec(WznmTMQuerymodMQuery* rec);
	void updateRst(ListWznmTMQuerymodMQuery& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmTMQuerymodMQuery** rec);
	Sbecore::ubigint loadRefsByR(Sbecore::ubigint refR, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByR(Sbecore::ubigint refR, const bool append, ListWznmTMQuerymodMQuery& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmTMQuerymodMQuery: C++ wrapper for table TblWznmTMQuerymodMQuery (PgSQL database)
	*/
class PgTblWznmTMQuerymodMQuery : public TblWznmTMQuerymodMQuery, public Sbecore::PgTable {

public:
	PgTblWznmTMQuerymodMQuery();
	~PgTblWznmTMQuerymodMQuery();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmTMQuerymodMQuery** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmTMQuerymodMQuery& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmTMQuerymodMQuery** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmTMQuerymodMQuery& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmTMQuerymodMQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmTMQuerymodMQuery& rst);

	Sbecore::ubigint insertRec(WznmTMQuerymodMQuery* rec);
	void insertRst(ListWznmTMQuerymodMQuery& rst, bool transact = false);
	void updateRec(WznmTMQuerymodMQuery* rec);
	void updateRst(ListWznmTMQuerymodMQuery& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmTMQuerymodMQuery** rec);
	Sbecore::ubigint loadRefsByR(Sbecore::ubigint refR, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByR(Sbecore::ubigint refR, const bool append, ListWznmTMQuerymodMQuery& rst);
};
#endif

#endif

