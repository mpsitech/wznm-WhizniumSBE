/**
	* \file WznmMMachine.h
	* database access for table TblWznmMMachine (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMMACHINE_H
#define WZNMMMACHINE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMMachine: record of TblWznmMMachine
	*/
class WznmMMachine {

public:
	WznmMMachine(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMMachtype = 0, const std::string sref = "", const Sbecore::uint ixWznmWCloudtype = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMMachtype;
	std::string sref;
	Sbecore::uint ixWznmWCloudtype;
	std::string Comment;

public:
	bool operator==(const WznmMMachine& comp);
	bool operator!=(const WznmMMachine& comp);
};

/**
	* ListWznmMMachine: recordset of TblWznmMMachine
	*/
class ListWznmMMachine {

public:
	ListWznmMMachine();
	ListWznmMMachine(const ListWznmMMachine& src);
	~ListWznmMMachine();

	void clear();
	unsigned int size() const;
	void append(WznmMMachine* rec);

	WznmMMachine* operator[](const Sbecore::uint ix);
	ListWznmMMachine& operator=(const ListWznmMMachine& src);
	bool operator==(const ListWznmMMachine& comp);
	bool operator!=(const ListWznmMMachine& comp);

public:
	std::vector<WznmMMachine*> nodes;
};

/**
	* TblWznmMMachine: C++ wrapper for table TblWznmMMachine
	*/
class TblWznmMMachine {

public:

public:
	TblWznmMMachine();
	virtual ~TblWznmMMachine();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMMachine** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMMachine& rst);

	virtual Sbecore::ubigint insertRec(WznmMMachine* rec);
	Sbecore::ubigint insertNewRec(WznmMMachine** rec = NULL, const Sbecore::ubigint refWznmMMachtype = 0, const std::string sref = "", const Sbecore::uint ixWznmWCloudtype = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMMachine& rst, WznmMMachine** rec = NULL, const Sbecore::ubigint refWznmMMachtype = 0, const std::string sref = "", const Sbecore::uint ixWznmWCloudtype = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmMMachine& rst, bool transact = false);
	virtual void updateRec(WznmMMachine* rec);
	virtual void updateRst(ListWznmMMachine& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMMachine** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMMachtype, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMMachine& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMMachine: C++ wrapper for table TblWznmMMachine (MySQL database)
	*/
class MyTblWznmMMachine : public TblWznmMMachine, public Sbecore::MyTable {

public:
	MyTblWznmMMachine();
	~MyTblWznmMMachine();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMMachine& rst);

	Sbecore::ubigint insertRec(WznmMMachine* rec);
	void insertRst(ListWznmMMachine& rst, bool transact = false);
	void updateRec(WznmMMachine* rec);
	void updateRst(ListWznmMMachine& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMMachine** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMMachtype, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMMachine: C++ wrapper for table TblWznmMMachine (PgSQL database)
	*/
class PgTblWznmMMachine : public TblWznmMMachine, public Sbecore::PgTable {

public:
	PgTblWznmMMachine();
	~PgTblWznmMMachine();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMMachine** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMMachine& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMMachine** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMMachine** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMMachine& rst);

	Sbecore::ubigint insertRec(WznmMMachine* rec);
	void insertRst(ListWznmMMachine& rst, bool transact = false);
	void updateRec(WznmMMachine* rec);
	void updateRst(ListWznmMMachine& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMMachine** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMMachtype, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif

