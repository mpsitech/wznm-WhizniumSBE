/**
	* \file WznmQMtdAInvpar.h
	* Dbs and XML wrapper for table TblWznmQMtdAInvpar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQMTDAINVPAR_H
#define WZNMQMTDAINVPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMtdAInvpar: record of TblWznmQMtdAInvpar
	*/
class WznmQMtdAInvpar {

public:
	WznmQMtdAInvpar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint mtdNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	std::string stubRefWznmMVector;
	Sbecore::uint Length;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMtdAInvpar: recordset of TblWznmQMtdAInvpar
	*/
class ListWznmQMtdAInvpar {

public:
	ListWznmQMtdAInvpar();
	ListWznmQMtdAInvpar(const ListWznmQMtdAInvpar& src);
	~ListWznmQMtdAInvpar();

	void clear();
	unsigned int size() const;
	void append(WznmQMtdAInvpar* rec);

	ListWznmQMtdAInvpar& operator=(const ListWznmQMtdAInvpar& src);

public:
	std::vector<WznmQMtdAInvpar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMtdAInvpar: C++ wrapper for table TblWznmQMtdAInvpar
	*/
class TblWznmQMtdAInvpar {

public:
	TblWznmQMtdAInvpar();
	virtual ~TblWznmQMtdAInvpar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMtdAInvpar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtdAInvpar& rst);

	virtual Sbecore::ubigint insertRec(WznmQMtdAInvpar* rec);
	Sbecore::ubigint insertNewRec(WznmQMtdAInvpar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMtdAInvpar& rst, WznmQMtdAInvpar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmQMtdAInvpar& rst);
	virtual void updateRec(WznmQMtdAInvpar* rec);
	virtual void updateRst(ListWznmQMtdAInvpar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMtdAInvpar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtdAInvpar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMtdAInvpar: C++ wrapper for table TblWznmQMtdAInvpar (MySQL database)
	*/
class MyTblWznmQMtdAInvpar : public TblWznmQMtdAInvpar, public Sbecore::MyTable {

public:
	MyTblWznmQMtdAInvpar();
	~MyTblWznmQMtdAInvpar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtdAInvpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtdAInvpar& rst);

	Sbecore::ubigint insertRec(WznmQMtdAInvpar* rec);
	void insertRst(ListWznmQMtdAInvpar& rst);
	void updateRec(WznmQMtdAInvpar* rec);
	void updateRst(ListWznmQMtdAInvpar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtdAInvpar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtdAInvpar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMtdAInvpar: C++ wrapper for table TblWznmQMtdAInvpar (PgSQL database)
	*/
class PgTblWznmQMtdAInvpar : public TblWznmQMtdAInvpar, public Sbecore::PgTable {

public:
	PgTblWznmQMtdAInvpar();
	~PgTblWznmQMtdAInvpar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMtdAInvpar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMtdAInvpar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMtdAInvpar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMtdAInvpar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtdAInvpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtdAInvpar& rst);

	Sbecore::ubigint insertRec(WznmQMtdAInvpar* rec);
	void insertRst(ListWznmQMtdAInvpar& rst);
	void updateRec(WznmQMtdAInvpar* rec);
	void updateRst(ListWznmQMtdAInvpar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtdAInvpar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtdAInvpar& rst);
};
#endif

#endif

