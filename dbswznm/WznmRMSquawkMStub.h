/**
	* \file WznmRMSquawkMStub.h
	* database access for table TblWznmRMSquawkMStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMSQUAWKMSTUB_H
#define WZNMRMSQUAWKMSTUB_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMSquawkMStub: record of TblWznmRMSquawkMStub
	*/
class WznmRMSquawkMStub {

public:
	WznmRMSquawkMStub(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSquawk = 0, const Sbecore::ubigint refWznmMStub = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMSquawk;
	Sbecore::ubigint refWznmMStub;

public:
	bool operator==(const WznmRMSquawkMStub& comp);
	bool operator!=(const WznmRMSquawkMStub& comp);
};

/**
	* ListWznmRMSquawkMStub: recordset of TblWznmRMSquawkMStub
	*/
class ListWznmRMSquawkMStub {

public:
	ListWznmRMSquawkMStub();
	ListWznmRMSquawkMStub(const ListWznmRMSquawkMStub& src);
	~ListWznmRMSquawkMStub();

	void clear();
	unsigned int size() const;
	void append(WznmRMSquawkMStub* rec);

	WznmRMSquawkMStub* operator[](const Sbecore::uint ix);
	ListWznmRMSquawkMStub& operator=(const ListWznmRMSquawkMStub& src);
	bool operator==(const ListWznmRMSquawkMStub& comp);
	bool operator!=(const ListWznmRMSquawkMStub& comp);

public:
	std::vector<WznmRMSquawkMStub*> nodes;
};

/**
	* TblWznmRMSquawkMStub: C++ wrapper for table TblWznmRMSquawkMStub
	*/
class TblWznmRMSquawkMStub {

public:

public:
	TblWznmRMSquawkMStub();
	virtual ~TblWznmRMSquawkMStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMSquawkMStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMSquawkMStub& rst);

	virtual Sbecore::ubigint insertRec(WznmRMSquawkMStub* rec);
	Sbecore::ubigint insertNewRec(WznmRMSquawkMStub** rec = NULL, const Sbecore::ubigint refWznmMSquawk = 0, const Sbecore::ubigint refWznmMStub = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMSquawkMStub& rst, WznmRMSquawkMStub** rec = NULL, const Sbecore::ubigint refWznmMSquawk = 0, const Sbecore::ubigint refWznmMStub = 0);
	virtual void insertRst(ListWznmRMSquawkMStub& rst, bool transact = false);
	virtual void updateRec(WznmRMSquawkMStub* rec);
	virtual void updateRst(ListWznmRMSquawkMStub& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMSquawkMStub** rec);
	virtual Sbecore::ubigint loadRefsBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadSqksByStb(Sbecore::ubigint refWznmMStub, const bool append, std::vector<Sbecore::ubigint>& refWznmMSquawks);
	virtual Sbecore::ubigint loadStbsBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, std::vector<Sbecore::ubigint>& refWznmMStubs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMSquawkMStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMSquawkMStub: C++ wrapper for table TblWznmRMSquawkMStub (MySQL database)
	*/
class MyTblWznmRMSquawkMStub : public TblWznmRMSquawkMStub, public Sbecore::MyTable {

public:
	MyTblWznmRMSquawkMStub();
	~MyTblWznmRMSquawkMStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMSquawkMStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMSquawkMStub& rst);

	Sbecore::ubigint insertRec(WznmRMSquawkMStub* rec);
	void insertRst(ListWznmRMSquawkMStub& rst, bool transact = false);
	void updateRec(WznmRMSquawkMStub* rec);
	void updateRst(ListWznmRMSquawkMStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMSquawkMStub** rec);
	Sbecore::ubigint loadRefsBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadSqksByStb(Sbecore::ubigint refWznmMStub, const bool append, std::vector<Sbecore::ubigint>& refWznmMSquawks);
	Sbecore::ubigint loadStbsBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, std::vector<Sbecore::ubigint>& refWznmMStubs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMSquawkMStub: C++ wrapper for table TblWznmRMSquawkMStub (PgSQL database)
	*/
class PgTblWznmRMSquawkMStub : public TblWznmRMSquawkMStub, public Sbecore::PgTable {

public:
	PgTblWznmRMSquawkMStub();
	~PgTblWznmRMSquawkMStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMSquawkMStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMSquawkMStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMSquawkMStub** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMSquawkMStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMSquawkMStub& rst);

	Sbecore::ubigint insertRec(WznmRMSquawkMStub* rec);
	void insertRst(ListWznmRMSquawkMStub& rst, bool transact = false);
	void updateRec(WznmRMSquawkMStub* rec);
	void updateRst(ListWznmRMSquawkMStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMSquawkMStub** rec);
	Sbecore::ubigint loadRefsBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadSqksByStb(Sbecore::ubigint refWznmMStub, const bool append, std::vector<Sbecore::ubigint>& refWznmMSquawks);
	Sbecore::ubigint loadStbsBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, std::vector<Sbecore::ubigint>& refWznmMStubs);
};
#endif

#endif

