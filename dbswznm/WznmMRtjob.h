/**
	* \file WznmMRtjob.h
	* database access for table TblWznmMRtjob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMRTJOB_H
#define WZNMMRTJOB_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMRtjob: record of TblWznmMRtjob
	*/
class WznmMRtjob {

public:
	WznmMRtjob(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMApp = 0, const Sbecore::ubigint supRefWznmMRtjob = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMApp;
	Sbecore::ubigint supRefWznmMRtjob;
	Sbecore::usmallint supLvl;
	Sbecore::ubigint refWznmMJob;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WznmMRtjob& comp);
	bool operator!=(const WznmMRtjob& comp);
};

/**
	* ListWznmMRtjob: recordset of TblWznmMRtjob
	*/
class ListWznmMRtjob {

public:
	ListWznmMRtjob();
	ListWznmMRtjob(const ListWznmMRtjob& src);
	~ListWznmMRtjob();

	void clear();
	unsigned int size() const;
	void append(WznmMRtjob* rec);

	WznmMRtjob* operator[](const Sbecore::uint ix);
	ListWznmMRtjob& operator=(const ListWznmMRtjob& src);
	bool operator==(const ListWznmMRtjob& comp);
	bool operator!=(const ListWznmMRtjob& comp);

public:
	std::vector<WznmMRtjob*> nodes;
};

/**
	* TblWznmMRtjob: C++ wrapper for table TblWznmMRtjob
	*/
class TblWznmMRtjob {

public:

public:
	TblWznmMRtjob();
	virtual ~TblWznmMRtjob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMRtjob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRtjob& rst);

	virtual Sbecore::ubigint insertRec(WznmMRtjob* rec);
	Sbecore::ubigint insertNewRec(WznmMRtjob** rec = NULL, const Sbecore::ubigint refWznmMApp = 0, const Sbecore::ubigint supRefWznmMRtjob = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMRtjob& rst, WznmMRtjob** rec = NULL, const Sbecore::ubigint refWznmMApp = 0, const Sbecore::ubigint supRefWznmMRtjob = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMRtjob& rst, bool transact = false);
	virtual void updateRec(WznmMRtjob* rec);
	virtual void updateRst(ListWznmMRtjob& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMRtjob** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMRtjob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByApp(Sbecore::ubigint refWznmMApp, const bool append, ListWznmMRtjob& rst);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMRtjob, const bool append, ListWznmMRtjob& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWznmMRtjob);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMRtjob& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListWznmMRtjob& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListWznmMRtjob& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMRtjob: C++ wrapper for table TblWznmMRtjob (MySQL database)
	*/
class MyTblWznmMRtjob : public TblWznmMRtjob, public Sbecore::MyTable {

public:
	MyTblWznmMRtjob();
	~MyTblWznmMRtjob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRtjob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRtjob& rst);

	Sbecore::ubigint insertRec(WznmMRtjob* rec);
	void insertRst(ListWznmMRtjob& rst, bool transact = false);
	void updateRec(WznmMRtjob* rec);
	void updateRst(ListWznmMRtjob& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRtjob** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMRtjob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByApp(Sbecore::ubigint refWznmMApp, const bool append, ListWznmMRtjob& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMRtjob, const bool append, ListWznmMRtjob& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWznmMRtjob);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMRtjob: C++ wrapper for table TblWznmMRtjob (PgSQL database)
	*/
class PgTblWznmMRtjob : public TblWznmMRtjob, public Sbecore::PgTable {

public:
	PgTblWznmMRtjob();
	~PgTblWznmMRtjob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMRtjob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMRtjob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMRtjob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMRtjob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRtjob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRtjob& rst);

	Sbecore::ubigint insertRec(WznmMRtjob* rec);
	void insertRst(ListWznmMRtjob& rst, bool transact = false);
	void updateRec(WznmMRtjob* rec);
	void updateRst(ListWznmMRtjob& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRtjob** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMRtjob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByApp(Sbecore::ubigint refWznmMApp, const bool append, ListWznmMRtjob& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMRtjob, const bool append, ListWznmMRtjob& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWznmMRtjob);
};
#endif

#endif

