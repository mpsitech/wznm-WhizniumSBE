/**
	* \file WznmRMComponentMOppack.h
	* database access for table TblWznmRMComponentMOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMCOMPONENTMOPPACK_H
#define WZNMRMCOMPONENTMOPPACK_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMComponentMOppack: record of TblWznmRMComponentMOppack
	*/
class WznmRMComponentMOppack {

public:
	WznmRMComponentMOppack(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMOppack = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMComponent;
	Sbecore::ubigint refWznmMOppack;

public:
	bool operator==(const WznmRMComponentMOppack& comp);
	bool operator!=(const WznmRMComponentMOppack& comp);
};

/**
	* ListWznmRMComponentMOppack: recordset of TblWznmRMComponentMOppack
	*/
class ListWznmRMComponentMOppack {

public:
	ListWznmRMComponentMOppack();
	ListWznmRMComponentMOppack(const ListWznmRMComponentMOppack& src);
	~ListWznmRMComponentMOppack();

	void clear();
	unsigned int size() const;
	void append(WznmRMComponentMOppack* rec);

	WznmRMComponentMOppack* operator[](const Sbecore::uint ix);
	ListWznmRMComponentMOppack& operator=(const ListWznmRMComponentMOppack& src);
	bool operator==(const ListWznmRMComponentMOppack& comp);
	bool operator!=(const ListWznmRMComponentMOppack& comp);

public:
	std::vector<WznmRMComponentMOppack*> nodes;
};

/**
	* TblWznmRMComponentMOppack: C++ wrapper for table TblWznmRMComponentMOppack
	*/
class TblWznmRMComponentMOppack {

public:

public:
	TblWznmRMComponentMOppack();
	virtual ~TblWznmRMComponentMOppack();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMComponentMOppack** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMComponentMOppack& rst);

	virtual Sbecore::ubigint insertRec(WznmRMComponentMOppack* rec);
	Sbecore::ubigint insertNewRec(WznmRMComponentMOppack** rec = NULL, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMOppack = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMComponentMOppack& rst, WznmRMComponentMOppack** rec = NULL, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMOppack = 0);
	virtual void insertRst(ListWznmRMComponentMOppack& rst, bool transact = false);
	virtual void updateRec(WznmRMComponentMOppack* rec);
	virtual void updateRst(ListWznmRMComponentMOppack& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMComponentMOppack** rec);
	virtual Sbecore::ubigint loadCmpsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refWznmMComponents);
	virtual Sbecore::ubigint loadOpksByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refWznmMOppacks);
	virtual Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMComponentMOppack& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMComponentMOppack: C++ wrapper for table TblWznmRMComponentMOppack (MySQL database)
	*/
class MyTblWznmRMComponentMOppack : public TblWznmRMComponentMOppack, public Sbecore::MyTable {

public:
	MyTblWznmRMComponentMOppack();
	~MyTblWznmRMComponentMOppack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMComponentMOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMComponentMOppack& rst);

	Sbecore::ubigint insertRec(WznmRMComponentMOppack* rec);
	void insertRst(ListWznmRMComponentMOppack& rst, bool transact = false);
	void updateRec(WznmRMComponentMOppack* rec);
	void updateRst(ListWznmRMComponentMOppack& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMComponentMOppack** rec);
	Sbecore::ubigint loadCmpsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refWznmMComponents);
	Sbecore::ubigint loadOpksByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refWznmMOppacks);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMComponentMOppack: C++ wrapper for table TblWznmRMComponentMOppack (PgSQL database)
	*/
class PgTblWznmRMComponentMOppack : public TblWznmRMComponentMOppack, public Sbecore::PgTable {

public:
	PgTblWznmRMComponentMOppack();
	~PgTblWznmRMComponentMOppack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMComponentMOppack** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMComponentMOppack& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMComponentMOppack** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMComponentMOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMComponentMOppack& rst);

	Sbecore::ubigint insertRec(WznmRMComponentMOppack* rec);
	void insertRst(ListWznmRMComponentMOppack& rst, bool transact = false);
	void updateRec(WznmRMComponentMOppack* rec);
	void updateRst(ListWznmRMComponentMOppack& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMComponentMOppack** rec);
	Sbecore::ubigint loadCmpsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refWznmMComponents);
	Sbecore::ubigint loadOpksByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refWznmMOppacks);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif
