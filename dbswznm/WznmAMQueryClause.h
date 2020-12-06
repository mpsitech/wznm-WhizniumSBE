/**
	* \file WznmAMQueryClause.h
	* database access for table TblWznmAMQueryClause (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMQUERYCLAUSE_H
#define WZNMAMQUERYCLAUSE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMQueryClauseBasetype TblWznmAMQueryClause::VecVBasetype

/**
	* WznmAMQueryClause: record of TblWznmAMQueryClause
	*/
class WznmAMQueryClause {

public:
	WznmAMQueryClause(const Sbecore::ubigint ref = 0, const Sbecore::ubigint qryRefWznmMQuery = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint x1RefWznmMQuerymod = 0, const Sbecore::uint ixVBasetype = 0, const std::string Clause = "", const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::ubigint refWznmMVectoritem = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint qryRefWznmMQuery;
	Sbecore::uint qryNum;
	Sbecore::ubigint x1RefWznmMQuerymod;
	Sbecore::uint ixVBasetype;
	std::string Clause;
	Sbecore::ubigint refWznmMPreset;
	Sbecore::ubigint refWznmMVector;
	Sbecore::ubigint refWznmMVectoritem;

public:
	bool operator==(const WznmAMQueryClause& comp);
	bool operator!=(const WznmAMQueryClause& comp);
};

/**
	* ListWznmAMQueryClause: recordset of TblWznmAMQueryClause
	*/
class ListWznmAMQueryClause {

public:
	ListWznmAMQueryClause();
	ListWznmAMQueryClause(const ListWznmAMQueryClause& src);
	~ListWznmAMQueryClause();

	void clear();
	unsigned int size() const;
	void append(WznmAMQueryClause* rec);

	WznmAMQueryClause* operator[](const Sbecore::uint ix);
	ListWznmAMQueryClause& operator=(const ListWznmAMQueryClause& src);
	bool operator==(const ListWznmAMQueryClause& comp);
	bool operator!=(const ListWznmAMQueryClause& comp);

public:
	std::vector<WznmAMQueryClause*> nodes;
};

/**
	* TblWznmAMQueryClause: C++ wrapper for table TblWznmAMQueryClause
	*/
class TblWznmAMQueryClause {

public:
	/**
		* VecVBasetype (full: VecWznmVAMQueryClauseBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint IX = 1;
		static const Sbecore::uint REF = 2;
		static const Sbecore::uint EQN = 3;
		static const Sbecore::uint PRE = 4;
		static const Sbecore::uint VIT = 5;
		static const Sbecore::uint JREF = 6;
		static const Sbecore::uint LCL = 7;
		static const Sbecore::uint LAT = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMQueryClause();
	virtual ~TblWznmAMQueryClause();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMQueryClause** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMQueryClause& rst);

	virtual Sbecore::ubigint insertRec(WznmAMQueryClause* rec);
	Sbecore::ubigint insertNewRec(WznmAMQueryClause** rec = NULL, const Sbecore::ubigint qryRefWznmMQuery = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint x1RefWznmMQuerymod = 0, const Sbecore::uint ixVBasetype = 0, const std::string Clause = "", const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::ubigint refWznmMVectoritem = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmAMQueryClause& rst, WznmAMQueryClause** rec = NULL, const Sbecore::ubigint qryRefWznmMQuery = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint x1RefWznmMQuerymod = 0, const Sbecore::uint ixVBasetype = 0, const std::string Clause = "", const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::ubigint refWznmMVectoritem = 0);
	virtual void insertRst(ListWznmAMQueryClause& rst, bool transact = false);
	virtual void updateRec(WznmAMQueryClause* rec);
	virtual void updateRst(ListWznmAMQueryClause& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMQueryClause** rec);
	virtual Sbecore::ubigint loadRefsByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, ListWznmAMQueryClause& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMQueryClause& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMQueryClause: C++ wrapper for table TblWznmAMQueryClause (MySQL database)
	*/
class MyTblWznmAMQueryClause : public TblWznmAMQueryClause, public Sbecore::MyTable {

public:
	MyTblWznmAMQueryClause();
	~MyTblWznmAMQueryClause();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMQueryClause** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMQueryClause& rst);

	Sbecore::ubigint insertRec(WznmAMQueryClause* rec);
	void insertRst(ListWznmAMQueryClause& rst, bool transact = false);
	void updateRec(WznmAMQueryClause* rec);
	void updateRst(ListWznmAMQueryClause& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMQueryClause** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, ListWznmAMQueryClause& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMQueryClause: C++ wrapper for table TblWznmAMQueryClause (PgSQL database)
	*/
class PgTblWznmAMQueryClause : public TblWznmAMQueryClause, public Sbecore::PgTable {

public:
	PgTblWznmAMQueryClause();
	~PgTblWznmAMQueryClause();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMQueryClause** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMQueryClause& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMQueryClause** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMQueryClause& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMQueryClause** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMQueryClause& rst);

	Sbecore::ubigint insertRec(WznmAMQueryClause* rec);
	void insertRst(ListWznmAMQueryClause& rst, bool transact = false);
	void updateRec(WznmAMQueryClause* rec);
	void updateRst(ListWznmAMQueryClause& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMQueryClause** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, ListWznmAMQueryClause& rst);
};
#endif

#endif
