/**
	* \file WznmQTblMNQuery.h
	* Dbs and XML wrapper for table TblWznmQTblMNQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLMNQUERY_H
#define WZNMQTBLMNQUERY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblMNQuery: record of TblWznmQTblMNQuery
	*/
class WznmQTblMNQuery {

public:
	WznmQTblMNQuery(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const std::string stubsTrefWznmMQuerymod = "", const Sbecore::ubigint ref = 0, const bool Source = false, const std::string yesnoSource = "", const std::string Prefix = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	std::string stubsTrefWznmMQuerymod;
	Sbecore::ubigint ref;
	bool Source;
	std::string yesnoSource;
	std::string Prefix;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTblMNQuery: recordset of TblWznmQTblMNQuery
	*/
class ListWznmQTblMNQuery {

public:
	ListWznmQTblMNQuery();
	ListWznmQTblMNQuery(const ListWznmQTblMNQuery& src);
	~ListWznmQTblMNQuery();

	void clear();
	unsigned int size() const;
	void append(WznmQTblMNQuery* rec);

	ListWznmQTblMNQuery& operator=(const ListWznmQTblMNQuery& src);

public:
	std::vector<WznmQTblMNQuery*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblMNQuery: C++ wrapper for table TblWznmQTblMNQuery
	*/
class TblWznmQTblMNQuery {

public:
	TblWznmQTblMNQuery();
	virtual ~TblWznmQTblMNQuery();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblMNQuery** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblMNQuery& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblMNQuery* rec);
	Sbecore::ubigint insertNewRec(WznmQTblMNQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const std::string stubsTrefWznmMQuerymod = "", const Sbecore::ubigint ref = 0, const bool Source = false, const std::string yesnoSource = "", const std::string Prefix = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblMNQuery& rst, WznmQTblMNQuery** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const std::string stubsTrefWznmMQuerymod = "", const Sbecore::ubigint ref = 0, const bool Source = false, const std::string yesnoSource = "", const std::string Prefix = "");
	virtual void insertRst(ListWznmQTblMNQuery& rst);
	virtual void updateRec(WznmQTblMNQuery* rec);
	virtual void updateRst(ListWznmQTblMNQuery& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblMNQuery** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblMNQuery& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblMNQuery: C++ wrapper for table TblWznmQTblMNQuery (MySQL database)
	*/
class MyTblWznmQTblMNQuery : public TblWznmQTblMNQuery, public Sbecore::MyTable {

public:
	MyTblWznmQTblMNQuery();
	~MyTblWznmQTblMNQuery();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblMNQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblMNQuery& rst);

	Sbecore::ubigint insertRec(WznmQTblMNQuery* rec);
	void insertRst(ListWznmQTblMNQuery& rst);
	void updateRec(WznmQTblMNQuery* rec);
	void updateRst(ListWznmQTblMNQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblMNQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblMNQuery& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblMNQuery: C++ wrapper for table TblWznmQTblMNQuery (PgSQL database)
	*/
class PgTblWznmQTblMNQuery : public TblWznmQTblMNQuery, public Sbecore::PgTable {

public:
	PgTblWznmQTblMNQuery();
	~PgTblWznmQTblMNQuery();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblMNQuery** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblMNQuery& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblMNQuery** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblMNQuery& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblMNQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblMNQuery& rst);

	Sbecore::ubigint insertRec(WznmQTblMNQuery* rec);
	void insertRst(ListWznmQTblMNQuery& rst);
	void updateRec(WznmQTblMNQuery* rec);
	void updateRst(ListWznmQTblMNQuery& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblMNQuery** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblMNQuery& rst);
};
#endif

#endif
