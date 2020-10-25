/**
	* \file WznmQDlgMNQuery.h
	* Dbs and XML wrapper for table TblWznmQDlgMNQuery (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQDLGMNQUERY_H
#define WZNMQDLGMNQUERY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQDlgMNQuery: record of TblWznmQDlgMNQuery
	*/
class WznmQDlgMNQuery {

public:
	WznmQDlgMNQuery(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQDlgMNQuery: recordset of TblWznmQDlgMNQuery
	*/
class ListWznmQDlgMNQuery {

public:
	ListWznmQDlgMNQuery();
	ListWznmQDlgMNQuery(const ListWznmQDlgMNQuery& src);
	~ListWznmQDlgMNQuery();

	void clear();
	unsigned int size() const;
	void append(WznmQDlgMNQuery* rec);

	ListWznmQDlgMNQuery& operator=(const ListWznmQDlgMNQuery& src);

public:
	std::vector<WznmQDlgMNQuery*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQDlgMNQuery: C++ wrapper for table TblWznmQDlgMNQuery
	*/
class TblWznmQDlgMNQuery {

public:
	TblWznmQDlgMNQuery();
	virtual ~TblWznmQDlgMNQuery();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQDlgMNQuery** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgMNQuery& rst);

	virtual Sbecore::ubigint insertRec(WznmQDlgMNQuery* rec);
	Sbecore::ubigint insertNewRec(WznmQDlgMNQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQDlgMNQuery& rst, WznmQDlgMNQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQDlgMNQuery& rst);
	virtual void updateRec(WznmQDlgMNQuery* rec);
	virtual void updateRst(ListWznmQDlgMNQuery& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgMNQuery** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgMNQuery& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQDlgMNQuery: C++ wrapper for table TblWznmQDlgMNQuery (MySQL database)
	*/
class MyTblWznmQDlgMNQuery : public TblWznmQDlgMNQuery, public Sbecore::MyTable {

public:
	MyTblWznmQDlgMNQuery();
	~MyTblWznmQDlgMNQuery();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQDlgMNQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgMNQuery& rst);

	Sbecore::ubigint insertRec(WznmQDlgMNQuery* rec);
	void insertRst(ListWznmQDlgMNQuery& rst);
	void updateRec(WznmQDlgMNQuery* rec);
	void updateRst(ListWznmQDlgMNQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgMNQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgMNQuery& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQDlgMNQuery: C++ wrapper for table TblWznmQDlgMNQuery (PgSQL database)
	*/
class PgTblWznmQDlgMNQuery : public TblWznmQDlgMNQuery, public Sbecore::PgTable {

public:
	PgTblWznmQDlgMNQuery();
	~PgTblWznmQDlgMNQuery();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQDlgMNQuery** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQDlgMNQuery& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQDlgMNQuery** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQDlgMNQuery& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQDlgMNQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgMNQuery& rst);

	Sbecore::ubigint insertRec(WznmQDlgMNQuery* rec);
	void insertRst(ListWznmQDlgMNQuery& rst);
	void updateRec(WznmQDlgMNQuery* rec);
	void updateRst(ListWznmQDlgMNQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgMNQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgMNQuery& rst);
};
#endif

#endif

