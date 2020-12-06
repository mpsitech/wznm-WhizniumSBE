/**
	* \file WznmQQryQry1NQuerycol.h
	* Dbs and XML wrapper for table TblWznmQQryQry1NQuerycol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQQRYQRY1NQUERYCOL_H
#define WZNMQQRYQRY1NQUERYCOL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQryQry1NQuerycol: record of TblWznmQQryQry1NQuerycol
	*/
class WznmQQryQry1NQuerycol {

public:
	WznmQQryQry1NQuerycol(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint qryNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint qryNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQQryQry1NQuerycol: recordset of TblWznmQQryQry1NQuerycol
	*/
class ListWznmQQryQry1NQuerycol {

public:
	ListWznmQQryQry1NQuerycol();
	ListWznmQQryQry1NQuerycol(const ListWznmQQryQry1NQuerycol& src);
	~ListWznmQQryQry1NQuerycol();

	void clear();
	unsigned int size() const;
	void append(WznmQQryQry1NQuerycol* rec);

	ListWznmQQryQry1NQuerycol& operator=(const ListWznmQQryQry1NQuerycol& src);

public:
	std::vector<WznmQQryQry1NQuerycol*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQryQry1NQuerycol: C++ wrapper for table TblWznmQQryQry1NQuerycol
	*/
class TblWznmQQryQry1NQuerycol {

public:
	TblWznmQQryQry1NQuerycol();
	virtual ~TblWznmQQryQry1NQuerycol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQryQry1NQuerycol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryQry1NQuerycol& rst);

	virtual Sbecore::ubigint insertRec(WznmQQryQry1NQuerycol* rec);
	Sbecore::ubigint insertNewRec(WznmQQryQry1NQuerycol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint qryNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQQryQry1NQuerycol& rst, WznmQQryQry1NQuerycol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint qryNum = 0);
	virtual void insertRst(ListWznmQQryQry1NQuerycol& rst);
	virtual void updateRec(WznmQQryQry1NQuerycol* rec);
	virtual void updateRst(ListWznmQQryQry1NQuerycol& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQryQry1NQuerycol** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryQry1NQuerycol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQryQry1NQuerycol: C++ wrapper for table TblWznmQQryQry1NQuerycol (MySQL database)
	*/
class MyTblWznmQQryQry1NQuerycol : public TblWznmQQryQry1NQuerycol, public Sbecore::MyTable {

public:
	MyTblWznmQQryQry1NQuerycol();
	~MyTblWznmQQryQry1NQuerycol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryQry1NQuerycol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryQry1NQuerycol& rst);

	Sbecore::ubigint insertRec(WznmQQryQry1NQuerycol* rec);
	void insertRst(ListWznmQQryQry1NQuerycol& rst);
	void updateRec(WznmQQryQry1NQuerycol* rec);
	void updateRst(ListWznmQQryQry1NQuerycol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryQry1NQuerycol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryQry1NQuerycol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQryQry1NQuerycol: C++ wrapper for table TblWznmQQryQry1NQuerycol (PgSQL database)
	*/
class PgTblWznmQQryQry1NQuerycol : public TblWznmQQryQry1NQuerycol, public Sbecore::PgTable {

public:
	PgTblWznmQQryQry1NQuerycol();
	~PgTblWznmQQryQry1NQuerycol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQryQry1NQuerycol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQryQry1NQuerycol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQryQry1NQuerycol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQryQry1NQuerycol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryQry1NQuerycol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryQry1NQuerycol& rst);

	Sbecore::ubigint insertRec(WznmQQryQry1NQuerycol* rec);
	void insertRst(ListWznmQQryQry1NQuerycol& rst);
	void updateRec(WznmQQryQry1NQuerycol* rec);
	void updateRst(ListWznmQQryQry1NQuerycol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryQry1NQuerycol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryQry1NQuerycol& rst);
};
#endif

#endif
