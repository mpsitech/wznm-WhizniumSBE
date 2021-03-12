/**
	* \file WznmQMtdARetpar.h
	* Dbs and XML wrapper for table TblWznmQMtdARetpar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQMTDARETPAR_H
#define WZNMQMTDARETPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMtdARetpar: record of TblWznmQMtdARetpar
	*/
class WznmQMtdARetpar {

public:
	WznmQMtdARetpar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string Comment = "");

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
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMtdARetpar: recordset of TblWznmQMtdARetpar
	*/
class ListWznmQMtdARetpar {

public:
	ListWznmQMtdARetpar();
	ListWznmQMtdARetpar(const ListWznmQMtdARetpar& src);
	~ListWznmQMtdARetpar();

	void clear();
	unsigned int size() const;
	void append(WznmQMtdARetpar* rec);

	ListWznmQMtdARetpar& operator=(const ListWznmQMtdARetpar& src);

public:
	std::vector<WznmQMtdARetpar*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMtdARetpar: C++ wrapper for table TblWznmQMtdARetpar
	*/
class TblWznmQMtdARetpar {

public:
	TblWznmQMtdARetpar();
	virtual ~TblWznmQMtdARetpar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMtdARetpar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtdARetpar& rst);

	virtual Sbecore::ubigint insertRec(WznmQMtdARetpar* rec);
	Sbecore::ubigint insertNewRec(WznmQMtdARetpar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQMtdARetpar& rst, WznmQMtdARetpar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmQMtdARetpar& rst);
	virtual void updateRec(WznmQMtdARetpar* rec);
	virtual void updateRst(ListWznmQMtdARetpar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMtdARetpar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtdARetpar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMtdARetpar: C++ wrapper for table TblWznmQMtdARetpar (MySQL database)
	*/
class MyTblWznmQMtdARetpar : public TblWznmQMtdARetpar, public Sbecore::MyTable {

public:
	MyTblWznmQMtdARetpar();
	~MyTblWznmQMtdARetpar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtdARetpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtdARetpar& rst);

	Sbecore::ubigint insertRec(WznmQMtdARetpar* rec);
	void insertRst(ListWznmQMtdARetpar& rst);
	void updateRec(WznmQMtdARetpar* rec);
	void updateRst(ListWznmQMtdARetpar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtdARetpar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtdARetpar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMtdARetpar: C++ wrapper for table TblWznmQMtdARetpar (PgSQL database)
	*/
class PgTblWznmQMtdARetpar : public TblWznmQMtdARetpar, public Sbecore::PgTable {

public:
	PgTblWznmQMtdARetpar();
	~PgTblWznmQMtdARetpar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMtdARetpar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMtdARetpar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMtdARetpar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMtdARetpar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMtdARetpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMtdARetpar& rst);

	Sbecore::ubigint insertRec(WznmQMtdARetpar* rec);
	void insertRst(ListWznmQMtdARetpar& rst);
	void updateRec(WznmQMtdARetpar* rec);
	void updateRst(ListWznmQMtdARetpar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMtdARetpar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMtdARetpar& rst);
};
#endif

#endif
