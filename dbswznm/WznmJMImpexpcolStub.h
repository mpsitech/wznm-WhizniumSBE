/**
	* \file WznmJMImpexpcolStub.h
	* database access for table TblWznmJMImpexpcolStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMJMIMPEXPCOLSTUB_H
#define WZNMJMIMPEXPCOLSTUB_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMImpexpcolStub: record of TblWznmJMImpexpcolStub
	*/
class WznmJMImpexpcolStub {

public:
	WznmJMImpexpcolStub(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMImpexpcol = 0, const Sbecore::ubigint x1RefWznmMVectoritem = 0, const Sbecore::ubigint refWznmMStub = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMImpexpcol;
	Sbecore::ubigint x1RefWznmMVectoritem;
	Sbecore::ubigint refWznmMStub;

public:
	bool operator==(const WznmJMImpexpcolStub& comp);
	bool operator!=(const WznmJMImpexpcolStub& comp);
};

/**
	* ListWznmJMImpexpcolStub: recordset of TblWznmJMImpexpcolStub
	*/
class ListWznmJMImpexpcolStub {

public:
	ListWznmJMImpexpcolStub();
	ListWznmJMImpexpcolStub(const ListWznmJMImpexpcolStub& src);
	~ListWznmJMImpexpcolStub();

	void clear();
	unsigned int size() const;
	void append(WznmJMImpexpcolStub* rec);

	WznmJMImpexpcolStub* operator[](const Sbecore::uint ix);
	ListWznmJMImpexpcolStub& operator=(const ListWznmJMImpexpcolStub& src);
	bool operator==(const ListWznmJMImpexpcolStub& comp);
	bool operator!=(const ListWznmJMImpexpcolStub& comp);

public:
	std::vector<WznmJMImpexpcolStub*> nodes;
};

/**
	* TblWznmJMImpexpcolStub: C++ wrapper for table TblWznmJMImpexpcolStub
	*/
class TblWznmJMImpexpcolStub {

public:

public:
	TblWznmJMImpexpcolStub();
	virtual ~TblWznmJMImpexpcolStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMImpexpcolStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMImpexpcolStub& rst);

	virtual Sbecore::ubigint insertRec(WznmJMImpexpcolStub* rec);
	Sbecore::ubigint insertNewRec(WznmJMImpexpcolStub** rec = NULL, const Sbecore::ubigint refWznmMImpexpcol = 0, const Sbecore::ubigint x1RefWznmMVectoritem = 0, const Sbecore::ubigint refWznmMStub = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmJMImpexpcolStub& rst, WznmJMImpexpcolStub** rec = NULL, const Sbecore::ubigint refWznmMImpexpcol = 0, const Sbecore::ubigint x1RefWznmMVectoritem = 0, const Sbecore::ubigint refWznmMStub = 0);
	virtual void insertRst(ListWznmJMImpexpcolStub& rst, bool transact = false);
	virtual void updateRec(WznmJMImpexpcolStub* rec);
	virtual void updateRst(ListWznmJMImpexpcolStub& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMImpexpcolStub** rec);
	virtual bool loadRecByIelVit(Sbecore::ubigint refWznmMImpexpcol, Sbecore::ubigint x1RefWznmMVectoritem, WznmJMImpexpcolStub** rec);
	virtual Sbecore::ubigint loadRefsByIel(Sbecore::ubigint refWznmMImpexpcol, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByIel(Sbecore::ubigint refWznmMImpexpcol, const bool append, ListWznmJMImpexpcolStub& rst);
	virtual bool loadStbByIelVit(Sbecore::ubigint refWznmMImpexpcol, Sbecore::ubigint x1RefWznmMVectoritem, Sbecore::ubigint& refWznmMStub);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMImpexpcolStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMImpexpcolStub: C++ wrapper for table TblWznmJMImpexpcolStub (MySQL database)
	*/
class MyTblWznmJMImpexpcolStub : public TblWznmJMImpexpcolStub, public Sbecore::MyTable {

public:
	MyTblWznmJMImpexpcolStub();
	~MyTblWznmJMImpexpcolStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMImpexpcolStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMImpexpcolStub& rst);

	Sbecore::ubigint insertRec(WznmJMImpexpcolStub* rec);
	void insertRst(ListWznmJMImpexpcolStub& rst, bool transact = false);
	void updateRec(WznmJMImpexpcolStub* rec);
	void updateRst(ListWznmJMImpexpcolStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMImpexpcolStub** rec);
	bool loadRecByIelVit(Sbecore::ubigint refWznmMImpexpcol, Sbecore::ubigint x1RefWznmMVectoritem, WznmJMImpexpcolStub** rec);
	Sbecore::ubigint loadRefsByIel(Sbecore::ubigint refWznmMImpexpcol, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByIel(Sbecore::ubigint refWznmMImpexpcol, const bool append, ListWznmJMImpexpcolStub& rst);
	bool loadStbByIelVit(Sbecore::ubigint refWznmMImpexpcol, Sbecore::ubigint x1RefWznmMVectoritem, Sbecore::ubigint& refWznmMStub);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMImpexpcolStub: C++ wrapper for table TblWznmJMImpexpcolStub (PgSQL database)
	*/
class PgTblWznmJMImpexpcolStub : public TblWznmJMImpexpcolStub, public Sbecore::PgTable {

public:
	PgTblWznmJMImpexpcolStub();
	~PgTblWznmJMImpexpcolStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMImpexpcolStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMImpexpcolStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMImpexpcolStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMImpexpcolStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMImpexpcolStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMImpexpcolStub& rst);

	Sbecore::ubigint insertRec(WznmJMImpexpcolStub* rec);
	void insertRst(ListWznmJMImpexpcolStub& rst, bool transact = false);
	void updateRec(WznmJMImpexpcolStub* rec);
	void updateRst(ListWznmJMImpexpcolStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMImpexpcolStub** rec);
	bool loadRecByIelVit(Sbecore::ubigint refWznmMImpexpcol, Sbecore::ubigint x1RefWznmMVectoritem, WznmJMImpexpcolStub** rec);
	Sbecore::ubigint loadRefsByIel(Sbecore::ubigint refWznmMImpexpcol, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByIel(Sbecore::ubigint refWznmMImpexpcol, const bool append, ListWznmJMImpexpcolStub& rst);
	bool loadStbByIelVit(Sbecore::ubigint refWznmMImpexpcol, Sbecore::ubigint x1RefWznmMVectoritem, Sbecore::ubigint& refWznmMStub);
};
#endif

#endif

