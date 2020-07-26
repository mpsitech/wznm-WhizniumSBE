/**
	* \file WznmAMOpInvarg.h
	* database access for table TblWznmAMOpInvarg (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMAMOPINVARG_H
#define WZNMAMOPINVARG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMOpInvarg: record of TblWznmAMOpInvarg
	*/
class WznmAMOpInvarg {

public:
	WznmAMOpInvarg(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmCAMOpInvarg = 0, const Sbecore::ubigint opxRefWznmMOp = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmCAMOpInvarg;
	Sbecore::ubigint opxRefWznmMOp;
	Sbecore::uint opxNum;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	Sbecore::ubigint refWznmMVector;
	std::string Defval;
	Sbecore::ubigint refWznmMVectoritem;
	std::string Comment;

public:
	bool operator==(const WznmAMOpInvarg& comp);
	bool operator!=(const WznmAMOpInvarg& comp);
};

/**
	* ListWznmAMOpInvarg: recordset of TblWznmAMOpInvarg
	*/
class ListWznmAMOpInvarg {

public:
	ListWznmAMOpInvarg();
	ListWznmAMOpInvarg(const ListWznmAMOpInvarg& src);
	~ListWznmAMOpInvarg();

	void clear();
	unsigned int size() const;
	void append(WznmAMOpInvarg* rec);

	WznmAMOpInvarg* operator[](const Sbecore::uint ix);
	ListWznmAMOpInvarg& operator=(const ListWznmAMOpInvarg& src);
	bool operator==(const ListWznmAMOpInvarg& comp);
	bool operator!=(const ListWznmAMOpInvarg& comp);

public:
	std::vector<WznmAMOpInvarg*> nodes;
};

/**
	* TblWznmAMOpInvarg: C++ wrapper for table TblWznmAMOpInvarg
	*/
class TblWznmAMOpInvarg {

public:

public:
	TblWznmAMOpInvarg();
	virtual ~TblWznmAMOpInvarg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMOpInvarg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOpInvarg& rst);

	virtual Sbecore::ubigint insertRec(WznmAMOpInvarg* rec);
	Sbecore::ubigint insertNewRec(WznmAMOpInvarg** rec = NULL, const Sbecore::ubigint refWznmCAMOpInvarg = 0, const Sbecore::ubigint opxRefWznmMOp = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMOpInvarg& rst, WznmAMOpInvarg** rec = NULL, const Sbecore::ubigint refWznmCAMOpInvarg = 0, const Sbecore::ubigint opxRefWznmMOp = 0, const Sbecore::uint opxNum = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMVector = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmAMOpInvarg& rst, bool transact = false);
	virtual void updateRec(WznmAMOpInvarg* rec);
	virtual void updateRst(ListWznmAMOpInvarg& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMOpInvarg** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOpInvarg, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOpInvarg, const bool append, ListWznmAMOpInvarg& rst);
	virtual Sbecore::ubigint loadRstByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, ListWznmAMOpInvarg& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMOpInvarg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMOpInvarg: C++ wrapper for table TblWznmAMOpInvarg (MySQL database)
	*/
class MyTblWznmAMOpInvarg : public TblWznmAMOpInvarg, public Sbecore::MyTable {

public:
	MyTblWznmAMOpInvarg();
	~MyTblWznmAMOpInvarg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMOpInvarg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOpInvarg& rst);

	Sbecore::ubigint insertRec(WznmAMOpInvarg* rec);
	void insertRst(ListWznmAMOpInvarg& rst, bool transact = false);
	void updateRec(WznmAMOpInvarg* rec);
	void updateRst(ListWznmAMOpInvarg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMOpInvarg** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOpInvarg, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOpInvarg, const bool append, ListWznmAMOpInvarg& rst);
	Sbecore::ubigint loadRstByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, ListWznmAMOpInvarg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMOpInvarg: C++ wrapper for table TblWznmAMOpInvarg (PgSQL database)
	*/
class PgTblWznmAMOpInvarg : public TblWznmAMOpInvarg, public Sbecore::PgTable {

public:
	PgTblWznmAMOpInvarg();
	~PgTblWznmAMOpInvarg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMOpInvarg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMOpInvarg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMOpInvarg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMOpInvarg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMOpInvarg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMOpInvarg& rst);

	Sbecore::ubigint insertRec(WznmAMOpInvarg* rec);
	void insertRst(ListWznmAMOpInvarg& rst, bool transact = false);
	void updateRec(WznmAMOpInvarg* rec);
	void updateRst(ListWznmAMOpInvarg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMOpInvarg** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMOpInvarg, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMOpInvarg, const bool append, ListWznmAMOpInvarg& rst);
	Sbecore::ubigint loadRstByOpx(Sbecore::ubigint opxRefWznmMOp, const bool append, ListWznmAMOpInvarg& rst);
};
#endif

#endif

