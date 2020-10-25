/**
	* \file WznmJAMStateTrigCond.h
	* database access for table TblWznmJAMStateTrigCond (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMJAMSTATETRIGCOND_H
#define WZNMJAMSTATETRIGCOND_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJAMStateTrigCond: record of TblWznmJAMStateTrigCond
	*/
class WznmJAMStateTrigCond {

public:
	WznmJAMStateTrigCond(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmAMStateTrig = 0, const Sbecore::uint x1IxWznmVApptarget = 0, const std::string Cond = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmAMStateTrig;
	Sbecore::uint x1IxWznmVApptarget;
	std::string Cond;

public:
	bool operator==(const WznmJAMStateTrigCond& comp);
	bool operator!=(const WznmJAMStateTrigCond& comp);
};

/**
	* ListWznmJAMStateTrigCond: recordset of TblWznmJAMStateTrigCond
	*/
class ListWznmJAMStateTrigCond {

public:
	ListWznmJAMStateTrigCond();
	ListWznmJAMStateTrigCond(const ListWznmJAMStateTrigCond& src);
	~ListWznmJAMStateTrigCond();

	void clear();
	unsigned int size() const;
	void append(WznmJAMStateTrigCond* rec);

	WznmJAMStateTrigCond* operator[](const Sbecore::uint ix);
	ListWznmJAMStateTrigCond& operator=(const ListWznmJAMStateTrigCond& src);
	bool operator==(const ListWznmJAMStateTrigCond& comp);
	bool operator!=(const ListWznmJAMStateTrigCond& comp);

public:
	std::vector<WznmJAMStateTrigCond*> nodes;
};

/**
	* TblWznmJAMStateTrigCond: C++ wrapper for table TblWznmJAMStateTrigCond
	*/
class TblWznmJAMStateTrigCond {

public:

public:
	TblWznmJAMStateTrigCond();
	virtual ~TblWznmJAMStateTrigCond();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJAMStateTrigCond** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJAMStateTrigCond& rst);

	virtual Sbecore::ubigint insertRec(WznmJAMStateTrigCond* rec);
	Sbecore::ubigint insertNewRec(WznmJAMStateTrigCond** rec = NULL, const Sbecore::ubigint refWznmAMStateTrig = 0, const Sbecore::uint x1IxWznmVApptarget = 0, const std::string Cond = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJAMStateTrigCond& rst, WznmJAMStateTrigCond** rec = NULL, const Sbecore::ubigint refWznmAMStateTrig = 0, const Sbecore::uint x1IxWznmVApptarget = 0, const std::string Cond = "");
	virtual void insertRst(ListWznmJAMStateTrigCond& rst, bool transact = false);
	virtual void updateRec(WznmJAMStateTrigCond* rec);
	virtual void updateRst(ListWznmJAMStateTrigCond& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJAMStateTrigCond** rec);
	virtual bool loadCndByStrTrg(Sbecore::ubigint refWznmAMStateTrig, Sbecore::uint x1IxWznmVApptarget, std::string& Cond);
	virtual bool loadRecByStrTrg(Sbecore::ubigint refWznmAMStateTrig, Sbecore::uint x1IxWznmVApptarget, WznmJAMStateTrigCond** rec);
	virtual Sbecore::ubigint loadRefsByStr(Sbecore::ubigint refWznmAMStateTrig, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByStr(Sbecore::ubigint refWznmAMStateTrig, const bool append, ListWznmJAMStateTrigCond& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJAMStateTrigCond& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJAMStateTrigCond: C++ wrapper for table TblWznmJAMStateTrigCond (MySQL database)
	*/
class MyTblWznmJAMStateTrigCond : public TblWznmJAMStateTrigCond, public Sbecore::MyTable {

public:
	MyTblWznmJAMStateTrigCond();
	~MyTblWznmJAMStateTrigCond();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJAMStateTrigCond** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJAMStateTrigCond& rst);

	Sbecore::ubigint insertRec(WznmJAMStateTrigCond* rec);
	void insertRst(ListWznmJAMStateTrigCond& rst, bool transact = false);
	void updateRec(WznmJAMStateTrigCond* rec);
	void updateRst(ListWznmJAMStateTrigCond& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJAMStateTrigCond** rec);
	bool loadCndByStrTrg(Sbecore::ubigint refWznmAMStateTrig, Sbecore::uint x1IxWznmVApptarget, std::string& Cond);
	bool loadRecByStrTrg(Sbecore::ubigint refWznmAMStateTrig, Sbecore::uint x1IxWznmVApptarget, WznmJAMStateTrigCond** rec);
	Sbecore::ubigint loadRefsByStr(Sbecore::ubigint refWznmAMStateTrig, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByStr(Sbecore::ubigint refWznmAMStateTrig, const bool append, ListWznmJAMStateTrigCond& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJAMStateTrigCond: C++ wrapper for table TblWznmJAMStateTrigCond (PgSQL database)
	*/
class PgTblWznmJAMStateTrigCond : public TblWznmJAMStateTrigCond, public Sbecore::PgTable {

public:
	PgTblWznmJAMStateTrigCond();
	~PgTblWznmJAMStateTrigCond();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJAMStateTrigCond** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJAMStateTrigCond& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJAMStateTrigCond** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJAMStateTrigCond& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJAMStateTrigCond** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJAMStateTrigCond& rst);

	Sbecore::ubigint insertRec(WznmJAMStateTrigCond* rec);
	void insertRst(ListWznmJAMStateTrigCond& rst, bool transact = false);
	void updateRec(WznmJAMStateTrigCond* rec);
	void updateRst(ListWznmJAMStateTrigCond& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJAMStateTrigCond** rec);
	bool loadCndByStrTrg(Sbecore::ubigint refWznmAMStateTrig, Sbecore::uint x1IxWznmVApptarget, std::string& Cond);
	bool loadRecByStrTrg(Sbecore::ubigint refWznmAMStateTrig, Sbecore::uint x1IxWznmVApptarget, WznmJAMStateTrigCond** rec);
	Sbecore::ubigint loadRefsByStr(Sbecore::ubigint refWznmAMStateTrig, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByStr(Sbecore::ubigint refWznmAMStateTrig, const bool append, ListWznmJAMStateTrigCond& rst);
};
#endif

#endif

