/**
	* \file WznmQVer1NTable.h
	* Dbs and XML wrapper for table TblWznmQVer1NTable (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQVER1NTABLE_H
#define WZNMQVER1NTABLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NTable: record of TblWznmQVer1NTable
	*/
class WznmQVer1NTable {

public:
	WznmQVer1NTable(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NTable: recordset of TblWznmQVer1NTable
	*/
class ListWznmQVer1NTable {

public:
	ListWznmQVer1NTable();
	ListWznmQVer1NTable(const ListWznmQVer1NTable& src);
	~ListWznmQVer1NTable();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NTable* rec);

	ListWznmQVer1NTable& operator=(const ListWznmQVer1NTable& src);

public:
	std::vector<WznmQVer1NTable*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NTable: C++ wrapper for table TblWznmQVer1NTable
	*/
class TblWznmQVer1NTable {

public:
	TblWznmQVer1NTable();
	virtual ~TblWznmQVer1NTable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NTable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NTable& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NTable* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NTable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NTable& rst, WznmQVer1NTable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NTable& rst);
	virtual void updateRec(WznmQVer1NTable* rec);
	virtual void updateRst(ListWznmQVer1NTable& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NTable** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NTable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NTable: C++ wrapper for table TblWznmQVer1NTable (MySQL database)
	*/
class MyTblWznmQVer1NTable : public TblWznmQVer1NTable, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NTable();
	~MyTblWznmQVer1NTable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NTable& rst);

	Sbecore::ubigint insertRec(WznmQVer1NTable* rec);
	void insertRst(ListWznmQVer1NTable& rst);
	void updateRec(WznmQVer1NTable* rec);
	void updateRst(ListWznmQVer1NTable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NTable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NTable& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NTable: C++ wrapper for table TblWznmQVer1NTable (PgSQL database)
	*/
class PgTblWznmQVer1NTable : public TblWznmQVer1NTable, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NTable();
	~PgTblWznmQVer1NTable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NTable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NTable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NTable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NTable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NTable& rst);

	Sbecore::ubigint insertRec(WznmQVer1NTable* rec);
	void insertRst(ListWznmQVer1NTable& rst);
	void updateRec(WznmQVer1NTable* rec);
	void updateRst(ListWznmQVer1NTable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NTable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NTable& rst);
};
#endif

#endif

