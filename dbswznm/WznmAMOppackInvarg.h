/**
	* \file WznmAMOppackInvarg.h
	* database access for table TblWznmAMOppackInvarg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMOPPACKINVARG_H
#define WZNMAMOPPACKINVARG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMOppackInvarg: record of TblWznmAMOppackInvarg
	*/
class WznmAMOppackInvarg {

public:
	WznmAMOppackInvarg(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmCAMOppackInvarg = 0, const Sbecore::ubigint opkRefWznmMOppack = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmCAMOppackInvarg;
	Sbecore::ubigint opkRefWznmMOppack;
	Sbecore::uint opkNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	std::string Defval;
	Sbecore::ubigint refWznmMVectoritem;
	std::string Comment;

public:
	bool operator==(const WznmAMOppackInvarg& comp);
	bool operator!=(const WznmAMOppackInvarg& comp);
};

/**
	* ListWznmAMOppackInvarg: recordset of TblWznmAMOppackInvarg
	*/
class ListWznmAMOppackInvarg {

public:
	ListWznmAMOppackInvarg();
	ListWznmAMOppackInvarg(const ListWznmAMOppackInvarg& src);
	~ListWznmAMOppackInvarg();

	void clear();
	unsigned int size() const;
	void append(WznmAMOppackInvarg* rec);

	WznmAMOppackInvarg* operator[](const Sbecore::uint ix);
	ListWznmAMOppackInvarg& operator=(const ListWznmAMOppackInvarg& src);
	bool operator==(const ListWznmAMOppackInvarg& comp);
	bool operator!=(const ListWznmAMOppackInvarg& comp);

public:
	std::vector<WznmAMOppackInvarg*> nodes;
};

/**
	* TblWznmAMOppackInvarg: C++ wrapper for table TblWznmAMOppackInvarg
	*/
class TblWznmAMOppackInvarg {

public:

public:
	TblWznmAMOppackInvarg();
	virtual ~TblWznmAMOppackInvarg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMOppackInvarg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOppackInvarg& rst);

	virtual Sbecore::ubigint insertRec(WznmAMOppackInvarg* rec);
	Sbecore::ubigint insertNewRec(WznmAMOppackInvarg** rec = NULL, const Sbecore::ubigint refWznmCAMOppackInvarg = 0, const Sbecore::ubigint opkRefWznmMOppack = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMOppackInvarg& rst, WznmAMOppackInvarg** rec = NULL, const Sbecore::ubigint refWznmCAMOppackInvarg = 0, const Sbecore::ubigint opkRefWznmMOppack = 0, const Sbecore::uint opkNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmAMOppackInvarg& rst, bool transact = false);
	virtual void updateRec(WznmAMOppackInvarg* rec);
	virtual void updateRst(ListWznmAMOppackInvarg& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMOppackInvarg** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOppackInvarg, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOppackInvarg, const bool append, ListWznmAMOppackInvarg& rst);
	virtual Sbecore::ubigint loadRstByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, ListWznmAMOppackInvarg& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMOppackInvarg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMOppackInvarg: C++ wrapper for table TblWznmAMOppackInvarg (MySQL database)
	*/
class MyTblWznmAMOppackInvarg : public TblWznmAMOppackInvarg, public Sbecore::MyTable {

public:
	MyTblWznmAMOppackInvarg();
	~MyTblWznmAMOppackInvarg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMOppackInvarg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOppackInvarg& rst);

	Sbecore::ubigint insertRec(WznmAMOppackInvarg* rec);
	void insertRst(ListWznmAMOppackInvarg& rst, bool transact = false);
	void updateRec(WznmAMOppackInvarg* rec);
	void updateRst(ListWznmAMOppackInvarg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMOppackInvarg** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOppackInvarg, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOppackInvarg, const bool append, ListWznmAMOppackInvarg& rst);
	Sbecore::ubigint loadRstByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, ListWznmAMOppackInvarg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMOppackInvarg: C++ wrapper for table TblWznmAMOppackInvarg (PgSQL database)
	*/
class PgTblWznmAMOppackInvarg : public TblWznmAMOppackInvarg, public Sbecore::PgTable {

public:
	PgTblWznmAMOppackInvarg();
	~PgTblWznmAMOppackInvarg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMOppackInvarg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMOppackInvarg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMOppackInvarg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMOppackInvarg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMOppackInvarg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOppackInvarg& rst);

	Sbecore::ubigint insertRec(WznmAMOppackInvarg* rec);
	void insertRst(ListWznmAMOppackInvarg& rst, bool transact = false);
	void updateRec(WznmAMOppackInvarg* rec);
	void updateRst(ListWznmAMOppackInvarg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMOppackInvarg** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOppackInvarg, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOppackInvarg, const bool append, ListWznmAMOppackInvarg& rst);
	Sbecore::ubigint loadRstByOpk(Sbecore::ubigint opkRefWznmMOppack, const bool append, ListWznmAMOppackInvarg& rst);
};
#endif

#endif
