/**
	* \file WznmRMJobMOppack.h
	* database access for table TblWznmRMJobMOppack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMRMJOBMOPPACK_H
#define WZNMRMJOBMOPPACK_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMJobMOppack: record of TblWznmRMJobMOppack
	*/
class WznmRMJobMOppack {

public:
	WznmRMJobMOppack(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMJob = 0, const Sbecore::ubigint refWznmMOppack = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMJob;
	Sbecore::ubigint refWznmMOppack;

public:
	bool operator==(const WznmRMJobMOppack& comp);
	bool operator!=(const WznmRMJobMOppack& comp);
};

/**
	* ListWznmRMJobMOppack: recordset of TblWznmRMJobMOppack
	*/
class ListWznmRMJobMOppack {

public:
	ListWznmRMJobMOppack();
	ListWznmRMJobMOppack(const ListWznmRMJobMOppack& src);
	~ListWznmRMJobMOppack();

	void clear();
	unsigned int size() const;
	void append(WznmRMJobMOppack* rec);

	WznmRMJobMOppack* operator[](const Sbecore::uint ix);
	ListWznmRMJobMOppack& operator=(const ListWznmRMJobMOppack& src);
	bool operator==(const ListWznmRMJobMOppack& comp);
	bool operator!=(const ListWznmRMJobMOppack& comp);

public:
	std::vector<WznmRMJobMOppack*> nodes;
};

/**
	* TblWznmRMJobMOppack: C++ wrapper for table TblWznmRMJobMOppack
	*/
class TblWznmRMJobMOppack {

public:

public:
	TblWznmRMJobMOppack();
	virtual ~TblWznmRMJobMOppack();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMJobMOppack** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMJobMOppack& rst);

	virtual Sbecore::ubigint insertRec(WznmRMJobMOppack* rec);
	Sbecore::ubigint insertNewRec(WznmRMJobMOppack** rec = NULL, const Sbecore::ubigint refWznmMJob = 0, const Sbecore::ubigint refWznmMOppack = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMJobMOppack& rst, WznmRMJobMOppack** rec = NULL, const Sbecore::ubigint refWznmMJob = 0, const Sbecore::ubigint refWznmMOppack = 0);
	virtual void insertRst(ListWznmRMJobMOppack& rst, bool transact = false);
	virtual void updateRec(WznmRMJobMOppack* rec);
	virtual void updateRst(ListWznmRMJobMOppack& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMJobMOppack** rec);
	virtual Sbecore::ubigint loadJobsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refWznmMJobs);
	virtual Sbecore::ubigint loadOpksByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refWznmMOppacks);
	virtual Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMJobMOppack& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMJobMOppack: C++ wrapper for table TblWznmRMJobMOppack (MySQL database)
	*/
class MyTblWznmRMJobMOppack : public TblWznmRMJobMOppack, public Sbecore::MyTable {

public:
	MyTblWznmRMJobMOppack();
	~MyTblWznmRMJobMOppack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMJobMOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMJobMOppack& rst);

	Sbecore::ubigint insertRec(WznmRMJobMOppack* rec);
	void insertRst(ListWznmRMJobMOppack& rst, bool transact = false);
	void updateRec(WznmRMJobMOppack* rec);
	void updateRst(ListWznmRMJobMOppack& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMJobMOppack** rec);
	Sbecore::ubigint loadJobsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refWznmMJobs);
	Sbecore::ubigint loadOpksByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refWznmMOppacks);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMJobMOppack: C++ wrapper for table TblWznmRMJobMOppack (PgSQL database)
	*/
class PgTblWznmRMJobMOppack : public TblWznmRMJobMOppack, public Sbecore::PgTable {

public:
	PgTblWznmRMJobMOppack();
	~PgTblWznmRMJobMOppack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMJobMOppack** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMJobMOppack& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMJobMOppack** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMJobMOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMJobMOppack& rst);

	Sbecore::ubigint insertRec(WznmRMJobMOppack* rec);
	void insertRst(ListWznmRMJobMOppack& rst, bool transact = false);
	void updateRec(WznmRMJobMOppack* rec);
	void updateRst(ListWznmRMJobMOppack& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMJobMOppack** rec);
	Sbecore::ubigint loadJobsByOpk(Sbecore::ubigint refWznmMOppack, const bool append, std::vector<Sbecore::ubigint>& refWznmMJobs);
	Sbecore::ubigint loadOpksByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refWznmMOppacks);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif

