/**
	* \file WznmAccRMUserUniversal.h
	* database access for table TblWznmAccRMUserUniversal (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMACCRMUSERUNIVERSAL_H
#define WZNMACCRMUSERUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAccRMUserUniversal: record of TblWznmAccRMUserUniversal
	*/
class WznmAccRMUserUniversal {

public:
	WznmAccRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWznmVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMUser;
	Sbecore::uint unvIxWznmVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWznmVRecaccess;

public:
	bool operator==(const WznmAccRMUserUniversal& comp);
	bool operator!=(const WznmAccRMUserUniversal& comp);
};

/**
	* ListWznmAccRMUserUniversal: recordset of TblWznmAccRMUserUniversal
	*/
class ListWznmAccRMUserUniversal {

public:
	ListWznmAccRMUserUniversal();
	ListWznmAccRMUserUniversal(const ListWznmAccRMUserUniversal& src);
	~ListWznmAccRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(WznmAccRMUserUniversal* rec);

	WznmAccRMUserUniversal* operator[](const Sbecore::uint ix);
	ListWznmAccRMUserUniversal& operator=(const ListWznmAccRMUserUniversal& src);
	bool operator==(const ListWznmAccRMUserUniversal& comp);
	bool operator!=(const ListWznmAccRMUserUniversal& comp);

public:
	std::vector<WznmAccRMUserUniversal*> nodes;
};

/**
	* TblWznmAccRMUserUniversal: C++ wrapper for table TblWznmAccRMUserUniversal
	*/
class TblWznmAccRMUserUniversal {

public:

public:
	TblWznmAccRMUserUniversal();
	virtual ~TblWznmAccRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAccRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAccRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(WznmAccRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(WznmAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWznmVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmAccRMUserUniversal& rst, WznmAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWznmVRecaccess = 0);
	virtual void insertRst(ListWznmAccRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(WznmAccRMUserUniversal* rec);
	virtual void updateRst(ListWznmAccRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAccRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnv(Sbecore::ubigint refWznmMUser, Sbecore::uint unvIxWznmVMaintable, Sbecore::ubigint unvUref, WznmAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAccRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAccRMUserUniversal: C++ wrapper for table TblWznmAccRMUserUniversal (MySQL database)
	*/
class MyTblWznmAccRMUserUniversal : public TblWznmAccRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblWznmAccRMUserUniversal();
	~MyTblWznmAccRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WznmAccRMUserUniversal* rec);
	void insertRst(ListWznmAccRMUserUniversal& rst, bool transact = false);
	void updateRec(WznmAccRMUserUniversal* rec);
	void updateRst(ListWznmAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refWznmMUser, Sbecore::uint unvIxWznmVMaintable, Sbecore::ubigint unvUref, WznmAccRMUserUniversal** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAccRMUserUniversal: C++ wrapper for table TblWznmAccRMUserUniversal (PgSQL database)
	*/
class PgTblWznmAccRMUserUniversal : public TblWznmAccRMUserUniversal, public Sbecore::PgTable {

public:
	PgTblWznmAccRMUserUniversal();
	~PgTblWznmAccRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAccRMUserUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAccRMUserUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WznmAccRMUserUniversal* rec);
	void insertRst(ListWznmAccRMUserUniversal& rst, bool transact = false);
	void updateRec(WznmAccRMUserUniversal* rec);
	void updateRst(ListWznmAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refWznmMUser, Sbecore::uint unvIxWznmVMaintable, Sbecore::ubigint unvUref, WznmAccRMUserUniversal** rec);
};
#endif

#endif

