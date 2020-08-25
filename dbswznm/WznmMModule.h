/**
	* \file WznmMModule.h
	* database access for table TblWznmMModule (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMMMODULE_H
#define WZNMMMODULE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMModule: record of TblWznmMModule
	*/
class WznmMModule {

public:
	WznmMModule(const Sbecore::ubigint ref = 0, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string sref = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint verRefWznmMVersion;
	Sbecore::uint verNum;
	std::string sref;
	Sbecore::ubigint refJ;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WznmMModule& comp);
	bool operator!=(const WznmMModule& comp);
};

/**
	* ListWznmMModule: recordset of TblWznmMModule
	*/
class ListWznmMModule {

public:
	ListWznmMModule();
	ListWznmMModule(const ListWznmMModule& src);
	~ListWznmMModule();

	void clear();
	unsigned int size() const;
	void append(WznmMModule* rec);

	WznmMModule* operator[](const Sbecore::uint ix);
	ListWznmMModule& operator=(const ListWznmMModule& src);
	bool operator==(const ListWznmMModule& comp);
	bool operator!=(const ListWznmMModule& comp);

public:
	std::vector<WznmMModule*> nodes;
};

/**
	* TblWznmMModule: C++ wrapper for table TblWznmMModule
	*/
class TblWznmMModule {

public:

public:
	TblWznmMModule();
	virtual ~TblWznmMModule();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMModule** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMModule& rst);

	virtual Sbecore::ubigint insertRec(WznmMModule* rec);
	Sbecore::ubigint insertNewRec(WznmMModule** rec = NULL, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string sref = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMModule& rst, WznmMModule** rec = NULL, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string sref = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMModule& rst, bool transact = false);
	virtual void updateRec(WznmMModule* rec);
	virtual void updateRst(ListWznmMModule& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMModule** rec);
	virtual Sbecore::ubigint loadRefsByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMModule& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMModule& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMModule: C++ wrapper for table TblWznmMModule (MySQL database)
	*/
class MyTblWznmMModule : public TblWznmMModule, public Sbecore::MyTable {

public:
	MyTblWznmMModule();
	~MyTblWznmMModule();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMModule& rst);

	Sbecore::ubigint insertRec(WznmMModule* rec);
	void insertRst(ListWznmMModule& rst, bool transact = false);
	void updateRec(WznmMModule* rec);
	void updateRst(ListWznmMModule& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMModule** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMModule& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMModule: C++ wrapper for table TblWznmMModule (PgSQL database)
	*/
class PgTblWznmMModule : public TblWznmMModule, public Sbecore::PgTable {

public:
	PgTblWznmMModule();
	~PgTblWznmMModule();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMModule** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMModule& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMModule** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMModule& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMModule** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMModule& rst);

	Sbecore::ubigint insertRec(WznmMModule* rec);
	void insertRst(ListWznmMModule& rst, bool transact = false);
	void updateRec(WznmMModule* rec);
	void updateRst(ListWznmMModule& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMModule** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMModule& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

