/**
	* \file WznmJMQuerycolStub.h
	* database access for table TblWznmJMQuerycolStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMJMQUERYCOLSTUB_H
#define WZNMJMQUERYCOLSTUB_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMQuerycolStub: record of TblWznmJMQuerycolStub
	*/
class WznmJMQuerycolStub {

public:
	WznmJMQuerycolStub(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMQuerycol = 0, const Sbecore::ubigint x1RefWznmMVectoritem = 0, const Sbecore::ubigint x2RefWznmMPreset = 0, const Sbecore::ubigint refWznmMStub = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMQuerycol;
	Sbecore::ubigint x1RefWznmMVectoritem;
	Sbecore::ubigint x2RefWznmMPreset;
	Sbecore::ubigint refWznmMStub;

public:
	bool operator==(const WznmJMQuerycolStub& comp);
	bool operator!=(const WznmJMQuerycolStub& comp);
};

/**
	* ListWznmJMQuerycolStub: recordset of TblWznmJMQuerycolStub
	*/
class ListWznmJMQuerycolStub {

public:
	ListWznmJMQuerycolStub();
	ListWznmJMQuerycolStub(const ListWznmJMQuerycolStub& src);
	~ListWznmJMQuerycolStub();

	void clear();
	unsigned int size() const;
	void append(WznmJMQuerycolStub* rec);

	WznmJMQuerycolStub* operator[](const Sbecore::uint ix);
	ListWznmJMQuerycolStub& operator=(const ListWznmJMQuerycolStub& src);
	bool operator==(const ListWznmJMQuerycolStub& comp);
	bool operator!=(const ListWznmJMQuerycolStub& comp);

public:
	std::vector<WznmJMQuerycolStub*> nodes;
};

/**
	* TblWznmJMQuerycolStub: C++ wrapper for table TblWznmJMQuerycolStub
	*/
class TblWznmJMQuerycolStub {

public:

public:
	TblWznmJMQuerycolStub();
	virtual ~TblWznmJMQuerycolStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMQuerycolStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMQuerycolStub& rst);

	virtual Sbecore::ubigint insertRec(WznmJMQuerycolStub* rec);
	Sbecore::ubigint insertNewRec(WznmJMQuerycolStub** rec = NULL, const Sbecore::ubigint refWznmMQuerycol = 0, const Sbecore::ubigint x1RefWznmMVectoritem = 0, const Sbecore::ubigint x2RefWznmMPreset = 0, const Sbecore::ubigint refWznmMStub = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmJMQuerycolStub& rst, WznmJMQuerycolStub** rec = NULL, const Sbecore::ubigint refWznmMQuerycol = 0, const Sbecore::ubigint x1RefWznmMVectoritem = 0, const Sbecore::ubigint x2RefWznmMPreset = 0, const Sbecore::ubigint refWznmMStub = 0);
	virtual void insertRst(ListWznmJMQuerycolStub& rst, bool transact = false);
	virtual void updateRec(WznmJMQuerycolStub* rec);
	virtual void updateRst(ListWznmJMQuerycolStub& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMQuerycolStub** rec);
	virtual bool loadRecByQcoVit(Sbecore::ubigint refWznmMQuerycol, Sbecore::ubigint x1RefWznmMVectoritem, WznmJMQuerycolStub** rec);
	virtual Sbecore::ubigint loadRefsByQco(Sbecore::ubigint refWznmMQuerycol, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByQco(Sbecore::ubigint refWznmMQuerycol, const bool append, ListWznmJMQuerycolStub& rst);
	virtual bool loadStbByQcoVitPst(Sbecore::ubigint refWznmMQuerycol, Sbecore::ubigint x1RefWznmMVectoritem, Sbecore::ubigint x2RefWznmMPreset, Sbecore::ubigint& refWznmMStub);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMQuerycolStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMQuerycolStub: C++ wrapper for table TblWznmJMQuerycolStub (MySQL database)
	*/
class MyTblWznmJMQuerycolStub : public TblWznmJMQuerycolStub, public Sbecore::MyTable {

public:
	MyTblWznmJMQuerycolStub();
	~MyTblWznmJMQuerycolStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMQuerycolStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMQuerycolStub& rst);

	Sbecore::ubigint insertRec(WznmJMQuerycolStub* rec);
	void insertRst(ListWznmJMQuerycolStub& rst, bool transact = false);
	void updateRec(WznmJMQuerycolStub* rec);
	void updateRst(ListWznmJMQuerycolStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMQuerycolStub** rec);
	bool loadRecByQcoVit(Sbecore::ubigint refWznmMQuerycol, Sbecore::ubigint x1RefWznmMVectoritem, WznmJMQuerycolStub** rec);
	Sbecore::ubigint loadRefsByQco(Sbecore::ubigint refWznmMQuerycol, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQco(Sbecore::ubigint refWznmMQuerycol, const bool append, ListWznmJMQuerycolStub& rst);
	bool loadStbByQcoVitPst(Sbecore::ubigint refWznmMQuerycol, Sbecore::ubigint x1RefWznmMVectoritem, Sbecore::ubigint x2RefWznmMPreset, Sbecore::ubigint& refWznmMStub);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMQuerycolStub: C++ wrapper for table TblWznmJMQuerycolStub (PgSQL database)
	*/
class PgTblWznmJMQuerycolStub : public TblWznmJMQuerycolStub, public Sbecore::PgTable {

public:
	PgTblWznmJMQuerycolStub();
	~PgTblWznmJMQuerycolStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMQuerycolStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMQuerycolStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMQuerycolStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMQuerycolStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMQuerycolStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMQuerycolStub& rst);

	Sbecore::ubigint insertRec(WznmJMQuerycolStub* rec);
	void insertRst(ListWznmJMQuerycolStub& rst, bool transact = false);
	void updateRec(WznmJMQuerycolStub* rec);
	void updateRst(ListWznmJMQuerycolStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMQuerycolStub** rec);
	bool loadRecByQcoVit(Sbecore::ubigint refWznmMQuerycol, Sbecore::ubigint x1RefWznmMVectoritem, WznmJMQuerycolStub** rec);
	Sbecore::ubigint loadRefsByQco(Sbecore::ubigint refWznmMQuerycol, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQco(Sbecore::ubigint refWznmMQuerycol, const bool append, ListWznmJMQuerycolStub& rst);
	bool loadStbByQcoVitPst(Sbecore::ubigint refWznmMQuerycol, Sbecore::ubigint x1RefWznmMVectoritem, Sbecore::ubigint x2RefWznmMPreset, Sbecore::ubigint& refWznmMStub);
};
#endif

#endif

