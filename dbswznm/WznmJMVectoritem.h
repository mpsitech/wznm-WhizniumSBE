/**
	* \file WznmJMVectoritem.h
	* database access for table TblWznmJMVectoritem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMJMVECTORITEM_H
#define WZNMJMVECTORITEM_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMVectoritem: record of TblWznmJMVectoritem
	*/
class WznmJMVectoritem {

public:
	WznmJMVectoritem(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMVectoritem;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WznmJMVectoritem& comp);
	bool operator!=(const WznmJMVectoritem& comp);
};

/**
	* ListWznmJMVectoritem: recordset of TblWznmJMVectoritem
	*/
class ListWznmJMVectoritem {

public:
	ListWznmJMVectoritem();
	ListWznmJMVectoritem(const ListWznmJMVectoritem& src);
	~ListWznmJMVectoritem();

	void clear();
	unsigned int size() const;
	void append(WznmJMVectoritem* rec);

	WznmJMVectoritem* operator[](const Sbecore::uint ix);
	ListWznmJMVectoritem& operator=(const ListWznmJMVectoritem& src);
	bool operator==(const ListWznmJMVectoritem& comp);
	bool operator!=(const ListWznmJMVectoritem& comp);

public:
	std::vector<WznmJMVectoritem*> nodes;
};

/**
	* TblWznmJMVectoritem: C++ wrapper for table TblWznmJMVectoritem
	*/
class TblWznmJMVectoritem {

public:

public:
	TblWznmJMVectoritem();
	virtual ~TblWznmJMVectoritem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMVectoritem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMVectoritem& rst);

	virtual Sbecore::ubigint insertRec(WznmJMVectoritem* rec);
	Sbecore::ubigint insertNewRec(WznmJMVectoritem** rec = NULL, const Sbecore::ubigint refWznmMVectoritem = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMVectoritem& rst, WznmJMVectoritem** rec = NULL, const Sbecore::ubigint refWznmMVectoritem = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmJMVectoritem& rst, bool transact = false);
	virtual void updateRec(WznmJMVectoritem* rec);
	virtual void updateRst(ListWznmJMVectoritem& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMVectoritem** rec);
	virtual bool loadRecByVitLoc(Sbecore::ubigint refWznmMVectoritem, Sbecore::ubigint x1RefWznmMLocale, WznmJMVectoritem** rec);
	virtual Sbecore::ubigint loadRefsByVit(Sbecore::ubigint refWznmMVectoritem, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByVit(Sbecore::ubigint refWznmMVectoritem, const bool append, ListWznmJMVectoritem& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMVectoritem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMVectoritem: C++ wrapper for table TblWznmJMVectoritem (MySQL database)
	*/
class MyTblWznmJMVectoritem : public TblWznmJMVectoritem, public Sbecore::MyTable {

public:
	MyTblWznmJMVectoritem();
	~MyTblWznmJMVectoritem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMVectoritem& rst);

	Sbecore::ubigint insertRec(WznmJMVectoritem* rec);
	void insertRst(ListWznmJMVectoritem& rst, bool transact = false);
	void updateRec(WznmJMVectoritem* rec);
	void updateRst(ListWznmJMVectoritem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMVectoritem** rec);
	bool loadRecByVitLoc(Sbecore::ubigint refWznmMVectoritem, Sbecore::ubigint x1RefWznmMLocale, WznmJMVectoritem** rec);
	Sbecore::ubigint loadRefsByVit(Sbecore::ubigint refWznmMVectoritem, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVit(Sbecore::ubigint refWznmMVectoritem, const bool append, ListWznmJMVectoritem& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMVectoritem: C++ wrapper for table TblWznmJMVectoritem (PgSQL database)
	*/
class PgTblWznmJMVectoritem : public TblWznmJMVectoritem, public Sbecore::PgTable {

public:
	PgTblWznmJMVectoritem();
	~PgTblWznmJMVectoritem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMVectoritem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMVectoritem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMVectoritem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMVectoritem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMVectoritem& rst);

	Sbecore::ubigint insertRec(WznmJMVectoritem* rec);
	void insertRst(ListWznmJMVectoritem& rst, bool transact = false);
	void updateRec(WznmJMVectoritem* rec);
	void updateRst(ListWznmJMVectoritem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMVectoritem** rec);
	bool loadRecByVitLoc(Sbecore::ubigint refWznmMVectoritem, Sbecore::ubigint x1RefWznmMLocale, WznmJMVectoritem** rec);
	Sbecore::ubigint loadRefsByVit(Sbecore::ubigint refWznmMVectoritem, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVit(Sbecore::ubigint refWznmMVectoritem, const bool append, ListWznmJMVectoritem& rst);
};
#endif

#endif

