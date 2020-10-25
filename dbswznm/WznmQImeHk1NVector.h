/**
	* \file WznmQImeHk1NVector.h
	* Dbs and XML wrapper for table TblWznmQImeHk1NVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQIMEHK1NVECTOR_H
#define WZNMQIMEHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQImeHk1NVector: record of TblWznmQImeHk1NVector
	*/
class WznmQImeHk1NVector {

public:
	WznmQImeHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQImeHk1NVector: recordset of TblWznmQImeHk1NVector
	*/
class ListWznmQImeHk1NVector {

public:
	ListWznmQImeHk1NVector();
	ListWznmQImeHk1NVector(const ListWznmQImeHk1NVector& src);
	~ListWznmQImeHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WznmQImeHk1NVector* rec);

	ListWznmQImeHk1NVector& operator=(const ListWznmQImeHk1NVector& src);

public:
	std::vector<WznmQImeHk1NVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQImeHk1NVector: C++ wrapper for table TblWznmQImeHk1NVector
	*/
class TblWznmQImeHk1NVector {

public:
	TblWznmQImeHk1NVector();
	virtual ~TblWznmQImeHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQImeHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WznmQImeHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WznmQImeHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQImeHk1NVector& rst, WznmQImeHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQImeHk1NVector& rst);
	virtual void updateRec(WznmQImeHk1NVector* rec);
	virtual void updateRst(ListWznmQImeHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQImeHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQImeHk1NVector: C++ wrapper for table TblWznmQImeHk1NVector (MySQL database)
	*/
class MyTblWznmQImeHk1NVector : public TblWznmQImeHk1NVector, public Sbecore::MyTable {

public:
	MyTblWznmQImeHk1NVector();
	~MyTblWznmQImeHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQImeHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeHk1NVector& rst);

	Sbecore::ubigint insertRec(WznmQImeHk1NVector* rec);
	void insertRst(ListWznmQImeHk1NVector& rst);
	void updateRec(WznmQImeHk1NVector* rec);
	void updateRst(ListWznmQImeHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQImeHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQImeHk1NVector: C++ wrapper for table TblWznmQImeHk1NVector (PgSQL database)
	*/
class PgTblWznmQImeHk1NVector : public TblWznmQImeHk1NVector, public Sbecore::PgTable {

public:
	PgTblWznmQImeHk1NVector();
	~PgTblWznmQImeHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQImeHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQImeHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQImeHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQImeHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQImeHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQImeHk1NVector& rst);

	Sbecore::ubigint insertRec(WznmQImeHk1NVector* rec);
	void insertRst(ListWznmQImeHk1NVector& rst);
	void updateRec(WznmQImeHk1NVector* rec);
	void updateRst(ListWznmQImeHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQImeHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQImeHk1NVector& rst);
};
#endif

#endif

