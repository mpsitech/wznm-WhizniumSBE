/**
	* \file WznmRMJobMOp.h
	* database access for table TblWznmRMJobMOp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMRMJOBMOP_H
#define WZNMRMJOBMOP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMJobMOp: record of TblWznmRMJobMOp
	*/
class WznmRMJobMOp {

public:
	WznmRMJobMOp(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMJob = 0, const Sbecore::ubigint refWznmMOp = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMJob;
	Sbecore::ubigint refWznmMOp;

public:
	bool operator==(const WznmRMJobMOp& comp);
	bool operator!=(const WznmRMJobMOp& comp);
};

/**
	* ListWznmRMJobMOp: recordset of TblWznmRMJobMOp
	*/
class ListWznmRMJobMOp {

public:
	ListWznmRMJobMOp();
	ListWznmRMJobMOp(const ListWznmRMJobMOp& src);
	~ListWznmRMJobMOp();

	void clear();
	unsigned int size() const;
	void append(WznmRMJobMOp* rec);

	WznmRMJobMOp* operator[](const Sbecore::uint ix);
	ListWznmRMJobMOp& operator=(const ListWznmRMJobMOp& src);
	bool operator==(const ListWznmRMJobMOp& comp);
	bool operator!=(const ListWznmRMJobMOp& comp);

public:
	std::vector<WznmRMJobMOp*> nodes;
};

/**
	* TblWznmRMJobMOp: C++ wrapper for table TblWznmRMJobMOp
	*/
class TblWznmRMJobMOp {

public:

public:
	TblWznmRMJobMOp();
	virtual ~TblWznmRMJobMOp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMJobMOp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMJobMOp& rst);

	virtual Sbecore::ubigint insertRec(WznmRMJobMOp* rec);
	Sbecore::ubigint insertNewRec(WznmRMJobMOp** rec = NULL, const Sbecore::ubigint refWznmMJob = 0, const Sbecore::ubigint refWznmMOp = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMJobMOp& rst, WznmRMJobMOp** rec = NULL, const Sbecore::ubigint refWznmMJob = 0, const Sbecore::ubigint refWznmMOp = 0);
	virtual void insertRst(ListWznmRMJobMOp& rst, bool transact = false);
	virtual void updateRec(WznmRMJobMOp* rec);
	virtual void updateRst(ListWznmRMJobMOp& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMJobMOp** rec);
	virtual Sbecore::ubigint loadJobsByOpx(Sbecore::ubigint refWznmMOp, const bool append, std::vector<Sbecore::ubigint>& refWznmMJobs);
	virtual Sbecore::ubigint loadOpxsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refWznmMOps);
	virtual Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMJobMOp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMJobMOp: C++ wrapper for table TblWznmRMJobMOp (MySQL database)
	*/
class MyTblWznmRMJobMOp : public TblWznmRMJobMOp, public Sbecore::MyTable {

public:
	MyTblWznmRMJobMOp();
	~MyTblWznmRMJobMOp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMJobMOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMJobMOp& rst);

	Sbecore::ubigint insertRec(WznmRMJobMOp* rec);
	void insertRst(ListWznmRMJobMOp& rst, bool transact = false);
	void updateRec(WznmRMJobMOp* rec);
	void updateRst(ListWznmRMJobMOp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMJobMOp** rec);
	Sbecore::ubigint loadJobsByOpx(Sbecore::ubigint refWznmMOp, const bool append, std::vector<Sbecore::ubigint>& refWznmMJobs);
	Sbecore::ubigint loadOpxsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refWznmMOps);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMJobMOp: C++ wrapper for table TblWznmRMJobMOp (PgSQL database)
	*/
class PgTblWznmRMJobMOp : public TblWznmRMJobMOp, public Sbecore::PgTable {

public:
	PgTblWznmRMJobMOp();
	~PgTblWznmRMJobMOp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMJobMOp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMJobMOp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMJobMOp** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMJobMOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMJobMOp& rst);

	Sbecore::ubigint insertRec(WznmRMJobMOp* rec);
	void insertRst(ListWznmRMJobMOp& rst, bool transact = false);
	void updateRec(WznmRMJobMOp* rec);
	void updateRst(ListWznmRMJobMOp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMJobMOp** rec);
	Sbecore::ubigint loadJobsByOpx(Sbecore::ubigint refWznmMOp, const bool append, std::vector<Sbecore::ubigint>& refWznmMJobs);
	Sbecore::ubigint loadOpxsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refWznmMOps);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif

