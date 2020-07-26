/**
	* \file WznmQJobAVar.h
	* Dbs and XML wrapper for table TblWznmQJobAVar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQJOBAVAR_H
#define WZNMQJOBAVAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobAVar: record of TblWznmQJobAVar
	*/
class WznmQJobAVar {

public:
	WznmQJobAVar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint jobNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const bool Shr = false, const std::string yesnoShr = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint jobNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	std::string srefIxWznmVVartype;
	std::string titIxWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	std::string stubRefWznmMVector;
	Sbecore::uint Length;
	bool Shr;
	std::string yesnoShr;
	std::string Comment;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQJobAVar: recordset of TblWznmQJobAVar
	*/
class ListWznmQJobAVar {

public:
	ListWznmQJobAVar();
	ListWznmQJobAVar(const ListWznmQJobAVar& src);
	~ListWznmQJobAVar();

	void clear();
	unsigned int size() const;
	void append(WznmQJobAVar* rec);

	ListWznmQJobAVar& operator=(const ListWznmQJobAVar& src);

public:
	std::vector<WznmQJobAVar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobAVar: C++ wrapper for table TblWznmQJobAVar
	*/
class TblWznmQJobAVar {

public:
	TblWznmQJobAVar();
	virtual ~TblWznmQJobAVar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobAVar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobAVar& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobAVar* rec);
	Sbecore::ubigint insertNewRec(WznmQJobAVar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint jobNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const bool Shr = false, const std::string yesnoShr = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobAVar& rst, WznmQJobAVar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint jobNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const std::string srefIxWznmVVartype = "", const std::string titIxWznmVVartype = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::uint Length = 0, const bool Shr = false, const std::string yesnoShr = "", const std::string Comment = "");
	virtual void insertRst(ListWznmQJobAVar& rst);
	virtual void updateRec(WznmQJobAVar* rec);
	virtual void updateRst(ListWznmQJobAVar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobAVar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobAVar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobAVar: C++ wrapper for table TblWznmQJobAVar (MySQL database)
	*/
class MyTblWznmQJobAVar : public TblWznmQJobAVar, public Sbecore::MyTable {

public:
	MyTblWznmQJobAVar();
	~MyTblWznmQJobAVar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobAVar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobAVar& rst);

	Sbecore::ubigint insertRec(WznmQJobAVar* rec);
	void insertRst(ListWznmQJobAVar& rst);
	void updateRec(WznmQJobAVar* rec);
	void updateRst(ListWznmQJobAVar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobAVar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobAVar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobAVar: C++ wrapper for table TblWznmQJobAVar (PgSQL database)
	*/
class PgTblWznmQJobAVar : public TblWznmQJobAVar, public Sbecore::PgTable {

public:
	PgTblWznmQJobAVar();
	~PgTblWznmQJobAVar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobAVar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobAVar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobAVar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobAVar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobAVar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobAVar& rst);

	Sbecore::ubigint insertRec(WznmQJobAVar* rec);
	void insertRst(ListWznmQJobAVar& rst);
	void updateRec(WznmQJobAVar* rec);
	void updateRst(ListWznmQJobAVar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobAVar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobAVar& rst);
};
#endif

#endif

