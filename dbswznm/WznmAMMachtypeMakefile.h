/**
	* \file WznmAMMachtypeMakefile.h
	* database access for table TblWznmAMMachtypeMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMAMMACHTYPEMAKEFILE_H
#define WZNMAMMACHTYPEMAKEFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMMachtypeMakefile: record of TblWznmAMMachtypeMakefile
	*/
class WznmAMMachtypeMakefile {

public:
	WznmAMMachtypeMakefile(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMMachtype = 0, const std::string x1SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMMachtype;
	std::string x1SrefKTag;
	std::string Val;

public:
	bool operator==(const WznmAMMachtypeMakefile& comp);
	bool operator!=(const WznmAMMachtypeMakefile& comp);
};

/**
	* ListWznmAMMachtypeMakefile: recordset of TblWznmAMMachtypeMakefile
	*/
class ListWznmAMMachtypeMakefile {

public:
	ListWznmAMMachtypeMakefile();
	ListWznmAMMachtypeMakefile(const ListWznmAMMachtypeMakefile& src);
	~ListWznmAMMachtypeMakefile();

	void clear();
	unsigned int size() const;
	void append(WznmAMMachtypeMakefile* rec);

	WznmAMMachtypeMakefile* operator[](const Sbecore::uint ix);
	ListWznmAMMachtypeMakefile& operator=(const ListWznmAMMachtypeMakefile& src);
	bool operator==(const ListWznmAMMachtypeMakefile& comp);
	bool operator!=(const ListWznmAMMachtypeMakefile& comp);

public:
	std::vector<WznmAMMachtypeMakefile*> nodes;
};

/**
	* TblWznmAMMachtypeMakefile: C++ wrapper for table TblWznmAMMachtypeMakefile
	*/
class TblWznmAMMachtypeMakefile {

public:

public:
	TblWznmAMMachtypeMakefile();
	virtual ~TblWznmAMMachtypeMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMMachtypeMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMachtypeMakefile& rst);

	virtual Sbecore::ubigint insertRec(WznmAMMachtypeMakefile* rec);
	Sbecore::ubigint insertNewRec(WznmAMMachtypeMakefile** rec = NULL, const Sbecore::ubigint refWznmMMachtype = 0, const std::string x1SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMMachtypeMakefile& rst, WznmAMMachtypeMakefile** rec = NULL, const Sbecore::ubigint refWznmMMachtype = 0, const std::string x1SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWznmAMMachtypeMakefile& rst, bool transact = false);
	virtual void updateRec(WznmAMMachtypeMakefile* rec);
	virtual void updateRst(ListWznmAMMachtypeMakefile& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMMachtypeMakefile** rec);
	virtual Sbecore::ubigint loadRefsByMty(Sbecore::ubigint refWznmMMachtype, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMty(Sbecore::ubigint refWznmMMachtype, const bool append, ListWznmAMMachtypeMakefile& rst);
	virtual bool loadValByMtyTag(Sbecore::ubigint refWznmMMachtype, std::string x1SrefKTag, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMMachtypeMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMMachtypeMakefile: C++ wrapper for table TblWznmAMMachtypeMakefile (MySQL database)
	*/
class MyTblWznmAMMachtypeMakefile : public TblWznmAMMachtypeMakefile, public Sbecore::MyTable {

public:
	MyTblWznmAMMachtypeMakefile();
	~MyTblWznmAMMachtypeMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMachtypeMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMachtypeMakefile& rst);

	Sbecore::ubigint insertRec(WznmAMMachtypeMakefile* rec);
	void insertRst(ListWznmAMMachtypeMakefile& rst, bool transact = false);
	void updateRec(WznmAMMachtypeMakefile* rec);
	void updateRst(ListWznmAMMachtypeMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMachtypeMakefile** rec);
	Sbecore::ubigint loadRefsByMty(Sbecore::ubigint refWznmMMachtype, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMty(Sbecore::ubigint refWznmMMachtype, const bool append, ListWznmAMMachtypeMakefile& rst);
	bool loadValByMtyTag(Sbecore::ubigint refWznmMMachtype, std::string x1SrefKTag, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMMachtypeMakefile: C++ wrapper for table TblWznmAMMachtypeMakefile (PgSQL database)
	*/
class PgTblWznmAMMachtypeMakefile : public TblWznmAMMachtypeMakefile, public Sbecore::PgTable {

public:
	PgTblWznmAMMachtypeMakefile();
	~PgTblWznmAMMachtypeMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMMachtypeMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMMachtypeMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMMachtypeMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMMachtypeMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMachtypeMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMachtypeMakefile& rst);

	Sbecore::ubigint insertRec(WznmAMMachtypeMakefile* rec);
	void insertRst(ListWznmAMMachtypeMakefile& rst, bool transact = false);
	void updateRec(WznmAMMachtypeMakefile* rec);
	void updateRst(ListWznmAMMachtypeMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMachtypeMakefile** rec);
	Sbecore::ubigint loadRefsByMty(Sbecore::ubigint refWznmMMachtype, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMty(Sbecore::ubigint refWznmMMachtype, const bool append, ListWznmAMMachtypeMakefile& rst);
	bool loadValByMtyTag(Sbecore::ubigint refWznmMMachtype, std::string x1SrefKTag, std::string& Val);
};
#endif

#endif

