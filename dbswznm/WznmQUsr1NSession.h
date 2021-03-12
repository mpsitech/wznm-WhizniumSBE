/**
	* \file WznmQUsr1NSession.h
	* Dbs and XML wrapper for table TblWznmQUsr1NSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQUSR1NSESSION_H
#define WZNMQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQUsr1NSession: record of TblWznmQUsr1NSession
	*/
class WznmQUsr1NSession {

public:
	WznmQUsr1NSession(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQUsr1NSession: recordset of TblWznmQUsr1NSession
	*/
class ListWznmQUsr1NSession {

public:
	ListWznmQUsr1NSession();
	ListWznmQUsr1NSession(const ListWznmQUsr1NSession& src);
	~ListWznmQUsr1NSession();

	void clear();
	unsigned int size() const;
	void append(WznmQUsr1NSession* rec);

	ListWznmQUsr1NSession& operator=(const ListWznmQUsr1NSession& src);

public:
	std::vector<WznmQUsr1NSession*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQUsr1NSession: C++ wrapper for table TblWznmQUsr1NSession
	*/
class TblWznmQUsr1NSession {

public:
	TblWznmQUsr1NSession();
	virtual ~TblWznmQUsr1NSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsr1NSession& rst);

	virtual Sbecore::ubigint insertRec(WznmQUsr1NSession* rec);
	Sbecore::ubigint insertNewRec(WznmQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQUsr1NSession& rst, WznmQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQUsr1NSession& rst);
	virtual void updateRec(WznmQUsr1NSession* rec);
	virtual void updateRst(ListWznmQUsr1NSession& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsr1NSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQUsr1NSession: C++ wrapper for table TblWznmQUsr1NSession (MySQL database)
	*/
class MyTblWznmQUsr1NSession : public TblWznmQUsr1NSession, public Sbecore::MyTable {

public:
	MyTblWznmQUsr1NSession();
	~MyTblWznmQUsr1NSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsr1NSession& rst);

	Sbecore::ubigint insertRec(WznmQUsr1NSession* rec);
	void insertRst(ListWznmQUsr1NSession& rst);
	void updateRec(WznmQUsr1NSession* rec);
	void updateRst(ListWznmQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsr1NSession& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQUsr1NSession: C++ wrapper for table TblWznmQUsr1NSession (PgSQL database)
	*/
class PgTblWznmQUsr1NSession : public TblWznmQUsr1NSession, public Sbecore::PgTable {

public:
	PgTblWznmQUsr1NSession();
	~PgTblWznmQUsr1NSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQUsr1NSession** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQUsr1NSession& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQUsr1NSession** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQUsr1NSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQUsr1NSession& rst);

	Sbecore::ubigint insertRec(WznmQUsr1NSession* rec);
	void insertRst(ListWznmQUsr1NSession& rst);
	void updateRec(WznmQUsr1NSession* rec);
	void updateRst(ListWznmQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQUsr1NSession& rst);
};
#endif

#endif
