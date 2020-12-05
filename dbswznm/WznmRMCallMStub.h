/**
	* \file WznmRMCallMStub.h
	* database access for table TblWznmRMCallMStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMCALLMSTUB_H
#define WZNMRMCALLMSTUB_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMCallMStub: record of TblWznmRMCallMStub
	*/
class WznmRMCallMStub {

public:
	WznmRMCallMStub(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMCall = 0, const Sbecore::ubigint refWznmMStub = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMCall;
	Sbecore::ubigint refWznmMStub;

public:
	bool operator==(const WznmRMCallMStub& comp);
	bool operator!=(const WznmRMCallMStub& comp);
};

/**
	* ListWznmRMCallMStub: recordset of TblWznmRMCallMStub
	*/
class ListWznmRMCallMStub {

public:
	ListWznmRMCallMStub();
	ListWznmRMCallMStub(const ListWznmRMCallMStub& src);
	~ListWznmRMCallMStub();

	void clear();
	unsigned int size() const;
	void append(WznmRMCallMStub* rec);

	WznmRMCallMStub* operator[](const Sbecore::uint ix);
	ListWznmRMCallMStub& operator=(const ListWznmRMCallMStub& src);
	bool operator==(const ListWznmRMCallMStub& comp);
	bool operator!=(const ListWznmRMCallMStub& comp);

public:
	std::vector<WznmRMCallMStub*> nodes;
};

/**
	* TblWznmRMCallMStub: C++ wrapper for table TblWznmRMCallMStub
	*/
class TblWznmRMCallMStub {

public:

public:
	TblWznmRMCallMStub();
	virtual ~TblWznmRMCallMStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMCallMStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMCallMStub& rst);

	virtual Sbecore::ubigint insertRec(WznmRMCallMStub* rec);
	Sbecore::ubigint insertNewRec(WznmRMCallMStub** rec = NULL, const Sbecore::ubigint refWznmMCall = 0, const Sbecore::ubigint refWznmMStub = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMCallMStub& rst, WznmRMCallMStub** rec = NULL, const Sbecore::ubigint refWznmMCall = 0, const Sbecore::ubigint refWznmMStub = 0);
	virtual void insertRst(ListWznmRMCallMStub& rst, bool transact = false);
	virtual void updateRec(WznmRMCallMStub* rec);
	virtual void updateRst(ListWznmRMCallMStub& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMCallMStub** rec);
	virtual Sbecore::ubigint loadCalsByStb(Sbecore::ubigint refWznmMStub, const bool append, std::vector<Sbecore::ubigint>& refWznmMCalls);
	virtual Sbecore::ubigint loadStbsByCal(Sbecore::ubigint refWznmMCall, const bool append, std::vector<Sbecore::ubigint>& refWznmMStubs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMCallMStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMCallMStub: C++ wrapper for table TblWznmRMCallMStub (MySQL database)
	*/
class MyTblWznmRMCallMStub : public TblWznmRMCallMStub, public Sbecore::MyTable {

public:
	MyTblWznmRMCallMStub();
	~MyTblWznmRMCallMStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMCallMStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMCallMStub& rst);

	Sbecore::ubigint insertRec(WznmRMCallMStub* rec);
	void insertRst(ListWznmRMCallMStub& rst, bool transact = false);
	void updateRec(WznmRMCallMStub* rec);
	void updateRst(ListWznmRMCallMStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMCallMStub** rec);
	Sbecore::ubigint loadCalsByStb(Sbecore::ubigint refWznmMStub, const bool append, std::vector<Sbecore::ubigint>& refWznmMCalls);
	Sbecore::ubigint loadStbsByCal(Sbecore::ubigint refWznmMCall, const bool append, std::vector<Sbecore::ubigint>& refWznmMStubs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMCallMStub: C++ wrapper for table TblWznmRMCallMStub (PgSQL database)
	*/
class PgTblWznmRMCallMStub : public TblWznmRMCallMStub, public Sbecore::PgTable {

public:
	PgTblWznmRMCallMStub();
	~PgTblWznmRMCallMStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMCallMStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMCallMStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMCallMStub** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMCallMStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMCallMStub& rst);

	Sbecore::ubigint insertRec(WznmRMCallMStub* rec);
	void insertRst(ListWznmRMCallMStub& rst, bool transact = false);
	void updateRec(WznmRMCallMStub* rec);
	void updateRst(ListWznmRMCallMStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMCallMStub** rec);
	Sbecore::ubigint loadCalsByStb(Sbecore::ubigint refWznmMStub, const bool append, std::vector<Sbecore::ubigint>& refWznmMCalls);
	Sbecore::ubigint loadStbsByCal(Sbecore::ubigint refWznmMCall, const bool append, std::vector<Sbecore::ubigint>& refWznmMStubs);
};
#endif

#endif

