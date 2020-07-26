/**
	* \file WznmJMUserState.h
	* database access for table TblWznmJMUserState (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMJMUSERSTATE_H
#define WZNMJMUSERSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMUserState: record of TblWznmJMUserState
	*/
class WznmJMUserState {

public:
	WznmJMUserState(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMUser;
	Sbecore::uint x1Start;
	Sbecore::uint ixVState;

public:
	bool operator==(const WznmJMUserState& comp);
	bool operator!=(const WznmJMUserState& comp);
};

/**
	* ListWznmJMUserState: recordset of TblWznmJMUserState
	*/
class ListWznmJMUserState {

public:
	ListWznmJMUserState();
	ListWznmJMUserState(const ListWznmJMUserState& src);
	~ListWznmJMUserState();

	void clear();
	unsigned int size() const;
	void append(WznmJMUserState* rec);

	WznmJMUserState* operator[](const Sbecore::uint ix);
	ListWznmJMUserState& operator=(const ListWznmJMUserState& src);
	bool operator==(const ListWznmJMUserState& comp);
	bool operator!=(const ListWznmJMUserState& comp);

public:
	std::vector<WznmJMUserState*> nodes;
};

/**
	* TblWznmJMUserState: C++ wrapper for table TblWznmJMUserState
	*/
class TblWznmJMUserState {

public:

public:
	TblWznmJMUserState();
	virtual ~TblWznmJMUserState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMUserState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMUserState& rst);

	virtual Sbecore::ubigint insertRec(WznmJMUserState* rec);
	Sbecore::ubigint insertNewRec(WznmJMUserState** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmJMUserState& rst, WznmJMUserState** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	virtual void insertRst(ListWznmJMUserState& rst, bool transact = false);
	virtual void updateRec(WznmJMUserState* rec);
	virtual void updateRst(ListWznmJMUserState& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMUserState** rec);
	virtual bool loadRecByUsrSta(Sbecore::ubigint refWznmMUser, Sbecore::uint x1Start, WznmJMUserState** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWznmMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWznmMUser, const bool append, ListWznmJMUserState& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMUserState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMUserState: C++ wrapper for table TblWznmJMUserState (MySQL database)
	*/
class MyTblWznmJMUserState : public TblWznmJMUserState, public Sbecore::MyTable {

public:
	MyTblWznmJMUserState();
	~MyTblWznmJMUserState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMUserState& rst);

	Sbecore::ubigint insertRec(WznmJMUserState* rec);
	void insertRst(ListWznmJMUserState& rst, bool transact = false);
	void updateRec(WznmJMUserState* rec);
	void updateRst(ListWznmJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refWznmMUser, Sbecore::uint x1Start, WznmJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWznmMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWznmMUser, const bool append, ListWznmJMUserState& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMUserState: C++ wrapper for table TblWznmJMUserState (PgSQL database)
	*/
class PgTblWznmJMUserState : public TblWznmJMUserState, public Sbecore::PgTable {

public:
	PgTblWznmJMUserState();
	~PgTblWznmJMUserState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMUserState** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMUserState& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMUserState** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMUserState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMUserState& rst);

	Sbecore::ubigint insertRec(WznmJMUserState* rec);
	void insertRst(ListWznmJMUserState& rst, bool transact = false);
	void updateRec(WznmJMUserState* rec);
	void updateRst(ListWznmJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refWznmMUser, Sbecore::uint x1Start, WznmJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWznmMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWznmMUser, const bool append, ListWznmJMUserState& rst);
};
#endif

#endif

