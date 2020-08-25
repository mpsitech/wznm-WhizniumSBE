/**
	* \file WznmJMTagTitle.h
	* database access for table TblWznmJMTagTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMJMTAGTITLE_H
#define WZNMJMTAGTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMTagTitle: record of TblWznmJMTagTitle
	*/
class WznmJMTagTitle {

public:
	WznmJMTagTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMTag = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMTag;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmJMTagTitle& comp);
	bool operator!=(const WznmJMTagTitle& comp);
};

/**
	* ListWznmJMTagTitle: recordset of TblWznmJMTagTitle
	*/
class ListWznmJMTagTitle {

public:
	ListWznmJMTagTitle();
	ListWznmJMTagTitle(const ListWznmJMTagTitle& src);
	~ListWznmJMTagTitle();

	void clear();
	unsigned int size() const;
	void append(WznmJMTagTitle* rec);

	WznmJMTagTitle* operator[](const Sbecore::uint ix);
	ListWznmJMTagTitle& operator=(const ListWznmJMTagTitle& src);
	bool operator==(const ListWznmJMTagTitle& comp);
	bool operator!=(const ListWznmJMTagTitle& comp);

public:
	std::vector<WznmJMTagTitle*> nodes;
};

/**
	* TblWznmJMTagTitle: C++ wrapper for table TblWznmJMTagTitle
	*/
class TblWznmJMTagTitle {

public:

public:
	TblWznmJMTagTitle();
	virtual ~TblWznmJMTagTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMTagTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMTagTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmJMTagTitle* rec);
	Sbecore::ubigint insertNewRec(WznmJMTagTitle** rec = NULL, const Sbecore::ubigint refWznmMTag = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMTagTitle& rst, WznmJMTagTitle** rec = NULL, const Sbecore::ubigint refWznmMTag = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmJMTagTitle& rst, bool transact = false);
	virtual void updateRec(WznmJMTagTitle* rec);
	virtual void updateRst(ListWznmJMTagTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMTagTitle** rec);
	virtual bool loadRecByTagLoc(Sbecore::ubigint refWznmMTag, Sbecore::ubigint x1RefWznmMLocale, WznmJMTagTitle** rec);
	virtual Sbecore::ubigint loadRefsByTag(Sbecore::ubigint refWznmMTag, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTag(Sbecore::ubigint refWznmMTag, const bool append, ListWznmJMTagTitle& rst);
	virtual bool loadTitByTagLoc(Sbecore::ubigint refWznmMTag, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMTagTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMTagTitle: C++ wrapper for table TblWznmJMTagTitle (MySQL database)
	*/
class MyTblWznmJMTagTitle : public TblWznmJMTagTitle, public Sbecore::MyTable {

public:
	MyTblWznmJMTagTitle();
	~MyTblWznmJMTagTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMTagTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMTagTitle& rst);

	Sbecore::ubigint insertRec(WznmJMTagTitle* rec);
	void insertRst(ListWznmJMTagTitle& rst, bool transact = false);
	void updateRec(WznmJMTagTitle* rec);
	void updateRst(ListWznmJMTagTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMTagTitle** rec);
	bool loadRecByTagLoc(Sbecore::ubigint refWznmMTag, Sbecore::ubigint x1RefWznmMLocale, WznmJMTagTitle** rec);
	Sbecore::ubigint loadRefsByTag(Sbecore::ubigint refWznmMTag, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTag(Sbecore::ubigint refWznmMTag, const bool append, ListWznmJMTagTitle& rst);
	bool loadTitByTagLoc(Sbecore::ubigint refWznmMTag, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMTagTitle: C++ wrapper for table TblWznmJMTagTitle (PgSQL database)
	*/
class PgTblWznmJMTagTitle : public TblWznmJMTagTitle, public Sbecore::PgTable {

public:
	PgTblWznmJMTagTitle();
	~PgTblWznmJMTagTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMTagTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMTagTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMTagTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMTagTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMTagTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMTagTitle& rst);

	Sbecore::ubigint insertRec(WznmJMTagTitle* rec);
	void insertRst(ListWznmJMTagTitle& rst, bool transact = false);
	void updateRec(WznmJMTagTitle* rec);
	void updateRst(ListWznmJMTagTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMTagTitle** rec);
	bool loadRecByTagLoc(Sbecore::ubigint refWznmMTag, Sbecore::ubigint x1RefWznmMLocale, WznmJMTagTitle** rec);
	Sbecore::ubigint loadRefsByTag(Sbecore::ubigint refWznmMTag, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTag(Sbecore::ubigint refWznmMTag, const bool append, ListWznmJMTagTitle& rst);
	bool loadTitByTagLoc(Sbecore::ubigint refWznmMTag, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#endif

