/**
	* \file WznmQPnlMNQuery.h
	* Dbs and XML wrapper for table TblWznmQPnlMNQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPNLMNQUERY_H
#define WZNMQPNLMNQUERY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPnlMNQuery: record of TblWznmQPnlMNQuery
	*/
class WznmQPnlMNQuery {

public:
	WznmQPnlMNQuery(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPnlMNQuery: recordset of TblWznmQPnlMNQuery
	*/
class ListWznmQPnlMNQuery {

public:
	ListWznmQPnlMNQuery();
	ListWznmQPnlMNQuery(const ListWznmQPnlMNQuery& src);
	~ListWznmQPnlMNQuery();

	void clear();
	unsigned int size() const;
	void append(WznmQPnlMNQuery* rec);

	ListWznmQPnlMNQuery& operator=(const ListWznmQPnlMNQuery& src);

public:
	std::vector<WznmQPnlMNQuery*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPnlMNQuery: C++ wrapper for table TblWznmQPnlMNQuery
	*/
class TblWznmQPnlMNQuery {

public:
	TblWznmQPnlMNQuery();
	virtual ~TblWznmQPnlMNQuery();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPnlMNQuery** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPnlMNQuery& rst);

	virtual Sbecore::ubigint insertRec(WznmQPnlMNQuery* rec);
	Sbecore::ubigint insertNewRec(WznmQPnlMNQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQPnlMNQuery& rst, WznmQPnlMNQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQPnlMNQuery& rst);
	virtual void updateRec(WznmQPnlMNQuery* rec);
	virtual void updateRst(ListWznmQPnlMNQuery& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPnlMNQuery** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPnlMNQuery& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPnlMNQuery: C++ wrapper for table TblWznmQPnlMNQuery (MySQL database)
	*/
class MyTblWznmQPnlMNQuery : public TblWznmQPnlMNQuery, public Sbecore::MyTable {

public:
	MyTblWznmQPnlMNQuery();
	~MyTblWznmQPnlMNQuery();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPnlMNQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPnlMNQuery& rst);

	Sbecore::ubigint insertRec(WznmQPnlMNQuery* rec);
	void insertRst(ListWznmQPnlMNQuery& rst);
	void updateRec(WznmQPnlMNQuery* rec);
	void updateRst(ListWznmQPnlMNQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPnlMNQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPnlMNQuery& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPnlMNQuery: C++ wrapper for table TblWznmQPnlMNQuery (PgSQL database)
	*/
class PgTblWznmQPnlMNQuery : public TblWznmQPnlMNQuery, public Sbecore::PgTable {

public:
	PgTblWznmQPnlMNQuery();
	~PgTblWznmQPnlMNQuery();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPnlMNQuery** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPnlMNQuery& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPnlMNQuery** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPnlMNQuery& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPnlMNQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPnlMNQuery& rst);

	Sbecore::ubigint insertRec(WznmQPnlMNQuery* rec);
	void insertRst(ListWznmQPnlMNQuery& rst);
	void updateRec(WznmQPnlMNQuery* rec);
	void updateRst(ListWznmQPnlMNQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPnlMNQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPnlMNQuery& rst);
};
#endif

#endif
