/**
	* \file WznmAMUserAccess.h
	* database access for table TblWznmAMUserAccess (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMAMUSERACCESS_H
#define WZNMAMUSERACCESS_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMUserAccess: record of TblWznmAMUserAccess
	*/
class WznmAMUserAccess {

public:
	WznmAMUserAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMUser;
	Sbecore::uint x1IxWznmVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWznmWAccess;

public:
	bool operator==(const WznmAMUserAccess& comp);
	bool operator!=(const WznmAMUserAccess& comp);
};

/**
	* ListWznmAMUserAccess: recordset of TblWznmAMUserAccess
	*/
class ListWznmAMUserAccess {

public:
	ListWznmAMUserAccess();
	ListWznmAMUserAccess(const ListWznmAMUserAccess& src);
	~ListWznmAMUserAccess();

	void clear();
	unsigned int size() const;
	void append(WznmAMUserAccess* rec);

	WznmAMUserAccess* operator[](const Sbecore::uint ix);
	ListWznmAMUserAccess& operator=(const ListWznmAMUserAccess& src);
	bool operator==(const ListWznmAMUserAccess& comp);
	bool operator!=(const ListWznmAMUserAccess& comp);

public:
	std::vector<WznmAMUserAccess*> nodes;
};

/**
	* TblWznmAMUserAccess: C++ wrapper for table TblWznmAMUserAccess
	*/
class TblWznmAMUserAccess {

public:

public:
	TblWznmAMUserAccess();
	virtual ~TblWznmAMUserAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMUserAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMUserAccess& rst);

	virtual Sbecore::ubigint insertRec(WznmAMUserAccess* rec);
	Sbecore::ubigint insertNewRec(WznmAMUserAccess** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmAMUserAccess& rst, WznmAMUserAccess** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint x1IxWznmVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWznmWAccess = 0);
	virtual void insertRst(ListWznmAMUserAccess& rst, bool transact = false);
	virtual void updateRec(WznmAMUserAccess* rec);
	virtual void updateRst(ListWznmAMUserAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMUserAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWznmMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWznmMUser, const bool append, ListWznmAMUserAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMUserAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMUserAccess: C++ wrapper for table TblWznmAMUserAccess (MySQL database)
	*/
class MyTblWznmAMUserAccess : public TblWznmAMUserAccess, public Sbecore::MyTable {

public:
	MyTblWznmAMUserAccess();
	~MyTblWznmAMUserAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMUserAccess& rst);

	Sbecore::ubigint insertRec(WznmAMUserAccess* rec);
	void insertRst(ListWznmAMUserAccess& rst, bool transact = false);
	void updateRec(WznmAMUserAccess* rec);
	void updateRst(ListWznmAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWznmMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWznmMUser, const bool append, ListWznmAMUserAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMUserAccess: C++ wrapper for table TblWznmAMUserAccess (PgSQL database)
	*/
class PgTblWznmAMUserAccess : public TblWznmAMUserAccess, public Sbecore::PgTable {

public:
	PgTblWznmAMUserAccess();
	~PgTblWznmAMUserAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMUserAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMUserAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMUserAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMUserAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMUserAccess& rst);

	Sbecore::ubigint insertRec(WznmAMUserAccess* rec);
	void insertRst(ListWznmAMUserAccess& rst, bool transact = false);
	void updateRec(WznmAMUserAccess* rec);
	void updateRst(ListWznmAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWznmMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWznmMUser, const bool append, ListWznmAMUserAccess& rst);
};
#endif

#endif

