/**
	* \file WznmQTblHk1NVector.h
	* Dbs and XML wrapper for table TblWznmQTblHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLHK1NVECTOR_H
#define WZNMQTBLHK1NVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblHk1NVector: record of TblWznmQTblHk1NVector
	*/
class WznmQTblHk1NVector {

public:
	WznmQTblHk1NVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTblHk1NVector: recordset of TblWznmQTblHk1NVector
	*/
class ListWznmQTblHk1NVector {

public:
	ListWznmQTblHk1NVector();
	ListWznmQTblHk1NVector(const ListWznmQTblHk1NVector& src);
	~ListWznmQTblHk1NVector();

	void clear();
	unsigned int size() const;
	void append(WznmQTblHk1NVector* rec);

	ListWznmQTblHk1NVector& operator=(const ListWznmQTblHk1NVector& src);

public:
	std::vector<WznmQTblHk1NVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblHk1NVector: C++ wrapper for table TblWznmQTblHk1NVector
	*/
class TblWznmQTblHk1NVector {

public:
	TblWznmQTblHk1NVector();
	virtual ~TblWznmQTblHk1NVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblHk1NVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblHk1NVector& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblHk1NVector* rec);
	Sbecore::ubigint insertNewRec(WznmQTblHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblHk1NVector& rst, WznmQTblHk1NVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblHk1NVector& rst);
	virtual void updateRec(WznmQTblHk1NVector* rec);
	virtual void updateRst(ListWznmQTblHk1NVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblHk1NVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblHk1NVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblHk1NVector: C++ wrapper for table TblWznmQTblHk1NVector (MySQL database)
	*/
class MyTblWznmQTblHk1NVector : public TblWznmQTblHk1NVector, public Sbecore::MyTable {

public:
	MyTblWznmQTblHk1NVector();
	~MyTblWznmQTblHk1NVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblHk1NVector& rst);

	Sbecore::ubigint insertRec(WznmQTblHk1NVector* rec);
	void insertRst(ListWznmQTblHk1NVector& rst);
	void updateRec(WznmQTblHk1NVector* rec);
	void updateRst(ListWznmQTblHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblHk1NVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblHk1NVector: C++ wrapper for table TblWznmQTblHk1NVector (PgSQL database)
	*/
class PgTblWznmQTblHk1NVector : public TblWznmQTblHk1NVector, public Sbecore::PgTable {

public:
	PgTblWznmQTblHk1NVector();
	~PgTblWznmQTblHk1NVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblHk1NVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblHk1NVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblHk1NVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblHk1NVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblHk1NVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblHk1NVector& rst);

	Sbecore::ubigint insertRec(WznmQTblHk1NVector* rec);
	void insertRst(ListWznmQTblHk1NVector& rst);
	void updateRec(WznmQTblHk1NVector* rec);
	void updateRst(ListWznmQTblHk1NVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblHk1NVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblHk1NVector& rst);
};
#endif

#endif

