/**
	* \file WznmAMUsergroupAccess.h
	* database access for table TblWznmAMUsergroupAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMUSERGROUPACCESS_H
#define WZNMAMUSERGROUPACCESS_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMUsergroupAccess: record of TblWznmAMUsergroupAccess
	*/
class WznmAMUsergroupAccess {

public:
	WznmAMUsergroupAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMUsergroup;
	Sbecore::uint x1IxWznmVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWznmWAccess;

public:
	bool operator==(const WznmAMUsergroupAccess& comp);
	bool operator!=(const WznmAMUsergroupAccess& comp);
};

/**
	* ListWznmAMUsergroupAccess: recordset of TblWznmAMUsergroupAccess
	*/
class ListWznmAMUsergroupAccess {

public:
	ListWznmAMUsergroupAccess();
	ListWznmAMUsergroupAccess(const ListWznmAMUsergroupAccess& src);
	~ListWznmAMUsergroupAccess();

	void clear();
	unsigned int size() const;
	void append(WznmAMUsergroupAccess* rec);

	WznmAMUsergroupAccess* operator[](const Sbecore::uint ix);
	ListWznmAMUsergroupAccess& operator=(const ListWznmAMUsergroupAccess& src);
	bool operator==(const ListWznmAMUsergroupAccess& comp);
	bool operator!=(const ListWznmAMUsergroupAccess& comp);

public:
	std::vector<WznmAMUsergroupAccess*> nodes;
};

/**
	* TblWznmAMUsergroupAccess: C++ wrapper for table TblWznmAMUsergroupAccess
	*/
class TblWznmAMUsergroupAccess {

public:

public:
	TblWznmAMUsergroupAccess();
	virtual ~TblWznmAMUsergroupAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMUsergroupAccess& rst);

	virtual Sbecore::ubigint insertRec(WznmAMUsergroupAccess* rec);
	Sbecore::ubigint insertNewRec(WznmAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmAMUsergroupAccess& rst, WznmAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0);
	virtual void insertRst(ListWznmAMUsergroupAccess& rst, bool transact = false);
	virtual void updateRec(WznmAMUsergroupAccess* rec);
	virtual void updateRst(ListWznmAMUsergroupAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, ListWznmAMUsergroupAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMUsergroupAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMUsergroupAccess: C++ wrapper for table TblWznmAMUsergroupAccess (MySQL database)
	*/
class MyTblWznmAMUsergroupAccess : public TblWznmAMUsergroupAccess, public Sbecore::MyTable {

public:
	MyTblWznmAMUsergroupAccess();
	~MyTblWznmAMUsergroupAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(WznmAMUsergroupAccess* rec);
	void insertRst(ListWznmAMUsergroupAccess& rst, bool transact = false);
	void updateRec(WznmAMUsergroupAccess* rec);
	void updateRst(ListWznmAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, ListWznmAMUsergroupAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMUsergroupAccess: C++ wrapper for table TblWznmAMUsergroupAccess (PgSQL database)
	*/
class PgTblWznmAMUsergroupAccess : public TblWznmAMUsergroupAccess, public Sbecore::PgTable {

public:
	PgTblWznmAMUsergroupAccess();
	~PgTblWznmAMUsergroupAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMUsergroupAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMUsergroupAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMUsergroupAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(WznmAMUsergroupAccess* rec);
	void insertRst(ListWznmAMUsergroupAccess& rst, bool transact = false);
	void updateRec(WznmAMUsergroupAccess* rec);
	void updateRst(ListWznmAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, ListWznmAMUsergroupAccess& rst);
};
#endif

#endif

