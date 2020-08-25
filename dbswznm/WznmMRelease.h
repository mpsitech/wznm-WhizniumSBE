/**
	* \file WznmMRelease.h
	* database access for table TblWznmMRelease (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMMRELEASE_H
#define WZNMMRELEASE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMRelease: record of TblWznmMRelease
	*/
class WznmMRelease {

public:
	WznmMRelease(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMMachine = 0, const std::string sref = "", const std::string srefsKOption = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMComponent;
	Sbecore::ubigint refWznmMMachine;
	std::string sref;
	std::string srefsKOption;
	std::string Comment;

public:
	bool operator==(const WznmMRelease& comp);
	bool operator!=(const WznmMRelease& comp);
};

/**
	* ListWznmMRelease: recordset of TblWznmMRelease
	*/
class ListWznmMRelease {

public:
	ListWznmMRelease();
	ListWznmMRelease(const ListWznmMRelease& src);
	~ListWznmMRelease();

	void clear();
	unsigned int size() const;
	void append(WznmMRelease* rec);

	WznmMRelease* operator[](const Sbecore::uint ix);
	ListWznmMRelease& operator=(const ListWznmMRelease& src);
	bool operator==(const ListWznmMRelease& comp);
	bool operator!=(const ListWznmMRelease& comp);

public:
	std::vector<WznmMRelease*> nodes;
};

/**
	* TblWznmMRelease: C++ wrapper for table TblWznmMRelease
	*/
class TblWznmMRelease {

public:

public:
	TblWznmMRelease();
	virtual ~TblWznmMRelease();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMRelease** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRelease& rst);

	virtual Sbecore::ubigint insertRec(WznmMRelease* rec);
	Sbecore::ubigint insertNewRec(WznmMRelease** rec = NULL, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMMachine = 0, const std::string sref = "", const std::string srefsKOption = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMRelease& rst, WznmMRelease** rec = NULL, const Sbecore::ubigint refWznmMComponent = 0, const Sbecore::ubigint refWznmMMachine = 0, const std::string sref = "", const std::string srefsKOption = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMRelease& rst, bool transact = false);
	virtual void updateRec(WznmMRelease* rec);
	virtual void updateRst(ListWznmMRelease& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMRelease** rec);
	virtual Sbecore::ubigint loadRefsByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCmp(Sbecore::ubigint refWznmMComponent, const bool append, ListWznmMRelease& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMRelease& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMRelease: C++ wrapper for table TblWznmMRelease (MySQL database)
	*/
class MyTblWznmMRelease : public TblWznmMRelease, public Sbecore::MyTable {

public:
	MyTblWznmMRelease();
	~MyTblWznmMRelease();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRelease& rst);

	Sbecore::ubigint insertRec(WznmMRelease* rec);
	void insertRst(ListWznmMRelease& rst, bool transact = false);
	void updateRec(WznmMRelease* rec);
	void updateRst(ListWznmMRelease& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRelease** rec);
	Sbecore::ubigint loadRefsByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCmp(Sbecore::ubigint refWznmMComponent, const bool append, ListWznmMRelease& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMRelease: C++ wrapper for table TblWznmMRelease (PgSQL database)
	*/
class PgTblWznmMRelease : public TblWznmMRelease, public Sbecore::PgTable {

public:
	PgTblWznmMRelease();
	~PgTblWznmMRelease();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMRelease** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMRelease& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMRelease** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMRelease& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRelease** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRelease& rst);

	Sbecore::ubigint insertRec(WznmMRelease* rec);
	void insertRst(ListWznmMRelease& rst, bool transact = false);
	void updateRec(WznmMRelease* rec);
	void updateRst(ListWznmMRelease& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRelease** rec);
	Sbecore::ubigint loadRefsByCmp(Sbecore::ubigint refWznmMComponent, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCmp(Sbecore::ubigint refWznmMComponent, const bool append, ListWznmMRelease& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

