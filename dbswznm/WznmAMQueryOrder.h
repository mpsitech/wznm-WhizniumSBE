/**
	* \file WznmAMQueryOrder.h
	* database access for table TblWznmAMQueryOrder (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMAMQUERYORDER_H
#define WZNMAMQUERYORDER_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMQueryOrder: record of TblWznmAMQueryOrder
	*/
class WznmAMQueryOrder {

public:
	WznmAMQueryOrder(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMQuery = 0, const std::string Short = "", const std::string srefsWznmMTablecol = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMQuery;
	std::string Short;
	std::string srefsWznmMTablecol;

public:
	bool operator==(const WznmAMQueryOrder& comp);
	bool operator!=(const WznmAMQueryOrder& comp);
};

/**
	* ListWznmAMQueryOrder: recordset of TblWznmAMQueryOrder
	*/
class ListWznmAMQueryOrder {

public:
	ListWznmAMQueryOrder();
	ListWznmAMQueryOrder(const ListWznmAMQueryOrder& src);
	~ListWznmAMQueryOrder();

	void clear();
	unsigned int size() const;
	void append(WznmAMQueryOrder* rec);

	WznmAMQueryOrder* operator[](const Sbecore::uint ix);
	ListWznmAMQueryOrder& operator=(const ListWznmAMQueryOrder& src);
	bool operator==(const ListWznmAMQueryOrder& comp);
	bool operator!=(const ListWznmAMQueryOrder& comp);

public:
	std::vector<WznmAMQueryOrder*> nodes;
};

/**
	* TblWznmAMQueryOrder: C++ wrapper for table TblWznmAMQueryOrder
	*/
class TblWznmAMQueryOrder {

public:

public:
	TblWznmAMQueryOrder();
	virtual ~TblWznmAMQueryOrder();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMQueryOrder** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMQueryOrder& rst);

	virtual Sbecore::ubigint insertRec(WznmAMQueryOrder* rec);
	Sbecore::ubigint insertNewRec(WznmAMQueryOrder** rec = NULL, const Sbecore::ubigint refWznmMQuery = 0, const std::string Short = "", const std::string srefsWznmMTablecol = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMQueryOrder& rst, WznmAMQueryOrder** rec = NULL, const Sbecore::ubigint refWznmMQuery = 0, const std::string Short = "", const std::string srefsWznmMTablecol = "");
	virtual void insertRst(ListWznmAMQueryOrder& rst, bool transact = false);
	virtual void updateRec(WznmAMQueryOrder* rec);
	virtual void updateRst(ListWznmAMQueryOrder& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMQueryOrder** rec);
	virtual Sbecore::ubigint loadRefsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByQry(Sbecore::ubigint refWznmMQuery, const bool append, ListWznmAMQueryOrder& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMQueryOrder& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMQueryOrder: C++ wrapper for table TblWznmAMQueryOrder (MySQL database)
	*/
class MyTblWznmAMQueryOrder : public TblWznmAMQueryOrder, public Sbecore::MyTable {

public:
	MyTblWznmAMQueryOrder();
	~MyTblWznmAMQueryOrder();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMQueryOrder** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMQueryOrder& rst);

	Sbecore::ubigint insertRec(WznmAMQueryOrder* rec);
	void insertRst(ListWznmAMQueryOrder& rst, bool transact = false);
	void updateRec(WznmAMQueryOrder* rec);
	void updateRst(ListWznmAMQueryOrder& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMQueryOrder** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint refWznmMQuery, const bool append, ListWznmAMQueryOrder& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMQueryOrder: C++ wrapper for table TblWznmAMQueryOrder (PgSQL database)
	*/
class PgTblWznmAMQueryOrder : public TblWznmAMQueryOrder, public Sbecore::PgTable {

public:
	PgTblWznmAMQueryOrder();
	~PgTblWznmAMQueryOrder();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMQueryOrder** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMQueryOrder& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMQueryOrder** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMQueryOrder& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMQueryOrder** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMQueryOrder& rst);

	Sbecore::ubigint insertRec(WznmAMQueryOrder* rec);
	void insertRst(ListWznmAMQueryOrder& rst, bool transact = false);
	void updateRec(WznmAMQueryOrder* rec);
	void updateRst(ListWznmAMQueryOrder& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMQueryOrder** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint refWznmMQuery, const bool append, ListWznmAMQueryOrder& rst);
};
#endif

#endif

