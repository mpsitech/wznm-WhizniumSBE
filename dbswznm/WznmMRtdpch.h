/**
	* \file WznmMRtdpch.h
	* database access for table TblWznmMRtdpch (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMRTDPCH_H
#define WZNMMRTDPCH_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMRtdpch: record of TblWznmMRtdpch
	*/
class WznmMRtdpch {

public:
	WznmMRtdpch(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMBlock = 0, const std::string sref = "", const bool Merge = false);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMRtjob;
	Sbecore::ubigint refWznmMBlock;
	std::string sref;
	bool Merge;

public:
	bool operator==(const WznmMRtdpch& comp);
	bool operator!=(const WznmMRtdpch& comp);
};

/**
	* ListWznmMRtdpch: recordset of TblWznmMRtdpch
	*/
class ListWznmMRtdpch {

public:
	ListWznmMRtdpch();
	ListWznmMRtdpch(const ListWznmMRtdpch& src);
	~ListWznmMRtdpch();

	void clear();
	unsigned int size() const;
	void append(WznmMRtdpch* rec);

	WznmMRtdpch* operator[](const Sbecore::uint ix);
	ListWznmMRtdpch& operator=(const ListWznmMRtdpch& src);
	bool operator==(const ListWznmMRtdpch& comp);
	bool operator!=(const ListWznmMRtdpch& comp);

public:
	std::vector<WznmMRtdpch*> nodes;
};

/**
	* TblWznmMRtdpch: C++ wrapper for table TblWznmMRtdpch
	*/
class TblWznmMRtdpch {

public:

public:
	TblWznmMRtdpch();
	virtual ~TblWznmMRtdpch();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMRtdpch** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRtdpch& rst);

	virtual Sbecore::ubigint insertRec(WznmMRtdpch* rec);
	Sbecore::ubigint insertNewRec(WznmMRtdpch** rec = NULL, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMBlock = 0, const std::string sref = "", const bool Merge = false);
	Sbecore::ubigint appendNewRecToRst(ListWznmMRtdpch& rst, WznmMRtdpch** rec = NULL, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMBlock = 0, const std::string sref = "", const bool Merge = false);
	virtual void insertRst(ListWznmMRtdpch& rst, bool transact = false);
	virtual void updateRec(WznmMRtdpch* rec);
	virtual void updateRst(ListWznmMRtdpch& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMRtdpch** rec);
	virtual Sbecore::ubigint loadRefsByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, ListWznmMRtdpch& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMRtdpch& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMRtdpch: C++ wrapper for table TblWznmMRtdpch (MySQL database)
	*/
class MyTblWznmMRtdpch : public TblWznmMRtdpch, public Sbecore::MyTable {

public:
	MyTblWznmMRtdpch();
	~MyTblWznmMRtdpch();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRtdpch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRtdpch& rst);

	Sbecore::ubigint insertRec(WznmMRtdpch* rec);
	void insertRst(ListWznmMRtdpch& rst, bool transact = false);
	void updateRec(WznmMRtdpch* rec);
	void updateRst(ListWznmMRtdpch& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRtdpch** rec);
	Sbecore::ubigint loadRefsByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, ListWznmMRtdpch& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMRtdpch: C++ wrapper for table TblWznmMRtdpch (PgSQL database)
	*/
class PgTblWznmMRtdpch : public TblWznmMRtdpch, public Sbecore::PgTable {

public:
	PgTblWznmMRtdpch();
	~PgTblWznmMRtdpch();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMRtdpch** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMRtdpch& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMRtdpch** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMRtdpch& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRtdpch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRtdpch& rst);

	Sbecore::ubigint insertRec(WznmMRtdpch* rec);
	void insertRst(ListWznmMRtdpch& rst, bool transact = false);
	void updateRec(WznmMRtdpch* rec);
	void updateRst(ListWznmMRtdpch& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRtdpch** rec);
	Sbecore::ubigint loadRefsByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, ListWznmMRtdpch& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

