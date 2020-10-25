/**
	* \file WznmJMLocaleTitle.h
	* database access for table TblWznmJMLocaleTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMJMLOCALETITLE_H
#define WZNMJMLOCALETITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMLocaleTitle: record of TblWznmJMLocaleTitle
	*/
class WznmJMLocaleTitle {

public:
	WznmJMLocaleTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMLocale = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMLocale;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmJMLocaleTitle& comp);
	bool operator!=(const WznmJMLocaleTitle& comp);
};

/**
	* ListWznmJMLocaleTitle: recordset of TblWznmJMLocaleTitle
	*/
class ListWznmJMLocaleTitle {

public:
	ListWznmJMLocaleTitle();
	ListWznmJMLocaleTitle(const ListWznmJMLocaleTitle& src);
	~ListWznmJMLocaleTitle();

	void clear();
	unsigned int size() const;
	void append(WznmJMLocaleTitle* rec);

	WznmJMLocaleTitle* operator[](const Sbecore::uint ix);
	ListWznmJMLocaleTitle& operator=(const ListWznmJMLocaleTitle& src);
	bool operator==(const ListWznmJMLocaleTitle& comp);
	bool operator!=(const ListWznmJMLocaleTitle& comp);

public:
	std::vector<WznmJMLocaleTitle*> nodes;
};

/**
	* TblWznmJMLocaleTitle: C++ wrapper for table TblWznmJMLocaleTitle
	*/
class TblWznmJMLocaleTitle {

public:

public:
	TblWznmJMLocaleTitle();
	virtual ~TblWznmJMLocaleTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMLocaleTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMLocaleTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmJMLocaleTitle* rec);
	Sbecore::ubigint insertNewRec(WznmJMLocaleTitle** rec = NULL, const Sbecore::ubigint refWznmMLocale = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMLocaleTitle& rst, WznmJMLocaleTitle** rec = NULL, const Sbecore::ubigint refWznmMLocale = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmJMLocaleTitle& rst, bool transact = false);
	virtual void updateRec(WznmJMLocaleTitle* rec);
	virtual void updateRst(ListWznmJMLocaleTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMLocaleTitle** rec);
	virtual bool loadRecByLocLo2(Sbecore::ubigint refWznmMLocale, Sbecore::ubigint x1RefWznmMLocale, WznmJMLocaleTitle** rec);
	virtual Sbecore::ubigint loadRefsByLoc(Sbecore::ubigint refWznmMLocale, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refWznmMLocale, const bool append, ListWznmJMLocaleTitle& rst);
	virtual bool loadTitByLocLo2(Sbecore::ubigint refWznmMLocale, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMLocaleTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMLocaleTitle: C++ wrapper for table TblWznmJMLocaleTitle (MySQL database)
	*/
class MyTblWznmJMLocaleTitle : public TblWznmJMLocaleTitle, public Sbecore::MyTable {

public:
	MyTblWznmJMLocaleTitle();
	~MyTblWznmJMLocaleTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMLocaleTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMLocaleTitle& rst);

	Sbecore::ubigint insertRec(WznmJMLocaleTitle* rec);
	void insertRst(ListWznmJMLocaleTitle& rst, bool transact = false);
	void updateRec(WznmJMLocaleTitle* rec);
	void updateRst(ListWznmJMLocaleTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMLocaleTitle** rec);
	bool loadRecByLocLo2(Sbecore::ubigint refWznmMLocale, Sbecore::ubigint x1RefWznmMLocale, WznmJMLocaleTitle** rec);
	Sbecore::ubigint loadRefsByLoc(Sbecore::ubigint refWznmMLocale, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refWznmMLocale, const bool append, ListWznmJMLocaleTitle& rst);
	bool loadTitByLocLo2(Sbecore::ubigint refWznmMLocale, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMLocaleTitle: C++ wrapper for table TblWznmJMLocaleTitle (PgSQL database)
	*/
class PgTblWznmJMLocaleTitle : public TblWznmJMLocaleTitle, public Sbecore::PgTable {

public:
	PgTblWznmJMLocaleTitle();
	~PgTblWznmJMLocaleTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMLocaleTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMLocaleTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMLocaleTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMLocaleTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMLocaleTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMLocaleTitle& rst);

	Sbecore::ubigint insertRec(WznmJMLocaleTitle* rec);
	void insertRst(ListWznmJMLocaleTitle& rst, bool transact = false);
	void updateRec(WznmJMLocaleTitle* rec);
	void updateRst(ListWznmJMLocaleTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMLocaleTitle** rec);
	bool loadRecByLocLo2(Sbecore::ubigint refWznmMLocale, Sbecore::ubigint x1RefWznmMLocale, WznmJMLocaleTitle** rec);
	Sbecore::ubigint loadRefsByLoc(Sbecore::ubigint refWznmMLocale, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLoc(Sbecore::ubigint refWznmMLocale, const bool append, ListWznmJMLocaleTitle& rst);
	bool loadTitByLocLo2(Sbecore::ubigint refWznmMLocale, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#endif

