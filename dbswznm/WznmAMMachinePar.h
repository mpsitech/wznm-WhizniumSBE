/**
	* \file WznmAMMachinePar.h
	* database access for table TblWznmAMMachinePar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMAMMACHINEPAR_H
#define WZNMAMMACHINEPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMMachinePar: record of TblWznmAMMachinePar
	*/
class WznmAMMachinePar {

public:
	WznmAMMachinePar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMMachine = 0, const std::string x1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMMachine;
	std::string x1SrefKKey;
	std::string Val;

public:
	bool operator==(const WznmAMMachinePar& comp);
	bool operator!=(const WznmAMMachinePar& comp);
};

/**
	* ListWznmAMMachinePar: recordset of TblWznmAMMachinePar
	*/
class ListWznmAMMachinePar {

public:
	ListWznmAMMachinePar();
	ListWznmAMMachinePar(const ListWznmAMMachinePar& src);
	~ListWznmAMMachinePar();

	void clear();
	unsigned int size() const;
	void append(WznmAMMachinePar* rec);

	WznmAMMachinePar* operator[](const Sbecore::uint ix);
	ListWznmAMMachinePar& operator=(const ListWznmAMMachinePar& src);
	bool operator==(const ListWznmAMMachinePar& comp);
	bool operator!=(const ListWznmAMMachinePar& comp);

public:
	std::vector<WznmAMMachinePar*> nodes;
};

/**
	* TblWznmAMMachinePar: C++ wrapper for table TblWznmAMMachinePar
	*/
class TblWznmAMMachinePar {

public:

public:
	TblWznmAMMachinePar();
	virtual ~TblWznmAMMachinePar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMMachinePar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMachinePar& rst);

	virtual Sbecore::ubigint insertRec(WznmAMMachinePar* rec);
	Sbecore::ubigint insertNewRec(WznmAMMachinePar** rec = NULL, const Sbecore::ubigint refWznmMMachine = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMMachinePar& rst, WznmAMMachinePar** rec = NULL, const Sbecore::ubigint refWznmMMachine = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWznmAMMachinePar& rst, bool transact = false);
	virtual void updateRec(WznmAMMachinePar* rec);
	virtual void updateRst(ListWznmAMMachinePar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMMachinePar** rec);
	virtual Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWznmMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWznmMMachine, const bool append, ListWznmAMMachinePar& rst);
	virtual bool loadValByMchKey(Sbecore::ubigint refWznmMMachine, std::string x1SrefKKey, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMMachinePar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMMachinePar: C++ wrapper for table TblWznmAMMachinePar (MySQL database)
	*/
class MyTblWznmAMMachinePar : public TblWznmAMMachinePar, public Sbecore::MyTable {

public:
	MyTblWznmAMMachinePar();
	~MyTblWznmAMMachinePar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMachinePar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMachinePar& rst);

	Sbecore::ubigint insertRec(WznmAMMachinePar* rec);
	void insertRst(ListWznmAMMachinePar& rst, bool transact = false);
	void updateRec(WznmAMMachinePar* rec);
	void updateRst(ListWznmAMMachinePar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMachinePar** rec);
	Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWznmMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWznmMMachine, const bool append, ListWznmAMMachinePar& rst);
	bool loadValByMchKey(Sbecore::ubigint refWznmMMachine, std::string x1SrefKKey, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMMachinePar: C++ wrapper for table TblWznmAMMachinePar (PgSQL database)
	*/
class PgTblWznmAMMachinePar : public TblWznmAMMachinePar, public Sbecore::PgTable {

public:
	PgTblWznmAMMachinePar();
	~PgTblWznmAMMachinePar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMMachinePar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMMachinePar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMMachinePar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMMachinePar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMachinePar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMachinePar& rst);

	Sbecore::ubigint insertRec(WznmAMMachinePar* rec);
	void insertRst(ListWznmAMMachinePar& rst, bool transact = false);
	void updateRec(WznmAMMachinePar* rec);
	void updateRst(ListWznmAMMachinePar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMachinePar** rec);
	Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWznmMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWznmMMachine, const bool append, ListWznmAMMachinePar& rst);
	bool loadValByMchKey(Sbecore::ubigint refWznmMMachine, std::string x1SrefKKey, std::string& Val);
};
#endif

#endif

