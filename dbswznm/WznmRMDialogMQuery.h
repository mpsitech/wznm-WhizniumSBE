/**
	* \file WznmRMDialogMQuery.h
	* database access for table TblWznmRMDialogMQuery (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMRMDIALOGMQUERY_H
#define WZNMRMDIALOGMQUERY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMDialogMQuery: record of TblWznmRMDialogMQuery
	*/
class WznmRMDialogMQuery {

public:
	WznmRMDialogMQuery(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMDialog = 0, const Sbecore::ubigint refWznmMQuery = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMDialog;
	Sbecore::ubigint refWznmMQuery;

public:
	bool operator==(const WznmRMDialogMQuery& comp);
	bool operator!=(const WznmRMDialogMQuery& comp);
};

/**
	* ListWznmRMDialogMQuery: recordset of TblWznmRMDialogMQuery
	*/
class ListWznmRMDialogMQuery {

public:
	ListWznmRMDialogMQuery();
	ListWznmRMDialogMQuery(const ListWznmRMDialogMQuery& src);
	~ListWznmRMDialogMQuery();

	void clear();
	unsigned int size() const;
	void append(WznmRMDialogMQuery* rec);

	WznmRMDialogMQuery* operator[](const Sbecore::uint ix);
	ListWznmRMDialogMQuery& operator=(const ListWznmRMDialogMQuery& src);
	bool operator==(const ListWznmRMDialogMQuery& comp);
	bool operator!=(const ListWznmRMDialogMQuery& comp);

public:
	std::vector<WznmRMDialogMQuery*> nodes;
};

/**
	* TblWznmRMDialogMQuery: C++ wrapper for table TblWznmRMDialogMQuery
	*/
class TblWznmRMDialogMQuery {

public:

public:
	TblWznmRMDialogMQuery();
	virtual ~TblWznmRMDialogMQuery();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMDialogMQuery** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMDialogMQuery& rst);

	virtual Sbecore::ubigint insertRec(WznmRMDialogMQuery* rec);
	Sbecore::ubigint insertNewRec(WznmRMDialogMQuery** rec = NULL, const Sbecore::ubigint refWznmMDialog = 0, const Sbecore::ubigint refWznmMQuery = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMDialogMQuery& rst, WznmRMDialogMQuery** rec = NULL, const Sbecore::ubigint refWznmMDialog = 0, const Sbecore::ubigint refWznmMQuery = 0);
	virtual void insertRst(ListWznmRMDialogMQuery& rst, bool transact = false);
	virtual void updateRec(WznmRMDialogMQuery* rec);
	virtual void updateRst(ListWznmRMDialogMQuery& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMDialogMQuery** rec);
	virtual Sbecore::ubigint loadDlgsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refWznmMDialogs);
	virtual Sbecore::ubigint loadQrysByDlg(Sbecore::ubigint refWznmMDialog, const bool append, std::vector<Sbecore::ubigint>& refWznmMQuerys);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMDialogMQuery& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMDialogMQuery: C++ wrapper for table TblWznmRMDialogMQuery (MySQL database)
	*/
class MyTblWznmRMDialogMQuery : public TblWznmRMDialogMQuery, public Sbecore::MyTable {

public:
	MyTblWznmRMDialogMQuery();
	~MyTblWznmRMDialogMQuery();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMDialogMQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMDialogMQuery& rst);

	Sbecore::ubigint insertRec(WznmRMDialogMQuery* rec);
	void insertRst(ListWznmRMDialogMQuery& rst, bool transact = false);
	void updateRec(WznmRMDialogMQuery* rec);
	void updateRst(ListWznmRMDialogMQuery& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMDialogMQuery** rec);
	Sbecore::ubigint loadDlgsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refWznmMDialogs);
	Sbecore::ubigint loadQrysByDlg(Sbecore::ubigint refWznmMDialog, const bool append, std::vector<Sbecore::ubigint>& refWznmMQuerys);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMDialogMQuery: C++ wrapper for table TblWznmRMDialogMQuery (PgSQL database)
	*/
class PgTblWznmRMDialogMQuery : public TblWznmRMDialogMQuery, public Sbecore::PgTable {

public:
	PgTblWznmRMDialogMQuery();
	~PgTblWznmRMDialogMQuery();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMDialogMQuery** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMDialogMQuery& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMDialogMQuery** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMDialogMQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMDialogMQuery& rst);

	Sbecore::ubigint insertRec(WznmRMDialogMQuery* rec);
	void insertRst(ListWznmRMDialogMQuery& rst, bool transact = false);
	void updateRec(WznmRMDialogMQuery* rec);
	void updateRst(ListWznmRMDialogMQuery& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMDialogMQuery** rec);
	Sbecore::ubigint loadDlgsByQry(Sbecore::ubigint refWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refWznmMDialogs);
	Sbecore::ubigint loadQrysByDlg(Sbecore::ubigint refWznmMDialog, const bool append, std::vector<Sbecore::ubigint>& refWznmMQuerys);
};
#endif

#endif

