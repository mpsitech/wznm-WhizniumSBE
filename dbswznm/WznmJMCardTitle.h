/**
	* \file WznmJMCardTitle.h
	* database access for table TblWznmJMCardTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMJMCARDTITLE_H
#define WZNMJMCARDTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMCardTitle: record of TblWznmJMCardTitle
	*/
class WznmJMCardTitle {

public:
	WznmJMCardTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMCard = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMCard;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmJMCardTitle& comp);
	bool operator!=(const WznmJMCardTitle& comp);
};

/**
	* ListWznmJMCardTitle: recordset of TblWznmJMCardTitle
	*/
class ListWznmJMCardTitle {

public:
	ListWznmJMCardTitle();
	ListWznmJMCardTitle(const ListWznmJMCardTitle& src);
	~ListWznmJMCardTitle();

	void clear();
	unsigned int size() const;
	void append(WznmJMCardTitle* rec);

	WznmJMCardTitle* operator[](const Sbecore::uint ix);
	ListWznmJMCardTitle& operator=(const ListWznmJMCardTitle& src);
	bool operator==(const ListWznmJMCardTitle& comp);
	bool operator!=(const ListWznmJMCardTitle& comp);

public:
	std::vector<WznmJMCardTitle*> nodes;
};

/**
	* TblWznmJMCardTitle: C++ wrapper for table TblWznmJMCardTitle
	*/
class TblWznmJMCardTitle {

public:

public:
	TblWznmJMCardTitle();
	virtual ~TblWznmJMCardTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMCardTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMCardTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmJMCardTitle* rec);
	Sbecore::ubigint insertNewRec(WznmJMCardTitle** rec = NULL, const Sbecore::ubigint refWznmMCard = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMCardTitle& rst, WznmJMCardTitle** rec = NULL, const Sbecore::ubigint refWznmMCard = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmJMCardTitle& rst, bool transact = false);
	virtual void updateRec(WznmJMCardTitle* rec);
	virtual void updateRst(ListWznmJMCardTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMCardTitle** rec);
	virtual bool loadRecByCarLoc(Sbecore::ubigint refWznmMCard, Sbecore::ubigint x1RefWznmMLocale, WznmJMCardTitle** rec);
	virtual Sbecore::ubigint loadRefsByCar(Sbecore::ubigint refWznmMCard, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCar(Sbecore::ubigint refWznmMCard, const bool append, ListWznmJMCardTitle& rst);
	virtual bool loadTitByCarLoc(Sbecore::ubigint refWznmMCard, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMCardTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMCardTitle: C++ wrapper for table TblWznmJMCardTitle (MySQL database)
	*/
class MyTblWznmJMCardTitle : public TblWznmJMCardTitle, public Sbecore::MyTable {

public:
	MyTblWznmJMCardTitle();
	~MyTblWznmJMCardTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMCardTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMCardTitle& rst);

	Sbecore::ubigint insertRec(WznmJMCardTitle* rec);
	void insertRst(ListWznmJMCardTitle& rst, bool transact = false);
	void updateRec(WznmJMCardTitle* rec);
	void updateRst(ListWznmJMCardTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMCardTitle** rec);
	bool loadRecByCarLoc(Sbecore::ubigint refWznmMCard, Sbecore::ubigint x1RefWznmMLocale, WznmJMCardTitle** rec);
	Sbecore::ubigint loadRefsByCar(Sbecore::ubigint refWznmMCard, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCar(Sbecore::ubigint refWznmMCard, const bool append, ListWznmJMCardTitle& rst);
	bool loadTitByCarLoc(Sbecore::ubigint refWznmMCard, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMCardTitle: C++ wrapper for table TblWznmJMCardTitle (PgSQL database)
	*/
class PgTblWznmJMCardTitle : public TblWznmJMCardTitle, public Sbecore::PgTable {

public:
	PgTblWznmJMCardTitle();
	~PgTblWznmJMCardTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMCardTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMCardTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMCardTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMCardTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMCardTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMCardTitle& rst);

	Sbecore::ubigint insertRec(WznmJMCardTitle* rec);
	void insertRst(ListWznmJMCardTitle& rst, bool transact = false);
	void updateRec(WznmJMCardTitle* rec);
	void updateRst(ListWznmJMCardTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMCardTitle** rec);
	bool loadRecByCarLoc(Sbecore::ubigint refWznmMCard, Sbecore::ubigint x1RefWznmMLocale, WznmJMCardTitle** rec);
	Sbecore::ubigint loadRefsByCar(Sbecore::ubigint refWznmMCard, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCar(Sbecore::ubigint refWznmMCard, const bool append, ListWznmJMCardTitle& rst);
	bool loadTitByCarLoc(Sbecore::ubigint refWznmMCard, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#endif

