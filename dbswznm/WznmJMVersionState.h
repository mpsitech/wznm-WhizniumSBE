/**
	* \file WznmJMVersionState.h
	* database access for table TblWznmJMVersionState (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMJMVERSIONSTATE_H
#define WZNMJMVERSIONSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMVersionState: record of TblWznmJMVersionState
	*/
class WznmJMVersionState {

public:
	WznmJMVersionState(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::uint x1Start;
	Sbecore::uint ixVState;

public:
	bool operator==(const WznmJMVersionState& comp);
	bool operator!=(const WznmJMVersionState& comp);
};

/**
	* ListWznmJMVersionState: recordset of TblWznmJMVersionState
	*/
class ListWznmJMVersionState {

public:
	ListWznmJMVersionState();
	ListWznmJMVersionState(const ListWznmJMVersionState& src);
	~ListWznmJMVersionState();

	void clear();
	unsigned int size() const;
	void append(WznmJMVersionState* rec);

	WznmJMVersionState* operator[](const Sbecore::uint ix);
	ListWznmJMVersionState& operator=(const ListWznmJMVersionState& src);
	bool operator==(const ListWznmJMVersionState& comp);
	bool operator!=(const ListWznmJMVersionState& comp);

public:
	std::vector<WznmJMVersionState*> nodes;
};

/**
	* TblWznmJMVersionState: C++ wrapper for table TblWznmJMVersionState
	*/
class TblWznmJMVersionState {

public:

public:
	TblWznmJMVersionState();
	virtual ~TblWznmJMVersionState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMVersionState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMVersionState& rst);

	virtual Sbecore::ubigint insertRec(WznmJMVersionState* rec);
	Sbecore::ubigint insertNewRec(WznmJMVersionState** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmJMVersionState& rst, WznmJMVersionState** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	virtual void insertRst(ListWznmJMVersionState& rst, bool transact = false);
	virtual void updateRec(WznmJMVersionState* rec);
	virtual void updateRst(ListWznmJMVersionState& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMVersionState** rec);
	virtual bool loadRecByVerSta(Sbecore::ubigint refWznmMVersion, Sbecore::uint x1Start, WznmJMVersionState** rec);
	virtual Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmJMVersionState& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMVersionState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMVersionState: C++ wrapper for table TblWznmJMVersionState (MySQL database)
	*/
class MyTblWznmJMVersionState : public TblWznmJMVersionState, public Sbecore::MyTable {

public:
	MyTblWznmJMVersionState();
	~MyTblWznmJMVersionState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMVersionState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMVersionState& rst);

	Sbecore::ubigint insertRec(WznmJMVersionState* rec);
	void insertRst(ListWznmJMVersionState& rst, bool transact = false);
	void updateRec(WznmJMVersionState* rec);
	void updateRst(ListWznmJMVersionState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMVersionState** rec);
	bool loadRecByVerSta(Sbecore::ubigint refWznmMVersion, Sbecore::uint x1Start, WznmJMVersionState** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmJMVersionState& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMVersionState: C++ wrapper for table TblWznmJMVersionState (PgSQL database)
	*/
class PgTblWznmJMVersionState : public TblWznmJMVersionState, public Sbecore::PgTable {

public:
	PgTblWznmJMVersionState();
	~PgTblWznmJMVersionState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMVersionState** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMVersionState& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMVersionState** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMVersionState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMVersionState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMVersionState& rst);

	Sbecore::ubigint insertRec(WznmJMVersionState* rec);
	void insertRst(ListWznmJMVersionState& rst, bool transact = false);
	void updateRec(WznmJMVersionState* rec);
	void updateRst(ListWznmJMVersionState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMVersionState** rec);
	bool loadRecByVerSta(Sbecore::ubigint refWznmMVersion, Sbecore::uint x1Start, WznmJMVersionState** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmJMVersionState& rst);
};
#endif

#endif

