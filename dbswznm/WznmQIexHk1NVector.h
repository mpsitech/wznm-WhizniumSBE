/**
	* \file WznmQIexHk1NVector.h
	* Dbs and XML wrapper for table TblWznmQIexHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQIEXHK1NVECTOR_H
#define WZNMQIEXHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQIexHk1NVector: record of TblWznmQIexHk1NVector
	*/
class WznmQIexHk1NVector {

public:
	WznmQIexHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQIexHk1NVector: recordset of TblWznmQIexHk1NVector
	*/
class ListWznmQIexHk1NVector {

public:
	ListWznmQIexHk1NVector();
	ListWznmQIexHk1NVector(const ListWznmQIexHk1NVector& src);
	~ListWznmQIexHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WznmQIexHk1NVector* rec);

	ListWznmQIexHk1NVector& operator=(const ListWznmQIexHk1NVector& src);

public:
	std::vector<WznmQIexHk1NVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQIexHk1NVector: C++ wrapper for table TblWznmQIexHk1NVector
	*/
class TblWznmQIexHk1NVector {

public:
	TblWznmQIexHk1NVector();
	virtual ~TblWznmQIexHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQIexHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIexHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WznmQIexHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WznmQIexHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQIexHk1NVector& rst, WznmQIexHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQIexHk1NVector& rst);
	virtual void updateRec(WznmQIexHk1NVector* rec);
	virtual void updateRst(ListWznmQIexHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQIexHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIexHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQIexHk1NVector: C++ wrapper for table TblWznmQIexHk1NVector (MySQL database)
	*/
class MyTblWznmQIexHk1NVector : public TblWznmQIexHk1NVector, public Sbecore::MyTable {

public:
	MyTblWznmQIexHk1NVector();
	~MyTblWznmQIexHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIexHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIexHk1NVector& rst);

	Sbecore::ubigint insertRec(WznmQIexHk1NVector* rec);
	void insertRst(ListWznmQIexHk1NVector& rst);
	void updateRec(WznmQIexHk1NVector* rec);
	void updateRst(ListWznmQIexHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIexHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIexHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQIexHk1NVector: C++ wrapper for table TblWznmQIexHk1NVector (PgSQL database)
	*/
class PgTblWznmQIexHk1NVector : public TblWznmQIexHk1NVector, public Sbecore::PgTable {

public:
	PgTblWznmQIexHk1NVector();
	~PgTblWznmQIexHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQIexHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQIexHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQIexHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQIexHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIexHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIexHk1NVector& rst);

	Sbecore::ubigint insertRec(WznmQIexHk1NVector* rec);
	void insertRst(ListWznmQIexHk1NVector& rst);
	void updateRec(WznmQIexHk1NVector* rec);
	void updateRst(ListWznmQIexHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIexHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIexHk1NVector& rst);
};
#endif

#endif

