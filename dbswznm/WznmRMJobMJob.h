/**
	* \file WznmRMJobMJob.h
	* database access for table TblWznmRMJobMJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMJOBMJOB_H
#define WZNMRMJOBMJOB_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVRMJobMJobConstract TblWznmRMJobMJob::VecVConstract

/**
	* WznmRMJobMJob: record of TblWznmRMJobMJob
	*/
class WznmRMJobMJob {

public:
	WznmRMJobMJob(const Sbecore::ubigint ref = 0, const Sbecore::ubigint supRefWznmMJob = 0, const Sbecore::ubigint subRefWznmMJob = 0, const std::string Short = "", const bool Multi = false, const Sbecore::uint ixVConstract = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint supRefWznmMJob;
	Sbecore::ubigint subRefWznmMJob;
	std::string Short;
	bool Multi;
	Sbecore::uint ixVConstract;

public:
	bool operator==(const WznmRMJobMJob& comp);
	bool operator!=(const WznmRMJobMJob& comp);
};

/**
	* ListWznmRMJobMJob: recordset of TblWznmRMJobMJob
	*/
class ListWznmRMJobMJob {

public:
	ListWznmRMJobMJob();
	ListWznmRMJobMJob(const ListWznmRMJobMJob& src);
	~ListWznmRMJobMJob();

	void clear();
	unsigned int size() const;
	void append(WznmRMJobMJob* rec);

	WznmRMJobMJob* operator[](const Sbecore::uint ix);
	ListWznmRMJobMJob& operator=(const ListWznmRMJobMJob& src);
	bool operator==(const ListWznmRMJobMJob& comp);
	bool operator!=(const ListWznmRMJobMJob& comp);

public:
	std::vector<WznmRMJobMJob*> nodes;
};

/**
	* TblWznmRMJobMJob: C++ wrapper for table TblWznmRMJobMJob
	*/
class TblWznmRMJobMJob {

public:
	/**
		* VecVConstract (full: VecWznmVRMJobMJobConstract)
		*/
	class VecVConstract {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint CRE = 2;
		static const Sbecore::uint CUST = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

public:
	TblWznmRMJobMJob();
	virtual ~TblWznmRMJobMJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMJobMJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMJobMJob& rst);

	virtual Sbecore::ubigint insertRec(WznmRMJobMJob* rec);
	Sbecore::ubigint insertNewRec(WznmRMJobMJob** rec = NULL, const Sbecore::ubigint supRefWznmMJob = 0, const Sbecore::ubigint subRefWznmMJob = 0, const std::string Short = "", const bool Multi = false, const Sbecore::uint ixVConstract = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMJobMJob& rst, WznmRMJobMJob** rec = NULL, const Sbecore::ubigint supRefWznmMJob = 0, const Sbecore::ubigint subRefWznmMJob = 0, const std::string Short = "", const bool Multi = false, const Sbecore::uint ixVConstract = 0);
	virtual void insertRst(ListWznmRMJobMJob& rst, bool transact = false);
	virtual void updateRec(WznmRMJobMJob* rec);
	virtual void updateRst(ListWznmRMJobMJob& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMJobMJob** rec);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySub(Sbecore::ubigint subRefWznmMJob, const bool append, ListWznmRMJobMJob& rst);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMJob, const bool append, ListWznmRMJobMJob& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMJobMJob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMJobMJob: C++ wrapper for table TblWznmRMJobMJob (MySQL database)
	*/
class MyTblWznmRMJobMJob : public TblWznmRMJobMJob, public Sbecore::MyTable {

public:
	MyTblWznmRMJobMJob();
	~MyTblWznmRMJobMJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMJobMJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMJobMJob& rst);

	Sbecore::ubigint insertRec(WznmRMJobMJob* rec);
	void insertRst(ListWznmRMJobMJob& rst, bool transact = false);
	void updateRec(WznmRMJobMJob* rec);
	void updateRst(ListWznmRMJobMJob& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMJobMJob** rec);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySub(Sbecore::ubigint subRefWznmMJob, const bool append, ListWznmRMJobMJob& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMJob, const bool append, ListWznmRMJobMJob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMJobMJob: C++ wrapper for table TblWznmRMJobMJob (PgSQL database)
	*/
class PgTblWznmRMJobMJob : public TblWznmRMJobMJob, public Sbecore::PgTable {

public:
	PgTblWznmRMJobMJob();
	~PgTblWznmRMJobMJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMJobMJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMJobMJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMJobMJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmRMJobMJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMJobMJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMJobMJob& rst);

	Sbecore::ubigint insertRec(WznmRMJobMJob* rec);
	void insertRst(ListWznmRMJobMJob& rst, bool transact = false);
	void updateRec(WznmRMJobMJob* rec);
	void updateRst(ListWznmRMJobMJob& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMJobMJob** rec);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySub(Sbecore::ubigint subRefWznmMJob, const bool append, ListWznmRMJobMJob& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMJob, const bool append, ListWznmRMJobMJob& rst);
};
#endif

#endif
