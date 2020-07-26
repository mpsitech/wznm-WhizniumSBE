/**
	* \file WznmAMJobCmd.h
	* database access for table TblWznmAMJobCmd (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMAMJOBCMD_H
#define WZNMAMJOBCMD_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMJobCmd: record of TblWznmAMJobCmd
	*/
class WznmAMJobCmd {

public:
	WznmAMJobCmd(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMJob;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WznmAMJobCmd& comp);
	bool operator!=(const WznmAMJobCmd& comp);
};

/**
	* ListWznmAMJobCmd: recordset of TblWznmAMJobCmd
	*/
class ListWznmAMJobCmd {

public:
	ListWznmAMJobCmd();
	ListWznmAMJobCmd(const ListWznmAMJobCmd& src);
	~ListWznmAMJobCmd();

	void clear();
	unsigned int size() const;
	void append(WznmAMJobCmd* rec);

	WznmAMJobCmd* operator[](const Sbecore::uint ix);
	ListWznmAMJobCmd& operator=(const ListWznmAMJobCmd& src);
	bool operator==(const ListWznmAMJobCmd& comp);
	bool operator!=(const ListWznmAMJobCmd& comp);

public:
	std::vector<WznmAMJobCmd*> nodes;
};

/**
	* TblWznmAMJobCmd: C++ wrapper for table TblWznmAMJobCmd
	*/
class TblWznmAMJobCmd {

public:

public:
	TblWznmAMJobCmd();
	virtual ~TblWznmAMJobCmd();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMJobCmd** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMJobCmd& rst);

	virtual Sbecore::ubigint insertRec(WznmAMJobCmd* rec);
	Sbecore::ubigint insertNewRec(WznmAMJobCmd** rec = NULL, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMJobCmd& rst, WznmAMJobCmd** rec = NULL, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWznmAMJobCmd& rst, bool transact = false);
	virtual void updateRec(WznmAMJobCmd* rec);
	virtual void updateRst(ListWznmAMJobCmd& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMJobCmd** rec);
	virtual Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWznmMJob, const bool append, ListWznmAMJobCmd& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMJobCmd& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMJobCmd: C++ wrapper for table TblWznmAMJobCmd (MySQL database)
	*/
class MyTblWznmAMJobCmd : public TblWznmAMJobCmd, public Sbecore::MyTable {

public:
	MyTblWznmAMJobCmd();
	~MyTblWznmAMJobCmd();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMJobCmd** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMJobCmd& rst);

	Sbecore::ubigint insertRec(WznmAMJobCmd* rec);
	void insertRst(ListWznmAMJobCmd& rst, bool transact = false);
	void updateRec(WznmAMJobCmd* rec);
	void updateRst(ListWznmAMJobCmd& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMJobCmd** rec);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWznmMJob, const bool append, ListWznmAMJobCmd& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMJobCmd: C++ wrapper for table TblWznmAMJobCmd (PgSQL database)
	*/
class PgTblWznmAMJobCmd : public TblWznmAMJobCmd, public Sbecore::PgTable {

public:
	PgTblWznmAMJobCmd();
	~PgTblWznmAMJobCmd();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMJobCmd** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMJobCmd& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMJobCmd** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMJobCmd& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMJobCmd** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMJobCmd& rst);

	Sbecore::ubigint insertRec(WznmAMJobCmd* rec);
	void insertRst(ListWznmAMJobCmd& rst, bool transact = false);
	void updateRec(WznmAMJobCmd* rec);
	void updateRst(ListWznmAMJobCmd& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMJobCmd** rec);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWznmMJob, const bool append, ListWznmAMJobCmd& rst);
};
#endif

#endif

