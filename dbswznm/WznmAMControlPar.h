/**
	* \file WznmAMControlPar.h
	* database access for table TblWznmAMControlPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMAMCONTROLPAR_H
#define WZNMAMCONTROLPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMControlPar: record of TblWznmAMControlPar
	*/
class WznmAMControlPar {

public:
	WznmAMControlPar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMControl = 0, const std::string x1SrefKKey = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string osrefKVal = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMControl;
	std::string x1SrefKKey;
	Sbecore::ubigint x2RefWznmMLocale;
	std::string osrefKVal;

public:
	bool operator==(const WznmAMControlPar& comp);
	bool operator!=(const WznmAMControlPar& comp);
};

/**
	* ListWznmAMControlPar: recordset of TblWznmAMControlPar
	*/
class ListWznmAMControlPar {

public:
	ListWznmAMControlPar();
	ListWznmAMControlPar(const ListWznmAMControlPar& src);
	~ListWznmAMControlPar();

	void clear();
	unsigned int size() const;
	void append(WznmAMControlPar* rec);

	WznmAMControlPar* operator[](const Sbecore::uint ix);
	ListWznmAMControlPar& operator=(const ListWznmAMControlPar& src);
	bool operator==(const ListWznmAMControlPar& comp);
	bool operator!=(const ListWznmAMControlPar& comp);

public:
	std::vector<WznmAMControlPar*> nodes;
};

/**
	* TblWznmAMControlPar: C++ wrapper for table TblWznmAMControlPar
	*/
class TblWznmAMControlPar {

public:

public:
	TblWznmAMControlPar();
	virtual ~TblWznmAMControlPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMControlPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMControlPar& rst);

	virtual Sbecore::ubigint insertRec(WznmAMControlPar* rec);
	Sbecore::ubigint insertNewRec(WznmAMControlPar** rec = NULL, const Sbecore::ubigint refWznmMControl = 0, const std::string x1SrefKKey = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string osrefKVal = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMControlPar& rst, WznmAMControlPar** rec = NULL, const Sbecore::ubigint refWznmMControl = 0, const std::string x1SrefKKey = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string osrefKVal = "");
	virtual void insertRst(ListWznmAMControlPar& rst, bool transact = false);
	virtual void updateRec(WznmAMControlPar* rec);
	virtual void updateRst(ListWznmAMControlPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMControlPar** rec);
	virtual Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCon(Sbecore::ubigint refWznmMControl, const bool append, ListWznmAMControlPar& rst);
	virtual bool loadValByConKeyLoc(Sbecore::ubigint refWznmMControl, std::string x1SrefKKey, Sbecore::ubigint x2RefWznmMLocale, std::string& osrefKVal);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMControlPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMControlPar: C++ wrapper for table TblWznmAMControlPar (MySQL database)
	*/
class MyTblWznmAMControlPar : public TblWznmAMControlPar, public Sbecore::MyTable {

public:
	MyTblWznmAMControlPar();
	~MyTblWznmAMControlPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMControlPar& rst);

	Sbecore::ubigint insertRec(WznmAMControlPar* rec);
	void insertRst(ListWznmAMControlPar& rst, bool transact = false);
	void updateRec(WznmAMControlPar* rec);
	void updateRst(ListWznmAMControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMControlPar** rec);
	Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refWznmMControl, const bool append, ListWznmAMControlPar& rst);
	bool loadValByConKeyLoc(Sbecore::ubigint refWznmMControl, std::string x1SrefKKey, Sbecore::ubigint x2RefWznmMLocale, std::string& osrefKVal);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMControlPar: C++ wrapper for table TblWznmAMControlPar (PgSQL database)
	*/
class PgTblWznmAMControlPar : public TblWznmAMControlPar, public Sbecore::PgTable {

public:
	PgTblWznmAMControlPar();
	~PgTblWznmAMControlPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMControlPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMControlPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMControlPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMControlPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMControlPar& rst);

	Sbecore::ubigint insertRec(WznmAMControlPar* rec);
	void insertRst(ListWznmAMControlPar& rst, bool transact = false);
	void updateRec(WznmAMControlPar* rec);
	void updateRst(ListWznmAMControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMControlPar** rec);
	Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refWznmMControl, const bool append, ListWznmAMControlPar& rst);
	bool loadValByConKeyLoc(Sbecore::ubigint refWznmMControl, std::string x1SrefKKey, Sbecore::ubigint x2RefWznmMLocale, std::string& osrefKVal);
};
#endif

#endif

