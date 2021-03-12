/**
	* \file WznmQVecMNTable.h
	* Dbs and XML wrapper for table TblWznmQVecMNTable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECMNTABLE_H
#define WZNMQVECMNTABLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVecMNTable: record of TblWznmQVecMNTable
	*/
class WznmQVecMNTable {

public:
	WznmQVecMNTable(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSubset = 0, const std::string stubRefWznmMSubset = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMSubset;
	std::string stubRefWznmMSubset;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVecMNTable: recordset of TblWznmQVecMNTable
	*/
class ListWznmQVecMNTable {

public:
	ListWznmQVecMNTable();
	ListWznmQVecMNTable(const ListWznmQVecMNTable& src);
	~ListWznmQVecMNTable();

	void clear();
	unsigned int size() const;
	void append(WznmQVecMNTable* rec);

	ListWznmQVecMNTable& operator=(const ListWznmQVecMNTable& src);

public:
	std::vector<WznmQVecMNTable*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVecMNTable: C++ wrapper for table TblWznmQVecMNTable
	*/
class TblWznmQVecMNTable {

public:
	TblWznmQVecMNTable();
	virtual ~TblWznmQVecMNTable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVecMNTable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecMNTable& rst);

	virtual Sbecore::ubigint insertRec(WznmQVecMNTable* rec);
	Sbecore::ubigint insertNewRec(WznmQVecMNTable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSubset = 0, const std::string stubRefWznmMSubset = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVecMNTable& rst, WznmQVecMNTable** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSubset = 0, const std::string stubRefWznmMSubset = "");
	virtual void insertRst(ListWznmQVecMNTable& rst);
	virtual void updateRec(WznmQVecMNTable* rec);
	virtual void updateRst(ListWznmQVecMNTable& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVecMNTable** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecMNTable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVecMNTable: C++ wrapper for table TblWznmQVecMNTable (MySQL database)
	*/
class MyTblWznmQVecMNTable : public TblWznmQVecMNTable, public Sbecore::MyTable {

public:
	MyTblWznmQVecMNTable();
	~MyTblWznmQVecMNTable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecMNTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecMNTable& rst);

	Sbecore::ubigint insertRec(WznmQVecMNTable* rec);
	void insertRst(ListWznmQVecMNTable& rst);
	void updateRec(WznmQVecMNTable* rec);
	void updateRst(ListWznmQVecMNTable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecMNTable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecMNTable& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVecMNTable: C++ wrapper for table TblWznmQVecMNTable (PgSQL database)
	*/
class PgTblWznmQVecMNTable : public TblWznmQVecMNTable, public Sbecore::PgTable {

public:
	PgTblWznmQVecMNTable();
	~PgTblWznmQVecMNTable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVecMNTable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVecMNTable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVecMNTable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVecMNTable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecMNTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecMNTable& rst);

	Sbecore::ubigint insertRec(WznmQVecMNTable* rec);
	void insertRst(ListWznmQVecMNTable& rst);
	void updateRec(WznmQVecMNTable* rec);
	void updateRst(ListWznmQVecMNTable& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecMNTable** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecMNTable& rst);
};
#endif

#endif
