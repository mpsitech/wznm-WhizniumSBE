/**
	* \file WznmQQrySup1NQuery.h
	* Dbs and XML wrapper for table TblWznmQQrySup1NQuery (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQQRYSUP1NQUERY_H
#define WZNMQQRYSUP1NQUERY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQrySup1NQuery: record of TblWznmQQrySup1NQuery
	*/
class WznmQQrySup1NQuery {

public:
	WznmQQrySup1NQuery(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQQrySup1NQuery: recordset of TblWznmQQrySup1NQuery
	*/
class ListWznmQQrySup1NQuery {

public:
	ListWznmQQrySup1NQuery();
	ListWznmQQrySup1NQuery(const ListWznmQQrySup1NQuery& src);
	~ListWznmQQrySup1NQuery();

	void clear();
	unsigned int size() const;
	void append(WznmQQrySup1NQuery* rec);

	ListWznmQQrySup1NQuery& operator=(const ListWznmQQrySup1NQuery& src);

public:
	std::vector<WznmQQrySup1NQuery*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQrySup1NQuery: C++ wrapper for table TblWznmQQrySup1NQuery
	*/
class TblWznmQQrySup1NQuery {

public:
	TblWznmQQrySup1NQuery();
	virtual ~TblWznmQQrySup1NQuery();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQrySup1NQuery** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQrySup1NQuery& rst);

	virtual Sbecore::ubigint insertRec(WznmQQrySup1NQuery* rec);
	Sbecore::ubigint insertNewRec(WznmQQrySup1NQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQQrySup1NQuery& rst, WznmQQrySup1NQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQQrySup1NQuery& rst);
	virtual void updateRec(WznmQQrySup1NQuery* rec);
	virtual void updateRst(ListWznmQQrySup1NQuery& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQrySup1NQuery** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQrySup1NQuery& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQrySup1NQuery: C++ wrapper for table TblWznmQQrySup1NQuery (MySQL database)
	*/
class MyTblWznmQQrySup1NQuery : public TblWznmQQrySup1NQuery, public Sbecore::MyTable {

public:
	MyTblWznmQQrySup1NQuery();
	~MyTblWznmQQrySup1NQuery();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQrySup1NQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQrySup1NQuery& rst);

	Sbecore::ubigint insertRec(WznmQQrySup1NQuery* rec);
	void insertRst(ListWznmQQrySup1NQuery& rst);
	void updateRec(WznmQQrySup1NQuery* rec);
	void updateRst(ListWznmQQrySup1NQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQrySup1NQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQrySup1NQuery& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQrySup1NQuery: C++ wrapper for table TblWznmQQrySup1NQuery (PgSQL database)
	*/
class PgTblWznmQQrySup1NQuery : public TblWznmQQrySup1NQuery, public Sbecore::PgTable {

public:
	PgTblWznmQQrySup1NQuery();
	~PgTblWznmQQrySup1NQuery();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQrySup1NQuery** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQrySup1NQuery& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQrySup1NQuery** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQrySup1NQuery& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQrySup1NQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQrySup1NQuery& rst);

	Sbecore::ubigint insertRec(WznmQQrySup1NQuery* rec);
	void insertRst(ListWznmQQrySup1NQuery& rst);
	void updateRec(WznmQQrySup1NQuery* rec);
	void updateRst(ListWznmQQrySup1NQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQrySup1NQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQrySup1NQuery& rst);
};
#endif

#endif

