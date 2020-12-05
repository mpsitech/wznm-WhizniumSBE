/**
	* \file WznmMSubset.h
	* database access for table TblWznmMSubset (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMSUBSET_H
#define WZNMMSUBSET_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMSubset: record of TblWznmMSubset
	*/
class WznmMSubset {

public:
	WznmMSubset(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refWznmMCard = 0, const std::string sref = "", const std::string Short = "", const std::string Cond = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMTable;
	Sbecore::ubigint refWznmMPreset;
	Sbecore::ubigint refWznmMCard;
	std::string sref;
	std::string Short;
	std::string Cond;
	std::string Comment;

public:
	bool operator==(const WznmMSubset& comp);
	bool operator!=(const WznmMSubset& comp);
};

/**
	* ListWznmMSubset: recordset of TblWznmMSubset
	*/
class ListWznmMSubset {

public:
	ListWznmMSubset();
	ListWznmMSubset(const ListWznmMSubset& src);
	~ListWznmMSubset();

	void clear();
	unsigned int size() const;
	void append(WznmMSubset* rec);

	WznmMSubset* operator[](const Sbecore::uint ix);
	ListWznmMSubset& operator=(const ListWznmMSubset& src);
	bool operator==(const ListWznmMSubset& comp);
	bool operator!=(const ListWznmMSubset& comp);

public:
	std::vector<WznmMSubset*> nodes;
};

/**
	* TblWznmMSubset: C++ wrapper for table TblWznmMSubset
	*/
class TblWznmMSubset {

public:

public:
	TblWznmMSubset();
	virtual ~TblWznmMSubset();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMSubset** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSubset& rst);

	virtual Sbecore::ubigint insertRec(WznmMSubset* rec);
	Sbecore::ubigint insertNewRec(WznmMSubset** rec = NULL, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refWznmMCard = 0, const std::string sref = "", const std::string Short = "", const std::string Cond = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMSubset& rst, WznmMSubset** rec = NULL, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refWznmMCard = 0, const std::string sref = "", const std::string Short = "", const std::string Cond = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMSubset& rst, bool transact = false);
	virtual void updateRec(WznmMSubset* rec);
	virtual void updateRst(ListWznmMSubset& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMSubset** rec);
	virtual bool loadRecByCar(Sbecore::ubigint refWznmMCard, WznmMSubset** rec);
	virtual bool loadRecByPst(Sbecore::ubigint refWznmMPreset, WznmMSubset** rec);
	virtual Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmMSubset& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMSubset& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMSubset: C++ wrapper for table TblWznmMSubset (MySQL database)
	*/
class MyTblWznmMSubset : public TblWznmMSubset, public Sbecore::MyTable {

public:
	MyTblWznmMSubset();
	~MyTblWznmMSubset();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSubset& rst);

	Sbecore::ubigint insertRec(WznmMSubset* rec);
	void insertRst(ListWznmMSubset& rst, bool transact = false);
	void updateRec(WznmMSubset* rec);
	void updateRst(ListWznmMSubset& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSubset** rec);
	bool loadRecByCar(Sbecore::ubigint refWznmMCard, WznmMSubset** rec);
	bool loadRecByPst(Sbecore::ubigint refWznmMPreset, WznmMSubset** rec);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmMSubset& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMSubset: C++ wrapper for table TblWznmMSubset (PgSQL database)
	*/
class PgTblWznmMSubset : public TblWznmMSubset, public Sbecore::PgTable {

public:
	PgTblWznmMSubset();
	~PgTblWznmMSubset();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMSubset** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMSubset& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMSubset** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMSubset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSubset& rst);

	Sbecore::ubigint insertRec(WznmMSubset* rec);
	void insertRst(ListWznmMSubset& rst, bool transact = false);
	void updateRec(WznmMSubset* rec);
	void updateRst(ListWznmMSubset& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSubset** rec);
	bool loadRecByCar(Sbecore::ubigint refWznmMCard, WznmMSubset** rec);
	bool loadRecByPst(Sbecore::ubigint refWznmMPreset, WznmMSubset** rec);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmMSubset& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

