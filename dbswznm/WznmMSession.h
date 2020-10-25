/**
	* \file WznmMSession.h
	* database access for table TblWznmMSession (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMSESSION_H
#define WZNMMSESSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMSession: record of TblWznmMSession
	*/
class WznmMSession {

public:
	WznmMSession(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMUser;
	Sbecore::uint start;
	Sbecore::uint stop;
	std::string Ip;

public:
	bool operator==(const WznmMSession& comp);
	bool operator!=(const WznmMSession& comp);
};

/**
	* ListWznmMSession: recordset of TblWznmMSession
	*/
class ListWznmMSession {

public:
	ListWznmMSession();
	ListWznmMSession(const ListWznmMSession& src);
	~ListWznmMSession();

	void clear();
	unsigned int size() const;
	void append(WznmMSession* rec);

	WznmMSession* operator[](const Sbecore::uint ix);
	ListWznmMSession& operator=(const ListWznmMSession& src);
	bool operator==(const ListWznmMSession& comp);
	bool operator!=(const ListWznmMSession& comp);

public:
	std::vector<WznmMSession*> nodes;
};

/**
	* TblWznmMSession: C++ wrapper for table TblWznmMSession
	*/
class TblWznmMSession {

public:

public:
	TblWznmMSession();
	virtual ~TblWznmMSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSession& rst);

	virtual Sbecore::ubigint insertRec(WznmMSession* rec);
	Sbecore::ubigint insertNewRec(WznmMSession** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMSession& rst, WznmMSession** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	virtual void insertRst(ListWznmMSession& rst, bool transact = false);
	virtual void updateRec(WznmMSession* rec);
	virtual void updateRst(ListWznmMSession& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMSession** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMSession: C++ wrapper for table TblWznmMSession (MySQL database)
	*/
class MyTblWznmMSession : public TblWznmMSession, public Sbecore::MyTable {

public:
	MyTblWznmMSession();
	~MyTblWznmMSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSession& rst);

	Sbecore::ubigint insertRec(WznmMSession* rec);
	void insertRst(ListWznmMSession& rst, bool transact = false);
	void updateRec(WznmMSession* rec);
	void updateRst(ListWznmMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSession** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMSession: C++ wrapper for table TblWznmMSession (PgSQL database)
	*/
class PgTblWznmMSession : public TblWznmMSession, public Sbecore::PgTable {

public:
	PgTblWznmMSession();
	~PgTblWznmMSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMSession** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMSession& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMSession** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSession& rst);

	Sbecore::ubigint insertRec(WznmMSession* rec);
	void insertRst(ListWznmMSession& rst, bool transact = false);
	void updateRec(WznmMSession* rec);
	void updateRst(ListWznmMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSession** rec);
};
#endif

#endif

