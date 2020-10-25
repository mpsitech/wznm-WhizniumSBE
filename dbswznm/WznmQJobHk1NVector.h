/**
	* \file WznmQJobHk1NVector.h
	* Dbs and XML wrapper for table TblWznmQJobHk1NVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQJOBHK1NVECTOR_H
#define WZNMQJOBHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobHk1NVector: record of TblWznmQJobHk1NVector
	*/
class WznmQJobHk1NVector {

public:
	WznmQJobHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQJobHk1NVector: recordset of TblWznmQJobHk1NVector
	*/
class ListWznmQJobHk1NVector {

public:
	ListWznmQJobHk1NVector();
	ListWznmQJobHk1NVector(const ListWznmQJobHk1NVector& src);
	~ListWznmQJobHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WznmQJobHk1NVector* rec);

	ListWznmQJobHk1NVector& operator=(const ListWznmQJobHk1NVector& src);

public:
	std::vector<WznmQJobHk1NVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobHk1NVector: C++ wrapper for table TblWznmQJobHk1NVector
	*/
class TblWznmQJobHk1NVector {

public:
	TblWznmQJobHk1NVector();
	virtual ~TblWznmQJobHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WznmQJobHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobHk1NVector& rst, WznmQJobHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQJobHk1NVector& rst);
	virtual void updateRec(WznmQJobHk1NVector* rec);
	virtual void updateRst(ListWznmQJobHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobHk1NVector: C++ wrapper for table TblWznmQJobHk1NVector (MySQL database)
	*/
class MyTblWznmQJobHk1NVector : public TblWznmQJobHk1NVector, public Sbecore::MyTable {

public:
	MyTblWznmQJobHk1NVector();
	~MyTblWznmQJobHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobHk1NVector& rst);

	Sbecore::ubigint insertRec(WznmQJobHk1NVector* rec);
	void insertRst(ListWznmQJobHk1NVector& rst);
	void updateRec(WznmQJobHk1NVector* rec);
	void updateRst(ListWznmQJobHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobHk1NVector: C++ wrapper for table TblWznmQJobHk1NVector (PgSQL database)
	*/
class PgTblWznmQJobHk1NVector : public TblWznmQJobHk1NVector, public Sbecore::PgTable {

public:
	PgTblWznmQJobHk1NVector();
	~PgTblWznmQJobHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobHk1NVector& rst);

	Sbecore::ubigint insertRec(WznmQJobHk1NVector* rec);
	void insertRst(ListWznmQJobHk1NVector& rst);
	void updateRec(WznmQJobHk1NVector* rec);
	void updateRst(ListWznmQJobHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobHk1NVector& rst);
};
#endif

#endif

