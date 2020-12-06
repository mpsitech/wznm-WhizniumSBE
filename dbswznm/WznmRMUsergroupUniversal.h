/**
	* \file WznmRMUsergroupUniversal.h
	* database access for table TblWznmRMUsergroupUniversal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMUSERGROUPUNIVERSAL_H
#define WZNMRMUSERGROUPUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMUsergroupUniversal: record of TblWznmRMUsergroupUniversal
	*/
class WznmRMUsergroupUniversal {

public:
	WznmRMUsergroupUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWznmVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMUsergroup;
	Sbecore::uint unvIxWznmVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWznmVRecaccess;

public:
	bool operator==(const WznmRMUsergroupUniversal& comp);
	bool operator!=(const WznmRMUsergroupUniversal& comp);
};

/**
	* ListWznmRMUsergroupUniversal: recordset of TblWznmRMUsergroupUniversal
	*/
class ListWznmRMUsergroupUniversal {

public:
	ListWznmRMUsergroupUniversal();
	ListWznmRMUsergroupUniversal(const ListWznmRMUsergroupUniversal& src);
	~ListWznmRMUsergroupUniversal();

	void clear();
	unsigned int size() const;
	void append(WznmRMUsergroupUniversal* rec);

	WznmRMUsergroupUniversal* operator[](const Sbecore::uint ix);
	ListWznmRMUsergroupUniversal& operator=(const ListWznmRMUsergroupUniversal& src);
	bool operator==(const ListWznmRMUsergroupUniversal& comp);
	bool operator!=(const ListWznmRMUsergroupUniversal& comp);

public:
	std::vector<WznmRMUsergroupUniversal*> nodes;
};

/**
	* TblWznmRMUsergroupUniversal: C++ wrapper for table TblWznmRMUsergroupUniversal
	*/
class TblWznmRMUsergroupUniversal {

public:

public:
	TblWznmRMUsergroupUniversal();
	virtual ~TblWznmRMUsergroupUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMUsergroupUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMUsergroupUniversal& rst);

	virtual Sbecore::ubigint insertRec(WznmRMUsergroupUniversal* rec);
	Sbecore::ubigint insertNewRec(WznmRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWznmVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMUsergroupUniversal& rst, WznmRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWznmVRecaccess = 0);
	virtual void insertRst(ListWznmRMUsergroupUniversal& rst, bool transact = false);
	virtual void updateRec(WznmRMUsergroupUniversal* rec);
	virtual void updateRst(ListWznmRMUsergroupUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMUsergroupUniversal** rec);
	virtual bool loadRecByUsgMtbUnv(Sbecore::ubigint refWznmMUsergroup, Sbecore::uint unvIxWznmVMaintable, Sbecore::ubigint unvUref, WznmRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMUsergroupUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMUsergroupUniversal: C++ wrapper for table TblWznmRMUsergroupUniversal (MySQL database)
	*/
class MyTblWznmRMUsergroupUniversal : public TblWznmRMUsergroupUniversal, public Sbecore::MyTable {

public:
	MyTblWznmRMUsergroupUniversal();
	~MyTblWznmRMUsergroupUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(WznmRMUsergroupUniversal* rec);
	void insertRst(ListWznmRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(WznmRMUsergroupUniversal* rec);
	void updateRst(ListWznmRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refWznmMUsergroup, Sbecore::uint unvIxWznmVMaintable, Sbecore::ubigint unvUref, WznmRMUsergroupUniversal** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMUsergroupUniversal: C++ wrapper for table TblWznmRMUsergroupUniversal (PgSQL database)
	*/
class PgTblWznmRMUsergroupUniversal : public TblWznmRMUsergroupUniversal, public Sbecore::PgTable {

public:
	PgTblWznmRMUsergroupUniversal();
	~PgTblWznmRMUsergroupUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMUsergroupUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(WznmRMUsergroupUniversal* rec);
	void insertRst(ListWznmRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(WznmRMUsergroupUniversal* rec);
	void updateRst(ListWznmRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refWznmMUsergroup, Sbecore::uint unvIxWznmVMaintable, Sbecore::ubigint unvUref, WznmRMUsergroupUniversal** rec);
};
#endif

#endif
