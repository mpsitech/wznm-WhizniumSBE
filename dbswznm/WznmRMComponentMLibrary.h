/**
	* \file WznmRMComponentMLibrary.h
	* database access for table TblWznmRMComponentMLibrary (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMRMCOMPONENTMLIBRARY_H
#define WZNMRMCOMPONENTMLIBRARY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMComponentMLibrary: record of TblWznmRMComponentMLibrary
	*/
class WznmRMComponentMLibrary {

public:
	WznmRMComponentMLibrary(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMLibrary = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMComponent;
	Sbecore::ubigint refWznmMLibrary;

public:
	bool operator==(const WznmRMComponentMLibrary& comp);
	bool operator!=(const WznmRMComponentMLibrary& comp);
};

/**
	* ListWznmRMComponentMLibrary: recordset of TblWznmRMComponentMLibrary
	*/
class ListWznmRMComponentMLibrary {

public:
	ListWznmRMComponentMLibrary();
	ListWznmRMComponentMLibrary(const ListWznmRMComponentMLibrary& src);
	~ListWznmRMComponentMLibrary();

	void clear();
	unsigned int size() const;
	void append(WznmRMComponentMLibrary* rec);

	WznmRMComponentMLibrary* operator[](const Sbecore::uint ix);
	ListWznmRMComponentMLibrary& operator=(const ListWznmRMComponentMLibrary& src);
	bool operator==(const ListWznmRMComponentMLibrary& comp);
	bool operator!=(const ListWznmRMComponentMLibrary& comp);

public:
	std::vector<WznmRMComponentMLibrary*> nodes;
};

/**
	* TblWznmRMComponentMLibrary: C++ wrapper for table TblWznmRMComponentMLibrary
	*/
class TblWznmRMComponentMLibrary {

public:

public:
	TblWznmRMComponentMLibrary();
	virtual ~TblWznmRMComponentMLibrary();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMComponentMLibrary** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMComponentMLibrary& rst);

	virtual Sbecore::ubigint insertRec(WznmRMComponentMLibrary* rec);
	Sbecore::ubigint insertNewRec(WznmRMComponentMLibrary** rec = NULL, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMLibrary = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMComponentMLibrary& rst, WznmRMComponentMLibrary** rec = NULL, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMLibrary = 0);
	virtual void insertRst(ListWznmRMComponentMLibrary& rst, bool transact = false);
	virtual void updateRec(WznmRMComponentMLibrary* rec);
	virtual void updateRst(ListWznmRMComponentMLibrary& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMComponentMLibrary** rec);
	virtual Sbecore::ubigint loadCmpsByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWznmMComponents);
	virtual Sbecore::ubigint loadLibsByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refWznmMLibrarys);
	virtual Sbecore::ubigint loadRefsByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMComponentMLibrary& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMComponentMLibrary: C++ wrapper for table TblWznmRMComponentMLibrary (MySQL database)
	*/
class MyTblWznmRMComponentMLibrary : public TblWznmRMComponentMLibrary, public Sbecore::MyTable {

public:
	MyTblWznmRMComponentMLibrary();
	~MyTblWznmRMComponentMLibrary();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMComponentMLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMComponentMLibrary& rst);

	Sbecore::ubigint insertRec(WznmRMComponentMLibrary* rec);
	void insertRst(ListWznmRMComponentMLibrary& rst, bool transact = false);
	void updateRec(WznmRMComponentMLibrary* rec);
	void updateRst(ListWznmRMComponentMLibrary& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMComponentMLibrary** rec);
	Sbecore::ubigint loadCmpsByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWznmMComponents);
	Sbecore::ubigint loadLibsByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refWznmMLibrarys);
	Sbecore::ubigint loadRefsByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMComponentMLibrary: C++ wrapper for table TblWznmRMComponentMLibrary (PgSQL database)
	*/
class PgTblWznmRMComponentMLibrary : public TblWznmRMComponentMLibrary, public Sbecore::PgTable {

public:
	PgTblWznmRMComponentMLibrary();
	~PgTblWznmRMComponentMLibrary();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMComponentMLibrary** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMComponentMLibrary& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMComponentMLibrary** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMComponentMLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMComponentMLibrary& rst);

	Sbecore::ubigint insertRec(WznmRMComponentMLibrary* rec);
	void insertRst(ListWznmRMComponentMLibrary& rst, bool transact = false);
	void updateRec(WznmRMComponentMLibrary* rec);
	void updateRst(ListWznmRMComponentMLibrary& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMComponentMLibrary** rec);
	Sbecore::ubigint loadCmpsByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refWznmMComponents);
	Sbecore::ubigint loadLibsByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refWznmMLibrarys);
	Sbecore::ubigint loadRefsByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif

