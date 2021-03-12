/**
	* \file WznmQVer1NQuery.h
	* Dbs and XML wrapper for table TblWznmQVer1NQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NQUERY_H
#define WZNMQVER1NQUERY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NQuery: record of TblWznmQVer1NQuery
	*/
class WznmQVer1NQuery {

public:
	WznmQVer1NQuery(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVer1NQuery: recordset of TblWznmQVer1NQuery
	*/
class ListWznmQVer1NQuery {

public:
	ListWznmQVer1NQuery();
	ListWznmQVer1NQuery(const ListWznmQVer1NQuery& src);
	~ListWznmQVer1NQuery();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NQuery* rec);

	ListWznmQVer1NQuery& operator=(const ListWznmQVer1NQuery& src);

public:
	std::vector<WznmQVer1NQuery*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NQuery: C++ wrapper for table TblWznmQVer1NQuery
	*/
class TblWznmQVer1NQuery {

public:
	TblWznmQVer1NQuery();
	virtual ~TblWznmQVer1NQuery();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NQuery** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NQuery& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NQuery* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NQuery& rst, WznmQVer1NQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NQuery& rst);
	virtual void updateRec(WznmQVer1NQuery* rec);
	virtual void updateRst(ListWznmQVer1NQuery& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NQuery** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NQuery& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NQuery: C++ wrapper for table TblWznmQVer1NQuery (MySQL database)
	*/
class MyTblWznmQVer1NQuery : public TblWznmQVer1NQuery, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NQuery();
	~MyTblWznmQVer1NQuery();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NQuery& rst);

	Sbecore::ubigint insertRec(WznmQVer1NQuery* rec);
	void insertRst(ListWznmQVer1NQuery& rst);
	void updateRec(WznmQVer1NQuery* rec);
	void updateRst(ListWznmQVer1NQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NQuery& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NQuery: C++ wrapper for table TblWznmQVer1NQuery (PgSQL database)
	*/
class PgTblWznmQVer1NQuery : public TblWznmQVer1NQuery, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NQuery();
	~PgTblWznmQVer1NQuery();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NQuery** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NQuery& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NQuery** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NQuery& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NQuery& rst);

	Sbecore::ubigint insertRec(WznmQVer1NQuery* rec);
	void insertRst(ListWznmQVer1NQuery& rst);
	void updateRec(WznmQVer1NQuery* rec);
	void updateRst(ListWznmQVer1NQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NQuery& rst);
};
#endif

#endif
