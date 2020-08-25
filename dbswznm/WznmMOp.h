/**
	* \file WznmMOp.h
	* database access for table TblWznmMOp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMMOP_H
#define WZNMMOP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMOp: record of TblWznmMOp
	*/
class WznmMOp {

public:
	WznmMOp(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMOppack = 0, const Sbecore::ubigint refWznmMSquawk = 0, const std::string sref = "", const bool Shrdat = false, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMOppack;
	Sbecore::ubigint refWznmMSquawk;
	std::string sref;
	bool Shrdat;
	std::string Comment;

public:
	bool operator==(const WznmMOp& comp);
	bool operator!=(const WznmMOp& comp);
};

/**
	* ListWznmMOp: recordset of TblWznmMOp
	*/
class ListWznmMOp {

public:
	ListWznmMOp();
	ListWznmMOp(const ListWznmMOp& src);
	~ListWznmMOp();

	void clear();
	unsigned int size() const;
	void append(WznmMOp* rec);

	WznmMOp* operator[](const Sbecore::uint ix);
	ListWznmMOp& operator=(const ListWznmMOp& src);
	bool operator==(const ListWznmMOp& comp);
	bool operator!=(const ListWznmMOp& comp);

public:
	std::vector<WznmMOp*> nodes;
};

/**
	* TblWznmMOp: C++ wrapper for table TblWznmMOp
	*/
class TblWznmMOp {

public:

public:
	TblWznmMOp();
	virtual ~TblWznmMOp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMOp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMOp& rst);

	virtual Sbecore::ubigint insertRec(WznmMOp* rec);
	Sbecore::ubigint insertNewRec(WznmMOp** rec = NULL, const Sbecore::ubigint refWznmMOppack = 0, const Sbecore::ubigint refWznmMSquawk = 0, const std::string sref = "", const bool Shrdat = false, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMOp& rst, WznmMOp** rec = NULL, const Sbecore::ubigint refWznmMOppack = 0, const Sbecore::ubigint refWznmMSquawk = 0, const std::string sref = "", const bool Shrdat = false, const std::string Comment = "");
	virtual void insertRst(ListWznmMOp& rst, bool transact = false);
	virtual void updateRec(WznmMOp* rec);
	virtual void updateRst(ListWznmMOp& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMOp** rec);
	virtual bool loadRecBySqk(Sbecore::ubigint refWznmMSquawk, WznmMOp** rec);
	virtual Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByOpk(Sbecore::ubigint refWznmMOppack, const bool append, ListWznmMOp& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMOp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMOp: C++ wrapper for table TblWznmMOp (MySQL database)
	*/
class MyTblWznmMOp : public TblWznmMOp, public Sbecore::MyTable {

public:
	MyTblWznmMOp();
	~MyTblWznmMOp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMOp& rst);

	Sbecore::ubigint insertRec(WznmMOp* rec);
	void insertRst(ListWznmMOp& rst, bool transact = false);
	void updateRec(WznmMOp* rec);
	void updateRst(ListWznmMOp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMOp** rec);
	bool loadRecBySqk(Sbecore::ubigint refWznmMSquawk, WznmMOp** rec);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByOpk(Sbecore::ubigint refWznmMOppack, const bool append, ListWznmMOp& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMOp: C++ wrapper for table TblWznmMOp (PgSQL database)
	*/
class PgTblWznmMOp : public TblWznmMOp, public Sbecore::PgTable {

public:
	PgTblWznmMOp();
	~PgTblWznmMOp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMOp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMOp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMOp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMOp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMOp& rst);

	Sbecore::ubigint insertRec(WznmMOp* rec);
	void insertRst(ListWznmMOp& rst, bool transact = false);
	void updateRec(WznmMOp* rec);
	void updateRst(ListWznmMOp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMOp** rec);
	bool loadRecBySqk(Sbecore::ubigint refWznmMSquawk, WznmMOp** rec);
	Sbecore::ubigint loadRefsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByOpk(Sbecore::ubigint refWznmMOppack, const bool append, ListWznmMOp& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

