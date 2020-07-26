/**
	* \file WznmJMErrorTitle.h
	* database access for table TblWznmJMErrorTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMJMERRORTITLE_H
#define WZNMJMERRORTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMErrorTitle: record of TblWznmJMErrorTitle
	*/
class WznmJMErrorTitle {

public:
	WznmJMErrorTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMError = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMError;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmJMErrorTitle& comp);
	bool operator!=(const WznmJMErrorTitle& comp);
};

/**
	* ListWznmJMErrorTitle: recordset of TblWznmJMErrorTitle
	*/
class ListWznmJMErrorTitle {

public:
	ListWznmJMErrorTitle();
	ListWznmJMErrorTitle(const ListWznmJMErrorTitle& src);
	~ListWznmJMErrorTitle();

	void clear();
	unsigned int size() const;
	void append(WznmJMErrorTitle* rec);

	WznmJMErrorTitle* operator[](const Sbecore::uint ix);
	ListWznmJMErrorTitle& operator=(const ListWznmJMErrorTitle& src);
	bool operator==(const ListWznmJMErrorTitle& comp);
	bool operator!=(const ListWznmJMErrorTitle& comp);

public:
	std::vector<WznmJMErrorTitle*> nodes;
};

/**
	* TblWznmJMErrorTitle: C++ wrapper for table TblWznmJMErrorTitle
	*/
class TblWznmJMErrorTitle {

public:

public:
	TblWznmJMErrorTitle();
	virtual ~TblWznmJMErrorTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMErrorTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMErrorTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmJMErrorTitle* rec);
	Sbecore::ubigint insertNewRec(WznmJMErrorTitle** rec = NULL, const Sbecore::ubigint refWznmMError = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMErrorTitle& rst, WznmJMErrorTitle** rec = NULL, const Sbecore::ubigint refWznmMError = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmJMErrorTitle& rst, bool transact = false);
	virtual void updateRec(WznmJMErrorTitle* rec);
	virtual void updateRst(ListWznmJMErrorTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMErrorTitle** rec);
	virtual bool loadRecByErrLoc(Sbecore::ubigint refWznmMError, Sbecore::ubigint x1RefWznmMLocale, WznmJMErrorTitle** rec);
	virtual Sbecore::ubigint loadRefsByErr(Sbecore::ubigint refWznmMError, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByErr(Sbecore::ubigint refWznmMError, const bool append, ListWznmJMErrorTitle& rst);
	virtual bool loadTitByErrLoc(Sbecore::ubigint refWznmMError, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMErrorTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMErrorTitle: C++ wrapper for table TblWznmJMErrorTitle (MySQL database)
	*/
class MyTblWznmJMErrorTitle : public TblWznmJMErrorTitle, public Sbecore::MyTable {

public:
	MyTblWznmJMErrorTitle();
	~MyTblWznmJMErrorTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMErrorTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMErrorTitle& rst);

	Sbecore::ubigint insertRec(WznmJMErrorTitle* rec);
	void insertRst(ListWznmJMErrorTitle& rst, bool transact = false);
	void updateRec(WznmJMErrorTitle* rec);
	void updateRst(ListWznmJMErrorTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMErrorTitle** rec);
	bool loadRecByErrLoc(Sbecore::ubigint refWznmMError, Sbecore::ubigint x1RefWznmMLocale, WznmJMErrorTitle** rec);
	Sbecore::ubigint loadRefsByErr(Sbecore::ubigint refWznmMError, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByErr(Sbecore::ubigint refWznmMError, const bool append, ListWznmJMErrorTitle& rst);
	bool loadTitByErrLoc(Sbecore::ubigint refWznmMError, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMErrorTitle: C++ wrapper for table TblWznmJMErrorTitle (PgSQL database)
	*/
class PgTblWznmJMErrorTitle : public TblWznmJMErrorTitle, public Sbecore::PgTable {

public:
	PgTblWznmJMErrorTitle();
	~PgTblWznmJMErrorTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMErrorTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMErrorTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMErrorTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMErrorTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMErrorTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMErrorTitle& rst);

	Sbecore::ubigint insertRec(WznmJMErrorTitle* rec);
	void insertRst(ListWznmJMErrorTitle& rst, bool transact = false);
	void updateRec(WznmJMErrorTitle* rec);
	void updateRst(ListWznmJMErrorTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMErrorTitle** rec);
	bool loadRecByErrLoc(Sbecore::ubigint refWznmMError, Sbecore::ubigint x1RefWznmMLocale, WznmJMErrorTitle** rec);
	Sbecore::ubigint loadRefsByErr(Sbecore::ubigint refWznmMError, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByErr(Sbecore::ubigint refWznmMError, const bool append, ListWznmJMErrorTitle& rst);
	bool loadTitByErrLoc(Sbecore::ubigint refWznmMError, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#endif

