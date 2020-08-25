/**
	* \file WznmRMUserMUsergroup.h
	* database access for table TblWznmRMUserMUsergroup (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMRMUSERMUSERGROUP_H
#define WZNMRMUSERMUSERGROUP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMUserMUsergroup: record of TblWznmRMUserMUsergroup
	*/
class WznmRMUserMUsergroup {

public:
	WznmRMUserMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::uint ixWznmVUserlevel = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMUser;
	Sbecore::ubigint refWznmMUsergroup;
	Sbecore::uint ixWznmVUserlevel;

public:
	bool operator==(const WznmRMUserMUsergroup& comp);
	bool operator!=(const WznmRMUserMUsergroup& comp);
};

/**
	* ListWznmRMUserMUsergroup: recordset of TblWznmRMUserMUsergroup
	*/
class ListWznmRMUserMUsergroup {

public:
	ListWznmRMUserMUsergroup();
	ListWznmRMUserMUsergroup(const ListWznmRMUserMUsergroup& src);
	~ListWznmRMUserMUsergroup();

	void clear();
	unsigned int size() const;
	void append(WznmRMUserMUsergroup* rec);

	WznmRMUserMUsergroup* operator[](const Sbecore::uint ix);
	ListWznmRMUserMUsergroup& operator=(const ListWznmRMUserMUsergroup& src);
	bool operator==(const ListWznmRMUserMUsergroup& comp);
	bool operator!=(const ListWznmRMUserMUsergroup& comp);

public:
	std::vector<WznmRMUserMUsergroup*> nodes;
};

/**
	* TblWznmRMUserMUsergroup: C++ wrapper for table TblWznmRMUserMUsergroup
	*/
class TblWznmRMUserMUsergroup {

public:

public:
	TblWznmRMUserMUsergroup();
	virtual ~TblWznmRMUserMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMUserMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WznmRMUserMUsergroup* rec);
	Sbecore::ubigint insertNewRec(WznmRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::uint ixWznmVUserlevel = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMUserMUsergroup& rst, WznmRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::uint ixWznmVUserlevel = 0);
	virtual void insertRst(ListWznmRMUserMUsergroup& rst, bool transact = false);
	virtual void updateRec(WznmRMUserMUsergroup* rec);
	virtual void updateRst(ListWznmRMUserMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, ListWznmRMUserMUsergroup& rst);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWznmMUser, const bool append, ListWznmRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMUserMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMUserMUsergroup: C++ wrapper for table TblWznmRMUserMUsergroup (MySQL database)
	*/
class MyTblWznmRMUserMUsergroup : public TblWznmRMUserMUsergroup, public Sbecore::MyTable {

public:
	MyTblWznmRMUserMUsergroup();
	~MyTblWznmRMUserMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(WznmRMUserMUsergroup* rec);
	void insertRst(ListWznmRMUserMUsergroup& rst, bool transact = false);
	void updateRec(WznmRMUserMUsergroup* rec);
	void updateRst(ListWznmRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, ListWznmRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWznmMUser, const bool append, ListWznmRMUserMUsergroup& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMUserMUsergroup: C++ wrapper for table TblWznmRMUserMUsergroup (PgSQL database)
	*/
class PgTblWznmRMUserMUsergroup : public TblWznmRMUserMUsergroup, public Sbecore::PgTable {

public:
	PgTblWznmRMUserMUsergroup();
	~PgTblWznmRMUserMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMUserMUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMUserMUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmRMUserMUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(WznmRMUserMUsergroup* rec);
	void insertRst(ListWznmRMUserMUsergroup& rst, bool transact = false);
	void updateRec(WznmRMUserMUsergroup* rec);
	void updateRst(ListWznmRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, ListWznmRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWznmMUser, const bool append, ListWznmRMUserMUsergroup& rst);
};
#endif

#endif

