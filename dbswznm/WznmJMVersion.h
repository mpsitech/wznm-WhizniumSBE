/**
	* \file WznmJMVersion.h
	* database access for table TblWznmJMVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMJMVERSION_H
#define WZNMJMVERSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMVersion: record of TblWznmJMVersion
	*/
class WznmJMVersion {

public:
	WznmJMVersion(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string About1 = "", const std::string About2 = "", const std::string About3 = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string About1;
	std::string About2;
	std::string About3;

public:
	bool operator==(const WznmJMVersion& comp);
	bool operator!=(const WznmJMVersion& comp);
};

/**
	* ListWznmJMVersion: recordset of TblWznmJMVersion
	*/
class ListWznmJMVersion {

public:
	ListWznmJMVersion();
	ListWznmJMVersion(const ListWznmJMVersion& src);
	~ListWznmJMVersion();

	void clear();
	unsigned int size() const;
	void append(WznmJMVersion* rec);

	WznmJMVersion* operator[](const Sbecore::uint ix);
	ListWznmJMVersion& operator=(const ListWznmJMVersion& src);
	bool operator==(const ListWznmJMVersion& comp);
	bool operator!=(const ListWznmJMVersion& comp);

public:
	std::vector<WznmJMVersion*> nodes;
};

/**
	* TblWznmJMVersion: C++ wrapper for table TblWznmJMVersion
	*/
class TblWznmJMVersion {

public:

public:
	TblWznmJMVersion();
	virtual ~TblWznmJMVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMVersion& rst);

	virtual Sbecore::ubigint insertRec(WznmJMVersion* rec);
	Sbecore::ubigint insertNewRec(WznmJMVersion** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string About1 = "", const std::string About2 = "", const std::string About3 = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMVersion& rst, WznmJMVersion** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string About1 = "", const std::string About2 = "", const std::string About3 = "");
	virtual void insertRst(ListWznmJMVersion& rst, bool transact = false);
	virtual void updateRec(WznmJMVersion* rec);
	virtual void updateRst(ListWznmJMVersion& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMVersion** rec);
	virtual bool loadRecByVerLoc(Sbecore::ubigint refWznmMVersion, Sbecore::ubigint x1RefWznmMLocale, WznmJMVersion** rec);
	virtual Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmJMVersion& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMVersion: C++ wrapper for table TblWznmJMVersion (MySQL database)
	*/
class MyTblWznmJMVersion : public TblWznmJMVersion, public Sbecore::MyTable {

public:
	MyTblWznmJMVersion();
	~MyTblWznmJMVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMVersion& rst);

	Sbecore::ubigint insertRec(WznmJMVersion* rec);
	void insertRst(ListWznmJMVersion& rst, bool transact = false);
	void updateRec(WznmJMVersion* rec);
	void updateRst(ListWznmJMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMVersion** rec);
	bool loadRecByVerLoc(Sbecore::ubigint refWznmMVersion, Sbecore::ubigint x1RefWznmMLocale, WznmJMVersion** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmJMVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMVersion: C++ wrapper for table TblWznmJMVersion (PgSQL database)
	*/
class PgTblWznmJMVersion : public TblWznmJMVersion, public Sbecore::PgTable {

public:
	PgTblWznmJMVersion();
	~PgTblWznmJMVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMVersion& rst);

	Sbecore::ubigint insertRec(WznmJMVersion* rec);
	void insertRst(ListWznmJMVersion& rst, bool transact = false);
	void updateRec(WznmJMVersion* rec);
	void updateRst(ListWznmJMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMVersion** rec);
	bool loadRecByVerLoc(Sbecore::ubigint refWznmMVersion, Sbecore::ubigint x1RefWznmMLocale, WznmJMVersion** rec);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmJMVersion& rst);
};
#endif

#endif
