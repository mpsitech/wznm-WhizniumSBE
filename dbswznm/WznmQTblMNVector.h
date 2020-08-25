/**
	* \file WznmQTblMNVector.h
	* Dbs and XML wrapper for table TblWznmQTblMNVector (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLMNVECTOR_H
#define WZNMQTBLMNVECTOR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblMNVector: record of TblWznmQTblMNVector
	*/
class WznmQTblMNVector {

public:
	WznmQTblMNVector(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSubset = 0, const std::string stubRefWznmMSubset = "");

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
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTblMNVector: recordset of TblWznmQTblMNVector
	*/
class ListWznmQTblMNVector {

public:
	ListWznmQTblMNVector();
	ListWznmQTblMNVector(const ListWznmQTblMNVector& src);
	~ListWznmQTblMNVector();

	void clear();
	unsigned int size() const;
	void append(WznmQTblMNVector* rec);

	ListWznmQTblMNVector& operator=(const ListWznmQTblMNVector& src);

public:
	std::vector<WznmQTblMNVector*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblMNVector: C++ wrapper for table TblWznmQTblMNVector
	*/
class TblWznmQTblMNVector {

public:
	TblWznmQTblMNVector();
	virtual ~TblWznmQTblMNVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblMNVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblMNVector& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblMNVector* rec);
	Sbecore::ubigint insertNewRec(WznmQTblMNVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSubset = 0, const std::string stubRefWznmMSubset = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblMNVector& rst, WznmQTblMNVector** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSubset = 0, const std::string stubRefWznmMSubset = "");
	virtual void insertRst(ListWznmQTblMNVector& rst);
	virtual void updateRec(WznmQTblMNVector* rec);
	virtual void updateRst(ListWznmQTblMNVector& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblMNVector** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblMNVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblMNVector: C++ wrapper for table TblWznmQTblMNVector (MySQL database)
	*/
class MyTblWznmQTblMNVector : public TblWznmQTblMNVector, public Sbecore::MyTable {

public:
	MyTblWznmQTblMNVector();
	~MyTblWznmQTblMNVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblMNVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblMNVector& rst);

	Sbecore::ubigint insertRec(WznmQTblMNVector* rec);
	void insertRst(ListWznmQTblMNVector& rst);
	void updateRec(WznmQTblMNVector* rec);
	void updateRst(ListWznmQTblMNVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblMNVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblMNVector& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblMNVector: C++ wrapper for table TblWznmQTblMNVector (PgSQL database)
	*/
class PgTblWznmQTblMNVector : public TblWznmQTblMNVector, public Sbecore::PgTable {

public:
	PgTblWznmQTblMNVector();
	~PgTblWznmQTblMNVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblMNVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblMNVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblMNVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblMNVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblMNVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblMNVector& rst);

	Sbecore::ubigint insertRec(WznmQTblMNVector* rec);
	void insertRst(ListWznmQTblMNVector& rst);
	void updateRec(WznmQTblMNVector* rec);
	void updateRst(ListWznmQTblMNVector& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblMNVector** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblMNVector& rst);
};
#endif

#endif

