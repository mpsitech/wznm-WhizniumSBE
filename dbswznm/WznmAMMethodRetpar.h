/**
	* \file WznmAMMethodRetpar.h
	* database access for table TblWznmAMMethodRetpar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMMETHODRETPAR_H
#define WZNMAMMETHODRETPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMMethodRetpar: record of TblWznmAMMethodRetpar
	*/
class WznmAMMethodRetpar {

public:
	WznmAMMethodRetpar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint mtdRefWznmMMethod = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint Length = 0, const std::string Comment = "");

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
	bool operator==(const WznmAMMethodRetpar& comp);
	bool operator!=(const WznmAMMethodRetpar& comp);
};

/**
	* ListWznmAMMethodRetpar: recordset of TblWznmAMMethodRetpar
	*/
class ListWznmAMMethodRetpar {

public:
	ListWznmAMMethodRetpar();
	ListWznmAMMethodRetpar(const ListWznmAMMethodRetpar& src);
	~ListWznmAMMethodRetpar();

	void clear();
	unsigned int size() const;
	void append(WznmAMMethodRetpar* rec);

	WznmAMMethodRetpar* operator[](const Sbecore::uint ix);
	ListWznmAMMethodRetpar& operator=(const ListWznmAMMethodRetpar& src);
	bool operator==(const ListWznmAMMethodRetpar& comp);
	bool operator!=(const ListWznmAMMethodRetpar& comp);

public:
	std::vector<WznmAMMethodRetpar*> nodes;
};

/**
	* TblWznmAMMethodRetpar: C++ wrapper for table TblWznmAMMethodRetpar
	*/
class TblWznmAMMethodRetpar {

public:

public:
	TblWznmAMMethodRetpar();
	virtual ~TblWznmAMMethodRetpar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMMethodRetpar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMethodRetpar& rst);

	virtual Sbecore::ubigint insertRec(WznmAMMethodRetpar* rec);
	Sbecore::ubigint insertNewRec(WznmAMMethodRetpar** rec = NULL, const Sbecore::ubigint mtdRefWznmMMethod = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint Length = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMMethodRetpar& rst, WznmAMMethodRetpar** rec = NULL, const Sbecore::ubigint mtdRefWznmMMethod = 0, const Sbecore::uint mtdNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint Length = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmAMMethodRetpar& rst, bool transact = false);
	virtual void updateRec(WznmAMMethodRetpar* rec);
	virtual void updateRst(ListWznmAMMethodRetpar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMMethodRetpar** rec);
	virtual Sbecore::ubigint loadRefsByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, ListWznmAMMethodRetpar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMMethodRetpar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMMethodRetpar: C++ wrapper for table TblWznmAMMethodRetpar (MySQL database)
	*/
class MyTblWznmAMMethodRetpar : public TblWznmAMMethodRetpar, public Sbecore::MyTable {

public:
	MyTblWznmAMMethodRetpar();
	~MyTblWznmAMMethodRetpar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMethodRetpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMethodRetpar& rst);

	Sbecore::ubigint insertRec(WznmAMMethodRetpar* rec);
	void insertRst(ListWznmAMMethodRetpar& rst, bool transact = false);
	void updateRec(WznmAMMethodRetpar* rec);
	void updateRst(ListWznmAMMethodRetpar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMethodRetpar** rec);
	Sbecore::ubigint loadRefsByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, ListWznmAMMethodRetpar& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMMethodRetpar: C++ wrapper for table TblWznmAMMethodRetpar (PgSQL database)
	*/
class PgTblWznmAMMethodRetpar : public TblWznmAMMethodRetpar, public Sbecore::PgTable {

public:
	PgTblWznmAMMethodRetpar();
	~PgTblWznmAMMethodRetpar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMMethodRetpar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMMethodRetpar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMMethodRetpar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMMethodRetpar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMethodRetpar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMethodRetpar& rst);

	Sbecore::ubigint insertRec(WznmAMMethodRetpar* rec);
	void insertRst(ListWznmAMMethodRetpar& rst, bool transact = false);
	void updateRec(WznmAMMethodRetpar* rec);
	void updateRst(ListWznmAMMethodRetpar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMethodRetpar** rec);
	Sbecore::ubigint loadRefsByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMtd(Sbecore::ubigint mtdRefWznmMMethod, const bool append, ListWznmAMMethodRetpar& rst);
};
#endif

#endif

