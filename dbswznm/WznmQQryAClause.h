/**
	* \file WznmQQryAClause.h
	* Dbs and XML wrapper for table TblWznmQQryAClause (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQQRYACLAUSE_H
#define WZNMQQRYACLAUSE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQryAClause: record of TblWznmQQryAClause
	*/
class WznmQQryAClause {

public:
	WznmQQryAClause(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint x1RefWznmMQuerymod = 0, const std::string stubX1RefWznmMQuerymod = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string Clause = "", const Sbecore::ubigint refWznmMPreset = 0, const std::string stubRefWznmMPreset = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint qryNum;
	Sbecore::ubigint x1RefWznmMQuerymod;
	std::string stubX1RefWznmMQuerymod;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string Clause;
	Sbecore::ubigint refWznmMPreset;
	std::string stubRefWznmMPreset;
	Sbecore::ubigint refWznmMVector;
	std::string stubRefWznmMVector;
	Sbecore::ubigint refWznmMVectoritem;
	std::string stubRefWznmMVectoritem;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQQryAClause: recordset of TblWznmQQryAClause
	*/
class ListWznmQQryAClause {

public:
	ListWznmQQryAClause();
	ListWznmQQryAClause(const ListWznmQQryAClause& src);
	~ListWznmQQryAClause();

	void clear();
	unsigned int size() const;
	void append(WznmQQryAClause* rec);

	ListWznmQQryAClause& operator=(const ListWznmQQryAClause& src);

public:
	std::vector<WznmQQryAClause*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQryAClause: C++ wrapper for table TblWznmQQryAClause
	*/
class TblWznmQQryAClause {

public:
	TblWznmQQryAClause();
	virtual ~TblWznmQQryAClause();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQryAClause** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryAClause& rst);

	virtual Sbecore::ubigint insertRec(WznmQQryAClause* rec);
	Sbecore::ubigint insertNewRec(WznmQQryAClause** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint x1RefWznmMQuerymod = 0, const std::string stubX1RefWznmMQuerymod = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string Clause = "", const Sbecore::ubigint refWznmMPreset = 0, const std::string stubRefWznmMPreset = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQQryAClause& rst, WznmQQryAClause** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint x1RefWznmMQuerymod = 0, const std::string stubX1RefWznmMQuerymod = "", const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string Clause = "", const Sbecore::ubigint refWznmMPreset = 0, const std::string stubRefWznmMPreset = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "");
	virtual void insertRst(ListWznmQQryAClause& rst);
	virtual void updateRec(WznmQQryAClause* rec);
	virtual void updateRst(ListWznmQQryAClause& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQryAClause** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryAClause& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQryAClause: C++ wrapper for table TblWznmQQryAClause (MySQL database)
	*/
class MyTblWznmQQryAClause : public TblWznmQQryAClause, public Sbecore::MyTable {

public:
	MyTblWznmQQryAClause();
	~MyTblWznmQQryAClause();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryAClause** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryAClause& rst);

	Sbecore::ubigint insertRec(WznmQQryAClause* rec);
	void insertRst(ListWznmQQryAClause& rst);
	void updateRec(WznmQQryAClause* rec);
	void updateRst(ListWznmQQryAClause& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryAClause** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryAClause& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQryAClause: C++ wrapper for table TblWznmQQryAClause (PgSQL database)
	*/
class PgTblWznmQQryAClause : public TblWznmQQryAClause, public Sbecore::PgTable {

public:
	PgTblWznmQQryAClause();
	~PgTblWznmQQryAClause();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQryAClause** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQryAClause& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQryAClause** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQryAClause& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQryAClause** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQryAClause& rst);

	Sbecore::ubigint insertRec(WznmQQryAClause* rec);
	void insertRst(ListWznmQQryAClause& rst);
	void updateRec(WznmQQryAClause* rec);
	void updateRst(ListWznmQQryAClause& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQryAClause** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQryAClause& rst);
};
#endif

#endif

