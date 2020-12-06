/**
	* \file WznmQTco1NQuerycol.h
	* Dbs and XML wrapper for table TblWznmQTco1NQuerycol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTCO1NQUERYCOL_H
#define WZNMQTCO1NQUERYCOL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTco1NQuerycol: record of TblWznmQTco1NQuerycol
	*/
class WznmQTco1NQuerycol {

public:
	WznmQTco1NQuerycol(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTco1NQuerycol: recordset of TblWznmQTco1NQuerycol
	*/
class ListWznmQTco1NQuerycol {

public:
	ListWznmQTco1NQuerycol();
	ListWznmQTco1NQuerycol(const ListWznmQTco1NQuerycol& src);
	~ListWznmQTco1NQuerycol();

	void clear();
	unsigned int size() const;
	void append(WznmQTco1NQuerycol* rec);

	ListWznmQTco1NQuerycol& operator=(const ListWznmQTco1NQuerycol& src);

public:
	std::vector<WznmQTco1NQuerycol*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTco1NQuerycol: C++ wrapper for table TblWznmQTco1NQuerycol
	*/
class TblWznmQTco1NQuerycol {

public:
	TblWznmQTco1NQuerycol();
	virtual ~TblWznmQTco1NQuerycol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTco1NQuerycol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTco1NQuerycol& rst);

	virtual Sbecore::ubigint insertRec(WznmQTco1NQuerycol* rec);
	Sbecore::ubigint insertNewRec(WznmQTco1NQuerycol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTco1NQuerycol& rst, WznmQTco1NQuerycol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTco1NQuerycol& rst);
	virtual void updateRec(WznmQTco1NQuerycol* rec);
	virtual void updateRst(ListWznmQTco1NQuerycol& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTco1NQuerycol** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTco1NQuerycol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTco1NQuerycol: C++ wrapper for table TblWznmQTco1NQuerycol (MySQL database)
	*/
class MyTblWznmQTco1NQuerycol : public TblWznmQTco1NQuerycol, public Sbecore::MyTable {

public:
	MyTblWznmQTco1NQuerycol();
	~MyTblWznmQTco1NQuerycol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTco1NQuerycol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTco1NQuerycol& rst);

	Sbecore::ubigint insertRec(WznmQTco1NQuerycol* rec);
	void insertRst(ListWznmQTco1NQuerycol& rst);
	void updateRec(WznmQTco1NQuerycol* rec);
	void updateRst(ListWznmQTco1NQuerycol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTco1NQuerycol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTco1NQuerycol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTco1NQuerycol: C++ wrapper for table TblWznmQTco1NQuerycol (PgSQL database)
	*/
class PgTblWznmQTco1NQuerycol : public TblWznmQTco1NQuerycol, public Sbecore::PgTable {

public:
	PgTblWznmQTco1NQuerycol();
	~PgTblWznmQTco1NQuerycol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTco1NQuerycol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTco1NQuerycol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTco1NQuerycol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTco1NQuerycol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTco1NQuerycol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTco1NQuerycol& rst);

	Sbecore::ubigint insertRec(WznmQTco1NQuerycol* rec);
	void insertRst(ListWznmQTco1NQuerycol& rst);
	void updateRec(WznmQTco1NQuerycol* rec);
	void updateRst(ListWznmQTco1NQuerycol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTco1NQuerycol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTco1NQuerycol& rst);
};
#endif

#endif
