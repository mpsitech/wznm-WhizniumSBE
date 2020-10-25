/**
	* \file WznmQVer1NVector.h
	* Dbs and XML wrapper for table TblWznmQVer1NVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQVER1NVECTOR_H
#define WZNMQVER1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NVector: record of TblWznmQVer1NVector
	*/
class WznmQVer1NVector {

public:
	WznmQVer1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NVector: recordset of TblWznmQVer1NVector
	*/
class ListWznmQVer1NVector {

public:
	ListWznmQVer1NVector();
	ListWznmQVer1NVector(const ListWznmQVer1NVector& src);
	~ListWznmQVer1NVector();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NVector* rec);

	ListWznmQVer1NVector& operator=(const ListWznmQVer1NVector& src);

public:
	std::vector<WznmQVer1NVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NVector: C++ wrapper for table TblWznmQVer1NVector
	*/
class TblWznmQVer1NVector {

public:
	TblWznmQVer1NVector();
	virtual ~TblWznmQVer1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NVector& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NVector* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NVector& rst, WznmQVer1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NVector& rst);
	virtual void updateRec(WznmQVer1NVector* rec);
	virtual void updateRst(ListWznmQVer1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NVector: C++ wrapper for table TblWznmQVer1NVector (MySQL database)
	*/
class MyTblWznmQVer1NVector : public TblWznmQVer1NVector, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NVector();
	~MyTblWznmQVer1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NVector& rst);

	Sbecore::ubigint insertRec(WznmQVer1NVector* rec);
	void insertRst(ListWznmQVer1NVector& rst);
	void updateRec(WznmQVer1NVector* rec);
	void updateRst(ListWznmQVer1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NVector: C++ wrapper for table TblWznmQVer1NVector (PgSQL database)
	*/
class PgTblWznmQVer1NVector : public TblWznmQVer1NVector, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NVector();
	~PgTblWznmQVer1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NVector& rst);

	Sbecore::ubigint insertRec(WznmQVer1NVector* rec);
	void insertRst(ListWznmQVer1NVector& rst);
	void updateRec(WznmQVer1NVector* rec);
	void updateRst(ListWznmQVer1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NVector& rst);
};
#endif

#endif

