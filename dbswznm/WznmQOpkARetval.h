/**
	* \file WznmQOpkARetval.h
	* Dbs and XML wrapper for table TblWznmQOpkARetval (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPKARETVAL_H
#define WZNMQOPKARETVAL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpkARetval: record of TblWznmQOpkARetval
	*/
class WznmQOpkARetval {

public:
	WznmQOpkARetval(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint opkNum;
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
	* ListWznmQOpkARetval: recordset of TblWznmQOpkARetval
	*/
class ListWznmQOpkARetval {

public:
	ListWznmQOpkARetval();
	ListWznmQOpkARetval(const ListWznmQOpkARetval& src);
	~ListWznmQOpkARetval();

	void clear();
	unsigned int size() const;
	void append(WznmQOpkARetval* rec);

	ListWznmQOpkARetval& operator=(const ListWznmQOpkARetval& src);

public:
	std::vector<WznmQOpkARetval*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpkARetval: C++ wrapper for table TblWznmQOpkARetval
	*/
class TblWznmQOpkARetval {

public:
	TblWznmQOpkARetval();
	virtual ~TblWznmQOpkARetval();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpkARetval** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkARetval& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpkARetval* rec);
	Sbecore::ubigint insertNewRec(WznmQOpkARetval** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpkARetval& rst, WznmQOpkARetval** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const std::string Comment = "");
	virtual void insertRst(ListWznmQOpkARetval& rst);
	virtual void updateRec(WznmQOpkARetval* rec);
	virtual void updateRst(ListWznmQOpkARetval& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkARetval** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkARetval& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpkARetval: C++ wrapper for table TblWznmQOpkARetval (MySQL database)
	*/
class MyTblWznmQOpkARetval : public TblWznmQOpkARetval, public Sbecore::MyTable {

public:
	MyTblWznmQOpkARetval();
	~MyTblWznmQOpkARetval();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkARetval** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkARetval& rst);

	Sbecore::ubigint insertRec(WznmQOpkARetval* rec);
	void insertRst(ListWznmQOpkARetval& rst);
	void updateRec(WznmQOpkARetval* rec);
	void updateRst(ListWznmQOpkARetval& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkARetval** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkARetval& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpkARetval: C++ wrapper for table TblWznmQOpkARetval (PgSQL database)
	*/
class PgTblWznmQOpkARetval : public TblWznmQOpkARetval, public Sbecore::PgTable {

public:
	PgTblWznmQOpkARetval();
	~PgTblWznmQOpkARetval();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpkARetval** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpkARetval& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpkARetval** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpkARetval& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkARetval** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkARetval& rst);

	Sbecore::ubigint insertRec(WznmQOpkARetval* rec);
	void insertRst(ListWznmQOpkARetval& rst);
	void updateRec(WznmQOpkARetval* rec);
	void updateRst(ListWznmQOpkARetval& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkARetval** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkARetval& rst);
};
#endif

#endif
