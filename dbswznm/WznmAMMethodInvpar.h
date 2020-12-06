/**
	* \file WznmAMMethodInvpar.h
	* database access for table TblWznmAMMethodInvpar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMMETHODINVPAR_H
#define WZNMAMMETHODINVPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMMethodInvpar: record of TblWznmAMMethodInvpar
	*/
class WznmAMMethodInvpar {

public:
	WznmAMMethodInvpar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint mtdRefWznmMMethod = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint Length = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint mtdRefWznmMMethod;
	Sbecore::uint mtdNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	Sbecore::uint Length;
	std::string Comment;

public:
	bool operator==(const WznmAMMethodInvpar& comp);
	bool operator!=(const WznmAMMethodInvpar& comp);
};

/**
	* ListWznmAMMethodInvpar: recordset of TblWznmAMMethodInvpar
	*/
class ListWznmAMMethodInvpar {

public:
	ListWznmAMMethodInvpar();
	ListWznmAMMethodInvpar(const ListWznmAMMethodInvpar& src);
	~ListWznmAMMethodInvpar();

	void clear();
	unsigned int size() const;
	void append(WznmAMMethodInvpar* rec);

	WznmAMMethodInvpar* operator[](const Sbecore::uint ix);
	ListWznmAMMethodInvpar& operator=(const ListWznmAMMethodInvpar& src);
	bool operator==(const ListWznmAMMethodInvpar& comp);
	bool operator!=(const ListWznmAMMethodInvpar& comp);

public:
	std::vector<WznmAMMethodInvpar*> nodes;
};

/**
	* TblWznmAMMethodInvpar: C++ wrapper for table TblWznmAMMethodInvpar
	*/
class TblWznmAMMethodInvpar {

public:

public:
	TblWznmAMMethodInvpar();
	virtual ~TblWznmAMMethodInvpar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMMethodInvpar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMethodInvpar& rst);

	virtual Sbecore::ubigint insertRec(WznmAMMethodInvpar* rec);
	Sbecore::ubigint insertNewRec(WznmAMMethodInvpar** rec = NULL, const Sbecore::ubigint mtdRefWznmMMethod = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint Length = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMMethodInvpar& rst, WznmAMMethodInvpar** rec = NULL, const Sbecore::ubigint mtdRefWznmMMethod = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint Length = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmAMMethodInvpar& rst, bool transact = false);
	virtual void updateRec(WznmAMMethodInvpar* rec);
	virtual void updateRst(ListWznmAMMethodInvpar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMMethodInvpar** rec);
	virtual Sbecore::ubigint loadRefsByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, ListWznmAMMethodInvpar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMMethodInvpar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMMethodInvpar: C++ wrapper for table TblWznmAMMethodInvpar (MySQL database)
	*/
class MyTblWznmAMMethodInvpar : public TblWznmAMMethodInvpar, public Sbecore::MyTable {

public:
	MyTblWznmAMMethodInvpar();
	~MyTblWznmAMMethodInvpar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMethodInvpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMethodInvpar& rst);

	Sbecore::ubigint insertRec(WznmAMMethodInvpar* rec);
	void insertRst(ListWznmAMMethodInvpar& rst, bool transact = false);
	void updateRec(WznmAMMethodInvpar* rec);
	void updateRst(ListWznmAMMethodInvpar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMethodInvpar** rec);
	Sbecore::ubigint loadRefsByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, ListWznmAMMethodInvpar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMMethodInvpar: C++ wrapper for table TblWznmAMMethodInvpar (PgSQL database)
	*/
class PgTblWznmAMMethodInvpar : public TblWznmAMMethodInvpar, public Sbecore::PgTable {

public:
	PgTblWznmAMMethodInvpar();
	~PgTblWznmAMMethodInvpar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMMethodInvpar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMMethodInvpar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMMethodInvpar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMMethodInvpar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMethodInvpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMethodInvpar& rst);

	Sbecore::ubigint insertRec(WznmAMMethodInvpar* rec);
	void insertRst(ListWznmAMMethodInvpar& rst, bool transact = false);
	void updateRec(WznmAMMethodInvpar* rec);
	void updateRst(ListWznmAMMethodInvpar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMethodInvpar** rec);
	Sbecore::ubigint loadRefsByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, ListWznmAMMethodInvpar& rst);
};
#endif

#endif
