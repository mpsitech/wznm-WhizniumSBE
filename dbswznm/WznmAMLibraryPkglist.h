/**
	* \file WznmAMLibraryPkglist.h
	* database access for table TblWznmAMLibraryPkglist (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMLIBRARYPKGLIST_H
#define WZNMAMLIBRARYPKGLIST_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMLibraryPkglist: record of TblWznmAMLibraryPkglist
	*/
class WznmAMLibraryPkglist {

public:
	WznmAMLibraryPkglist(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMLibrary = 0, const Sbecore::ubigint x1RefWznmMMachine = 0, const std::string Pkglist = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMLibrary;
	Sbecore::ubigint x1RefWznmMMachine;
	std::string Pkglist;

public:
	bool operator==(const WznmAMLibraryPkglist& comp);
	bool operator!=(const WznmAMLibraryPkglist& comp);
};

/**
	* ListWznmAMLibraryPkglist: recordset of TblWznmAMLibraryPkglist
	*/
class ListWznmAMLibraryPkglist {

public:
	ListWznmAMLibraryPkglist();
	ListWznmAMLibraryPkglist(const ListWznmAMLibraryPkglist& src);
	~ListWznmAMLibraryPkglist();

	void clear();
	unsigned int size() const;
	void append(WznmAMLibraryPkglist* rec);

	WznmAMLibraryPkglist* operator[](const Sbecore::uint ix);
	ListWznmAMLibraryPkglist& operator=(const ListWznmAMLibraryPkglist& src);
	bool operator==(const ListWznmAMLibraryPkglist& comp);
	bool operator!=(const ListWznmAMLibraryPkglist& comp);

public:
	std::vector<WznmAMLibraryPkglist*> nodes;
};

/**
	* TblWznmAMLibraryPkglist: C++ wrapper for table TblWznmAMLibraryPkglist
	*/
class TblWznmAMLibraryPkglist {

public:

public:
	TblWznmAMLibraryPkglist();
	virtual ~TblWznmAMLibraryPkglist();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMLibraryPkglist** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMLibraryPkglist& rst);

	virtual Sbecore::ubigint insertRec(WznmAMLibraryPkglist* rec);
	Sbecore::ubigint insertNewRec(WznmAMLibraryPkglist** rec = NULL, const Sbecore::ubigint refWznmMLibrary = 0, const Sbecore::ubigint x1RefWznmMMachine = 0, const std::string Pkglist = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMLibraryPkglist& rst, WznmAMLibraryPkglist** rec = NULL, const Sbecore::ubigint refWznmMLibrary = 0, const Sbecore::ubigint x1RefWznmMMachine = 0, const std::string Pkglist = "");
	virtual void insertRst(ListWznmAMLibraryPkglist& rst, bool transact = false);
	virtual void updateRec(WznmAMLibraryPkglist* rec);
	virtual void updateRst(ListWznmAMLibraryPkglist& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMLibraryPkglist** rec);
	virtual bool loadPklByLibMch(Sbecore::ubigint refWznmMLibrary, Sbecore::ubigint x1RefWznmMMachine, std::string& Pkglist);
	virtual Sbecore::ubigint loadRefsByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByLib(Sbecore::ubigint refWznmMLibrary, const bool append, ListWznmAMLibraryPkglist& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMLibraryPkglist& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMLibraryPkglist: C++ wrapper for table TblWznmAMLibraryPkglist (MySQL database)
	*/
class MyTblWznmAMLibraryPkglist : public TblWznmAMLibraryPkglist, public Sbecore::MyTable {

public:
	MyTblWznmAMLibraryPkglist();
	~MyTblWznmAMLibraryPkglist();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMLibraryPkglist** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMLibraryPkglist& rst);

	Sbecore::ubigint insertRec(WznmAMLibraryPkglist* rec);
	void insertRst(ListWznmAMLibraryPkglist& rst, bool transact = false);
	void updateRec(WznmAMLibraryPkglist* rec);
	void updateRst(ListWznmAMLibraryPkglist& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMLibraryPkglist** rec);
	bool loadPklByLibMch(Sbecore::ubigint refWznmMLibrary, Sbecore::ubigint x1RefWznmMMachine, std::string& Pkglist);
	Sbecore::ubigint loadRefsByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLib(Sbecore::ubigint refWznmMLibrary, const bool append, ListWznmAMLibraryPkglist& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMLibraryPkglist: C++ wrapper for table TblWznmAMLibraryPkglist (PgSQL database)
	*/
class PgTblWznmAMLibraryPkglist : public TblWznmAMLibraryPkglist, public Sbecore::PgTable {

public:
	PgTblWznmAMLibraryPkglist();
	~PgTblWznmAMLibraryPkglist();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMLibraryPkglist** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMLibraryPkglist& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMLibraryPkglist** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMLibraryPkglist& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMLibraryPkglist** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMLibraryPkglist& rst);

	Sbecore::ubigint insertRec(WznmAMLibraryPkglist* rec);
	void insertRst(ListWznmAMLibraryPkglist& rst, bool transact = false);
	void updateRec(WznmAMLibraryPkglist* rec);
	void updateRst(ListWznmAMLibraryPkglist& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMLibraryPkglist** rec);
	bool loadPklByLibMch(Sbecore::ubigint refWznmMLibrary, Sbecore::ubigint x1RefWznmMMachine, std::string& Pkglist);
	Sbecore::ubigint loadRefsByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLib(Sbecore::ubigint refWznmMLibrary, const bool append, ListWznmAMLibraryPkglist& rst);
};
#endif

#endif

