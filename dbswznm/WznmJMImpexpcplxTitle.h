/**
	* \file WznmJMImpexpcplxTitle.h
	* database access for table TblWznmJMImpexpcplxTitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMJMIMPEXPCPLXTITLE_H
#define WZNMJMIMPEXPCPLXTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMImpexpcplxTitle: record of TblWznmJMImpexpcplxTitle
	*/
class WznmJMImpexpcplxTitle {

public:
	WznmJMImpexpcplxTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMImpexpcplx = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMImpexpcplx;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmJMImpexpcplxTitle& comp);
	bool operator!=(const WznmJMImpexpcplxTitle& comp);
};

/**
	* ListWznmJMImpexpcplxTitle: recordset of TblWznmJMImpexpcplxTitle
	*/
class ListWznmJMImpexpcplxTitle {

public:
	ListWznmJMImpexpcplxTitle();
	ListWznmJMImpexpcplxTitle(const ListWznmJMImpexpcplxTitle& src);
	~ListWznmJMImpexpcplxTitle();

	void clear();
	unsigned int size() const;
	void append(WznmJMImpexpcplxTitle* rec);

	WznmJMImpexpcplxTitle* operator[](const Sbecore::uint ix);
	ListWznmJMImpexpcplxTitle& operator=(const ListWznmJMImpexpcplxTitle& src);
	bool operator==(const ListWznmJMImpexpcplxTitle& comp);
	bool operator!=(const ListWznmJMImpexpcplxTitle& comp);

public:
	std::vector<WznmJMImpexpcplxTitle*> nodes;
};

/**
	* TblWznmJMImpexpcplxTitle: C++ wrapper for table TblWznmJMImpexpcplxTitle
	*/
class TblWznmJMImpexpcplxTitle {

public:

public:
	TblWznmJMImpexpcplxTitle();
	virtual ~TblWznmJMImpexpcplxTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMImpexpcplxTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMImpexpcplxTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmJMImpexpcplxTitle* rec);
	Sbecore::ubigint insertNewRec(WznmJMImpexpcplxTitle** rec = NULL, const Sbecore::ubigint refWznmMImpexpcplx = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMImpexpcplxTitle& rst, WznmJMImpexpcplxTitle** rec = NULL, const Sbecore::ubigint refWznmMImpexpcplx = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmJMImpexpcplxTitle& rst, bool transact = false);
	virtual void updateRec(WznmJMImpexpcplxTitle* rec);
	virtual void updateRst(ListWznmJMImpexpcplxTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMImpexpcplxTitle** rec);
	virtual bool loadRecByIexLoc(Sbecore::ubigint refWznmMImpexpcplx, Sbecore::ubigint x1RefWznmMLocale, WznmJMImpexpcplxTitle** rec);
	virtual Sbecore::ubigint loadRefsByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, ListWznmJMImpexpcplxTitle& rst);
	virtual bool loadTitByIexLoc(Sbecore::ubigint refWznmMImpexpcplx, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMImpexpcplxTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMImpexpcplxTitle: C++ wrapper for table TblWznmJMImpexpcplxTitle (MySQL database)
	*/
class MyTblWznmJMImpexpcplxTitle : public TblWznmJMImpexpcplxTitle, public Sbecore::MyTable {

public:
	MyTblWznmJMImpexpcplxTitle();
	~MyTblWznmJMImpexpcplxTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMImpexpcplxTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMImpexpcplxTitle& rst);

	Sbecore::ubigint insertRec(WznmJMImpexpcplxTitle* rec);
	void insertRst(ListWznmJMImpexpcplxTitle& rst, bool transact = false);
	void updateRec(WznmJMImpexpcplxTitle* rec);
	void updateRst(ListWznmJMImpexpcplxTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMImpexpcplxTitle** rec);
	bool loadRecByIexLoc(Sbecore::ubigint refWznmMImpexpcplx, Sbecore::ubigint x1RefWznmMLocale, WznmJMImpexpcplxTitle** rec);
	Sbecore::ubigint loadRefsByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, ListWznmJMImpexpcplxTitle& rst);
	bool loadTitByIexLoc(Sbecore::ubigint refWznmMImpexpcplx, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMImpexpcplxTitle: C++ wrapper for table TblWznmJMImpexpcplxTitle (PgSQL database)
	*/
class PgTblWznmJMImpexpcplxTitle : public TblWznmJMImpexpcplxTitle, public Sbecore::PgTable {

public:
	PgTblWznmJMImpexpcplxTitle();
	~PgTblWznmJMImpexpcplxTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMImpexpcplxTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMImpexpcplxTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMImpexpcplxTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMImpexpcplxTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMImpexpcplxTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMImpexpcplxTitle& rst);

	Sbecore::ubigint insertRec(WznmJMImpexpcplxTitle* rec);
	void insertRst(ListWznmJMImpexpcplxTitle& rst, bool transact = false);
	void updateRec(WznmJMImpexpcplxTitle* rec);
	void updateRst(ListWznmJMImpexpcplxTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMImpexpcplxTitle** rec);
	bool loadRecByIexLoc(Sbecore::ubigint refWznmMImpexpcplx, Sbecore::ubigint x1RefWznmMLocale, WznmJMImpexpcplxTitle** rec);
	Sbecore::ubigint loadRefsByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, ListWznmJMImpexpcplxTitle& rst);
	bool loadTitByIexLoc(Sbecore::ubigint refWznmMImpexpcplx, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#endif

