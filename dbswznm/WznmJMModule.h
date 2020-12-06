/**
	* \file WznmJMModule.h
	* database access for table TblWznmJMModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMJMMODULE_H
#define WZNMJMMODULE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMModule: record of TblWznmJMModule
	*/
class WznmJMModule {

public:
	WznmJMModule(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMModule = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMModule;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WznmJMModule& comp);
	bool operator!=(const WznmJMModule& comp);
};

/**
	* ListWznmJMModule: recordset of TblWznmJMModule
	*/
class ListWznmJMModule {

public:
	ListWznmJMModule();
	ListWznmJMModule(const ListWznmJMModule& src);
	~ListWznmJMModule();

	void clear();
	unsigned int size() const;
	void append(WznmJMModule* rec);

	WznmJMModule* operator[](const Sbecore::uint ix);
	ListWznmJMModule& operator=(const ListWznmJMModule& src);
	bool operator==(const ListWznmJMModule& comp);
	bool operator!=(const ListWznmJMModule& comp);

public:
	std::vector<WznmJMModule*> nodes;
};

/**
	* TblWznmJMModule: C++ wrapper for table TblWznmJMModule
	*/
class TblWznmJMModule {

public:

public:
	TblWznmJMModule();
	virtual ~TblWznmJMModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMModule& rst);

	virtual Sbecore::ubigint insertRec(WznmJMModule* rec);
	Sbecore::ubigint insertNewRec(WznmJMModule** rec = NULL, const Sbecore::ubigint refWznmMModule = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMModule& rst, WznmJMModule** rec = NULL, const Sbecore::ubigint refWznmMModule = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmJMModule& rst, bool transact = false);
	virtual void updateRec(WznmJMModule* rec);
	virtual void updateRst(ListWznmJMModule& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMModule** rec);
	virtual bool loadRecByMdlLoc(Sbecore::ubigint refWznmMModule, Sbecore::ubigint x1RefWznmMLocale, WznmJMModule** rec);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWznmMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMdl(Sbecore::ubigint refWznmMModule, const bool append, ListWznmJMModule& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMModule: C++ wrapper for table TblWznmJMModule (MySQL database)
	*/
class MyTblWznmJMModule : public TblWznmJMModule, public Sbecore::MyTable {

public:
	MyTblWznmJMModule();
	~MyTblWznmJMModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMModule& rst);

	Sbecore::ubigint insertRec(WznmJMModule* rec);
	void insertRst(ListWznmJMModule& rst, bool transact = false);
	void updateRec(WznmJMModule* rec);
	void updateRst(ListWznmJMModule& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMModule** rec);
	bool loadRecByMdlLoc(Sbecore::ubigint refWznmMModule, Sbecore::ubigint x1RefWznmMLocale, WznmJMModule** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWznmMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint refWznmMModule, const bool append, ListWznmJMModule& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMModule: C++ wrapper for table TblWznmJMModule (PgSQL database)
	*/
class PgTblWznmJMModule : public TblWznmJMModule, public Sbecore::PgTable {

public:
	PgTblWznmJMModule();
	~PgTblWznmJMModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMModule& rst);

	Sbecore::ubigint insertRec(WznmJMModule* rec);
	void insertRst(ListWznmJMModule& rst, bool transact = false);
	void updateRec(WznmJMModule* rec);
	void updateRst(ListWznmJMModule& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMModule** rec);
	bool loadRecByMdlLoc(Sbecore::ubigint refWznmMModule, Sbecore::ubigint x1RefWznmMLocale, WznmJMModule** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint refWznmMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint refWznmMModule, const bool append, ListWznmJMModule& rst);
};
#endif

#endif
