/**
	* \file WznmJMSquawkTitle.h
	* database access for table TblWznmJMSquawkTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMJMSQUAWKTITLE_H
#define WZNMJMSQUAWKTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMSquawkTitle: record of TblWznmJMSquawkTitle
	*/
class WznmJMSquawkTitle {

public:
	WznmJMSquawkTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSquawk = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMSquawk;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmJMSquawkTitle& comp);
	bool operator!=(const WznmJMSquawkTitle& comp);
};

/**
	* ListWznmJMSquawkTitle: recordset of TblWznmJMSquawkTitle
	*/
class ListWznmJMSquawkTitle {

public:
	ListWznmJMSquawkTitle();
	ListWznmJMSquawkTitle(const ListWznmJMSquawkTitle& src);
	~ListWznmJMSquawkTitle();

	void clear();
	unsigned int size() const;
	void append(WznmJMSquawkTitle* rec);

	WznmJMSquawkTitle* operator[](const Sbecore::uint ix);
	ListWznmJMSquawkTitle& operator=(const ListWznmJMSquawkTitle& src);
	bool operator==(const ListWznmJMSquawkTitle& comp);
	bool operator!=(const ListWznmJMSquawkTitle& comp);

public:
	std::vector<WznmJMSquawkTitle*> nodes;
};

/**
	* TblWznmJMSquawkTitle: C++ wrapper for table TblWznmJMSquawkTitle
	*/
class TblWznmJMSquawkTitle {

public:

public:
	TblWznmJMSquawkTitle();
	virtual ~TblWznmJMSquawkTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMSquawkTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMSquawkTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmJMSquawkTitle* rec);
	Sbecore::ubigint insertNewRec(WznmJMSquawkTitle** rec = NULL, const Sbecore::ubigint refWznmMSquawk = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMSquawkTitle& rst, WznmJMSquawkTitle** rec = NULL, const Sbecore::ubigint refWznmMSquawk = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmJMSquawkTitle& rst, bool transact = false);
	virtual void updateRec(WznmJMSquawkTitle* rec);
	virtual void updateRst(ListWznmJMSquawkTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMSquawkTitle** rec);
	virtual bool loadRecBySqkLoc(Sbecore::ubigint refWznmMSquawk, Sbecore::ubigint x1RefWznmMLocale, WznmJMSquawkTitle** rec);
	virtual Sbecore::ubigint loadRefsBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, ListWznmJMSquawkTitle& rst);
	virtual bool loadTitBySqkLoc(Sbecore::ubigint refWznmMSquawk, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMSquawkTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMSquawkTitle: C++ wrapper for table TblWznmJMSquawkTitle (MySQL database)
	*/
class MyTblWznmJMSquawkTitle : public TblWznmJMSquawkTitle, public Sbecore::MyTable {

public:
	MyTblWznmJMSquawkTitle();
	~MyTblWznmJMSquawkTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMSquawkTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMSquawkTitle& rst);

	Sbecore::ubigint insertRec(WznmJMSquawkTitle* rec);
	void insertRst(ListWznmJMSquawkTitle& rst, bool transact = false);
	void updateRec(WznmJMSquawkTitle* rec);
	void updateRst(ListWznmJMSquawkTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMSquawkTitle** rec);
	bool loadRecBySqkLoc(Sbecore::ubigint refWznmMSquawk, Sbecore::ubigint x1RefWznmMLocale, WznmJMSquawkTitle** rec);
	Sbecore::ubigint loadRefsBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, ListWznmJMSquawkTitle& rst);
	bool loadTitBySqkLoc(Sbecore::ubigint refWznmMSquawk, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMSquawkTitle: C++ wrapper for table TblWznmJMSquawkTitle (PgSQL database)
	*/
class PgTblWznmJMSquawkTitle : public TblWznmJMSquawkTitle, public Sbecore::PgTable {

public:
	PgTblWznmJMSquawkTitle();
	~PgTblWznmJMSquawkTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMSquawkTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMSquawkTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMSquawkTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMSquawkTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMSquawkTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMSquawkTitle& rst);

	Sbecore::ubigint insertRec(WznmJMSquawkTitle* rec);
	void insertRst(ListWznmJMSquawkTitle& rst, bool transact = false);
	void updateRec(WznmJMSquawkTitle* rec);
	void updateRst(ListWznmJMSquawkTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMSquawkTitle** rec);
	bool loadRecBySqkLoc(Sbecore::ubigint refWznmMSquawk, Sbecore::ubigint x1RefWznmMLocale, WznmJMSquawkTitle** rec);
	Sbecore::ubigint loadRefsBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySqk(Sbecore::ubigint refWznmMSquawk, const bool append, ListWznmJMSquawkTitle& rst);
	bool loadTitBySqkLoc(Sbecore::ubigint refWznmMSquawk, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#endif

