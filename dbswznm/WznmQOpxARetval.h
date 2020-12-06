/**
	* \file WznmQOpxARetval.h
	* Dbs and XML wrapper for table TblWznmQOpxARetval (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPXARETVAL_H
#define WZNMQOPXARETVAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpxARetval: record of TblWznmQOpxARetval
	*/
class WznmQOpxARetval {

public:
	WznmQOpxARetval(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint opxNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	std::string stubRefWznmMVector;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQOpxARetval: recordset of TblWznmQOpxARetval
	*/
class ListWznmQOpxARetval {

public:
	ListWznmQOpxARetval();
	ListWznmQOpxARetval(const ListWznmQOpxARetval& src);
	~ListWznmQOpxARetval();

	void clear();
	unsigned int size() const;
	void append(WznmQOpxARetval* rec);

	ListWznmQOpxARetval& operator=(const ListWznmQOpxARetval& src);

public:
	std::vector<WznmQOpxARetval*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpxARetval: C++ wrapper for table TblWznmQOpxARetval
	*/
class TblWznmQOpxARetval {

public:
	TblWznmQOpxARetval();
	virtual ~TblWznmQOpxARetval();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpxARetval** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxARetval& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpxARetval* rec);
	Sbecore::ubigint insertNewRec(WznmQOpxARetval** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpxARetval& rst, WznmQOpxARetval** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Comment = "");
	virtual void insertRst(ListWznmQOpxARetval& rst);
	virtual void updateRec(WznmQOpxARetval* rec);
	virtual void updateRst(ListWznmQOpxARetval& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxARetval** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxARetval& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpxARetval: C++ wrapper for table TblWznmQOpxARetval (MySQL database)
	*/
class MyTblWznmQOpxARetval : public TblWznmQOpxARetval, public Sbecore::MyTable {

public:
	MyTblWznmQOpxARetval();
	~MyTblWznmQOpxARetval();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxARetval** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxARetval& rst);

	Sbecore::ubigint insertRec(WznmQOpxARetval* rec);
	void insertRst(ListWznmQOpxARetval& rst);
	void updateRec(WznmQOpxARetval* rec);
	void updateRst(ListWznmQOpxARetval& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxARetval** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxARetval& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpxARetval: C++ wrapper for table TblWznmQOpxARetval (PgSQL database)
	*/
class PgTblWznmQOpxARetval : public TblWznmQOpxARetval, public Sbecore::PgTable {

public:
	PgTblWznmQOpxARetval();
	~PgTblWznmQOpxARetval();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpxARetval** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpxARetval& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpxARetval** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpxARetval& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxARetval** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxARetval& rst);

	Sbecore::ubigint insertRec(WznmQOpxARetval* rec);
	void insertRst(ListWznmQOpxARetval& rst);
	void updateRec(WznmQOpxARetval* rec);
	void updateRst(ListWznmQOpxARetval& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxARetval** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxARetval& rst);
};
#endif

#endif
