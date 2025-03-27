/**
	* \file WznmMBox.h
	* database access for table TblWznmMBox (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMMBOX_H
#define WZNMMBOX_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMBox: record of TblWznmMBox
	*/
class WznmMBox {

public:
	WznmMBox(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSheet = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::smallint x = 0, const Sbecore::smallint y = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMSheet;
	Sbecore::uint unvIxWznmVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::smallint x;
	Sbecore::smallint y;

public:
	bool operator==(const WznmMBox& comp);
	bool operator!=(const WznmMBox& comp);
};

/**
	* ListWznmMBox: recordset of TblWznmMBox
	*/
class ListWznmMBox {

public:
	ListWznmMBox();
	ListWznmMBox(const ListWznmMBox& src);
	~ListWznmMBox();

	void clear();
	unsigned int size() const;
	void append(WznmMBox* rec);

	WznmMBox* operator[](const Sbecore::uint ix);
	ListWznmMBox& operator=(const ListWznmMBox& src);
	bool operator==(const ListWznmMBox& comp);
	bool operator!=(const ListWznmMBox& comp);

public:
	std::vector<WznmMBox*> nodes;
};

/**
	* TblWznmMBox: C++ wrapper for table TblWznmMBox
	*/
class TblWznmMBox {

public:

public:
	TblWznmMBox();
	virtual ~TblWznmMBox();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMBox** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMBox& rst);

	virtual Sbecore::ubigint insertRec(WznmMBox* rec);
	Sbecore::ubigint insertNewRec(WznmMBox** rec = NULL, const Sbecore::ubigint refWznmMSheet = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::smallint x = 0, const Sbecore::smallint y = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmMBox& rst, WznmMBox** rec = NULL, const Sbecore::ubigint refWznmMSheet = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::smallint x = 0, const Sbecore::smallint y = 0);
	virtual void insertRst(ListWznmMBox& rst, bool transact = false);
	virtual void updateRec(WznmMBox* rec);
	virtual void updateRst(ListWznmMBox& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMBox** rec);
	virtual Sbecore::ubigint loadRefsBySht(Sbecore::ubigint refWznmMSheet, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySht(Sbecore::ubigint refWznmMSheet, const bool append, ListWznmMBox& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMBox& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMBox: C++ wrapper for table TblWznmMBox (MySQL database)
	*/
class MyTblWznmMBox : public TblWznmMBox, public Sbecore::MyTable {

public:
	MyTblWznmMBox();
	~MyTblWznmMBox();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMBox& rst);

	Sbecore::ubigint insertRec(WznmMBox* rec);
	void insertRst(ListWznmMBox& rst, bool transact = false);
	void updateRec(WznmMBox* rec);
	void updateRst(ListWznmMBox& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMBox** rec);
	Sbecore::ubigint loadRefsBySht(Sbecore::ubigint refWznmMSheet, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySht(Sbecore::ubigint refWznmMSheet, const bool append, ListWznmMBox& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMBox: C++ wrapper for table TblWznmMBox (PgSQL database)
	*/
class PgTblWznmMBox : public TblWznmMBox, public Sbecore::PgTable {

public:
	PgTblWznmMBox();
	~PgTblWznmMBox();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMBox** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMBox& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMBox** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMBox& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMBox& rst);

	Sbecore::ubigint insertRec(WznmMBox* rec);
	void insertRst(ListWznmMBox& rst, bool transact = false);
	void updateRec(WznmMBox* rec);
	void updateRst(ListWznmMBox& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMBox** rec);
	Sbecore::ubigint loadRefsBySht(Sbecore::ubigint refWznmMSheet, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySht(Sbecore::ubigint refWznmMSheet, const bool append, ListWznmMBox& rst);
};
#endif

#endif
