/**
	* \file WznmJMControlTitle.h
	* database access for table TblWznmJMControlTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMJMCONTROLTITLE_H
#define WZNMJMCONTROLTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMControlTitle: record of TblWznmJMControlTitle
	*/
class WznmJMControlTitle {

public:
	WznmJMControlTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMControl;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmJMControlTitle& comp);
	bool operator!=(const WznmJMControlTitle& comp);
};

/**
	* ListWznmJMControlTitle: recordset of TblWznmJMControlTitle
	*/
class ListWznmJMControlTitle {

public:
	ListWznmJMControlTitle();
	ListWznmJMControlTitle(const ListWznmJMControlTitle& src);
	~ListWznmJMControlTitle();

	void clear();
	unsigned int size() const;
	void append(WznmJMControlTitle* rec);

	WznmJMControlTitle* operator[](const Sbecore::uint ix);
	ListWznmJMControlTitle& operator=(const ListWznmJMControlTitle& src);
	bool operator==(const ListWznmJMControlTitle& comp);
	bool operator!=(const ListWznmJMControlTitle& comp);

public:
	std::vector<WznmJMControlTitle*> nodes;
};

/**
	* TblWznmJMControlTitle: C++ wrapper for table TblWznmJMControlTitle
	*/
class TblWznmJMControlTitle {

public:

public:
	TblWznmJMControlTitle();
	virtual ~TblWznmJMControlTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMControlTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMControlTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmJMControlTitle* rec);
	Sbecore::ubigint insertNewRec(WznmJMControlTitle** rec = NULL, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMControlTitle& rst, WznmJMControlTitle** rec = NULL, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmJMControlTitle& rst, bool transact = false);
	virtual void updateRec(WznmJMControlTitle* rec);
	virtual void updateRst(ListWznmJMControlTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMControlTitle** rec);
	virtual bool loadRecByConLoc(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMLocale, WznmJMControlTitle** rec);
	virtual Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCon(Sbecore::ubigint refWznmMControl, const bool append, ListWznmJMControlTitle& rst);
	virtual bool loadTitByConLoc(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMControlTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMControlTitle: C++ wrapper for table TblWznmJMControlTitle (MySQL database)
	*/
class MyTblWznmJMControlTitle : public TblWznmJMControlTitle, public Sbecore::MyTable {

public:
	MyTblWznmJMControlTitle();
	~MyTblWznmJMControlTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMControlTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMControlTitle& rst);

	Sbecore::ubigint insertRec(WznmJMControlTitle* rec);
	void insertRst(ListWznmJMControlTitle& rst, bool transact = false);
	void updateRec(WznmJMControlTitle* rec);
	void updateRst(ListWznmJMControlTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMControlTitle** rec);
	bool loadRecByConLoc(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMLocale, WznmJMControlTitle** rec);
	Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refWznmMControl, const bool append, ListWznmJMControlTitle& rst);
	bool loadTitByConLoc(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMControlTitle: C++ wrapper for table TblWznmJMControlTitle (PgSQL database)
	*/
class PgTblWznmJMControlTitle : public TblWznmJMControlTitle, public Sbecore::PgTable {

public:
	PgTblWznmJMControlTitle();
	~PgTblWznmJMControlTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMControlTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMControlTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMControlTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMControlTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMControlTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMControlTitle& rst);

	Sbecore::ubigint insertRec(WznmJMControlTitle* rec);
	void insertRst(ListWznmJMControlTitle& rst, bool transact = false);
	void updateRec(WznmJMControlTitle* rec);
	void updateRst(ListWznmJMControlTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMControlTitle** rec);
	bool loadRecByConLoc(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMLocale, WznmJMControlTitle** rec);
	Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refWznmMControl, const bool append, ListWznmJMControlTitle& rst);
	bool loadTitByConLoc(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#endif

