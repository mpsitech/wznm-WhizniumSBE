/**
	* \file WznmQIex1NImpexp.h
	* Dbs and XML wrapper for table TblWznmQIex1NImpexp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQIEX1NIMPEXP_H
#define WZNMQIEX1NIMPEXP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQIex1NImpexp: record of TblWznmQIex1NImpexp
	*/
class WznmQIex1NImpexp {

public:
	WznmQIex1NImpexp(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQIex1NImpexp: recordset of TblWznmQIex1NImpexp
	*/
class ListWznmQIex1NImpexp {

public:
	ListWznmQIex1NImpexp();
	ListWznmQIex1NImpexp(const ListWznmQIex1NImpexp& src);
	~ListWznmQIex1NImpexp();

	void clear();
	unsigned int size() const;
	void append(WznmQIex1NImpexp* rec);

	ListWznmQIex1NImpexp& operator=(const ListWznmQIex1NImpexp& src);

public:
	std::vector<WznmQIex1NImpexp*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQIex1NImpexp: C++ wrapper for table TblWznmQIex1NImpexp
	*/
class TblWznmQIex1NImpexp {

public:
	TblWznmQIex1NImpexp();
	virtual ~TblWznmQIex1NImpexp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQIex1NImpexp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIex1NImpexp& rst);

	virtual Sbecore::ubigint insertRec(WznmQIex1NImpexp* rec);
	Sbecore::ubigint insertNewRec(WznmQIex1NImpexp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQIex1NImpexp& rst, WznmQIex1NImpexp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQIex1NImpexp& rst);
	virtual void updateRec(WznmQIex1NImpexp* rec);
	virtual void updateRst(ListWznmQIex1NImpexp& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQIex1NImpexp** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIex1NImpexp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQIex1NImpexp: C++ wrapper for table TblWznmQIex1NImpexp (MySQL database)
	*/
class MyTblWznmQIex1NImpexp : public TblWznmQIex1NImpexp, public Sbecore::MyTable {

public:
	MyTblWznmQIex1NImpexp();
	~MyTblWznmQIex1NImpexp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIex1NImpexp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIex1NImpexp& rst);

	Sbecore::ubigint insertRec(WznmQIex1NImpexp* rec);
	void insertRst(ListWznmQIex1NImpexp& rst);
	void updateRec(WznmQIex1NImpexp* rec);
	void updateRst(ListWznmQIex1NImpexp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIex1NImpexp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIex1NImpexp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQIex1NImpexp: C++ wrapper for table TblWznmQIex1NImpexp (PgSQL database)
	*/
class PgTblWznmQIex1NImpexp : public TblWznmQIex1NImpexp, public Sbecore::PgTable {

public:
	PgTblWznmQIex1NImpexp();
	~PgTblWznmQIex1NImpexp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQIex1NImpexp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQIex1NImpexp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQIex1NImpexp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQIex1NImpexp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIex1NImpexp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIex1NImpexp& rst);

	Sbecore::ubigint insertRec(WznmQIex1NImpexp* rec);
	void insertRst(ListWznmQIex1NImpexp& rst);
	void updateRec(WznmQIex1NImpexp* rec);
	void updateRst(ListWznmQIex1NImpexp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIex1NImpexp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIex1NImpexp& rst);
};
#endif

#endif

