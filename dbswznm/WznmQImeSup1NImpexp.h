/**
	* \file WznmQImeSup1NImpexp.h
	* Dbs and XML wrapper for table TblWznmQImeSup1NImpexp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIMESUP1NIMPEXP_H
#define WZNMQIMESUP1NIMPEXP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQImeSup1NImpexp: record of TblWznmQImeSup1NImpexp
	*/
class WznmQImeSup1NImpexp {

public:
	WznmQImeSup1NImpexp(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQImeSup1NImpexp: recordset of TblWznmQImeSup1NImpexp
	*/
class ListWznmQImeSup1NImpexp {

public:
	ListWznmQImeSup1NImpexp();
	ListWznmQImeSup1NImpexp(const ListWznmQImeSup1NImpexp& src);
	~ListWznmQImeSup1NImpexp();

	void clear();
	unsigned int size() const;
	void append(WznmQImeSup1NImpexp* rec);

	ListWznmQImeSup1NImpexp& operator=(const ListWznmQImeSup1NImpexp& src);

public:
	std::vector<WznmQImeSup1NImpexp*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQImeSup1NImpexp: C++ wrapper for table TblWznmQImeSup1NImpexp
	*/
class TblWznmQImeSup1NImpexp {

public:
	TblWznmQImeSup1NImpexp();
	virtual ~TblWznmQImeSup1NImpexp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQImeSup1NImpexp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeSup1NImpexp& rst);

	virtual Sbecore::ubigint insertRec(WznmQImeSup1NImpexp* rec);
	Sbecore::ubigint insertNewRec(WznmQImeSup1NImpexp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQImeSup1NImpexp& rst, WznmQImeSup1NImpexp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQImeSup1NImpexp& rst);
	virtual void updateRec(WznmQImeSup1NImpexp* rec);
	virtual void updateRst(ListWznmQImeSup1NImpexp& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQImeSup1NImpexp** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeSup1NImpexp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQImeSup1NImpexp: C++ wrapper for table TblWznmQImeSup1NImpexp (MySQL database)
	*/
class MyTblWznmQImeSup1NImpexp : public TblWznmQImeSup1NImpexp, public Sbecore::MyTable {

public:
	MyTblWznmQImeSup1NImpexp();
	~MyTblWznmQImeSup1NImpexp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQImeSup1NImpexp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeSup1NImpexp& rst);

	Sbecore::ubigint insertRec(WznmQImeSup1NImpexp* rec);
	void insertRst(ListWznmQImeSup1NImpexp& rst);
	void updateRec(WznmQImeSup1NImpexp* rec);
	void updateRst(ListWznmQImeSup1NImpexp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQImeSup1NImpexp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeSup1NImpexp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQImeSup1NImpexp: C++ wrapper for table TblWznmQImeSup1NImpexp (PgSQL database)
	*/
class PgTblWznmQImeSup1NImpexp : public TblWznmQImeSup1NImpexp, public Sbecore::PgTable {

public:
	PgTblWznmQImeSup1NImpexp();
	~PgTblWznmQImeSup1NImpexp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQImeSup1NImpexp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQImeSup1NImpexp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQImeSup1NImpexp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQImeSup1NImpexp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQImeSup1NImpexp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeSup1NImpexp& rst);

	Sbecore::ubigint insertRec(WznmQImeSup1NImpexp* rec);
	void insertRst(ListWznmQImeSup1NImpexp& rst);
	void updateRec(WznmQImeSup1NImpexp* rec);
	void updateRst(ListWznmQImeSup1NImpexp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQImeSup1NImpexp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeSup1NImpexp& rst);
};
#endif

#endif
