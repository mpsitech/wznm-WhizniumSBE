/**
	* \file WznmRMLibraryMOppack.h
	* database access for table TblWznmRMLibraryMOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMLIBRARYMOPPACK_H
#define WZNMRMLIBRARYMOPPACK_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMLibraryMOppack: record of TblWznmRMLibraryMOppack
	*/
class WznmRMLibraryMOppack {

public:
	WznmRMLibraryMOppack(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMLibrary = 0, const Sbecore::ubigint refWznmMOppack = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMLibrary;
	Sbecore::ubigint refWznmMOppack;

public:
	bool operator==(const WznmRMLibraryMOppack& comp);
	bool operator!=(const WznmRMLibraryMOppack& comp);
};

/**
	* ListWznmRMLibraryMOppack: recordset of TblWznmRMLibraryMOppack
	*/
class ListWznmRMLibraryMOppack {

public:
	ListWznmRMLibraryMOppack();
	ListWznmRMLibraryMOppack(const ListWznmRMLibraryMOppack& src);
	~ListWznmRMLibraryMOppack();

	void clear();
	unsigned int size() const;
	void append(WznmRMLibraryMOppack* rec);

	WznmRMLibraryMOppack* operator[](const Sbecore::uint ix);
	ListWznmRMLibraryMOppack& operator=(const ListWznmRMLibraryMOppack& src);
	bool operator==(const ListWznmRMLibraryMOppack& comp);
	bool operator!=(const ListWznmRMLibraryMOppack& comp);

public:
	std::vector<WznmRMLibraryMOppack*> nodes;
};

/**
	* TblWznmRMLibraryMOppack: C++ wrapper for table TblWznmRMLibraryMOppack
	*/
class TblWznmRMLibraryMOppack {

public:

public:
	TblWznmRMLibraryMOppack();
	virtual ~TblWznmRMLibraryMOppack();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMLibraryMOppack** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMLibraryMOppack& rst);

	virtual Sbecore::ubigint insertRec(WznmRMLibraryMOppack* rec);
	Sbecore::ubigint insertNewRec(WznmRMLibraryMOppack** rec = NULL, const Sbecore::ubigint refWznmMLibrary = 0, const Sbecore::ubigint refWznmMOppack = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMLibraryMOppack& rst, WznmRMLibraryMOppack** rec = NULL, const Sbecore::ubigint refWznmMLibrary = 0, const Sbecore::ubigint refWznmMOppack = 0);
	virtual void insertRst(ListWznmRMLibraryMOppack& rst, bool transact = false);
	virtual void updateRec(WznmRMLibraryMOppack* rec);
	virtual void updateRst(ListWznmRMLibraryMOppack& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMLibraryMOppack** rec);
	virtual Sbecore::ubigint loadLibsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refWznmMLibrarys);
	virtual Sbecore::ubigint loadOpksByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWznmMOppacks);
	virtual Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMLibraryMOppack& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMLibraryMOppack: C++ wrapper for table TblWznmRMLibraryMOppack (MySQL database)
	*/
class MyTblWznmRMLibraryMOppack : public TblWznmRMLibraryMOppack, public Sbecore::MyTable {

public:
	MyTblWznmRMLibraryMOppack();
	~MyTblWznmRMLibraryMOppack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMLibraryMOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMLibraryMOppack& rst);

	Sbecore::ubigint insertRec(WznmRMLibraryMOppack* rec);
	void insertRst(ListWznmRMLibraryMOppack& rst, bool transact = false);
	void updateRec(WznmRMLibraryMOppack* rec);
	void updateRst(ListWznmRMLibraryMOppack& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMLibraryMOppack** rec);
	Sbecore::ubigint loadLibsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refWznmMLibrarys);
	Sbecore::ubigint loadOpksByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWznmMOppacks);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMLibraryMOppack: C++ wrapper for table TblWznmRMLibraryMOppack (PgSQL database)
	*/
class PgTblWznmRMLibraryMOppack : public TblWznmRMLibraryMOppack, public Sbecore::PgTable {

public:
	PgTblWznmRMLibraryMOppack();
	~PgTblWznmRMLibraryMOppack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMLibraryMOppack** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMLibraryMOppack& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMLibraryMOppack** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMLibraryMOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMLibraryMOppack& rst);

	Sbecore::ubigint insertRec(WznmRMLibraryMOppack* rec);
	void insertRst(ListWznmRMLibraryMOppack& rst, bool transact = false);
	void updateRec(WznmRMLibraryMOppack* rec);
	void updateRst(ListWznmRMLibraryMOppack& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMLibraryMOppack** rec);
	Sbecore::ubigint loadLibsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refWznmMLibrarys);
	Sbecore::ubigint loadOpksByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWznmMOppacks);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif

