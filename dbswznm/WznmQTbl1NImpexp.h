/**
	* \file WznmQTbl1NImpexp.h
	* Dbs and XML wrapper for table TblWznmQTbl1NImpexp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBL1NIMPEXP_H
#define WZNMQTBL1NIMPEXP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTbl1NImpexp: record of TblWznmQTbl1NImpexp
	*/
class WznmQTbl1NImpexp {

public:
	WznmQTbl1NImpexp(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTbl1NImpexp: recordset of TblWznmQTbl1NImpexp
	*/
class ListWznmQTbl1NImpexp {

public:
	ListWznmQTbl1NImpexp();
	ListWznmQTbl1NImpexp(const ListWznmQTbl1NImpexp& src);
	~ListWznmQTbl1NImpexp();

	void clear();
	unsigned int size() const;
	void append(WznmQTbl1NImpexp* rec);

	ListWznmQTbl1NImpexp& operator=(const ListWznmQTbl1NImpexp& src);

public:
	std::vector<WznmQTbl1NImpexp*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTbl1NImpexp: C++ wrapper for table TblWznmQTbl1NImpexp
	*/
class TblWznmQTbl1NImpexp {

public:
	TblWznmQTbl1NImpexp();
	virtual ~TblWznmQTbl1NImpexp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NImpexp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NImpexp& rst);

	virtual Sbecore::ubigint insertRec(WznmQTbl1NImpexp* rec);
	Sbecore::ubigint insertNewRec(WznmQTbl1NImpexp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTbl1NImpexp& rst, WznmQTbl1NImpexp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTbl1NImpexp& rst);
	virtual void updateRec(WznmQTbl1NImpexp* rec);
	virtual void updateRst(ListWznmQTbl1NImpexp& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NImpexp** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NImpexp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTbl1NImpexp: C++ wrapper for table TblWznmQTbl1NImpexp (MySQL database)
	*/
class MyTblWznmQTbl1NImpexp : public TblWznmQTbl1NImpexp, public Sbecore::MyTable {

public:
	MyTblWznmQTbl1NImpexp();
	~MyTblWznmQTbl1NImpexp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NImpexp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NImpexp& rst);

	Sbecore::ubigint insertRec(WznmQTbl1NImpexp* rec);
	void insertRst(ListWznmQTbl1NImpexp& rst);
	void updateRec(WznmQTbl1NImpexp* rec);
	void updateRst(ListWznmQTbl1NImpexp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NImpexp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NImpexp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTbl1NImpexp: C++ wrapper for table TblWznmQTbl1NImpexp (PgSQL database)
	*/
class PgTblWznmQTbl1NImpexp : public TblWznmQTbl1NImpexp, public Sbecore::PgTable {

public:
	PgTblWznmQTbl1NImpexp();
	~PgTblWznmQTbl1NImpexp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTbl1NImpexp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTbl1NImpexp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTbl1NImpexp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTbl1NImpexp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NImpexp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NImpexp& rst);

	Sbecore::ubigint insertRec(WznmQTbl1NImpexp* rec);
	void insertRst(ListWznmQTbl1NImpexp& rst);
	void updateRec(WznmQTbl1NImpexp* rec);
	void updateRst(ListWznmQTbl1NImpexp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NImpexp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NImpexp& rst);
};
#endif

#endif

