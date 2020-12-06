/**
	* \file WznmAMMachineMakefile.h
	* database access for table TblWznmAMMachineMakefile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMMACHINEMAKEFILE_H
#define WZNMAMMACHINEMAKEFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMMachineMakefile: record of TblWznmAMMachineMakefile
	*/
class WznmAMMachineMakefile {

public:
	WznmAMMachineMakefile(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMMachine = 0, const std::string x1SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMMachine;
	std::string x1SrefKTag;
	std::string Val;

public:
	bool operator==(const WznmAMMachineMakefile& comp);
	bool operator!=(const WznmAMMachineMakefile& comp);
};

/**
	* ListWznmAMMachineMakefile: recordset of TblWznmAMMachineMakefile
	*/
class ListWznmAMMachineMakefile {

public:
	ListWznmAMMachineMakefile();
	ListWznmAMMachineMakefile(const ListWznmAMMachineMakefile& src);
	~ListWznmAMMachineMakefile();

	void clear();
	unsigned int size() const;
	void append(WznmAMMachineMakefile* rec);

	WznmAMMachineMakefile* operator[](const Sbecore::uint ix);
	ListWznmAMMachineMakefile& operator=(const ListWznmAMMachineMakefile& src);
	bool operator==(const ListWznmAMMachineMakefile& comp);
	bool operator!=(const ListWznmAMMachineMakefile& comp);

public:
	std::vector<WznmAMMachineMakefile*> nodes;
};

/**
	* TblWznmAMMachineMakefile: C++ wrapper for table TblWznmAMMachineMakefile
	*/
class TblWznmAMMachineMakefile {

public:

public:
	TblWznmAMMachineMakefile();
	virtual ~TblWznmAMMachineMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMMachineMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMachineMakefile& rst);

	virtual Sbecore::ubigint insertRec(WznmAMMachineMakefile* rec);
	Sbecore::ubigint insertNewRec(WznmAMMachineMakefile** rec = NULL, const Sbecore::ubigint refWznmMMachine = 0, const std::string x1SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMMachineMakefile& rst, WznmAMMachineMakefile** rec = NULL, const Sbecore::ubigint refWznmMMachine = 0, const std::string x1SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWznmAMMachineMakefile& rst, bool transact = false);
	virtual void updateRec(WznmAMMachineMakefile* rec);
	virtual void updateRst(ListWznmAMMachineMakefile& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMMachineMakefile** rec);
	virtual Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWznmMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWznmMMachine, const bool append, ListWznmAMMachineMakefile& rst);
	virtual bool loadValByMchTag(Sbecore::ubigint refWznmMMachine, std::string x1SrefKTag, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMMachineMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMMachineMakefile: C++ wrapper for table TblWznmAMMachineMakefile (MySQL database)
	*/
class MyTblWznmAMMachineMakefile : public TblWznmAMMachineMakefile, public Sbecore::MyTable {

public:
	MyTblWznmAMMachineMakefile();
	~MyTblWznmAMMachineMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMachineMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMachineMakefile& rst);

	Sbecore::ubigint insertRec(WznmAMMachineMakefile* rec);
	void insertRst(ListWznmAMMachineMakefile& rst, bool transact = false);
	void updateRec(WznmAMMachineMakefile* rec);
	void updateRst(ListWznmAMMachineMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMachineMakefile** rec);
	Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWznmMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWznmMMachine, const bool append, ListWznmAMMachineMakefile& rst);
	bool loadValByMchTag(Sbecore::ubigint refWznmMMachine, std::string x1SrefKTag, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMMachineMakefile: C++ wrapper for table TblWznmAMMachineMakefile (PgSQL database)
	*/
class PgTblWznmAMMachineMakefile : public TblWznmAMMachineMakefile, public Sbecore::PgTable {

public:
	PgTblWznmAMMachineMakefile();
	~PgTblWznmAMMachineMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMMachineMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMMachineMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMMachineMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMMachineMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMMachineMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMMachineMakefile& rst);

	Sbecore::ubigint insertRec(WznmAMMachineMakefile* rec);
	void insertRst(ListWznmAMMachineMakefile& rst, bool transact = false);
	void updateRec(WznmAMMachineMakefile* rec);
	void updateRst(ListWznmAMMachineMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMMachineMakefile** rec);
	Sbecore::ubigint loadRefsByMch(Sbecore::ubigint refWznmMMachine, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMch(Sbecore::ubigint refWznmMMachine, const bool append, ListWznmAMMachineMakefile& rst);
	bool loadValByMchTag(Sbecore::ubigint refWznmMMachine, std::string x1SrefKTag, std::string& Val);
};
#endif

#endif
