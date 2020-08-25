/**
	* \file WznmMError.h
	* database access for table TblWznmMError (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMMERROR_H
#define WZNMMERROR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMError: record of TblWznmMError
	*/
class WznmMError {

public:
	WznmMError(const Sbecore::ubigint ref = 0, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint verRefWznmMVersion;
	Sbecore::uint verNum;
	std::string sref;
	Sbecore::ubigint refJTitle;
	std::string Title;

public:
	bool operator==(const WznmMError& comp);
	bool operator!=(const WznmMError& comp);
};

/**
	* ListWznmMError: recordset of TblWznmMError
	*/
class ListWznmMError {

public:
	ListWznmMError();
	ListWznmMError(const ListWznmMError& src);
	~ListWznmMError();

	void clear();
	unsigned int size() const;
	void append(WznmMError* rec);

	WznmMError* operator[](const Sbecore::uint ix);
	ListWznmMError& operator=(const ListWznmMError& src);
	bool operator==(const ListWznmMError& comp);
	bool operator!=(const ListWznmMError& comp);

public:
	std::vector<WznmMError*> nodes;
};

/**
	* TblWznmMError: C++ wrapper for table TblWznmMError
	*/
class TblWznmMError {

public:

public:
	TblWznmMError();
	virtual ~TblWznmMError();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMError** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMError& rst);

	virtual Sbecore::ubigint insertRec(WznmMError* rec);
	Sbecore::ubigint insertNewRec(WznmMError** rec = NULL, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMError& rst, WznmMError** rec = NULL, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "");
	virtual void insertRst(ListWznmMError& rst, bool transact = false);
	virtual void updateRec(WznmMError* rec);
	virtual void updateRst(ListWznmMError& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMError** rec);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMError& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMError& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMError: C++ wrapper for table TblWznmMError (MySQL database)
	*/
class MyTblWznmMError : public TblWznmMError, public Sbecore::MyTable {

public:
	MyTblWznmMError();
	~MyTblWznmMError();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMError& rst);

	Sbecore::ubigint insertRec(WznmMError* rec);
	void insertRst(ListWznmMError& rst, bool transact = false);
	void updateRec(WznmMError* rec);
	void updateRst(ListWznmMError& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMError** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMError& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMError: C++ wrapper for table TblWznmMError (PgSQL database)
	*/
class PgTblWznmMError : public TblWznmMError, public Sbecore::PgTable {

public:
	PgTblWznmMError();
	~PgTblWznmMError();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMError** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMError& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMError** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMError& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMError** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMError& rst);

	Sbecore::ubigint insertRec(WznmMError* rec);
	void insertRst(ListWznmMError& rst, bool transact = false);
	void updateRec(WznmMError* rec);
	void updateRst(ListWznmMError& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMError** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMError& rst);
};
#endif

#endif

