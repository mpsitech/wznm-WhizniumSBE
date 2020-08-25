/**
	* \file WznmRMPanelMQuery.h
	* database access for table TblWznmRMPanelMQuery (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMRMPANELMQUERY_H
#define WZNMRMPANELMQUERY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMPanelMQuery: record of TblWznmRMPanelMQuery
	*/
class WznmRMPanelMQuery {

public:
	WznmRMPanelMQuery(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMPanel = 0, const Sbecore::ubigint refWznmMQuery = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMPanel;
	Sbecore::ubigint refWznmMQuery;

public:
	bool operator==(const WznmRMPanelMQuery& comp);
	bool operator!=(const WznmRMPanelMQuery& comp);
};

/**
	* ListWznmRMPanelMQuery: recordset of TblWznmRMPanelMQuery
	*/
class ListWznmRMPanelMQuery {

public:
	ListWznmRMPanelMQuery();
	ListWznmRMPanelMQuery(const ListWznmRMPanelMQuery& src);
	~ListWznmRMPanelMQuery();

	void clear();
	unsigned int size() const;
	void append(WznmRMPanelMQuery* rec);

	WznmRMPanelMQuery* operator[](const Sbecore::uint ix);
	ListWznmRMPanelMQuery& operator=(const ListWznmRMPanelMQuery& src);
	bool operator==(const ListWznmRMPanelMQuery& comp);
	bool operator!=(const ListWznmRMPanelMQuery& comp);

public:
	std::vector<WznmRMPanelMQuery*> nodes;
};

/**
	* TblWznmRMPanelMQuery: C++ wrapper for table TblWznmRMPanelMQuery
	*/
class TblWznmRMPanelMQuery {

public:

public:
	TblWznmRMPanelMQuery();
	virtual ~TblWznmRMPanelMQuery();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMPanelMQuery** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMPanelMQuery& rst);

	virtual Sbecore::ubigint insertRec(WznmRMPanelMQuery* rec);
	Sbecore::ubigint insertNewRec(WznmRMPanelMQuery** rec = NULL, const Sbecore::ubigint refWznmMPanel = 0, const Sbecore::ubigint refWznmMQuery = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMPanelMQuery& rst, WznmRMPanelMQuery** rec = NULL, const Sbecore::ubigint refWznmMPanel = 0, const Sbecore::ubigint refWznmMQuery = 0);
	virtual void insertRst(ListWznmRMPanelMQuery& rst, bool transact = false);
	virtual void updateRec(WznmRMPanelMQuery* rec);
	virtual void updateRst(ListWznmRMPanelMQuery& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMPanelMQuery** rec);
	virtual Sbecore::ubigint loadPnlsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refWznmMPanels);
	virtual Sbecore::ubigint loadQrysByPnl(Sbecore::ubigint refWznmMPanel, const bool append, std::vector<Sbecore::ubigint>& refWznmMQuerys);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMPanelMQuery& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMPanelMQuery: C++ wrapper for table TblWznmRMPanelMQuery (MySQL database)
	*/
class MyTblWznmRMPanelMQuery : public TblWznmRMPanelMQuery, public Sbecore::MyTable {

public:
	MyTblWznmRMPanelMQuery();
	~MyTblWznmRMPanelMQuery();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMPanelMQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMPanelMQuery& rst);

	Sbecore::ubigint insertRec(WznmRMPanelMQuery* rec);
	void insertRst(ListWznmRMPanelMQuery& rst, bool transact = false);
	void updateRec(WznmRMPanelMQuery* rec);
	void updateRst(ListWznmRMPanelMQuery& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMPanelMQuery** rec);
	Sbecore::ubigint loadPnlsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refWznmMPanels);
	Sbecore::ubigint loadQrysByPnl(Sbecore::ubigint refWznmMPanel, const bool append, std::vector<Sbecore::ubigint>& refWznmMQuerys);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMPanelMQuery: C++ wrapper for table TblWznmRMPanelMQuery (PgSQL database)
	*/
class PgTblWznmRMPanelMQuery : public TblWznmRMPanelMQuery, public Sbecore::PgTable {

public:
	PgTblWznmRMPanelMQuery();
	~PgTblWznmRMPanelMQuery();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMPanelMQuery** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMPanelMQuery& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMPanelMQuery** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMPanelMQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMPanelMQuery& rst);

	Sbecore::ubigint insertRec(WznmRMPanelMQuery* rec);
	void insertRst(ListWznmRMPanelMQuery& rst, bool transact = false);
	void updateRec(WznmRMPanelMQuery* rec);
	void updateRst(ListWznmRMPanelMQuery& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMPanelMQuery** rec);
	Sbecore::ubigint loadPnlsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refWznmMPanels);
	Sbecore::ubigint loadQrysByPnl(Sbecore::ubigint refWznmMPanel, const bool append, std::vector<Sbecore::ubigint>& refWznmMQuerys);
};
#endif

#endif

